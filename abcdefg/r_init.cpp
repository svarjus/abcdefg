#include "pch.h"

struct EnumData {
	DWORD dwProcessId;
	HWND hWnd;
};

BOOL CALLBACK EnumProc(HWND hWnd, LPARAM lParam) {
	EnumData& ed = *(EnumData*)lParam;
	DWORD dwProcessId = 0x0;
	GetWindowThreadProcessId(hWnd, &dwProcessId);
	if (ed.dwProcessId == dwProcessId) {
		ed.hWnd = hWnd;
		SetLastError(ERROR_SUCCESS);
		return FALSE;
	}
	return TRUE;
}

HWND findWindowFromProcessId(DWORD dwProcessId) {
	EnumData ed = { dwProcessId };
	if (!EnumWindows(EnumProc, (LPARAM)&ed) &&
		(GetLastError() == ERROR_SUCCESS)) {
		return ed.hWnd;
	}
	return NULL;
}
g::endScene g::GetEndScene()
{
	DXGI_SWAP_CHAIN_DESC sd;
	ZeroMemory(&sd, sizeof(sd));
	sd.BufferCount = 2;
	sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	HANDLE handle = GetCurrentProcess();
	DWORD pid = GetProcessId(handle);
	HWND window = findWindowFromProcessId(pid);
	sd.OutputWindow = window;
	sd.SampleDesc.Count = 1;
	sd.Windowed = TRUE;
	sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

	IDXGISwapChain* swap_chain;
	ID3D11Device* device;

	const D3D_FEATURE_LEVEL feature_levels[] = { D3D_FEATURE_LEVEL_11_0, D3D_FEATURE_LEVEL_10_0, };
	if (D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, 0, feature_levels, 2, D3D11_SDK_VERSION, &sd, &swap_chain, &device, nullptr, nullptr) == S_OK){
		void** vTable = *reinterpret_cast<void***>(swap_chain);
		swap_chain->Release();
		device->Release();

		return (endScene)vTable[8];
	}
	return nullptr;
}
void g::R_Init()
{
	pEndScene = GetEndScene();

	if (!pEndScene) {
		MessageBox(NULL, "faield", "ouldn't fidn ecnxenece", 0);
		exit(-1);
	}
	hook* a = nullptr;
	a->install_x64(&(PVOID&)pEndScene, D3D_Draw);
	G_Init();
}
long __stdcall g::D3D_Draw(IDXGISwapChain* p_swap_chain, UINT sync_interval, UINT flags)
{


	G_SetVariables();

	return pEndScene(p_swap_chain, sync_interval, flags);
}