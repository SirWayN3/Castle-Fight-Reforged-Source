"cf_01_ab_cr07_01"
{
	/*
		[self]
		target=Ability_Names_Humans
		type=ability
		name=Evasion
		descr=Evade Chance: %evasion% %
	*/
	// Common Evade

	"BaseClass"                     "ability_datadriven"
	"AbilityBehavior"				"DOTA_ABILITY_BEHAVIOR_PASSIVE"
	// "AbilityUnitTargetType"			"DOTA_UNIT_TARGET_CREEP | DOTA_UNIT_TARGET_BUILDING"
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
			"evasion"					"15" // Chance in Percent
		}
	}

	"Modifiers"
	{
		"cf_mo_cr_evade"
		{
			"Passive"					"1"
			"IsHidden"					"1"
			"Properties"
			{
				"MODIFIER_PROPERTY_EVASION_CONSTANT"	"%evasion"
			}

		}
	}
}

