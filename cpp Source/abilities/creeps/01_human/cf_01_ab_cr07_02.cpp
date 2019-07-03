"cf_01_ab_cr07_02"
{
	/*
		[self]
		target=Ability_Names_Humans
		type=ability
		name=Defend
		descr=Chance to Reflect a Ranged Attack. Also Reduces Ranged Incoming Damage and Spell Damage.<br>Spell Damage Reduction: %spell_reduction%% <br>Chance to Reflect Ranged Attacks: %ranged_reflect%% <br>Damage Reduction Percent from Ranged Attacks: %ranged_reduction% 
		[cf_mo_cr_defend]
		target=Ability_Names_Humans
		type=modifier
		name=Defend
	*/
	// Defender Defend

	"BaseClass"                     "ability_datadriven"
	"AbilityBehavior"				"DOTA_ABILITY_BEHAVIOR_PASSIVE"
	// "AbilityUnitTargetType"			"DOTA_UNIT_TARGET_CREEP | DOTA_UNIT_TARGET_BUILDING"
	"AbilityTextureName" 			"mars_bulwark"

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
			"spell_reduction"			"50" // Chance in Percent
		}
		"02"
		{
			"var_type"					"FIELD_INTEGER"
			"ranged_reflect"			"50" // Chance in Percent
		}
		"03"
		{
			"var_type"					"FIELD_INTEGER"
			"ranged_reduction"			"40" // Reduction in Percent
		}
	}
	"OnProjectileHitUnit"
	{
		
		"RunScript"
		{
			"ScriptFile"		"abilities/01_human/cf_ab_defend.lua"
			"Function"			"cf_ab_defend_projectile"
		}
	}
	"Modifiers"
	{
		"cf_mo_cr_defend"
		{
			"Passive"					"1"
			"IsHidden"					"1"
			"Properties"
			{
				"MODIFIER_PROPERTY_MAGICAL_RESISTANCE_BONUS"	"%spell_reduction"
			}
			// "OnCreated"
			// {
				
			// }
			"OnTakeDamage"
			{
				"RunScript"
				{
					"ScriptFile"		"abilities/01_human/cf_ab_defend.lua"
					"Function"			"cf_ab_defend"
					"damage"			"%attack_damage"
					"ranged_reflect"	"%ranged_reflect"
					"ranged_reduction"	"%ranged_reduction"
				}
			}

		}
	}
}

