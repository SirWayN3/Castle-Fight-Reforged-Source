


 $("#AddonMode").text = $.Localize("addon_pregame_Mode_Classic");
 $("#AddonIsHost").text = $.Localize("addon_pregame_IsNotHost")
 // $("#AddonMode").onmouseover = $.Localize("addon_pregame_Mode_Classic_Hover");
var isHost = false;
function cf_setplayerhost( kv ) {
	// $.Msg("cf_setplayerhost")
	if ( kv.isHost == true ) {
		$("#AddonIsHost").text = $.Localize("addon_pregame_IsHost");
		
	}

}

GameEvents.Subscribe("cf_player_SetHost", cf_setplayerhost);
