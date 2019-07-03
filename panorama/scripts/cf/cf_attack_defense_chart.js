
// if (attack_defense_data == null ) { 
// 	var attack_defense_data = {} 
// }

function cf_attack_defense_show_hide() {
	// $.Msg("ShoowHide")
	var panel = $("#cf_group_attack_defense_chart");

	// panel.SwitchClass( "Hidden", "");
	// panel.RemoveClass("Maximized")
	// panel.AddClass("Minimized")
	panel.ToggleClass("Hidden")
	if ( panel.BHasClass("Hidden") ) {
	// $.Msg("ShoowHide")
		$("#cf_btn_show_hide").GetChild(0).text = $.Localize("cf_btn_show_hide__show");
	}
	else
	{
		$("#cf_btn_show_hide").GetChild(0).text = $.Localize("cf_btn_show_hide__hide");
	}
	
}



function cf_attack_defense_table( ) {
	// $.Msg()

	var data = CustomNetTables.GetTableValue("cf_attack_defense","attack_defense_t")

	var n = 0;
	var z = 0;
	var panel = null;

	// Fill Table Header with Localized Strings
	panel = $("#cf_defense_header");
	for (var i in data) {
		for (var j in data[i]) {
			n++;
			// $.Msg(j)
			panel.GetChild(n).text = $.Localize(j);
		}
		break; // do only once
	}

	// Fill Table Lines with Values
	z = 0;
	n = 0;
	for (var i in data) {
		z ++;
		n = 0;

		panel = $("#"+i);
		panel.GetChild(n).text = $.Localize(i);
		// panel.GetChild(n).text = $.Localize(i).replace(" ","<br>");

		for (var j in data[i] ) {
			n ++;
			// Create Table with these Values
			// $.Msg( i," vs ",j," ",data[i][j])
			panel = $("#"+i);
			// $.Msg(panel)
			// if (panel !== null) {
				panel.GetChild(n).text = data[i][j]+"%";
			// };
		}
	}
	
}


(function()
{ 
	// GameEvents.Subscribe( "cf_attack_defense_table", cf_attack_defense_table );

	CustomNetTables.SubscribeNetTableListener( "cf_attack_defense", cf_attack_defense_table )
  	cf_attack_defense_table()
})();
