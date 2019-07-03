"cf_02_ab_cr06_02"
{
	/*
		[self]
		target=Ability_Names_Naga
		type=ability
		name=Summon $self.cf_unitcount$ $self.cf_unitname.this$
		descr=
		lore=
	*/
	// Common Bless Ability
	"BaseClass"                     "ability_datadriven"
	"AbilityBehavior"				" DOTA_ABILITY_BEHAVIOR_NO_TARGET "
	"AbilityUnitTargetTeam" 		"DOTA_UNIT_TARGET_TEAM_ENEMY"
	"AbilityUnitTargetType"			" DOTA_UNIT_TARGET_HERO | DOTA_UNIT_TARGET_CREEP"
	"AbilityTextureName" 			"weaver_the_swarm"

	"AbilityManaCost"				"70"
	"AbilityGoldCost"				"0"
	"AbilityCooldown"				"60"
	"AbilityCastRange" 				"600"
	"AbilityCastAnimation"			"ACT_DOTA_CAST_ABILITY_1"
	
    "cf_autocast"					"1"
    "cf_unitname"					"cf_02_cr_12_lobster"
    "cf_unitcount"					"2"
    
	"Level"							"1"
    "MaxLevel"                      "1"

	// Special
	//-------------------------------------------------------------------------------------------------------------
	"AbilitySpecial"
	{
		"01"
		{
			"var_type"				"FIELD_INTEGER"
			"duration"				"45" // Percent
		}
	}
	"OnSpellStart"
	{
		"RunScript"
		{
			"ScriptFile"				"abilities/02_naga/cf_ab_naga.lua"
			"Function"					"cf_ab_naga_summonlobster"
			"duration"					"%duration"
		}
	}
}

