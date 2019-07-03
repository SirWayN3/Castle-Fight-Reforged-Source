
function cf_builder_common_blink( event )
	-- Blink to Target
	local bPos = false
	local point = event.target_points[1]
	if event.caster:GetTeamNumber() == CF_TEAM_NUMBER_LEFT then
		if 
			point.x > cf_table_pathcorner.area_left.x1 and
			point.x < cf_table_pathcorner.area_left.x2 and
			point.y > cf_table_pathcorner.area_left.y1 and
			point.y < cf_table_pathcorner.area_left.y2
		then 
			bPos = true
		end
	else
		if 
			point.x > cf_table_pathcorner.area_right.x1 and
			point.x < cf_table_pathcorner.area_right.x2 and
			point.y > cf_table_pathcorner.area_right.y1 and
			point.y < cf_table_pathcorner.area_right.y2
		then 
			bPos = true
		end
	end

	if bPos then
		FindClearSpaceForUnit( event.caster, point, true )
	else
		SendErrorMessage(event.caster:GetPlayerOwnerID(), "#error_invalid_blink_position")
	end
end

function cf_builder_common_repair( mo )
	-- Check Modifier for Data
	-- print(cf_builder_common_repair,mo)
	if 
		mo.parent:IsIdle()
		and mo.ab_repair:IsFullyCastable()
		and mo.ab_repair:GetAutoCastState() 
		and not BuildingHelper:IsRepairing(mo.parent)
	then
		local target = mo.ab_repair:GetValidCastTarget(mo.parent)
		-- print(target)
		if target then 
			-- print(target,target:GetUnitName())
			mo.parent:CastAbilityOnTarget(target, mo.ab_repair, mo.ownerID) 
		end
	end
end


function cf_builder_common_rescuestrike( event )
	-- print ("cf_builder_common_rescuestrike")
	-- return
	-- PrintTable( event )
	if event.EventName == "OnCreated" then
		event.caster:SetModifierStackCount(event.mo_name, event.caster, 1)
		return
	end
	local point = event.target_points[1]
	local ability = event.ability
	local caster = event.caster
	local radius = ability:GetKeyValue("AOERadius")
	local abilityTargetType = ability:GetAbilityTargetType()
	local abilityTargetTeam = ability:GetAbilityTargetTeam()
	local abilityDamageType = ability:GetAbilityDamageType()
	local player = event.caster:GetPlayerID()
	local msg = ""
	local mo = caster:FindModifierByName(event.mo_name)

	if event.EventName == "OnSpellStart" then
			-- print (IsInToolsMode())
		if not cf_testmode() then
			mo:SetStackCount(mo:GetStackCount() -1 )
			if mo:GetStackCount() == 0 then
				ability:SetActivated( false )
			end
		end
		-- return
		-- Show Particle
		local particle = ParticleManager:CreateParticle( event.particle , PATTACH_POINT, caster )
		local duration = 5
		-- print ( point )
		ParticleManager:SetParticleControl(particle, 0, point )
		ParticleManager:SetParticleControl(particle, 1, Vector( radius,0,0 ))

		Timers:CreateTimer(duration, function() 
	    	ParticleManager:DestroyParticle(particle,false)
		end)
		-- Play Sound
		-- EmitGlobalSound(CF_RESCUESTRIKE_SOUND)
		
		-- Find Enemies
		local enemies = FindUnitsInRadius(
			caster:GetTeamNumber(),
			point,
			nil,
			radius,
			abilityTargetTeam,
			abilityTargetType,
			DOTA_UNIT_TARGET_FLAG_MAGIC_IMMUNE_ENEMIES,
			FIND_CLOSEST,
			false
		)
		local stats = {}
		stats.bounty = 0
		stats.kills = 0
		stats.damage = 0

		if not enemies[1] then
			-- print("No Enemies on the selection")
		else
			-- print("")
			-- print("enemies:")
			-- PrintTable( enemies )
			-- print("")
			local bounty = 0

			for k,v in pairs( enemies ) do
				if not v:IsCorpse() then 
					-- print(k,v)
					-- print(k,v:GetUnitName())
					bounty = v:GetGoldBounty()
					PlayerResource:ModifyGold( player, bounty, false, 0 )
					stats.bounty = stats.bounty + bounty
					stats.kills = stats.kills + 1
					stats.damage = stats.damage + v:GetHealth()
					v:ForceKill( false )
				end
			end
		end

		-- print( " stats from Rescue Strike:")
		-- PrintTable( stats )
		-- print("")
		---[[
		if stats.kills == 0 then
			msg = PlayerResource:GetPlayerName(player) .. " cf_rescuetrike_wasted "
			-- msg = PlayerResource:GetPlayerName(player) .. " - Wasted Rescue Strike!"
			style = { color = "red" }
		else
			msg = ( 
					PlayerResource:GetPlayerName(player) .. 
					" cf_rescuestrike_kills " .. stats.kills .. 
					" cf_rescuestrike_damage " .. stats.damage .. 
					" cf_rescuestrike_gold " .. stats.bounty
				)
			style = { color = "blue" }
		end
		Notifications:TopToAll({ text = msg , duration = 10.0, style = style})
		--]]
		-- CustomGameEventManager:Send_ServerToAllClients("cf_rescuestrike", stats )
	end
end

