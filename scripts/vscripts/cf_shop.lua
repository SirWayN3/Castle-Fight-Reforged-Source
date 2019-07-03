

if not CF_Shop then
    CF_Shop = class({})
end

function CF_Shop:PlayerEvent ( event )
	-- print("CF_SHOP:PlayerEvent")
	-- PrintTable( event )
	if event.eventName == "Buy" then
		CF_Shop:Buyrequest( event )
	elseif event.eventName == "ShowBuy" then
		CF_Shop:ShowBuyRequest( event )
	end
end
function CF_Shop:ShowBuyRequest( kv )
	
	local teamID = cf_playertable[kv.playerID].teamnumber

	local msg = "shop_showbuyrequest1 " .. PlayerResource:GetPlayerName(kv.playerID).. " shop_showbuyrequest2 " .. kv.itemName

	Notifications:BottomToTeam(
		teamID,
		{
			text=msg, duration=5, class="NotificationMessage"
		}
	)
	Notifications:BottomToTeam(
		teamID,
		{
			item=kv.itemName, duration=5, class="NotificationMessage"
		}
	)

end
function CF_Shop:Buyrequest( kv )
	-- print("CF_Shop_buyrequest")
	-- PrintTable(kv)
	-- print("")

	local playerID = kv.playerID
	local itemName = kv.itemName
	local builder = cf_playertable[playerID].builder.unit
	local teamID = cf_playertable[playerID].teamnumber
	local gold_cost = CF_Shop.ItemKV[teamID][itemName].GoldCost
	local msg = ""

	-- check for Gold Cost
	-- Debug
	-- print("Stock: ", CF_Shop.ItemKV[itemName].Stock)
	-- print(teamID)
	-- PrintTable(CF_Shop.ItemKV)
	-- Debug
	if PlayerResource:GetGold(playerID) < gold_cost then
		msg = "#error_not_enough_gold"
	    SendErrorMessage(playerID, msg)

	    -- Check Item for Availability

	elseif CF_Shop.ItemKV[teamID][itemName].Stock == 0 then

		if CF_Shop.ItemKV[teamID][itemName].StockMax == 0 then
			msg = "#error_item_only_once"
			SendErrorMessage(playerID, msg)
		else
			msg = "#error_item_out_of_stock " .. CF_Shop.ItemKV[teamID][itemName].TimeCur .. " #error_item_out_of_stock2"
			SendErrorMessage(playerID, msg)
		end
		
	else
		PlayerResource:SpendGold(playerID, gold_cost, 0)
		local item = builder:AddItemByName(itemName)
		CF_Shop.ItemKV[teamID][itemName].Stock = CF_Shop.ItemKV[teamID][itemName].Stock -1

		if cf_testmode() then
			item:SetDroppable(true);
			item:SetSellable(true);
		end
	end
end

function CF_Shop:Think()
	-- print("CF_Shop_Think")
	for _,t in pairs(CF_Shop.Teams) do
		for k,v in pairs(CF_Shop.ItemKV[t]) do
			-- print("")
			-- print(k)
			-- PrintTable(v)
			-- print(v.TimeCur)
			if v.Stock < v.StockMax then
				if v.TimeCur ~= 0 then
					v.TimeCur = v.TimeCur -1
				else -- Timer ready
					-- print("ReStock")
					v.Stock = v.Stock + 1
					v.TimeCur = v.TimeReStock
				end
			else
				v.TimeCur = v.TimeReStock
			end -- Enough in Stock
		end
	end
end




function CF_Shop:Init( ... )
	print("CF_Shop: Initialized...")
	CF_Shop.ready = true
	if not CF_Shop.Listener then
	CF_Shop.Listener = CustomGameEventManager:RegisterListener("cf_item_buyrequest", Dynamic_Wrap(CF_Shop, "PlayerEvent"))
	end
	CF_Shop.Teams = {}
	CF_Shop.Teams[0] = CF_TEAM_NUMBER_LEFT
	CF_Shop.Teams[1] = CF_TEAM_NUMBER_RIGHT
	local i = 0
	local t = nil
	CF_Shop.ItemKV = {}
	for _,t in pairs(CF_Shop.Teams) do
		-- print("team: ",t)
		CF_Shop.ItemKV[t] = {}
		for k,v in pairs(KeyValues.ItemKV) do
			-- print(k,v)
			CF_Shop.ItemKV[t][k] = {}
			CF_Shop.ItemKV[t][k].GoldCost 	= KeyValues.ItemKV[k].ItemCost
			CF_Shop.ItemKV[t][k].ItemQuality = KeyValues.ItemKV[k].ItemQuality
			CF_Shop.ItemKV[t][k].ItemType   = KeyValues.ItemKV[k].ItemType

			CF_Shop.ItemKV[t][k].Stock 	= KeyValues.ItemKV[k].ItemStockInitial or 0
			CF_Shop.ItemKV[t][k].StockMax 	= KeyValues.ItemKV[k].ItemStockMax

			CF_Shop.ItemKV[t][k].TimeReStock = KeyValues.ItemKV[k].ItemStockTime or 0
			CF_Shop.ItemKV[t][k].TimeInit 	= KeyValues.ItemKV[k].ItemInitialStockTime or 0
			CF_Shop.ItemKV[t][k].TimeCur 	= CF_Shop.ItemKV[t][k].TimeCur or CF_Shop.ItemKV[t][k].TimeInit
		end
		-- PrintTable(CF_Shop.ItemKV[t])
	end
end

if not CF_Shop.ready then CF_Shop:Init() end
-- CF_Shop:Init()