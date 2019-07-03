"cf_01_ab_bu10_01"
{
	/*
		[self]
		target=Ability_Names_Humans
		type=ability
		name=Call to Arms
		descr=Units are getting Duplicated by Chance when spawned by the Buildings.
		[cf_mo_bu_heroicshrine_caster]
		target=Ability_Names_Humans
		type=modifier
		name=Call to Arms - Caster
		[cf_mo_bu_heroicshrine_bonus]
		target=Ability_Names_Humans
		type=modifier
		name=Call to Arms
		descr=Chance to create a double spawn.
	*/
	// Heroic Shrine Double Unit Spawn
	"BaseClass"                     "ability_datadriven"
	"AbilityBehavior"				"DOTA_ABILITY_BEHAVIOR_PASSIVE | DOTA_ABILITY_BEHAVIOR_AURA "
	"AbilityUnitTargetTeam"			"DOTA_UNIT_TARGET_TEAM_FRIENDLY"
	"AbilityUnitTargetType"			"DOTA_UNIT_TARGET_ALL"
	"AbilityTextureName" 			"dark_seer_wall_of_replica"
	// "AbilityCastRange"				"1500"

	"Level"							"0"
	"MaxLevel"                      "1"
	// Special	
	//-------------------------------------------------------------------------------------------------------------
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
		"cf_mo_bu_heroicshrine_caster"
		{
			"Passive"				"1"
			"IsPurgable"			"0"
			"IsHidden" 				"1"
			"Aura"        			"cf_mo_bu_heroicshrine_bonus"
			"Aura_Radius" 			"%global_radius"
			"Aura_Teams"  			"DOTA_UNIT_TARGET_TEAM_FRIENDLY"
			"Aura_Types"  			"DOTA_UNIT_TARGET_BUILDING"
			// "Aura_Types"			"DOTA_UNIT_TARGET_ALL"
			"Aura_ApplyToCaster" "0"   // Not Apply to Self, default is 1
		}
		// Check Settings for the same name on CF_HEROIC_SHRINE_MODIFIER_NAME
		"cf_mo_bu_heroicshrine_bonus"
		{
			// "Passive" 		"1" //Apply as soon as the spell is learned
			// "IsHidden"    	"0" //Don't show the aura applier
			"IsBuff" 		"1"
			// "IsPurgable" 	"0"

			"Properties"
			{
				// "MODIFIER_PROPERTY_HEALTH_BONUS"		"1337"
			}

		}
	}
}