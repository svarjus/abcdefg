#include "pch.h"

bool g::WorldToScreen(vec3_t pos, vec2_t xy)
{
	uintptr_t* cam = (uintptr_t*)fnGetMainCamera();

	const vec3 a = WorldToScreenPoint(cam, vec3(pos[0], pos[1], pos[2]));
	const float y = (float)((int(*)())g::fnIl2cpp_resolve_icall(UE_GET_HEIGHT))();

	xy[0] = r::X(a.x);
	xy[1] = r::Y(y - a.y);


	return a.z >= 1.f;
}
g::box_s::box_s(vec3_t origin, vec3_t mins, vec3_t maxs)
{
	//box_s box{};

	vec3_t lowA, lowB, lowC, lowD;
	vec3_t highA, highB, highC, highD;

	lowA[0] = origin[0] - mins[0];
	lowA[1] = origin[1] - mins[1];
	lowA[2] = origin[2] - mins[2];

	lowB[0] = origin[0] + mins[0];
	lowB[1] = origin[1] + mins[1];
	lowB[2] = origin[2] - mins[2];

	lowC[0] = origin[0] - mins[0];
	lowC[1] = origin[1] + mins[1];
	lowC[2] = origin[2] - mins[2];

	lowD[0] = origin[0] + mins[0];
	lowD[1] = origin[1] - mins[1];
	lowD[2] = origin[2] - mins[2];

	highA[0] = lowA[0];
	highA[1] = lowA[1];
	highA[2] = origin[2] + maxs[2];

	highB[0] = lowB[0];
	highB[1] = lowB[1];
	highB[2] = origin[2] + maxs[2];

	highC[0] = lowC[0];
	highC[1] = lowC[1];
	highC[2] = origin[2] + maxs[2];

	highD[0] = lowD[0];
	highD[1] = lowD[1];
	highD[2] = origin[2] + maxs[2];

	this->lowA_valid = WorldToScreen(lowA, this->lowA);
	this->lowB_valid = WorldToScreen(lowB, this->lowB);
	this->lowC_valid = WorldToScreen(lowC, this->lowC);
	this->lowD_valid = WorldToScreen(lowD, this->lowD);

	this->highA_valid = WorldToScreen(highA, this->highA);
	this->highB_valid = WorldToScreen(highB, this->highB);
	this->highC_valid = WorldToScreen(highC, this->highC);
	this->highD_valid = WorldToScreen(highD, this->highD);

	//return box;
}
void g::box_s::R_DrawConstructedBoxEdges(vec4_t col) const
{
	if (!ImGui::GetCurrentContext())
		return;

	if (this->lowA_valid && this->lowC_valid)
		ImGui::GetBackgroundDrawList()->AddLine(ImVec2(this->lowA[0], this->lowA[1]), ImVec2(this->lowC[0], this->lowC[1]), IM_COL32(col[0], col[1], col[2], col[3]), 1.f);

	if (this->lowB_valid && this->lowD_valid)
		ImGui::GetBackgroundDrawList()->AddLine(ImVec2(this->lowB[0], this->lowB[1]), ImVec2(this->lowD[0], this->lowD[1]), IM_COL32(col[0], col[1], col[2], col[3]), 1.f);

	if (this->lowC_valid && this->lowB_valid)
		ImGui::GetBackgroundDrawList()->AddLine(ImVec2(this->lowC[0], this->lowC[1]), ImVec2(this->lowB[0], this->lowB[1]), IM_COL32(col[0], col[1], col[2], col[3]), 1.f);

	if (this->lowD_valid && this->lowA_valid)
		ImGui::GetBackgroundDrawList()->AddLine(ImVec2(this->lowD[0], this->lowD[1]), ImVec2(this->lowA[0], this->lowA[1]), IM_COL32(col[0], col[1], col[2], col[3]), 1.f);

	if (this->highA_valid && this->highC_valid)
		ImGui::GetBackgroundDrawList()->AddLine(ImVec2(this->highA[0], this->highA[1]), ImVec2(this->highC[0], this->highC[1]), IM_COL32(col[0], col[1], col[2], col[3]), 1.f);

	if (this->highB_valid && this->highD_valid)
		ImGui::GetBackgroundDrawList()->AddLine(ImVec2(this->highB[0], this->highB[1]), ImVec2(this->highD[0], this->highD[1]), IM_COL32(col[0], col[1], col[2], col[3]), 1.f);

	if (this->highC_valid && this->highB_valid)
		ImGui::GetBackgroundDrawList()->AddLine(ImVec2(this->highC[0], this->highC[1]), ImVec2(this->highB[0], this->highB[1]), IM_COL32(col[0], col[1], col[2], col[3]), 1.f);

	if (this->highD_valid && this->highA_valid)
		ImGui::GetBackgroundDrawList()->AddLine(ImVec2(this->highD[0], this->highD[1]), ImVec2(this->highA[0], this->highA[1]), IM_COL32(col[0], col[1], col[2], col[3]), 1.f);

	if (this->lowA_valid && this->highA_valid)
		ImGui::GetBackgroundDrawList()->AddLine(ImVec2(this->lowA[0], this->lowA[1]), ImVec2(this->highA[0], this->highA[1]), IM_COL32(col[0], col[1], col[2], col[3]), 1.f);

	if (this->lowB_valid && this->highB_valid)
		ImGui::GetBackgroundDrawList()->AddLine(ImVec2(this->lowB[0], this->lowB[1]), ImVec2(this->highB[0], this->highB[1]), IM_COL32(col[0], col[1], col[2], col[3]), 1.f);

	if (this->lowC_valid && this->highC_valid)
		ImGui::GetBackgroundDrawList()->AddLine(ImVec2(this->lowC[0], this->lowC[1]), ImVec2(this->highC[0], this->highC[1]), IM_COL32(col[0], col[1], col[2], col[3]), 1.f);

	if (this->lowD_valid && this->highD_valid)
		ImGui::GetBackgroundDrawList()->AddLine(ImVec2(this->lowD[0], this->lowD[1]), ImVec2(this->highD[0], this->highD[1]), IM_COL32(col[0], col[1], col[2], col[3]), 1.f);
}
void g::box_s::R_DrawConstructedBox(vec4_t col) const
{
	if (!ImGui::GetCurrentContext())
		return;

	if (this->lowA_valid && this->highC_valid && this->lowC_valid)
		ImGui::GetBackgroundDrawList()->AddTriangleFilled(ImVec2(this->lowA[0], this->lowA[1]), ImVec2(this->highC[0], this->highC[1]), ImVec2(this->lowC[0], this->lowC[1]), IM_COL32(col[0], col[1], col[2], col[3]));
	if (this->lowA_valid && this->highA_valid && this->highC_valid)
		ImGui::GetBackgroundDrawList()->AddTriangleFilled(ImVec2(this->highA[0], this->highA[1]), ImVec2(this->lowA[0], this->lowA[1]), ImVec2(this->highC[0], this->highC[1]), IM_COL32(col[0], col[1], col[2], col[3]));

	if (this->lowB_valid && this->highD_valid && this->lowD_valid)
		ImGui::GetBackgroundDrawList()->AddTriangleFilled(ImVec2(this->lowB[0], this->lowB[1]), ImVec2(this->highD[0], this->highD[1]), ImVec2(this->lowD[0], this->lowD[1]), IM_COL32(col[0], col[1], col[2], col[3]));
	if (this->lowB_valid && this->highB_valid && this->highD_valid)
		ImGui::GetBackgroundDrawList()->AddTriangleFilled(ImVec2(this->highB[0], this->highB[1]), ImVec2(this->lowB[0], this->lowB[1]), ImVec2(this->highD[0], this->highD[1]), IM_COL32(col[0], col[1], col[2], col[3]));

	if (this->lowC_valid && this->highB_valid && this->lowB_valid)
		ImGui::GetBackgroundDrawList()->AddTriangleFilled(ImVec2(this->lowC[0], this->lowC[1]), ImVec2(this->highB[0], this->highB[1]), ImVec2(this->lowB[0], this->lowB[1]), IM_COL32(col[0], col[1], col[2], col[3]));
	if (this->lowC_valid && this->highC_valid && this->highB_valid)
		ImGui::GetBackgroundDrawList()->AddTriangleFilled(ImVec2(this->highC[0], this->highC[1]), ImVec2(this->lowC[0], this->lowC[1]), ImVec2(this->highB[0], this->highB[1]), IM_COL32(col[0], col[1], col[2], col[3]));

	if (this->lowD_valid && this->highA_valid && this->lowA_valid)
		ImGui::GetBackgroundDrawList()->AddTriangleFilled(ImVec2(this->lowD[0], this->lowD[1]), ImVec2(this->highA[0], this->highA[1]), ImVec2(this->lowA[0], this->lowA[1]), IM_COL32(col[0], col[1], col[2], col[3]));
	if (this->lowD_valid && this->highD_valid && this->highA_valid)
		ImGui::GetBackgroundDrawList()->AddTriangleFilled(ImVec2(this->highD[0], this->highD[1]), ImVec2(this->lowD[0], this->lowD[1]), ImVec2(this->highA[0], this->highA[1]), IM_COL32(col[0], col[1], col[2], col[3]));

	if (this->highA_valid && this->highB_valid && this->highC_valid)
		ImGui::GetBackgroundDrawList()->AddTriangleFilled(ImVec2(this->highA[0], this->highA[1]), ImVec2(this->highB[0], this->highB[1]), ImVec2(this->highC[0], this->highC[1]), IM_COL32(col[0], col[1], col[2], col[3]));
	if (this->highA_valid && this->highB_valid && this->highD_valid)
		ImGui::GetBackgroundDrawList()->AddTriangleFilled(ImVec2(this->highA[0], this->highA[1]), ImVec2(this->highB[0], this->highB[1]), ImVec2(this->highD[0], this->highD[1]), IM_COL32(col[0], col[1], col[2], col[3]));

	if (this->lowA_valid && this->lowB_valid && this->lowC_valid)
		ImGui::GetBackgroundDrawList()->AddTriangleFilled(ImVec2(this->lowA[0], this->lowA[1]), ImVec2(this->lowB[0], this->lowB[1]), ImVec2(this->lowC[0], this->lowC[1]), IM_COL32(col[0], col[1], col[2], col[3]));
	if (this->lowA_valid && this->lowB_valid && this->lowD_valid)
		ImGui::GetBackgroundDrawList()->AddTriangleFilled(ImVec2(this->lowA[0], this->lowA[1]), ImVec2(this->lowB[0], this->lowB[1]), ImVec2(this->lowD[0], this->lowD[1]), IM_COL32(col[0], col[1], col[2], col[3]));
}