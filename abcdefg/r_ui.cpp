
#include "pch.h"


void g::R_MenuStyle()
{
	ImGuiStyle* style = &ImGui::GetStyle();
	ImVec4* colors = style->Colors;

	style->AntiAliasedLines = true;
	style->AntiAliasedFill = true;

	// Main
	style->WindowPadding.x = 5.0f;
	style->WindowPadding.y = 5.0f;
	style->PopupRounding = 2.0f;
	style->FramePadding.x = 10.0f;
	style->FramePadding.y = 5.0f;
	style->ItemSpacing.x = 10.0f;
	style->ItemSpacing.y = 5.0f;
	style->ItemInnerSpacing.x = 10.0f;
	style->ItemInnerSpacing.y = 4.0f;
	style->TouchExtraPadding.x = 0.0f;
	style->TouchExtraPadding.y = 0.0f;
	style->IndentSpacing = 30.0f;
	style->ScrollbarSize = 14.0f;
	style->GrabMinSize = 10.0f;

	// Borders
	style->WindowBorderSize = 1.0f;
	style->ChildBorderSize = 1.0f;
	style->PopupBorderSize = 1.0f;
	style->FrameBorderSize = 1.0f;
	style->TabBorderSize = 0.0f;

	// Rounding
	style->WindowRounding = 2.0f;
	style->ChildRounding = 2.0f;
	style->FrameRounding = 2.0f;
	style->ScrollbarRounding = 2.0f;
	style->GrabRounding = 2.0f;
	style->TabRounding = 2.0f;

	style->WindowTitleAlign = ImVec2(0.5, 0.5);


	colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 0.84f);
	colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 0.64f);
	colors[ImGuiCol_WindowBg] = ImVec4(0.11f, 0.11f, 0.11f, 0.90f);
	colors[ImGuiCol_ChildBg] = ImVec4(1.00f, 1.00f, 0.99f, 0.00f);
	colors[ImGuiCol_PopupBg] = ImVec4(0.08f, 0.08f, 0.08f, 0.93f);
	colors[ImGuiCol_Border] = ImVec4(0.20f, 0.20f, 0.20f, 0.55f);
	colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	colors[ImGuiCol_FrameBg] = ImVec4(0.06f, 0.06f, 0.06f, 0.56f);
	colors[ImGuiCol_FrameBgHovered] = ImVec4(0.20f, 0.20f, 0.20f, 0.60f);
	colors[ImGuiCol_FrameBgActive] = ImVec4(1.00f, 1.00f, 0.98f, 0.20f);
	colors[ImGuiCol_TitleBg] = ImVec4(0.11f, 0.11f, 0.11f, 1.00f);
	colors[ImGuiCol_TitleBgActive] = ImVec4(0.28f, 0.2f, 0.15f, 1.00f);
	colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 0.66f);
	colors[ImGuiCol_MenuBarBg] = ImVec4(1.00f, 1.00f, 1.00f, 0.07f);
	colors[ImGuiCol_ScrollbarBg] = ImVec4(0.02f, 0.02f, 0.02f, 0.53f);
	colors[ImGuiCol_ScrollbarGrab] = ImVec4(1.00f, 1.00f, 1.00f, 0.11f);
	colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(1.00f, 1.00f, 1.00f, 0.24f);
	colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.99f, 1.00f, 1.00f, 0.24f);
	colors[ImGuiCol_CheckMark] = ImVec4(1.00f, 0.55f, 0.39f, 0.69f);
	colors[ImGuiCol_SliderGrab] = ImVec4(1.00f, 0.55f, 0.39f, 0.69f);
	colors[ImGuiCol_SliderGrabActive] = ImVec4(1.00f, 0.55f, 0.39f, 1.00f);
	colors[ImGuiCol_Button] = ImVec4(0.24f, 0.24f, 0.24f, 0.55f);
	colors[ImGuiCol_ButtonHovered] = ImVec4(0.39f, 0.39f, 0.39f, 0.73f);
	colors[ImGuiCol_ButtonActive] = ImVec4(0.55f, 0.55f, 0.55f, 0.74f);
	colors[ImGuiCol_Header] = ImVec4(0.34f, 0.34f, 0.34f, 0.21f);
	colors[ImGuiCol_HeaderHovered] = ImVec4(1.00f, 1.00f, 1.00f, 0.36f);
	colors[ImGuiCol_HeaderActive] = ImVec4(1.00f, 1.00f, 1.00f, 0.36f);
	colors[ImGuiCol_Separator] = ImVec4(1.00f, 1.00f, 1.00f, 0.09f);
	colors[ImGuiCol_SeparatorHovered] = ImVec4(1.00f, 1.00f, 1.00f, 0.09f);
	colors[ImGuiCol_SeparatorActive] = ImVec4(1.00f, 1.00f, 1.00f, 0.20f);
	colors[ImGuiCol_ResizeGrip] = ImVec4(1.00f, 1.00f, 1.00f, 0.16f);
	colors[ImGuiCol_ResizeGripHovered] = ImVec4(1.00f, 1.00f, 1.00f, 0.39f);
	colors[ImGuiCol_ResizeGripActive] = ImVec4(1.00f, 1.00f, 1.00f, 0.39f);
	colors[ImGuiCol_Tab] = ImVec4(0.27f, 0.27f, 0.27f, 0.54f);
	colors[ImGuiCol_TabHovered] = ImVec4(1.00f, 0.53f, 0.36f, 0.48f);
	colors[ImGuiCol_TabActive] = ImVec4(1.00f, 0.55f, 0.39f, 0.69f);
	colors[ImGuiCol_TabUnfocused] = ImVec4(0.07f, 0.10f, 0.15f, 0.80f);
	colors[ImGuiCol_TabUnfocusedActive] = ImVec4(1.00f, 0.66f, 0.53f, 0.61f);
	colors[ImGuiCol_PlotLines] = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
	colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
	colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
	colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
	colors[ImGuiCol_TextSelectedBg] = ImVec4(1.00f, 0.70f, 0.62f, 0.30f);
	colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
	colors[ImGuiCol_NavHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.40f);
	colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.27f);
	colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
	colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.34f);

}
void g::R_UI_Player()
{
	hook* a = nullptr;

	if (ImGui::Checkbox("Invincibility", &v::invincibility.evar->enabled)) {
		v::invincibility.SetValue(v::invincibility.isEnabled());

		if (v::invincibility.isEnabled())
			a->write_addr(PlayerController_Die, "\xC3", 1); //write a return instruction at the beginning of PlayerController::Die() (invincibility)
		else
			a->write_addr(PlayerController_Die, "\x40", 1); //write a push rbx instruction at the beginning of PlayerController::Die()


	}

}
void g::R_UI_Weapons()
{
	hook* a = nullptr;
	if (ImGui::Checkbox("No Fire Delay", &v::no_fire_delay.evar->enabled)) {
		v::no_fire_delay.SetValue(v::no_fire_delay.isEnabled());

		if (v::no_fire_delay.isEnabled())
			a->nop(PlayerController_Fire_Delay); //no fire delay
		else
			a->write_addr(PlayerController_Fire_Delay, (char*)PlayerController_Fire_Delay_orgbytes, 5); //call GameAssembly.dll+DFB1E0



	}

	if (ImGui::Checkbox("Visual recoil", &v::visual_recoil.evar->enabled)) {
		v::visual_recoil.SetValue(v::visual_recoil.isEnabled());

		if (v::visual_recoil.isEnabled())
			a->nop(PlayerController_Fire_Recoil); //no visual recoil
		else
			a->write_addr(PlayerController_Fire_Recoil, (char*)PlayerController_Fire_Recoil_orgbytes, 5); //call GameAssembly.dll+DFB1E0


	}
	if (ImGui::Checkbox("Fire Effects", &v::fire_effect.evar->enabled)) {
		v::fire_effect.SetValue(v::fire_effect.isEnabled());

		if (v::fire_effect.isEnabled())
			a->nop(PlayerController_Fire_Effect); //no visual recoil
		else
			a->write_addr(PlayerController_Fire_Effect, (char*)PlayerController_Fire_Effect_orgbytes, 5); //call GameAssembly.dll+DFB1E0


	}

	const char* weapon[4] = { "ak", "shotgun", "sniper", "revolver" };
	static int selected_weap;
	ImGui::PushItemWidth(100);
	ImGui::Combo("Weapon", &selected_weap, weapon, IM_ARRAYSIZE(weapon));
	ImGui::Separator();
	ImGui::DragFloat("Damage", &v::weapon_damage.evar->arrayValue[selected_weap], 2.f, 0.f, 99999.f, "%.3f");
	ImGui::DragFloat("Spread", &v::weapon_spread.evar->arrayValue[selected_weap], 1.f, 0.f, 360.f, "%.3f");
	ImGui::DragFloat("Use Delay", &v::weapon_usedelay.evar->arrayValue[selected_weap], 0.02f, 0.f, 10.f, "%.3f");
	if (ImGui::Button("Set Defaults")) {
		v::weapon_usedelay.evar->arrayValue[0] = 0.1f;
		v::weapon_usedelay.evar->arrayValue[1] = 0.5f;
		v::weapon_usedelay.evar->arrayValue[2] = 1.f;
		v::weapon_usedelay.evar->arrayValue[3] = 0.5f;
	}


}
void g::R_UI_UnityEngine()
{
	if (ImGui::Checkbox("Skywalk", &v::world_skywalk.evar->enabled))
		v::world_skywalk.SetValue(v::world_skywalk.isEnabled());

	if (!v::world_skywalk.isEnabled())
		ImGui::BeginDisabled(true);

	ImGui::DragFloat("Z height", &v::world_skywalk_z.evar->floatValue, 2, std::numeric_limits<float>::min(), std::numeric_limits<float>::max(), "%.3f", 1);

	if (!v::world_skywalk.isEnabled())
		ImGui::EndDisabled();

	if (ImGui::Checkbox("Epic Jump", &v::epic_jump.evar->enabled))
		v::epic_jump.SetValue(v::epic_jump.isEnabled());


	if (ImGui::Checkbox("Spam", &v::tp_spam.evar->enabled))
		v::tp_spam.SetValue(v::tp_spam.isEnabled());

	if (!v::tp_spam.isEnabled())
		ImGui::BeginDisabled();

	ImGui::Text("\t"); ImGui::SameLine();
	ImGui::DragFloat("-Z Offset", &v::tp_spam_offset.evar->floatValue, 0.05f, -99999.f, 99999.f, "%.3f");


	if (!v::tp_spam.isEnabled())
		ImGui::EndDisabled();

}
void g::R_UI_Varjus()
{
	if (ImGui::Checkbox("ESP", &v::random_esp.evar->enabled))
		v::random_esp.SetValue(v::random_esp.isEnabled());

	static bool isOpen;
	if (ImGui::Button("PC Editor"))
		isOpen = !isOpen;

	if (ImGui::Checkbox("Moderator authority", &v::moderator_authority.evar->enabled))
		v::moderator_authority.SetValue(v::moderator_authority.isEnabled());

	if (ImGui::Checkbox("Overwrite chat", &v::overwrite_chat.evar->enabled))
		v::overwrite_chat.SetValue(v::overwrite_chat.isEnabled());

	if (!v::overwrite_chat.isEnabled())
		ImGui::BeginDisabled();

	ImGui::Text("\t");
	ImGui::SameLine();
	ImGui::BeginGroup();

	ImGui::PushItemWidth(300);
	ImGui::InputText("string##02", &chat_str);

	ImGui::EndGroup();


	if (!v::overwrite_chat.isEnabled())
		ImGui::EndDisabled();

	R_PlayerControllerEditor(isOpen);


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
		BANNED_FROM_MATCH = false;
		R_MenuStyle();
		save_file = true; //save after closing

		ImGui::Begin("epic big hack", 0, ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoCollapse);

		if(ImGui::BeginTabBar("aaaaa")) {
			if (ImGui::BeginTabItem("Player")) {
				R_UI_Player();
				ImGui::EndTabItem();
			}
			if (ImGui::BeginTabItem("Weapons")) {
				R_UI_Weapons();
				ImGui::EndTabItem();
			}
			if (ImGui::BeginTabItem("Engine")) {
				R_UI_UnityEngine();
				ImGui::EndTabItem();
			}
			if (ImGui::BeginTabItem("Varjus")) {
				R_UI_Varjus();
				ImGui::EndTabItem();
			}
			if (ImGui::BeginTabItem("Console")) {
				R_UI_Console();
				ImGui::EndTabItem();
			}
			ImGui::EndTabBar();
		}

		hook* a = nullptr;

		//R_UI_Player();
		//R_UI_Weapons();
		//R_UI_UnityEngine();
		//R_UI_Varjus();

		ImGui::End();

	}
	else {
		if (save_file) {
			Evar_SaveToFile(v::cfg::cfgDirectory);
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
	
	pContext->OMSetRenderTargets(1, &mainRenderTargetView, NULL);


	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());


}