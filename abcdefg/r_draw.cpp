
#include "pch.h"
LRESULT __stdcall g::WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	if (ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam) && GetKeyState(MENU_KEY) == true)
		return 1l;

	switch (uMsg) {
	case WM_SYSCOMMAND:
		if ((wParam & 0xfff0) == SC_KEYMENU)
			return 0;
		break;
	case WM_DESTROY:
		ImGui_ImplDX11_InvalidateDeviceObjects();
	}

	return CallWindowProcA(oWndProc, hWnd, uMsg, wParam, lParam);
}

long __stdcall g::D3D_Draw(IDXGISwapChain* p_swap_chain, UINT sync_interval, UINT flags)
{
	R_GetID3D11_Device(p_swap_chain);


	R_OpenMenu();


	G_SetVariables();

	if (&PlayerController != nullptr) {


		if (PlayerController.object) {
			//PlayerController_fields* LocalPlayer = PlayerController.object->static_fields->LocalPlayer;
			//PlayerController.klass->static_fields->LocalPlayer->bulletSpread = vars::spread_angle.floatValue;

			const bool keyPressed = GetAsyncKeyState(VK_DELETE) & 1;

			if (keyPressed) {
				int* code = ((int* (*)())(GameAssembly + 6500560))();
				int _codeArray[4];
				for (int i = 0; i < 4; i++)
					_codeArray[i] = code[8 + i];

				
				std::cout << "returns: 0x" << std::hex << code << '\n';

				for (int i = 0; i < 4; i++)
					std::cout << std::dec << _codeArray[i];

				std::cout << '\n';
				//if (LocalPlayer->spotLight) {
				//	std::cout << "LocalPlayer->spotLight: 0x" << std::hex << &LocalPlayer->spotLight << '\n';
				//}
				//else
				//	std::cout << "localplayer->spotLight invalid\n";
			}

			if (vars::random_esp.enabled) {
				if (&PlayerTransform != nullptr && fnGetMainCamera() && _tp.tpcoords) {
					vec3_t out;
					_tp.tpcoords[1] += 0.75;
					WorldToScreen((uint64_t)fnGetMainCamera(), _tp.tpcoords, out); {
						ImGui::GetBackgroundDrawList()->AddCircle(ImVec2(out[0], r::X(1080.f) - out[1]), 30, IM_COL32(0, 255, 0, 255), 10, 1.f);
					}
				}
			}
		}
	}

	R_EndRender();

	return pEndScene(p_swap_chain, sync_interval, flags);
}