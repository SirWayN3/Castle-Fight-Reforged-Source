"cf_01_ab_bu08_01"
{// Artillery Basic Attack
	/*
		[self]
		target=Ability_Names_Humans
		type=ability
		name=Artillery Attacks
		descr=Artillery Launches an Attack into the enemy Base, Target Position is chosen by Random.
	*/
	"BaseClass"                     "ability_datadriven"
	"AbilityBehavior"				" DOTA_ABILITY_BEHAVIOR_NO_TARGET | DOTA_ABILITY_BEHAVIOR_IMMEDIATE "

	"AbilityManaCost"				"0"
	"AbilityGoldCost"				"0"
	"AbilityCooldown"				"12"
	
	"Level"							"0"
	"MaxLevel"                      "1"

	"cf_utility"					"1"
	"cf_autocast"					"1"

	"AbilityUnitDamageType"         "DAMAGE_TYPE_PURE"
	"AbilityUnitTargetType"      	"DOTA_UNIT_TARGET_BUILDING"
	"AbilityUnitTargetTeam"			"DOTA_UNIT_TARGET_TEAM_ENEMY"

	"precache"
	{
		"particle"				"particles/cf_human_artillery_impact.vpcf"
	}
	"particle_impact"			"particles/cf_human_artillery_impact.vpcf"
	
	"AbilitySpecial"
	{
		"01"
		{
			"var_type"      	"FIELD_INTEGER"
			"damage_min"  		"300"
		}
		"02"
		{
			"var_type"			"FIELD_INTEGER"
			"damage_max"		"400"
		}
		"03"
		{
			"var_type"			"FIELD_INTEGER"
			"radius"			"160" // 320 AOE
		}
		"04"
		{
			"var_type"		"FIELD_INTEGER"
			"burnduration"	"5"
		}
		"05"
		{
			"var_type"		"FIELD_INTEGER"
			"timetoimpact"	"3"
		}
	}

	"OnSpellStart"
	{
		"RunScript"
		{
			"ScriptFile"					"abilities/01_human/cf_ab_artillery.lua"
			"Function"						"cf_ab_artillery_OnSpellStart"
		}
	}
}

