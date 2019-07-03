"cf_02_ab_cr10_03"
{
	/*
		[self]
		target=Ability_Names_Naga
		type=ability
		name=Defend
		descr=Reduces incoming Spell Damage.<br>Spell Damage Reduction: %spell_reduction%%
	*/
	// Defender Defend

	"BaseClass"                     "ability_datadriven"
	"AbilityBehavior"				"DOTA_ABILITY_BEHAVIOR_PASSIVE"
	// "AbilityUnitTargetType"			"DOTA_UNIT_TARGET_CREEP | DOTA_UNIT_TARGET_BUILDING"
	"AbilityTextureName" 			"antimage_spell_shield"

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
			"spell_reduction"			"70" // Chance in Percent
		}
	}
	"Modifiers"
	{
		"cf_mo_ancient_hydra"
		{
			"Passive"					"1"
			"IsHidden"					"1"
			"Properties"
			{
				"MODIFIER_PROPERTY_MAGICAL_RESISTANCE_BONUS"	"%spell_reduction"
			}

		}
	}
}

