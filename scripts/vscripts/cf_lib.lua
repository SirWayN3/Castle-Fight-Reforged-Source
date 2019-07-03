function CDOTA_BaseNPC:CF_GetAttackType()
	return GetUnitKV(self:GetUnitName(), "cf_attacktype" )
end

function CDOTA_BaseNPC:CF_GetDefenseType()
	return GetUnitKV(self:GetUnitName(), "cf_defensetype" )
end

function CDOTABaseAbility:GetEssenceCost()
-- 	print ( "declare essence Cost missing. cf_lib.lua" .. " Cost: " .. tostring( self:GetKeyValue("cf_AbilityEssenceCost" ) ) )
	return self:GetKeyValue( "cf_AbilityEssenceCost" ) or 0
end

function CDOTABaseAbility:GetManaCost()
	-- print ( "declare mana Cost missing. cf_lib.lua" .. " Cost: " .. tostring( self:GetKeyValue("cf_AbilityManaCost" ) ) )
	
	return self:GetKeyValue( "cf_AbilityManaCost" ) or self:GetKeyValue( "AbilityManaCost" )
end

function CDOTABaseAbility:GetEnergyCost()
	return self:GetKeyValue( "cf_AbilityEnergyCost" ) or 0
end

function CDOTABaseAbility:GetGoldCost()
	-- print ( "declare gold Cost missing. cf_lib.lua" .. " Cost: " .. tostring( self:GetKeyValue("cf_AbilityGoldCost" ) ) )
	return self:GetKeyValue( "cf_AbilityGoldCost" ) or self:GetKeyValue( "AbilityGoldCost" )
end
function CDOTABaseAbility:IsAutoCastAbility()
	if self:GetKeyValue("cf_autocast") then 
		return true
	else
		return false
	end
end
function CDOTABaseAbility:GetCastRangeBuffer()
	return self:GetKeyValue("AbilityCastRangeBuffer") or 0
end
-- function CDOTA_BaseNPC:cf_GetPhysicalArmor()
-- 	return self:GetKeyValue("cf_armor_physical") + self:GetPhysicalArmorValue() or 0
-- end
function CDOTABaseAbility:GetAttackTargetType()
	return self:GetKeyValue("AttackTargetType") or "AI_ATTACK_NONE"
end
function CDOTA_BaseNPC:GetMinimumAttackRange()
	return self:GetKeyValue("AttackRangeMin") or 0
end

function CDOTA_BaseNPC:IsInMinimumAttackRange( v )
	return (CalcDistanceBetweenEntityOBB(self,v) > self:GetMinimumAttackRange())
end
function CDOTA_BaseNPC:IsDamaged()
	-- return not ( self:GetMaxHealth() == self:GetHealth() )
	return self:GetHealthPercent() < 100
end
function CDOTA_BaseNPC:HasCorpse()
	return (self:GetKeyValue("HasCorpse") == 1) or false
end
function CDOTA_BaseNPC:IsCorpse()
	return ( self:GetUnitName() == "cf_corpse") or false
end
function CDOTA_BaseNPC:GetEssence()
	-- print ( "CDOTA_BaseNPC:GetEssence Missing Declaration here")
	return cf_playertable[self:GetPlayerID()].essence or -1
end
function CDOTA_BaseNPC:ModifyEssence( value )
	-- print ( "CDOTA_BaseNPC:ModifyEssence Missing Declaration here")
	self:SetEssence( self:GetEssence() + value )
end
function CDOTA_BaseNPC:SetEssence( value )
	cf_playertable[self:GetPlayerID()].essence = value
end

function CDOTA_BaseNPC:ModifyHealth( value )
	self:SetHealth( self:GetHealth() + value )
end
function CDOTA_BaseNPC:ModifyMana( value )
	-- print ( "CDOTA_BaseNPC:ModifyMana Missing Declaration here")
	self:SetMana( self:GetMana() + value )
end

function CDOTA_BaseNPC:GetEnergy()
	return cf_playertable[self:GetPlayerID()].energy or -1
end
function CDOTA_BaseNPC:SetEnergy( value )
	cf_playertable[self:GetPlayerID()].energy = value
end
function CDOTA_BaseNPC:ModifyEnergy( value )
	cf_playertable[self:GetPlayerID()].energy = cf_playertable[self:GetPlayerID()].energy + value
end
function CDOTA_BaseNPC:GetAllAbilities()
	local t = {}
	-- t.count = 0
	local ab = nil
	for i=0,self:GetAbilityCount()-1 do
		ab = self:GetAbilityByIndex(i)
		if ab ~= nil then
			-- print(i,tostring(ab:GetAbilityName()))
			-- t.count = t.count + 1
			t[ab:GetAbilityName()] = ab
		end

	end
	return t
end
function CDOTA_BaseNPC:GetAllAutoCastAbilities()
	local t = {}
	-- t.count = 0
	local ab = nil
	for i=0,self:GetAbilityCount()-1 do
		ab = self:GetAbilityByIndex(i)
		if ab ~= nil and ab:IsAutoCastAbility() then
			-- print(i,tostring(ab:GetAbilityName()))
			-- t.count = t.count + 1
			t[ab:GetAbilityName()] = ab
		end

	end
	return t
end
function CDOTA_BaseNPC:SetAllAbilitiesLevel( level )
	local t = self:GetAllAbilities()
	for k,v in pairs(t) do
		v:SetLevel(level)
	end
end
function CDOTA_BaseNPC:GetAttackTargetType()
	return self:GetKeyValue("AttackTargetType") or "AI_ATTACK_NONE"
end
function CDOTA_BaseNPC_Building:GetAttackTargetType()
	return self:GetKeyValue("AttackTargetType") or "AI_ATTACK_NONE"
end
function CDOTA_BaseNPC_Building:GetAttackRange()
	return self:GetKeyValue("AttackRange") or 0
end
function CF_GetDamageModifier(attacktype, defensetype)
	return CF_DAMAGETYPE_MODIFIERS[attacktype][defensetype]
end

function cf_testmode(playerID)
	if IsInToolsMode() then
		return true
	else
        -- SendErrorMessage(playerID, "#error_not_intoolsmode")
		return false
	end
end
function CF_GetArmorReductionPerc( value )
	return ( 1 - ( (0.052 * value ) / (0.9 + 0.048 * math.abs( value ) ) ) )
end



function cf_dbg( string )
	if CF_DEBUG then print ( string ) end
end


function deepcopy(orig)
    local orig_type = type(orig)
    local copy
    if orig_type == 'table' then
        copy = {}
        for orig_key, orig_value in next, orig, nil do
            copy[deepcopy(orig_key)] = deepcopy(orig_value)
        end
        setmetatable(copy, deepcopy(getmetatable(orig)))
    else -- number, string, boolean, etc
        copy = orig
    end
    return copy
end
function tablelength(T)
  local count = 0
  for _ in pairs(T) do count = count + 1 end
  return count
end
function cf_AttackMoveCommand_Init(unit)
	local param = {
		unit = unit,
		}

	-- print("cf_AttackMoveCommand_Init: AttackMove")
    Timers:CreateTimer(CF_UNIT_SPAWNED_TIMEFORORDER, cf_AttackMoveCommand_DO, param)
end



