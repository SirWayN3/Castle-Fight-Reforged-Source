cf_mo_bu_autocast = class({})


function cf_mo_bu_autocast:IsHidden()
	return false
end

function cf_mo_bu_autocast:IsPurgable()
	return false
end

function cf_mo_bu_autocast:OnCreated( kv )
	if IsServer() then
		local unit = self:GetParent()
		self.ab = unit:GetAllAutoCastAbilities()
		
		if tablelength(self.ab) > 0 then
			self:StartIntervalThink( CF_BUILDING_CHECKREADY )
		else
			self:Destroy()
		end
	end
end

function cf_mo_bu_autocast:OnDestroy()
	if IsServer() then
		-- print( "cf_mo_bu_autocast:OnDestroy" )
	end
end

function cf_mo_bu_autocast:GetPriority()
	return MODIFIER_PRIORITY_ULTRA
end

function cf_mo_bu_autocast:OnIntervalThink()
	if IsServer() then
		if (GameRules:State_Get() ~= DOTA_GAMERULES_STATE_GAME_IN_PROGRESS) then return end
		-- print( "cf_mo_bu_autocast:OnIntervalThink: Ability " .. self:GetAbility():GetAbilityName() .. " AutoCastState: " .. tostring(self:GetAbility():GetAutoCastState() ) .. " Duration: " .. self:GetDuration() )

		-- Check OnBuildingFinished for Details on entries; 0 based!
		for k,v in pairs(self.ab) do
			-- print(k,v,v:GetAbilityName())
			if v:IsFullyCastable() then v:CastAbility() end
		end
		
	end
end