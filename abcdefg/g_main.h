#pragma once

#ifndef gtest
#define gtest

#include "pch.h"

namespace g
{
	inline bool hasPlayerController;

	void G_SetVariables();
	void G_DebugVariables(PlayerController_c* LocalPlayer);
	void G_Init();
	void G_OffsetsAndHooks();

	inline uintptr_t* chatmanager = NULL;

}

#endif