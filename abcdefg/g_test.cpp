#include "pch.h"

MODULEINFO getModuleInfo(char* szModule);

void g::G_TestFunction()
{
	while (!false){

		if (GetAsyncKeyState(VK_INSERT) & 1) {
			hook* a = nullptr;

			BYTE buffer[3];
			a->get_bytes((void*)(GameAssembly + 0x1B85490), 3, buffer);
			std::cout << "bytes before: " << (uint16_t)buffer[0] << '|' << (uint16_t)buffer[1] << '|' << (uint16_t)buffer[2] << '\n';
			buffer[0] += 1;
			a->write_addr((void*)(GameAssembly + 0x1B85490), &buffer[0], 1);

			a->get_bytes((void*)(GameAssembly + 0x1B85490), 3, buffer);
			std::cout << "bytes after: " << (uint16_t)buffer[0] << '|' << (uint16_t)buffer[1] << '|' << (uint16_t)buffer[2] << '\n';

			if (fnIl2cpp_resolve_icall) {
				std::cout << "fnIl2cpp_resolve_icall is valid! - " << fnIl2cpp_resolve_icall << '\n';
			}
			else {
				std::cout << "fnIl2cpp_resolve_icall is not valid!\n";
				break;
			}
			MODULEINFO _module = getModuleInfo((char*)"GameAssembly.dll");
			PlayerController = (PlayerController_c*)absoluteAddress(findPattern(PATTERN_PLAYERCONTROLLER, MASK_PLAYERCONTROLLER, _module), 3);

			uintptr_t pcontroller = (GameAssembly + 0x12B0040) + 0x16E4088;
			std::cout << "pcontroller: " << std::hex << pcontroller << '\n';
		
			if (!PlayerController) {
				std::cout << "playercontroller nullptr!\n";
				return;
			}
		}

		//Sleep(10);

		if (PlayerController)
			if(PlayerController->klass->static_fields->LocalPlayer)
				PlayerController->klass->static_fields->LocalPlayer->bulletSpread = 1000.f;

	}
}
