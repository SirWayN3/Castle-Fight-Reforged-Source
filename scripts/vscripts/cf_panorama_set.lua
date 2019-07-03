

function cf_setpanorama_shop(playerID)
	-- print("cf_setpanorama_shop",playerID)

	CustomGameEventManager:Send_ServerToPlayer(PlayerResource:GetPlayer(playerID), "cf_shop_setpanorama", CF_Shop.ItemKV[PlayerResource:GetTeam(playerID)] )
end



function cf_setpanorama_abilites(playerID)
	-- Set Panorama according to ability information

	local unit = cf_playertable[playerID].builder.unit
	local t = {}
	local ab = nil
	t.builder = cf_playertable[playerID].builder.ent
	t.ab = {}

	for i=0, unit:GetAbilityCount() -1 do
		ab = unit:GetAbilityByIndex(i)
		if ab ~= nil then
			if ab:GetKeyValue("cf_custombuildpanel") == 1 then

				t.ab[i] = {}
				t.ab[i].name = ab:GetAbilityName()
				if 
					ab:GetKeyValue("AbilityTextureName") ~= "" and
					ab:GetKeyValue("AbilityTextureName") ~= nil
				then 
					t.ab[i].image = ab:GetAbilityName()
				else
					t.ab[i].image = ""
				end
				t.ab[i].ent = ab:entindex()

				t.ab[i].goldcost = ab:GetGoldCost( -1 )
				t.ab[i].manacost = ab:GetEnergyCost( -1 )
				t.ab[i].essencecost = ab:GetEssenceCost( -1 )
			end
		end
	end
	
	CustomGameEventManager:Send_ServerToPlayer(PlayerResource:GetPlayer(playerID), "cf_ab_setpanorama", t )
end


