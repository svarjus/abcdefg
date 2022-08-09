#pragma once

#ifndef offsets
#define offsets

#include "pch.h"

namespace g
{
	inline uintptr_t GameAssembly = (uintptr_t)GetModuleHandleA("GameAssembly.dll");
	inline uintptr_t UnityPlayer = (uintptr_t)GetModuleHandleA("UnityPlayer.dll");
	inline uintptr_t RedMatch = (uintptr_t)GetModuleHandle("Redmatch 2.exe");

	inline MODULEINFO gAssembly = getModuleInfo((char*)"GameAssembly.dll");

	static const uintptr_t GameObjectManagerOffset = (0x9AEAC1);
	static const uintptr_t PlayerControllerOffset =  (0x12B0040);
	static GameObjectManager* GameObject = (GameObjectManager*)(GameAssembly + GameObjectManagerOffset);
	inline PlayerController_c* PlayerController;
}

#endif