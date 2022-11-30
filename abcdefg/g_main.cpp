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
	WorldToScreenPoint								= (vec3(*)(void* camera, vec3 position))(GameAssembly + 14259792); //UnityEngine.Camera$$WorldToScreenPoint


	//gameassembly hooks
	Update_h										= (void(*)(g::PlayerController_c*))(GameAssembly + 4440480);			//PlayerController$$Update
	PrintChat_f										= (intptr_t(*)(intptr_t * a1, textobject * a2, uint32_t a3, char a4, intptr_t a5))(GameAssembly + 4076240);   //ChatManager$$SendChatMessage
	OutskirtsCodeGenerator__get_Code				= (uintptr_t)(GameAssembly + 4393504);									//OutskirtsCodeGenerator$$get_Code
	MyceliumNetwork$$get_LocalPlayer				= (uintptr_t)(GameAssembly + 2726800);									//MyceliumNetwork$$get_LocalPlayer

	//unity engine hooks
	UE_PlayerTransform_h							= (uint32_t(*)(void*, void*, float, void*))			(UnityPlayer + 0x10C08E0);
	PlayerInfo_f									= (void(*)(float*, DWORD*))							(UnityPlayer + 0x10B8B60);
	PlayerData_f									= (char(*)(uintptr_t * a1, float* a2, char a3))		(UnityPlayer + 0x07FDB0);

	PlayerController_Die							= (GameAssembly + 4409904);			//PlayerController$$Die
	PlayerController_Fire_Delay						= (GameAssembly + 4414112 + 0x137);	//PlayerController$$Fire + 0x137
	PlayerController_Fire_Recoil					= (GameAssembly + 4414112 + 0x23D);  //PlayerController$$Fire + 0x23D			--> StressReceiver.InduceStress
	PlayerController_Fire_Effect					= (GameAssembly + 4412608 + 279);   // PLayerController$$FireLocal + 279		--> Item.Fire

	SteamDLCManager__HasDLC_h						= (bool(*)(int32_t dlc))(g::GameAssembly + 2963200); //SteamDLCManager$$HasDLC

	OutskirtsKeyPad_Press_f							= (void(*)(void* keypad, int num, const MethodInfo * method))(GameAssembly + 4394768); //OutskirtsKeypad$$Press
	
}
void g::G_InitHooks()
{
	hook* a = nullptr;

	a->install(&(PVOID&)Update_h, PlayerController_Update);
	a->install(&(PVOID&)UE_PlayerTransform_h, UE_PlayerTransform);
	a->install(&(PVOID&)PlayerInfo_f, UE_PlayerInfo);
	a->install(&(PVOID&)PrintChat_f, PrintChat);
	a->install(&(PVOID&)OutskirtsKeyPad_Press_f, OutskirtsKeyPad_Press);
	//a->install(&(PVOID&)PlayerData_f, UE_PlayerData);

}
void g::G_RemoveHooks()
{
	hook* a = nullptr;

	a->remove(&(PVOID&)Update_h, PlayerController_Update);
	a->remove(&(PVOID&)UE_PlayerTransform_h, UE_PlayerTransform);
	a->remove(&(PVOID&)PlayerInfo_f, UE_PlayerInfo);
	a->remove(&(PVOID&)PrintChat_f, PrintChat);
	a->remove(&(PVOID&)OutskirtsKeyPad_Press_f, OutskirtsKeyPad_Press);
	a->remove(&(PVOID&)PlayerData_f, UE_PlayerData);

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