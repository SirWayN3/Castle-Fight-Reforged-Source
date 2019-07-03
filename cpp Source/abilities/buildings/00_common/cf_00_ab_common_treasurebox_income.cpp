"cf_00_ab_common_treasurebox_income"
{
	/*
		[self]
		target=Ability_Names_Common
		type=ability
		name=Treasure Box gives Income.
		[cf_mo_bu_treasurebox]
		target=Ability_Names_Common
		type=modifier
		name=Treasure Box
		descr=Gives Bonus Income
	*/
	"BaseClass"                     "ability_datadriven"
	"AbilityBehavior"				"DOTA_ABILITY_BEHAVIOR_PASSIVE"

	"AbilityManaCost"				"0"
	"AbilityGoldCost"				"0"
	"AbilityCooldown"				"0"
	
	"Level"							"1"
	"MaxLevel"                      "1"


	"Modifiers"
	{
		"cf_mo_bu_treasurebox"
		{
			"Passive"				"1"
			"IsHidden"				"0"
			// "IsBuff"				"1"

			"OnCreated"
			{
				"RunScript"
		        {
		            "ScriptFile"        "cf_income.lua"
		            "Function"          "cf_income_addtreasurebox"
		        }
			}
			"OnDestroy"
			{
				"RunScript"
		        {
		            "ScriptFile"        "cf_income.lua"
		            "Function"          "cf_income_subtreasurebox"
		        }
			}
		}
	}
}

