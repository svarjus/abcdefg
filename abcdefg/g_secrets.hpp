#pragma once

#ifndef gsecrets
#define gsecrets

#include "pch.h"

namespace g
{
	inline OutskirtsKeypad_o* outskirts_keypad_obj;
	inline MethodInfo* outskirts_method;
	void RevealOutskirtsCode();

	inline void(*OutskirtsKeyPad_Press_f)(OutskirtsKeypad_o* keypad, int num, const MethodInfo* method);
	void OutskirtsKeyPad_Press(OutskirtsKeypad_o* keypad, int num, const MethodInfo* method);

}

#endif