

#include "pch.h"



void g::Reload(PlayerController_c* playercontroller)
{

	memcpy(&g::PlayerController, playercontroller, sizeof(playercontroller));
	g::hasPlayerController = true;

	return Reload_h(playercontroller);
}
