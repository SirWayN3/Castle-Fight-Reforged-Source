function cf_ab_defend( event )
	-- print("cf_ab_defend")
	-- PrintTable(event)

	-- event.damage = 0
	-- event.target:Heal(event.damage / 2, nil)
	if event.attacker:IsRangedAttacker() then
		local attacktype = event.attacker:CF_GetAttackType()
		local defensetype = event.unit:CF_GetDefenseType()

		-- local reduction = CF_GetArmorReductionPerc( event.unit:cf_GetPhysicalArmor() )
		local dmgmodifier = CF_GetDamageModifier( attacktype, defensetype )
		-- local heal = event.damage * reduction * dmgmodifier
		local heal = event.damage * dmgmodifier

		if RandomInt(0, 100) < event.ranged_reflect then
			-- Reduce Attack Damage
			heal = heal * (100 - event.ranged_reduction) / 100
			
			-- print("block","heal:",heal)
			if (event.unit:GetHealth() - heal) >= 1 then
				event.unit:ModifyHealth(heal,event.ability,false)
			end
		else
			-- Reflect Ranged Attack
			-- print("reflect","heal:",heal)
			if (event.unit:GetHealth() - heal) >= 1 then
				event.unit:ModifyHealth(heal,event.ability,false)

				-- Reflect here, since the unit is not dead
				local p = {
					Target = event.attacker,
					Source = event.unit,
					Ability = event.ability,
					iMoveSpeed = event.attacker:GetProjectileSpeed(),
					EffectName = event.attacker:GetRangedProjectileName(),
					vSourceLoc = event.unit:GetAbsOrigin(),
					flExpireTime = GameRules:GetGameTime() + 10,

				}
				ProjectileManager:CreateTrackingProjectile(p)
			end
		end
	end
end

function cf_ab_defend_projectile( event )
	-- PrintTable( event )
	ApplyDamage( {
		victim=event.target,
		attacker=event.caster,
		damage=event.target:GetAttackDamage(),
		damage_type=DAMAGE_TYPE_PHYSICAL,
		
	})
end

