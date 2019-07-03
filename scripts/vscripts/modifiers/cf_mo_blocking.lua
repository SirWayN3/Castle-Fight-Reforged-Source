cf_mo_blocking = class({})


function cf_mo_blocking:IsHidden()
	return false
end

function cf_mo_blocking:IsPurgable()
	return false
end
function cf_mo_blocking:IsDebuff()
	return false
end
function cf_mo_blocking:OnCreated( kv )
	if IsServer() then
		self.reduct = self:GetAbility():GetLevelSpecialValueFor("reduct", 1)
		self.chance = self:GetAbility():GetLevelSpecialValueFor("chance", 1)
	end
end
function cf_mo_blocking:GetModifierPhysical_ConstantBlock( kv )
	if IsServer() then
		if RollPercentage(self.chance) then
			return kv.damage - self.reduct
		end
	end
end
function cf_mo_blocking:DeclareFunctions()
	local funcs = {
		MODIFIER_PROPERTY_PHYSICAL_CONSTANT_BLOCK
	}

	return funcs
end
function cf_mo_blocking:OnIntervalThink()
	if IsServer() then
		
	end
end

function cf_mo_blocking:GetPriority()
	return MODIFIER_PRIORITY_ULTRA
end

