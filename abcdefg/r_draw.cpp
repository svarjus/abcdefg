
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

	if (GetAsyncKeyState(VK_NUMPAD0) & 1) {
		for (int i = 0; i < AlivePlayers; i++) {

			for (int j = 0; j < 32; j++) {
				const uint64_t compList = (uint64_t)players[i]->ComponentList;
				const uint64_t tranform = getComponentById(compList, j);

				std::cout << "player[" << i << "] at: 0x" << std::hex << tranform << '\n';
			}
			std::cout << '\n';
		}
	}

	if (AlivePlayers > 0) {


		G_SetWeaponData();
		R_DrawThroughWalls();
		Mod_DrawCoordinates();

	}


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