'use strict';

var frame_rate = 1/25
var step_val = 0.4;
var flow_active = false;



function cf_panel_income( data )
{
	// $.Msg("cf_resources.js","cf_panel_income ", data)
	// Start Flow of Progress Bar
	if (flow_active === false) { 
		flow_active = true;
		cf_panel_income_flow();
	}
	$("#cf_income_bar").value = 0;

}

function cf_panel_income_flow() {
	$("#cf_income_bar").value = $("#cf_income_bar").value + step_val;
	$.Schedule(frame_rate, cf_panel_income_flow);
}

// function cf_resources_update( table, key, data )
function cf_resources_update( kv )
{
	// $.Msg( "cf_reources_update: ",kv)

	$( "#cf_gold").text = kv.resources.gold;
	$( "#cf_essence").text = kv.resources.essence;
	$( "#cf_income").text = kv.resources.income_100 / 100;
	$( "#cf_energy").text = kv.resources.energy;
	
}

(function()
{ 
	GameEvents.Subscribe("cf_income", cf_panel_income)
	GameEvents.Subscribe("cf_resources_update", cf_resources_update);
  
})();
// CustomNetTables.SubscribeNetTableListener( "castlefightreforged", cf_resources_update );
