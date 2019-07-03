"cf_02_cr_13_hydra"
{
	/*
		[self]
		target=Creeps_Names
		type=unit
		name=Hydra
	*/
	"cf_attacktype"				"CF_COMBAT_ATTACK_CHAOS"
	"cf_defensetype"			"CF_COMBAT_ARMOR_MEDIUM"
	"ArmorPhysical"				"6"
	"HasCorpse"					"0"

	"Model"						"models/heroes/venomancer/venomancer.vmdl"	// Model.
	"ModelScale" 				"1"

	// DOTA_UNIT_CAP_NO_ATTACK   DOTA_UNIT_CAP_MELEE_ATTACK   DOTA_UNIT_CAP_RANGED_ATTACK   DOTA_UNIT_CAP_RANGED_ATTACK_DIRECTIONAL
	"AttackCapabilities"		"DOTA_UNIT_CAP_RANGED_ATTACK"
	"AttackDamageMin"			"75"		// Damage range min.
	"AttackDamageMax"			"125"		// Damage range max.
	"AttackRange"				"500"		// Range within a target can be attacked.
	"AttackRate"				"1.5"			// Speed of attack.
	"AttackTargetType"			"AI_ATTACK_ALL" // AI_ATTACK_ALL	AI_ATTACK_GROUND	AI_ATTACK_AIR

	"SoundSet"					"CastleFightCreep"							// Name of sound set.

	"ProjectileModel"			"particles/units/heroes/hero_venomancer/venomancer_base_attack.vpcf" // Particle 
	"ProjectileSpeed"			"900"
	//"AttackAnimationPoint"		"0.5"		// Normalized time in animation cycle to attack.

	"BaseClass"					"npc_dota_creature"	// Class of entity of link to.
	"Level"						"1"
	"AttackAcquisitionRange"	"1000"		// Range within a target can be acquired.

	"Ability1"					"cf_02_ab_cr13_01"			// Ability 1.
	"Ability2"					""			// Ability 2.
	"Ability3"					""			// Ability 3.
	"Ability4"					""			// Ability 4.

	"BountyGoldMin"				"5"		// Gold earned min.
	"BountyGoldMax"				"5"		// Gold earned max.

	// Bounds
	//----------------------------------------------------------------
	"BoundsHullName"			"DOTA_HULL_SIZE_SMALL"			// Hull type used for navigation/locomotion.
	"RingRadius"				"45"
	"HealthBarOffset"			"150"

	// Movement
	//----------------------------------------------------------------
	"MovementCapabilities"		"DOTA_UNIT_CAP_MOVE_GROUND"	 // DOTA_UNIT_CAP_MOVE_NONE DOTA_UNIT_CAP_MOVE_GROUND DOTA_UNIT_CAP_MOVE_FLY
	"MovementSpeed"				"350"		// Speed
	"MovementTurnRate"			"0.5"		// Turning rate.

	// Status
	//----------------------------------------------------------------
	"StatusHealth"				"750"		// Base health.
	"StatusHealthRegen"			"8"		// Health regeneration rate.
	"StatusMana"				"0"			// Base mana.
	"StatusManaRegen"			"0"			// Mana regeneration rate.
	"StatusStartingMana" 		"0" 		// -1 means default to full mana
	// "ArmorPhysical"				"0"

	"CombatClassAttack"			"DOTA_COMBAT_CLASS_ATTACK_BASIC"
	"CombatClassDefend"			"DOTA_COMBAT_CLASS_DEFEND_BASIC"
	"UnitRelationshipClass"		"DOTA_NPC_UNIT_RELATIONSHIP_TYPE_DEFAULT"
	"Creature"
    {
        "AttachWearables" // Acid Hydra
        {
            "1" { "ItemDef" "7078" } // Acidic Ward of the Hydra
            "2" { "ItemDef" "10890" } // Acid Hydra Cursor Pack
            "3" { "ItemDef" "6940" } // Acidic Tentacles of the Hydra
            "4" { "ItemDef" "6933" } // Acidic Mandible of the Hydra
            "5" { "ItemDef" "6943" } // Acidic Wings of the Hydra
            "6" { "ItemDef" "6942" } // Acidic Tail of the Hydra
        }
	}
}