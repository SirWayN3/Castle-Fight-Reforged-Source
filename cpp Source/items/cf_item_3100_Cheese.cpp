"item_custom_cheese"
{
	/*
		[self]
		target=Item_Names
		type=item
		name=Cheese
		descr=Gives one Essence to spent.
	*/
	"BaseClass"             		"item_datadriven"
	"ID" 							"3100"

	"AbilityTextureName"			"item_cheese"
	"AbilityBehavior"				" DOTA_ABILITY_BEHAVIOR_NO_TARGET "
	// "AbilityCastPoint"				"0"

	"ItemDroppable" 				"0"
	"ItemPurchasable" 				"1"
	"ItemSellable"					"0"
	"ItemShareability"      		"ITEM_NOT_SHAREABLE"
	"ItemInitialCharges" 			"1"
	"ItemStackable" 				"1"
	"ItemPermanent"         		"0"
	"ItemQuality" 					"epic"
	"ItemType"						"consumable"		// CF Item Type, used for Shop Sorting
	
	"ItemStockMax"					"2"
	"ItemStockTime"					"500"
	"ItemInitialStockTime"			"1000"
	"ItemStockInitial"				"0"
	"ItemCastOnPickup" 				"0" //-> Auto Cast Function

	// Item Info
	//-------------------------------------------------------------------------------------------------------------
	"ItemCost"						"1500"
	
	// Custom Info
	//-------------------------------------------------------------------------------------------------------------
	"Shop"							"1"
	// "EnergyCost"					"300"
	"UseInventory"					"1"
	
	"AbilitySpecial"
	{
		"01"
		{
			"var_type"      		"FIELD_INTEGER"
			"essence_amount"    	"1"
		}
	}

	"OnEquip"
	{
		"RunScript"
		{
			"ScriptFile"			"items/cf_items_common.lua"
			"Function"				"cf_item_cheese"
			"EventName" 			"OnSpellStart"
			"essence"				"%essence_amount"
		}
		"SpendCharge"				{}
	}
}



