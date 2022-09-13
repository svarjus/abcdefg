
#include "pch.h"
LRESULT __stdcall g::WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	if (ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam) || GetKeyState(MENU_KEY) == true)
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
typedef void(*AchievementEvaluator_LearningTheABCs__OnKill_h)(void* obj_ptr, uintptr_t obj_ptr2);
AchievementEvaluator_LearningTheABCs__OnKill_h AchievementEvaluator_LearningTheABCs__OnKill_f = (AchievementEvaluator_LearningTheABCs__OnKill_h)(g::GameAssembly + 19604144);
//D0 55 1E 98 48 02 00 00 00 00 00 00 00 00 00 00
void AchievementEvaluator_LearningTheABCs__OnKill(void* obj_ptr, uintptr_t obj_ptr2)
{
	//std::cout << "AchievementEvaluator_LearningTheABCs_o*: 0x" << std::hex << obj_ptr << '\n';

	//int32_t val = AchievementEvaluator_LearningTheABCs__get_achievement_f(obj_ptr);
	//const bool keyPressed = GetAsyncKeyState(VK_PRIOR) & 1;
	//if (keyPressed)
	//	std::cout << "AchievementEvaluator_LearningTheABCs__get_achievement(): " << val << '\n';
	std::cout << "AchievementEvaluator_LearningTheABCs__OnKill()\n";
	return/* AchievementEvaluator_LearningTheABCs__OnKill_f(obj_ptr, obj_ptr2)*/;
}
typedef bool(*SteamDLCManager__HasDLC_h)(int32_t dlc);
SteamDLCManager__HasDLC_h SteamDLCManager__HasDLC_f = (SteamDLCManager__HasDLC_h)(g::GameAssembly + 20156832);

bool SteamDLCManager__HasDLC(int32_t dlc)
{
	return true;
}
long __stdcall g::D3D_Draw(IDXGISwapChain* p_swap_chain, UINT sync_interval, UINT flags)
{
	R_GetID3D11_Device(p_swap_chain);

	static bool once = true;

	if (once) {
		once = false;
		hook* a = nullptr;
		std::cout << "hook it\n";
		a->install(&(PVOID&)SteamDLCManager__HasDLC_f, SteamDLCManager__HasDLC);
	}

	R_OpenMenu();
	G_SetVariables();

	const bool keyPressed = GetAsyncKeyState(VK_DELETE) & 1;

	if (keyPressed) {

		//int* code = ((int* (*)())(GameAssembly + 3905472))(); //System_Int32_array* OutskirtsCodeGenerator__get_Code (const MethodInfo* method);
		//int _codeArray[4];
		//for (int i = 0; i < 4; i++)
		//	_codeArray[i] = code[8 + i];
		//for (int i = 0; i < 4; i++)
		//	std::cout << std::dec << _codeArray[i];

		//if (&PlayerController) {
		//	std::cout << "yep: 0x" << std::hex << &PlayerController << '\n';
		//}
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

	R_EndRender();

	return pEndScene(p_swap_chain, sync_interval, flags);
}