-- Evaluate the state of the game
function CCastleFightReforged:OnThink()
	-- print( "Castle Fight Reforged addon script is running." )

	self.StateMachine()


	return 1
end


function CCastleFightReforged:OnScriptReload()
	print("")
	print("")
	print("Castle Fight Reforged Addon: Reloaded.")
	LoadGameKeyValues()
	-- GameRules:Playtesting_UpdateAddOnKeyValues()
	-- ReloadMOTD()

	
	-- cf_SetTables_TopBar_steamID(0)
	-- cf_SetTables_TopBar_builder(0)
	-- HeroSelection:Init()
	-- cf_SetTables_TopBar_CState(0)



end



function CCastleFightReforged:OnNPCSpawned( event )
	if not IsServer() then return end

	local hUnit = EntIndexToHScript( event.entindex )
	local playerID = hUnit:GetPlayerOwnerID()

	if hUnit:IsRealHero() then
		-- print("OnNPCSpawned: IsHero")
		-- print( hUnit:GetUnitName() )

		
		-- print("SetMana from Unit " .. hUnit:GetMana() )
		-- Set Starting Values, Items etc.
		-- local param = {
		-- 	unit = hUnit,
		-- 	setmana = 0,
		-- }
		-- cf_dbg( "OnNPCSpawned: Debug Edit.")
		-- cf_dbg( "Owner: " .. hUnit:GetPlayerOwnerID())
		-- Save Builder ID for later usage
		if IsBuilder(hUnit) then 
			if cf_testmode() then
				hUnit:AddAbility("cf_00_ab_builder_test1")
				hUnit:AddAbility("cf_00_ab_builder_test2")
				hUnit:AddAbility("cf_00_ab_builder_test3")
			end
			if cf_playertable[playerID] == nil then -- Happens with Bots
				local t = {}
				t.PlayerID = playerID
				CCastleFightReforged:OnConnectFull( t )
			end

			hUnit:SetAllAbilitiesLevel(1)
			cf_playertable[playerID].isReady = true
			cf_playertable[playerID].builder = {}
			cf_playertable[playerID].builder.unit = hUnit
			cf_playertable[playerID].builder.name = hUnit:GetUnitName()
			cf_playertable[playerID].builder.ent = hUnit:GetEntityIndex()
			cf_playertable[playerID].builder.abilities = {}

			cf_playertable[playerID].teamnumber = hUnit:GetTeamNumber()
			for i=1,10 do
				cf_playertable[playerID].builder.abilities[i] = hUnit:GetAbilityByIndex(i+10-1-1)
			end

			-- Set Builder Properties
	    	Timers:CreateTimer(CF_UNIT_SPAWNED_TIMEFORORDER, 
	    		function()
	    			-- if not CF_DEBUG then 
					-- hUnit:SetMana( 0 )
					-- end
					-- hUnit:AddNewModifier(hUnit, nil, "modifier_invulnerable", {} )
					hUnit:AddNewModifier(hUnit, nil, "cf_mo_builder", {})
	    		end
	    	)
	    
			
			cf_resources_sendtopanorama(playerID)
			-- cf_setpanorama_attackdefensetable( playerID )
			cf_setpanorama_shop(playerID)
			cf_setpanorama_abilites( playerID )
			cf_SetTables_TopBar_builder(playerID)
		end

	elseif hUnit:GetName() == "npc_dota_creature" and not hUnit:IsCorpse() then
		hUnit:SetAllAbilitiesLevel(1)

		if cf_testmode() then
			hUnit:SetControllableByPlayer(0, true)
		end

		hUnit:AddNewModifier(hUnit:GetOwner(), nil, "cf_mo_cr_ai", {})

		-- print( hUnit )
	-- elseif hUnit:GetName() == "npc_dota_fort" then
		-- hUnit:AddNewModifier(hUnit, nil, "modifier_building", {})
		-- print("NPC_DOTA_FORT Spawned. Check for modifier applied.",hUnit:HasModifier("modifier_building") )

	-- elseif hUnit:GetName() == "npc_dota_building" then
		-- PrintTable(hUnit)
		-- print( "npc_dota_building: " .. hUnit:GetName() ,hUnit:GetOwner())
		-- hUnit:AddNewModifier(hUnit:GetOwner(), nil, "cf_mo_bu_attack_ai", {})



	end
end
function CCastleFightReforged:OnEntityKilled( kv )
	-- print("OnEntityKilled")
	local killed = EntIndexToHScript( kv.entindex_killed )
	-- local attacker = EntIndexToHScript( kv.entindex_attacker )
	local pID = killed:GetPlayerOwnerID()
	-- print(killed:IsCreature())
	if killed:IsCreature() then
		-- print("OnEntityKilled",killed:GetUnitName())
		if killed:HasCorpse() then
			local pos = killed:GetAbsOrigin()
			local owner = killed:GetOwner()
			local team = killed:GetTeamNumber()
			local name = killed:GetUnitName()
			-- print("OnEntityKilled Leave Corpse: ",killed:HasCorpse())
			Timers:CreateTimer(CF_UNIT_CORPSE_DELAY,function() 
				-- Create Corpse
				local corpse = CreateUnitByName(
					"cf_corpse",
					pos,
					true,
					owner,
					owner,
					team
				)
				corpse.unit_name = name
				corpse:AddNewModifier(nil,
					nil,
					"cf_mo_cr_corpse",
					{duration = -1 }
				)
				if not killed:IsNull() then UTIL_Remove(killed) end
			end)
		end
	end
end
function CCastleFightReforged:Build_Abilities( keys)
	-- Call from Panorma with Custom Ability Buttons

	-- print ( "Build Abilities Custom: PlayerID: " .. keys.player )
	-- print ( "Ability Name: " .. keys.abilityEnt )
	-- local builder = cf_playertable[keys.playerID].builder.unit
	-- local ability = cf_playertable[keys.playerID].builder.abilities[keys.abilityID]

	-- print ( ability:GetAbilityName() )
	local builder = EntIndexToHScript(keys.builder)
	local ability =  EntIndexToHScript(keys.abilityEnt)
	local gold_cost = ability:GetGoldCost()
	local energy_cost = ability:GetEnergyCost()
	local essence_cost = ability:GetEssenceCost()
	local playerID = keys.player
	-- PrintTable(cf_playertable)
	if 
		builder:GetEnergy() >= energy_cost
	then
		if
			builder:GetGold() >= gold_cost
		then
			if 
				builder:GetEssence() >= essence_cost
			then
				-- builder:ModifyGold(-gold_cost, false, 0)
			    -- builder:ModifyMana(-energy_cost )
				builder:CastAbilityNoTarget(ability, playerID)
			else
                DebugPrint("Failed placement of - Not enough essence!")
                SendErrorMessage(playerID, "#error_not_enough_essence")
			end
		else
            DebugPrint("Failed placement of - Not enough gold!")
            SendErrorMessage(playerID, "#error_not_enough_gold")
		end

	else
        DebugPrint("Failed placement of - Not enough energy!")
        SendErrorMessage(playerID, "#error_not_enough_energy")

	end
end

-- modified builder.lua [event:OnConstructionStarted] for the call of this function. nocallback possible yet. 23.02.2019
function CCastleFightReforged:OnBuildingStarted( kv )
	-- print("OnBuildingStarted")
	-- PrintTable(keys)
	cf_income_addbyunit( kv.unit ) -- income shall be raised with spent gold
	
	-- Check new Unit for Ability Levels, set them to 0
	for i=0,kv.unit:GetAbilityCount() -1 do
		local hAbility = kv.unit:GetAbilityByIndex(i)
		if hAbility ~= nil then hAbility:SetLevel(0) end
	end
	kv.unit:AddNewModifier( kv.unit, nil, "cf_mo_bu_building_particle", { duration = kv.duration } )
	
	if kv.eventName ~= "Upgrade" then cf_quests:OnBuildingStarted( kv ) end
end

-- modified builder.lua [event:OnConstructionCompleted] for the call of this function. nocallback possible yet. 23.02.2019
-- another Entry Point from Building Upgrade Lua
function CCastleFightReforged:OnBuildingFinished( keys )
	-- print("OnBuildingFinished")
	-- PrintTable(keys)
	-- print(keys.unit:GetUnitName() )
	-- print(keys.unit.buildingTable.UnitName)
	-- print( GetUnitKV(keys.unit:GetUnitName(),"cf_spawner" ) )
	local unit = keys.unit
	local unitname = unit:GetUnitName()

	if cf_testmode() then
		unit:AddAbility("cf_00_common_ab_bu_destroy")
	end
	
	unit:SetAllAbilitiesLevel(1)
	-- PrintTable ( unit )
	-- print ("","")
	local ab = unit:FindAbilityByName("cf_00_common_ab_bu_toggleautocast")
	if ab ~= nil then ab:ToggleAbility() end
	

	unit:AddNewModifier(unit:GetOwner(), nil, "cf_mo_bu_attack_ai", {})
	-- cf_income_addbyunit( keys.unit ) -- Removed, income shall be raised with spent gold
end

function CCastleFightReforged:OnBuildingUpgradeStarted ( keys )
	-- print("OnBuildingUpgradeStarted")
	keys.eventName = "Upgrade"
	CCastleFightReforged:OnBuildingStarted(keys)
end

function CCastleFightReforged:OnBuildingUpgradeFinished ( keys )
	-- print("OnBuildingUpgradeFinished")
	keys.eventName = "Upgrade"
	CCastleFightReforged:OnBuildingFinished(keys)
end


-- This function is called once when the player fully connects and becomes "Ready" during Loading
function CCastleFightReforged:OnConnectFull(keys)
	DebugPrint("Player fully connected.")
	-- PrintTable(keys)

	-- CCastleFightReforged:CaptureGameMode()

	local playerID = keys.PlayerID
	

	if cf_playertable == nil then cf_playertable = {} end
	cf_playertable[playerID] = {}
	cf_playertable[playerID].player = PlayerResource:GetPlayer(playerID)
	cf_playertable[playerID].steamID = PlayerResource:GetSteamID(playerID)
	cf_playertable[playerID].IsHost = GameRules:PlayerHasCustomGameHostPrivileges(PlayerResource:GetPlayer(playerID))
	CustomGameEventManager:Send_ServerToPlayer(PlayerResource:GetPlayer(playerID), "cf_player_SetHost", { isHost = cf_playertable[playerID].IsHost } )
	-- PlayerResource:OnPlayerConnect(keys)

	cf_SetTables_TopBar_steamID( playerID )
	cf_SetTables_TopBar_CState(playerID)
	cf_income_playerinit( playerID )
end

function CCastleFightReforged:OnDisconnect( keys )
	print("OnDisconnect")
	PrintTable(keys)
	-- return
	-- local msg = ( 
		-- PlayerResource:GetPlayerName(keys.PlayerID)
	-- )
	Notifications:TopToAll({ text = msg , duration = 10.0, style = { color = "red" }})

	cf_SetTables_TopBar_CState(playerID)
end
function CCastleFightReforged:OnPlayerReconnect( keys )


	cf_setpanorama_abilites(keys.PlayerID)
	cf_setpanorama_shop(keys.PlayerID)
	cf_SetTables_TopBar_CState(playerID)
end


