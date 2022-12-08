
#include "pch.h"


void g::BypassAntiCheat()
{
	if (!v::bypass_anticheat.isEnabled() || !PlayerController_ptr)
		return;

	static bool first_init = true;

	if (first_init) {
		first_init = false;
		PlayerController_ptr->antiCheat_offenses = -500;
		anticheat_offenses = 0;
	}

	if (PlayerController_ptr->antiCheat_offenses != -500) {
		PlayerController_ptr->antiCheat_offenses = -500;
		anticheat_offenses++;
		PlayerController_ptr->antiCheat_lastFireTime = 0;
		PlayerController_ptr->identityIsMine = 0;
		PlayerController_ptr->leftTriggerDownLastFrame = 0;

	}

}