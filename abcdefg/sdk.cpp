#include "pch.h"


char* scanBasic(char* pattern, char* mask, char* begin, intptr_t size)
{
	intptr_t patternLen = strlen(mask);

	for (int i = 0; i < size; i++)
	{
		bool found = true;
		for (int j = 0; j < patternLen; j++)
		{
			if (mask[j] != '?' && pattern[j] != *(char*)((intptr_t)begin + i + j))
			{
				found = false;
				break;
			}
		}
		if (found)
		{
			return (begin + i);
		}
	}
	return nullptr;
}
uintptr_t findPattern(char* pattern, char* mask, MODULEINFO targetModule)
{
	char* match{ nullptr };
	MEMORY_BASIC_INFORMATION mbi{};
	int size = targetModule.SizeOfImage;
	char* begin = (char*)targetModule.lpBaseOfDll;

	for (char* curr = begin; curr < begin + size; curr += mbi.RegionSize)
	{
		if (!VirtualQuery(curr, &mbi, sizeof(mbi)) || mbi.State != MEM_COMMIT || mbi.Protect == PAGE_NOACCESS) continue;

		match = scanBasic(pattern, mask, curr, mbi.RegionSize);

		if (match != nullptr)
		{
			break;
		}
	}
	return (uintptr_t)match;
}

uint64_t absoluteAddress(uint64_t address, uint64_t offset)
{
	if (!address)
		return 0;

	uint64_t v = *(int*)(address + offset);
	return v + (address + offset) + 4;
}
MODULEINFO getModuleInfo(char* szModule)
{
	MODULEINFO modinfo = { 0 };
	HMODULE hModule = GetModuleHandle(szModule);
	if (hModule == 0)
		return modinfo;
	GetModuleInformation(GetCurrentProcess(), hModule, &modinfo, sizeof(MODULEINFO));
	return modinfo;
}