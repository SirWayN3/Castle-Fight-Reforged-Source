cf_mo_naga_earthquake = class({})


function cf_mo_naga_earthquake:IsHidden()
	return false
end

function cf_mo_naga_earthquake:IsPurgable()
	return false
end


function cf_mo_naga_earthquake:GetEffectAttachType()
    return PATTACH_ABSORIGIN_FOLLOW
end
function cf_mo_naga_earthquake:GetModifierAttackSpeedBonus_Constant()
	return self.as_slow
end

function cf_mo_naga_earthquake:GetModifierMoveSpeedBonus_Percentage()
	return self.ms_slow
end

function cf_mo_naga_earthquake:DeclareFunctions()
	local funcs = {
		MODIFIER_PROPERTY_MOVESPEED_BONUS_PERCENTAGE,
		MODIFIER_PROPERTY_ATTACKSPEED_BONUS_CONSTANT
	}

	return funcs
end
-- function cf_mo_naga_earthquake:OnRefresh( kv )
-- 	if IsServer() then
-- 		self.ms_slow_init = kv.ms_slow
-- 		self.as_slow_init = kv.as_slow
-- 	end
-- end

function cf_mo_naga_earthquake:OnCreated( kv )
	if IsServer() then
		-- PrintTable(kv)
		-- print("Position:",self:GetAbsOrigin())
		-- print(
			-- "cf_mo_naga_earthquake",
			-- kv.particle,
			-- kv.ms_slow,
			-- kv.as_slow
			-- kv.pos
			-- kv.target:GetUnitName()
			-- )
		-- self.duration = kv.duration
		self.ms_slow = kv.ms_slow
		self.as_slow = kv.as_slow
		self.pos = self:GetParent():GetOrigin()
		self.particle = kv.particle
		self.teamnumber = self:GetCaster():GetTeamNumber()
		self.aoe = kv.aoe
		self.damage = kv.dmg_to_ground
		self.caster = self:GetCaster() -- Nothing in here...
		self.ability = kv.ability
		-- self:OnIntervalThink()
		self:StartIntervalThink(1.0)
		print("Caster",self.caster)
		
	end
end
function cf_mo_naga_earthquake:OnDestroy()
	-- expired
	-- print("cf_mo_naga_earthquake","OnDestroy")
	if IsServer() then
		UTIL_Remove( self:GetParent() )
		ParticleManager:DestroyParticle(self.fx, true)
	end
end
function cf_mo_naga_earthquake:OnIntervalThink()
	if IsServer() then
		self:CreateParticle()
		local enemies = FindUnitsInRadius(
			self.teamnumber,
			self.pos,
			nil,
			self.aoe,
			DOTA_UNIT_TARGET_TEAM_ENEMY,
			DOTA_UNIT_TARGET_CREEP,
			DOTA_UNIT_TARGET_FLAG_NONE,
			FIND_ANY_ORDER,
			false
		)
		if #enemies > 0 then
			for k,v in pairs(enemies) do
				if not v:HasFlyMovementCapability() then
					print(k,v:GetUnitName())
					local t = {
						victim = v,
						attacker = self.caster,
						damage = self.damage,
						damage_type = DAMAGE_TYPE_MAGICAL,
						ability = self.ability
					}
					print("attacker: ",self.caster)
					-- PrintTable(t)
					ApplyDamage(t)
				end
			end
		end

	end
end
function cf_mo_naga_earthquake:CreateParticle()
	if self.fx then ParticleManager:DestroyParticle(self.fx, true) end
	self.fx = ParticleManager:CreateParticle(
			self.particle,
			PATTACH_WORLDORIGIN,
			nil
			)
	-- print("particle",self.particle)
	ParticleManager:SetParticleControl(
		self.fx,
		0,
		self.pos
		)
end
function cf_mo_naga_earthquake:GetPriority()
	return MODIFIER_PRIORITY_ULTRA
end


-- function cf_mo_naga_earthquake:CheckState()
-- 	local state = {
-- 	[MODIFIER_STATE_STUNNED] = true,
-- 	}

-- 	return state
-- end
