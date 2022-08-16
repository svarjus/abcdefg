#include "pch.h"

MODULEINFO getModuleInfo(char* szModule);

typedef void(*Reload_hook)(g::PlayerController_c*);
static void(*Reload_h)(g::PlayerController_c*) = (Reload_hook)(g::GameAssembly + 0x27BBA0);

static bool hasPController;

void Reload(g::PlayerController_c* playercontroller)
{
	
	memcpy(&g::PlayerController, playercontroller, sizeof(playercontroller));
	if (playercontroller) {
	//	std::cout << "playerController: 0x" << std::hex << playercontroller << '\n';
	//	playercontroller->klass->static_fields->LocalPlayer->bulletSpread = 100;
		std::cout <<  playercontroller->klass->static_fields->LocalPlayer->bulletSpread << '\n';
	}
	hasPController = true;
	return Reload_h(playercontroller);
}

typedef void(*isOwned_hook)(void*);
static void(*isOwned_f)(void*) = (isOwned_hook)(g::GameAssembly + 2983184);
bool Unlockable_BulletEffect__IsOwned(void* s)
{
	std::cout << "yep this is definitely owned\n";

	return true;
}

void g::G_TestFunction()
{
	hook* a = nullptr;
	//Reload_h = (Reload_hook)(GameAssembly + 0x27BBA0);

	DetourTransactionBegin();
	DetourAttach(&(LPVOID&)Reload_h, Reload);
	DetourTransactionCommit();

	DetourTransactionBegin();
	DetourAttach(&(LPVOID&)isOwned_f, Unlockable_BulletEffect__IsOwned);
	DetourTransactionCommit();

	while (!false){

		static bool toggleFPS;

		if (GetAsyncKeyState(VK_INSERT) & 1) {
			toggleFPS = !toggleFPS;

			 
			if (hasPController) {
				((void(*)(PlayerController_c * pc))(GameAssembly + 2599824))(&PlayerController);
			}


		}
		if (hasPController) {
			PlayerController.klass->static_fields->LocalPlayer->bulletSpread = 100;
		}
		//if (toggleFPS) {
		//	((void(*)(void*, float))(GameAssembly + 2621200))((void*)(GameAssembly + 0x284420), 90);
		//	//const tpSetFPS* gameobject = (tpSetFPS*)fnIl2cpp_resolve_icall(EXPORT_LIMITFRAMERATE);
		//	//gameobject(10);
		//}
		////Sleep(10);

	}
}
