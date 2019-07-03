"cf_02_ab_cr05_02"
{
	/*
		[self]
		target=Ability_Names_Naga
		type=ability
		name=Thorn Shield
		descr=Reflect Melee Damage by %reflect_perc%% <br>The Damage reflected is pure.
	*/
	// Common Bash Attack
	"BaseClass"                     "ability_datadriven"
	"AbilityBehavior"				"DOTA_ABILITY_BEHAVIOR_PASSIVE"
	"AbilityUnitTargetType"			"DOTA_UNIT_TARGET_CREEP"
	"AbilityTextureName" 			"centaur_return"


	"AbilityManaCost"				"0"
	"AbilityGoldCost"				"0"
	"AbilityCooldown"				"0"
	
	"Level"							"1"
    "MaxLevel"                      "1"
	"precache"
	{
		"particle"	"particles/units/heroes/hero_centaur/centaur_return.vpcf"
	}

	"AbilitySpecial"
	{
		"01"
		{
			"var_type"					"FIELD_INTEGER"
			"reflect_perc"				"35" // Chance in Percent
		}
	}

	"Modifiers"
	{
		"cf_mo_dragonturtle_return"
		{
			"Passive"	"1"
			"IsHidden"	"1"
			"OnAttacked"
			{
				"RunScript"
				{
					"ScriptFile"	"abilities/ab_creeps_common.lua"
					"Function"		"cf_ab_cr_return"
					"reflect_perc"	"%reflect_perc"
					"attack_damage"	"%attack_damage"
					"target_type"	"Melee"
				}
			}	
		}
	}
}

