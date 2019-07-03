function cf_ab_chamber( event )
	-- PrintTable( event )
	if event.ability:IsFullyCastable() then
		event.attacker:CastAbilityOnTarget(event.target, event.ability, event.attacker:GetPlayerOwnerID())

	else
		-- print("Ability no ready yet")
		return false
	end
end