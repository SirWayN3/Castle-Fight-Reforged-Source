"cf_01_bu_09_watchtower"
{
	/*
		[self]
		target=Building_Names
		type=building
		name=Watchtower
	*/
	"cf_attacktype"				"CF_COMBAT_ATTACK_PIERCE"
	"cf_defensetype"			"CF_COMBAT_ARMOR_FORTIFIED"
	"ArmorPhysical"			"8"
	"cf_incomeincrease"			"1.2"
	"cf_energyincrease"			"0"
	"ConstructionSize"			"3"
	"AttackTargetType"			"AI_ATTACK_ALL" // AI_ATTACK_ALL	AI_ATTACK_GROUND	AI_ATTACK_AIR
	
	
	// "BaseClass"					"npc_dota_base"	// Class of entity of link to.
	"BaseClass"					"npc_dota_building"	// Class of entity of link to.
	"Model"						"models/props_structures/radiant_melee_barracks001.vmdl"	// Model.
	"ModelScale" 				"0.25"

	"HealthBarOffset"			"400"
	
	"StatusHealth"				"1500"		// Base health.
	"StatusHealthRegen"			"0"			// Health regeneration rate.

	
	"Ability1"					""			// Ability 1.
	"Ability2"					""			// Ability 2.
	"Ability3"					""			// Ability 3.
	"Ability4"					""			// Ability 4.
	"Ability5"					""			// Ability 5.
	"Ability6"					""			// Ability 6 - Extra.
	"Ability7"					""			// Ability 7 - Extra.
	"Ability8"					""			// Ability 8 - Extra.

	// "ArmorPhysical"				"0"		// Physical protection.
	"MagicalResistance"			"0"			// Magical protection.
	"AttackCapabilities"		"DOTA_UNIT_CAP_RANGED_ATTACK"
	"AttackDamageMin"			"40"			// Damage range min.
	"AttackDamageMax"			"50"			// Damage range max.
	"AttackDamageType"			"DAMAGE_TYPE_ArmorPhysical"
	"AttackRate"				"0.5"			// Speed of attack.
	"AttackAnimationPoint"		"0"			// Normalized time in animation cycle to attack.
	"AttackAcquisitionRange"	"1000"			// Range within a target can be acquired.
	"AttackRange"				"950"			// Range within a target can be attacked.
	"ProjectileModel"			"particles/units/heroes/hero_clinkz/clinkz_base_attack.vpcf" // Particle system model for projectile.
	"ProjectileSpeed" 			"2000" // Speed of projectile.

	"BountyGoldMin"				"37"			// Gold earned min.
	"BountyGoldMax"				"37"			// Gold earned max.

	"BoundsHullName"			"DOTA_HULL_SIZE_BUILDING"			// Hull type used for navigation/locomotion.
	"RingRadius"				"50"

	"MovementCapabilities"		"DOTA_UNIT_CAP_MOVE_NONE"			// Type of locomotion - ground, air
	"MovementSpeed"				"0"			// Speed
	"MovementTurnRate"			"0"			// Turning rate.

	"StatusMana"				"0"			// Base mana.
	"StatusManaRegen"			"0"			// Mana regeneration rate.

	"CombatClassAttack"			"DOTA_COMBAT_CLASS_ATTACK_SIEGE"
	"CombatClassDefend"			"DOTA_COMBAT_CLASS_DEFEND_STRUCTURE"
	"UnitRelationshipClass"		"DOTA_NPC_UNIT_RELATIONSHIP_TYPE_BUILDING"
	
}