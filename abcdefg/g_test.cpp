#include "pch.h"

MODULEINFO getModuleInfo(char* szModule);

void g::G_TestFunction()
{
	while (!false){

		static bool toggleFPS;

		if (GetAsyncKeyState(VK_INSERT) & 1) {
			toggleFPS = !toggleFPS;
			std::cout << "toggleFPS: " << toggleFPS << '\n';
			//const tpQuit* quit = (tpQuit*)fnIl2cpp_resolve_icall(EXPORT_QUIT);
			//if (quit) {
			//	quit(1);
			//}
			//else std::cout << "il2cpp call invalid!\n";

			PlayerController_c* pc = reinterpret_cast<PlayerController_c*>(GameAssembly + 0x284420);

			if (pc) {
				std::cout << "WOW! (" << pc << ")\n";
				((void(*)(PlayerController_c*))(GameAssembly + 2619504))(pc);
			}
			else std::cout << "no\n";

		}
		//if (toggleFPS) {
		//	((void(*)(void*, float))(GameAssembly + 2621200))((void*)(GameAssembly + 0x284420), 90);
		//	//const tpSetFPS* gameobject = (tpSetFPS*)fnIl2cpp_resolve_icall(EXPORT_LIMITFRAMERATE);
		//	//gameobject(10);
		//}
		////Sleep(10);

	}
}
