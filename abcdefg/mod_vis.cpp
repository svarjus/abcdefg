#include "pch.h"

void g::Mod_DrawCoordinates()
{


	ImDrawList* draw = ImGui::GetBackgroundDrawList();


	char buff[1024];
	//bool lastTimeJumped = LocalPlayer->lastTimeJumped;
	//vec3_t _rigid_origin;
	//XZY2XYZ(LocalPlayer->rigid_origin, _rigid_origin);

	float yaw = UE_ConvertGameYaw(PlayerTransform.yaw);

	sprintf_s(buff, "X: %.3f\nY: %.3f\nZ: %.3f\nyaw: %.3f\nzVel: %.3f", _tp.myCoords[0], _tp.myCoords[1], _tp.myCoords[2], yaw, PlayerTransform.zVelocity);

	draw->AddText(ImVec2(0, 400), IM_COL32(0, 255, 0, 255), buff);

	

}