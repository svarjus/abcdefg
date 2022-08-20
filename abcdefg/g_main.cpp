#include "pch.h"


void g::G_DebugVariables(PlayerController_fields* LocalPlayer)
{
	ImDrawList* draw = ImGui::GetBackgroundDrawList();


	char buff[1024];
	//bool lastTimeJumped = LocalPlayer->lastTimeJumped;
	vec3_t _rigid_origin;
	XZY2XYZ(LocalPlayer->rigid_origin, _rigid_origin);
	sprintf_s(buff, "X: %.3f\nY: %.3f\nZ: %.3f", _rigid_origin[0], _rigid_origin[1], _rigid_origin[2]);

	draw->AddText(ImVec2(0, 400), IM_COL32(0, 255, 0, 255), buff);
	
}

void g::G_SetVariables()
{
	if (!g::hasPlayerController)
		return;

	PlayerController_fields* LocalPlayer = PlayerController.object->static_fields->LocalPlayer;
	//PlayerController.klass->static_fields->LocalPlayer->bulletSpread = vars::spread_angle.floatValue;

	bool keyPressed = GetAsyncKeyState(VK_DELETE) & 1;
	for (int i = 0; i < 3; i++) {
		const ItemPointer element = LocalPlayer->items->elements[i];

		element.item->info->damage = vars::weapon_damage.arrayValue[i];
		element.item->info->bulletSpread = vars::weapon_spread.arrayValue[i];
		element.item->info->maxbulletSpread = vars::weapon_spread.arrayValue[i];
		element.item->info->normalSpread = vars::weapon_spread.arrayValue[i];
		element.item->info->movementSpreadMultiplier = 0;
		element.item->info->adsSpread = vars::weapon_spread.arrayValue[i];
		element.item->info->adsBulletSpread = vars::weapon_spread.arrayValue[i];
		element.item->info->bulletSpreadDecrease = 0;
		element.item->info->cameraADSBobMultiplier = 0;
		element.item->info->cameraADSBobMultiplier = 0;
		element.item->totalAmmo.value = 9999;
		element.item->ammo.value = 9999;

	}
	if (keyPressed)
		std::cout << "&LocalPlayer->lastDamagePacketID: " << &LocalPlayer->lastDamagePacketID << '\n';
	G_DebugVariables(LocalPlayer);
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
	
	//a->nop((GameAssembly + 0x3FEBFC));
	a->install(&(PVOID&)Reload_h, Reload); //hook PlayerController.Reload() to steal the PlayerController object :x
	a->install(&(PVOID&)UE_PlayerTransform_h, UE_PlayerTransform);
	if (vars::invincibility.enabled)
		a->write_addr((GameAssembly + 0x27AB90), "\xC3", 1); //write a return instruction at the beginning of PlayerController::Die() (invincibility)

	if (vars::no_fire_delay.enabled)
		a->nop((GameAssembly + 0x27BCDA)); //no fire delay
	
}
