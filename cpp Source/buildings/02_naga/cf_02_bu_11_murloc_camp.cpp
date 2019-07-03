"cf_02_bu_11_murloc_camp"
{
	/*
		[self]
		target=Building_Names
		type=building
		name=Murloc Camp
	*/
	"cf_attacktype"				""
	"cf_defensetype"			"CF_COMBAT_ARMOR_FORTIFIED"
	"ArmorPhysical"				"5"
	"cf_incomeincrease"			"2.6"
	"cf_energyincrease"			"130"
	"cf_spawner"				"1"
	"ConstructionSize"			"3"
	"PedestalModel"				"models/items/pedestals/pedestal_2/pedestal_2.vmdl"
	"PedestalModelScale"		"1.2"

	// "BaseClass"					"npc_dota_base"	// Class of entity of link to.
	"BaseClass"					"npc_dota_building"	// Class of entity of link to.
	"Model"						"models/heroes/dragon_knight/dragon_knight.vmdl"	// Model.
	"ModelScale" 				"0.8"

	"HealthBarOffset"			"400"
	
	"StatusHealth"				"1300"		// Base health.
	"StatusHealthRegen"			"0"			// Health regeneration rate.

	
	"Ability1"					"cf_02_ab_bu11_01"			// Ability 1.
	"Ability2"					"cf_00_common_ab_bu_toggleautocast"			// Ability 2.
	"Ability3"					""			// Ability 3.
	"Ability4"					""			// Ability 4.
	"Ability5"					""			// Ability 5.
	"Ability6"					""			// Ability 6 - Extra.
	"Ability7"					""			// Ability 7 - Extra.
	"Ability8"					"cf_02_ab_bu11_up1"			// Ability 8 - Extra.

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

	"BountyGoldMin"				"50"			// Gold earned min.
	"BountyGoldMax"				"50"			// Gold earned max.

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