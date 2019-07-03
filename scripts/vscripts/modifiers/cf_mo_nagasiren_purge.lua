cf_mo_nagasiren_purge = class({})


function cf_mo_nagasiren_purge:IsHidden()
	return false
end

function cf_mo_nagasiren_purge:IsPurgable()
	return true
end
function cf_mo_nagasiren_purge:GetEffectName()
    return "particles/generic_gameplay/generic_purge.vpcf"
end

function cf_mo_nagasiren_purge:GetEffectAttachType()
    return PATTACH_ABSORIGIN_FOLLOW
end
function cf_mo_nagasiren_purge:GetModifierAttackSpeedBonus_Constant()
	return self.as_slow
end

function cf_mo_nagasiren_purge:GetModifierMoveSpeedBonus_Percentage()
	return self.ms_slow
end

function cf_mo_nagasiren_purge:DeclareFunctions()
	local funcs = {
		MODIFIER_PROPERTY_MOVESPEED_BONUS_PERCENTAGE,
		MODIFIER_PROPERTY_ATTACKSPEED_BONUS_CONSTANT
	}

	return funcs
end
function cf_mo_nagasiren_purge:OnRefresh( kv )
	if IsServer() then
		self.ms_slow_init = kv.ms_slow
		self.as_slow_init = kv.as_slow
	end
end

function cf_mo_nagasiren_purge:OnCreated( kv )
	if IsServer() then
		-- self.duration = kv.duration
		self.ms_slow_init = kv.ms_slow
		self.as_slow_init = kv.as_slow
		self:StartIntervalThink(0.05)
	end
end
function cf_mo_nagasiren_purge:OnIntervalThink()
	if IsServer() then
		-- print(self:GetDuration(),self:GetRemainingTime())

		self.ms_slow = self.ms_slow_init * self:GetRemainingTime() / self:GetDuration()
		self.as_slow = self.as_slow_init * self:GetRemainingTime() / self:GetDuration()

		-- print(self.ms_slow,self.as_slow)
		-- print()
	end
end

function cf_mo_nagasiren_purge:GetPriority()
	return MODIFIER_PRIORITY_ULTRA
end


-- function cf_mo_nagasiren_purge:CheckState()
-- 	local state = {
-- 	[MODIFIER_STATE_STUNNED] = true,
-- 	}

-- 	return state
-- end
