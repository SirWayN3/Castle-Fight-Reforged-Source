"cf_01_ab_cr06_01"
{
	/*
		[self]
		target=Ability_Names_Humans
		type=ability
		name=Chamber
		descr=When ready, launches a powerful AoE Damage Attack. But disabling the unit and pushing it back from the Explosion.<br><br>Bonus Damage: %bonus_dmg%<br>AoE Radius: %aoe_radius%<br>Pushback Distance: %pushback_distance%<br>Disabled Duration: %disabled_duration%
		[cf_mo_cr_chamber_disabled]
		target=Ability_Names_Humans
		type=modifier
		name=Chamber Results
		descr=Too bad... Silenced, Rooted and Disarmed
	*/
	// Warlock Chamber AoE Attack

	"BaseClass"                     "ability_datadriven"
	"AbilityBehavior"				"DOTA_ABILITY_BEHAVIOR_UNIT_TARGET "
	"AbilityUnitTargetType"			"DOTA_UNIT_TARGET_CREEP"
	"AbilityUnitTargetTeam"			"DOTA_UNIT_TARGET_TEAM_ENEMY"
	"AbilityTextureName" 			"pugna_nether_blast"

	"AbilityManaCost"				"35"
	"AbilityGoldCost"				"0"
	"AbilityCooldown"				"12"
	
	"Level"							"1"
	"MaxLevel"                      "1"
	"precache"
	{
		"particle"			"particles/units/heroes/hero_pugna/pugna_netherblast.vpcf"
	}
	// Special
	//-------------------------------------------------------------------------------------------------------------
	"AbilitySpecial"
	{
		"01"
		{
			"var_type"					"FIELD_INTEGER"
			"bonus_dmg"					"270" 
		}
		"02"
		{
			"var_type"					"FIELD_INTEGER"
			"aoe_radius"				"370"
		}
		"03"
		{
			"var_type"					"FIELD_INTEGER"
			"pushback_distance"			"1000"
		}
		"04"
		{
			"var_type"					"FIELD_INTEGER"
			"disabled_duration"			"10"
		}
	}
	"Modifiers"
	{
		"cf_mo_chamber"
		{
			"Passive"					"1"
			"IsHidden"					"1"
			"OnAttack"
			{
				"RunScript"
				{
					"ScriptFile"					"abilities/01_human/cf_ab_chamber.lua"
					"Function"						"cf_ab_chamber"
					"Target"						"TARGET"
				}
			}
		}
		"cf_mo_cr_chamber_disabled"
		{
			"Passive"					"0"
			"IsHidden"					"0"
			"States"
			{
				"MODIFIER_STATE_DISARMED"		"MODIFIER_STATE_VALUE_ENABLED"
				"MODIFIER_STATE_ROOTED"			"MODIFIER_STATE_VALUE_ENABLED"
				"MODIFIER_STATE_SILENCED"		"MODIFIER_STATE_VALUE_ENABLED"
			}
		}
	}
	"OnSpellStart"
	{
		"Knockback"
		{
			"Target"							"CASTER"
			"Center"							"TARGET"
			"Duration"							"1"
			"Distance"							"%pushback_distance"
			"Height"							"0"
			"ShouldStun"						"FALSE"

		}
		"FireEffect"
		{
			"Target"							"CASTER"
			"EffectName"						"particles/units/heroes/hero_pugna/pugna_netherblast.vpcf"
			"EffectAttachType"					"follow_origin"
			"EffectRadius"						"%aoe_radius"

			"EffectLifeDurationScale"			"1"

		}
		"ApplyModifier"
		{
			"Target"							"CASTER"
			"ModifierName"						"cf_mo_cr_chamber_disabled"
			"Duration"							"%disabled_duration"
		}
		"Damage"
		{
			"Target"
			{
				"Center"						"TARGET"
				"Radius"						"%aoe_radius"
				"Teams"							"DOTA_UNIT_TARGET_TEAM_ENEMY"
				"Types"							"DOTA_UNIT_TARGET_CREEP"
			}
			"Type"								"DAMAGE_TYPE_MAGICAL"
			"Damage"							"%bonus_dmg"
		}
	}
}

