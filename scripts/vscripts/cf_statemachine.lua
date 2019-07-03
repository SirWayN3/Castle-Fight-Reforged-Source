

if cf_state_value == nil then
	-- State Machine
	CF_STATE_INIT 							= 0
	CF_STATE_WAITFORPREGAME					= 10	-- Wait for Player loaded
	CF_STATE_WAITFORSTART					= 20
	CF_STATE_GAME_IN_PROGRESS				= 30


	cf_state_value							= CF_STATE_INIT
	-- State Machine End
end

if CastleFightReforged_StateActions == nil then
	CastleFightReforged_StateActions = {
		[CF_STATE_INIT]			= function (x) 
				cf_state_value = CF_STATE_SETTABLES 
				cf_SetTables_AttackMove()
				cf_state_value = CF_STATE_WAITFORPREGAME
				HeroSelection:Init()
				-- Timers:CreateTimer( CF_RESOURCE_TIMER, cf_resource_timer )
			end,
			
		[CF_STATE_WAITFORPREGAME]	= function (x)
				if GameRules:State_Get() == DOTA_GAMERULES_STATE_PRE_GAME then
					HeroSelection:Start()
					cf_state_value = CF_STATE_WAITFORSTART
					local building = Entities:FindAllByName("cf_fort_left")
					building[1]:AddNewModifier(nil, nil, "modifier_building", {})
					-- function building[1]:IsUnderConstruction() return false end

					local building = Entities:FindAllByName("cf_fort_right")
					building[1]:AddNewModifier(nil, nil, "modifier_building", {})
					-- function building[1]:IsUnderConstruction() return false end

				end
			end,
		[CF_STATE_WAITFORSTART] = function (x)
				if GameRules:State_Get() == DOTA_GAMERULES_STATE_GAME_IN_PROGRESS then
					Timers:CreateTimer( CF_INCOME_TIMER, cf_income_timer )
					-- cf_income_timer()
					cf_state_value = CF_STATE_GAME_IN_PROGRESS
				end
				cf_resource_timer()
			end,
		[CF_STATE_GAME_IN_PROGRESS] = function (x)
				CF_Shop:Think()
				cf_resource_timer()
			end,
	}
	
end

function CCastleFightReforged:StateMachine()
	-- print("CastleFightReforged:StateMachine: Current State " .. cf_state_value)
	
	
	CastleFightReforged_StateActions[cf_state_value]()

	
end

