"cf_XX_ab_crXX_XX_aura"
{
	/*
		[self]
		target=Ability_Names_Common
		type=ability
		name=Dummy Aura Ability
		[cf_mo_cr_aura]
		target=Ability_Names_Common
		type=modifier
		name=Aura Dummy Owner
		[cf_mo_cr_aura_bonus]
		target=Ability_Names_Common
		type=modifier
		name=Aura Dummy Bonus
	*/
	// Common Aura
	"BaseClass"             		"ability_datadriven"
	"AbilityTextureName"			""

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
			"radius"			"1000"
		}
		"02"
		{
			"var_type"			"FIELD_INTEGER"
			"bonus"				"0"
		}
	}
	"Modifiers"
	{
		"cf_mo_cr_aura"
		{
			"Passive"				"1"
			"IsPurgable"			"0"
			"IsHidden" 				"0"
			"Aura"        			"cf_mo_cr_aura_bonus"
			"Aura_Radius" 			"%radius"
			"Aura_Teams"  			"DOTA_UNIT_TARGET_TEAM_FRIENDLY"
			"Aura_Types"  			"DOTA_UNIT_TARGET_CREEP"

			"Aura_ApplyToCaster" 	"1"   // Not Apply to Self, default is 1
		}
		"cf_mo_cr_aura_bonus"
		{
			"Passive" 			"1" //Apply as soon as the spell is learned
			"IsHidden"    		"0" //Don't show the aura applier
			"IsBuff" 			"1"

			// "Attributes"       "MODIFIER_ATTRIBUTE_MULTIPLE" // -> stackable, but not working properly
			"Properties"
			{
				// "MODIFIER_PROPERTY_HEALTH_REGEN_CONSTANT"		"5"
			}

		}
	}
}



