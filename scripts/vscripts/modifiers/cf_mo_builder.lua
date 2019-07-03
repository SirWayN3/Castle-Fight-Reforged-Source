cf_mo_builder = class({})


function cf_mo_builder:IsHidden()
	return false
end

function cf_mo_builder:IsPurgable()
	return false
end

function cf_mo_builder:OnCreated( kv )
	if IsServer() then
		local unit = self:GetParent()
		-- self.ab_repair = unit:FindAbilityByName("cf_00_ab_builder_repair")
		self.ab_repair = BuildingHelper:GetRepairAbility(unit)
		-- print(self.ab_repair,self.ab_repair:GetAbilityName(),self.ab_repair:GetCastRange() + self.ab_repair:GetCastRangeBuffer())
		self:StartIntervalThink( CF_CREEP_AUTOCAST_TIMER )
		self.parent = unit
		self.ownerID = unit:GetPlayerOwnerID()
	end
end

function cf_mo_builder:OnIntervalThink()
	if IsServer() then
		if self.ab_repair ~= nil then
			-- print("cf_mo_builder")
			cf_builder_common_repair( self )
		end
	end
end

function cf_mo_builder:GetPriority()
	return MODIFIER_PRIORITY_ULTRA
end

function cf_mo_builder:CheckState()
	local state = {
	[MODIFIER_STATE_INVULNERABLE] = true,
	[MODIFIER_STATE_MAGIC_IMMUNE] = true,
	[MODIFIER_STATE_NO_HEALTH_BAR] = true,
	[MODIFIER_STATE_NO_UNIT_COLLISION] = true,
	-- [MODIFIER_STATE_NO_TEAM_SELECT] = true,
	[MODIFIER_STATE_ATTACK_IMMUNE] = true,
	}

	return state
end