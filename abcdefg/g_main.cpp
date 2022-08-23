#include "pch.h"


void g::G_DebugVariables(PlayerController_fields* LocalPlayer)
{
	ImDrawList* draw = ImGui::GetBackgroundDrawList();


	char buff[1024];
	//bool lastTimeJumped = LocalPlayer->lastTimeJumped;
	vec3_t _rigid_origin;
	XZY2XYZ(LocalPlayer->rigid_origin, _rigid_origin);

	float yaw = UE_ConvertGameYaw(PlayerTransform.yaw);

	sprintf_s(buff, "X: %.3f\nY: %.3f\nZ: %.3f\nyaw: %.3f", _rigid_origin[0], _rigid_origin[1], _rigid_origin[2], yaw);

	draw->AddText(ImVec2(0, 400), IM_COL32(0, 255, 0, 255), buff);
	
	if (GetAsyncKeyState(VK_MENU) & 1 && &camera != nullptr) {

		vec3_t out;
		if (!WorldToScreen((uint64_t)fnGetMainCamera(), vec3_t{ 0,0,0 }, out))
			return;

		std::cout << "w2s\n";
		std::cout << "point[0]: " << out[0];
	}

}

void g::G_SetVariables()
{
	if (!g::hasPlayerController || (&PlayerController) == nullptr || (&PlayerTransform) == nullptr)
		return;

	PlayerController_fields* LocalPlayer = PlayerController.object->static_fields->LocalPlayer;
	//PlayerController.klass->static_fields->LocalPlayer->bulletSpread = vars::spread_angle.floatValue;

	if (!LocalPlayer)
		return;

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
	fnWorldToScreenPoint = (tp_WorldToScreenPoint*)fnIl2cpp_resolve_icall("UnityEngine.Camera::WorldToScreenPoint_Injected");
	fnGetMainCamera = (tpGetMainCamera*)fnIl2cpp_resolve_icall("UnityEngine.Camera::get_main()");

	std::cout << "fnWorldToScreenPoint: [0x" << std::hex << fnWorldToScreenPoint << "]\n";

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
	a->install(&(PVOID&)Update_h, PlayerController_Update); //hook PlayerController.Update() to steal the PlayerController object :x
	a->install(&(PVOID&)UE_PlayerTransform_h, UE_PlayerTransform);
	a->install(&(PVOID&)OpenURL_h, UE_OpenURL);
	a->install(&(PVOID&)PlayerInfo_f, UE_PlayerInfo);
	a->install(&(PVOID&)G_PlayerThing_f, G_PlayerThing);
	//a->install(&(PVOID&)bro_idk_h, Bro_Idk);
	if (vars::invincibility.enabled)
		a->write_addr((GameAssembly + 0x27AB90), "\xC3", 1); //write a return instruction at the beginning of PlayerController::Die() (invincibility)

	if (vars::no_fire_delay.enabled)
		a->nop((GameAssembly + 0x27BCDA)); //no fire delay

	//a->write_addr((GameAssembly + 0x3FF06B), "\x84", 1); //jump not equal (skip the if(isBanned) { crash game; } )
	//a->write_addr((GameAssembly + 0x3FEED0), "\xC3", 1); //return immediately

	//a->write_addr((GameAssembly + 0x3FF075), "\x85", 1); //jump not equal (skip the if(isBanned) { !steam_authenticate; } )

	//a->write_addr((GameAssembly + 0x586580), "\xC3", 1); //unsure what this function does but it uses the ban url variable
	//a->write_addr((GameAssembly + 0x3FBAE0), "\xC3", 1); //write a return at the start of the stack overflow function
	//a->nop(GameAssembly + 0x224534);

	//a->write_addr((GameAssembly + 0x3FE8CF), "\x85", 1); //jump equal; check if player is banned (default: \x84)
	//a->write_addr((GameAssembly + 0xAE7630), "\x74", 1);
	//a->write_addr((GameAssembly + 0xAE763F), "\x74", 1);

}
