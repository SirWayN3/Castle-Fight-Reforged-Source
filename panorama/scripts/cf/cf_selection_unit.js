
var cf_selected_entity = null

var Dbg = false

function cf_OnUpdateSelectedUnit()
{
	// Fires Only when selecting controllable units
	// DbgW("");
	// DbgW("cf_selection_unit.js: Unit has been selected");
	var ent = cf_GetSelectedEntities()
	// Function can get multiple selected Units. Always use 0-Index, this is the one currently on Focus. Skips with tabbing through
	ent = ent[0]
	// $.Msg(ent)
	if (( ent === -1 ) || (typeof ent === 'undefined')) { return }
	// if (! Entities.IsValidEntity(ent) ) { return };


	// var name = Entities.GetUnitLabel(Number(ent))
	// DbgW( ent ,name)
	// Query Doesnt work
	// var ent = cf_GetQueryEntities()
	// var name = Entities.GetUnitLabel(Number(ent))
	// DbgW( ent ,name)
	cf_PanelUpdateUnitInformation( {ent : ent })
}
function cf_OnUpdateQueryUnit()
{
	// Fires Only when selecting Non-Controllable Units
	// DbgW("");
	// DbgW("cf_OnUpdateQueryUnit.js: Unit has been selected");
	// Selection doesnt work
	// var ent = cf_GetSelectedEntities()
	// var name = Entities.GetUnitLabel(Number(ent))
	// DbgW( ent ,name)
	var ent = cf_GetQueryEntities()
	if (( ent === -1 ) || (typeof ent === 'undefined')) { return }
	// if (! Entities.IsValidEntity(ent) ) { return };
	// var name = Entities.GetUnitLabel(Number(ent))
	// DbgW( ent ,name)
	cf_PanelUpdateUnitInformation( {ent : ent })

}


function cf_PanelUpdateUnitInformation( data ) {
	// DbgW("")
	DbgW( "","cf_PanelUpdateUnitInformation",data)

	if ( data.ent !== cf_selected_entity ) {
		cf_selected_entity = data.ent
		DbgW("")
		DbgW("cf_PanelUpdateUnitInformation ","Update Panel Information. New Entity: ",cf_selected_entity)

		// Update from Unit Information here.
		/*

				Entities.HasAttackCapability( integer nEntityIndex )
			Entities.HasCastableAbilities( integer nEntityIndex )
				Entities.HasMovementCapability( integer nEntityIndex )
			Entities.IsAlive( integer nEntityIndex )
			Entities.IsEnemy( integer nEntityIndex )
			Entities.IsFrozen( integer nEntityIndex )
			Entities.IsDisarmed( integer nEntityIndex )
			Entities.IsIllusion( integer nEntityIndex ) -> Does this exist?
			Entities.IsInvisible( integer nEntityIndex )
				Entities.IsInvulnerable( integer nEntityIndex ) -> Hide Health Bar? or Hide for Builder only?
			Entities.IsMagicImmune( integer nEntityIndex )
			Entities.IsSilenced( integer nEntityIndex )

			Entities.IsStunned( integer nEntityIndex )

				Entities.GetDamageMin( integer nEntityIndex )
				Entities.GetDamageMax( integer nEntityIndex )
				Entities.GetDamageBonus( integer nEntityIndex )

			Entities.GetHealth( integer nEntityIndex )
			Entities.GetHealthThinkRegen( integer nEntityIndex )
			Entities.GetMaxHealth( integer nEntityIndex )

			Entities.GetMana( integer nEntityIndex )
			Entities.GetManaThinkRegen( integer nEntityIndex )
			Entities.GetMaxMana( integer nEntityIndex )

			Entities.GetAttackRange( integer nEntityIndex )
			Entities.GetAttackSpeed( integer nEntityIndex )
			Entities.GetIncreasedAttackSpeed( integer nEntityIndex )
				Entities.GetAttacksPerSecond( integer nEntityIndex )
			Entities.GetSecondsPerAttack( integer nEntityIndex )
			Entities.GetBaseAttackTime( integer nEntityIndex )

				Entities.GetBaseMoveSpeed( integer nEntityIndex )
				Entities.GetMoveSpeedModifier( integer nEntityIndex, float flBaseSpeed )

				Entities.GetPhysicalArmorValue( integer nEntityIndex )
				Entities.GetBonusPhysicalArmor( integer nEntityIndex )

			Entities.GetClassname( integer nEntityIndex ) -> Useful to gather Information from CustomNetTables?
			Entities.GetUnitLabel( integer nEntityIndex ) -> Useful to gather Information from CustomNetTables?
			Entities.GetUnitName( integer nEntityIndex )  -> Useful to gather Information from CustomNetTables?
			

		*/
		var panel, text, sub;
		data.ClassName = Entities.GetClassname( data.ent );
		data.UnitName = Entities.GetUnitName( data.ent );
		data.UnitLabel = Entities.GetUnitLabel( data.ent );
		data.OwnerID = Entities.GetPlayerOwnerID( data.ent );
		if ( data.OwnerID != -1) {
			data.OwnerName = Players.GetPlayerName(data.OwnerID) ;
			data.HasOwner = true;
		} else {
			data.OwnerName = "";
			data.HasOwner = false;
		}
		
		var info = CustomNetTables.GetTableValue("cf_unit_kv", data.ClassName );
		if ( info === undefined ) {
			DbgW( "Entry Not Found checking UnitName");
			info = CustomNetTables.GetTableValue("cf_unit_kv",data.UnitName );
			if ( info === undefined ) {
				DbgW("Entry still not found. Returning");
				DbgW(data);
				return;
			}
		}
		// DbgW("CustomNetTable Info: ",info)
		data.HasInvulnerable = Entities.IsInvulnerable( data.ent )
		data.AttackType = info.cf_attacktype || -1;
		// data.HasAttack = Entities.HasAttackCapability( data.ent );
		data.HasAttack = info.AttackCapabilities != 0; // DOTA_UNIT_CAP_NO_ATTACK
		data.AttackSpeed = Entities.GetAttacksPerSecond( data.ent )

		data.DefenseType = info.cf_defensetype || -1;
		data.HasDefense = true;
		if ( data.HasInvulnerable) { data.HasDefense = false };
		data.PhysicalArmor = Entities.GetPhysicalArmorValue( data.ent );
		// data.PhysicalArmor = info.cf_armor_physical;
		data.PhysicalArmorBonus = Entities.GetBonusPhysicalArmor( data.ent );

		data.DmgMin = Entities.GetDamageMin( data.ent );
		data.DmgMax = Entities.GetDamageMax( data.ent );
		data.DmgBonus = Entities.GetDamageBonus( data.ent );
		// data.Model = info.Model;
		data.HasMovement = Entities.HasMovementCapability( data.ent );
		data.MoveSpeed = Entities.GetBaseMoveSpeed( data.ent );
		data.MoveSpeedBonus = Entities.GetMoveSpeedModifier( data.ent , data.MoveSpeed);

		data.Ability = {};
		data.Ability[1] = info.Ability1;
		DbgW(data)

		// Fill Panels with Information

			// Header
			panel = $("#cf_unit_info_header");
			panel.GetChild(0).text = $.Localize("cf_unit_info_header");
			panel.GetChild(1).text = $.Localize(data.UnitName);
			if ( data.HasOwner) {
				text = $.Localize("cf_unit_info_header_owner") + data.OwnerName;
			} else { text = ""}
			panel.GetChild(2).text = text
			panel.GetChild(3).text = $.Localize("cf_unit_info_header_ent") + data.ent;

			// Attack, Damage
			panel = $("#cf_unit_info_attack")
			if (data.HasAttack) {
				panel.RemoveClass("Hidden")
				panel.GetChild(0).text = $.Localize("cf_unit_info_attack")
				panel.GetChild(1).text = $.Localize(data.AttackType);
				text = data.DmgMin + " - " + data.DmgMax;
				if ( data.DmgBonus != 0 ) { text = text + " ( +" + data.DmgBonus + ")" }
				panel.GetChild(2).text = $.Localize("cf_unit_info_damage")+text ;
				panel.GetChild(3).text = $.Localize("cf_unit_info_attackspeed") + data.AttackSpeed;
			} else {
				panel.AddClass("Hidden")
			}

			// Defense, Armor
			panel = $("#cf_unit_info_defense")
			if (data.HasDefense) {
				panel.RemoveClass("Hidden")
				panel.GetChild(0).text = $.Localize("cf_unit_info_defense")
				panel.GetChild(1).text = $.Localize(data.DefenseType);
				text = $.Localize("cf_unit_info_armor") + data.PhysicalArmor;
				if ( data.PhysicalArmorBonus != 0 ) {
					text = text + " ( +" + data.PhysicalArmorBonus + ")";
				}
				panel.GetChild(2).text = text;
			} else {
				panel.AddClass("Hidden")
			}

			// Movement
			panel = $("#cf_unit_info_movement");
			if (data.HasMovement) {
				panel.RemoveClass("Hidden")
				panel.GetChild(0).text = $.Localize("cf_unit_info_movement")
				panel.GetChild(1).text = $.Localize("cf_unit_info_movement_speed") + data.MoveSpeedBonus;
				// panel.GetChild(1).text = data.MoveSpeedBonus;
			} else {
				panel.AddClass("Hidden")
			}

			// Abilities
			/*
			panel = $("#cf_unit_info_abilities");
			sub = panel.GetChild(0).GetChild(0); // Get First Ability Slot
			sub.abilityname = data.Ability[1];
			sub.contextEntityIndex = data.ent;
			*/
			

	}
	else {
		// DbgW("cf_PanelUpdateUnitInformation ","Entity is selected already")
	}
}
// Local player shortcut
function cf_GetSelectedEntities() {
    return Players.GetSelectedEntities(Players.GetLocalPlayer());
}
function cf_GetQueryEntities()
{
    return Players.GetQueryUnit(Players.GetLocalPlayer());
}

(function () {
    // Custom event listeners


    // Built-In Dota client events
    GameEvents.Subscribe("dota_player_update_selected_unit", cf_OnUpdateSelectedUnit);
    GameEvents.Subscribe("dota_player_update_query_unit", cf_OnUpdateQueryUnit);
})();

function DbgW( text ) {
	if ( Dbg ) {
		$.Msg( text );
	};
}