#pragma once

#ifndef pcontroller
#define pcontroller

#include "pch.h"
namespace g {

	inline struct __tp
	{
		bool needs_teleport;
		vec3_t tpcoords;
		vec3_t myCoords;
	}_tp;

	inline void(*Update_h)(g::PlayerController_c*);



	inline uintptr_t PlayerController_Die;
	inline uintptr_t PlayerController_Fire_Delay;
	inline uintptr_t PlayerController_Fire_Recoil;
	inline uintptr_t PlayerController_Fire_Effect;

	inline BYTE PlayerController_Fire_Delay_orgbytes[5];
	inline BYTE PlayerController_Fire_Recoil_orgbytes[5];
	inline BYTE PlayerController_Fire_Effect_orgbytes[5];

	inline uintptr_t OutskirtsCodeGenerator__get_Code;
	inline uintptr_t MyceliumNetwork$$get_LocalPlayer;
	inline uintptr_t PlayerController$$OnKill;

	
	void PlayerController$$OnKill_(PlayerController_c* __this, KillData_o* data);
	void PlayerController_Update(g::PlayerController_c* playercontroller);
	bool WorldToScreen(int64_t camFields, vec3_t pos, vec3_t out);
	bool WorldToScreen(vec3_t pos, vec2_t xy);

	intptr_t __fastcall PrintChat(intptr_t* a1, textobject* a2, uint32_t a3, char a4, intptr_t a5);

	inline std::vector<GameObject*> players;



}
#endif