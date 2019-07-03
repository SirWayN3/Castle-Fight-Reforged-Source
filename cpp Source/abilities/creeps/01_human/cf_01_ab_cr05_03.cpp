"cf_01_ab_cr05_03"
{
	/*
		[self]
		target=Ability_Names_Humans
		type=ability
		name=Bless Unit
		descr=Bonus Armor: %armor%<br>Bonus HP Regen: %hp_regen%<br>Duration: %duration%s
		[cf_bless_crusader]
		target=Ability_Names_Humans
		type=modifier
		name=Blessed
		descr=Bonus Armor and Bonus HP Regen
	*/
	// Common Bless Ability
	"BaseClass"                     "ability_datadriven"
	"AbilityBehavior"				"DOTA_ABILITY_BEHAVIOR_UNIT_TARGET"
	"AbilityUnitTargetTeam" 		"DOTA_UNIT_TARGET_TEAM_FRIENDLY"
	"AbilityUnitTargetType"			"DOTA_UNIT_TARGET_CREEP"
	"AbilityTextureName" 			"omniknight_repel"

	"AbilityManaCost"				"33"
	"AbilityGoldCost"				"0"
	"AbilityCooldown"				"7"
	"AbilityCastRange" 				"300"
	
    "cf_autocast"					"1"
    "cf_ai_ab_castondamaged"		"1"

	"Level"							"1"
    "MaxLevel"                      "1"

	// Special
	//-------------------------------------------------------------------------------------------------------------
	"AbilitySpecial"
	{
		"01"
		{
			"var_type"					"FIELD_INTEGER"
			"armor"						"6" // Chance in Percent
		}
		"02"
		{
			"var_type"					"FIELD_INTEGER"
			"hp_regen"					"16"
		}
		"03"
		{
			"var_type"					"FIELD_INTEGER"
			"duration"					"10" // Duration in Seconds
		}
	}

	"OnSpellStart"
	{
		"ApplyModifier"
		{
			"ModifierName"				"cf_bless_crusader"
			"Target"					"TARGET"
		}
	}
	"Modifiers"
	{
		"cf_bless_crusader"
		{
			"Duration"					"%duration"
			"IsPurgable"				"1"
			"IsBuff"					"1"
			"Properties"
			{

				"MODIFIER_PROPERTY_HEALTH_REGEN_CONSTANT"	"%hp_regen"
				"MODIFIER_PROPERTY_PHYSICAL_ARMOR_BONUS" 	"%armor"
				}
			"OnCreated"
			{
				"AttachEffect"
				{
					"EffectName" 			"particles/units/heroes/hero_legion_commander/legion_commander_press_ribbon.vpcf"
					"EffectAttachType" 		"follow_origin"
					"Target" 				"TARGET"
				}
			}
		}
	}
}

