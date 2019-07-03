"cf_01_ab_builder_bu01"
{
	/*
		[self]
		target=Ability_Names_Builder
		type=ability
		name=Build $self.UnitName.this$
		descr=$self.UnitName.this$ trains $cf_01_cr_01_footman.this$. Cheap meele Units.<br>Upgradable to $cf_01_cr_07_defender.this$.<br><br>Gold Cost: $self.cf_AbilityGoldCost$
	*/
	"BaseClass"                     "ability_datadriven"
	"AbilityTextureName"			""
	
	"Level"							"1"
    "MaxLevel"                      "1"
	
	"cf_AbilityEnergyCost"			"0"
	"cf_AbilityGoldCost"			"100"
	"cf_AbilityEssenceCost"			"0"
	"cf_custombuildpanel"			"1"
	
	"BuildTime"						"10"
	"UnitName"						"cf_01_bu_01_barracks"
	



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