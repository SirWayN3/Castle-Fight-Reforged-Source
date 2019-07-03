

function cf_item_cheese( event )
	print( "cf_item_cheese")
	-- PrintTable( event )
	event.caster:ModifyEssence( event.essence )
	-- event.caster:RemoveItem(event.ability)
	print( "cf_item_cheese")
end

function cf_item_damage( event )
	print ( "cf_item_damage: Apply ",event.EventName)
	-- PrintTable ( event )
	local multiplier = nil
	if event.EventName == "DamageDouble" then
		multiplier = 100
	elseif event.EventName == "DamageQuad" then
		multiplier = 300
	end
	local units = FindUnitsInRadius(
		event.caster:GetTeamNumber(),
		Vector(0,0,0),
		nil,
		FIND_UNITS_EVERYWHERE,
		DOTA_UNIT_TARGET_TEAM_FRIENDLY,
		DOTA_UNIT_TARGET_CREEP,
		DOTA_UNIT_TARGET_FLAG_NONE,
		FIND_ANY_ORDER,
		false
		)
	-- print("","Units: ")
	-- PrintTable( units )
	-- print("")

	print ( "Damage Multiplier: " .. multiplier )
	local mo = 0
	local stack = 0
	if units[1] ~= nil then
		for _,unit in pairs( units ) do
			print ( unit:GetEntityIndex())
			-- 
			
			mo = unit:AddNewModifier(
				-- nil,
				event.caster,
				event.ability,
				"cf_mo_cr_damage",
				{ duration = 30 }
				)
			-- stack = multiplier / 100 * unit:GetBaseDamageMin()
			stack = multiplier
			mo:SetStackCount( stack )
		end
	end
	-- event.caster:RemoveItem(event.ability)
	print ( "cf_item_damage: Apply ",event.EventName)
end

function cf_item_restorationstone(event)
	local mo = event.caster:FindModifierByName(event.mo_name)
	mo:SetStackCount( mo:GetStackCount() + event.charges )
	local ab = mo:GetAbility()
	ab:SetActivated(true)
end


function cf_item_orb_of_lightning(keys)
	-- Init Cast from Item
	local caster = keys.caster
	local target = keys.target
	local ability = keys.ability
	local event = keys.EventName

	-- print ("cf_item_orb_of_lightning",event)
	if event == "OnCreated" then
		-- PrintTable( keys )
		-- Fill Ability with Information, need to gather only once
		ability.bridge_delay = ability:GetSpecialValueFor("bridge_delay")
		ability.bridge_range = ability:GetSpecialValueFor("bridge_range")
		ability.bridge_count_init = ability:GetSpecialValueFor("bridge_count")
		ability.bridge_damage_reduction = ability:GetSpecialValueFor("bridge_reduction_perc")
		ability.damage_init = ability:GetAbilityDamage()
		ability.damage_type = ability:GetAbilityDamageType()

	elseif event == "OnSpellStart" then
		-- Fill Information Used for Instances
		keys.bridge_count = ability.bridge_count_init
		keys.damage_current = ability.damage_init
		
		local lightningBolt = ParticleManager:CreateParticle(keys.particle, PATTACH_WORLDORIGIN, target)
		ParticleManager:SetParticleControl(lightningBolt,0,Vector(target:GetAbsOrigin().x,target:GetAbsOrigin().y,target:GetAbsOrigin().z + target:GetBoundingMaxs().z ))   
		ParticleManager:SetParticleControl(lightningBolt,1,Vector(target:GetAbsOrigin().x,target:GetAbsOrigin().y,target:GetAbsOrigin().z + target:GetBoundingMaxs().z ))
		
		-- Damage first Unit hit
		-- ApplyDamage(
		-- 	{
		-- 		victim = target,
		-- 		attacker = caster,
		-- 		damage = keys.damage_current,
		-- 		damage_type = ability.damage_type
		-- 	}
		-- )
		-- ability.bridge_count_current = ability.bridge_count_current - 1
		-- ability.damage_current = ability.damage_current * ability.bridge_damage_reduction * /100

		-- Call self with delay, with other key data
		keys.EventName = "OnSpellJump"
		-- keys.damage_current = 200 -- Testing
		keys.unit_hit = {}
		-- keys.particle = "particles/units/heroes/hero_zuus/zuus_lightning_bolt.vpcf"
		-- keys.damage_current = keys.damage_current * (1-ability.bridge_damage_reduction / 100)
		-- keys.bridge_count = keys.bridge_count -1
		-- keys.target = target

		-- store current target in keys, do not jump to already hit targets
		keys.unit_hit[keys.bridge_count] = keys.target:GetEntityIndex()

		Timers:CreateTimer(ability.bridge_delay,
		-- Timers:CreateTimer(0.5,
			function()
			cf_item_orb_of_lightning( keys )
			end)

	elseif event == "OnSpellJump" then
		-- Applies damage to the next or first target, regarding damage loss etc.
		-- print("")
		-- print("")
		-- print("")
		-- print("Instance: ",keys.bridge_count)
		-- PrintTable( keys )
		-- store current target in keys, do not jump to already hit targets
		-- keys.unit_hit[keys.bridge_count] = keys.target

		-- PrintTable( keys.unit_hit )
		-- Apply Damage to the hit unit.
		ApplyDamage(
			{
				victim = target,
				attacker = caster,
				damage = keys.damage_current,
				damage_type = ability.damage_type
			}
		)
		
		-- Decrements our jump count and damage for this instance
		keys.bridge_count = keys.bridge_count -1
		keys.damage_current = keys.damage_current * (1-ability.bridge_damage_reduction / 100)
	
		-- Checks if there are jumps left
		if keys.bridge_count > 0 then
			-- Finds units in the radius to jump to
			local units = FindUnitsInRadius(caster:GetTeamNumber(), target:GetAbsOrigin(), nil, ability.bridge_range, ability:GetAbilityTargetTeam(), ability:GetAbilityTargetType(), ability:GetAbilityTargetFlags(), FIND_CLOSEST, false)
			-- PrintTable( units )
			local index = nil
			local new_target = nil
			for j,o in pairs(units) do
				index = o:GetEntityIndex()

				for k,v in pairs(keys.unit_hit) do
					-- print ("",k,v,j,index)
					if index ~= v then
						new_target = o
						-- print("new_target",new_target:GetEntityIndex())
						-- break
					else
						-- recently found target is NOT valid
						new_target = nil
						-- print("new_target: DELETE")
						break
					end
				end
				-- new target has been found
				if new_target then break end
			end
			-- Checks if there is a new target
			if new_target ~= nil then
				-- print( "new_target:",new_target:GetEntityIndex())
				-- Creates the particle between the new target and the last target
				local lightningBolt = ParticleManager:CreateParticle(keys.particle_jump, PATTACH_WORLDORIGIN, target)
				ParticleManager:SetParticleControl(lightningBolt,0,Vector(target:GetAbsOrigin().x,target:GetAbsOrigin().y,target:GetAbsOrigin().z + target:GetBoundingMaxs().z ))   
				ParticleManager:SetParticleControl(lightningBolt,1,Vector(new_target:GetAbsOrigin().x,new_target:GetAbsOrigin().y,new_target:GetAbsOrigin().z + new_target:GetBoundingMaxs().z ))
				-- Sets the new target as the current target for this instance
				-- ability.target[current] = new_target
				-- print ( "new_target", new_target)

				keys.target = new_target
				-- store current target in keys, do not jump to already hit targets
				keys.unit_hit[keys.bridge_count] = new_target:GetEntityIndex()
				-- PrintTable( keys.unit_hit )

				Timers:CreateTimer(ability.bridge_delay,
				-- Timers:CreateTimer(2,
					function()
					cf_item_orb_of_lightning( keys )
					end)
				-- Applies the modifer to the new target, which runs this function on it
				-- ability:ApplyDataDrivenModifier(caster, new_target, "modifier_arc_lightning_datadriven", {})
			else
				-- If there are no new targets, this instance is over
				-- print( " no more targets")
			end
		else
			-- If there are no more jumps, this instance is over
			-- print(" no more Jumps possible")
		end
	end
end

