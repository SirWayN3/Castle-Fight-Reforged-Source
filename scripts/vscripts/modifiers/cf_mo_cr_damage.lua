cf_mo_cr_damage = class({})

function cf_mo_cr_damage:IsHidden()
	return false
end

function cf_mo_cr_damage:IsPurgable()
	return false
end

function cf_mo_cr_damage:IsDebuff()
	return false
end

function cf_mo_cr_damage:DeclareFunctions()
	local funcs = {
		MODIFIER_PROPERTY_BASEDAMAGEOUTGOING_PERCENTAGE
		-- MODIFIER_PROPERTY_PREATTACK_BONUS_DAMAGE
		-- MODIFIER_PROPERTY_BASEDAMAGEOUTGOING_PERCENTAGE
	}

	return funcs
end
function cf_mo_cr_damage:GetPriority()
	return MODIFIER_PRIORITY_ULTRA
end

function cf_mo_cr_damage:GetModifierBaseDamageOutgoing_Percentage( )
	return self.bonusdmg
end


function cf_mo_cr_damage:OnCreated( kv )
	print ( "cf_mo_cr_damage OnCreated")
	-- print(kv)
	-- PrintTable(kv)

	-- self.multiplier = kv.multiplier / 100
	-- local unit = self:GetParent()
	-- print( unit:GetUnitName() )
	-- print( unit:GetBaseDamageMin() )
	-- self.bonusdmg = self:GetStackCount() / 100 * unit:GetBaseDamageMin() 
	self.bonusdmg = self:GetStackCount()
	print(self.bonusdmg)
end

-- function cf_mo_cr_damage:OnDestroy()
-- 	print("cf_mo_cr_damage: OnDestroy")
-- end

