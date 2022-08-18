#pragma once

#ifndef offsets
#define offsets

#include "pch.h"

namespace g
{
	inline uintptr_t GameAssembly = (uintptr_t)GetModuleHandleA("GameAssembly.dll");
	inline uintptr_t UnityPlayer = (uintptr_t)GetModuleHandleA("UnityPlayer.dll");
	inline uintptr_t RedMatch = (uintptr_t)GetModuleHandle("Redmatch 2.exe");

	static const uintptr_t PlayerControllerOffset =  (0x12B0040);
	inline PlayerController_c PlayerController;
}

#endif