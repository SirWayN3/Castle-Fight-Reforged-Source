"cf_02_ab_cr08_02"
{
	/*
		[self]
		target=Ability_Names_Naga
		type=ability
		name=Bash Attack
		descr=Chance: %chance%% <br>Bonus Dmg: %damage%<br>Stun Duration: %duration%s
	*/
	// Common Bash Attack
	"BaseClass"                     "ability_datadriven"
	"AbilityBehavior"				"DOTA_ABILITY_BEHAVIOR_PASSIVE"
	"AbilityUnitTargetType"			"DOTA_UNIT_TARGET_CREEP"
	"AbilityTextureName" 			"sven_storm_bolt"

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
			"chance"					"15" // Chance in Percent
		}
		"02"
		{
			"var_type"					"FIELD_INTEGER"
			"damage"					"25"
		}
		"03"
		{
			"var_type"					"FIELD_INTEGER"
			"duration"					"2" // Duration in Seconds
		}
	}
	"Modifiers"
	{
		"cf_mo_cr_bash"
		{
			"Passive"					"1"
			"IsHidden"					"1"
			"OnAttackLanded"
			{
				"RunScript"
				{
					"ScriptFile"		"abilities/ab_creeps_common.lua"
					"Function"			"cf_ab_cr_bash"
					"chance"			"%chance"
					"damage"			"%damage"
					"duration"			"%duration"
				}
			}
		}
	}
}

