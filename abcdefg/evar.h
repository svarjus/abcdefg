#pragma once

#ifndef cfghash
#define cfghash

#include "pch.h"

enum evartype_t
{
	EVAR_BOOL,
	EVAR_INT,
	EVAR_FLOAT,
	EVAR_VEC2,
	EVAR_VEC3,
	EVAR_VEC4,
	EVAR_ARRAY //stores all values as floats
};

struct evar_s
{
	bool initialized; //a way to check if Evar_Register was ever called
	const char* name;
	int intValue;
	float floatValue;
	vec2_t vec2Value;
	vec3_t vec3Value;
	vec4_t vec4Value;
	std::vector<float> arrayValue;
	bool enabled;
	float value;
	evartype_t type;
	evar_s* Next;
};


inline evar_s* evar;
inline evar_s* evarList[256]{};
inline uint32_t evarCount;

evar_s* Evar_FindByName(const char* name);
void Evar_Register(evar_s* evar, const char* name, evartype_t type, float defaultValue);
void Evar_Register(evar_s* evar, const char* name, evartype_t type, float* defaultValue);
void Evar_Register(evar_s* evar, const char* name, evartype_t type, float defaultValue, uint32_t size); //arrays


void Evar_Setup();
void Evar_SetValue(evar_s* evar, float value);
void Evar_SetValue(evar_s* evar, float* value);
void Evar_SetValue(evar_s* evar, float* valueArray, uint32_t items, uint32_t beginIndex);


std::vector<evar_s*> Evar_GetAlphabetically();

inline uint32_t (*Com_HashString)(char* string) = (uint32_t(__cdecl*)(char*))0x569DA0;
static std::string evar_save_path_cstr;


#endif