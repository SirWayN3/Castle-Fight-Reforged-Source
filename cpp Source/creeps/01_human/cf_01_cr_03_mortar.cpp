"cf_01_cr_03_mortar"
{
	/*
		[self]
		target=Creeps_Names
		type=unit
		name=Mortar
	*/
	"cf_attacktype"				"CF_COMBAT_ATTACK_SIEGE"
	"cf_defensetype"			"CF_COMBAT_ARMOR_LIGHT"
	"ArmorPhysical"				"0"
	"HasCorpse"					"1"

	"Model"						"models/heroes/techies/techies.vmdl"
	// "Portrait" 					"vgui/hud/heroportraits/portrait_sniper"
	"ModelScale" 				"0.5"
	// "RenderablePortrait"
	// {
	// 	"Particles"
	// 	{
	// 		"particles/units/heroes/hero_techies/techies_loadout.vpcf"		"loadout"
	// 	}
	// }
	// DOTA_UNIT_CAP_NO_ATTACK   DOTA_UNIT_CAP_MELEE_ATTACK   DOTA_UNIT_CAP_RANGED_ATTACK   DOTA_UNIT_CAP_RANGED_ATTACK_DIRECTIONAL
	"AttackCapabilities"		"DOTA_UNIT_CAP_RANGED_ATTACK"
	"AttackDamageMin"			"68"		// Damage range min.
	"AttackDamageMax"			"80"		// Damage range max.
	"AttackRange"				"1000"		// Range within a target can be attacked.
	"AttackRangeMin"			"250"		// Minimum Attack Range
	"AttackRate"				"3.5"			// Speed of attack.
	"AttackTargetType"			"AI_ATTACK_GROUND" // AI_ATTACK_ALL	AI_ATTACK_GROUND	AI_ATTACK_AIR

	"SoundSet"					"CastleFightCreep"							// Name of sound set.
	
	"ProjectileModel"			"particles/units/heroes/hero_techies/techies_base_attack.vpcf"
	"ProjectileSpeed" 			"900"
	"AttackAnimationPoint"		"0.5"		// Normalized time in animation cycle to attack.

	"BaseClass"					"npc_dota_creature"	// Class of entity of link to.
	"Level"						"1"
	"AttackAcquisitionRange"	"1200"		// Range within a target can be acquired.

	"Ability1"					"cf_01_ab_cr03_01"			// Ability 1.
	"Ability2"					""			// Ability 2.
	"Ability3"					""			// Ability 3.
	"Ability4"					""			// Ability 4.

	"BountyGoldMin"				"7"		// Gold earned min.
	"BountyGoldMax"				"7"		// Gold earned max.

	// Bounds
	//----------------------------------------------------------------
	"BoundsHullName"			"DOTA_HULL_SIZE_SMALL"			// Hull type used for navigation/locomotion.
	"RingRadius"				"45"
	"HealthBarOffset"			"150"

	// Movement
	//----------------------------------------------------------------
	"MovementCapabilities"		"DOTA_UNIT_CAP_MOVE_GROUND"	 // DOTA_UNIT_CAP_MOVE_NONE DOTA_UNIT_CAP_MOVE_GROUND DOTA_UNIT_CAP_MOVE_FLY
	"MovementSpeed"				"215"		// Speed
	"MovementTurnRate"			"0.5"		// Turning rate.

	// Status
	//----------------------------------------------------------------
	"StatusHealth"				"280"		// Base health.
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
        "AttachWearables" // Default npc_dota_hero_techies
        {
            "1" { "ItemDef" "491" } // Techies Squee Costume
            "2" { "ItemDef" "490" } // Techies Cart
            "3" { "ItemDef" "492" } // Techies Spleen Costume
            "4" { "ItemDef" "394" } // Techies Bomb Arsenal
            "5" { "ItemDef" "487" } // Techies Spoon Costume
            "6" { "ItemDef" "489" } // Techies Slingshot
            // "7" { "ItemDef" "499" } // Techies Sign
        }
	}
}