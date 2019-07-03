"cf_builder_dummy"
{
	/*
		[self]
		target=Builder_Names
		type=hero
		name=Dummy
	*/
		// add a dummy Hero for picking. Remove every Entry that could be annyoing during custom pick screen.
		// check addons_game_mode.lua for the corect hero.

		"override_hero"				"npc_dota_hero_jakiro"			// Hero to override		
		"UnitLabel"					"cf_builder_human"
		// CastleFight Special
		"cf_attacktype"				""
		"cf_defensetype"			""
		"cf_armorvalue"				"13.37"


		// General
		//-------------------------------------------------------------------------------------------------------------
		"Model"						"models/heroes/antimage/antimage.mdl"			// Model.
		// "SoundSet"					"Hero_Antimage"							// Name of sound set.
		"Enabled"					"1"
		"Level"						"1"
		"HeroUnlockOrder"			"1"
		"Role"						""
		"Rolelevels"				""
		"Team"						"Good"
		"Portrait"					"vgui/hud/heroportraits/portrait_antimage"
		"ModelScale" 				".1"
		"HeroGlowColor" 			"120 64 148"
		"PickSound"					""
		
		"HeroSelectSoundEffect"		""

		// Abilities
		//-------------------------------------------------------------------------------------------------------------
		"Ability1"		"generic_hidden"
		"Ability2"		"generic_hidden"
		"Ability3"		"generic_hidden"
		"Ability4"		"generic_hidden"
		"Ability5"		"generic_hidden"
		"Ability6"		"generic_hidden"
		"Ability7"		"generic_hidden"
		"Ability8"		"generic_hidden"
		"Ability9"		"generic_hidden"
		"Ability10"		"generic_hidden"
		"Ability11"		"generic_hidden"
		"Ability12"		"generic_hidden"
		"Ability13"		"generic_hidden"
		"Ability14"		"generic_hidden"
		"Ability15"		"generic_hidden"
		"Ability16"		"generic_hidden"
		"Ability17"		"generic_hidden"
		"Ability18"		"generic_hidden"
		"Ability19"		"generic_hidden"
		"Ability20"		"generic_hidden"

		// Armor
		//-------------------------------------------------------------------------------------------------------------
		"ArmorPhysical"				"0"										// Physical protection.

		// Attack
		//-------------------------------------------------------------------------------------------------------------
		"AttackCapabilities"		"DOTA_UNIT_CAP_NO_ATTACK"
		"AttackDamageMin"			"0"									// Damage range min.
		"AttackDamageMax"			"0"									// Damage range max.	
		"AttackRate"				"0"									// Speed of attack.
		"AttackAnimationPoint"		"0"									// Normalized time in animation cycle to attack.
		"AttackAcquisitionRange"	"0"									// Range within a target can be acquired.
		"AttackRange"				"0"									// Range within a target can be attacked.
		"ProjectileModel"			""										// Particle system model for projectile.
		"ProjectileSpeed"			"0"										// Speed of projectile.

		// Attributes
		//-------------------------------------------------------------------------------------------------------------
		"AttributePrimary"			"DOTA_ATTRIBUTE_AGILITY"
		"AttributeBaseStrength"		"0"									// Base strength
		"AttributeStrengthGain"		"0"									// Strength bonus per level.
		"AttributeBaseIntelligence"	"0"									// Base intelligence
		"AttributeIntelligenceGain"	"0"									// Intelligence bonus per level.
		"AttributeBaseAgility"		"0"									// Base agility
		"AttributeAgilityGain"		"0"									// Agility bonus per level.

		// Movement
		//-------------------------------------------------------------------------------------------------------------
		"MovementSpeed"				"0"									// Speed.
		"MovementTurnRate"			"0.5"									// Turning rate.
		"MovementCapabilities"		"DOTA_UNIT_CAP_MOVE_NONE"			// Type of locomotion - ground, air
		
		"BoundsHullName"			"DOTA_HULL_SIZE_HERO"
		"HealthBarOffset"			"140"

		"VoiceFile" 				""
		
		// Status
		//----------------------------------------------------------------
		"StatusHealth"				"1337"		// Base health.
		"StatusHealthRegen"			"200"			// Health regeneration rate.
		"StatusMana"				"0"		// Base mana.
		"StatusManaRegen"			"0"		// Mana regeneration rate.

		

} 