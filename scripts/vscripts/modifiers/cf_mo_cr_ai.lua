cf_mo_cr_ai = class({})

cf_mo_cr_ai.interval = 0.5

function cf_mo_cr_ai:IsHidden()
	return false
end

function cf_mo_cr_ai:IsPurgable()
	return false
end

function cf_mo_cr_ai:OnCreated( kv )
	if IsServer() then
		self:StartIntervalThink(self.interval)

		-- check for abilities
		local unit = self:GetParent()
		self.ab = unit:GetAllAutoCastAbilities()
		self.unit = unit
		unit.mo = self
		

		if tablelength(self.ab) > 0 then
			-- self:StartIntervalThink( CF_CREEP_AUTOCAST_TIMER )
			self.ownerID = unit:GetPlayerOwnerID()
		else
			self.ab = nil
		end
		if unit:HasAttackCapability() then
			-- print(unit:GetAttackTargetType())
			-- if unit:GetAttackTargetType() == "AI_ATTACK_ALL" then
				-- self:Destroy()
			-- else
				self.attackCap = unit:GetAttackCapability()
				unit.attackType = unit:GetAttackTargetType()
				-- print("attacktype",self.attackCap)
				self.target = nil
				unit:SetAttackCapability(DOTA_UNIT_CAP_NO_ATTACK)
			-- end
		elseif self.ab == nil then
			-- This should technically never run
			print("cf_mo_cr_ai","No Attack and no active Abilities.","WTF?")
			self:StartIntervalThink(-1)
			-- self:Destroy()
		end

		
	end
end
-- function cf_mo_cr_ai:OnDominated()
-- 	print("cf_mo_cr_ai: OnDominated")
	
-- end

function cf_mo_cr_ai:OnDestroy()
	if IsServer() then
		-- print( " cf_mo_cr_ai:OnDestroy" )
	end
end

function cf_mo_cr_ai:GetPriority()
	return MODIFIER_PRIORITY_ULTRA
end

function cf_mo_cr_ai:OnIntervalThink()
	if IsServer() then
		-- print("cf_mo_cr_ai","Interval")
		-- First Check for Abilities ready to cast
		cf_ai_core(self)
	end
end

function cf_mo_cr_ai:OrderAttack()
	self.unit:SetAttackCapability(self.attackCap)
	self.unit:Stop()
	self.unit:SetForceAttackTarget(self.target)
	-- self.unit:SetAggroTarget(self.target)

	self.order = "AI_ORDER_ATTACK"
end

function cf_mo_cr_ai:GetNewOrder()
	-- print("cf_mo_cr_ai","GetNewOrder")
	self.target = nil
	self.unit:SetAttackCapability(DOTA_UNIT_CAP_NO_ATTACK)

	-- Get new Orders
	self:OnIntervalThink()
end