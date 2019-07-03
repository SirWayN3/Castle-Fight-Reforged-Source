
function cf_ab_ressurect_onspellstart( kv )
	-- PrintTable( kv )
	--[[
		kv.ability; kv.attacker; kv.caster; kv.particle; kv.target; kv.unit
	]]
	-- print(kv.target:GetUnitName())
	-- PrintTable(kv.target)
	-- if kv.target
	if kv.target == nil then return end
	if kv.target.unit_name == nil then return end
	local unit = CreateUnitByName(
		kv.target.unit_name,
		kv.target:GetAbsOrigin(),
		true,
		kv.caster:GetOwner(),
		kv.caster:GetOwner(),
		kv.caster:GetTeam()
	)
	if not kv.target:IsNull() then UTIL_Remove(kv.target) end
	ParticleManager:CreateParticle(kv.particle, PATTACH_OVERHEAD_FOLLOW, unit)

end

