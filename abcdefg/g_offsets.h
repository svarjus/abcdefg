#pragma once

#ifndef offsets
#define offsets

#include "pch.h"

namespace g
{
	static uintptr_t GameAssembly = (uintptr_t)GetModuleHandleA("GameAssembly.dll");
	static uintptr_t UnityPlayer = (uintptr_t)GetModuleHandleA("UnityPlayer.dll");

	static MODULEINFO gAssembly = (MODULEINFO)((void*)GameAssembly);

	static const uintptr_t GameObjectManagerOffset = (0x9AEAC1);
	static GameObjectManager* GameObject = (GameObjectManager*)(GameAssembly + GameObjectManagerOffset);
}

#endif