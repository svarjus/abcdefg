#pragma once

#ifndef gtest
#define gtest

#include "pch.h"

namespace g
{
	inline bool hasPlayerController;

	void G_Init();
	void G_OffsetsAndHooks();
	void G_PrepareHooks();
	void G_InitHooks();
	void G_RemoveHooks();

	inline uintptr_t* chatmanager = NULL;

}

#endif