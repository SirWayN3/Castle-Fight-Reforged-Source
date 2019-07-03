"cf_00_common_ab_bu_toggleautocast"
{
	/*
		[self]
		target=Ability_Names_Common
		type=ability
		name=Toggle Autocast
		[cf_mo_bu_autocast]
		target=Ability_Names_Common
		type=modifier
		name=Building AutoCast
		descr=Performing Autocast on Abilities...
	*/
	// Upgrade Building
	"BaseClass" 					"ability_datadriven"

	"AbilityType"                   "DOTA_ABILITY_TYPE_BASIC"
	"AbilityBehavior"				" DOTA_ABILITY_BEHAVIOR_NO_TARGET | DOTA_ABILITY_BEHAVIOR_IMMEDIATE | DOTA_ABILITY_BEHAVIOR_TOGGLE"
	"AbilityUnitTargetTeam" 		"DOTA_UNIT_TARGET_TEAM_CUSTOM"
	"AbilityUnitTargetType"      	"DOTA_UNIT_TARGET_BASIC"
	"AbilityTextureName" 			"invoker_alacrity"

	"cf_AbilityGoldCost"			"0"
	"cf_AbilityManaCost"			"0"
	"cf_AbilityEssenceCost"			"0"

	"Level"							"0"
	"MaxLevel"                      "1"


	"OnToggleOn"
	{
		"ApplyModifier"
		{
			"Target"				"CASTER"
			"ModifierName"			"cf_mo_bu_autocast"
		}
	}

	"OnToggleOff"
	{
		"RemoveModifier"
		{
			"Target"				"CASTER"
			"ModifierName"			"cf_mo_bu_autocast"
		}

	}
}

