#include "pch.h"


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
			PC_GetHealth* get_health = (PC_GetHealth*)fnIl2cpp_resolve_icall("PlayerController::get_health()");
			PlayerController_c controller;

			if (get_health)
				std::cout << "window width: " << get_health(&controller) << '\n';
			else std::cout << "with is invalid!\n";
		}

		Sleep(10);

	}
}