"item_custom_restoration_stone"
{
	/*
		[self]
		target=Item_Names
		type=item
		name=Restoration Stone
		descr=Gives one more Charge for Rescue Strike.
		lore=Suggested by: Napoqe
	*/
	"BaseClass"             		"item_datadriven"
	"ID" 							"3120"
	
	"AbilityTextureName"			"item_ultimate_orb"
	"AbilityBehavior"				" DOTA_ABILITY_BEHAVIOR_NO_TARGET "
	// "AbilityCastPoint"				"0"

	"ItemDroppable" 				"0"
	"ItemPurchasable" 				"1"
	"ItemSellable"					"0"
	"ItemShareability"      		"ITEM_NOT_SHAREABLE"
	"ItemInitialCharges" 			"1"
	"ItemStackable" 				"1"
	"ItemPermanent"         		"0"
	"ItemQuality" 					"artifact"
	"ItemType"						"consumable"		// CF Item Type, used for Shop Sorting
	
	"ItemStockMax"					"1"
	"ItemStockTime"					"1000"
	"ItemInitialStockTime"			"1000"
	"ItemStockInitial"				"0"
	"ItemCastOnPickup" 				"0" //-> Auto Cast Function

	// Item Info
	//-------------------------------------------------------------------------------------------------------------
	"ItemCost"						"2500"
	
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
			"Function"				"cf_item_restorationstone"
			"mo_name"				"cf_mo_rescuestrike"
			"charges"				"1"
		}
		"SpendCharge"				{}
	}
}



