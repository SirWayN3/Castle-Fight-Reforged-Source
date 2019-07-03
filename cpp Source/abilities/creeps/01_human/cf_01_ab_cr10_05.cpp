"cf_01_ab_cr10_05"
{
	/*
		[self]
		target=Ability_Names_Humans
		type=ability
		name=Armor Aura
		descr=Bonus Armor: %armor%<br>Radius: %radius%
		[cf_mo_cr_aura_paladin]
		target=Ability_Names_Humans
		type=modifier
		name=Armor Aura Owner
		[cf_mo_cr_aura_paladin_bonus]
		target=Ability_Names_Humans
		type=modifier
		name=Bonus Armor
	*/
	// Common Aura
	"BaseClass"             		"ability_datadriven"
	"AbilityTextureName"			"item_ring_of_basilius"

	"AbilityBehavior"				" DOTA_ABILITY_BEHAVIOR_PASSIVE | DOTA_ABILITY_BEHAVIOR_AURA "
	"AbilityUnitTargetType"			"DOTA_UNIT_TARGET_CREEP"

	"AbilityManaCost"				"0"
	"AbilityGoldCost"				"0"
	"AbilityCooldown"				"0"
	
	"Level"							"1"
    "MaxLevel"                      "1"

	"AbilitySpecial"
	{
		"01"
		{
			"var_type"			"FIELD_INTEGER"
			"radius"			"400"
		}
		"02"
		{
			"var_type"			"FIELD_INTEGER"
			"armor"				"3"
		}
	}
	"Modifiers"
	{
	    "cf_mo_cr_aura_paladin"
	    {
			"Passive"				"1"
			"IsPurgable"			"0"
			"IsHidden" 				"1"
	        "Aura"        			"cf_mo_cr_aura_paladin_bonus"
	        "Aura_Radius" 			"%radius"
	        "Aura_Teams"  			"DOTA_UNIT_TARGET_TEAM_FRIENDLY"
	        "Aura_Types"  			"DOTA_UNIT_TARGET_CREEP"

	        "Aura_ApplyToCaster" 	"1"   // Not Apply to Self, default is 1
	    }
	    "cf_mo_cr_aura_paladin_bonus"
	    {
	        "Passive" 			"1" //Apply as soon as the spell is learned
	        "IsHidden"    		"0" //Don't show the aura applier
         	"IsBuff" 			"1"

         	// "Attributes"       "MODIFIER_ATTRIBUTE_MULTIPLE" // -> stackable, but not working properly
			"Properties"
			{
				"MODIFIER_PROPERTY_PHYSICAL_ARMOR_BONUS"		"%armor"
			}

	    }
	}
}



