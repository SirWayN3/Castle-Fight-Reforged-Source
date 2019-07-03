"cf_02_ab_cr03_01"
{
	/*
		[self]
		target=Ability_Names_Naga
		type=ability
		name=Bounce Attack
		descr=Attacks Bounces for %bounces% Times.<br>Range for the Bounces is %range%.<br>Damage will get reduced by %damage_reduction_percent%%
	*/
	// Common Cleave Attack
	"BaseClass"                     "ability_datadriven"
	"AbilityBehavior"				"DOTA_ABILITY_BEHAVIOR_PASSIVE"
	"AbilityUnitTargetType"			"DOTA_UNIT_TARGET_CREEP | DOTA_UNIT_TARGET_BUILDING"
	"AbilityTextureName" 			"luna_moon_glaive"

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
			"range"						"250" 
		}
		"02"
		{
			"var_type"					"FIELD_INTEGER"
			"bounces"					"3"
		}
		"03"
		{
			"var_type"					"FIELD_INTEGER"
			"damage_reduction_percent"	"30"
		}
	}

	"Modifiers"
	{
		"cf_mo_cr_bounceattack"
		{
			"Passive"					"1"
			"IsHidden"					"1"
			"OnAttackLanded"
			{
				"RunScript"
				{
					"ScriptFile"		"abilities/ab_creeps_common.lua"
					"Function"			"cf_ab_cr_bounce_attack"
					"range"				"%range"
					"bounces"			"%bounes"
					"dmg_reduct"		"%damage_reduction_percent"
				}
			}
		}
	}
}

