
#include "pch.h"
LRESULT __stdcall g::WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	if (ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam))
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
void g::R_MainLoop()
{
	//imgui drawing can be used in this function
	const int AlivePlayers = GetAlivePlayers();

	//if (GetAsyncKeyState(VK_NUMPAD0) & 1) {
	//	((void(*)(PlayerController_c * pc, bool grounded, UnityEngine_Transform_o * groundedTransform))());
	//}

	if (AlivePlayers > 0) {

		if (GetAsyncKeyState(VK_NUMPAD5) & 1) {

			//if (outskirts_keypad_obj && outskirts_method) {
			//	std::cout << "outskirts_keypad_obj: " << outskirts_keypad_obj << '\n';
			//	std::cout << "outskirts_method: " << outskirts_method << '\n';

			//	OutskirtsKeyPad_Press_f(outskirts_keypad_obj, 1, outskirts_method);

			//}

			//TimeoutManager_o* timeout = (TimeoutManager_o*)(GameAssembly + 0x1BF8C10);
			//if (timeout) {

			//	TimeoutManager_StaticFields* timeout_sf =  timeout->klass->static_fields;

			//	if (timeout_sf) {

			//		std::cout << "mutedText: " << ResolveSystemString(timeout_sf->MutedText) << '\n';

			//	}
			//		//std::cout << "spam limiter: " << _cm->fields.spamLimiter << '\n';
			//	
			//}
		}
		//G_SetWeaponData();
		R_DrawThroughWalls();
		Mod_DrawCoordinates();


	}

	BypassAntiCheat();


}
long __stdcall g::D3D_Draw(IDXGISwapChain* p_swap_chain, UINT sync_interval, UINT flags)
{
	R_GetID3D11_Device(p_swap_chain);


	R_OpenMenu();
	GetAllPlayers();
	R_MainLoop();

	R_EndRender();

	return pEndScene(p_swap_chain, sync_interval, flags);
}

void g::R_DrawThroughWalls()
{
	if (!v::random_esp.isEnabled())
		return;

	vec3_t org;
	for (auto& i : players) {

		GetPlayerOrigin(i, org);

		const vec3 a(org[0], org[1], org[2]);

		const vec3 out = WorldToScreenPoint((uintptr_t*)fnGetMainCamera(), a);

		if (out.z >= 1.f) {
			const float y = (float)((int(*)())g::fnIl2cpp_resolve_icall(UE_GET_HEIGHT))();
			//ImGui::GetBackgroundDrawList()->AddCircleFilled(ImVec2(out.x, r::Y(y - out.y)), 30, IM_COL32(0, 255, 0, 255));

			const g::box_s box(org, vec3_t{ .4f,.75f,.4f }, vec3_t{ .4f,.75f,.4f });
			box.R_DrawConstructedBoxEdges(vec4_t{ 255,0,0,255 });
			box.R_DrawConstructedBox(vec4_t{ 255,0,0,55 });
		}

	}

}