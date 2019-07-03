"cf_01_cr_09_marksman"
{
	/*
		[self]
		target=Creeps_Names
		type=unit
		name=Marksman
	*/
	"cf_attacktype"				"CF_COMBAT_ATTACK_PIERCE"
	"cf_defensetype"			"CF_COMBAT_ARMOR_MEDIUM"
	"ArmorPhysical"				"1"
	"HasCorpse"					"1"

	"Model"						"models/heroes/sniper/sniper.vmdl"	// Model.
	"Portrait" 					"vgui/hud/heroportraits/portrait_sniper"
	"ModelScale" 				"0.9"

	// DOTA_UNIT_CAP_NO_ATTACK   DOTA_UNIT_CAP_MELEE_ATTACK   DOTA_UNIT_CAP_RANGED_ATTACK   DOTA_UNIT_CAP_RANGED_ATTACK_DIRECTIONAL
	"AttackCapabilities"		"DOTA_UNIT_CAP_RANGED_ATTACK"
	"AttackDamageMin"			"43"		// Damage range min.
	"AttackDamageMax"			"95"		// Damage range max.
	"AttackRange"				"500"		// Range within a target can be attacked.
	"AttackRate"				"1"			// Speed of attack.
	"AttackTargetType"			"AI_ATTACK_AIR" // AI_ATTACK_ALL	AI_ATTACK_GROUND	AI_ATTACK_AIR

	"SoundSet"					"CastleFightCreep"							// Name of sound set.
	
	"ProjectileModel"			"particles/units/heroes/hero_sniper/sniper_base_attack.vpcf"
	"ProjectileSpeed" 			"3000"
	"AttackAnimationPoint"		"0.5"		// Normalized time in animation cycle to attack.

	"BaseClass"					"npc_dota_creature"	// Class of entity of link to.
	"Level"						"1"
	"AttackAcquisitionRange"	"1000"		// Range within a target can be acquired.

	"Ability1"					"cf_01_ab_cr09_01"			// Ability 1.
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
	"MovementSpeed"				"275"		// Speed
	"MovementTurnRate"			"0.5"		// Turning rate.

	// Status
	//----------------------------------------------------------------
	"StatusHealth"				"450"		// Base health.
	"StatusHealthRegen"			"0.5"		// Health regeneration rate.
	"StatusMana"				"0"			// Base mana.
	"StatusManaRegen"			"0"			// Mana regeneration rate.
	"StatusStartingMana" 		"0" 		// -1 means default to full mana
	// "ArmorPhysical"				"0"

	"CombatClassAttack"			"DOTA_COMBAT_CLASS_ATTACK_BASIC"
	"CombatClassDefend"			"DOTA_COMBAT_CLASS_DEFEND_BASIC"
	"UnitRelationshipClass"		"DOTA_NPC_UNIT_RELATIONSHIP_TYPE_DEFAULT"
	"Creature"
    {
        "AttachWearables" // Default npc_dota_hero_sniper
        {
            "1" { "ItemDef" "281" } // Sniper's Weapon
            "2" { "ItemDef" "282" } // Sniper's Cape
            "3" { "ItemDef" "283" } // Sniper's Head Gear
            "4" { "ItemDef" "284" } // Sniper's Shoulder Armor
            // "5" { "ItemDef" "285" } // Sniper's Bracers
        }
	}

}