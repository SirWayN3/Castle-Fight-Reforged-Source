"cf_00_ab_builder_test2"
{
	/*
		[self]
		target=Ability_Names_Builder
		type=ability
		name=TESTING ABILITY2
	*/
	// General
	//-------------------------------------------------------------------------------------------------------------
	"BaseClass"                     "ability_datadriven"
	
	"Level"							"1"
    "MaxLevel"                      "1"
	
	
	"AbilityBehavior"				"DOTA_ABILITY_BEHAVIOR_NO_TARGET"
	// "AbilityType"                   "DOTA_ABILITY_TYPE_BASIC"
	// "AbilityUnitTargetType"      	"DOTA_UNIT_TARGET_BUILDING"
	
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
			"Function"				"cf_builder_common_test2"
     		// "EventName" 			"OnSpellStart"
     		// "Target" 				"POINT"
		}
	}
}