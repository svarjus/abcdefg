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

	void UE_Noclip(PlayerTransform_s* transform);
	uint32_t __fastcall UE_PlayerTransform(g::PlayerTransform_s* transform, void* a2, float a3, void* a4);

	typedef int64_t(*OpenURL_hook)(intptr_t* unsure);
	inline int64_t(*OpenURL_h)(intptr_t* unsure) = (OpenURL_hook)(GameAssembly + 0x133F360);
	int64_t __fastcall UE_OpenURL(intptr_t* unsure);

	typedef void(*PlayerInfo_h)(float* a1, DWORD* a2);
	inline void(*PlayerInfo_f)(float* a1, DWORD* a2) = (PlayerInfo_h)(UnityPlayer + 0x10B8B60);

	void __fastcall UE_PlayerInfo(float* a1, DWORD* a2);

	inline bool needs_teleport;
	inline vec3_t tpcoords;

	typedef void(*G_PlayerThing_hook)(PlayerController_c* ptr);
	inline void(*G_PlayerThing_f)(PlayerController_c* ptr) = (G_PlayerThing_hook)(GameAssembly + 0x282340);

	void __fastcall G_PlayerThing(PlayerController_c* ptr);

	bool WorldToScreen(int64_t camFields, vec3_t pos, vec3_t out);

	inline intptr_t camera;


}
#endif