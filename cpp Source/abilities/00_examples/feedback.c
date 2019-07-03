"cf_XX_ab_crXX_XX_feedback"
{
	/*
		[self]
		target=Ability_Names_Humans
		type=ability
		name=Feedback Attack
		descr=Burns %mana_burn% Mana every attack.
	*/
	"BaseClass"					"ability_datadriven"
	"AbilityTextureName"		"disruptor_static_storm"
	"MaxLevel"					"1"

	"AbilityBehavior"			"DOTA_ABILITY_BEHAVIOR_PASSIVE"
	"AbilityUnitDamageType"		"DAMAGE_TYPE_PHYSICAL"		


	"AbilitySpecial"
	{
		"01"
		{
			"var_type"				"FIELD_FLOAT"
			"damage_per_burn"		"1.0"
		}
		"02"
		{
			"var_type"				"FIELD_INTEGER"
			"mana_per_hit"			"25"
		}
	}

	"Modifiers"
	{
		"cf_feedback"
		{
			"Passive"	"1"
			"IsHidden"	"1"

			"OnAttackLanded"
			{
				"RunScript"
				{
					"ScriptFile"	"abilities/ab_creeps_common.lua"
					"Function"		"cf_ab_cr_manaburn_attack"
					"Target"		"TARGET"
					"damage_per_burn"	"%damage_per_burn"
					"mana_per_hit"		"%mana_per_hit"
				}
			}
		}
	}
}
