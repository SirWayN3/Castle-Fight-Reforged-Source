"cf_02_cr_09_murloc_assasin"
{
	/*
		[self]
		target=Creeps_Names
		type=unit
		name=Murloc Assasin
	*/
	"cf_attacktype"				"CF_COMBAT_ATTACK_NORMAL"
	"cf_defensetype"			"CF_COMBAT_ARMOR_UNARMED"
	"ArmorPhysical"				"8"
	"HasCorpse"					"1"

	"Model"						"models/heroes/dragon_knight/dragon_knight.vmdl"	// Model.
	"Portrait" 					"vgui/hud/heroportraits/portrait_dragon_knight"
	"ModelScale" 				"0.8"

	// DOTA_UNIT_CAP_NO_ATTACK   DOTA_UNIT_CAP_MELEE_ATTACK   DOTA_UNIT_CAP_RANGED_ATTACK   DOTA_UNIT_CAP_RANGED_ATTACK_DIRECTIONAL
	"AttackCapabilities"		"DOTA_UNIT_CAP_MELEE_ATTACK"
	"AttackDamageMin"			"55"		// Damage range min.
	"AttackDamageMax"			"70"		// Damage range max.
	"AttackRange"				"128"		// Range within a target can be attacked.
	"AttackRate"				"1.25"			// Speed of attack.
	"AttackTargetType"			"AI_ATTACK_GROUND" // AI_ATTACK_ALL	AI_ATTACK_GROUND	AI_ATTACK_AIR

	"SoundSet"					"CastleFightCreep"							// Name of sound set.

	//"ProjectileModel"			"particles/base_attacks/ranged_badguy.vpcf" // Particle system model for projectile.
	//"ProjectileSpeed"			"900"		// Speed of projectile.
	//"AttackAnimationPoint"		"0.5"		// Normalized time in animation cycle to attack.

	"BaseClass"					"npc_dota_creature"	// Class of entity of link to.
	"Level"						"1"
	"AttackAcquisitionRange"	"1000"		// Range within a target can be acquired.

	"Ability1"					"cf_02_ab_cr09_01"			// Ability 1.
	"Ability2"					"cf_02_ab_cr09_02"			// Ability 2.
	"Ability3"					"cf_02_ab_cr09_03"			// Ability 3.
	"Ability4"					"cf_02_ab_cr09_04"			// Ability 4.
	"Ability5"					"cf_02_ab_cr09_05"

	"BountyGoldMin"				"10"		// Gold earned min.
	"BountyGoldMax"				"10"		// Gold earned max.

	// Bounds
	//----------------------------------------------------------------
	"BoundsHullName"			"DOTA_HULL_SIZE_SMALL"			// Hull type used for navigation/locomotion.
	"RingRadius"				"45"
	"HealthBarOffset"			"150"

	// Movement
	//----------------------------------------------------------------
	"MovementCapabilities"		"DOTA_UNIT_CAP_MOVE_GROUND"	 // DOTA_UNIT_CAP_MOVE_NONE DOTA_UNIT_CAP_MOVE_GROUND DOTA_UNIT_CAP_MOVE_FLY
	"MovementSpeed"				"280"		// Speed
	"MovementTurnRate"			"0.5"		// Turning rate.

	// Status
	//----------------------------------------------------------------
	"StatusHealth"				"750"		// Base health.
	"StatusHealthRegen"			"1"		// Health regeneration rate.
	"StatusMana"				"0"			// Base mana.
	"StatusManaRegen"			"0"			// Mana regeneration rate.
	"StatusStartingMana" 		"0" 		// -1 means default to full mana
	// "ArmorPhysical"				"0"

	"CombatClassAttack"			"DOTA_COMBAT_CLASS_ATTACK_BASIC"
	"CombatClassDefend"			"DOTA_COMBAT_CLASS_DEFEND_BASIC"
	"UnitRelationshipClass"		"DOTA_NPC_UNIT_RELATIONSHIP_TYPE_DEFAULT"
	"Creature"
    {
        "DisableClumpingBehavior"       "1"
        "AttachWearables"
        {
            // "1" { "ItemDef" "67" } // Dragon Knight's Offhand
            "2" { "ItemDef" "66" } // Dragon Knight's Weapon
            // "3" { "ItemDef" "65" } // Dragon Knight's Bracers
            // "4" { "ItemDef" "64" } // Dragon Knight's Shoulder Armor
            // "5" { "ItemDef" "8647" } // Dragon Knight's Elder Dragon
            "6" { "ItemDef" "63" } // Dragon Knight's Helmet
			// "7" { "ItemDef" "68" } // Dragon Knight's Skirt
        }
    }
}