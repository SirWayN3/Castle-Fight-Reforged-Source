"cf_01_ab_builder_bu07"
{
	/*
		[self]
		target=Ability_Names_Builder
		type=ability
		name=Build Gjallerhorn
	*/
	"BaseClass"                     "ability_datadriven"
	"AbilityTextureName"			""
	
	"Level"							"1"
    "MaxLevel"                      "1"
	
	"cf_AbilityEnergyCost"			"750"
	"cf_AbilityGoldCost"			"225"
	"cf_AbilityEssenceCost"			"0"
	"cf_custombuildpanel"			"1"
	
	"BuildTime"						"10"
	"UnitName"						"cf_01_bu_07_gjallerhorn"
	



	"Building"						"1"
	"PlayerCanControl"				"1"
	"Scale"							"1"

	"AbilityCastRange" 				"250"
	"AbilityCooldown"				"0"
	"AbilityType"                   "DOTA_ABILITY_TYPE_BASIC"
	"AbilityBehavior"				" DOTA_ABILITY_BEHAVIOR_IMMEDIATE | DOTA_ABILITY_BEHAVIOR_HIDDEN "
	"AbilityUnitTargetTeam" 		"DOTA_UNIT_TARGET_TEAM_CUSTOM"
	"AbilityUnitTargetType"      	"DOTA_UNIT_TARGET_BASIC"

	"OnSpellStart"
    {
        "RunScript"
        {
            "ScriptFile"        "libraries/builder.lua"
            "Function"          "Build"
        }
	}
}