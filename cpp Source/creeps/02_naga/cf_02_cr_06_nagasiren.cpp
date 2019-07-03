"cf_02_cr_06_nagasiren"
{
	/*
		[self]
		target=Creeps_Names
		type=unit
		name=Naga Siren
	*/
	"cf_attacktype"				"CF_COMBAT_ATTACK_CHAOS"
	"cf_defensetype"			"CF_COMBAT_ARMOR_UNARMED"
	"ArmorPhysical"				"3"
	"HasCorpse"					"1"

	"Model"						"models/heroes/siren/siren.vmdl"	// Model.
	// "Portrait" 					"vgui/hud/heroportraits/portrait_dragon_knight"
	"ModelScale" 				"0.8"

	// DOTA_UNIT_CAP_NO_ATTACK   DOTA_UNIT_CAP_MELEE_ATTACK   DOTA_UNIT_CAP_RANGED_ATTACK   DOTA_UNIT_CAP_RANGED_ATTACK_DIRECTIONAL
	"AttackCapabilities"		"DOTA_UNIT_CAP_RANGED_ATTACK"
	"AttackDamageMin"			"60"		// Damage range min.
	"AttackDamageMax"			"100"		// Damage range max.
	"AttackRange"				"400"		// Range within a target can be attacked.
	"AttackRate"				"1.6"			// Speed of attack.
	"AttackTargetType"			"AI_ATTACK_ALL" // AI_ATTACK_ALL	AI_ATTACK_GROUND	AI_ATTACK_AIR

	"SoundSet"					"CastleFightCreep"							// Name of sound set.

	"ProjectileModel"			"particles/units/heroes/hero_shadowshaman/shadow_shaman_ward_base_attack.vpcf" // Particle system model for projectile.
	"ProjectileSpeed"			"900"		// Speed of projectile.
	//"AttackAnimationPoint"		"0.5"		// Normalized time in animation cycle to attack.

	"BaseClass"					"npc_dota_creature"	// Class of entity of link to.
	"Level"						"1"
	"AttackAcquisitionRange"	"1000"		// Range within a target can be acquired.

	"Ability1"					"cf_02_ab_cr06_01"			// Ability 1.
	"Ability2"					"cf_02_ab_cr06_02"			// Ability 2.
	"Ability3"					""			// Ability 3.
	"Ability4"					""			// Ability 4.

	"BountyGoldMin"				"11"		// Gold earned min.
	"BountyGoldMax"				"11"		// Gold earned max.

	// Bounds
	//----------------------------------------------------------------
	"BoundsHullName"			"DOTA_HULL_SIZE_SMALL"			// Hull type used for navigation/locomotion.
	"RingRadius"				"45"
	"HealthBarOffset"			"150"

	// Movement
	//----------------------------------------------------------------
	"MovementCapabilities"		"DOTA_UNIT_CAP_MOVE_GROUND"	 // DOTA_UNIT_CAP_MOVE_NONE DOTA_UNIT_CAP_MOVE_GROUND DOTA_UNIT_CAP_MOVE_FLY
	"MovementSpeed"				"290"		// Speed
	"MovementTurnRate"			"0.5"		// Turning rate.

	// Status
	//----------------------------------------------------------------
	"StatusHealth"				"550"		// Base health.
	"StatusHealthRegen"			"1"		// Health regeneration rate.
	"StatusMana"				"300"			// Base mana.
	"StatusManaRegen"			"2.5"			// Mana regeneration rate.
	"StatusStartingMana" 		"225" 		// -1 means default to full mana
	// "ArmorPhysical"				"0"

	"CombatClassAttack"			"DOTA_COMBAT_CLASS_ATTACK_BASIC"
	"CombatClassDefend"			"DOTA_COMBAT_CLASS_DEFEND_BASIC"
	"UnitRelationshipClass"		"DOTA_NPC_UNIT_RELATIONSHIP_TYPE_DEFAULT"
	"Creature"
    {
        "AttachWearables" // Default npc_dota_hero_naga_siren
        {
            "1" { "ItemDef" "191" } // Naga Siren's Head
            "2" { "ItemDef" "193" } // Naga Siren's Tail
            "3" { "ItemDef" "192" } // Naga Siren's Sword
            "4" { "ItemDef" "194" } // Naga Siren's Armor
            "5" { "ItemDef" "532" } // Naga Siren's Ambient Effects
            "6" { "ItemDef" "312" } // Naga Siren's Offhand Sword
        }
	}
}