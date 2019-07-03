
function cf_builder_common_checkTools(playerID)
	if IsInToolsMode() then
		return true
	else
        SendErrorMessage(playerID, "#error_not_intoolsmode")
		return false
	end
end

function cf_builder_common_test1( event )
	-- Point Target Ability
	print("cf_builder_common_test1")
	local caster = event.caster
	local playerID = caster:GetPlayerID()
	if not cf_builder_common_checkTools(playerID) then return end
	-- PrintTable( event )
	local units = {}
	local hUnit
	
	-- units[0] = "cf_01_bu_09_watchtower"
	-- units[10] = "cf_01_bu_11_stronghold"
	-- units[1] = "cf_01_bu_01_barracks"
	-- units[11] = "cf_01_cr_05_crusader"
	-- units[50] = "cf_01_cr_01_footman"
	-- units[2] = "cf_01_cr_07_defender"
	units[3] = "cf_01_cr_10_paladin"
	-- units[4] = "cf_02_cr_09_murloc_assasin"
	-- units[4] = "cf_02_cr_10_hydra_ancient"
	-- units[51] = "cf_02_cr_12_lobster"
	
	for k,v in pairs(units) do
		print(k,v)
		hUnit = CreateUnitByName(v, event.target_points[1] - Vector(RandomInt(-500,500),RandomInt(-500,500),0),false,nil,nil,DOTA_TEAM_BADGUYS)
		hUnit:AddNewModifier(nil, nil, "cf_mo_bu_autocast", {Duration = -1})
		-- hUnit:SetNeverMoveToClearSpace(true)
        hUnit:RemoveModifierByName("modifier_invulnerable")
        if hUnit:IsBuilding() then
        	hUnit:SetBaseHealthRegen(10)
        end
        hUnit:SetControllableByPlayer(0, false)
	end

end


function cf_builder_common_test2( event )
	-- No Target Ability
	print("cf_builder_common_test2")
	local caster = event.caster
	local playerID = caster:GetPlayerID()
	if not cf_builder_common_checkTools(playerID) then return end
	local item = nil
	-- item = caster:AddItemByName("item_custom_scroll_of_speed")
	-- item = caster:AddItemByName("item_custom_orb_of_lightning")
	-- item = caster:AddItemByName("item_custom_rune_of_repair")
	-- item = caster:AddItemByName("item_custom_restoration_stone")
	-- item = caster:AddItemByName("item_custom_damage_double")
	item = caster:AddItemByName("item_custom_blast_staff")

	if item ~= nil then
		item:SetDroppable(true);
		item:SetSellable(true);
	end

	local units = FindUnitsInRadius(
		caster:GetTeamNumber(),
		Vector(0, 0, 0),
		nil,
		FIND_UNITS_EVERYWHERE,
		DOTA_UNIT_TARGET_TEAM_FRIENDLY,
		DOTA_UNIT_TARGET_CREEP, 
		DOTA_UNIT_TARGET_FLAG_DEAD, 
		FIND_ANY_ORDER, 
		false)
	-- PrintTable(units)

	-- print(units[1]:GetUnitName(),units[1]:GetEntityIndex())
	-- print(units[1]:GetHealth(), units[1]:IsAlive())
	for k,v in pairs(units) do
		if not v:IsAlive() then
			print(v:GetUnitName(),v:GetEntityIndex(),v:IsAlive())
		end
	end
end


function cf_builder_common_test3( event )
	-- Target Unit Ability
	print("cf_builder_common_test3")
	local caster = event.caster
	local playerID = caster:GetPlayerID()
	local target = event.target
	local ability = event.ability
	if not cf_builder_common_checkTools(playerID) then return end
	-- target:RemoveModifierByName("cf_mo_bu_attack_ai")
	-- target:AddNewModifier(target, nil, "cf_mo_bu_attack_ai",  { duration = -1})
	-- target:AddNewModifier(target, nil, "modifier_building", {})
	-- local mo = target:GetModifierCount()
	-- for i=0,mo do
		-- print(i,target:GetModifierNameByIndex(i))
	-- end
	-- PrintTable ( event )
	-- event.target:GetUnitName()
	-- print(event.target:GetBaseDamageMin())

	target:ForceKill(false)
	-- print( target:GetTeamNumber())

end