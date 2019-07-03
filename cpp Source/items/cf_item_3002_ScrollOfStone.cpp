"item_custom_scroll_of_stone"
{
	/*
		[self]
		target=Item_Names
		type=item
		name=Scroll of Stone
		descr=Gives Armor Buff to all Allied Units in Radius.
	*/
	"BaseClass"             		"item_datadriven"
	"ID" 							"3002"

	"AbilityTextureName"			"item_tpscroll"
	"AbilityBehavior"				"DOTA_ABILITY_BEHAVIOR_POINT | DOTA_ABILITY_BEHAVIOR_AOE "
	// "AbilityCastPoint"				"0"

	"AbilityCastRange"				"99999"
	"AOERadius" 					"1000"

	"ItemDroppable" 				"0"
	"ItemPurchasable" 				"1"
	"ItemSellable"					"0"
	"ItemShareability"      		"ITEM_NOT_SHAREABLE"
	"ItemPermanent"         		"0"
	"ItemQuality" 					"consumable"
	"ItemType"						"offensive"		// CF Item Type, used for Shop Sorting
	
	"ItemStockMax"					"2"
	"ItemStockTime"					"120"
	"ItemInitialStockTime"			"360"
	"ItemStockInitial"				"2"

	"ItemStackable" 				"1"
	"ItemInitialCharges"			"1"
	"precache"
	{
		"particle"	"particles/units/heroes/hero_dazzle/dazzle_armor_friend.vpcf"
	}
	// Item Info
	//-------------------------------------------------------------------------------------------------------------
	"ItemCost"						"150"
	
	// Custom Info
	//-------------------------------------------------------------------------------------------------------------
	"Shop"							"1"
	// "EnergyCost"					"300"
	"UseInventory"					"1"
	
	"AbilitySpecial"
	{
		"01"
		{
			"var_type"				"FIELD_INTEGER"
			"radius"				"1000"
		}
		"02"
		{
			"var_type"				"FIELD_INTEGER"
			"heal"					"400"
		}
		"03"
		{
			"var_type"				"FIELD_INTEGER"
			"armor"					"8"
		}
		"04"
		{
			"var_type"				"FIELD_INTEGER"
			"duration"				"30"
		}
		"05"
		{
			"var_type"				"FIELD_INTEGER"
			"mana"					"200"
		}
	}
	"OnSpellStart"
	{
		"SpendCharge"
		{}
		"ApplyModifier"
		{
			"ModifierName"			"modifier_scroll_of_stone_bonus_armor"
			"Target"
			{
				"Center"			"POINT"
				"Radius"			"%radius"
				"Teams"				"DOTA_UNIT_TARGET_TEAM_FRIENDLY"
				"Types"				"DOTA_UNIT_TARGET_CREEP"
			}
		}
		"ApplyModifier"
		{
			"ModifierName"			"modifier_scroll_of_stone_bonus_mana"
			"Target"
			{
				"Center"			"POINT"
				"Radius"			"%radius"
				"Teams"				"DOTA_UNIT_TARGET_TEAM_FRIENDLY"
				"Types"				"DOTA_UNIT_TARGET_CREEP"
			}
		}
		"Heal"
		{
			"HealAmount"			"%heal"
			"Target"
			{
				"Center"			"POINT"
				"Radius"			"%radius"
				"Teams"				"DOTA_UNIT_TARGET_TEAM_FRIENDLY"
				"Types"				"DOTA_UNIT_TARGET_CREEP"
			}
		}
	}

	"Modifiers"
	{
		"modifier_scroll_of_stone_bonus_armor"
		{
			"Duration"					"%duration"
			"Passive" 					"0"
			"IsHidden" 					"1"
			"EffectName"				"particles/units/heroes/hero_dazzle/dazzle_armor_friend.vpcf"
			"EffectAttachType"      	"follow_overhead"
			"Properties"
			{
				"MODIFIER_PROPERTY_PHYSICAL_ARMOR_BONUS"		"%armor"
			}
		}
		
		"modifier_scroll_of_stone_bonus_mana"
		{
			"Duration"		"1"
			"Passive" 		"0"
			"IsHidden" 		"1"
			"Properties"
			{
				"MODIFIER_PROPERTY_MANA_REGEN_CONSTANT"			"%mana"
			}
		}
	}
}



