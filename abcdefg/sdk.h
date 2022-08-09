#pragma once

#ifndef sdk_
#define sdk_

#include "pch.h"

char* scanBasic(char* pattern, char* mask, char* begin, intptr_t size);
uintptr_t findPattern(char* pattern, char* mask, MODULEINFO targetModule);
uint64_t absoluteAddress(uint64_t address, uint64_t offset);
MODULEINFO getModuleInfo(char* szModule);

#endif
