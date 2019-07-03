function cf_ab_split( kv )
	
	local ability = kv.ability

	local unit_name = ability:GetKeyValue("AB_SplitUnit")
	local unit_count = ability:GetKeyValue("AB_SplitUnitCount")


	for i=1,unit_count do
		CreateUnitByName(
			unit_name,
			kv.caster:GetAbsOrigin(),
			true,
			kv.caster:GetOwner(),
			kv.caster:GetOwner(),
			kv.caster:GetTeam()
		)
	end
	
end

function cf_takecontrol( kv )

	local target = kv.ability:GetValidCastTarget(kv.caster)
	if target then 
		-- PrintTable( kv )
		-- print(target,target:GetUnitName())
		target:SetOwner( kv.caster:GetOwner() )
		target:SetTeam( kv.caster:GetTeamNumber() )
		target:SetNewWayPoints()

		local particle = ParticleManager:CreateParticle( kv.particle, PATTACH_ABSORIGIN_FOLLOW, target )
		ParticleManager:SetParticleControl( particle, 0, target:GetOrigin() )
		ParticleManager:SetParticleControl( particle, 1, target:GetOrigin() )
	else
		-- print("No target found")
	end

end

function cf_ab_coral_statue( kv )
	local units = FindUnitsInRadius(
		kv.caster:GetTeamNumber(),
		kv.caster:GetAbsOrigin(),
		nil,
		kv.radius,
		kv.ability:GetAbilityTargetTeam(),
		kv.ability:GetAbilityTargetType(),
		kv.ability:GetAbilityTargetFlags(),
		FIND_ANY_ORDER, 
		false)

	for k,v in pairs( units ) do
		if v:IsCorpse() then
			--
		elseif v:IsBuilding() then
			v:Heal(kv.hp_bu, kv.ability)
		elseif v:IsCreep() then
			v:Heal(kv.hp_cr, kv.ability)
		end
	end
end

function cf_ab_naga_purge( kv )
	-- print("cf_ab_naga_purge")
	-- PrintTable( kv)
	if kv.target:IsSummoned() then
		ApplyDamage({
			victim = kv.target,
			attacker = kv.caster,
			damage = kv.summon_damage,
			damage_type = DAMAGE_TYPE_MAGICAL,
			damage_flags = DOTA_DAMAGE_FLAG_IGNORES_MAGIC_ARMOR
		})
	end
	kv.target:AddNewModifier(kv.caster, kv.ability, "cf_mo_nagasiren_purge", {
		duration = kv.duration,
		as_slow = kv.as_slow,
		ms_slow = kv.ms_slow
	})
	kv.target:Purge(true, false, false, false, false)
end

function cf_ab_naga_summonlobster( kv )
	-- print("cf_ab_naga_summonlobster")
	-- PrintTable(kv)
	for i=1,kv.ability:GetKeyValue("cf_unitcount") do
		-- print(i)
		local unit = CreateUnitByName(
			kv.ability:GetKeyValue("cf_unitname"),
			kv.caster:GetAbsOrigin(),
			true,
			kv.caster:GetOwner(), 
			kv.caster:GetOwner(),
			kv.caster:GetTeamNumber()
		)
		-- print(unit:GetUnitName(),unit:IsSummoned())
		unit:AddNewModifier(kv.caster, kv.ability, "modifier_kill", {duration = kv.duration })
	end
end

function cf_ab_earthquake( kv )
	-- print("cf_ab_earthquake",kv.duration)
	-- kv.particle

	local target = kv.ability:GetValidCastTarget(kv.caster)

	if target then
		-- print("target:",target:GetUnitName(),target:GetAbsOrigin())
		-- local pos = target:GetAbsOrigin()
		print("caster",kv.caster)
		local th = CreateModifierThinker(
			kv.caster,
			kv.ability,
			"cf_mo_naga_earthquake",
			{ 
				duration = kv.duration,
				as_slow = kv.as_slow,
				ms_slow = kv.ms_slow,
				-- pos = pos,
				radius = kv.radius,
				aoe = kv.aoe,
				dmg_to_ground = kv.dmg_to_ground,
				particle = kv.particle
			},
			target:GetAbsOrigin(),
			kv.caster:GetTeamNumber(),
			false
		)
		-- print("Thinker:",th)
		-- print("")
	end
end