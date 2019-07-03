"cf_01_cr_05_crusader"
{
	/*
		[self]
		target=Creeps_Names
		type=unit
		name=Crusader
	*/
	"cf_attacktype"				"CF_COMBAT_ATTACK_HERO"
	"cf_defensetype"			"CF_COMBAT_ARMOR_HEAVY"
	"ArmorPhysical"				"6"
	"HasCorpse"					"1"

	"Model"						"models/heroes/omniknight/omniknight.vmdl"
	"Portrait" 					"vgui/hud/heroportraits/portrait_omniknight"
	"ModelScale" 				"0.8"

	// DOTA_UNIT_CAP_NO_ATTACK   DOTA_UNIT_CAP_MELEE_ATTACK   DOTA_UNIT_CAP_RANGED_ATTACK   DOTA_UNIT_CAP_RANGED_ATTACK_DIRECTIONAL
	"AttackCapabilities"		"DOTA_UNIT_CAP_MELEE_ATTACK"
	"AttackDamageMin"			"50"		// Damage range min.
	"AttackDamageMax"			"70"		// Damage range max.
	"AttackRange"				"128"		// Range within a target can be attacked.
	"AttackRate"				"1.42"			// Speed of attack.
	"AttackTargetType"			"AI_ATTACK_GROUND" // AI_ATTACK_ALL	AI_ATTACK_GROUND	AI_ATTACK_AIR

	"SoundSet"					"CastleFightCreep"							// Name of sound set.
	
	"ProjectileModel"			"particles/units/heroes/hero_techies/techies_base_attack.vpcf"
	"ProjectileSpeed" 			"900"
	"AttackAnimationPoint"		"0.5"		// Normalized time in animation cycle to attack.

	"BaseClass"					"npc_dota_creature"	// Class of entity of link to.
	"Level"						"1"
	"AttackAcquisitionRange"	"1000"		// Range within a target can be acquired.

	"Ability1"					"cf_01_ab_cr05_01"			// Ability 1.
	"Ability2"					"cf_01_ab_cr05_02"			// Ability 2.
	"Ability3"					"cf_01_ab_cr05_03"			// Ability 3.
	"Ability4"					""			// Ability 4.

	"BountyGoldMin"				"12"		// Gold earned min.
	"BountyGoldMax"				"12"		// Gold earned max.

	// Bounds
	//----------------------------------------------------------------
	"BoundsHullName"			"DOTA_HULL_SIZE_SMALL"			// Hull type used for navigation/locomotion.
	"RingRadius"				"45"
	"HealthBarOffset"			"150"

	// Movement
	//----------------------------------------------------------------
	"MovementCapabilities"		"DOTA_UNIT_CAP_MOVE_GROUND"	 // DOTA_UNIT_CAP_MOVE_NONE DOTA_UNIT_CAP_MOVE_GROUND DOTA_UNIT_CAP_MOVE_FLY
	"MovementSpeed"				"375"		// Speed
	"MovementTurnRate"			"0.5"		// Turning rate.

	// Status
	//----------------------------------------------------------------
	"StatusHealth"				"600"		// Base health.
	"StatusHealthRegen"			"0.5"		// Health regeneration rate.
	"StatusMana"				"200"		// Base mana.
	"StatusManaRegen"			"2"			// Mana regeneration rate.
	"StatusStartingMana" 		"150" 		// -1 means default to full mana
	// "ArmorPhysical"				"0"

	"CombatClassAttack"			"DOTA_COMBAT_CLASS_ATTACK_BASIC"
	"CombatClassDefend"			"DOTA_COMBAT_CLASS_DEFEND_BASIC"
	"UnitRelationshipClass"		"DOTA_NPC_UNIT_RELATIONSHIP_TYPE_DEFAULT"
	"Creature"
    {
        "AttachWearables" // Default npc_dota_hero_omniknight
        {
            "1" { "ItemDef" "45" } // Omniknight's Head
            "2" { "ItemDef" "44" } // Omniknight's Weapon
            // "3" { "ItemDef" "13" } // Omniknight's Bracers
            "4" { "ItemDef" "42" } // Omniknight's Shoulders
            // "5" { "ItemDef" "562" } // Omniknight's Miscellaneous
            "6" { "ItemDef" "46" } // Omniknight's Hair
            // "7" { "ItemDef" "43" } // Omniknight's Cape
        }
	}
	
}