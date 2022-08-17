#include "pch.h"

MODULEINFO getModuleInfo(char* szModule);


void g::G_SetVariables()
{
	if (!g::hasPlayerController)
		return;

	PlayerController.klass->static_fields->LocalPlayer->bulletSpread = 0;
	for (int i = 0; i < 3; i++) {
		PlayerController.klass->static_fields->LocalPlayer->items->elements[i].item->info->magazineSize = 9999;
		PlayerController.klass->static_fields->LocalPlayer->items->elements[i].item->info->damage = 9999;
		PlayerController.klass->static_fields->LocalPlayer->items->elements[i].item->info->startingAmmo = 9999;

		PlayerController.klass->static_fields->LocalPlayer->items->elements[i].item->ammo.setValue(88888);

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

	a->write_addr((GameAssembly + 0x27AB90), "\xC3", 1); //write a return instruction at the beginning of PlayerController::Die()
	
}