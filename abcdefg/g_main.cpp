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
	WorldToScreenPoint								= (vec3(*)(void* camera, vec3 position))(GameAssembly + 14300496); //UnityEngine.Camera$$WorldToScreenPoint


	//gameassembly hooks
	Update_h										= (void(*)(g::PlayerController_c*))(GameAssembly + 4593264);			//PlayerController$$Update
	PrintChat_f										= (intptr_t(*)(intptr_t * a1, textobject * a2, uint32_t a3, char a4, intptr_t a5))(GameAssembly + 3873824);   //ChatManager$$SendChatMessage
	OutskirtsCodeGenerator__get_Code				= (uintptr_t)(GameAssembly + 4545952);									//OutskirtsCodeGenerator__get_Code
	MyceliumNetwork$$get_LocalPlayer				= (uintptr_t)(GameAssembly + 3993360);									//MyceliumNetwork$$get_LocalPlayer

	//unity engine hooks
	UE_PlayerTransform_h							= (uint32_t(*)(void*, void*, float, void*))			(UnityPlayer + 0x10C08E0);
	PlayerInfo_f									= (void(*)(float*, DWORD*))							(UnityPlayer + 0x10B8B60);

	PlayerController_Die							= (GameAssembly + 4562016);			//PlayerController$$Die
	PlayerController_Fire_Delay						= (GameAssembly + 4566576 + 0x137);	//PlayerController$$Fire + 0x149


	SteamDLCManager__HasDLC_h						= (bool(*)(int32_t dlc))(g::GameAssembly + 2687056); //SteamDLCManager$$HasDLC

}
void g::G_InitHooks()
{
	hook* a = nullptr;

	a->install(&(PVOID&)Update_h, PlayerController_Update);
	a->install(&(PVOID&)UE_PlayerTransform_h, UE_PlayerTransform);
	a->install(&(PVOID&)PlayerInfo_f, UE_PlayerInfo);
	a->install(&(PVOID&)PrintChat_f, PrintChat);

}
void g::G_RemoveHooks()
{
	hook* a = nullptr;

	a->remove(&(PVOID&)Update_h, PlayerController_Update);
	a->remove(&(PVOID&)UE_PlayerTransform_h, UE_PlayerTransform);
	a->remove(&(PVOID&)PlayerInfo_f, UE_PlayerInfo);
	a->remove(&(PVOID&)PrintChat_f, PrintChat);
}
void g::G_OffsetsAndHooks()
{
	hook* a = nullptr;

	a->get_bytes((void*)PlayerController_Fire_Delay, 5, PlayerController_Fire_Delay_orgbytes);

	if (v::invincibility.isEnabled()) {
		a->write_addr(PlayerController_Die, "\xC3", 1); //write a return instruction at the beginning of PlayerController::Die() (invincibility)
	}
	if (v::no_fire_delay.isEnabled()) {
		a->nop(PlayerController_Fire_Delay); //no fire delay
	}

}