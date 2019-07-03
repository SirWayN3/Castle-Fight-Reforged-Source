

function cf_ab_artillery_OnSpellStart( event )
	-- print("cf_ab_artillery_OnSpellStart")
	-- PrintTable( event )
	local ability = event.ability
	local caster = event.caster
	-- local target = Entities:FindByName
	-- use cf_table_pathcorner.area_left OR cf_table_pathcorner.area_right to get .x1, .x2, .y1, .y2
	local x = nil
	local y = nil
	local z = 0

	if caster:GetTeamNumber() == CF_TEAM_NUMBER_LEFT then
		x = RandomFloat(cf_table_pathcorner.area_right.x1, cf_table_pathcorner.area_right.x2)
		y = RandomFloat(cf_table_pathcorner.area_right.y1, cf_table_pathcorner.area_right.y2)
	else
		x = RandomFloat(cf_table_pathcorner.area_left.x1, cf_table_pathcorner.area_left.x2)
		y = RandomFloat(cf_table_pathcorner.area_left.y1, cf_table_pathcorner.area_left.y2)
	end
	-- print ("x: " .. x .. " y: "..y)
	local point = Vector(x,y,z)
	-- point = Entities:FindByName(nil, "cf_01_bu_01_barracks"):GetAbsOrigin()
	-- local point = Vector(-7400,1000,0)
	local timetoimpact = ability:GetSpecialValueFor("timetoimpact")
	local burnduration = ability:GetSpecialValueFor("burnduration")
	local damage = RandomInt( ability:GetSpecialValueFor("damage_min"), ability:GetSpecialValueFor("damage_max") )
	local damagetype = ability:GetAbilityDamageType()
	local burnradius = ability:GetSpecialValueFor("radius")
	-- print ( burnradius, burnduration, damage)
	-- print ( target )
	-- print (
	-- 		ability:GetAbilityTargetTeam(),
	-- 		ability:GetAbilityTargetType()
	-- 	)
	local particle = nil
	Timers:CreateTimer(timetoimpact, function()
		-- Impact Particle
		particle = ParticleManager:CreateParticle(
			ability:GetKeyValue("particle_impact"),
			PATTACH_POINT,
			caster
		)
		Timers:CreateTimer( 5, function()
			ParticleManager:DestroyParticle(particle, false)
			end
		)
		ParticleManager:SetParticleControl(particle, 0, point)

		-- print (" Find Targets, Apply Damage missing. Use Ability TargetType ect. to make damage.")
		local enemies = FindUnitsInRadius(
			caster:GetTeamNumber(),
			point,
			nil,
			burnradius,
			ability:GetAbilityTargetTeam(),
			ability:GetAbilityTargetType(),
			DOTA_UNIT_TARGET_FLAG_MAGIC_IMMUNE_ENEMIES,
			FIND_ANY_ORDER,
			false
		)
		-- PrintTable( enemies )
		-- print ( enemies[1] )
		if enemies[1] then
			for k,v in pairs(enemies) do
				-- print(k,v,v:GetUnitName())
				-- print ( v:GetUnitName() )
				local damage = {
					victim = v,
					attacker = caster,
					damage = damage,
					damage_type = damagetype,
					damage_flags = DOTA_DAMAGE_FLAG_BYPASSES_BLOCK,
					ability = ability, --Optional.
				}
				ApplyDamage(damage)
			end
		else
			-- print ( "no unit hit with artillery strike" )
		end
		
	end
	)
	-- print ("")
end
