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
void g::OutskirtsKeyPad_Press(OutskirtsKeypad_o* keypad, int num, const MethodInfo* method)
{
	outskirts_keypad_obj = reinterpret_cast<OutskirtsKeypad_o*>(keypad);
	outskirts_method = const_cast<MethodInfo*>(method);

	printf("keypad: 0x%p\n", keypad);
	printf("number: %i\n", num);
	printf("methodInfo: 0x%p\n", method);

	return OutskirtsKeyPad_Press_f(keypad, num, method);
}
