"cf_XX_ab_crXX_XX_evade"
{
	/*
		[self]
		target=Ability_Names_Humans
		type=ability
		name=Evasion
		descr=Evade Chance: %evasion%
	*/
	/* Remove this Part in the Resulting Ability
		[cf_mo_cr_evade]
		target=Ability_Names_Common
		type=modifier
		name=Evasion
	*/
	// Common Evade
	"BaseClass"                     "ability_datadriven"
	"AbilityBehavior"				"DOTA_ABILITY_BEHAVIOR_PASSIVE"
	"AbilityUnitTargetType"			"DOTA_UNIT_TARGET_CREEP | DOTA_UNIT_TARGET_BUILDING"
	"AbilityTextureName" 			"phantom_assassin_blur"

	"AbilityManaCost"				"0"
	"AbilityGoldCost"				"0"
	"AbilityCooldown"				"0"
	
	"Level"							"1"
	"MaxLevel"                      "1"

	// Special
	//-------------------------------------------------------------------------------------------------------------
	"AbilitySpecial"
	{
		"01"
		{
			"var_type"					"FIELD_INTEGER"
			"evasion"					"100" // Chance in Percent
		}
	}

	"Modifiers"
	{
		"cf_mo_cr_evade"
		{
			"Passive"					"1"
			"IsHidden"					"0"
			"Properties"
			{
				"MODIFIER_PROPERTY_EVASION_CONSTANT"	"%evasion"
			}

		}
	}
}

