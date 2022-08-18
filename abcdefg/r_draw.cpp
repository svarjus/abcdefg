
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


	R_EndRender();
	
	//if (GetAsyncKeyState(VK_HOME) & 1) {
	//	//std::cout << "LocalPlayer->items->elements[0].item->info: " << LocalPlayer->items->elements[0].item->info << '\n';
	//	for (int i = 1; i < 10; i++)
	//		((void(*)(int32_t a))(GameAssembly + 3347664))(i);
	//}

	return pEndScene(p_swap_chain, sync_interval, flags);
}