#include "pch.h"


void g::G_DebugVariables(PlayerController_c* LocalPlayer)
{
	ImDrawList* draw = ImGui::GetBackgroundDrawList();


	char buff[1024];
	//bool lastTimeJumped = LocalPlayer->lastTimeJumped;
	//vec3_t _rigid_origin;
	//XZY2XYZ(LocalPlayer->rigid_origin, _rigid_origin);

	float yaw = UE_ConvertGameYaw(PlayerTransform.yaw);

	sprintf_s(buff, "X: %.3f\nY: %.3f\nZ: %.3f\nyaw: %.3f", _tp.myCoords[0], _tp.myCoords[1], _tp.myCoords[2], yaw);

	draw->AddText(ImVec2(0, 400), IM_COL32(0, 255, 0, 255), buff);

}

void g::G_SetVariables()
{
	//if (!g::hasPlayerController || (&PlayerController) == nullptr || (&PlayerTransform) == nullptr)
	//	return;
	////PlayerController_fields* LocalPlayer = PlayerController.object->static_fields->LocalPlayer;
	//////PlayerController.klass->static_fields->LocalPlayer->bulletSpread = vars::spread_angle.floatValue;

	////const bool keyPressed = GetAsyncKeyState(VK_DELETE) & 1;

	//if (!&PlayerController)
	//	return;

	//if (!PlayerController.items)
	//	return;

	//for (int i = 0; i < PlayerController.items->count; i++) {
	//	const ItemPointer element = PlayerController.items->elements[i];

	//	if (!PlayerController.items->elements)
	//		continue;

	//	if (!&PlayerController.items->elements[i])
	//		continue;

	//	//element.item->info->damage = vars::weapon_damage.arrayValue[i];
	//	element.item->info->bulletSpread = vars::weapon_spread.arrayValue[i];
	//	element.item->info->maxBulletSpread = vars::weapon_spread.arrayValue[i];
	//	element.item->info->normalSpread = vars::weapon_spread.arrayValue[i];
	//	element.item->info->movementSpreadMultiplier =01;
	//	element.item->info->adsSpread = vars::weapon_spread.arrayValue[i];
	//	element.item->info->adsBulletSpread = vars::weapon_spread.arrayValue[i];
	//	element.item->info->bulletSpreadDecrease = 0;
	//	element.item->info->cameraADSBobMultiplier = 1;
	//	element.item->info->cameraADSBobMultiplier = 1;
	//	//element.item->info->kickback = 100;
	//	//element.item->bulletSpread = 360;

	//	element.item->totalAmmo.value = 9999;
	//	element.item->ammo.value = 9999;
	//	PlayerController.animationSmoothTime = 1.f;
	//	PlayerController.smoothTime = 1.f;

	//}
	////if (keyPressed) {
	////	std::cout << "&bulletspread: " element.item->bulletSpread << '\n';
	////}
	//G_DebugVariables(&PlayerController);
}
void g::G_Init()
{
	static bool once = true;

	if (!once)
		return;
	
	once = false;


	G_OffsetsAndHooks();

	hook* a = nullptr;
	//BYTE buffer[3]{};

	////replace the cheat engine string with something else
	//a->get_bytes((void*)(GameAssembly + 31647208), 3, buffer);
	//std::cout << "bytes before: " << (uint16_t)buffer[0] << '|' << (uint16_t)buffer[1] << '|' << (uint16_t)buffer[2] << '\n';
	//buffer[0] += 1;
	//a->write_addr((void*)(GameAssembly + 31647208), &buffer[0], 1);

	//a->get_bytes((void*)(GameAssembly + 31647208), 3, buffer);
	//std::cout << "bytes after: " << (uint16_t)buffer[0] << '|' << (uint16_t)buffer[1] << '|' << (uint16_t)buffer[2] << '\n';
	

}
//bool(*MyceliumBanManager__IsBanned_f)(int64_t);
//bool(*TimeoutManager__IsBanned_f)(int64_t);
//bool MyceliumBanManager__IsBanned(int64_t player)
//{
//	return false;
//}
//bool TimeoutManager__IsBanned(int64_t player)
//{
//	return false;
//}

void g::G_OffsetsAndHooks()
{
	hook* a = nullptr;

	//unity engine calls
	fnIl2cpp_resolve_icall = (tpIl2cpp_resolve_icall*)GetProcAddress((HMODULE)GameAssembly, EXPORT_IL2CPP_RESOLVE_ICALL);
	fnWorldToScreenPoint = (tp_WorldToScreenPoint*)fnIl2cpp_resolve_icall("UnityEngine.Camera::WorldToScreenPoint_Injected");
	fnGetMainCamera = (tpGetMainCamera*)fnIl2cpp_resolve_icall("UnityEngine.Camera::get_main()");


	//gameassembly hooks
	Update_h							= (Update_hook)(GameAssembly + 4593264); //PlayerController$$Update
	PrintChat_f							= (PrintChat_hook)(GameAssembly + 3873824);   //ChatManager$$SendChatMessage
	OutskirtsCodeGenerator__get_Code	= (uintptr_t)(GameAssembly + 4545952); //OutskirtsCodeGenerator__get_Code
	MyceliumNetwork$$get_LocalPlayer	= (uintptr_t)(GameAssembly + 3993360);  //MyceliumNetwork$$get_LocalPlayer
	PlayerController__OnKill_f			= (void(*)(PlayerController_c*, KillData_o*))(GameAssembly + 4578416); //PlayerController$$OnKill

	//unity engine hooks
	UE_PlayerTransform_h	= (UE_PlayerTransform_hook)	(UnityPlayer + 0x10C08E0);
	PlayerInfo_f			= (PlayerInfo_h)			(UnityPlayer + 0x10B8B60);

	//MyceliumBanManager__IsBanned_f	= (bool(*)(int64_t))	(GameAssembly + 3004624);
	//TimeoutManager__IsBanned_f		= (bool(*)(int64_t))	(GameAssembly + 3846864);

	PlayerController_Die = GameAssembly + 4562016; //PlayerController$$Die
	PlayerController_Fire_Delay = (GameAssembly + 4566576 + 0x137); //PlayerController$$Fire + 0x149
	a->get_bytes((void*)PlayerController_Fire_Delay, 5, PlayerController_Fire_Delay_orgbytes);

	printf("PlayerController__OnKill_f: (0x%p)\n", PlayerController__OnKill_f);


	a->install(&(PVOID&)Update_h, PlayerController_Update); //hook PlayerController.Update() to steal the PlayerController object :x
	a->install(&(PVOID&)UE_PlayerTransform_h, UE_PlayerTransform);
	a->install(&(PVOID&)PlayerInfo_f, UE_PlayerInfo);
	a->install(&(PVOID&)PrintChat_f, PrintChat);
	a->install(&(PVOID&)PlayerController__OnKill_f, PlayerController$$OnKill_);
	//a->install(&(PVOID&)MyceliumBanManager__IsBanned_f, MyceliumBanManager__IsBanned);
	//a->install(&(PVOID&)TimeoutManager__IsBanned_f, TimeoutManager__IsBanned);


	if (vars::invincibility.enabled) {

		if (!PlayerController_Die) {
			MessageBoxA(NULL, "failed to find pattern (invincibility)!", "ERROR", 0);
			exit(-1);
			return;
		}

		a->write_addr(PlayerController_Die, "\xC3", 1); //write a return instruction at the beginning of PlayerController::Die() (invincibility)
	}
	if (vars::no_fire_delay.enabled) {

		if (!PlayerController_Die) {
			MessageBoxA(NULL, "failed to find pattern (no fire delay)!", "ERROR", 0);
			exit(-1);
			return;
		}

		a->nop(PlayerController_Fire_Delay); //no fire delay
	}
	//a->write_addr(GameAssembly + 0x808540, "\xC3", 1);
	//48 89 5C 24 08 48 89 6C 24 10 48 89 74 24 18 48 89 7C 24 20 41 56 48 83 EC 20 48 8B 74 24 50 4C 8B F1 48 8B 0D 1F 0E 88
}