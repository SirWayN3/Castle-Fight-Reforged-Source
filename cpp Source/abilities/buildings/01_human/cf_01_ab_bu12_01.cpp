"cf_01_ab_bu12_01"
{
	/*
		[self]
		target=Ability_Names_Humans
		type=ability
		name=Spawns $self.cf_unit_count$ $self.cf_unit_name.this$
		descr=Heavy Gunner are ranged, but cannot attack Air Units. But they have Splash Attack and Critical Strike.
	*/
	"BaseClass"                     "ability_datadriven"
	"AbilityBehavior"				" DOTA_ABILITY_BEHAVIOR_NO_TARGET | DOTA_ABILITY_BEHAVIOR_IMMEDIATE "
	
	"AbilityManaCost"				"0"
	"AbilityGoldCost"				"0"
	"AbilityCooldown"				"31.5"
	
	"Level"							"0"
	"MaxLevel"                      "1"

	"cf_ab_spawner"					"1"
	"cf_unit_name"					"cf_01_cr_08_heavygunner"
	"cf_unit_count"					"1"
	"cf_autocast"					"1"

	"OnSpellStart"
	{
		"RunScript"
		{
			"ScriptFile"			"abilities/common/cf_common_ab_bu_spawn_units.lua"
			"Function"				"cf_common_ab_bu_spawn_units_OnSpellStart"
			"EventName" 			"SpawnUnits"
		}
	}
}

