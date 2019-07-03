cf_mo_criticalstrike = class({})


function cf_mo_criticalstrike:IsHidden()
	return false
end

function cf_mo_criticalstrike:IsPurgable()
	return false
end
function cf_mo_criticalstrike:IsDebuff()
	return false
end

function cf_mo_criticalstrike:OnCreated( kv )
	if IsServer() then
		-- print("cf_mo_criticalstrike","OnCreated")
		-- print("Ability:",self:GetAbility() )
		self.crit_mult = self:GetAbility():GetLevelSpecialValueFor("crit_mult", 1)
		self.crit_chance = self:GetAbility():GetLevelSpecialValueFor("crit_chance", 1)
		-- self.crit_damage = 0
		-- self.crit_chance = 100
		-- self.crit_active = false
	end
end
function cf_mo_criticalstrike:OnAttackLanded( kv )
	if IsServer() then
		if kv.attacker == self:GetParent() then
			-- print("OnAttackLanded")
			-- print("","Target",kv.target:GetUnitName())
			-- print("","Attacker:",kv.attacker:GetUnitName())
			-- print("","CritChance:",self.crit_chance)
			-- print("Target",kv.victim:GetUnitName())
			-- PrintTable(kv)
			if RollPercentage(self.crit_chance) then
				self.crit_active = self.crit_mult
			else
				self.crit_active = 0
			end
		end
	end
end
function cf_mo_criticalstrike:GetModifierPreAttack_CriticalStrike(kv)
	return self.crit_active
end
function cf_mo_criticalstrike:DeclareFunctions()
	local funcs = {
		MODIFIER_EVENT_ON_ATTACK_LANDED,
		MODIFIER_PROPERTY_PREATTACK_CRITICALSTRIKE
	}

	return funcs
end
function cf_mo_criticalstrike:OnIntervalThink()
	if IsServer() then
		
	end
end

function cf_mo_criticalstrike:GetPriority()
	return MODIFIER_PRIORITY_ULTRA
end

