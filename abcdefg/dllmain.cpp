// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

static bool hooked = false;
BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{


    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        if (!hooked) {
            std::thread(g::CG_DllEntry, hModule, (LPTHREAD_START_ROUTINE)g::CG_DllEntry).detach();
            hooked = true;
        }
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}