"cf_02_ab_cr10_02"
{
	/*
		[self]
		target=Ability_Names_Naga
		type=ability
		name=Splash Attack
		descr=Inner Radius: %radius_outer%<br>Damage Percent: %dmg_outer_perc%
	*/
	// Common Splash Attack
	"BaseClass"                     "ability_datadriven"
	"AbilityBehavior"				"DOTA_ABILITY_BEHAVIOR_PASSIVE"
	"AbilityUnitTargetType"			"DOTA_UNIT_TARGET_CREEP | DOTA_UNIT_TARGET_BUILDING"
	"AbilityTextureName" 			"ogre_magi_ignite"

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
			"radius_inner"				"10"
		}
		"02"
		{
			"var_type"					"FIELD_INTEGER"
			"radius_outer"				"250"
		}
		"03"
		{
			"var_type"					"FIELD_INTEGER"
			"dmg_inner_perc"			"150"
		}
		"04"
		{
			"var_type"					"FIELD_INTEGER"
			"dmg_outer_perc"			"100"
		}
	}
	"Modifiers"
	{
		"cf_mo_cr_splash"
		{
			"Passive"					"1"
			"IsHidden"					"0"
			"OnAttackLanded"
			{
				"RunScript"
				{
					"ScriptFile"		"abilities/ab_creeps_common.lua"
					"Function"			"cf_ab_cr_splash"
					"damage"			"%attack_damage"
					// Modify Values here to adjust damage amplify
					// "radius_inner"		"%radius_inner"
					// "dmg_inner_perc"	"%dmg_inner_perc"
					"radius_outer"		"%radius_outer"
					"dmg_outer_perc"	"%dmg_outer_perc"
				}
			}
		}
	}
}

