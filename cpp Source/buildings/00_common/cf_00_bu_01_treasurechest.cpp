"cf_00_bu_01_treasurechest"
{
	/*
		[self]
		target=Building_Names
		type=building
		name=Treasure Chest
	*/
	"cf_attacktype"				""
	"cf_defensetype"			"CF_COMBAT_ARMOR_FORTIFIED"
	"cf_armorvalue"				"5"
	"cf_incomeincrease"			"2"
	"cf_treasurebox"			"1"
	"ConstructionSize"			"2"
	
	"BaseClass"					"npc_dota_base"	// Class of entity of link to.
	"Model"						"models/props_gameplay/treasure_chest_gold.vmdl"	// Model.
	"ModelScale" 				"1.5"

	"HealthBarOffset"			"400"
	
	"StatusHealth"				"1200"		// Base health.
	"StatusHealthRegen"			"0"			// Health regeneration rate.

	
	"Ability1"					"cf_00_ab_common_treasurebox_income"			// Ability 1.
	"Ability2"					""			// Ability 2.
	"Ability3"					""			// Ability 3.
	"Ability4"					""			// Ability 4.
	"Ability5"					""			// Ability 5.
	"Ability6"					""			// Ability 6 - Extra.
	"Ability7"					""			// Ability 7 - Extra.
	"Ability8"					""			// Ability 8 - Extra.

	// "ArmorPhysical"				"0"		// Physical protection.
	"MagicalResistance"			"0"			// Magical protection.
	"AttackCapabilities"		"DOTA_UNIT_CAP_NO_ATTACK"
	"AttackDamageMin"			"0"			// Damage range min.
	"AttackDamageMax"			"0"			// Damage range max.
	"AttackDamageType"			"DAMAGE_TYPE_ArmorPhysical"
	"AttackRate"				"0"			// Speed of attack.
	"AttackAnimationPoint"		"0"			// Normalized time in animation cycle to attack.
	"AttackAcquisitionRange"	"0"			// Range within a target can be acquired.
	"AttackRange"				"0"			// Range within a target can be attacked.
	"ProjectileModel"			""			// Particle system model for projectile.
	"ProjectileSpeed"			"0"			// Speed of projectile.

	"BountyGoldMin"				"0"			// Gold earned min.
	"BountyGoldMax"				"0"			// Gold earned max.

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