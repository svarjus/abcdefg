
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


	//G_SetVariables();

	
	if (&PlayerTransform != nullptr && fnGetMainCamera() && tpcoords) {
		vec3_t out;
		tpcoords[1] += 0.75;
		WorldToScreen((uint64_t)fnGetMainCamera(), tpcoords, out); {
			ImGui::GetBackgroundDrawList()->AddCircle(ImVec2(out[0], r::X(1080.f) - out[1]), 30, IM_COL32(0, 255, 0, 255), 10, 1.f);
		}
	}

	if (GetAsyncKeyState(VK_HOME) & 1) {
		if (!PlayerController.object->static_fields->LocalPlayer->items) {
			std::cout << "weapon[0] is invalid\n";
		}
		else {
			std::cout << "weapon[0] is valid!\n";
			std::cout << PlayerController.object->static_fields->LocalPlayer->items << '\n';
		}

	}

	R_EndRender();

	return pEndScene(p_swap_chain, sync_interval, flags);
}