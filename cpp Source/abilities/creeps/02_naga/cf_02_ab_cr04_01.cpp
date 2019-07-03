"cf_02_ab_cr04_01"
{
	/*
		[self]
		target=Ability_Names_Naga
		type=ability
		name=Cleave Attack
		descr=Radius: %radius%<br>Damage Percent: %percent%%
	*/
	// Common Cleave Attack
	"BaseClass"                     "ability_datadriven"
	"AbilityBehavior"				"DOTA_ABILITY_BEHAVIOR_PASSIVE"
	"AbilityUnitTargetType"			"DOTA_UNIT_TARGET_CREEP | DOTA_UNIT_TARGET_BUILDING"
	"AbilityTextureName" 			"sven_great_cleave"

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
			"radius"					"230" 
		}
		"02"
		{
			"var_type"					"FIELD_INTEGER"
			"percent"					"35"
		}
	}

	"Modifiers"
	{
		"cf_mo_cr_cleave"
		{
			"Passive"					"1"
			"IsHidden"					"0"
			"OnAttackLanded"
			{
				"CleaveAttack"
				{
					"CleavePercent"			"%percent"
					"CleaveRadius"			"%radius"
				}
			}
		}
	}
}

