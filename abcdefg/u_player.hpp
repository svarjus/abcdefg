#pragma once

#ifndef uplayer
#define uplayer

#include "pch.h"

namespace g
{
	struct textobject
	{
		char pad[20];
		char message[256];
	};
	//inline int64_t(*OpenURL_h)(intptr_t* unsure);

	inline uint32_t(*UE_PlayerTransform_h)(void* a1, void* a2, float a3, void* a4);
	inline void(*PlayerInfo_f)(float* a1, DWORD* a2);
	inline intptr_t(*PrintChat_f)(intptr_t* a1, textobject* a2, uint32_t a3, char a4, intptr_t a5);

	void __fastcall			UE_PlayerInfo(float* a1, DWORD* a2);
	uint32_t __fastcall		UE_PlayerTransform(g::PlayerTransform_s* transform, void* a2, float a3, void* a4);
	//int64_t __fastcall		UE_OpenURL(intptr_t* unsure);
}

#endif