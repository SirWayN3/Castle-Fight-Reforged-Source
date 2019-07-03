function cf_ab_gryphon_chain( kv )
	-- PrintTable( kv )
	-- kv.target
	-- kv.caster
	-- kv.Damage
	if kv.target:IsBuilding() then return end
	ApplyDamage( { 
		victim = kv.target,
		attacker = kv.attacker,
		damage = kv.Damage,
		damage_type = DAMAGE_TYPE_MAGICAL,
		damage_flags = DOTA_DAMAGE_FLAG_BYPASSES_BLOCK
	} )

	local lightningBolt = ParticleManager:CreateParticle(kv.particle_jump, PATTACH_WORLDORIGIN, kv.caster)
	ParticleManager:SetParticleControl(
		lightningBolt,
		0,
		Vector(kv.caster:GetAbsOrigin().x,
			kv.caster:GetAbsOrigin().y,
			kv.caster:GetAbsOrigin().z + kv.caster:GetBoundingMaxs().z )
		)   
	ParticleManager:SetParticleControl(
		lightningBolt,
		1,
		Vector(kv.target:GetAbsOrigin().x,
			kv.target:GetAbsOrigin().y,
			kv.target:GetAbsOrigin().z + kv.target:GetBoundingMaxs().z )
		)
				
end