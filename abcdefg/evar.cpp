

#include "pch.h"

evar_s* Evar_FindByName(const char* name)
{
	evar_s* evar = nullptr;
	for (uint32_t i = 0; i < evarCount; i++) {
		evar = evarList[i];
		if (!strcmp(name, evar->name))
			return evar;

	}
	return evar; //returns a nullptr on purpose
}
void Evar_Register(evar_s* evar, const char* name, evartype_t type, float defaultValue, uint32_t size) //arrays
{
	if (type < evartype_t::EVAR_ARRAY || size < 1)
		return;

	evar->arrayValue.reserve(size);
	evar->name = name;
	evar->type = type;
	evar->value = defaultValue;

	switch (type) {
	case evartype_t::EVAR_ARRAY:
		for (uint32_t i = 0; i < size; i++){
			evar->arrayValue.push_back(defaultValue);
		}
		break;
	}

	evarList[evarCount] = evar;
	evar->Next = evarList[evarCount + 1];
	evarCount += 1;
}
void Evar_Register(evar_s* evar, const char* name, evartype_t type, float* defaultValue)
{
	if (type < evartype_t::EVAR_VEC2)
		return;

	evar->name = name;
	evar->type = type;
	evar->value = defaultValue[0];
	switch (type) {
	case evartype_t::EVAR_VEC2:
		evar->enabled = (bool)defaultValue[0] && (bool)defaultValue[1];
		evar->vec2Value[0] = defaultValue[0];
		evar->vec2Value[1] = defaultValue[1];
		break;
	case evartype_t::EVAR_VEC3:
		evar->enabled = (bool)defaultValue[0] && (bool)defaultValue[1] && (bool)defaultValue[2];
		evar->vec3Value[0] = defaultValue[0];
		evar->vec3Value[1] = defaultValue[1];
		evar->vec3Value[2] = defaultValue[2];
		break;
	case evartype_t::EVAR_VEC4:
		evar->enabled = (bool)defaultValue[0] && (bool)defaultValue[1] && (bool)defaultValue[2] && (bool)defaultValue[3];
		evar->vec4Value[0] = defaultValue[0];
		evar->vec4Value[1] = defaultValue[1];
		evar->vec4Value[2] = defaultValue[2];
		evar->vec4Value[3] = defaultValue[3];
		break;
	case evartype_t::EVAR_ARRAY:
		for (uint32_t i = 0; i < 32; i++) {

		}
		break;
	}
	evarList[evarCount] = evar;
	evar->Next = evarList[evarCount + 1];
	evarCount += 1;

}
void Evar_Register(evar_s* evar, const char* name, evartype_t type, float defaultValue)
{
	
	evar->type = type;
	evar->name = name;
	evar->enabled = defaultValue != 0.0;
	evar->value = defaultValue;


	switch (type) {
	case evartype_t::EVAR_BOOL:
		evar->enabled = (bool)defaultValue;
		evar->intValue = evar->enabled;
		evar->floatValue = NULL;
		break;
	case evartype_t::EVAR_INT:
		evar->intValue = (int)defaultValue;
		evar->floatValue = NULL;
		break;
	case evartype_t::EVAR_FLOAT:
		evar->floatValue = defaultValue;
		evar->intValue = NULL;
		break;
	}
	evarList[evarCount] = evar;
	evar->Next = evarList[evarCount + 1];
	evarCount += 1;
}
void Evar_SetValue(evar_s* evar, float value)
{
	if (!evar)
		return;

	evar->value = value;
	evar->enabled = (value != 0.0);

	switch (evar->type) {
	case evartype_t::EVAR_BOOL:
		evar->intValue = evar->enabled;
		evar->floatValue = NULL;
		break;
	case evartype_t::EVAR_INT:
		evar->intValue = (int)value;
		evar->floatValue = NULL;
		break;
	case evartype_t::EVAR_FLOAT:
		evar->floatValue = value;
		evar->intValue = NULL;
		break;
	}

}
void Evar_SetValue(evar_s* evar, float* value)
{
	if (evar->type < evartype_t::EVAR_VEC2)
		return;

	switch (evar->type) {
	case evartype_t::EVAR_VEC2:
		evar->enabled = (bool)value[0] && (bool)value[1];
		evar->vec2Value[0] = value[0];
		evar->vec2Value[1] = value[1];
		break;
	case evartype_t::EVAR_VEC3:
		evar->enabled = (bool)value[0] && (bool)value[1] && (bool)value[2];
		evar->vec3Value[0] = value[0];
		evar->vec3Value[1] = value[1];
		evar->vec3Value[2] = value[2];
		break;
	case evartype_t::EVAR_VEC4:
		evar->enabled = (bool)value[0] && (bool)value[1] && (bool)value[2] && (bool)value[3];
		evar->vec4Value[0] = value[0];
		evar->vec4Value[1] = value[1];
		evar->vec4Value[2] = value[2];
		evar->vec4Value[3] = value[3];
		break;

	}

}
void Evar_SetValue(evar_s* evar, float* valueArray, uint32_t items, uint32_t beginIndex)
{
	if (evar->type < evartype_t::EVAR_ARRAY || items > evar->arrayValue.size())
		return;

	switch (evar->type) {
	case evartype_t::EVAR_ARRAY:
		for (uint32_t i = beginIndex; i < beginIndex + items; i++) {

			if (i >= evar->arrayValue.size())
				break;

			evar->arrayValue[i] = valueArray[i];
		}
		break;

	}

}
std::vector<evar_s*> Evar_GetAlphabetically()
{
	std::vector<std::string> evar_names;
	std::vector<evar_s*> evars;

	for (uint32_t i = 0; i < evarCount; i++) {
		evar_s* evar = evarList[i];

		if (evar)
			evar_names.push_back(evar->name);
	}

	std::sort(evar_names.begin(), evar_names.end());

	for (auto& i : evar_names) {
		evar_s* evar = Evar_FindByName(i.c_str());

		if (evar)
			evars.push_back(evar);
	}

	return evars;

}
void Evar_Setup()
{
	evarCount = 0;

	vars::cfg::cfgDirectory = fs::GetExePath() + "\\big_hack.cfg";

	Evar_Register(&vars::invincibility, "invincibility", evartype_t::EVAR_BOOL, (float)0);
	Evar_Register(&vars::no_fire_delay, "no_fire_delay", evartype_t::EVAR_BOOL, (float)0);
	Evar_Register(&vars::spread_angle,  "spread_angle",  evartype_t::EVAR_FLOAT, 10);

}