'use strict';



// New Function with modular Button SPawn Event
function cf_ab_setpanorama( kv ) {
	var panel = null;
	// $.Msg("cf_ab_setpanorama: ");
	// return;
	// $.Msg(panel)
	// return
	panel = $("#cf_ability_buttons_container");
	panel.RemoveAndDeleteChildren();
	$.Each(kv.ab, function( k, v) {
		// $.Msg(v);
		var p2 = null;
		// $.Msg("Loop",k);

		p2 = Modular.Spawn( "ability_buttons", panel);
		
		// p2.SetName(k.name );
		p2.SetImage(k.image);
		p2.SetHover(k.name);
		// $.Msg({ builder : kv.builder, ability : k.ent })
		p2.SetButtonFunc({ builder : kv.builder, ability : k.ent });
		p2.SetGoldCost(k.goldcost );
		p2.SetManaCost(k.manacost );
		p2.SetEssCost(k.essencecost );
		
	});
}



(function()
{ 
  GameEvents.Subscribe( "cf_ab_setpanorama", cf_ab_setpanorama );
  
})();