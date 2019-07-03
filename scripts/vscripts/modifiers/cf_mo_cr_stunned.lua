cf_mo_cr_stunned = class({})


function cf_mo_cr_stunned:IsHidden()
	return false
end

function cf_mo_cr_stunned:IsPurgable()
	return false
end
function cf_mo_cr_stunned:GetEffectName()
    return "particles/generic_gameplay/generic_stunned.vpcf"
end
function cf_mo_cr_stunned:GetEffectAttachType()
    return PATTACH_OVERHEAD_FOLLOW
end

function cf_mo_cr_stunned:DeclareFunctions()
	local funcs = {
		MODIFIER_PROPERTY_OVERRIDE_ANIMATION,
	}

	return funcs
end

--------------------------------------------------------------------------------

function cf_mo_cr_stunned:GetOverrideAnimation( params )
	return ACT_DOTA_DISABLED
end

function cf_mo_cr_stunned:GetPriority()
	return MODIFIER_PRIORITY_ULTRA
end


function cf_mo_cr_stunned:CheckState()
	local state = {
	[MODIFIER_STATE_STUNNED] = true,
	}

	return state
end
