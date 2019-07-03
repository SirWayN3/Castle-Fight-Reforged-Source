
if cf_quests == nil then
	cf_quests = class({})

	cf_quests.FirstBuildings = {}

	cf_quests.FirstBuildings.Active = true
	cf_quests.FirstBuildings.PlayerID = {}
	cf_quests.FirstBuildings.Bonus = {}
	cf_quests.FirstBuildings.Bonus[1] = 20
	cf_quests.FirstBuildings.Bonus[2] = 15
	cf_quests.FirstBuildings.Bonus[3] = 10
	cf_quests.FirstBuildings.Bonus[4] = 5
end

function cf_quests:OnBuildingStarted( kv )
	-- print("cf_quests, onNPCSpawned",kv)
	local t = {}
	local b = false
	t = cf_quests.FirstBuildings
	if t.Active then
		if t.PlayerID[kv.playerID] == nil then
			for k,v in pairs(t.Bonus) do
				if v > 0 then
					t.Bonus[k] = 0
					t.PlayerID[kv.playerID] = true
					b = true
					-- print("Give Player Bonus Gold")
					PlayerResource:ModifyGold(kv.playerID,v, true, 0)
					Notifications:TopToAll({text="quests_firstbuildings_playergetsgold1 " .. PlayerResource:GetPlayerName(kv.playerID) .. " quests_firstbuildings_playergetsgold2 " .. v .. " quests_firstbuildings_playergetsgold3 ", duration=5.0})
					break
				end

			end
			if b == false then t.Active = false end
		end
	end
end



