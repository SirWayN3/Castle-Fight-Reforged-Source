"item_custom_rune_of_repair"
{
	/*
		[self]
		target=Item_Names
		type=item
		name=Rune of Repair
		descr=Passivly Repairs Units in Radius.
		[cf_mo_item_runeofrepair_aura]
		target=Item_Names
		type=modifier
		name=Repair Aura Self
	*/
	"BaseClass"             		"item_datadriven"
	"ID" 							"3001"
	"AbilityTextureName"			"item_headdress"
	"AbilityBehavior"				" DOTA_ABILITY_BEHAVIOR_PASSIVE | DOTA_ABILITY_BEHAVIOR_AURA "
	
	"AbilityCastRange"				"1000"

	"ItemDroppable" 				"0"
	"ItemPurchasable" 				"1"
	"ItemSellable"					"0"
	"ItemShareability"      		"ITEM_NOT_SHAREABLE"
	"ItemPermanent"         		"1"
	"ItemQuality" 					"common"
	"ItemType"						"defensive"		// CF Item Type, used for Shop Sorting
	
	"ItemStockMax"					"1"
	"ItemStockTime"					"1000"
	"ItemInitialStockTime"			"360"
	"ItemStockInitial"				"0"

	// Item Info
	//-------------------------------------------------------------------------------------------------------------
	"ItemCost"						"500"
	
	// Custom Info
	//-------------------------------------------------------------------------------------------------------------
	"Shop"							"1"
	"EnergyCost"					"0"
	"UseInventory"					"1"
	
	"AbilitySpecial"
	{
		"01"
		{
			"var_type"			"FIELD_INTEGER"
			"radius"			"1000"
		}
		"02"
		{
			"var_type"			"FIELD_INTEGER"
			"heal"				"5"
		}
		"03"
		{
			"var_type"			"FIELD_INTEGER"
			"interval"			"1"
		}
	}
	"Modifiers"
	{
		"cf_mo_item_runeofrepair_aura"
		{
			"Passive"			"1"
			"IsHidden"			"1"
			"IsPurgable"		"0"
			"IsBuff"			"1"
			"ThinkInterval"		"%interval"
			"Attributes"		"MODIFIER_ATTRIBUTE_MULTIPLE"

			"OnIntervalThink"
			{
				"Heal"
				{
					"HealAmount"		"%heal"
					"Target"
					{
						"Center"		"CASTER"
						"Radius"		"%radius"
						"Teams"			"DOTA_UNIT_TARGET_TEAM_FRIENDLY"
						"Types"			"DOTA_UNIT_TARGET_BUILDING"
						// "MaxTargets"	"10"
						// "Random"		"1" // Whether to select a random unit if more than MaxTargets exist.
					}
				}
			}

		}
	}
}



