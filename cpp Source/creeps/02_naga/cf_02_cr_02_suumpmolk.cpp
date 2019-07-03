"cf_02_cr_02_suumpmolk"
{
	/*
		[self]
		target=Creeps_Names
		type=unit
		name=Suumpmolk
	*/
	"cf_attacktype"				"CF_COMBAT_ATTACK_NORMAL"
	"cf_defensetype"			"CF_COMBAT_ARMOR_MEDIUM"
	"ArmorPhysical"				"3"
	"HasCorpse"					"1"

	"Model"						"models/heroes/weaver/weaver.vmdl"	// Model.
	// "Portrait" 					"vgui/hud/heroportraits/portrait_dragon_knight"
	"ModelScale" 				"0.8"

	// DOTA_UNIT_CAP_NO_ATTACK   DOTA_UNIT_CAP_MELEE_ATTACK   DOTA_UNIT_CAP_RANGED_ATTACK   DOTA_UNIT_CAP_RANGED_ATTACK_DIRECTIONAL
	"AttackCapabilities"		"DOTA_UNIT_CAP_RANGED_ATTACK"
	"AttackDamageMin"			"38"		// Damage range min.
	"AttackDamageMax"			"38"		// Damage range max.
	"AttackRange"				"325"		// Range within a target can be attacked.
	"AttackRate"				"1.37"			// Speed of attack.
	"AttackTargetType"			"AI_ATTACK_ALL" // AI_ATTACK_ALL	AI_ATTACK_GROUND	AI_ATTACK_AIR

	"SoundSet"					"CastleFightCreep"							// Name of sound set.

	"ProjectileModel"			"particles/units/heroes/hero_venomancer/venomancer_base_attack.vpcf" // Particle system model for projectile.
	"ProjectileSpeed"			"900"		// Speed of projectile.
	"AttackAnimationPoint"		"0.5"		// Normalized time in animation cycle to attack.

	"BaseClass"					"npc_dota_creature"	// Class of entity of link to.
	"Level"						"1"
	"AttackAcquisitionRange"	"1000"		// Range within a target can be acquired.

	"Ability1"					"cf_02_ab_cr02_01"			// Ability 1.
	"Ability2"					""			// Ability 2.
	"Ability3"					""			// Ability 3.
	"Ability4"					""			// Ability 4.

	"BountyGoldMin"				"6"		// Gold earned min.
	"BountyGoldMax"				"6"		// Gold earned max.

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
	"StatusHealth"				"380"		// Base health.
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
        "AttachWearables" // Default npc_dota_hero_weaver
        {
            "1" { "ItemDef" "280" } // Weaver's Back
            "2" { "ItemDef" "278" } // Weaver's Legs
            "3" { "ItemDef" "277" } // Weaver's Antennae
            "4" { "ItemDef" "585" } // Weaver's Miscellaneous
            "5" { "ItemDef" "279" } // Weaver's Arms
        }
    }
}