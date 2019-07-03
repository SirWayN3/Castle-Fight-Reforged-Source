"cf_XX_ab_crXX_XX_block"
{
	/*
		[self]
		target=Ability_Names_Naga
		type=ability
		name=Hard Shell
		descr=Chance to block incoming Damage.<br>Chance: %chance%% <br>Reduction: %reduct%
	*/
	// Common Critical Strike
	"BaseClass"                     "ability_datadriven"
	"AbilityBehavior"				"DOTA_ABILITY_BEHAVIOR_PASSIVE"
	"AbilityTextureName" 			"mars_bulwark"

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
			"chance"					"50" // chance in percent
		}
		"02"
		{
			"var_type"					"FIELD_INTEGER"
			"reduct"					"35" // base_attack + this percentage * base_attack
		}
	}
	"OnCreated"
	{
		"ApplyModifier"
		{
			"Target"					"CASTER"
			"ModifierName"				"cf_mo_blocking"
		}
	}
}

