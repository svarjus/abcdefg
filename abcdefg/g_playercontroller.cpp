

#include "pch.h"



void g::Reload(PlayerController_c* playercontroller)
{
	memcpy(&g::PlayerController, playercontroller, sizeof(playercontroller));
	g::hasPlayerController = true;

	return Reload_h(playercontroller);
}
uint32_t __fastcall g::UE_PlayerTransform(PlayerTransform_s* transform, void* a2, float a3, void* a4)
{
	if(vars::world_skywalk.enabled)
		transform->origin[1] = vars::world_skywalk_z.floatValue;
	return UE_PlayerTransform_h(transform, a2, a3, a4);
}