-- Generated from template

if CCastleFightReforged == nil then
	print("")
	print("")
	print("")
	print( "Castle Fight Reforged addon: Class has been built." )
	CCastleFightReforged = class({})
	CCastleFightReforged.CallBacks = {}
	CCastleFightReforged.Precache = {}
	_G.CCastleFightReforged = CCastleFightReforged
else
	CCastleFightReforged:OnScriptReload()
end

require( "cf_settings" ) -- require constants first
require( "cf_damagetypemodifiers" )
require( "cf_lib" )

-- Essential lua libraries: (don't remove!)
require('libraries/util')
require('libraries/timers')
require('libraries/player_resource')
require('libraries/physics')
require('libraries/projectiles')
require('libraries/animations')
require('libraries/playertables')
require('libraries/selection')

-- require('gamemode')

require( "libraries/notifications")
require( "libraries/buildinghelper")


require( "cf_statemachine" )
require( "cf_game_events" )
require( "cf_filters" )
require( "cf_income" )
require( "cf_nettables")
require( "modifiers/cf_mo_00_collection" )
require( "cf_ai_core")
require( "cf_panorama_set" )
require( "cf_shop" )
require( "cf_quests" )
require( 'cf_heroselection')
require( "abilities/cf_builder_common")


function Precache( context )
	print("Castle Fight Reforged - Precaching")
	-- Sound Files
	PrecacheResource("soundfile", CF_INCOME_SOUNDFILE, context)
	PrecacheResource("soundfile", CF_RESCUESTRIKE_SOUND, context)
	PrecacheResource("soundfile", "soundevents/game_sounds_custom.vsndevts", context)

	-- Particle Folder
	PrecacheResource("particle_folder", "particles/buildinghelper", context)

	-- Particles
	PrecacheResource("particle", CF_BU_PARTICLE, context)
	PrecacheResource("particle", CF_RESCUESTRIKE_PARTICLE, context)
	PrecacheResource("particle", "particles/econ/items/clockwerk/clockwerk_paraflare/clockwerk_para_rocket_flare_model.vpcf", context)
	PrecacheResource("particle", "particles/econ/items/techies/techies_arcana/techies_suicide_flame.vpcf", context)
	PrecacheResource("particle", "particles/generic_gameplay/generic_stunned.vpcf", context)

	-- Models
	PrecacheResource("model", "models/items/pedestals/pedestal_2/pedestal_2.vmdl", context)
	-- Items

	-- Units


end

function Activate()
	print( "Castle Fight Reforged addon is loaded." )
	
	GameRules.CastleFightReforged = CCastleFightReforged()
	GameRules.CastleFightReforged = CCastleFightReforged:Game_Init()

	print("		MapName:",GetMapName())
	print("		AddonName:")
end


function CCastleFightReforged:Game_Init()
	local bEnableStandardPickScreen = false -- Testing Purpose
	
	print( "Castle Fight Reforged Init GameMode" )
	-- print( "Castle Fight Reforged Init GameMode: Check For EnableCustomGameSetupAutoLaunch" )
	self._GameMode = GameRules:GetGameModeEntity()
	
	GameRules:GetGameModeEntity():SetAnnouncerDisabled( true )
	GameRules:GetGameModeEntity():SetUnseenFogOfWarEnabled( false )
	GameRules:GetGameModeEntity():SetFogOfWarDisabled( true )
	GameRules:GetGameModeEntity():SetTopBarTeamValuesVisible( false )
	GameRules:GetGameModeEntity():SetTowerBackdoorProtectionEnabled( false )

	if not bEnableStandardPickScreen then
		GameRules:GetGameModeEntity():SetCustomGameForceHero( "npc_dota_hero_jakiro")
	end

	
	GameRules:SetCustomGameTeamMaxPlayers( CF_TEAM_NUMBER_LEFT, CastleFightReforged_PLAYERS_PER_TEAM )
	GameRules:SetCustomGameTeamMaxPlayers( CF_TEAM_NUMBER_RIGHT, CastleFightReforged_PLAYERS_PER_TEAM )

	-- GameRules:SetCustomGameTeamMaxPlayers( DOTA_TEAM_GOODGUYS, 0 )
	-- GameRules:SetCustomGameTeamMaxPlayers( DOTA_TEAM_BADGUYS, 0 )
	-- for nCurTeam = DOTA_TEAM_CUSTOM_1,( DOTA_TEAM_CUSTOM_1 + CastleFightReforged_TEAMS_PER_GAME - 1 ) do
		-- GameRules:SetCustomGameTeamMaxPlayers( nCurTeam, CastleFightReforged_PLAYERS_PER_TEAM )
	-- end
	-- print("Game_Init","Changed CustomgameSetup Timings, to endless")
	GameRules:SetCustomGameSetupAutoLaunchDelay( -1 )
	-- GameRules:SetCustomGameSetupRemainingTime(-1)
	-- GameRules:SetCustomGameSetupTimeout( -1 )

	GameRules:SetHeroRespawnEnabled( false )
	GameRules:SetHeroSelectionTime( 0.0 )
	if bEnableStandardPickScreen then GameRules:SetHeroSelectionTime( -1 ) end

	GameRules:SetSameHeroSelectionEnabled( true )
	GameRules:SetTimeOfDay( 0.25 )
	GameRules:SetStrategyTime( 60.0 )

	if cf_testmode() then GameRules:SetStrategyTime(10.0) end
	GameRules:SetShowcaseTime( 15.0 )		-- Shows all picked heroes. 
	if cf_testmode() then GameRules:SetShowcaseTime(0.0) end
	GameRules:SetPreGameTime( 75.0 )		-- Time until Horn sounds

	if cf_testmode() then GameRules:SetPreGameTime(15.0) end
	GameRules:SetPostGameTime( 45.0 )
	GameRules:SetTreeRegrowTime( 0 )
	GameRules:SetFirstBloodActive( false )

	-- Gold
	GameRules:SetStartingGold( CastleFightReforged_STARTING_GOLD )
	if cf_testmode() then GameRules:SetStartingGold( 10000 ) end
	GameRules:SetGoldTickTime( 0 ) -- Solved by income system
	GameRules:SetGoldPerTick( 0 ) -- Solved by income system
	
	GameRules:GetGameModeEntity():SetRemoveIllusionsOnDeath( true )
	GameRules:GetGameModeEntity():SetRecommendedItemsDisabled( true )
	GameRules:GetGameModeEntity():SetDaynightCycleDisabled( true )
	GameRules:GetGameModeEntity():SetStashPurchasingDisabled( true )
	GameRules:GetGameModeEntity():SetCustomBuybackCooldownEnabled( false )
	GameRules:GetGameModeEntity():SetCustomBuybackCostEnabled( false )
 	GameRules:GetGameModeEntity():DisableHudFlip( true )
 	GameRules:GetGameModeEntity():SetLoseGoldOnDeath( false )
 	GameRules:GetGameModeEntity():SetFriendlyBuildingMoveToEnabled( true )
 	GameRules:GetGameModeEntity():SetDeathOverlayDisabled( true )
 	GameRules:GetGameModeEntity():SetHudCombatEventsDisabled( true )
	GameRules:GetGameModeEntity():SetWeatherEffectsDisabled( true )
	GameRules:GetGameModeEntity():SetCameraSmoothCountOverride( 2 )
	GameRules:GetGameModeEntity():SetSelectionGoldPenaltyEnabled( false )
	-- GameRules:GetGameModeEntity():ClearExecuteOrderFilter()

	GameRules:GetGameModeEntity():SetExecuteOrderFilter( Dynamic_Wrap( CCastleFightReforged, "OrderFilter"), self )
	GameRules:GetGameModeEntity():SetDamageFilter( Dynamic_Wrap( CCastleFightReforged, "DamageFilter" ), self )
	GameRules:GetGameModeEntity():SetGoldSoundDisabled( true )
	
 	GameRules:SetCustomGameAllowHeroPickMusic( false )
 	GameRules:SetCustomGameAllowBattleMusic( false )
	GameRules:SetCustomGameAllowMusicAtGameStart( true )
	
	
	-- Event Registration: Functions are found in cf_game_events.lua
	ListenToGameEvent( "npc_spawned", Dynamic_Wrap( CCastleFightReforged, 'OnNPCSpawned' ), self )
  	ListenToGameEvent('entity_hurt',  Dynamic_Wrap( CCastleFightReforged, 'OnEntityHurt'), self)
  	ListenToGameEvent('player_connect_full', Dynamic_Wrap( CCastleFightReforged, 'OnConnectFull'), self)
	ListenToGameEvent('entity_killed', Dynamic_Wrap(CCastleFightReforged, 'OnEntityKilled'), self)
	ListenToGameEvent('player_disconnect', Dynamic_Wrap(CCastleFightReforged, 'OnDisconnect'), self)
	ListenToGameEvent("player_reconnected", Dynamic_Wrap(CCastleFightReforged, 'OnPlayerReconnect'), self)
	
	CustomGameEventManager:RegisterListener("cf_ability_helper_command", Dynamic_Wrap(CCastleFightReforged, "Build_Abilities"))


	GameRules:GetGameModeEntity():SetThink( "OnThink", self, "GlobalThink", 2 )



end

