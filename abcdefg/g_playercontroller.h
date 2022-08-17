#pragma once

#ifndef pcontroller
#define pcontroller

#include "pch.h"

namespace g {
	typedef void(*Reload_hook)(g::PlayerController_c*);
	inline void(*Reload_h)(g::PlayerController_c*) = (Reload_hook)(g::GameAssembly + 0x27BBA0);

	void Reload(g::PlayerController_c* playercontroller);
}
#endif