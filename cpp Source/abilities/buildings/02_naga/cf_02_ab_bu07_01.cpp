"cf_02_ab_bu07_01"
{
	/*
		[self]
		target=Ability_Names_Naga
		type=ability
		name=Earthquake
		descr=
	*/
	"BaseClass"                     "ability_datadriven"
	"AbilityBehavior"				" DOTA_ABILITY_BEHAVIOR_UNIT_TARGET | DOTA_ABILITY_BEHAVIOR_IMMEDIATE "
	"AbilityUnitTargetTeam" 		"DOTA_UNIT_TARGET_TEAM_ENEMY"
	"AbilityUnitTargetType"			"DOTA_UNIT_TARGET_CREEP"
	"AbilityTextureName" 			"leshrac_split_earth"
	"AbilityCastRange"				"30000"
	
	"AbilityManaCost"				"7"
	"AbilityGoldCost"				"0"
	"AbilityCooldown"				"1"
	
	"Level"							"0"
    "MaxLevel"                      "1"

    "cf_ab_utility"					"1"
    "cf_autocast"					"1"

	"precache"
	{
		"particle"	"particles/units/heroes/hero_ursa/ursa_earthshock.vpcf"
	}
	"AbilitySpecial"
	{
		"01"
		{
			"var_type"			"FIELD_INTEGER"
			"radius"			"700"
		}
		"02"
		{
			"var_type"			"FIELD_FLOAT"
			"duration"			"10"
		}
		"03"
		{
			"var_type"			"FIELD_FLOAT"
			"aoe"				"250"
		}
		"04"
		{
			"var_type"			"FIELD_INTEGER"
			"as_slow"			"50"
		}
		"05"
		{
			"var_type"			"FIELD_INTEGER"
			"ms_slow"			"50"
		}
		"06"
		{
			"var_type"			"FIELD_INTEGER"
			"dmg_to_ground"		"40"
		}
	}
	"OnSpellStart"
	{
		"RunScript"
		{
			"ScriptFile"			"abilities/02_naga/cf_ab_naga.lua"
			"Function"				"cf_ab_earthquake"
			"particle"				"particles/units/heroes/hero_ursa/ursa_earthshock.vpcf"
			"radius"				"%radius"
			"duration"				"%duration"
			"aoe"					"%aoe"
			"as_slow"				"%as_slow"
			"ms_slow"				"%ms_slow"
			"dmg_to_ground"			"%dmg_to_ground"
		}
	}
}

