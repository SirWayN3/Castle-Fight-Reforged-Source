"cf_00_ab_builder_rescuestrike"
{
	/*
		[self]
		target=Ability_Names_Builder
		type=ability
		name=Rescue Strike
		[cf_mo_rescuestrike]
		target=Ability_Names_Builder
		type=modifier
		name=Rescue Strike Charges
	*/
	// General
	//-------------------------------------------------------------------------------------------------------------
	"BaseClass"                     "ability_datadriven"
	
	"Level"							"1"
    "MaxLevel"                      "1"
	
	
	"AbilityBehavior"				"DOTA_ABILITY_BEHAVIOR_POINT | DOTA_ABILITY_BEHAVIOR_AOE "
	"AbilityUnitDamageType"         "DAMAGE_TYPE_PURE"
	"AbilityUnitTargetType"      	"DOTA_UNIT_TARGET_BASIC"
	"AbilityUnitTargetTeam"			"DOTA_UNIT_TARGET_TEAM_ENEMY"
	"SpellImmunityType"				"SPELL_IMMUNITY_ENEMIES_YES"
	
	// Casting
	//-------------------------------------------------------------------------------------------------------------
	"AbilityCastPoint"				"0.4"
	"AbilityCastRange"				"1000"
	"AOERadius"						"1000"

	// Time		
	//-------------------------------------------------------------------------------------------------------------
	"AbilityCooldown"				"1"
	
	// Cost
	//-------------------------------------------------------------------------------------------------------------
	"AbilityManaCost"				"0"
	
	"AbilitySound"					"Hero_Pugna.NetherBlast"

	// Special	
	//-------------------------------------------------------------------------------------------------------------
	
	"precache"
	{
		"particle"					"particles/units/heroes/hero_pugna/pugna_netherblast.vpcf"
	}

	"AbilityCastAnimation"		"ACT_DOTA_CAST_ABILITY_1"
	"OnSpellStart"
	{
		"RunScript"
		{
			"ScriptFile"			"abilities/cf_builder_common.lua"
			"Function"				"cf_builder_common_rescuestrike"
     		"EventName" 			"OnSpellStart"
     		"Target" 				"POINT"
     		"particle"				"particles/units/heroes/hero_pugna/pugna_netherblast.vpcf"
			"mo_name"				"cf_mo_rescuestrike"
     		
		}
	}
	"Modifiers"
	{
		// Modifier Name also used in Restoration Stone
		"cf_mo_rescuestrike"
		{
			"Passive"				"1"
			"IsHidden" 				"0"
			"IsBuff"				"1"
			"OnCreated"
			{
				"RunScript"
				{
					"ScriptFile"			"abilities/cf_builder_common.lua"
					"Function"				"cf_builder_common_rescuestrike"
					"EventName"				"OnCreated"
					"mo_name"				"cf_mo_rescuestrike"
				}
			}
		}
	}

}