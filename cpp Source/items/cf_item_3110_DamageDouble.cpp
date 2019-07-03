"item_custom_damage_double"
{
	/*
		[self]
		target=Item_Names
		type=item
		name=Damage Double
		descr=Gives all Allied Alive Units Double Damage!
	*/
	"BaseClass"             		"item_datadriven"
	"ID" 							"3110"

	"AbilityTextureName"			"item_refresher_shard"
	"AbilityBehavior"				" DOTA_ABILITY_BEHAVIOR_NO_TARGET "
	// "AbilityCastPoint"				"0"

	"ItemDroppable" 				"0"
	"ItemPurchasable" 				"1"
	"ItemSellable"					"0"
	"ItemShareability"      		"ITEM_NOT_SHAREABLE"
	"ItemInitialCharges" 			"1"
	"ItemStackable" 				"1"
	"ItemPermanent"         		"0"
	"ItemQuality" 					"rare"
	"ItemType"						"offensive"		// CF Item Type, used for Shop Sorting
	
	"ItemStockMax"					"1"
	"ItemStockTime"					"500"
	"ItemInitialStockTime"			"1000"
	"ItemStockInitial"				"0"
	// Doesnt work with Custom Shop, check with OnEquipped or something
	"ItemCastOnPickup" 				"0" //-> Auto Cast Function

	// Item Info
	//-------------------------------------------------------------------------------------------------------------
	"ItemCost"						"600"
	
	// Custom Info
	//-------------------------------------------------------------------------------------------------------------
	"Shop"							"1"
	// "EnergyCost"					"300"
	"UseInventory"					"1"
	
	"OnEquip"
	{
		"RunScript"
		{
			"ScriptFile"			"items/cf_items_common.lua"
			"Function"				"cf_item_damage"
			"EventName" 			"DamageDouble"
		}
		"SpendCharge"				{}
	}
}



