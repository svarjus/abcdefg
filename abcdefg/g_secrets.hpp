#pragma once

#ifndef gsecrets
#define gsecrets

#include "pch.h"

namespace g
{
	inline void* outskirts_keypad_obj;
	inline MethodInfo* outskirts_method;
	void RevealOutskirtsCode();

	inline void(*OutskirtsKeyPad_Press_f)(void* keypad, int num, const MethodInfo* method);
	void OutskirtsKeyPad_Press(void* keypad, int num, const MethodInfo* method);

}

#endif