#include "pch.h"


void g::R_AppendBool(const char* name, bool* value)
{
	ImGui::Checkbox(name, value);
	ImGui::SameLine(); ImGui::Text("(0x%p)", value);

}
void g::R_AppendInt(const char* name, int* value)
{
	ImGui::PushItemWidth(150);
	ImGui::InputInt(name, value);
	ImGui::SameLine(); ImGui::Text("(0x%p)", value);
}
void g::R_AppendInt16(const char* name, int16_t* value)
{
	ImGui::PushItemWidth(200);
	ImGui::InputInt(name, (int*)value);
	ImGui::SameLine(); ImGui::Text("(0x%p)", value);

}
void g::R_AppendFloat(const char* name, float* value)
{
	ImGui::PushItemWidth(100);
	ImGui::InputFloat(name, value, 0, 0, "%.3f");
	ImGui::SameLine(); ImGui::Text("(0x%p)", value);

}
void g::R_AppendVec2(const char* name, vec2_t value)
{
	ImGui::PushItemWidth(160);
	ImGui::InputFloat2(name, value, "%.3f");
	ImGui::SameLine(); ImGui::Text("(0x%p)", value);

}
void g::R_AppendVec3(const char* name, vec3_t value)
{
	ImGui::PushItemWidth(250);
	ImGui::InputFloat3(name, value, "%.3f");
	ImGui::SameLine(); ImGui::Text("(0x%p)", value);

}
void g::R_AppendString(const char* name, char* buff, size_t size, const char* value)
{
	ImGui::PushItemWidth(100);
	ImGui::InputText(name, buff, size);

}

void g::R_PlayerControllerEditor(bool& isOpen)
{
	if (!&PlayerController || !isOpen)
		return;

	constexpr int ah = sizeof(PlayerController_c);

	if (ImGui::Begin("PC Editor", &isOpen, ImGuiWindowFlags_AlwaysAutoResize)) {
		ImGui::BeginChild("pc_editor", ImVec2(800, 600), true);
		PlayerController_c* pc = PlayerController_ptr;

		R_AppendFloat("additiveFov", &pc->additiveFOV);
		R_AppendBool("ads", &pc->ads);
		R_AppendFloat("animationSmoothTime", &pc->animationSmoothTime);
		R_AppendFloat("bulletSpread", &pc->bulletSpread);
		R_AppendVec3("constantForce", pc->constantForce);
		R_AppendInt("crosshairIndex", &pc->crosshairIndex);
		R_AppendBool("dead", &pc->dead);
		R_AppendBool("grounded", &pc->grounded);
		R_AppendBool("groundedLastTick", &pc->groundedLastTick);
		R_AppendVec3("groundedTransformLastPosition", pc->groundedTransformLastPosition);
		R_AppendBool("isActingAsLocalPlayer", &pc->isActingAsLocalPlayer);
		R_AppendInt("itemIndex", &pc->itemIndex);
		R_AppendInt16("lastDamagePacketID", &pc->lastDamagePacketID);
		R_AppendFloat("lastTimeGrounded", &pc->lastTimeGrounded);
		R_AppendFloat("lastTimeJumped", &pc->lastTimeJumped);
		R_AppendFloat("lastTimePulledOutItem", &pc->lastTimePulledOutItem);
		R_AppendFloat("lastTimeTookDamage", &pc->lastTimeTookDamage);
		R_AppendBool("meleeing", &pc->meleeing);
		R_AppendVec3("momentum", pc->momentum);
		R_AppendVec3("moveAmount", pc->moveAmount);
		R_AppendFloat("nextTimeToCircleDamage", &pc->nextTimeToCircleDamage);
		R_AppendFloat("nextTimeToRegen", &pc->nextTimeToRegen);
		R_AppendVec3("pushForce", pc->pushForce);
		R_AppendInt("regenAmount", &pc->regenAmount);
		R_AppendFloat("regenAmount", &pc->regenInterval);
		R_AppendBool("reloading", &pc->reloading);
		//R_AppendVec3("rigid_origin", pc->rigid_origin);
		//R_AppendFloat("rigid_time", &pc->rigid_time);
		R_AppendBool("shielded", &pc->shielded);
		R_AppendVec3("smoothMoveVelocity", pc->smoothMoveVelocity);
		R_AppendFloat("smoothTime", &pc->smoothTime);
		R_AppendBool("sprinting", &pc->sprinting);
		R_AppendBool("toJump", &pc->toJump);
		R_AppendFloat("verticalLookRotation", &pc->verticalLookRotation);
		R_AppendBool("wasInteractable", &pc->wasInteractable);

		ImGui::EndChild();
	}
	ImGui::End();


}