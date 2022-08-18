#include "pch.h"

//RECT rectangle, rect2, rect3, rect4, rect5;
//void r::TextWithOutline(std::string p, D3DRECT rect, vec3_t color)
//{
//	if (!font1 || !font1out)
//		return;
//
//	const char* text = p.c_str();
//
//	rect.x1 = X(rect.x1);
//	rect.y1 = Y(rect.y1);
//	rect.x2 = X(rect.x2);
//	rect.y2 = Y(rect.y2);
//
//	SetRect(&rect2, rect.x1 - 1, rect.y1, rect.x2, rect.y2);
//	font1out->DrawText(NULL, text, -1, &rect2, DT_NOCLIP | DT_LEFT, D3DCOLOR_ARGB(255, 0, 0, 0));
//
//	SetRect(&rect3, rect.x1 + 1, rect.y1, rect.x2, rect.y2);
//	font1out->DrawText(NULL, text, -1, &rect3, DT_NOCLIP | DT_LEFT, D3DCOLOR_ARGB(255, 0, 0, 0));
//
//	SetRect(&rect4, rect.x1, rect.y1 + 1, rect.x2, rect.y2);
//	font1out->DrawText(NULL, text, -1, &rect4, DT_NOCLIP | DT_LEFT, D3DCOLOR_ARGB(255, 0, 0, 0));
//
//	SetRect(&rect5, rect.x1, rect.y1 - 1, rect.x2, rect.y2);
//	font1out->DrawText(NULL, text, -1, &rect5, DT_NOCLIP | DT_LEFT, D3DCOLOR_ARGB(255, 0, 0, 0));
//
//	SetRect(&rectangle, rect.x1, rect.y1, rect.x2, rect.y2);
//	font1->DrawText(NULL, text, -1, &rectangle, DT_NOCLIP | DT_LEFT, D3DCOLOR_ARGB(255, (int)color[0], (int)color[1], (int)color[2]));
//
//}
//void r::TextWithOutline(vec2_t _rect, vec4_t color, const char* msg, ...)
//{
//	if (!font1 || !font1out)
//		return;
//
//	char v2[4096]; // [esp+0h] [ebp-1000h] BYREF
//	va_list va; // [esp+100Ch] [ebp+Ch] BYREF
//
//	va_start(va, msg);
//	_vsnprintf_s(v2, 0x1000u, msg, va);
//	v2[4095] = 0;
//
//	D3DRECT rect{};
//	rect.x1 = X(_rect[0]);
//	rect.y1 = Y(_rect[1]);
//	rect.x2 = X(_rect[0]+10);
//	rect.y2 = Y(_rect[1]+10);
//
//	SetRect(&rect2, rect.x1 - 1, rect.y1, rect.x2, rect.y2);
//	font1out->DrawText(NULL, v2, -1, &rect2, DT_NOCLIP | DT_LEFT, D3DCOLOR_ARGB(255, 0, 0, 0));
//
//	SetRect(&rect3, rect.x1 + 1, rect.y1, rect.x2, rect.y2);
//	font1out->DrawText(NULL, v2, -1, &rect3, DT_NOCLIP | DT_LEFT, D3DCOLOR_ARGB(255, 0, 0, 0));
//
//	SetRect(&rect4, rect.x1, rect.y1 + 1, rect.x2, rect.y2);
//	font1out->DrawText(NULL, v2, -1, &rect4, DT_NOCLIP | DT_LEFT, D3DCOLOR_ARGB(255, 0, 0, 0));
//
//	SetRect(&rect5, rect.x1, rect.y1 - 1, rect.x2, rect.y2);
//	font1out->DrawText(NULL, v2, -1, &rect5, DT_NOCLIP | DT_LEFT, D3DCOLOR_ARGB(255, 0, 0, 0));
//
//	SetRect(&rectangle, rect.x1, rect.y1, rect.x2, rect.y2);
//	font1->DrawText(NULL, v2, -1, &rectangle, DT_NOCLIP | DT_LEFT, D3DCOLOR_ARGB((BYTE)color[3], (BYTE)color[0], (BYTE)color[1], (BYTE)color[2]));
//
//}
float r::X(float pos)
{
	const float x = (float)((int(*)())g::fnIl2cpp_resolve_icall(UE_GET_WIDTH))();
	return pos <= 1920 ? pos / (1920.f / x) : pos * (x / 1920);

}
float r::Y(float pos)
{
	const float y = (float)((int(*)())g::fnIl2cpp_resolve_icall(UE_GET_HEIGHT))();
	return pos <= 1080 ? pos / (1080.f / y) : pos * (y / 1080);
}
void r::MetricsHelpMarker(const char* desc)
{
	ImGui::TextDisabled("(?)");
	if (ImGui::IsItemHovered())
	{
		ImGui::BeginTooltip();
		ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
		ImGui::TextUnformatted(desc);
		ImGui::PopTextWrapPos();
		ImGui::EndTooltip();
	}
}