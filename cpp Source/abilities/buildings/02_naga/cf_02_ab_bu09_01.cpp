"cf_02_ab_bu09_01"
{
	/*
		[self]
		target=Ability_Names_Naga
		type=ability
		name=Regen Aura
		descr=Increases HP Regen of Buildings and Units in Range of %radius%.<br>Hp Regen for Buildings: %hp_bu%hp/sec<br>Hp Regen for Creeps: %hp_cr%hp/sec
	*/
	"BaseClass"                     "ability_datadriven"
	"AbilityBehavior"				" DOTA_ABILITY_BEHAVIOR_NO_TARGET | DOTA_ABILITY_BEHAVIOR_IMMEDIATE "
	
	"AbilityManaCost"				"0"
	"AbilityGoldCost"				"0"
	"AbilityCooldown"				"0"
	"AbilityUnitTargetTeam" 		"DOTA_UNIT_TARGET_TEAM_FRIENDLY"
	"AbilityUnitTargetType"			"DOTA_UNIT_TARGET_CREEP | DOTA_UNIT_TARGET_BUILDING"
	"AbilityTextureName" 			"filler_ability"
	"AbilityCastRange"				"700"
	
	"Level"							"0"
    "MaxLevel"                      "1"

    "cf_ab_utility"					"1"
	"cf_unit_count"					"1"
    "cf_autocast"					"1"
    
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
			"hp_bu"				"2.5"
		}
		"03"
		{
			"var_type"			"FIELD_FLOAT"
			"hp_cr"				"7.5"
		}
		"04"
		{
			"var_type"			"FIELD_INTEGER"
			"interval"			"1"
		}
	}
	"OnSpellStart"
	{
		"RunScript"
		{
			"ScriptFile"	"abilities/02_naga/cf_ab_naga.lua"
			"Function"		"cf_ab_coral_statue"
			"hp_bu"			"%hp_bu"
			"hp_cr"			"%hp_cr"
			"radius"		"%radius"
		}
	}

	
}

