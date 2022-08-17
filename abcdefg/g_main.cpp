#include "pch.h"


void g::G_SetVariables()
{
	if (!g::hasPlayerController)
		return;

	const PlayerController_fields* LocalPlayer = PlayerController.klass->static_fields->LocalPlayer;
	PlayerController.klass->static_fields->LocalPlayer->bulletSpread = vars::spread_angle.floatValue;
	for (int i = 0; i < 3; i++) {
		const ItemPointer element = LocalPlayer->items->elements[i];

		element.item->info->magazineSize = 9999;
		element.item->info->damage = 9999;
		element.item->info->startingAmmo = 9999;
		element.item->info->shots = 99999;
		element.item->info->cameraADSBobMultiplier = 0;



	}

}
void g::G_Init()
{
	static bool once = true;

	if (!once)
		return;
	
	once = false;
	fnIl2cpp_resolve_icall = (tpIl2cpp_resolve_icall*)GetProcAddress((HMODULE)GameAssembly, EXPORT_IL2CPP_RESOLVE_ICALL);

	hook* a = nullptr;
	BYTE buffer[3]{};

	//replace the cheat engine string with something else
	a->get_bytes((void*)(GameAssembly + 31647208), 3, buffer);
	std::cout << "bytes before: " << (uint16_t)buffer[0] << '|' << (uint16_t)buffer[1] << '|' << (uint16_t)buffer[2] << '\n';
	buffer[0] += 1;
	a->write_addr((void*)(GameAssembly + 31647208), &buffer[0], 1);

	a->get_bytes((void*)(GameAssembly + 31647208), 3, buffer);
	std::cout << "bytes after: " << (uint16_t)buffer[0] << '|' << (uint16_t)buffer[1] << '|' << (uint16_t)buffer[2] << '\n';


	a->install(&(PVOID&)Reload_h, Reload);

	if (vars::invincibility.enabled)
		a->write_addr((GameAssembly + 0x27AB90), "\xC3", 1); //write a return instruction at the beginning of PlayerController::Die() (invincibility)

	if (vars::no_fire_delay.enabled)
		a->nop((GameAssembly + 0x27BCDA)); //no fire delay
	
}
