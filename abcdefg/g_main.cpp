#include "pch.h"


void g::G_Init()
{
	static bool once = true;

	if (!once)
		return;
	
	once = false;

	G_PrepareHooks();
	G_InitHooks();
	G_OffsetsAndHooks();

	

}
void g::G_PrepareHooks()
{
	//unity engine calls
	fnIl2cpp_resolve_icall							= (tpIl2cpp_resolve_icall*)GetProcAddress((HMODULE)GameAssembly, EXPORT_IL2CPP_RESOLVE_ICALL);
	fnWorldToScreenPoint							= (tp_WorldToScreenPoint*)fnIl2cpp_resolve_icall("UnityEngine.Camera::WorldToScreenPoint_Injected");
	fnGetMainCamera									= (tpGetMainCamera*)fnIl2cpp_resolve_icall("UnityEngine.Camera::get_current()");
	fnSendChatMessage								= (tp_fnSendChatMessage*)fnIl2cpp_resolve_icall(SENDCHATMESSAGE);

	std::cout << "fnSendChatMessage: 0x" << std::hex << fnSendChatMessage << '\n';

	WorldToScreenPoint								= (vec3(*)(void* camera, vec3 position))(GameAssembly + 13245152); //UnityEngine.Camera$$WorldToScreenPoint


	//gameassembly hooks
	Update_h										= (void(*)(g::PlayerController_c*))(GameAssembly + 20508816);			//PlayerController$$Update
	PrintChat_f										= (void(*)(ChatManager_o*, System_String_o *, int32_t, bool, MyceliumPlayer_o*, MyceliumPlayer_o *, const MethodInfo*))	(GameAssembly + 20298592);   //ChatManager$$SendChatMessage
	OutskirtsCodeGenerator__get_Code				= (uintptr_t)(GameAssembly + 20460896);									//OutskirtsCodeGenerator__get_Code
	MyceliumNetwork$$get_LocalPlayer				= (uintptr_t)(GameAssembly + 19702000);									//MyceliumNetwork$$get_LocalPlayer

	//unity engine hooks
	UE_PlayerTransform_h							= (uint32_t(*)(void*, void*, float, void*))			(UnityPlayer + 0x10C08E0);
	PlayerInfo_f									= (void(*)(float*, DWORD*))							(UnityPlayer + 0x10B8B60);
	PlayerData_f									= (char(*)(uintptr_t * a1, float* a2, char a3))		(UnityPlayer + 0x07FDB0);

	PlayerController_Die							= (GameAssembly + 20477680);			//PlayerController$$Die
	PlayerController_Fire_Delay						= (GameAssembly + 20482208 + 0x137);	//PlayerController$$Fire + 0x137
	PlayerController_Fire_Recoil					= (GameAssembly + 20482208 + 0x23D);	//PlayerController$$Fire + 0x23D    PLayerController.Fire --> StressReceiver.InduceStress
	PlayerController_Fire_Effect					= (GameAssembly + 20480384 + 0x24A);		//PlayerController$$FireLocal --> Item.Fire

	SteamDLCManager__HasDLC_h						= (bool(*)(int32_t dlc))(g::GameAssembly + 19978912); //SteamDLCManager$$HasDLC

	OutskirtsKeyPad_Press_f							= (void(*)(void* keypad, int num, const MethodInfo * method))(GameAssembly + 20039616); //GameMode_TeamDeathmatch$$MessageHandler_SetPointsForTeam
	
	PlayerManager__GotKilledByPlayer_f				= (void (*)(MyceliumPlayer_o*, void*, float, int16_t))				(GameAssembly + 20342864);	//PlayerManager$$GotKilledByPlayer
	AntiCheat_Boost__OnAnyoneDeath_f				= (void (*)(MyceliumPlayer_o*, MyceliumPlayer_o*, void*))			(GameAssembly + 20239840);  //AntiCheat_Boost$$OnAnyoneDeath
	SpectatorControllerOnAnyoneDeath_f				= (void (*)(void*, MyceliumPlayer_o *, MyceliumPlayer_o *, void*))	(GameAssembly + 19962224);	//SpectatorController$$OnAnyoneDeath
	AntiCheat__TakeAction_f							= (void (*)(MyceliumPlayer_o*, System_String_o*))					(GameAssembly + 20240848);	//AntiCheat$$TakeAction

	UnityEngine_Networking_UnityWebRequest__Get_f	= (void*(*)(System_String_o*))										(GameAssembly + 19246624);	//UnityEngine.Networking.UnityWebRequest$$Get
	UnityEngine_Networking_UnityWebRequest__Post_f	= (void*(*)(System_String_o*, System_String_o*))					(GameAssembly + 19248000);	//UnityEngine.Networking.UnityWebRequest$$Post

	MyceliumPlayer__get_HasModeratorAuthority_f		= (bool(*)(MyceliumPlayer_o*))										(GameAssembly + 7735456);	//MyceliumPlayer$$get_HasModeratorAuthority


}
void g::G_InitHooks()
{
	hook* a = nullptr;

	a->install(&(PVOID&)Update_h, PlayerController_Update);
	a->install(&(PVOID&)UE_PlayerTransform_h, UE_PlayerTransform);
	a->install(&(PVOID&)PlayerInfo_f, UE_PlayerInfo);
	a->install(&(PVOID&)PrintChat_f, PrintChat);
	a->install(&(PVOID&)OutskirtsKeyPad_Press_f, OutskirtsKeyPad_Press);
	//a->install(&(PVOID&)PlayerManager__GotKilledByPlayer_f, PlayerManager__GotKilledByPlayer);
	//a->install(&(PVOID&)AntiCheat_Boost__OnAnyoneDeath_f, AntiCheat_Boost__OnAnyoneDeath);
	//a->install(&(PVOID&)SpectatorControllerOnAnyoneDeath_f, SpectatorControllerOnAnyoneDeath);
	a->install(&(PVOID&)AntiCheat__TakeAction_f, AntiCheat__TakeAction);

	a->install(&(PVOID&)UnityEngine_Networking_UnityWebRequest__Get_f, UnityEngine_Networking_UnityWebRequest__Get);
	a->install(&(PVOID&)UnityEngine_Networking_UnityWebRequest__Post_f, UnityEngine_Networking_UnityWebRequest__Post);

	a->install(&(PVOID&)MyceliumPlayer__get_HasModeratorAuthority_f, MyceliumPlayer__get_HasModeratorAuthority);

}
void g::G_RemoveHooks()
{
	hook* a = nullptr;

	a->remove(&(PVOID&)Update_h, PlayerController_Update);
	a->remove(&(PVOID&)UE_PlayerTransform_h, UE_PlayerTransform);
	a->remove(&(PVOID&)PlayerInfo_f, UE_PlayerInfo);
	a->remove(&(PVOID&)PrintChat_f, PrintChat);
	a->remove(&(PVOID&)OutskirtsKeyPad_Press_f, OutskirtsKeyPad_Press);
	//a->remove(&(PVOID&)PlayerData_f, UE_PlayerData);
	//a->remove(&(PVOID&)PlayerManager__GotKilledByPlayer_f, PlayerManager__GotKilledByPlayer);
	//a->remove(&(PVOID&)AntiCheat_Boost__OnAnyoneDeath_f, AntiCheat_Boost__OnAnyoneDeath);
	//a->remove(&(PVOID&)SpectatorControllerOnAnyoneDeath_f, SpectatorControllerOnAnyoneDeath);
	a->remove(&(PVOID&)AntiCheat__TakeAction_f, AntiCheat__TakeAction);

	a->remove(&(PVOID&)UnityEngine_Networking_UnityWebRequest__Get_f, UnityEngine_Networking_UnityWebRequest__Get);
	a->remove(&(PVOID&)UnityEngine_Networking_UnityWebRequest__Post_f, UnityEngine_Networking_UnityWebRequest__Post);

	a->remove(&(PVOID&)MyceliumPlayer__get_HasModeratorAuthority_f, MyceliumPlayer__get_HasModeratorAuthority);

}
void g::G_OffsetsAndHooks()
{
	hook* a = nullptr;

	a->get_bytes((void*)PlayerController_Fire_Delay, 5, PlayerController_Fire_Delay_orgbytes);
	a->get_bytes((void*)PlayerController_Fire_Recoil, 5, PlayerController_Fire_Recoil_orgbytes);
	a->get_bytes((void*)PlayerController_Fire_Effect, 5, PlayerController_Fire_Effect_orgbytes);

	if (v::invincibility.isEnabled()) {
		a->write_addr(PlayerController_Die, "\xC3", 1); //write a return instruction at the beginning of PlayerController::Die() (invincibility)
	}
	if (v::no_fire_delay.isEnabled()) {
		a->nop(PlayerController_Fire_Delay); //no fire delay
	}
	if (v::visual_recoil.isEnabled()) {
		a->nop(PlayerController_Fire_Recoil); //no visual recoil
	}
	if (v::fire_effect.isEnabled()) {
		a->nop(PlayerController_Fire_Effect); //no visual recoil
	}
}