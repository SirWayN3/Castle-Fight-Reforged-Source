

function cf_SetTables_UnitKV()
	-- Fill Net Tables to fit Panorama Entries.
	local t = deepcopy(KeyValues.UnitKV)
	-- print("")
	-- print("cf_SetTables_Panorama")
	-- PrintTable( t )
	for k,v in pairs(t) do
		-- print(k,v)
		CustomNetTables:SetTableValue("cf_unit_kv",k,v)
		-- print ( "   ",CustomNetTables:GetTableValue("cf_unit_kv",k))
		-- PrintTable( CustomNetTables:GetTableValue("cf_unit_kv",k) )
		-- for j,o in pairs(v) do
			-- print(k,j,o)

			-- CustomNetTables:SetTableValue("cf_unit_kv",k,o)
		-- end
	end
end
function cf_SetTables_TopBar_steamID( playerID )
	-- This will Init the NetTable Key
    CustomNetTables:SetTableValue("cf_topbar", "playerID"..playerID, { steamID = PlayerResource:GetSteamID( playerID ) })
end

function cf_SetTables_TopBar_builder( playerID )
	local t = CustomNetTables:GetTableValue("cf_topbar", "playerID"..playerID)
	t.builderName = cf_playertable[playerID].builder.name
	CustomNetTables:SetTableValue("cf_topbar", "playerID"..playerID, t)
	
end

function cf_SetTables_TopBar_CState( playerID )
	local t = CustomNetTables:GetTableValue("cf_topbar", "playerID"..playerID)
	t.CState = PlayerResource:GetConnectionState( playerID)
    CustomNetTables:SetTableValue("cf_topbar", "playerID"..playerID, t)
end

function cf_SetTables_attackdefense( )
	-- Set Panorama Information about Attack and Defense Table

	-- Modify Values: to prevent issues with sending floats
	local t = deepcopy(CF_DAMAGETYPE_MODIFIERS)

	for k,v in pairs( t ) do
		-- print(k,v)
		for j,z in pairs( v ) do
			t[k][j] = z * 100
		end
	end
	-- PrintTable( t )
	-- CustomGameEventManager:Send_ServerToPlayer(PlayerResource:GetPlayer(playerID), "cf_attack_defense_table", t )
	CustomNetTables:SetTableValue("cf_attack_defense", "attack_defense_t", t)
end


function cf_SetTables_AttackMove()
	-- if cf_table_pathcorner ~=  nil then return end

	cf_table_pathcorner = {}
	-- Starting Positions of Pathing
	local pos = 
			{
				"lane_top_",
				"lane_mid_",
				"lane_bot_"
			}

	local hTarget = nil
	local n = 0
	for i,v in ipairs(pos) do
      	-- print(i, v)
      	n = 0

		while true do
			n = n +1
			-- print("Entity to search for: ".. pos[i] .. n)
			hTarget = Entities:FindByName(hTarget, pos[i] .. n)
			if hTarget ~= nil then
				-- print ("AttackMove-TO: ")
				-- print ( hTarget:GetName() )
				cf_table_pathcorner[v .. n] = {}
				cf_table_pathcorner[v .. n].NextWaypoint = {}
				cf_table_pathcorner[v .. n].PrevWaypoint = {}

				

				cf_table_pathcorner[v .. n].NextWaypoint = nil
				cf_table_pathcorner[v .. n].PrevWaypoint = nil
				if n ~= 1 then
					cf_table_pathcorner[v .. n-1].NextWaypoint = v .. n
					cf_table_pathcorner[v .. n-1].NextWaypoint_pos = Entities:FindByName(nil,v .. n):GetAbsOrigin()

					cf_table_pathcorner[v .. n].PrevWaypoint = v .. (n-1)
					cf_table_pathcorner[v .. n].PrevWaypoint_pos = Entities:FindByName(nil,v .. (n -1)):GetAbsOrigin()
				end
			else
				-- print("Entity to search for: ".. pos[i] .. n)
				-- print ("Not found!")

				break
			end
		end
	end

	local v1 = nil
	local v2 = nil
	cf_table_pathcorner.area_left = {}
	cf_table_pathcorner.area_left.h = Entities:FindByName(nil, "cf_area_left")

	v1 = cf_table_pathcorner.area_left.h:GetOrigin()
	v2 = cf_table_pathcorner.area_left.h:GetBounds()

	cf_table_pathcorner.area_left.x1 = v1.x + v2.Mins.x
	cf_table_pathcorner.area_left.x2 = v1.x + v2.Maxs.x

	cf_table_pathcorner.area_left.y1 = v1.y + v2.Mins.y
	cf_table_pathcorner.area_left.y2 = v1.y + v2.Maxs.y

	v1 = cf_table_pathcorner.area_left.h:GetOrigin()
	v2 = cf_table_pathcorner.area_left.h:GetBounds()


	cf_table_pathcorner.area_right = {}
	cf_table_pathcorner.area_right.h = Entities:FindByName(nil, "cf_area_right")

	v1 = cf_table_pathcorner.area_right.h:GetOrigin()
	v2 = cf_table_pathcorner.area_right.h:GetBounds()

	cf_table_pathcorner.area_right.x1 = v1.x + v2.Mins.x
	cf_table_pathcorner.area_right.x2 = v1.x + v2.Maxs.x

	cf_table_pathcorner.area_right.y1 = v1.y + v2.Mins.y
	cf_table_pathcorner.area_right.y2 = v1.y + v2.Maxs.y

	-- PrintTable(cf_table_pathcorner.area_left)
	-- PrintTable(cf_table_pathcorner.area_right)
	-- print ("Done!.")
	-- print("")
end




cf_SetTables_UnitKV()
cf_SetTables_attackdefense()