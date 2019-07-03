"item_custom_orb_of_lightning"
{
	/*
		[self]
		target=Item_Names
		type=item
		name=Orb of Lightning
		descr=Release a Lightning Bolt, that jumps and deals Damage to Units.
	*/
	"BaseClass"             		"item_datadriven"

	"ID" 							"3007"

	"AbilityTextureName"			"item_refresher"
	
	"AbilityBehavior"				"DOTA_ABILITY_BEHAVIOR_UNIT_TARGET "
	"AbilityUnitTargetType"  		"DOTA_UNIT_TARGET_CREEP"
	"AbilityUnitTargetTeam" 		"DOTA_UNIT_TARGET_TEAM_ENEMY"
	"AbilityCastPoint"				"1"
	"AbilityCooldown"				"5"

	"AbilityUnitDamageType"			"DAMAGE_TYPE_MAGICAL" // Later this will be replaced to SPELL DAMAGE
	"AbilityDamage"					"1000"

	"ItemDroppable" 				"0"
	"ItemPurchasable" 				"1"
	"ItemSellable"					"0"
	"ItemShareability"      		"ITEM_NOT_SHAREABLE"
	"ItemPermanent"         		"1"
	"ItemQuality" 					"rare"
	"ItemType"						"offensive"		// CF Item Type, used for Shop Sorting
	
	"ItemStockMax"					"1"
	"ItemStockTime"					"1000"
	"ItemInitialStockTime"			"600"
	"ItemStockInitial"				"0"

	// Item Info
	//-------------------------------------------------------------------------------------------------------------
	"ItemCost"						"550"
	"precache"
	{
		"particle"		"particles/units/heroes/hero_zuus/zuus_arc_lightning_.vpcf"
		// "particle"		"particles/units/heroes/hero_zuus/zuus_arc_lightning_head.vpcf"
		// "particle"		"particles/units/heroes/hero_zuus/zuus_lightning_bolt_start.vpcf"
		"particle" 		"particles/units/heroes/hero_zuus/zuus_lightning_bolt.vpcf"
		// "soundfile"		"sounds/weapons/hero/zuus/arc_lightning.vsnd"
	}

	// Custom Info
	//-------------------------------------------------------------------------------------------------------------
	"Shop"							"1"
	// "EnergyCost"					"300"
	"UseInventory"					"1"

	"AbilitySpecial"
	{
		"01"
		{
			"var_type"			"FIELD_INTEGER"
			"bridge_count"		"10"
		}
		"02"
		{
			"var_type"			"FIELD_INTEGER"
			"bridge_range"		"500"
		}
		"03"
		{
			"var_type"			"FIELD_FLOAT"
			"bridge_delay"		"0.25"
		}
		"04"
		{
			"var_type"			"FIELD_INTEGER"
			"bridge_reduction_perc"	"15"
		}
	}
	"OnCreated"
	{
		"RunScript"
		{
			"ScriptFile"			"items/cf_items_common.lua"
			"Function"				"cf_item_orb_of_lightning"
			"EventName"				"OnCreated"
		}
	}
	"OnSpellStart"
	{
		"RunScript"
		{
			"ScriptFile"			"items/cf_items_common.lua"
			"Function"				"cf_item_orb_of_lightning"
			"EventName" 			"OnSpellStart"
			"particle_jump" 		"particles/units/heroes/hero_zuus/zuus_arc_lightning_.vpcf"
			"particle"				"particles/units/heroes/hero_zuus/zuus_lightning_bolt.vpcf"
		}
	}
}



