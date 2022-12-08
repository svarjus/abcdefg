

#include "pch.h"
evar_o* Evar_FindByName(const char* name)
{
	evar_o* evar = nullptr;

	for (uint32_t i = 0; i < evarCount; i++) {
		evar = evarList[i];
		if (!strcmp(name, evar->evar->name))
			return evar;

	}
	return evar; //returns a nullptr on purpose
}
void evar_o::Register(const char* name, evartype_t type, float* defaultValue, uint32_t size, bool save) //arrays
{

	evar_s* evar = this->evar;

	if (type < evartype_t::EVAR_ARRAY || size < 1 || !evar)
		return;

	evar->arrayValue.reserve(size);
	evar->name = name;
	evar->type = type;
	evar->value = defaultValue[0];

	switch (type) {
	case evartype_t::EVAR_ARRAY:
		for (uint32_t i = 0; i < size; i++) {
			evar->arrayValue.push_back(defaultValue[i]);
		}
		break;
	}

	evarList[evarCount] = this;
	evar->Next = evarList[evarCount + 1];
	evarCount += 1;
	evar->initialized = true;
	evar->save = save;
}
void evar_o::Register(const char* name, evartype_t type, float* defaultValue, bool save)
{
	evar_s* evar = this->evar;

	if (type < evartype_t::EVAR_VEC2 || !evar)
		return;

	evar->name = name;
	evar->type = type;
	evar->value = defaultValue[0];
	switch (type) {
	case evartype_t::EVAR_VEC2:
		evar->enabled = (bool)defaultValue[0] && (bool)defaultValue[1];
		evar->vecValue[0] = defaultValue[0];
		evar->vecValue[1] = defaultValue[1];
		break;
	case evartype_t::EVAR_VEC3:
		evar->enabled = (bool)defaultValue[0] && (bool)defaultValue[1] && (bool)defaultValue[2];
		evar->vecValue[0] = defaultValue[0];
		evar->vecValue[1] = defaultValue[1];
		evar->vecValue[2] = defaultValue[2];
		break;
	case evartype_t::EVAR_VEC4:
		evar->enabled = (bool)defaultValue[0] && (bool)defaultValue[1] && (bool)defaultValue[2] && (bool)defaultValue[3];
		evar->vecValue[0] = defaultValue[0];
		evar->vecValue[1] = defaultValue[1];
		evar->vecValue[2] = defaultValue[2];
		evar->vecValue[3] = defaultValue[3];
		break;
	case evartype_t::EVAR_ARRAY:
		for (uint32_t i = 0; i < 32; i++) {

		}
		break;
	}
	evarList[evarCount] = this;
	evar->Next = evarList[evarCount + 1];
	evarCount += 1;
	evar->initialized = true;
	evar->save = save;


}
void evar_o::Register(const char* name, evartype_t type, const char* defaultValue, bool save)
{
	evar_s* evar = this->evar;

	if (type != evartype_t::EVAR_STRING || !evar)
		return;

	evar->type = evartype_t::EVAR_STRING;
	evar->name = name;
	evar->enabled = true;
	evar->value = 0;

	evar->stringValue = defaultValue;
	evarList[evarCount] = this;
	evar->Next = evarList[evarCount + 1];
	evarCount += 1;
	evar->initialized = true;
	evar->save = save;

}
void evar_o::Register(const char* name, evartype_t type, float defaultValue, bool save)
{
	evar_s* evar = this->evar;

	if (!evar) {
		return;
	}

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
	evarList[evarCount] = this;
	evar->Next = evarList[evarCount + 1];
	evarCount += 1;
	evar->initialized = true;
	evar->save = save;


}
void evar_o::SetValue(float value)
{
	evar_s* evar = this->evar;

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
void evar_o::SetValue(const char* value)
{
	evar_s* evar = this->evar;

	if (!evar) {
		printf("setvalue(string): passed a null\n");
		return;
	}

	evar->stringValue = value;
	printf("SetValue(%s): name: [%s] at: [0x%p]\n", value, evar->name, &evar->stringValue);
}
void evar_o::SetValue(float* value)
{
	evar_s* evar = this->evar;


	if (evar->type < evartype_t::EVAR_VEC2 || !evar)
		return;



	switch (evar->type) {
	case evartype_t::EVAR_VEC2:
		evar->enabled = (bool)value[0] && (bool)value[1];
		evar->vecValue[0] = value[0];
		evar->vecValue[1] = value[1];
		break;
	case evartype_t::EVAR_VEC3:
		evar->enabled = (bool)value[0] && (bool)value[1] && (bool)value[2];
		evar->vecValue[0] = value[0];
		evar->vecValue[1] = value[1];
		evar->vecValue[2] = value[2];
		break;
	case evartype_t::EVAR_VEC4:
		evar->enabled = (bool)value[0] && (bool)value[1] && (bool)value[2] && (bool)value[3];
		evar->vecValue[0] = value[0];
		evar->vecValue[1] = value[1];
		evar->vecValue[2] = value[2];
		evar->vecValue[3] = value[3];
		break;

	}

}
void evar_o::SetValue(float* valueArray, uint32_t items, uint32_t beginIndex)
{
	evar_s* evar = this->evar;
	if (evar->type < evartype_t::EVAR_ARRAY || items > evar->arrayValue.size() || !evar)
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
		evar_o* evar = evarList[i];

		if (evar)
			evar_names.push_back(evar->evar->name);
	}

	std::sort(evar_names.begin(), evar_names.end());

	for (auto& i : evar_names) {
		evar_o* evar = Evar_FindByName(i.c_str());

		if (evar)
			evars.push_back(evar->evar);
	}

	return evars;

}
void Evar_Setup()
{
	evarCount = 0;

	v::cfg::cfgDirectory = fs::GetExePath() + "\\big_hack.cfg";

	float mod_weapon_damage[4] = {100, 100, 100, 100};
	float mod_spread[4] = { 10, 10, 10, 10 };
	float mod_weapon_mag[4] = { 100, 100, 100, 100 };

	v::invincibility.Register		("invincibility",		evartype_t::EVAR_BOOL, (float)0,				true);
	v::no_fire_delay.Register		("no_fire_delay",		evartype_t::EVAR_BOOL, (float)0,				true);

	v::weapon_damage.Register		("weapon_damage",		evartype_t::EVAR_ARRAY, mod_weapon_damage, 4,	true);
	v::weapon_spread.Register		("weapon_spread",		evartype_t::EVAR_ARRAY, mod_spread, 4,			true);
	v::weapon_usedelay.Register		("weapon_usedelay",		evartype_t::EVAR_ARRAY, mod_weapon_mag, 4,		true);


	v::world_skywalk.Register		("world_skywalk",		evartype_t::EVAR_BOOL,	(float)0,				true);
	v::world_skywalk_z.Register		("world_skywalk_z",		evartype_t::EVAR_FLOAT, (float)0,				true);

	v::tp_spam.Register				("tp_spam",				evartype_t::EVAR_BOOL,	(float)0,				true);
	v::tp_spam_offset.Register		("tp_spam_offset",		evartype_t::EVAR_FLOAT, (float)-.125,			true);

	v::random_esp.Register			("random_esp",			evartype_t::EVAR_BOOL,	(float)0,				true);
	v::visual_recoil.Register		("visual_recoil",		evartype_t::EVAR_BOOL,	(float)0,				true);
	v::fire_effect.Register			("fire_effect",			evartype_t::EVAR_BOOL,	(float)0,				true);
	v::epic_jump.Register			("epic_jump",			evartype_t::EVAR_BOOL,	(float)0,				true);
	v::overwrite_chat.Register		("overwrite_chat",		evartype_t::EVAR_STRING, "HELLO",				true);
	v::moderator_authority.Register	("moderator_authority",	evartype_t::EVAR_BOOL,	(float)0,				true);
	v::bypass_anticheat.Register	("bypass_anticheat",	evartype_t::EVAR_BOOL,	(float)1,				true);




}
int evar_o::GetInt()
{
	return this->evar->intValue;
}
float evar_o::GetFloat()
{
	return this->evar->floatValue;
}
float evar_o::GetVector(uint32_t prm)
{
	return this->evar->vecValue[prm];
}
const char* evar_o::GetString()
{
	return this->evar->stringValue.c_str();
}
bool evar_o::isEnabled()
{
	return this->evar->enabled;
}
float evar_o::GetArray(uint32_t prm)
{
	return this->evar->arrayValue[prm];
}