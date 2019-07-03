"cf_00_ab_builder_treasurechest"
{
	/*
		[self]
		target=Ability_Names_Builder
		type=ability
		name=Build $self.UnitName.this$
		descr=Increases Income with every $self.UnitName.this$. More of this type, still increase Income, but less then the last.
		lore=Gold is shiny... But Fragile...
	*/
	"BaseClass"                     "ability_datadriven"
	"AbilityTextureName"			"alchemist_goblins_greed"
	
	"Level"							"1"
    "MaxLevel"                      "1"
	
	"cf_AbilityEnergyCost"			"500"
	"cf_AbilityGoldCost"			"350"
	"cf_AbilityEssenceCost"			"0"
	"cf_custombuildpanel"			"1"
	
	"BuildTime"						"10"
	"UnitName"						"cf_00_bu_01_treasurechest"
	



	"Building"						"1"
	"PlayerCanControl"				"1"
	"Scale"							"1"

	"AbilityCastRange" 				"250"
	"AbilityCooldown"				"1"
	"AbilityType"                   "DOTA_ABILITY_TYPE_BASIC"
	"AbilityBehavior"				" DOTA_ABILITY_BEHAVIOR_NO_TARGET | DOTA_ABILITY_BEHAVIOR_IMMEDIATE | DOTA_ABILITY_BEHAVIOR_HIDDEN "
	"AbilityUnitTargetTeam" 		"DOTA_UNIT_TARGET_TEAM_CUSTOM"
	"AbilityUnitTargetType"      	"DOTA_UNIT_TARGET_BASIC"
	// "SpellImmunityType" 			"SPELL_IMMUNITY_ENEMIES_YES"

	"OnSpellStart"
    {
        "RunScript"
        {
            "ScriptFile"        "libraries/builder.lua"
            "Function"          "Build"
        }
	}
}