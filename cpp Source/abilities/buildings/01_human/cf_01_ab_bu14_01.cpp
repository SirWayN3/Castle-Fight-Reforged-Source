"cf_01_ab_bu14_01"
{
	/*
		[self]
		target=Ability_Names_Humans
		type=ability
		name=Spawns $self.cf_unit_count$ $self.cf_unit_name.this$
		descr=Paladin are meele units with Heavy Armor and Normal Attack. They can Bless Units to give them HP Regen and Bonus Armor. Also They Revive Units and have Bash and Cleave Attack and an Armor Bonus Aura.
	*/
	"BaseClass"                     "ability_datadriven"
	"AbilityBehavior"				" DOTA_ABILITY_BEHAVIOR_NO_TARGET | DOTA_ABILITY_BEHAVIOR_IMMEDIATE "
	
	"AbilityManaCost"				"0"
	"AbilityGoldCost"				"0"
	"AbilityCooldown"				"41.5"
	
	"Level"							"0"
    "MaxLevel"                      "1"

    "cf_ab_spawner"					"1"
	"cf_unit_name"					"cf_01_cr_10_paladin"
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

