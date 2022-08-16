#include "pch.h"

MODULEINFO getModuleInfo(char* szModule);

typedef void(*Reload_hook)(g::PlayerController_c*);
static void(*Reload_h)(g::PlayerController_c*) = (Reload_hook)(g::GameAssembly + 0x27BBA0);
void Reload(g::PlayerController_c* playercontroller)
{
	//memcpy(g::PlayerController, &playercontroller, sizeof(playercontroller));
	if (playercontroller) {
		std::cout << "playerController: 0x" << std::hex << playercontroller << '\n';
		playercontroller->klass->static_fields->LocalPlayer->bulletSpread = 100;
		std::cout <<  playercontroller->klass->static_fields->LocalPlayer->bulletSpread << '\n';
	}

	return Reload_h(playercontroller);
}


void g::G_TestFunction()
{
	hook* a = nullptr;
	//Reload_h = (Reload_hook)(GameAssembly + 0x27BBA0);

	DetourTransactionBegin();
	DetourAttach(&(LPVOID&)Reload_h, Reload);
	DetourTransactionCommit();

	while (!false){

		static bool toggleFPS;

		if (GetAsyncKeyState(VK_INSERT) & 1) {
			toggleFPS = !toggleFPS;
			//std::cout << "toggleFPS: " << toggleFPS << '\n';
			//const tpQuit* quit = (tpQuit*)fnIl2cpp_resolve_icall(EXPORT_QUIT);
			//if (quit) {
			//	quit(1);
			//}
			//else std::cout << "il2cpp call invalid!\n";

			//PlayerController_c* pc = reinterpret_cast<PlayerController_c*>(GameAssembly + 0x284420);

			//std::cout << "R11: " << std::hex << "0x" << a->find_pattern(GameAssembly, std::numeric_limits<uintptr_t>::max(), "80 2F 16 70 F4 01 00 00 E0 91 29 D0") << '\n'; //R11 register

			 MODULEINFO ah{};
			 ah.lpBaseOfDll = (void*)(0x10000000000);
			 ah.SizeOfImage = 0x16B58230360;

			 
			
			//uintptr_t ptr = a->find_pattern(0x10000000000, 0x16B58230360, "\x00\x01\x00\x00\xE0\x91");

			//std::cout << "R11_mask: " << std::hex << "0x" << findPattern((char*)"\x80\x2F\x16\x70\xF4\x01\x00\x00\xE0\x91\x29\xD0", (char*)"xxx??xxxxx??", 0, 0x26B58230360) << '\n'; //R11 register


			//findPattern((char*)"\x80\x2F\x16\x70\xF4\x01\x00\x00\xE0\x91\x29\xD0", (char*)"xxx??xxxxxxx", gAssembly);
			//if (pc) {
			//	std::cout << "WOW! (" << pc << ")\n";
			//	((void(*)(PlayerController_c*))(GameAssembly + 2619504))(pc);
			//}
			//else std::cout << "no\n";

		}
		//if (PlayerController) {
		//	PlayerController->klass->static_fields->LocalPlayer->bulletSpread = 10;
		//}
		//if (toggleFPS) {
		//	((void(*)(void*, float))(GameAssembly + 2621200))((void*)(GameAssembly + 0x284420), 90);
		//	//const tpSetFPS* gameobject = (tpSetFPS*)fnIl2cpp_resolve_icall(EXPORT_LIMITFRAMERATE);
		//	//gameobject(10);
		//}
		////Sleep(10);

	}
}
