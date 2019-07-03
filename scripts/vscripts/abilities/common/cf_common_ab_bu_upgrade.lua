function cf_common_ab_bu_upgrade ( event )
	-- PrintTable ( event )
	-- Upgrade Building by first, remove old Building, then Build new one, no Cancel possible
	local caster = event.caster
	local c_health = caster:GetHealth()
	local c_maxhealth = caster:GetMaxHealth()
	local ability = event.ability
	local name = ability:GetKeyValue("cf_upgrade_bu_to")
	local upgradetime = ability:GetKeyValue("UpgradeTime") or 0.5
	local timer = 0.04
	local goldcost = ability:GetGoldCost()
	local playerID = caster:GetPlayerOwnerID()
	-- print("upgrade: GoldCost: ",goldcost,"Current Gold:",PlayerResource:GetGold(caster:GetPlayerOwnerID()))
	if PlayerResource:GetGold(playerID) < goldcost then
        print("Failed placement of - Not enough gold!")
        SendErrorMessage(playerID, "#error_not_enough_gold")
	else
		PlayerResource:ModifyGold(playerID, -goldcost, true, 0)
		local new_building = BuildingHelper:UpgradeBuilding(caster, name)
		
		PlayerResource:NewSelection(new_building:GetPlayerOwnerID(),new_building)

		local t = {}
		t.unit = new_building
		t.duration = upgradetime

		new_building:SetHealth(c_health)
		local val = (new_building:GetMaxHealth() - c_maxhealth ) / upgradetime * timer

		-- print ( "Health Regen: ",val)

		Timers:CreateTimer(timer, function()
			if 
				not new_building:IsNull() 
				and new_building:IsAlive() 
				and new_building:HasModifier("cf_mo_bu_building_particle")
			then
				-- Apply health Regen by Timer
				-- new_building:ModifyHealth( val, ability, false)
				new_building:Heal( val , ability)
				return timer
			else
				return nil
			end
		end)

		CCastleFightReforged:OnBuildingUpgradeStarted( t )
		-- call when the Upgrade Time has been ended
		Timers:CreateTimer(upgradetime, function()
			if not new_building:IsNull() and new_building:IsAlive() then
				CCastleFightReforged:OnBuildingUpgradeFinished( t )
			end
		end)

	end
end
