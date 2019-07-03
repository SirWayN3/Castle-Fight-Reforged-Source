-- DEBUG Settings. They will be set to false at the end, if set as comment.
CF_DEBUG								= true
CF_DEBUG_DAMAGEFILTER					= false
-- CF_DEBUG_PRINT_DAMAGETYPE_ONLY			= "CF_COMBAT_ATTACK_SPELLS"
CF_DEBUG_BOT							= true
CF_DEBUG_ALLHEROES_ENABLED				= true

-- Game Rules
CastleFightReforged_PLAYERS_PER_TEAM 	= 3
CastleFightReforged_TEAMS_PER_GAME		= 2
CastleFightReforged_STARTING_GOLD		= 250
CastleFightReforged_STARTING_ENERGY		= 0
CastleFightReforged_STARTING_ESSENCE	= 1
-- CastleFightReforged_GOLD_PER_TICK    	= 0
-- CastleFightReforged_GOLD_TICK_TIME   	= 0


CF_HERO_LEVELSTART						= 25

CF_TEAM_NUMBER_LEFT						= DOTA_TEAM_GOODGUYS
CF_TEAM_NUMBER_RIGHT					= DOTA_TEAM_BADGUYS

CF_PICKING_TIME							= 60 -- Time in Seconds for Custom Picking Screen
if IsInToolsMode() then CF_PICKING_TIME = 5 end

CF_SELECTABLE_HEROES					= {} -- Will be set by Server LUA
-- Game Rules End



-- Ingame Constants
CF_CREEP_AUTOCAST_TIMER					= 1		-- Time in Seconds, creep check the abilities to be ready to cast
CF_BUILDING_CHECKREADY					= 0.5	-- Time in Seconds, the building checks the abilities to be ready to be spawned

CF_INCOME_STARTVALUE					= 5
CF_INCOME_TIMER							= 10
CF_RESOURCE_TIMER						= 1
CF_INCOME_SOUND							= "CastleFight.Income"
CF_INCOME_SOUNDFILE						= "sounds/items/item_handofmidas.vsnd"


CF_UNIT_SPAWNED_TIMEFORORDER			= 1	-- Delay in Seconds, newly spawned units gets orders
CF_UNIT_CORPSE_DELAY					= 3
CF_UNIT_CORPSE_DURATION					= 15 -- Corpse Duration till deletion

CF_HEROIC_SHRINE_MODIFIER_NAME			= "cf_mo_bu_heroicshrine_bonus"
CF_HEROIC_SHRINE_MODIFIER_CHANCE		= 0.24 -- Chance in % Heroic Shrine hits the Double Spawn
CF_HEROIC_SHRINE_MODIFIER_PARTICLE		= "particles/units/heroes/hero_techies/techies_stasis_ground_crack_light.vpcf"
CF_HEROIC_SHRINE_DELAY					= 1.0 -- Delay of Heroic Shrine for Units to spawn

-- CF_BU_PARTICLE							= "particles/units/heroes/hero_riki/riki_smokebomb.vpcf" -- Particle for Building Creation
CF_BU_PARTICLE							= "particles/cf_building_particle2.vpcf"

CF_BU_DESTROY_INTERVAL					= 0.3 	-- Keep this Value above 0.2, else it will cause errors in LUA_MODIFIER_INVALID
CF_BU_DESTROY_PERCENTAGE				= 0.05 	-- Value to calc HP removal with MaxHealth 

-- AI Settings
CF_AI_CREEP_AQCUIRETARGETRANGE			= 1000
CF_AI_CREEP_WAYPOINT_RANGE				= 500

-- Ingame Constants End

if CF_DEBUG == nil then CF_DEBUG = false end
if CF_DEBUG_DAMAGEFILTER == nil then CF_DEBUG_DAMAGEFILTER = false end
if CF_DEBUG_BOT == nil then CF_DEBUG_BOT = false end