"cf_02_ab_bu08_01"
{
	/*
		[self]
		target=Ability_Names_Naga
		type=ability
		name=Convert
		descr=Takes control of a Random enemy Unit. Can't take Legendary Units.
	*/
	"BaseClass"                     "ability_datadriven"
	"AbilityBehavior"				" DOTA_ABILITY_BEHAVIOR_NO_TARGET | DOTA_ABILITY_BEHAVIOR_IMMEDIATE "
	
	"AbilityManaCost"				"18"
	"AbilityGoldCost"				"0"
	"AbilityCooldown"				"1"
	"AbilityUnitTargetTeam" 		"DOTA_UNIT_TARGET_TEAM_ENEMY"
	"AbilityUnitTargetType"			"DOTA_UNIT_TARGET_CREEP"
	"AbilityTextureName" 			"spectre_reality"
	"AbilityCastRange"				"30000"
	
	"Level"							"0"
    "MaxLevel"                      "1"

    "cf_ab_utility"					"1"
    "cf_autocast"					"1"
    
    "precache"
    {
    	"particle"					"particles/units/heroes/hero_treant/treant_overgrowth_vine_core_sparkly.vpcf"
    }
	"OnSpellStart"
	{
		"RunScript"
		{
			"ScriptFile"			"abilities/02_naga/cf_ab_naga.lua"
			"Function"				"cf_takecontrol"
			"particle"				"particles/units/heroes/hero_treant/treant_overgrowth_vine_core_sparkly.vpcf"
		}
	}
}

