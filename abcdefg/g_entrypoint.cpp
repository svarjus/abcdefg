
#include "pch.h"

void g::CG_DllEntry(HMODULE hModule, LPTHREAD_START_ROUTINE startAddr)
{

	AllocConsole();
	FILE* fp;
	freopen_s(&fp, "CONOUT$", "w", stdout);

	fnIl2cpp_resolve_icall = (tpIl2cpp_resolve_icall*)GetProcAddress((HMODULE)gAssembly.lpBaseOfDll, EXPORT_IL2CPP_RESOLVE_ICALL);

	G_TestFunction();
}