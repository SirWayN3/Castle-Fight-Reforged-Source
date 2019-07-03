"cf00_TESTING_SNIPPET"
{
	/*
		[self]
		target=Ability_Names_Humans
		snippet=Critical_Strike
	*/
	// Common Critical Strike

	"BaseClass"                     "ability_datadriven"
	"AbilityBehavior"				"DOTA_ABILITY_BEHAVIOR_PASSIVE"
	"AbilityTextureName" 			"phantom_assassin_coup_de_grace"

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
			"crit_chance"				"10"
		}
		"02"
		{
			"var_type"					"FIELD_INTEGER"
			"crit_mult"					"150" // this percentage * base_attack
		}
	}
	"OnCreated"
	{
		"ApplyModifier"
		{
			"Target"					"CASTER"
			"ModifierName"				"cf_mo_criticalstrike"
		}
	}
	
}

