--[[
 Hero selection module for D2E.
 This file basically just separates the functions related to hero selection from
 the other functions present in D2E.
]]

--Constant parameters
-- SELECTION_DURATION_LIMIT = 60
SELECTION_DURATION_LIMIT = CF_PICKING_TIME

--Class definition
if HeroSelection == nil then
	HeroSelection = {}
	HeroSelection.__index = HeroSelection
	print( "HeroSelection LUA has been built." )
end

--[[
	Start
	Call this function from your gamemode once the gamestate changes
	to pre-game to start the hero selection.
]]
function HeroSelection:Start()
	--Figure out which players have to pick
	HeroSelection.playerPicks = {}
	HeroSelection.numPickers = 0
	for pID = 0, DOTA_MAX_PLAYERS -1 do
		if PlayerResource:IsValidPlayer( pID ) then -- Works with Bots
			HeroSelection.playerPicks[pID] = {}
			HeroSelection.playerPicks[pID].picked = false
			HeroSelection.playerPicks[pID].hero = ""
			HeroSelection.numPickers = HeroSelection.numPickers + 1
		end
		-- print("Hero Selection: Start",pID,PlayerResource:IsValidPlayer(pID))
	end

	--Start the pick timer
	HeroSelection.TimeLeft = SELECTION_DURATION_LIMIT
	Timers:CreateTimer( 0.04, HeroSelection.Tick )

	--Keep track of the number of players that have picked
	HeroSelection.playersPicked = 0

	--Listen for the pick event
	HeroSelection.listener = {}
	HeroSelection.listener["select"] = CustomGameEventManager:RegisterListener( "hero_selected", HeroSelection.HeroSelect )
	-- PrintTable(self)
end

function HeroSelection:Init( )
	-- print("Set Selectable Hero")
	local t = {}
	local n = 0
	HeroSelection.SelectableHeroes = {}
	for k,v in pairs( KeyValues.UnitKV ) do
		if v.cf_builder_id then
			-- if v.cf_builder_ready == 1 then
				HeroSelection.SelectableHeroes[v.cf_builder_id] = {}
				HeroSelection.SelectableHeroes[v.cf_builder_id].HeroName = k

				if cf_testmode() or CF_DEBUG_ALLHEROES_ENABLED then
				-- if CF_DEBUG_ALLHEROES_ENABLED then
					-- HeroSelection.SelectableHeroes[v.cf_builder_id].IsReady = (v.cf_builder_ready > 0)
					HeroSelection.SelectableHeroes[v.cf_builder_id].IsReady = true
				else
					HeroSelection.SelectableHeroes[v.cf_builder_id].IsReady = (v.cf_builder_ready == 1)
				end
			-- end
		end
	end

	for k,v in pairs(HeroSelection.SelectableHeroes) do
		-- if v.IsReady then
			n = n +1
			t[n] = v
		-- end
	end
	HeroSelection.SelectableHeroes = t
	-- PrintTable(HeroSelection.SelectableHeroes)
	-- Set all Heros for Picking Screen
	CustomNetTables:SetTableValue("cf_heroselection", "SelectableHeroes", HeroSelection.SelectableHeroes)
	local n = 0
	HeroSelection.HeroList = {}
	for k,v in pairs(HeroSelection.SelectableHeroes) do
		if v.IsReady then
			n = n +1
			HeroSelection.HeroList[n] = v
		end
	end
end
--[[
	Tick
	A tick of the pick timer.
	Params:
		- event {table} - A table containing PlayerID and HeroID.
]]
function HeroSelection:Tick() 
	--Send a time update to all clients
	if HeroSelection.TimeLeft >= 0 then
		CustomGameEventManager:Send_ServerToAllClients( "picking_time_update", {time = HeroSelection.TimeLeft} )
	else
		return nil
	end

	--Tick away a second of time
	HeroSelection.TimeLeft = HeroSelection.TimeLeft - 1
	-- if IsInToolsMode() then HeroSelection.TimeLeft = HeroSelection.TimeLeft + 1 end
	if HeroSelection.TimeLeft == -1 then
		--End picking phase

		HeroSelection:EndPicking()
		return nil
	elseif HeroSelection.TimeLeft >= 0 then
		return 1 -- Return to Timers
	else
		return nil
	end
end

--[[
	HeroSelect
	A player has selected a hero. This function is called by the CustomGameEventManager
	once a 'hero_selected' event was seen.
	Params:
		- event {table} - A table containing PlayerID and HeroID.
]]
function HeroSelection:HeroSelect( event )
	-- print("HeroSelect")

	if HeroSelection.playerPicks[ event.PlayerID ].picked == false then
		HeroSelection.playerPicks[ event.PlayerID ].picked = true

		HeroSelection.playersPicked = HeroSelection.playersPicked + 1
		HeroSelection.playerPicks[ event.PlayerID ].hero = event.HeroName

		--Send a pick event to all clients
		CustomGameEventManager:Send_ServerToAllClients( "picking_player_pick", 
			{ PlayerID = event.PlayerID, HeroName = event.HeroName} )

		-- Assign the hero if picking is over
		-- if HeroSelection.TimeLeft <= 0 then
			-- HeroSelection:AssignHero( event.PlayerID, event.HeroName )
		-- end
	end

	--Check if all heroes have been picked
	if HeroSelection.playersPicked >= HeroSelection.numPickers then
		--End picking
		HeroSelection.TimeLeft = 0
		HeroSelection:Tick()
	end
end
--[[
	EndPicking
	The final function of hero selection which is called once the selection is done.
	This function spawns the heroes for the players and signals the picking screen
	to disappear.
]]
function HeroSelection:EndPicking()
	-- print("EndPicking")
	--Stop listening to pick events
	if not IsInToolsMode() then
		for k,v in pairs(HeroSelection.listener) do
			-- print(k,v)
			CustomGameEventManager:UnregisterListener( v )
		end
	end

	--Assign the picked heroes to all players that have picked
	for pID, t in pairs( HeroSelection.playerPicks ) do
		-- Check for not picked players, give them Random Heroes
		-- print( "HeroSelection:Endpicking",pID)
		-- PrintTable(t)
		if not t.picked then
			local k = RandomInt(1,TableLength(HeroSelection.HeroList))
			local kv = {}
			-- print(pID,k,n)
			-- PrintTable(herolist)
			-- PrintTable(HeroSelection.SelectableHeroes)
			kv.HeroName = HeroSelection.HeroList[k].HeroName
			kv.PlayerID = pID
			kv.HeroID = k
			HeroSelection:HeroSelect( kv )

			HeroSelection:AssignHero( pID, kv.HeroName )
			-- print("HeroSelection:Endpicking: Assign Random Hero for pID: " .. pID .. " " .. kv.HeroName)
		else
			HeroSelection:AssignHero( pID, HeroSelection.playerPicks[ pID ].hero )
		end
	end

	--Signal the picking screen to disappear
	CustomGameEventManager:Send_ServerToAllClients( "picking_done", {} )
end

--[[
	AssignHero
	Assign a hero to the player. Replaces the current hero of the player
	with the selected hero, after it has finished precaching.
	Params:
		- player {integer} - The playerID of the player to assign to.
		- hero {string} - The unit name of the hero to assign (e.g. 'npc_dota_hero_rubick')
]]
function HeroSelection:AssignHero( pID, hero )

	PrecacheUnitByNameAsync( hero, function()
		-- 28.02.2019 Changed by SirWayNe, Replace with Proper Gold Value
		-- PlayerResource:ReplaceHeroWith( pID, hero, 0, 0 )
		PlayerResource:ReplaceHeroWith( pID, hero, PlayerResource:GetGold( pID ) , 0)
	end, pID)
end

