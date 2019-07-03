"cf_01_ab_cr10_04"
{
	/*
		[self]
		target=Ability_Names_Humans
		type=ability
		name=Ressurect Units
		descr=Ressurect Dead Friendly Units.
		[cf_mo_cr_ressurect_paladin]
		target=Ability_Names_Humans
		type=modifier
		name=Ressurect Aura Owner
		[cf_mo_cr_ressurect_paladin_bonus]
		target=Ability_Names_Humans
		type=modifier
		name=Ressurect Aura Bonus
	*/
	// Ressurect
	"BaseClass"             		"ability_datadriven"
	"AbilityTextureName"			"item_ring_of_basilius"

	"AbilityBehavior"				"DOTA_ABILITY_BEHAVIOR_UNIT_TARGET"
	"AbilityUnitTargetTeam" 		"DOTA_UNIT_TARGET_TEAM_FRIENDLY" // Can only Ressurect Friendly Units
	"AbilityUnitTargetType"			"DOTA_UNIT_TARGET_CREEP"
	// "AbilityUnitTargetFlags"		"DOTA_UNIT_TARGET_FLAG_INVULNERABLE"

	"AbilityManaCost"				"103"
	"AbilityGoldCost"				"0"
	"AbilityCooldown"				"40"
	"AbilityCastRange"				"400"
	
    "cf_autocast"					"1"
    "cf_ai_ab_castoncorpse"			"1"

	"Level"							"1"
    "MaxLevel"                      "1"

    "Precache"
    {
		"particle"				"particles/econ/events/ti9/shovel/shovel_baby_roshan_spawn_burst.vpcf"
    }
	"AbilitySpecial"
	{
		"01"
		{
			"var_type"			"FIELD_INTEGER"
			"delay"				"0.8"
		}
	}
	"OnSpellStart"
	{
		"DelayedAction"
		{
			"Delay"					"%delay"
			"Action"
			{
				"RunScript"
				{
					"ScriptFile"			"abilities/01_human/cf_ab_ressurect.lua"	
					"Function"				"cf_ab_ressurect_onspellstart"
					"particle"				"particles/econ/events/ti9/shovel/shovel_baby_roshan_spawn_burst.vpcf"
				}
			}
		}
	}
	
}







