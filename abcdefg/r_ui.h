#pragma once

#ifndef rmenu
#define rmenu
#include "pch.h"

namespace g
{
	inline std::vector<std::string> console_logs;
	inline std::string outskirts_code_text;


	inline std::string chat_str;

	void R_OpenMenu();
	void R_EndRender();
	void R_MenuStyle();

	void R_UI_Player();
	void R_UI_Weapons();
	void R_UI_UnityEngine();
	void R_UI_Varjus();
	void R_UI_Map();

	

	void AddLog(const std::string& str);

	void R_UI_Console();
}


#endif