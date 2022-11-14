#pragma once

#ifndef pceditor
#define pceditor

#include "pch.h"

namespace g
{
	void R_AppendBool(const char* name, bool* value);
	void R_AppendInt(const char* name, int* value);
	void R_AppendInt16(const char* name, int16_t* value);

	void R_AppendFloat(const char* name, float* value);
	void R_AppendVec2(const char* name, vec2_t value);
	void R_AppendVec3(const char* name, vec3_t value);
	void R_AppendString(const char* name, char* buff, size_t size, const char* value);

	void R_PlayerControllerEditor(bool& isOpen);

}

#endif