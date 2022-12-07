#include "pch.h"

void g::AddLog(const std::string& str)
{
	std::cout << str;
	console_logs.push_back(str);
}
void g::R_UI_Console()
{
	while (console_logs.size() > 1000)
		console_logs.erase(console_logs.begin(), console_logs.begin()+1);

	for (auto& i : console_logs) {
		ImGui::Text(i.c_str());
	}


}