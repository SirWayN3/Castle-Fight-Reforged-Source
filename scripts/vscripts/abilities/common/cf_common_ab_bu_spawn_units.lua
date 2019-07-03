

function cf_common_ab_bu_spawn_units_OnSpellStart( event )
	-- print("cf_common_ab_bu_spawn_units:OnSpellStart")
	-- PrintTable( event )
	-- local hParent = self:GetCaster()
	local hParent = event.caster
	local hAbility = event.ability
	local hOwner = hParent:GetOwner()
	local vPos = hParent:GetAbsOrigin() + Vector(0,-50,0)

	-- print( tostring( hParent:IsBuilding() ) )
	-- print (tostring( hParent:HasModifier("modifier_heroic_shrine_bonus") ))
	-- hParent:ForceKill( false )

	-- hParent:AddNewModifier(hParent, nil, "cf_mo_bu_destroy", {duration = -1 })
	-- hParent:RemoveModifierByName("cf_mo_bu_autocast")
	local iLevel = hAbility:GetLevel()
	local sUnitName = hAbility:GetKeyValue("cf_unit_name", iLevel)
	local iUnitCount = hAbility:GetKeyValue("cf_unit_count", iLevel)
	local iABIsSpawner = hAbility:GetKeyValue("cf_ab_spawner")
	-- Debug
	-- print ( 'hParent: ' .. hParent:GetUnitName() .. ' Team:' .. hParent:GetTeam() .. ' Other Team:' .. DOTA_TEAM_CUSTOM_2)
	-- print ( "cf_common_ab_bu_spawn_units_OnSpellStart: AB Name: " .. hAbility:GetAbilityName() )
	-- print("OnIntervalThink: " .. tostring(sUnitName) .. ' ' .. tostring(iUnitCount) .. ' ' .. iLevel)

	-- end
	-- print ( tostring( hParent:HasModifier( CF_HEROIC_SHRINE_MODIFIER_NAME ) ) )
	local hUnit = nil
	if sUnitName ~= nil and iUnitCount ~= 0 and iABIsSpawner == 1 then
		if hParent:HasModifier( CF_HEROIC_SHRINE_MODIFIER_NAME ) then
			local val = RandomInt(0,100)
			
			if val < CF_HEROIC_SHRINE_MODIFIER_CHANCE * 100 then
				-- print ( " HIT ")
				Timers:CreateTimer(CF_HEROIC_SHRINE_DELAY, function()
					for k=1,iUnitCount do
						hUnit = CreateUnitByName(sUnitName, vPos, true, hOwner, hOwner, hParent:GetTeam())
					end
					-- CreateUnitByName(sUnitName, vPos, true, hOwner, hOwner, hParent:GetTeam() )
					local particle = ParticleManager:CreateParticle(CF_HEROIC_SHRINE_MODIFIER_PARTICLE, PATTACH_ABSORIGIN_FOLLOW, hUnit)
					ParticleManager:SetParticleControl(particle, 0, hUnit:GetAbsOrigin())
					Timers:CreateTimer(5, function() 
				    	ParticleManager:DestroyParticle(particle,false)
					end)
				end)
			end
		end
		for k=1,iUnitCount do
			hUnit = CreateUnitByName(sUnitName, vPos, true, hOwner, hOwner, hParent:GetTeam())
		end
	end
end


