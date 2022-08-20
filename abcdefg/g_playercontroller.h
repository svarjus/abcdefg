#pragma once

#ifndef pcontroller
#define pcontroller

#include "pch.h"

namespace g {
	typedef void(*Reload_hook)(g::PlayerController_c*);
	inline void(*Reload_h)(g::PlayerController_c*) = (Reload_hook)(g::GameAssembly + 0x27BBA0);

	void Reload(g::PlayerController_c* playercontroller);
	
	typedef uint32_t (*UE_PlayerTransform_hook)(void* a1, void* a2, float a3, void* a4);
	inline uint32_t(*UE_PlayerTransform_h)(void* a1, void* a2, float a3, void* a4) = (UE_PlayerTransform_hook)(g::UnityPlayer + 0x10C08E0);

	uint32_t __fastcall UE_PlayerTransform(g::PlayerTransform_s* transform, void* a2, float a3, void* a4);


}
#endif