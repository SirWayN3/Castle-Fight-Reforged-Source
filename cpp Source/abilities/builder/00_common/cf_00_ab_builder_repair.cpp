"cf_00_ab_builder_repair"
{
	/*
		[self]
		target=Ability_Names_Builder
		type=ability
		name=Repair
		descr=Repair Buildings.
		[modifier_builder_repairing]
		target=Ability_Names_Builder
		type=modifier
		name=Repairing
		descr=Doing my job as a builder...
		[modifier_repairing]
		target=Ability_Names_Builder
		type=modifier
		name=Repairing
		descr=Getting repaired.
	*/
	// General
	//-------------------------------------------------------------------------------------------------------------
	"BaseClass"                     "ability_datadriven"
	
	"Level"							"1"
    "MaxLevel"                      "1"
	
	
	"AbilityBehavior"				" DOTA_ABILITY_BEHAVIOR_UNIT_TARGET | DOTA_ABILITY_BEHAVIOR_AUTOCAST "
	"AbilityUnitTargetTeam" 		"DOTA_UNIT_TARGET_TEAM_FRIENDLY"
	"AbilityUnitTargetType"      	"DOTA_UNIT_TARGET_BUILDING"
	"AbilityUnitTargetFlags" 		"DOTA_UNIT_TARGET_FLAG_INVULNERABLE"

	"AbilityTextureName" 			"shredder_return_chakram_2"
	
	// Casting
	//-------------------------------------------------------------------------------------------------------------
	"AbilityCastPoint"				"0.4"
	"AbilityCastRange"				"100"
    "AbilityCastRangeBuffer"  		"500"
    // "AbilityChannelTime" 			"99999"
    // "AbilityChannelTime" 			"-1"
	"cf_autocast"				"1"		// Ability is checked for this Entry. Then AutoCast is enabled.
	"cf_ai_ab_castondamaged"	"1"		// Ability will Target only damaged Units.

	// Time		
	//-------------------------------------------------------------------------------------------------------------
	"AbilityCooldown"				"5"
	
	// Cost
	//-------------------------------------------------------------------------------------------------------------
	"AbilityManaCost"				"0"
	
	// "AbilitySound"					"Hero_Antimage.Blink_out"

	// Special	
	//-------------------------------------------------------------------------------------------------------------

	// "AbilityCastAnimation"		"ACT_DOTA_CAST_ABILITY_1"
	"OnSpellStart" // Also works for Channel Starting
	{		
		"RunScript"
		{
			"ScriptFile"	"libraries/repair.lua"
			"Function"		"Repair"
		}
	}
	
}