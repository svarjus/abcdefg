#pragma once

#ifndef pcontroller
#define pcontroller

#include "pch.h"

namespace g {
	typedef void(*Update_hook)(g::PlayerController_c*);
	inline void(*Update_h)(g::PlayerController_c*) = (Update_hook)(g::GameAssembly + 0x282340);

	void PlayerController_Update(g::PlayerController_c* playercontroller);
	
	typedef uint32_t (*UE_PlayerTransform_hook)(void* a1, void* a2, float a3, void* a4);
	inline uint32_t(*UE_PlayerTransform_h)(void* a1, void* a2, float a3, void* a4) = (UE_PlayerTransform_hook)(g::UnityPlayer + 0x10C08E0);

	uint32_t __fastcall UE_PlayerTransform(g::PlayerTransform_s* transform, void* a2, float a3, void* a4);

	typedef int64_t(*OpenURL_hook)(intptr_t* unsure);
	inline int64_t(*OpenURL_h)(intptr_t* unsure) = (OpenURL_hook)(GameAssembly + 0x133F360);
	int64_t __fastcall UE_OpenURL(intptr_t* unsure);

	typedef void(*bro_idk)(intptr_t* unknown, intptr_t* unknown2);
	inline void(*bro_idk_h)(intptr_t* unknown, intptr_t* unknown2) = (bro_idk)(GameAssembly + 0x224530);
	void Bro_Idk(intptr_t* unknown, intptr_t* unknown2);
}
#endif