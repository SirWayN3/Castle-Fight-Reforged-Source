function cf_ab_cr_splash ( kv )
	-- PrintTable( kv )
	local t = {}
	t.attacker = kv.attacker
	t.damage_type = DAMAGE_TYPE_PHYSICAL
	t.damage = kv.damage
	if kv.radius_inner and kv.dmg_inner_perc then
		local enemies = FindUnitsInRadius(
			kv.caster:GetTeamNumber(),
			kv.target:GetAbsOrigin(),
			nil,
			kv.radius_inner,
			DOTA_UNIT_TARGET_TEAM_ENEMY,
			kv.ability:GetAbilityTargetType(),
			DOTA_UNIT_TARGET_FLAG_MAGIC_IMMUNE_ENEMIES,
			FIND_CLOSEST,
			false
		)
		t.damage = t.damage * kv.dmg_inner_perc
		for k,v in pairs(enemies) do
			if k ~= 1 and not v:HasFlyMovementCapability() then -- ignore first Unit found
				t.victim = v
				ApplyDamage(t)
			end

		end
	end
	-- print( kv.ability:GetAbilityTargetTeam(),kv.ability:GetAbilityTargetType())
	if kv.radius_outer and kv.dmg_outer_perc then
		local enemies = FindUnitsInRadius(
			kv.caster:GetTeamNumber(),
			kv.target:GetAbsOrigin(),
			nil,
			kv.radius_outer,
			DOTA_UNIT_TARGET_TEAM_ENEMY,
			kv.ability:GetAbilityTargetType(),
			DOTA_UNIT_TARGET_FLAG_MAGIC_IMMUNE_ENEMIES,
			FIND_CLOSEST,
			false
		)
		t.damage = t.damage * kv.dmg_outer_perc / 100
		for k,v in pairs(enemies) do
			-- print ( k,v,v:GetUnitName())
			if k ~= 1 and not v:HasFlyMovementCapability() then -- ignore first Unit found
				t.victim = v
				ApplyDamage(t)
			end

		end
	end
end
function cf_ab_cr_bash( kv )
	-- PrintTable(kv)
	-- local i = RandomInt(0,100)
	-- print(i,kv.chance)
	if kv.target:IsBuilding() then return end
	if kv.target:MatchesAttackType( kv.attacker:GetAttackTargetType() ) and RandomInt(0,100) <= kv.chance then
		local t = {}
		t.attacker = kv.attacker
		t.victim = kv.target
		t.damage_type = DAMAGE_TYPE_MAGICAL
		t.damage = kv.damage
		-- PrintTable(t)
		ApplyDamage(t)
		kv.target:AddNewModifier(kv.attacker, kv.target, "cf_mo_cr_stunned", {duration = kv.duration})
	end
end



function cf_ab_cr_manaburn_attack( kv )
	-- PrintTable(kv)
	local mana = kv.target:GetMana() or 0
	if mana > 0 then
		if mana > kv.mana_per_hit then
			mana = kv.mana_per_hit
		end
		-- Burn mana
		kv.target:ModifyMana(-mana)
		EmitSoundOn("Hero_Antimage.Manabreak", kv.target)
		ParticleManager:CreateParticle("particles/generic_gameplay/generic_manaburn.vpcf", PATTACH_ABSORIGIN, kv.target)
		if kv.damage_per_burn > 0 then
			t = {}
			t.victim = kv.target
			t.attacker = kv.attacker
			t.damage = mana * kv.damage_per_burn
			t.damage_type = DAMAGE_TYPE_MAGICAL
			t.damage_flags = DOTA_DAMAGE_FLAG_BYPASSES_BLOCK
			ApplyDamage(t)
		end
	end
end

function cf_ab_cr_return( kv )


	local return_damage = kv.attack_damage * kv.reflect_perc / 100
	-- Damage
	if kv.target_type == "Melee" and not kv.attacker:IsRangedAttacker() then
		if kv.attacker:GetTeamNumber() ~= kv.caster:GetTeamNumber() then
			ApplyDamage({ 
				victim = kv.attacker,
				attacker = kv.caster,
				damage = return_damage,
				damage_type = DAMAGE_TYPE_PURE,
				damage_flags = DOTA_DAMAGE_FLAG_REFLECTION
			})
			-- print("done "..return_damage)
			local particle = ParticleManager:CreateParticle("particles/units/heroes/hero_centaur/centaur_return.vpcf", PATTACH_OVERHEAD_FOLLOW, kv.target)
			ParticleManager:SetParticleControl(particle, 0, kv.caster:GetAbsOrigin())
			ParticleManager:SetParticleControl(particle, 1, kv.attacker:GetAbsOrigin())

		end
	end
end

function cf_ab_cr_bounce_attack( kv )
	PrintTable( kv )

	
end


