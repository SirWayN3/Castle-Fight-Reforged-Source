cf_mo_bu_building_particle = class({})


function cf_mo_bu_building_particle:IsDebuff()
	return false
end

function cf_mo_bu_building_particle:IsPurgable()
	return false
end

function cf_mo_bu_building_particle:DeclareFunctions()
	local funcs = {
		MODIFIER_PROPERTY_MANA_REGEN_TOTAL_PERCENTAGE,
	}

	return funcs
end
function cf_mo_bu_building_particle:OnCreated( kv )
	-- if IsServer() then
		-- self:StartIntervalThink( CF_BUILDING_CHECKREADY )
	-- end
	-- print ( "cf_mo_bu_building_particle: Created")
	local owner = self:GetParent()
	local particle = ParticleManager:CreateParticle( CF_BU_PARTICLE , PATTACH_ABSORIGIN_FOLLOW, owner )
	local duration = tonumber(kv.duration)
	-- print ( duration )
	ParticleManager:SetParticleControl(particle, 0, owner:GetAbsOrigin())
	self.particle = particle
	
end

function cf_mo_bu_building_particle:OnDestroy()
	if IsServer() then
		-- print( "cf_mo_bu_building_particle:OnDestroy" )
		ParticleManager:DestroyParticle(self.particle, true)
	end

end

function cf_mo_bu_building_particle:GetPriority()
	return MODIFIER_PRIORITY_ULTRA
end

function cf_mo_bu_building_particle:OnIntervalThink()
	
end

function cf_mo_bu_building_particle:CheckState()
	local state = {
	[MODIFIER_STATE_DISARMED] = true,
	-- [MODIFIER_STATE_SILENCED] = true,
	}

	return state
end

function cf_mo_bu_building_particle:GetModifierTotalPercentageManaRegen()
	return -100
end
