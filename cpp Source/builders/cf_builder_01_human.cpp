"npc_dota_hero_kunkka"
{
	/*
		[self]
		target=Builder_Names
		type=hero
		name=Builder Human
	*/					
	"override_hero"				"npc_dota_hero_kunkka"			// Hero to override		
	
	"UnitLabel"					"builder"
	"cf_builder_id"				"1"
	"cf_builder_ready"			"1"		// 1 for Ready, 2 for only in Tools Mode
	// CastleFight Special
	"cf_attacktype"				""
	"cf_defensetype"			""
	"cf_armorvalue"				"13.37"
	"RepairAbility"				"cf_00_ab_builder_repair"

	// General
	//-------------------------------------------------------------------------------------------------------------
	"ModelScale" 				"0.8"
	// "Model"						"" // Use the normal model provided by override_hero

	// "SoundSet"					"CastleFightBuilder"							// Name of sound set.
	// "IdleSoundLoop"				""
	// "GameSoundsFile"			""
	// "HeroSelectSoundEffect"		""
	// "VoiceFile"					""
	// "PickSound"					""

	"Enabled"					"1"
	"Level"						"1"

	// "Portrait"					"vgui/hud/heroportraits/portrait_antimage"
	"ModelScale" 				".90"
	"HeroGlowColor" 			"120 64 148"

	// Abilities
	//-------------------------------------------------------------------------------------------------------------
	"Ability1"		"cf_00_ab_builder_blink"
	"Ability2"		"cf_00_ab_builder_rescuestrike"
	"Ability3"		"cf_00_ab_builder_repair"
	"Ability4"		""
	"Ability5"		""
	"Ability6"		""
	"Ability7"		""
	"Ability8"		""
	"Ability9"		""
	// Let Build Abilities start after normal ones. The Abilities must be hidden.
	"Ability10"		"cf_01_ab_builder_bu01"
	"Ability11"		"cf_01_ab_builder_bu02"
	"Ability12"		"cf_01_ab_builder_bu03"
	"Ability13"		"cf_01_ab_builder_bu04"
	"Ability14"		"cf_01_ab_builder_bu05"
	"Ability15"		"cf_01_ab_builder_bu06"
	"Ability16"		"cf_01_ab_builder_bu07"
	"Ability17"		"cf_01_ab_builder_bu08"
	"Ability18"		"cf_01_ab_builder_bu09"
	"Ability19"		"cf_01_ab_builder_bu10"

	"Ability20"		"cf_00_ab_builder_treasurechest"


	"AbilityTalentStart" "21"				// When Talent tree abilties starts
	"Ability21"		"generic_hidden"
	"Ability22"		"generic_hidden"
	"Ability23"		"generic_hidden"
	"Ability24"		"generic_hidden"
	"Ability25"		"generic_hidden"
	"Ability26"		"generic_hidden"
	"Ability27"		"generic_hidden"
	"Ability28"		"generic_hidden"
	"Ability29"		"generic_hidden"


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
	"MovementSpeed"				"300"									// Speed.
	"MovementSpeed"				"1500"									// Speed.
	"MovementTurnRate"			"0.5"									// Turning rate.
	
	"BoundsHullName"			"DOTA_HULL_SIZE_HERO"
	"HealthBarOffset"			"140"

	
	// Status
	//----------------------------------------------------------------
	"StatusHealth"				"1337"		// Base health.
	"StatusHealthRegen"			"200"		// Health regeneration rate.
	"StatusMana"				"0"		// Base mana.
	"StatusManaRegen"			"0"			// Mana regeneration rate.
	"StatusStartingMana" 		"0" 		// -1 means default to full mana

	// Additional data needed to render the out of game portrait
	// "RenderablePortrait"
	// {
	// 	"Particles"
	// 	{
	// 		"antimage_loadout"
	// 		{
	// 			"0"
	// 			{
	// 				"type"		"follow_origin"
	// 				"location"	"attach_hitloc"
	// 			}
	// 		}	
	// 	}
	// }
	

} 