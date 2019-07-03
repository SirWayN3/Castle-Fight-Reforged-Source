"cf_00_ab_builder_blink"
{
	/*
		[self]
		target=Ability_Names_Builder
		type=ability
		name=Blink
	*/
	// General
	//-------------------------------------------------------------------------------------------------------------
	"BaseClass"                     "ability_datadriven"
	
	"Level"							"1"
    "MaxLevel"                      "1"
	
	
	"AbilityBehavior"				"DOTA_ABILITY_BEHAVIOR_POINT"
	// "AbilityType"                   "DOTA_ABILITY_TYPE_BASIC"
	// "AbilityUnitTargetType"      	"DOTA_UNIT_TARGET_NONE"
	
	// Casting
	//-------------------------------------------------------------------------------------------------------------
	"AbilityCastPoint"				"0.4"
	"AbilityCastRange"				"1000"

	// Time		
	//-------------------------------------------------------------------------------------------------------------
	"AbilityCooldown"				"5"
	
	// Cost
	//-------------------------------------------------------------------------------------------------------------
	"AbilityManaCost"				"0"
	
	"AbilitySound"					"Hero_Antimage.Blink_out"

	// Special	
	//-------------------------------------------------------------------------------------------------------------

	"AbilityCastAnimation"		"ACT_DOTA_CAST_ABILITY_1"
	"OnSpellStart"
	{
		"RunScript"
		{
			"ScriptFile"			"abilities/cf_builder_common.lua"
			"Function"				"cf_builder_common_blink"
     		"EventName" 			"OnSpellStart"
     		"Target" 				"POINT"
		}
	}
}