"cf_fort_right"
{
	/*
		[self]
		target=Building_Names
		type=building
		name=Fort Dire
	*/
	"cf_attacktype"				""
	"cf_defensetype"			"CF_COMBAT_ARMOR_FORTIFIED"
	"ArmorPhysical"			"10"
	"UnitName"					"cf_fort_right"

	"BaseClass"					"npc_dota_fort"	// Class of entity of link to.
	"Model"						"models/props_structures/dire_ancient_base001.vmdl"	// Model.

	"MinimapIcon"				"minimap_ancient"
	"MinimapIconSize"			"400"
	"HealthBarOffset"			"400"
	// Repair Stats
	"BuildTime"					"60"
	
	// Abilities
	//----------------------------------------------------------------
	
	"Ability1"					""			// Ability 1.
	"Ability2"					""			// Ability 2.
	"Ability3"					""			// Ability 3.
	"Ability4"					""			// Ability 4.
	"Ability5"					""			// Ability 5.
	"Ability6"					""			// Ability 6 - Extra.
	"Ability7"					""			// Ability 7 - Extra.
	"Ability8"					""			// Ability 8 - Extra.

	// Armor
	//----------------------------------------------------------------
	// "ArmorPhysical"				"0"		// Physical protection.
	"MagicalResistance"			"0"			// Magical protection.

	// Attack
	//----------------------------------------------------------------
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

	// Bounty
	//----------------------------------------------------------------
	"BountyGoldMin"				"0"			// Gold earned min.
	"BountyGoldMax"				"0"			// Gold earned max.

	// Bounds
	//----------------------------------------------------------------
	"BoundsHullName"			"DOTA_HULL_SIZE_BUILDING"			// Hull type used for navigation/locomotion.
	"RingRadius"				"350"

	// Movement
	//----------------------------------------------------------------
	"MovementCapabilities"		"DOTA_UNIT_CAP_MOVE_NONE"			// Type of locomotion - ground, air
	"MovementSpeed"				"0"			// Speed
	"MovementTurnRate"			"0"			// Turning rate.

	// Status
	//----------------------------------------------------------------
	"StatusHealth"				"4500"		// Base health.
	"StatusHealthRegen"			"10"			// Health regeneration rate.
	"StatusMana"				"0"			// Base mana.
	"StatusManaRegen"			"0"			// Mana regeneration rate.

	// Team
	//----------------------------------------------------------------
	"TeamName"					"DOTA_TEAM_BADGUYS"			// Team name.
	"CombatClassAttack"			"DOTA_COMBAT_CLASS_ATTACK_SIEGE"
	"CombatClassDefend"			"DOTA_COMBAT_CLASS_DEFEND_STRUCTURE"
	"UnitRelationshipClass"		"DOTA_NPC_UNIT_RELATIONSHIP_TYPE_BUILDING"
	
	// Does not work properly
	// "VisionDaytimeRange" 		"30000" // Range of vision during day light.
	// "VisionNighttimeRange" 		"30000" // Range of vision at night time.
}