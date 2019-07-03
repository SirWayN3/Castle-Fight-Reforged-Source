"cf_01_ab_cr10_03"
{
	/*
		[self]
		target=Ability_Names_Humans
		type=ability
		name=Bless Unit
		descr=Bonus Armor: %armor%<br>Bonus HP Regen: %hp_regen%<br>Duration: %duration%s<br>Bonus Max HP: %bonus_hp%
		[cf_bless_paladin]
		target=Ability_Names_Humans
		type=modifier
		name=Blessed
		descr=Bonus Armor, Bonus HP and Bonus HP Regen
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
			"armor"						"9" // Chance in Percent
		}
		"02"
		{
			"var_type"					"FIELD_INTEGER"
			"hp_regen"					"24"
		}
		"03"
		{
			"var_type"					"FIELD_INTEGER"
			"duration"					"11" // Duration in Seconds
		}
		"04"
		{
			"var_type"					"FIELD_INTEGER"
			"bonus_hp"					"100"
		}
	}

	"OnSpellStart"
	{
		"ApplyModifier"
		{
			"ModifierName"				"cf_bless_paladin"
			"Target"					"TARGET"
		}
	}
	"Modifiers"
	{
		"cf_bless_paladin"
		{
			"Duration"					"%duration"
			"IsPurgable"				"1"
			"IsBuff"					"1"
			"Properties"
			{

				"MODIFIER_PROPERTY_HEALTH_REGEN_CONSTANT"	"%hp_regen"
				"MODIFIER_PROPERTY_PHYSICAL_ARMOR_BONUS" 	"%armor"
				"MODIFIER_PROPERTY_HEALTH_BONUS"			"%bonus_hp"
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

