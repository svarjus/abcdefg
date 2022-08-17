
#include "pch.h"
void g::CG_DllEntry(HMODULE hModule, LPTHREAD_START_ROUTINE startAddr)
{

	AllocConsole();
	FILE* fp;
	freopen_s(&fp, "CONOUT$", "w", stdout);

	
	R_Init();
}