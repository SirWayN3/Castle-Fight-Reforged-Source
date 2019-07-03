"cf_01_cr_06_warlock"
{
	/*
		[self]
		target=Creeps_Names
		type=unit
		name=Warlock
	*/
	"cf_attacktype"				"CF_COMBAT_ATTACK_CHAOS"
	"cf_defensetype"			"CF_COMBAT_ARMOR_UNARMED"
	"ArmorPhysical"				"1"
	"HasCorpse"					"1"

	"Model"						"models/heroes/warlock/warlock.vmdl"	// Model.
	"Portrait" 					"vgui/hud/heroportraits/portrait_warlock"
	"ModelScale" 				"0.8"

	// DOTA_UNIT_CAP_NO_ATTACK   DOTA_UNIT_CAP_MELEE_ATTACK   DOTA_UNIT_CAP_RANGED_ATTACK   DOTA_UNIT_CAP_RANGED_ATTACK_DIRECTIONAL
	"AttackCapabilities"		"DOTA_UNIT_CAP_MELEE_ATTACK"
	"AttackDamageMin"			"30"		// Damage range min.
	"AttackDamageMax"			"33"		// Damage range max.
	"AttackRange"				"128"		// Range within a target can be attacked.
	"AttackRate"				"1.8"			// Speed of attack.
	"AttackTargetType"			"AI_ATTACK_GROUND" // AI_ATTACK_ALL	AI_ATTACK_GROUND	AI_ATTACK_AIR

	"SoundSet"					"CastleFightCreep"							// Name of sound set.
	
	"ProjectileModel"			"particles/units/heroes/hero_techies/techies_base_attack.vpcf"
	"ProjectileSpeed" 			"900"
	"AttackAnimationPoint"		"0.5"		// Normalized time in animation cycle to attack.

	"BaseClass"					"npc_dota_creature"	// Class of entity of link to.
	"Level"						"1"
	"AttackAcquisitionRange"	"1000"		// Range within a target can be acquired.

	"Ability1"					"cf_01_ab_cr06_01"			// Ability 1.
	"Ability2"					""			// Ability 2.
	"Ability3"					""			// Ability 3.
	"Ability4"					""			// Ability 4.

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
	"MovementSpeed"				"325"		// Speed
	"MovementTurnRate"			"0.5"		// Turning rate.

	// Status
	//----------------------------------------------------------------
	"StatusHealth"				"320"		// Base health.
	"StatusHealthRegen"			"0.5"		// Health regeneration rate.
	"StatusMana"				"100"		// Base mana.
	"StatusManaRegen"			"0.5"			// Mana regeneration rate.
	"StatusStartingMana" 		"100" 		// -1 means default to full mana
	// "ArmorPhysical"				"0"

	"CombatClassAttack"			"DOTA_COMBAT_CLASS_ATTACK_BASIC"
	"CombatClassDefend"			"DOTA_COMBAT_CLASS_DEFEND_BASIC"
	"UnitRelationshipClass"		"DOTA_NPC_UNIT_RELATIONSHIP_TYPE_DEFAULT"
	"Creature"
    {
        "AttachWearables" // Default npc_dota_hero_warlock
        {
            "1" { "ItemDef" "182" } // Warlock's Golem
            "2" { "ItemDef" "239" } // Warlock's Weapon
            "3" { "ItemDef" "240" } // Warlock's Lantern
            "4" { "ItemDef" "241" } // Warlock's Head
            "5" { "ItemDef" "245" } // Warlock's Bag
            "6" { "ItemDef" "242" } // Warlock's Shoulder
            "7" { "ItemDef" "244" } // Warlock's Robe
            "8" { "ItemDef" "243" } // Warlock's Arms
        }
	}
}