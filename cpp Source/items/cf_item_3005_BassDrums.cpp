"item_custom_bass_drums"
{
	/*
		[self]
		target=Item_Names
		type=item
		name=Bass Drums
		descr=Passively gives Units more Attack Damage
		[cf_mo_item_bassdrum_caster]
		target=Item_Names
		type=modifier
		name=Bass Drums Owner
		[co_mo_item_bassdrum_bonus]
		target=Item_Names
		type=modifier
		name=Bass Drums
		descr=Gives Bonus Damage
	*/
	"BaseClass"             		"item_datadriven"
	"ID" 							"3005"

	"AbilityTextureName"			"item_ancient_janggo"
	"AbilityBehavior"				" DOTA_ABILITY_BEHAVIOR_PASSIVE "
	// "AbilityCastPoint"				"0"

	"ItemDroppable" 				"0"
	"ItemPurchasable" 				"1"
	"ItemSellable"					"0"
	"ItemShareability"      		"ITEM_NOT_SHAREABLE"
	"ItemInitialCharges" 			"0"
	"ItemStackable" 				"0"
	"ItemPermanent"         		"1"
	"ItemQuality" 					"artifact"
	"ItemType"						"offensive"		// CF Item Type, used for Shop Sorting
	
	"ItemStockMax"					"0"
	"ItemStockTime"					"999999"
	"ItemInitialStockTime"			"360"
	"ItemStockInitial"				"1"
	// "ItemCastOnPickup" 				"1" //-> Auto Cast Function

	// Item Info
	//-------------------------------------------------------------------------------------------------------------
	"ItemCost"						"650"
	
	// Custom Info
	//-------------------------------------------------------------------------------------------------------------
	"Shop"							"1"
	// "EnergyCost"					"300"
	// "UseInventory"					"1"
	"AbilitySpecial"
	{
		"01"
		{
			"var_type"			"FIELD_INTEGER"
			"global_radius"		"30000"
		}
	}
	"Modifiers"
	{
		"cf_mo_item_bassdrum_caster"
		{
			"Passive"				"1"
			"IsPurgable"			"0"
			"IsHidden" 				"1"
			"Aura"        			"co_mo_item_bassdrum_bonus"
			"Aura_Radius" 			"%global_radius"
			"Aura_Teams"  			"DOTA_UNIT_TARGET_TEAM_FRIENDLY"
			"Aura_Types"  			"DOTA_UNIT_TARGET_CREEP"
			// "Aura_Types"			"DOTA_UNIT_TARGET_ALL"
			"Aura_ApplyToCaster" 	"0"   // Not Apply to Self, default is 1
		}
		"co_mo_item_bassdrum_bonus"
		{
			// "Passive" 		"1" //Apply as soon as the spell is learned
			"IsHidden"    		"0" //Don't show the aura applier
			"IsBuff" 			"1"
			// "IsPurgable" 	"0"

			"Properties"
			{
				"MODIFIER_PROPERTY_DAMAGEOUTGOING_PERCENTAGE"		"33"
			}

		}
	}
	
}



