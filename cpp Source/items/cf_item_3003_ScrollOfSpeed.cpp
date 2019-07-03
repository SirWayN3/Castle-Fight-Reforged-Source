"item_custom_scroll_of_speed"
{
	/*
		[self]
		target=Item_Names
		type=item
		name=Scroll of Speed
		descr=Passively gives Units more Move Speed
		lore=Suggested by: OvM
	*/
	"BaseClass"             		"item_datadriven"
	"ID" 							"3003"

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
		"particle"	"particles/units/heroes/hero_lone_druid/lone_druid_rabid_buff_speed.vpcf"
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
			"duration"				"30"
		}
		"03"
		{
			"var_type"				"FIELD_INTEGER"
			"speed"					"50"
		}
	}
	"OnSpellStart"
	{
		"SpendCharge"
		{}
		"ApplyModifier"
		{
			"ModifierName"			"modifier_scroll_of_speed_bonus_speed"
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
		"modifier_scroll_of_speed_bonus_speed"
		{
			"Duration"					"%duration"
			"Passive" 					"0"
			"IsHidden" 					"1"
			"EffectName"				"particles/units/heroes/hero_lone_druid/lone_druid_rabid_buff_speed.vpcf"
			"EffectAttachType"      	"follow_overhead"
			"Properties"
			{
				"MODIFIER_PROPERTY_MOVESPEED_BONUS_CONSTANT"		"%speed"
			}
		}
		
	}
}



