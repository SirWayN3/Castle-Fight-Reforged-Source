"cf_00_common_ab_bu_upgrade"
{
	/*
		[self]
		target=Ability_Names_Common
		type=ability
		name=Upgrade Dummy
	*/
	// Upgrade Building
	"BaseClass" 					"ability_datadriven"

	"AbilityType"                   "DOTA_ABILITY_TYPE_BASIC"
	"AbilityBehavior"				" DOTA_ABILITY_BEHAVIOR_NO_TARGET | DOTA_ABILITY_BEHAVIOR_IMMEDIATE "
	"AbilityUnitTargetTeam" 		"DOTA_UNIT_TARGET_TEAM_CUSTOM"
	"AbilityUnitTargetType"      	"DOTA_UNIT_TARGET_BASIC"
	// "AbilityTextureName" 			"invoker_alacrity"

	"cf_AbilityGoldCost"			"175"
	"cf_AbilityManaCost"			"0"
	"cf_AbilityEssenceCost"			"0"

	"Level"							"0"
	"MaxLevel"                      "1"

	"UpgradeTime"					"10"
	"cf_upgrade_bu_to"				"UNIT_NAME"

	"OnSpellStart"
	{
		"RunScript"
		{
			"ScriptFile"            "abilities/common/cf_common_ab_bu_upgrade"
			"Function"          	"cf_common_ab_bu_upgrade"
			// "Target" 				"CASTER"
		}
	}

}

