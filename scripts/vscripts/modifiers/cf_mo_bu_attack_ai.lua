cf_mo_bu_attack_ai = class({})

cf_mo_bu_attack_ai.interval = 0.2


function cf_mo_bu_attack_ai:IsHidden()
	return false
end

function cf_mo_bu_attack_ai:IsPurgable()
	return false
end

function cf_mo_bu_attack_ai:OnCreated( kv )
	if IsServer() then
		-- print("cf_mo_bu_attack_ai","OnCreated")
		local unit = self:GetParent()
		if unit:HasAttackCapability() then
			-- print(unit:GetAttackTargetType())
			if unit:GetAttackTargetType() == "AI_ATTACK_ALL" then
				-- self:Destroy()
			else
				self.attackCap = unit:GetAttackCapability()
				unit.attackType = unit:GetAttackTargetType()
				-- print("attacktype",self.attackCap)
				self.target = nil
				self.unit = unit
				unit:SetAttackCapability(DOTA_UNIT_CAP_NO_ATTACK)
				self:StartIntervalThink(self.interval)
			end
		else
			self:Destroy()
		end
	end
end
function cf_mo_bu_attack_ai:OnDestroy()
	if IsServer() then
		if self.unit and self.unit:IsAlive() then
			self.unit:SetAttackCapability(self.attackType)
		end
	end
end

function cf_mo_bu_attack_ai:GetPriority()
	return MODIFIER_PRIORITY_ULTRA
end

function cf_mo_bu_attack_ai:OnIntervalThink()
	if IsServer() then
		if self.target == nil then
			-- Check for Target
			self.target = self.unit:GetValidAttackTarget()
			-- Is Target Valid?
			if self.target ~= nil then
				-- print("cf_mo_bu_attack_ai","Target Acquired:",self.target:GetUnitName(),self.attackCap)
				self.unit:SetAttackCapability(self.attackCap)
				self.unit:SetForceAttackTarget(self.target)
			end
		else
			if not self.target:IsAlive() then
				self.target = nil
				self.unit:SetAttackCapability(DOTA_UNIT_CAP_NO_ATTACK)
			end
		end
		
	end
end