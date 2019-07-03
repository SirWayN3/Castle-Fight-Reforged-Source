
function cf_common_ab_bu_destroy( event )
	event.caster:ForceKill( false )
end

function cf_common_ab_bu_destroy_on( event )
	-- print("cf_common_ab_bu_destroy:OnToggleOn")
	-- PrintTable( event )
	-- local hParent = self:GetCaster()
	local hParent = event.caster

	-- print( tostring( hParent:IsBuilding() ) )
	-- print (tostring( hParent:HasModifier("modifier_heroic_shrine_bonus") ))
	-- hParent:ForceKill( false )

	hParent:AddNewModifier(hParent, nil, "cf_mo_bu_destroy", {duration = -1 })
	hParent:RemoveModifierByName("cf_mo_bu_autocast")

end

function cf_common_ab_bu_destroy_off( event )
	-- print("cf_common_ab_bu_destroy:OnToggleOff")
	local hParent = event.caster
	hParent:RemoveModifierByName("cf_mo_bu_destroy")
	hParent:AddNewModifier(hParent, nil, "cf_mo_bu_autocast", { Duration = -1 })
end

