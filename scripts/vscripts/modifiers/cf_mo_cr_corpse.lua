cf_mo_cr_corpse = class({})


function cf_mo_cr_corpse:IsHidden()
	return false
end

function cf_mo_cr_corpse:IsPurgable()
	return false
end

function cf_mo_cr_corpse:OnCreated( kv )
	if IsServer() then
		self:SetDuration(CF_UNIT_CORPSE_DURATION, true)
	
		
	end
end

function cf_mo_cr_corpse:OnDestroy()
	if IsServer() then
		-- print( " cf_mo_cr_corpse:OnDestroy" )
		if not self:GetParent():IsNull() then
			UTIL_Remove(self:GetParent())
		end
	end
end

function cf_mo_cr_corpse:GetPriority()
	return MODIFIER_PRIORITY_ULTRA
end

function cf_mo_cr_corpse:OnIntervalThink()
	if IsServer() then
		
	end
end

function cf_mo_cr_corpse:CheckState()
	local state = {
	-- [MODIFIER_STATE_INVULNERABLE] = true,
	[MODIFIER_STATE_MAGIC_IMMUNE] = true,
	[MODIFIER_STATE_NO_HEALTH_BAR] = true,
	[MODIFIER_STATE_NO_UNIT_COLLISION] = true,
	-- [MODIFIER_STATE_NO_TEAM_SELECT] = true,
	[MODIFIER_STATE_ATTACK_IMMUNE] = true,
	[MODIFIER_STATE_NOT_ON_MINIMAP] = true,
	-- [MODIFIER_STATE_COMMAND_RESTRICTED] = true,
	}

	return state
end
