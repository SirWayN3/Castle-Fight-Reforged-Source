"item_custom_blast_staff"
{
	/*
		[self]
		target=Item_Names
		type=item
		name=Blast Staff
		descr=Damages Random Unit every Second.
		[cf_mo_item_blast_staff_data]
		target=Item_Names
		type=modifier
		name=Blast Staff
		descr=Pew Pew
	*/
	"BaseClass"             		"item_datadriven"
	// "BaseClass"             		"item_lua"
	"ID" 							"3000"
	
	"AbilityTextureName"			"item_force_staff"
	"AbilityBehavior"				" DOTA_ABILITY_BEHAVIOR_PASSIVE "
	// "AbilityCastPoint"				"0"

	"ItemDroppable" 				"0"
	"ItemPurchasable" 				"1"
	"ItemSellable"					"0"
	"ItemShareability"      		"ITEM_NOT_SHAREABLE"
	"ItemPermanent"         		"1"
	"ItemQuality" 					"common"
	"ItemType"						"Consumable"		// CF Item Type, used for Shop Sorting
	"ItemType"						"defensive"		// CF Item Type, used for Shop Sorting
	
	"ItemStockMax"					"1"
	"ItemStockTime"					"360"
	"ItemInitialStockTime"			"360"
	"ItemStockInitial"				"1"
	// "ItemCastOnPickup" 				"1" -> Auto Cast Function

	// Item Info
	//-------------------------------------------------------------------------------------------------------------
	"ItemCost"						"150"
	
	// Custom Info
	//-------------------------------------------------------------------------------------------------------------
	"Shop"							"1"
	// "EnergyCost"					"300"
	// "UseInventory"					"1"
	
	"AbilitySpecial"
	{
		"01"
		{
			"var_type"      "FIELD_INTEGER"
			"damage"    	"60"
		}
		"02"
		{
			"var_type"		"FIELD_INTEGER"
			"radius"		"1000"
		}
		"03"
		{
			"var_type"		"FIELD_INTEGER"
			"movespeed"		"1200"
		}
	}

	"OnProjectileHitUnit"
	{
		"Damage"
		{
			"Target"				"TARGET"
			"Type"					"DAMAGE_TYPE_MAGICAL"// Later this will be replaced to SPELL DAMAGE
			"Damage"				"%damage"
		}
	}
	"Modifiers"
	{
		"cf_mo_item_blast_staff_data"
		{
			"Passive"				"1"
			"IsHidden"				"1"
			"Attributes"			"MODIFIER_ATTRIBUTE_MULTIPLE"
			"ThinkInterval"			"1"
			"OnIntervalThink"
			{
				"TrackingProjectile"
				{
					"Target"
					{
						"Center"		"CASTER"
						"Radius"		"%radius"
						"Teams"			"DOTA_UNIT_TARGET_TEAM_ENEMY"
						"Types"			"DOTA_UNIT_TARGET_CREEP"
						"Flags"			"DOTA_UNIT_TARGET_FLAG_NONE"
						"Random"		"TRUE"
					}
					"EffectName"		"particles/units/heroes/hero_crystalmaiden/maiden_base_attack.vpcf"
					"Dodgeable"			"FALSE"
					"ProvidesVision"	"FALSE"
					"Movespeed"			"%movespeed"
				}
			}
		}
	}
}



