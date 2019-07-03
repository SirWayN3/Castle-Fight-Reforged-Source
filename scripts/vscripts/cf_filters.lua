
function CCastleFightReforged:OnEntityHurt(keys)
	-- print( "OnEntityHurt" )
	-- PrintTable(keys)

	-- Don't use this unless you know what are you doing. 
	-- If you need to detect when a unit is damaged, use Damage Filter.
	-- local attacker_entity = EntIndexToHScript(keys.entindex_attacker)
    -- local victim_entity = EntIndexToHScript(keys.entindex_killed)
end

---------------------------------------------------------------------------
--	DamageFilter
--  *entindex_victim_const
--	*entindex_attacker_const
--	*entindex_inflictor_const
--	*damagetype_const
--	*damage
---------------------------------------------------------------------------
function CCastleFightReforged:DamageFilter( keys )
	-- print("CCastleFightReforged:OnDamage: INIT")
	-- Use GetKeyValue on Units to get attack type and set the modifier with matrix.
	-- try using normal values for attacktype and defensetype, alter them. UI would be easier to adapt
	if keys.entindex_attacker_const == nil then return true end -- if attacker is invalid, then return and let dmg be taken
		
	local attacker = EntIndexToHScript(keys.entindex_attacker_const)
    local victim = EntIndexToHScript(keys.entindex_victim_const)
	-- local damage = attacker:GetAttackDamage() -- Removed, use ATTACK and DEFEND type in cpp with BASIC -> 100% Damage, no Reduction.
	
	 -- disabled due to Bonus armor gained via Spells, Aura etc.
	-- local armor = victim:GetPhysicalArmorValue()
	-- local armor = victim:cf_GetPhysicalArmor()
	-- local reduction = CF_GetArmorReductionPerc( armor )

	local reduction = 1.0
	local attacktype = attacker:CF_GetAttackType()
	local defensetype = victim:CF_GetDefenseType()
	local dmgmodifier = 1.0
	local damagenew = keys.damage
	-- Check for damagetype_const for magical -> Items or Custom Spells that damage the Units.
	if keys.damagetype_const == DAMAGE_TYPE_MAGICAL then
		-- damagenew = keys.damage
		attacktype = "CF_COMBAT_ATTACK_SPELLS"
	else
		-- Does NOT work on Heroes for testing, since the UnitGetName is beeing ignored due to OverRide Hero
		if attacktype ~= nil and defensetype ~= nil then
			if attacktype ~= "" and defensetype ~= "" then
				dmgmodifier = CF_GetDamageModifier( attacktype, defensetype )
			end
		end


		damagenew = keys.damage * dmgmodifier * reduction
		-- local damagenew = damage * dmgmodifier
		-- damagenew = damagenew / reduction
	end
	
	
	-- DEBUG
	if cf_testmode() and CF_DEBUG_DAMAGEFILTER == true then
		-- if CF_DEBUG_PRINT_DAMAGETYPE_ONLY ~= nil then
			-- if attacktype == CF_DEBUG_PRINT_DAMAGETYPE_ONLY then
				PrintTable(keys)
				print( "DamageFilter" )
				print ( " attacktype: " .. tostring( attacktype ) .. " defensetype: " .. tostring(defensetype) )
				print ( " dmgmodifier: " .. tostring( dmgmodifier) .. " armor reduction: " .. reduction )
				print ( " damage: " .. damagenew .. " damage_old: " .. keys.damage)

				-- PrintTable(keys)
				print ("")
			-- end
		-- end
	end

	-- DEBUG END


	keys.damage = damagenew
	return true
end


function CCastleFightReforged:OrderFilter( order )
	-- print("ORDER")
	-- print("ORDER: " .. order.order_type )
	return true
end

