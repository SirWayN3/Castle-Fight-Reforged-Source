"cf_02_ab_bu02_up1"
{
	/*
		[self]
		target=Ability_Names_Naga
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

	"cf_AbilityGoldCost"			"725"
	"cf_AbilityManaCost"			"450"
	"cf_AbilityEssenceCost"			"1"

	"Level"							"1"
	"MaxLevel"                      "1"

	"UpgradeTime"					"10"
	"cf_upgrade_bu_to"				"cf_02_bu_14_lernaean_fountain"

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

