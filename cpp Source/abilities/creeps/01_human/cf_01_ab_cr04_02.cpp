"cf_01_ab_cr04_02"
{
	/*
		[self]
		target=Ability_Names_Humans
		type=ability
		name=Chain Lightning
		descr=Chance: %chance%%<br> Bonus Dmg: %bonus_dmg%<br>Jump Count: %jump_count%
	*/
	// Gryphon Rider Chain Lightning

	"BaseClass"                     "ability_datadriven"
	"AbilityBehavior"				"DOTA_ABILITY_BEHAVIOR_PASSIVE"
	"AbilityUnitTargetType"			"DOTA_UNIT_TARGET_CREEP"
	"AbilityTextureName" 			"zuus_arc_lightning"

	"AbilityManaCost"				"0"
	"AbilityGoldCost"				"0"
	"AbilityCooldown"				"0"
	
	"Level"							"1"
    "MaxLevel"                      "1"

	// Special
	//-------------------------------------------------------------------------------------------------------------
	"AbilitySpecial"
	{
		"01"
		{
			"var_type"					"FIELD_INTEGER"
			"chance"					"10" // Chance in Percent
		}
		"02"
		{
			"var_type"					"FIELD_INTEGER"
			"bonus_dmg"					"150"
		}
		"03"
		{
			"var_type"					"FIELD_INTEGER"
			"jump_count"				"0" // Duration in Seconds
		}
	}

	"Modifiers"
	{
		"cf_mo_cr_chain"
		{
			"Passive"					"1"
			"IsHidden"					"1"
			"OnAttackLanded"
			{
				"Random"
				{
					"Chance"			"%chance"
					"OnSuccess"
					{
						"RunScript"
						{
							"ScriptFile"			"abilities/01_human/cf_ab_chainlightning.lua"
							"Function"				"cf_ab_gryphon_chain"
							"Target"				"TARGET"
							"Damage"				"%bonus_dmg"
     						"particle_jump" 		"particles/units/heroes/hero_zuus/zuus_arc_lightning_.vpcf"
						}

					}
				}
			}
		}
	}
}

