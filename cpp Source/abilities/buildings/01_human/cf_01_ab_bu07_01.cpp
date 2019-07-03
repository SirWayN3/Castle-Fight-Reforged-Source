"cf_01_ab_bu07_01"
{
	/*
		[self]
		target=Ability_Names_Humans
		type=ability
		name=Holy Power
		descr=Gives Allied Units Bonus Attack Speed
		[cf_mo_cr_holy_power]
		target=Ability_Names_Humans
		type=modifier
		name=Holy Power
		descr=Gives Bonus Attack Speed
	*/
	"BaseClass"                     "ability_datadriven"
	"AbilityBehavior"				" DOTA_ABILITY_BEHAVIOR_NO_TARGET | DOTA_ABILITY_BEHAVIOR_IMMEDIATE "

	"AbilityManaCost"				"0"
	"AbilityGoldCost"				"0"
	"AbilityCooldown"				"7"
	
	"Level"							"0"
	"MaxLevel"                      "1"

	"cf_utility"					"1"
	"cf_autocast"					"1"

	// "AbilityUnitDamageType"         "DAMAGE_TYPE_PURE"
	"AbilityUnitTargetType"      	"DOTA_UNIT_TARGET_CREEP"
	"AbilityUnitTargetTeam"			"DOTA_UNIT_TARGET_TEAM_FRIENDLY"

	"AbilityCastRange"				"400"

	"precache"
	{
		"particle"				"particles/units/heroes/hero_sven/sven_spell_warcry.vpcf"
		"soundfile"				"sounds/weapons/hero/sven/warcry.vsnd"

	}
	
	"AbilitySpecial"
	{
		"01"
		{
			"var_type"      	"FIELD_INTEGER"
			"attackspeed"  		"66" // attackspeed Bonus in percent
		}
		"02"
		{
			"var_type"			"FIELD_INTEGER"
			"duration"			"-1"
		}
		"03"
		{
			"var_type"			"FIELD_INTEGER"
			"radius"			"400"
		}
	}

	"OnSpellStart"
	{
		"FireEffect"
		{
			"EffectName"			"particles/units/heroes/hero_sven/sven_spell_warcry.vpcf"
			"EffectAttachType"      "follow_origin"
			"Target"                "CASTER"
			"EffectRadius"			"%radius"
		}
		"FireSound"
		{
			"EffectName"			"sounds/weapons/hero/sven/warcry.vsnd"
			"Target"				"CASTER"
		}
		"ApplyModifier"
		{
			"Target"
			{
				"Center"			"CASTER"
				"Radius"			"%radius"
				"Teams"				"DOTA_UNIT_TARGET_TEAM_FRIENDLY"
				"Types"				"DOTA_UNIT_TARGET_CREEP"
			}
			"ModifierName"			"cf_mo_cr_holy_power"
			"Duration"				"%duration"
		}
	}

	"Modifiers"
	{
		"cf_mo_cr_holy_power"
		{
			"Passive"				"1"
			"IsPurgable"			"0"
			"IsHidden" 				"0"

			"IsBuff" 		"1"
			"IsPurgable" 	"1"

			"Properties"
			{
				"MODIFIER_PROPERTY_ATTACKSPEED_BONUS_CONSTANT"		"%attackspeed"
			}

		}
	}
}

