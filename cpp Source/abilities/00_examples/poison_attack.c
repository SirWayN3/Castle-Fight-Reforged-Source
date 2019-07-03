"cf_XX_ab_crXX_XX_poison"
{
	/*
		[self]
		target=Ability_Names_Naga
		type=ability
		name=Poison Attack
		descr=
		lore=Toxic inside
		[cf_mo_hydra_poison_debuff]
		target=Ability_Names_Naga
		type=modifier
		name=Poisoned
		descr=This unit has been Poisoned reducing Attackspeed, Movespeed and taking damage over time.
	*/
	// General
	//-------------------------------------------------------------------------------------------------------------
	"BaseClass"						"ability_datadriven"
	"AbilityBehavior"				" DOTA_ABILITY_BEHAVIOR_PASSIVE | DOTA_ABILITY_BEHAVIOR_ATTACK"
	"AbilityUnitTargetTeam"			"DOTA_UNIT_TARGET_TEAM_ENEMY"
	"AbilityUnitTargetType"			"DOTA_UNIT_TARGET_HERO | DOTA_UNIT_TARGET_BASIC"
	"AbilityUnitDamageType"			"DAMAGE_TYPE_MAGICAL"	
	"SpellImmunityType"				"SPELL_IMMUNITY_ENEMIES_NO"
	"AbilityTextureName"			"viper_poison_attack"

	// Time		
	//-------------------------------------------------------------------------------------------------------------
	"AbilityCooldown"				"0.0"
	"precache"
	{
		"soundfile"		"soundevents/game_sounds_heroes/game_sounds_viper.vsndevts"
		"particle"		"particles/units/heroes/hero_viper/viper_poison_attack.vpcf"
		"particle"		"particles/units/heroes/hero_viper/viper_poison_debuff.vpcf"
	}
	// Special
	//-------------------------------------------------------------------------------------------------------------
	"AbilitySpecial"
	{
		"01"
		{
			"var_type"						"FIELD_FLOAT"
			"duration"						"2.0"
		}
		"02"
		{
			"var_type"						"FIELD_INTEGER"
			"damage"						"4"
		}
		"03"
		{
			"var_type"						"FIELD_INTEGER"
			"bonus_movement_speed"			"-30"
		}
		"04"
		{
			"var_type"						"FIELD_INTEGER"
			"bonus_attack_speed"			"-30"
		}
	}

	"Modifiers"
	{
		"cf_mo_hydra_poison"
		{
			"Passive"	"1"
			"IsHidden"	"1"

			"Orb"
			{
				"Priority"			"DOTA_ORB_PRIORITY_ABILITY"
				"ProjectileName"	"particles/units/heroes/hero_viper/viper_poison_attack.vpcf"
				// "CastAttack"		"1"
			}

			"OnOrbFire"
			{
				"FireSound"
				{
					"EffectName"	"Hero_Viper.poisonAttack.Cast"
					"Target"		"CASTER"
				}
			}

			"OnOrbImpact"
			{
				"ApplyModifier"
				{
					"ModifierName"	"cf_mo_hydra_poison_debuff"
					"Target"		"TARGET"
				}

				"FireSound"
				{
					"EffectName"	"Hero_Viper.PoisonAttack.Target"
					"Target"		"TARGET"
				}
			}
		}

		"cf_mo_hydra_poison_debuff"
		{
			"IsDebuff"	"1"
			"Duration"	"%duration"

			"EffectName"	"particles/units/heroes/hero_viper/viper_poison_debuff.vpcf"
			"EffectAttachType"	"follow_origin"

			"ThinkInterval"	"1.0"

			"OnIntervalThink"
			{
				"Damage"
				{
					"Target"	"TARGET"
					"Type"		"DAMAGE_TYPE_MAGICAL"
					"Damage"	"%damage"
				}
			}

			"Properties"
			{
				"MODIFIER_PROPERTY_ATTACKSPEED_BONUS_CONSTANT"	"%bonus_attack_speed"
				"MODIFIER_PROPERTY_MOVESPEED_BONUS_PERCENTAGE"	"%bonus_movement_speed"
			}
		}
	}
}