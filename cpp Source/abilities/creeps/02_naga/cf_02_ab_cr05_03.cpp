"cf_02_ab_cr05_03"
{
	/*
		[self]
		target=Ability_Names_Naga
		type=ability
		name=Hard Shell
		descr=Reduces incoming Attack Damage by %damage_reduct%%.
	*/
	// Common Bash Attack
	"BaseClass"                     "ability_datadriven"
	"AbilityBehavior"				"DOTA_ABILITY_BEHAVIOR_PASSIVE"
	"AbilityUnitTargetType"			"DOTA_UNIT_TARGET_CREEP"
	"AbilityTextureName" 			"tidehunter_kraken_shell"

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
			"damage_reduct"				"-80" // Percent
		}
	}
	"Modifiers"
	{
		"cf_mo_cr_hard_shell"
		{
			"Passive"					"1"
			"IsHidden"					"1"
			"Properties"
			{
				"MODIFIER_PROPERTY_INCOMING_DAMAGE_PERCENTAGE"	"%damage_reduct"
			}
		}
	}
}

