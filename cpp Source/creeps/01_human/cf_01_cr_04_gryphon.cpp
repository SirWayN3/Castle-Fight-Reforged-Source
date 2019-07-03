"cf_01_cr_04_gryphonrider"
{
	/*
		[self]
		target=Creeps_Names
		type=unit
		name=Gryphon
	*/
	"cf_attacktype"				"CF_COMBAT_ATTACK_MAGIC"
	"cf_defensetype"			"CF_COMBAT_ARMOR_MEDIUM"
	"ArmorPhysical"				"0"
	"HasCorpse"					"0"

	"Model"						"models/heroes/visage/visage_familiar.vmdl"
	"ModelScale" 				"0.6"
	
	// DOTA_UNIT_CAP_NO_ATTACK   DOTA_UNIT_CAP_MELEE_ATTACK   DOTA_UNIT_CAP_RANGED_ATTACK   DOTA_UNIT_CAP_RANGED_ATTACK_DIRECTIONAL
	"AttackCapabilities"		"DOTA_UNIT_CAP_RANGED_ATTACK"
	"AttackDamageMin"			"45"		// Damage range min.
	"AttackDamageMax"			"50"		// Damage range max.
	"AttackRange"				"450"		// Range within a target can be attacked.
	"AttackRate"				"2"			// Speed of attack.
	"AttackTargetType"			"AI_ATTACK_ALL" // AI_ATTACK_ALL	AI_ATTACK_GROUND	AI_ATTACK_AIR

	"SoundSet"					"CastleFightCreep"							// Name of sound set.
	
	"ProjectileModel"			"particles/units/heroes/hero_techies/techies_base_attack.vpcf"
	"ProjectileSpeed" 			"900"
	"AttackAnimationPoint"		"0.5"		// Normalized time in animation cycle to attack.

	"BaseClass"					"npc_dota_creature"	// Class of entity of link to.
	"Level"						"1"
	"AttackAcquisitionRange"	"1000"		// Range within a target can be acquired.

	"Ability1"					"cf_01_ab_cr04_01"			// Ability 1.
	"Ability2"					"cf_01_ab_cr04_02"			// Ability 2.
	"Ability3"					""			// Ability 3.
	"Ability4"					""			// Ability 4.

	"BountyGoldMin"				"8"		// Gold earned min.
	"BountyGoldMax"				"8"		// Gold earned max.

	// Bounds
	//----------------------------------------------------------------
	"BoundsHullName"			"DOTA_HULL_SIZE_SMALL"			// Hull type used for navigation/locomotion.
	"RingRadius"				"45"
	"HealthBarOffset"			"150"

	// Movement
	//----------------------------------------------------------------
	"MovementCapabilities"		"DOTA_UNIT_CAP_MOVE_FLY"	 // DOTA_UNIT_CAP_MOVE_NONE DOTA_UNIT_CAP_MOVE_GROUND DOTA_UNIT_CAP_MOVE_FLY
	"MovementSpeed"				"350"		// Speed
	"MovementTurnRate"			"0.5"		// Turning rate.

	// Status
	//----------------------------------------------------------------
	"StatusHealth"				"500"		// Base health.
	"StatusHealthRegen"			"0.5"		// Health regeneration rate.
	"StatusMana"				"0"			// Base mana.
	"StatusManaRegen"			"0"			// Mana regeneration rate.
	"StatusStartingMana" 		"0" 		// -1 means default to full mana
	// "ArmorPhysical"				"0"

	"CombatClassAttack"			"DOTA_COMBAT_CLASS_ATTACK_BASIC"
	"CombatClassDefend"			"DOTA_COMBAT_CLASS_DEFEND_BASIC"
	"UnitRelationshipClass"		"DOTA_NPC_UNIT_RELATIONSHIP_TYPE_DEFAULT"
	
}