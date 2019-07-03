
var panel = null;
var items = {};
var clock = $("#cf_topbar_clock");

$.Msg("Compiled cf_topbar.js");

function topbar_clock()
{
	// $.Msg(Game.GetDOTATime(false,false));
	$.Schedule(1,topbar_clock);
	var s = Math.round(Game.GetDOTATime(false,true));
	clock.text = convert_to_time(s);
	// $.Msg(clock.text," ",s)
}

function topbar_create(  )
{
	var t = CustomNetTables.GetAllTableValues("cf_topbar")
	// $.Msg("topbar_create")
	// $.Msg(t)

	// return;

	// var item = null;
	var panel = null;
	$("#cf_topbar_left").RemoveAndDeleteChildren();

	$("#cf_topbar_right").RemoveAndDeleteChildren();
	// $.Msg(panel);

	$.Each(t, function( k, v) {
		var pID = k.key;
		var pID = parseInt(pID.substr(pID.length - 1), 10); // => "1"
		var team = Players.GetTeam( pID );
		if (team === DOTATeam_t.DOTA_TEAM_GOODGUYS) {
			panel = $("#cf_topbar_left");
		}
		if (team === DOTATeam_t.DOTA_TEAM_BADGUYS) {
			panel = $("#cf_topbar_right");
		}
		// $.Msg(k, " ", pID," ",team);
		items[k.key] = Modular.Spawn( "topbar_avatar", panel);
		items[k.key].SetSteamID( k.value.steamID)
		items[k.key].SetBuilder( k.value.builderName);
		items[k.key].SetCState( k.value.CState);

  	});
	// return;
	// $.Msg(items)
}

function convert_to_time( text ){
	var IsNeg = false;
	if (text < 0 ) {
		IsNeg = true;
		text = text * -1
	} 
    var sec_num = parseInt(text, 10); // don't forget the second param
    var hours   = Math.floor(sec_num / 3600);
    var minutes = Math.floor((sec_num - (hours * 3600)) / 60);
    var seconds = sec_num - (hours * 3600) - (minutes * 60);

    if (hours   < 10) {hours   = "0"+hours;}
    if (minutes < 10) {minutes = "0"+minutes;}
    if (seconds < 10) {seconds = "0"+seconds;}
    text = "";
    if (IsNeg) {
    	text = "-";
    }
    text = text + hours+':'+minutes+':'+seconds;
    return text;
}
// topbar_create()
(function()
{ 

	

	CustomNetTables.SubscribeNetTableListener( "cf_topbar", topbar_create )

	topbar_create( );
	$.Schedule(1, topbar_clock);
})();
