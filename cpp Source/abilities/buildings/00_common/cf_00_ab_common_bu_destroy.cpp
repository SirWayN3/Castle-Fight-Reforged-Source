"cf_00_common_ab_bu_destroy"
{
	/*
		[self]
		target=Ability_Names_Common
		type=ability
		name=Destroy this Building
		descr=Destroys this Building. Only Valid in Tools Mode
	*/
	// Will be added when building has been finished. Only in Tools Mode
	"BaseClass" 					"ability_datadriven"

	"AbilityType"                   "DOTA_ABILITY_TYPE_BASIC"
	// "AbilityBehavior"				" DOTA_ABILITY_BEHAVIOR_NO_TARGET | DOTA_ABILITY_BEHAVIOR_IMMEDIATE | DOTA_ABILITY_BEHAVIOR_TOGGLE "
	"AbilityBehavior"				" DOTA_ABILITY_BEHAVIOR_NO_TARGET | DOTA_ABILITY_BEHAVIOR_IMMEDIATE "
	"AbilityUnitTargetTeam" 		"DOTA_UNIT_TARGET_TEAM_CUSTOM"
	"AbilityUnitTargetType"      	"DOTA_UNIT_TARGET_BASIC"

	"AbilityManaCost"				"0"
	"AbilityGoldCost"				"0"
	"AbilityCooldown"				"0"

	"Level"							"1"
	"MaxLevel"                      "1"
	"OnSpellStart"
	{
		"RunScript"
		{
			"ScriptFile"			"abilities/common/cf_common_ab_bu_destroy"
			"Function"				"cf_common_ab_bu_destroy"
			"Target"				"CASTER"
		}
	}
	"OnToggleOn"
	{
		"RunScript"
		{
			"ScriptFile"            "abilities/common/cf_common_ab_bu_destroy"
			"Function"          	"cf_common_ab_bu_destroy_on"
			"Target" 				"CASTER"
		}
	}
	"OnToggleOff"
	{
		"RunScript"
		{
			"ScriptFile"            "abilities/common/cf_common_ab_bu_destroy"
			"Function"          	"cf_common_ab_bu_destroy_off"
			"Target" 				"CASTER"
		}
	}

}

