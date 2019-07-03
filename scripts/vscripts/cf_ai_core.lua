
--[[ 
	Recognized Commands in KeyValues:
		"cf_autocast"				"1"		// Ability is checked for this Entry. Then AutoCast is enabled.
		"cf_ai_ab_castondamaged"	"1"		// Ability will Target only damaged Units.
		"cf_ai_ab_castoncorpse"		"1"		// Ability will Target Corpse Units


		"AttackRangeMin"			"250"	// Minimum Attack Range of 250

		Use Filter for Enemy in Range:
			"AbilityUnitTargetTeam" 		" DOTA_UNIT_TARGET_TEAM_ENEMY "
			"AbilityUnitTargetType"			" DOTA_UNIT_TARGET_HERO | DOTA_UNIT_TARGET_CREEP "
			"AbilityCastRange" 				"500"
			-> Return Valid Enemy in Range.


	Attack Targets Types in KeyValue: {AttackTargetType}
		AI_ATTACK_NONE
		AI_ATTACK_ALL
		AI_ATTACK_GROUND
		AI_ATTACK_AIR
	
	Order Types stored in Modifier
		AI_ORDER_IDLE
		AI_ORDER_MOVE
		AI_ORDER_ATTACK
		AI_ORDER_CAST
]]

function cf_ai_core(mo)
	if mo.ab ~= nil then
		for k,v in pairs(mo.ab) do
			-- print(k,v:IsFullyCastable())
			if v:IsFullyCastable() then
				local target = v:GetValidCastTarget(mo.unit)
				-- print(k,target)
				if target then 
					-- print(target,target:GetUnitName())
					mo.unit:CastAbilityOnTarget(target, v, mo.ownerID)
					mo.order = "AI_ORDER_CAST"
					return
				end
			end
		end
	end
	-- Set for waypoints
	mo.unit:SetWayPointPos()
	-- mo:Destroy()
	-- Check for Valid Attack Target
	-- if mo.unit 
	-- print("Check for Valid Attack Target")
	if mo.target == nil then
		-- Check for Target
		local t = mo.unit:GetValidAttackTarget()
		-- print("cf_mo_cr_ai","Check for new target",mo.target,t)
		-- Is Target Valid?
		if t ~= nil and mo.target ~= t then
			mo.target = t
			mo:OrderAttack()
		else
			if mo.order ~= "AI_ORDER_MOVE" then
				-- print("cf_mo_cr_ai","no target, move to next waypoint")
				mo.order = "AI_ORDER_MOVE"
				
				mo.unit:MoveToPosition(mo.unit:GetWayPointPos())

			elseif mo.unit:IsIdle() then
				-- print("cf_mo_cr_ai","IsIdle",mo.unit:GetUnitName())
				mo.order = "AI_ORDER_IDLE"
				mo.unit:SetNextWayPoint()

			elseif mo.unit:IsWaypointInRange() then
				-- print("waypoint is in range, skip to next one")
				mo.order = "AI_ORDER_IDLE"
				mo.unit:SetNextWayPoint()
				
			end
		end
	else
		-- Unit has Target
		if mo.target:IsNull() then
			mo:GetNewOrder()

		elseif not mo.target:IsAlive() then
			mo:GetNewOrder()
		elseif not mo.target:IsOpposingTeam(mo.unit:GetTeamNumber()) then
			mo:GetNewOrder()
		elseif mo.target:IsBuilding() then
			-- check for new Valid Attack Targets when attacking Buildings
			local t = mo.unit:GetValidAttackTarget_Creep()
			-- print("cf_mo_cr_ai","Target is Building",t,mo.target)
			if t ~= nil and t ~= mo.target then
				mo.target = t
				mo:OrderAttack()
			end
		else
			-- Check Minimum Attack Range
			-- print(mo.unit:GetMinimumAttackRange())
			if mo.unit:GetMinimumAttackRange() > 0 then
				-- print("cf_mo_cr_ai","Check Min attack Range",mo.unit:IsInMinimumAttackRange(mo.target ))
				if not mo.unit:IsInMinimumAttackRange( mo.target ) then
					
					mo:GetNewOrder()
				end
			end
		end
	end
end

function CDOTABaseAbility:GetValidCastTarget( caster)
	-- print(
	-- 	self:GetAbilityName(),
	-- 	self:GetCastRange() + self:GetCastRangeBuffer(),
	-- 	self:GetAbilityTargetTeam(),
	-- 	self:GetAbilityTargetType(),
	-- 	self:GetAbilityTargetFlags()
	-- )
	local unit = FindUnitsInRadius(
		caster:GetTeamNumber(),
		caster:GetAbsOrigin(),
		nil,
		self:GetCastRange() + self:GetCastRangeBuffer(),
		self:GetAbilityTargetTeam(),
		self:GetAbilityTargetType(),
		self:GetAbilityTargetFlags(),
		FIND_ANY_ORDER,
		false)
	-- PrintTable(unit)
	-- print( "check additonal AI data, like HP Treshhold, or IsDamaged etc. ")
	if self:GetKeyValue("cf_ai_ab_castondamaged") == 1 then
		for _,v in pairs(unit) do
			if v:IsDamaged() then 
				if IsCustomBuilding(v) then
					if v:GetClassname() == "npc_dota_fort" then
						return v
					elseif not v:IsUnderConstruction() then
						return v
					end
				else
					return v
				end
			end
		end
	elseif self:GetKeyValue("cf_ai_ab_castoncorpse") == 1 then
		for _,v in pairs(unit) do
			if v:IsCorpse() then
				-- print("Check For Corpse",v:GetUnitName())
				return v
			end
		end
	elseif unit[1] then
		return unit[1]
	end
	return nil
end
function CDOTA_BaseNPC:SetNewWayPoints()
	self:SetWayPointPos(true)
end

function CDOTA_BaseNPC:GetValidAttackTarget()
	-- Check for Unit, then for Building if not found
	return self:GetValidAttackTarget_Creep() or self:GetValidAttackTarget_Building() or nil
end

function CDOTA_BaseNPC:GetValidAttackTarget_Creep()
	-- print("")
	-- print("CDOTA_BaseNPC","GetValidAttackTarget_Creep",self.attackType)

	local units = FindUnitsInRadius(
		self:GetTeamNumber(),
		self:GetAbsOrigin(),
		nil,
		-- self:Script_GetAttackRange() + self:GetAttackRangeBuffer(),
		CF_AI_CREEP_AQCUIRETARGETRANGE,
		DOTA_UNIT_TARGET_TEAM_ENEMY, -- teamFilter
		DOTA_UNIT_TARGET_CREEP, -- typeFilter
		DOTA_UNIT_TARGET_FLAG_MAGIC_IMMUNE_ENEMIES, -- flagFilter
		FIND_CLOSEST, -- order
		false
	)
	if #units == 0 then return nil end

	-- PrintTable(unit)
	for _,v in pairs(units) do
		-- print(v,v:GetUnitName(),"IsCorpse",v:IsCorpse())
		-- print("Distance",CalcDistanceBetweenEntityOBB(v,self))
		if not v:IsCorpse() then 
			if v:MatchesAttackType( self.attackType ) then
				if self:GetMinimumAttackRange() > 0 then
					-- print("MiNAttackRange",self:GetMinimumAttackRange())
				-- Min Attack Distance Check
					if self:IsInMinimumAttackRange( v ) then
						return v
					end
				else -- Not in Min Range
					return v
				end
			else -- Not matching Attack Type
				return nil
			end
		end
	end
	return nil
end
function CDOTA_BaseNPC:GetValidAttackTarget_Building()
	-- print("")
	-- print("CDOTA_BaseNPC","GetValidAttackTarget_Building",self.attackType)

	local units = FindUnitsInRadius(
		self:GetTeamNumber(),
		self:GetAbsOrigin(),
		nil,
		-- self:Script_GetAttackRange() + self:GetAttackRangeBuffer(),
		CF_AI_CREEP_AQCUIRETARGETRANGE,
		DOTA_UNIT_TARGET_TEAM_ENEMY, -- teamFilter
		DOTA_UNIT_TARGET_BUILDING, -- typeFilter
		DOTA_UNIT_TARGET_FLAG_MAGIC_IMMUNE_ENEMIES, -- flagFilter
		FIND_CLOSEST, -- order
		false
	)
	if #units == 0 then return nil end

	-- PrintTable(unit)
	for _,v in pairs(units) do
		-- print(v,v:GetUnitName())
		-- print("Distance",CalcDistanceBetweenEntityOBB(v,self))
		if v:MatchesAttackType( self.attackType ) then
			if self:GetMinimumAttackRange() > 0 then
				-- print("MiNAttackRange",self:GetMinimumAttackRange())
			-- Min Attack Distance Check
				if self:IsInMinimumAttackRange( v ) then
					return v
				end
			else -- Not in Min Range
				return v
			end
		else -- Not matching Attack Type
			return nil
		end
	end
	return nil
end
function CDOTA_BaseNPC:MatchesAttackType( attackType )
	if 
		attackType == "AI_ATTACK_ALL"
	then 
		return true 
	elseif
		attackType == "AI_ATTACK_GROUND" 
		and
		(
			self:HasGroundMovementCapability()
			or self:IsBuilding()
		)
	then 
		return true 
	elseif
		attackType == "AI_ATTACK_AIR"
		and self:HasFlyMovementCapability() 
	then 
		return true 
	else
		return false
	end
end

function CDOTA_BaseNPC:SetWayPointPos( force_renew )
	local force_renew = force_renew or false
	-- print("SetWayPointPos1")
	if self.wp ~= nil and not force_renew then return end
	-- print("SetWayPointPos2")
	local wpoint = Entities:FindByClassnameNearest("path_corner", self:GetAbsOrigin(), 5000.0)
	self.wp = {}
	self.wp.pos = {}
	self.wp.pos[0] = wpoint:GetAbsOrigin()
	self.wp.ind = 0
	self.wp.max = self.wp.ind

	local n = self.wp.ind
	local npoint = wpoint:GetName()
	local wpos = nil

	while ( true ) do

		if self:GetTeam() == CF_TEAM_NUMBER_LEFT then
			wpoint = cf_table_pathcorner[npoint].NextWaypoint
			wpos = cf_table_pathcorner[npoint].NextWaypoint_pos
		elseif self:GetTeam() == CF_TEAM_NUMBER_RIGHT then
			wpoint = cf_table_pathcorner[npoint].PrevWaypoint
			wpos = cf_table_pathcorner[npoint].PrevWaypoint_pos
		end
		if wpoint == nil then break end
		-- print("wpoint",wpoint,"npoint",npoint,"wpos",wpos)
		npoint = wpoint
		n = n +1
		-- self.wp.pos[n] = wpoint:GetEntityIndex():GetAbsOrigin()
		self.wp.pos[n] = wpos

		if n > 10 then break end -- Prevent issues...
	end

	self.wp.max = n
end
function CDOTA_BaseNPC:GetWayPointPos()
	if self.wp == nil then return nil end
	-- print("GetWayPointPos",self.wp.ind,self.wp.pos[self.wp.ind])
	return self.wp.pos[self.wp.ind]
end
function CDOTA_BaseNPC:SetNextWayPoint()
	self.wp.ind = self.wp.ind +1

	if self.wp.ind > self.wp.max then self.wp.ind = self.wp.max end
	-- print("SetNextWayPoint",self.wp.ind)
end
function CDOTA_BaseNPC:IsWaypointInRange()
	local v = self:GetAbsOrigin() - self:GetWayPointPos()
	if v:Length() < CF_AI_CREEP_WAYPOINT_RANGE then
		return true
	else
		return false
	end
end
