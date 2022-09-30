#pragma once

#ifndef pcontroller
#define pcontroller

#include "pch.h"
struct textobject
{
	char pad[20];
	char message[256];
};
namespace g {

	struct __tp
	{
		bool needs_teleport;
		vec3_t tpcoords;
		vec3_t myCoords;
	};

	typedef void(*Update_hook)(g::PlayerController_c*);

	

	//typedef int64_t(*OpenURL_hook)(intptr_t* unsure);
	//inline OpenURL_hook OpenURL_h;

	typedef uint32_t(*UE_PlayerTransform_hook)(void* a1, void* a2, float a3, void* a4);
	typedef void(*PlayerInfo_h)(float* a1, DWORD* a2);
	typedef intptr_t(*PrintChat_hook)(intptr_t* a1, textobject* a2, uint32_t a3, char a4, intptr_t a5);

	inline uintptr_t PlayerController_Die;
	inline uintptr_t PlayerController_Fire_Delay;
	inline BYTE PlayerController_Fire_Delay_orgbytes[5];

	inline Update_hook Update_h;
	inline PlayerInfo_h PlayerInfo_f;
	inline UE_PlayerTransform_hook UE_PlayerTransform_h;
	inline PrintChat_hook PrintChat_f;

	inline __tp _tp;
	void PlayerController_Update(g::PlayerController_c* playercontroller);
	bool WorldToScreen(int64_t camFields, vec3_t pos, vec3_t out);
	void __fastcall UE_PlayerInfo(float* a1, DWORD* a2);
	uint32_t __fastcall UE_PlayerTransform(g::PlayerTransform_s* transform, void* a2, float a3, void* a4);
	int64_t __fastcall UE_OpenURL(intptr_t* unsure);

	inline std::vector<players_s> players;

	intptr_t __fastcall PrintChat(intptr_t* a1, textobject* a2, uint32_t a3, char a4, intptr_t a5);


}
#endif