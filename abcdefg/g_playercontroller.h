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

	inline void (*PlayerManager__GotKilledByPlayer_f)(MyceliumPlayer_o* killer, void* damageData, float distance, int16_t damagePacketID);
	inline void (*AntiCheat_Boost__OnAnyoneDeath_f)(MyceliumPlayer_o* killer, MyceliumPlayer_o* victim, void* damageData);
	inline void (*SpectatorControllerOnAnyoneDeath_f)(void* _this, MyceliumPlayer_o* killer, MyceliumPlayer_o* victim, void* damageData);
	inline void (*AntiCheat__TakeAction_f)(MyceliumPlayer_o* hacker, System_String_o* code);



    void AntiCheat__TakeAction(MyceliumPlayer_o* hacker, System_String_o* code);
	void SpectatorControllerOnAnyoneDeath(void* _this, MyceliumPlayer_o* killer, MyceliumPlayer_o* victim, void* damageData);
	std::string ResolveSystemString(System_String_o* name);
	void AntiCheat_Boost__OnAnyoneDeath(MyceliumPlayer_o* killer, MyceliumPlayer_o* victim, void* damageData);
	void PlayerManager__GotKilledByPlayer(MyceliumPlayer_o* killer, void* damageData, float distance, int16_t damagePacketID);
	void PlayerController_Update(g::PlayerController_c* playercontroller);
	bool WorldToScreen(int64_t camFields, vec3_t pos, vec3_t out);
	bool WorldToScreen(vec3_t pos, vec2_t xy);

	intptr_t __fastcall PrintChat(intptr_t* a1, textobject* a2, uint32_t a3, char a4, intptr_t a5);

	inline std::vector<GameObject*> players;

	//UNITYENGINE WEBREQUESTS
	inline void* (*UnityEngine_Networking_UnityWebRequest__Get_f)(System_String_o* uri);
	inline void* (*UnityEngine_Networking_UnityWebRequest__Post_f)(System_String_o* uri, System_String_o* postData);

	void* UnityEngine_Networking_UnityWebRequest__Get(System_String_o* uri);
	void* UnityEngine_Networking_UnityWebRequest__Post(System_String_o* uri, System_String_o* postData);


	//moderator spoofing
	inline bool (*MyceliumPlayer__get_HasModeratorAuthority_f)(MyceliumPlayer_o* moderator);
	bool MyceliumPlayer__get_HasModeratorAuthority(MyceliumPlayer_o* moderator);


}
#endif