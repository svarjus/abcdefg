
#include "pch.h"

bool Evar_SaveToFile(std::string directory)
{
	std::fstream f;

	if (directory.size() < 2) {
		std::cout << "can't load config.. search directory is NULL\n";
		return false;
	}

	if (!fs::F_OpenFile(f, directory, fs::fileopen::FILE_OUT))
		return false;

	std::vector<evar_s*> evars = Evar_GetAlphabetically();

	for (auto &evar : evars) {
		
		//evar_s* evar = evarList[i];

		if (!evar)
			continue;

		switch (evar->type) {
			case evartype_t::EVAR_BOOL:		f << evar->name << " = " << evar->enabled		<< ";\n";		break;
			case evartype_t::EVAR_INT:		f << evar->name << " = " << evar->intValue		<< ";\n";		break;
			case evartype_t::EVAR_FLOAT:	f << evar->name << " = " << evar->floatValue	<< ";\n";		break;
			case evartype_t::EVAR_VEC2:		f << evar->name << " = " << evar->vec2Value[0] << ' ' << evar->vec2Value[1] << ";\n";		break;
			case evartype_t::EVAR_VEC3:		f << evar->name << " = " << evar->vec3Value[0] << ' ' << evar->vec3Value[1] << ' ' << evar->vec3Value[2] << ";\n";		break;
			case evartype_t::EVAR_VEC4:		f << evar->name << " = " << evar->vec4Value[0] << ' ' << evar->vec4Value[1] << ' ' << evar->vec4Value[2] << ' ' << evar->vec4Value[3] << ";\n";		break;
			case evartype_t::EVAR_ARRAY:
			{
				f << evar->name << " = ";
				for (uint32_t i = 0; i < evar->arrayValue.size(); i++)
				{
					f << evar->arrayValue[i];
					if(i != evar->arrayValue.size() - 1)
						f << ' ';
				}
				f << ";\n";

				break;
			}
			default:	break;
		}
	}
	fs::F_CloseFile(f);

	return true;
}
std::string var;
bool Evar_LoadVector(std::fstream& f, evar_s* evar, vec4_t vec)
{
	//assuming next character is the first number of the first index

	static const auto CheckValid = [](std::string var, float& vec) -> void {
		if (var == "N/A") {
			vec = 0.f;
			return;
		}
		vec = std::stof(var.c_str());
	}; 

	if (evar->type < evartype_t::EVAR_ARRAY) { //could also work for arrays, but I prefer to have it separate
		var = fs::F_ReadUntil(f, ' ');
		CheckValid(var, vec[0]);

		var = fs::F_ReadUntil(f, evar->type == evartype_t::EVAR_VEC2 ? '\n' : ' ');
		CheckValid(var, vec[1]);

		if (evar->type == evartype_t::EVAR_VEC2)
			return true;

		var = fs::F_ReadUntil(f, evar->type == evartype_t::EVAR_VEC3 ? '\n' : ' ');
		CheckValid(var, vec[2]);

		if (evar->type == evartype_t::EVAR_VEC3)
			return true;

		var = fs::F_ReadUntil(f, '\n');
		CheckValid(var, vec[3]);
	}
	else if (evar->type == evartype_t::EVAR_ARRAY) {
		size_t arraySize = evar->arrayValue.size();
		for (uint32_t i = 0; i < arraySize; i++) {

			if(i < arraySize - 1)
				var = fs::F_ReadUntil(f, ' ');
			else
				var = fs::F_ReadUntil(f, '\n');
			CheckValid(var, evar->arrayValue[i]);
		}
	}
	return true;


}
bool Evar_LoadFromFile(std::string directory)
{
	if (directory.size() < 2) {
		std::cout << "can't load config.. search directory is NULL\n";
		return false;
	}

	std::fstream f;
	uint32_t vars_read = 0;
	char ch{};
	static vec4_t vec{};

	if (!fs::F_OpenFile(f, directory, fs::fileopen::FILE_IN)) 
		return false;
	
	while (f.good()) {


		var = fs::F_ReadUntil(f, ' ');
		if (var == "N/A" || (!std::isalnum(var[0]))) {
			fs::F_ReadUntil(f, '\n');
			continue;
		}
		evar_s* evar = Evar_FindByName(var.c_str());

		f.get(ch); // '='
		f.get(ch); // ' '
	

		if (evar) {
			if (!evar->initialized)
				continue;
			if (evar->type > evartype_t::EVAR_FLOAT) {
				Evar_LoadVector(f, evar, vec);

				if(evar->type < evartype_t::EVAR_ARRAY)
					Evar_SetValue(evar, vec);

				vars_read++;
				continue;

			}

			else {
				std::string value = fs::F_ReadUntil(f, ';');
				if (value != "N/A") {
					Evar_SetValue(evar, std::stof(value.c_str()));
					vars_read++;

				}

			}
		}
		fs::F_ReadUntil(f, '\n');

	}
	std::cout << "total evars loaded: " << vars_read << '\n';
	return true;
}