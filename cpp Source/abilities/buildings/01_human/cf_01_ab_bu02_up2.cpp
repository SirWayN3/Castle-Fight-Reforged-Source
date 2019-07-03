"cf_01_ab_bu02_up2"
{
	/*
		[self]
		target=Ability_Names_Humans
		type=ability
		name=Upgrade Building
		descr=Upgrade Building to $self.cf_upgrade_bu_to.this$.
	*/
	// Upgrade Building
	"BaseClass" 					"ability_datadriven"

	"AbilityType"                   "DOTA_ABILITY_TYPE_BASIC"
	"AbilityBehavior"				" DOTA_ABILITY_BEHAVIOR_NO_TARGET | DOTA_ABILITY_BEHAVIOR_IMMEDIATE "
	"AbilityUnitTargetTeam" 		"DOTA_UNIT_TARGET_TEAM_CUSTOM"
	"AbilityUnitTargetType"      	"DOTA_UNIT_TARGET_BASIC"

	"cf_AbilityGoldCost"			"160"
	"cf_AbilityManaCost"			"0"
	"cf_AbilityEssenceCost"			"0"

	"Level"							"1"
	"MaxLevel"                      "1"

	"UpgradeTime"					"10"
	"cf_upgrade_bu_to"				"cf_01_bu_13_marksmencamp"

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

