

function cf_income_getcurrentvalue( playerID )
	print ( "cf_income_getcurrentvalue" )
	return cf_playertable[playerID].income.CurrentIncome
end

function cf_income_addbyunit( unit )
	local newincome = unit:GetKeyValue("cf_incomeincrease")
	if newincome == nil then return end
	-- print( newincome )
	local playerID = unit:GetPlayerOwnerID()
	if playerID == nil then return end
	if playerID == -1 then return end
	local t = {}
	t.newincome = newincome
	t.playerID = playerID
	cf_income_addcurrentvalue( t )

	-- Give energy to Hero
	local newenergy = unit:GetKeyValue("cf_energyincrease")
	if newenergy ~= nil then
		local hero = PlayerResource:GetPlayer(playerID):GetAssignedHero()
		hero:ModifyEnergy( newenergy )
	end

end


function cf_income_addcurrentvalue( keys )
	-- print ( "cf_income_addcurrentvalue" )
	-- PrintTable( keys )
	local raw = cf_playertable[keys.playerID].income.RawIncome
	raw = raw + keys.newincome
	cf_playertable[keys.playerID].income.RawIncome = raw
	cf_income_calcincome( keys.playerID )
end


function cf_income_timer()
	-- print ( "cf_income_timer" )
	cf_income_playergetsincome()
	CustomGameEventManager:Send_ServerToAllClients("cf_income", {timer = CF_INCOME_TIMER})
	return CF_INCOME_TIMER -- restart timer

end
-- Timers:CreateTimer( CF_RESOURCE_TIMER, cf_resource_timer )
function cf_resource_timer()
	for k,v in pairs( cf_playertable ) do
		cf_resources_sendtopanorama(k)
	end
	-- return CF_RESOURCE_TIMER -- restart timer
end

function cf_resources_sendtopanorama( playerID )
	-- print( "		Update Resources...")
	local k = playerID

	if cf_playertable[k].isReady == true then
		cf_playertable[k].gold = PlayerResource:GetGold(k)

		local t = {}
		t.resources = {}
		t.resources.gold = cf_playertable[k].gold
		t.resources.energy = cf_playertable[k].energy
		t.resources.essence = cf_playertable[k].essence
		t.resources.income_100 = cf_playertable[k].income.CurrentIncome_100

		CustomGameEventManager:Send_ServerToPlayer(PlayerResource:GetPlayer(k), "cf_resources_update", t)
		
	end

end

function cf_income_playergetsincome()
	-- print ( "cf_income_playergetsincome" )
	for k,v in pairs( cf_playertable ) do
		-- print(k,v)
		-- Reason: DOTA_ModifyGold_GameTick
		PlayerResource:ModifyGold( k , cf_playertable[k].income.CurrentIncome, true , DOTA_ModifyGold_GameTick )

	end
	-- EmitGlobalSound( CF_INCOME_SOUND ) -- Annoying
end

function cf_income_playerinit( playerID )
	-- Create Table for each Player to determine Gold income ect.
	-- print ( "cf_income_playerinit" )
	-- local team = nil

	cf_playertable[playerID].income = {}
	cf_playertable[playerID].income.RawIncome = CF_INCOME_STARTVALUE
	cf_playertable[playerID].income.CurrentIncome = 0.0
	cf_playertable[playerID].income.CurrentIncome_100 = 0.0
	cf_playertable[playerID].income.TreasureBoxCount = 0
	cf_playertable[playerID].income.TreasureBoxModifier = 1.0
	cf_playertable[playerID].income.IncomeModifier = 1.0

	cf_playertable[playerID].gold = CastleFightReforged_STARTING_GOLD
	cf_playertable[playerID].energy = CastleFightReforged_STARTING_ENERGY
	cf_playertable[playerID].essence = CastleFightReforged_STARTING_ESSENCE

	if cf_testmode() then
		cf_playertable[playerID].energy = 500000
	end
	cf_income_calcincome( playerID )

end

function cf_income_playerleft()
	print ( "cf_income_playerleft" )
	
end


function cf_income_addtreasurebox( event )
	-- PrintTable( event )
	-- print("cf_income_addtreasurebox")
	local playerID = event.caster:GetPlayerOwnerID()
	cf_playertable[playerID].income.TreasureBoxCount = cf_playertable[playerID].income.TreasureBoxCount +1
	cf_income_calctreasurebox( playerID )
	cf_income_calcincome( playerID )
end

function cf_income_subtreasurebox( event )
	-- print("cf_income_subtreasurebox")
	local playerID = event.caster:GetPlayerOwnerID()
	cf_playertable[playerID].income.TreasureBoxCount = cf_playertable[playerID].income.TreasureBoxCount -1
	cf_income_calctreasurebox( playerID )
	cf_income_calcincome( playerID )
end 

function cf_income_calctreasurebox( playerID )
	local modifier = 1.0
	if cf_playertable[playerID].income.TreasureBoxCount >= 1 then
		-- Each Treasurebox increases income by 1.15
		local g = 0
		for i=1,cf_playertable[playerID].income.TreasureBoxCount do
			g = g + 0.25 * ( 0.85 ^ ( i -1 ) )
		end
		modifier = 1 + g

	else
		-- No Treasure Box found. No Modifier is applied
	end
	cf_playertable[playerID].income.TreasureBoxModifier = modifier
end

function cf_income_calcincome( playerID )
	local g = cf_playertable[playerID].income.RawIncome
	g = g * cf_playertable[playerID].income.IncomeModifier
	g = g * cf_playertable[playerID].income.TreasureBoxModifier
	g = math.floor(g * 100)
	cf_playertable[playerID].income.CurrentIncome = g / 100
	cf_playertable[playerID].income.CurrentIncome_100 = g
	-- CustomNetTables:SetTableValue("castlefightreforged", "player"..playerID, {income = g * 100} )
	-- PrintTable( cf_playertable[playerID].income )
end 


