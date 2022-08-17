
#include "pch.h"

int g::ObscuredInt::getValue()
{
	return this->value - this->offset;
}

void g::ObscuredInt::setValue(int value)
{
	this->value = this->offset + value;
}

void g::CG_DllEntry(HMODULE hModule, LPTHREAD_START_ROUTINE startAddr)
{

	AllocConsole();
	FILE* fp;
	freopen_s(&fp, "CONOUT$", "w", stdout);

	
	R_Init();
}