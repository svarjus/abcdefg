#include "pch.h"

MODULEINFO getModuleInfo(char* szModule);


void g::G_SetVariables()
{
	if (!g::hasPlayerController)
		return;

	PlayerController_fields* LocalPlayer = PlayerController.klass->static_fields->LocalPlayer;

	PlayerController.klass->static_fields->LocalPlayer->bulletSpread = 360;
	for (int i = 0; i < 3; i++) {
		LocalPlayer->items->elements[i].item->info->magazineSize = 9999;
		LocalPlayer->items->elements[i].item->info->damage = 9999;
		LocalPlayer->items->elements[i].item->info->startingAmmo = 9999;

		LocalPlayer->items->elements[i].item->ammo.setValue(88888);
		LocalPlayer->items->elements[i].item->info->noscope = true;
		LocalPlayer->items->elements[i].item->info->cameraADSBobMultiplier = 0;



	}
	if (GetAsyncKeyState(VK_HOME) & 1) {
		std::cout << "LocalPlayer->items->elements[0].item->info: " << LocalPlayer->items->elements[0].item->info << '\n';
	}
}
void g::G_Init()
{
	static bool once = true;

	if (!once)
		return;
	
	once = false;
	fnIl2cpp_resolve_icall = (tpIl2cpp_resolve_icall*)GetProcAddress((HMODULE)gAssembly.lpBaseOfDll, EXPORT_IL2CPP_RESOLVE_ICALL);

	hook* a = nullptr;
	BYTE buffer[3]{};


	a->get_bytes((void*)(GameAssembly + 31647208), 3, buffer);
	std::cout << "bytes before: " << (uint16_t)buffer[0] << '|' << (uint16_t)buffer[1] << '|' << (uint16_t)buffer[2] << '\n';
	buffer[0] += 1;
	a->write_addr((void*)(GameAssembly + 31647208), &buffer[0], 1);

	a->get_bytes((void*)(GameAssembly + 31647208), 3, buffer);
	std::cout << "bytes after: " << (uint16_t)buffer[0] << '|' << (uint16_t)buffer[1] << '|' << (uint16_t)buffer[2] << '\n';


	a->install_x64(&(PVOID&)Reload_h, Reload);

	a->nop((GameAssembly + 0x27BCDA));

	//DetourTransactionBegin();
	//DetourAttach(&(PVOID&)Reload_h, Reload);
	//DetourTransactionCommit();
	
//	a->write_addr((GameAssembly + 0x27AB90), "\xC3", 1); //write a return instruction at the beginning of PlayerController::Die()
	
}
