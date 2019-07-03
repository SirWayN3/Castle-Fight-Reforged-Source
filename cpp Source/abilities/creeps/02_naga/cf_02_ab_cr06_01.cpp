"cf_02_ab_cr06_01"
{
	/*
		[self]
		target=Ability_Names_Naga
		type=ability
		name=Purge
		descr=Purges a target enemy Unit. Removes Buffs and Slows over time.<br>Deals %summon_damage% damage to summoned Units.
		lore=This might sting...
	*/
	// Common Bless Ability
	"BaseClass"                     "ability_datadriven"
	"AbilityBehavior"				"DOTA_ABILITY_BEHAVIOR_UNIT_TARGET"
	"AbilityUnitTargetTeam" 		"DOTA_UNIT_TARGET_TEAM_ENEMY"
	"AbilityUnitTargetType"			" DOTA_UNIT_TARGET_HERO | DOTA_UNIT_TARGET_CREEP"
	"AbilityTextureName" 			"leshrac_pulse_nova"

	"AbilityManaCost"				"20"
	"AbilityGoldCost"				"0"
	"AbilityCooldown"				"6"
	"AbilityCastRange" 				"500"
	"AbilityCastAnimation"			"ACT_DOTA_CAST_ABILITY_1"
	
    "cf_autocast"					"1"
    
	"Level"							"1"
    "MaxLevel"                      "1"

	// Special
	//-------------------------------------------------------------------------------------------------------------
	"AbilitySpecial"
	{
		"01"
		{
			"var_type"					"FIELD_INTEGER"
			"duration"					"7" // Duration in Seconds
		}
		"02"
		{
			"var_type"					"FIELD_INTEGER"
			"as_slow"					"-100"
		}
		"03"
		{
			"var_type"					"FIELD_INTEGER"
			"ms_slow"					"-100" 
		}
		"04"
		{
			"var_type"				"FIELD_INTEGER"
			"summon_damage"			"400"
		}
	}
	"OnSpellStart"
	{
		"RunScript"
		{
			"ScriptFile"				"abilities/02_naga/cf_ab_naga.lua"
			"Target"					"TARGET"
			"Function"					"cf_ab_naga_purge"
			"duration"					"%duration"
			"as_slow"					"%as_slow"
			"ms_slow"					"%ms_slow"
			"summon_damage"				"%summon_damage"
		}
	}
}

