#include "pch.h"

void g::RevealOutskirtsCode()
{
	int* code = ((int* (*)())(OutskirtsCodeGenerator__get_Code))(); //System_Int32_array* OutskirtsCodeGenerator__get_Code (const MethodInfo* method);
	int _codeArray[4];
	std::cout << "outskirts code: ";
	for (int i = 0; i < 4; i++) {
		_codeArray[i] = code[8 + i];
		std::cout << std::dec << _codeArray[i];

	}
	std::cout << '\n';
}