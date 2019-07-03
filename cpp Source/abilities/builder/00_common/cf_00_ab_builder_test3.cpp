"cf_00_ab_builder_test3"
{
	/*
		[self]
		target=Ability_Names_Builder
		type=ability
		name=TESTING ABILITY3
	*/
	// General
	//-------------------------------------------------------------------------------------------------------------
	"BaseClass"                     "ability_datadriven"
	
	"Level"							"1"
    "MaxLevel"                      "1"
	
	
	"AbilityBehavior"				"DOTA_ABILITY_BEHAVIOR_UNIT_TARGET"
	"AbilityType"                   "DOTA_ABILITY_TYPE_BASIC"
	"AbilityUnitTargetTeam" 		"DOTA_UNIT_TARGET_TEAM_BOTH"
	"AbilityUnitTargetType"      	"DOTA_UNIT_TARGET_ALL"
	"AbilityUnitTargetFlags"		"DOTA_UNIT_TARGET_FLAG_MAGIC_IMMUNE_ENEMIES"
	"SpellImmunityType"				"SPELL_IMMUNITY_ENEMIES_YES"
	
	// Casting
	//-------------------------------------------------------------------------------------------------------------
	"AbilityCastPoint"				"0"
	// "AbilityCastRange"				"1000"

	// Time		
	//-------------------------------------------------------------------------------------------------------------
	"AbilityCooldown"				"0"
	
	// Cost
	//-------------------------------------------------------------------------------------------------------------
	"AbilityManaCost"				"0"
	
	// "AbilitySound"					"Hero_Antimage.Blink_out"

	// Special	
	//-------------------------------------------------------------------------------------------------------------

	"AbilityCastAnimation"		"ACT_DOTA_CAST_ABILITY_2"
	"OnSpellStart"
	{
		"RunScript"
		{
			"ScriptFile"			"abilities/cf_builder_test.lua"
			"Function"				"cf_builder_common_test3"
     		// "EventName" 			"OnSpellStart"
     		"Target" 				"TARGET"
     		
		}
	}
}