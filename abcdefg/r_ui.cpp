
#include "pch.h"


void g::R_MenuStyle()
{
	ImGuiStyle* style = &ImGui::GetStyle();

	style->WindowPadding = ImVec2(15, 15);
	style->WindowRounding = 5.0f;
	style->FramePadding = ImVec2(5, 5);
	style->FrameRounding = 4.0f;
	style->ItemSpacing = ImVec2(12, 8);
	style->ItemInnerSpacing = ImVec2(8, 6);
	style->IndentSpacing = 25.0f;
	style->ScrollbarSize = 15.0f;
	style->ScrollbarRounding = 9.0f;
	style->GrabMinSize = 5.0f;
	style->GrabRounding = 3.0f;

	style->Colors[ImGuiCol_Text] = ImVec4(0.80f, 0.80f, 0.83f, 1.00f);
	style->Colors[ImGuiCol_TextDisabled] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
	style->Colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	//style->Colors[ImGuiCol_ChildWindowBg] = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
	style->Colors[ImGuiCol_PopupBg] = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
	style->Colors[ImGuiCol_Border] = ImVec4(0.80f, 0.80f, 0.83f, 0.88f);
	style->Colors[ImGuiCol_BorderShadow] = ImVec4(0.92f, 0.91f, 0.88f, 0.00f);
	style->Colors[ImGuiCol_FrameBg] = ImVec4(0.10f, 0.09f, 0.12f, 0.85f);
	style->Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.24f, 0.23f, 0.29f, 0.85f);
	style->Colors[ImGuiCol_FrameBgActive] = ImVec4(0.56f, 0.56f, 0.58f, 0.85f);
	style->Colors[ImGuiCol_TitleBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	style->Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(1.00f, 0.98f, 0.95f, 0.75f);
	style->Colors[ImGuiCol_TitleBgActive] = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
	style->Colors[ImGuiCol_MenuBarBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	style->Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	style->Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
	style->Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	style->Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	//style->Colors[ImGuiCol_ComboBg] = ImVec4(0.19f, 0.18f, 0.21f, 1.00f);
	style->Colors[ImGuiCol_CheckMark] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
	style->Colors[ImGuiCol_SliderGrab] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
	style->Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	style->Colors[ImGuiCol_Button] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	style->Colors[ImGuiCol_ButtonHovered] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
	style->Colors[ImGuiCol_ButtonActive] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	style->Colors[ImGuiCol_Header] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	style->Colors[ImGuiCol_HeaderHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	style->Colors[ImGuiCol_HeaderActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	//style->Colors[ImGuiCol_Column] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	//style->Colors[ImGuiCol_ColumnHovered] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
	//style->Colors[ImGuiCol_ColumnActive] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	style->Colors[ImGuiCol_ResizeGrip] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	style->Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	style->Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	//style->Colors[ImGuiCol_CloseButton] = ImVec4(0.40f, 0.39f, 0.38f, 0.16f);
	//style->Colors[ImGuiCol_CloseButtonHovered] = ImVec4(0.40f, 0.39f, 0.38f, 0.39f);
	//style->Colors[ImGuiCol_CloseButtonActive] = ImVec4(0.40f, 0.39f, 0.38f, 1.00f);
	style->Colors[ImGuiCol_PlotLines] = ImVec4(0.40f, 0.39f, 0.38f, 0.63f);
	style->Colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);
	style->Colors[ImGuiCol_PlotHistogram] = ImVec4(0.40f, 0.39f, 0.38f, 0.63f);
	style->Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);
	style->Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.25f, 1.00f, 0.00f, 0.43f);
	//style->Colors[ImGuiCol_ModalWindowDarkening] = ImVec4(1.00f, 0.98f, 0.95f, 0.73f);
}

void g::R_OpenMenu()
{
	if (!ImGui::GetCurrentContext()) {
		std::cout << "POSSIBLY NO CONTEXT!!!!\n";
		return;
	}
	static bool save_file = false;

	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	if (GetKeyState(MENU_KEY) == 1) {
		
		save_file = true; //save after closing

		R_MenuStyle();
		
		ImGui::Begin("REDMATCH 3", 0, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_AlwaysAutoResize);

		ImGui::Text("epic big hack");
		hook* a = nullptr;
		ImGui::BeginGroup();
		if (ImGui::Checkbox("Invincibility", &vars::invincibility.enabled)) {
			Evar_SetValue(&vars::invincibility, vars::invincibility.enabled);

			if (!PlayerController_Die) {
				MessageBoxA(NULL, "failed to find pattern!", "ERROR", 0);
				exit(-1);
				return;
			}

			if (vars::invincibility.enabled)
				a->write_addr(PlayerController_Die, "\xC3", 1); //write a return instruction at the beginning of PlayerController::Die() (invincibility)
			else 
				a->write_addr(PlayerController_Die, "\x40", 1); //write a push rbx instruction at the beginning of PlayerController::Die()

			
		}
		if (ImGui::Checkbox("No Fire Delay", &vars::no_fire_delay.enabled)) {
			Evar_SetValue(&vars::no_fire_delay, vars::no_fire_delay.enabled);

			if (vars::no_fire_delay.enabled)
				a->nop(PlayerController_Fire_Delay); //no fire delay
			else
				a->write_addr(PlayerController_Fire_Delay, "\xE8\xE1\x0B\xA0\xFF", 5); //call GameAssembly.dll+DFB1E0

	
		}
		ImGui::EndGroup();
		ImGui::SameLine();
		ImGui::BeginGroup();
		ImGui::Text("Weapon");
		ImGui::Separator();

		const char* weapon[3] = { "ak", "shotgun", "sniper"};
		static int selected_weap;
		ImGui::PushItemWidth(100);
		ImGui::Combo("Weapon", &selected_weap, weapon, IM_ARRAYSIZE(weapon));
		ImGui::Separator();
		ImGui::DragFloat("Damage", &vars::weapon_damage.arrayValue[selected_weap], 2, 0, 99999, "%.3f", 1);
		ImGui::DragFloat("Spread", &vars::weapon_spread.arrayValue[selected_weap], 1, 0, 360, "%.3f", 1);
		ImGui::DragFloat("Magazine", &vars::weapon_magazineSize.arrayValue[selected_weap], 1, 0, 99999, "%.3f", 1);

		ImGui::EndGroup();
		ImGui::SameLine();
		ImGui::BeginGroup();

		ImGui::Text("World");
		ImGui::Separator();

		if (ImGui::Checkbox("Skywalk", &vars::world_skywalk.enabled)) 
			Evar_SetValue(&vars::world_skywalk, vars::world_skywalk.enabled);
		
		if (!vars::world_skywalk.enabled)
			ImGui::BeginDisabled(true);

		ImGui::DragFloat("Z height", &vars::world_skywalk_z.floatValue, 2, std::numeric_limits<float>::min(), std::numeric_limits<float>::max(), "%.3f", 1);


		if (!vars::world_skywalk.enabled)
			ImGui::EndDisabled();

		ImGui::EndGroup();
		ImGui::SameLine();
		ImGui::BeginGroup();
		ImGui::Text("Teleport");
		ImGui::Separator();

		if (ImGui::Checkbox("Spam", &vars::tp_spam.enabled))
			Evar_SetValue(&vars::tp_spam, vars::tp_spam.enabled);

		ImGui::EndGroup();
		ImGui::SameLine();
		ImGui::BeginGroup();
		ImGui::Text("Esp");
		ImGui::Separator();

		if (ImGui::Checkbox("ESP", &vars::random_esp.enabled))
			Evar_SetValue(&vars::random_esp, vars::random_esp.enabled);
		ImGui::EndGroup();
		ImGui::End();

	}
	else {
		if (save_file) {
			Evar_SaveToFile(vars::cfg::cfgDirectory);
			std::cout << "save settings!\n";
			save_file = false;
		}
	}


}
void g::R_EndRender()
{
	if (!ImGui::GetCurrentContext()) {
		std::cout << "POSSIBLY NO CONTEXT!!!!\n";
		return;
	}
	ImGui::EndFrame();
	ImGui::Render();
	ImDrawData* data = ImGui::GetDrawData();
	pContext->OMSetRenderTargets(1, &mainRenderTargetView, NULL);

	ImGui_ImplDX11_RenderDrawData(data);
}