cf_mo_bu_destroy = class({})



function cf_mo_bu_destroy:IsDebuff()
	return false
end

-- function cf_mo_bu_destroy:IsPurgable()
-- 	return false
-- end

function cf_mo_bu_destroy:OnCreated( kv )
	-- Keep this Value @ 0.2, lower will result in errors from engine
	print ( CF_BU_DESTROY_INTERVAL )
	-- PrintTable( kv )
	self:StartIntervalThink( 0.5 )
	-- self:StartIntervalThink( 1 )
end

function cf_mo_bu_destroy:OnDestroy()
	
end

function cf_mo_bu_destroy:OnIntervalThink()
	local hParent = self:GetParent()
	-- print ( "damage self")
	-- local damage = {
	-- 				victim = hParent,
	-- 				attacker = hParent,
	-- 				-- damage = hParent:GetMaxHealth() / 10,
	-- 				damage = 100,
	-- 				damage_type = DAMAGE_TYPE_PURE,
	-- 				ability = nil,
	-- }
	-- ApplyDamage( damage )
	-- print( hParent:GetMaxHealth() )
	local damage = hParent:GetMaxHealth() * CF_BU_DESTROY_PERCENTAGE * CF_BU_DESTROY_INTERVAL
	-- hParent:SetHealth( hParent:GetHealth() - damage )
	hParent:ModifyHealth( -damage )
	if hParent:GetHealth() == 0 then
		-- hParent:ForceKill( true )
		BuildingHelper:RemoveBuilding( hParent , true)
		UTIL_Remove( hParent )
	end
end

