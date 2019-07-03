"cf_02_ab_cr10_01"
{
	/*
		[self]
		target=Ability_Names_Naga
		type=ability
		name=Split
		descr=Splits on death into $self.AB_SplitUnitCount$ $self.AB_SplitUnit.this$
		lore=You cant just kill a Hydra...
		[cf_mo_cr_split]
		target=Ability_Names_naga
		type=modifier
		name=Split
		descr=Splits into smaller Hydras.
	*/
	// Common Splash Attack

	"BaseClass"                     "ability_datadriven"
	"AbilityBehavior"				"DOTA_ABILITY_BEHAVIOR_PASSIVE"
	"AbilityUnitTargetType"			"DOTA_UNIT_TARGET_CREEP | DOTA_UNIT_TARGET_BUILDING"
	"AbilityTextureName" 			"venomancer_poison_nova" 

	"AbilityManaCost"				"0"
	"AbilityGoldCost"				"0"
	"AbilityCooldown"				"0"
	
	"Level"							"1"
    "MaxLevel"                      "1"

   	"AB_SplitUnitCount"				"2"
   	"AB_SplitUnit"					"cf_02_cr_13_hydra"

	"Modifiers"
	{
		"cf_mo_cr_split"
		{
			"Passive"					"1"
			"IsHidden"					"0"
			"OnDeath"
			{
				"RunScript"
				{
					"ScriptFile"		"abilities/02_naga/cf_ab_naga.lua"
					"Function"			"cf_ab_split"
				}
			}
		}
	}
}

