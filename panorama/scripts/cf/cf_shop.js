'use strict';


// $.Msg(ShopItem)
var ShopItem = {};

// $.Msg("cf_shop.js loaded");

function cf_shop_setpanorama( kv )
{
	var panel = null;
	// Debug
	// $.Msg("cf_shop_setpanorama")
	// $.Msg(kv)
	// cf_shop_toggle()
	// Debug

	// Get Panels Sorting
	var t = {};
	t[1] = "offensive";
	t[2] = "defensive";
	t[3] = "consumable";
	// $.Msg(t)
	$.Each(t, function( o, p) {
		// $.Msg(o)
		panel = $("#cf_shop_container_" + o );
		panel.RemoveAndDeleteChildren();
		// Fill Panels with Items. Check for Item Type
		$.Each(kv, function( k, v) {
			// $.Msg( v ,k,k.ItemType,o);
			if ( k.ItemType == o) {
				ShopItem[v] = Modular.Spawn( "shop_items", panel);
				
				ShopItem[v].SetItemName(v);
				ShopItem[v].SetButtonFunc(v);
				ShopItem[v].SetGoldCost(k.GoldCost);
				// ItemQuality
				// ItemType
			};
		});
	});


	
}


function cf_shop_toggle( )
{
	var panel = $("#cf_shop")
	// $.Msg("cf_shop_toggle")
	// $.Msg(panel.BHasClass("Hidden"))
	panel.ToggleClass("Hidden")
	if ( panel.BHasClass("Hidden")) {
		$("#cf_shop_button_label").text = $.Localize("cf_shop_button_label_show");
	} else {
		$("#cf_shop_button_label").text = $.Localize("cf_shop_button_label_hide");
	}
}

  
(function()
{ 
	// After Recompile doesnt work anymore.
	Game.AddCommand("cf_shop_toggle", cf_shop_toggle, "", 0);
	Game.CreateCustomKeyBind("b","cf_shop_toggle");
	
	GameEvents.Subscribe("cf_shop_setpanorama",cf_shop_setpanorama);
  
})();
