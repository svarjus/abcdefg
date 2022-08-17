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
	gameWindow = findWindowFromProcessId(pid);
	sd.OutputWindow = gameWindow;
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
	a->install(&(PVOID&)pEndScene, D3D_Draw);

	Evar_Setup();
	Evar_LoadFromFile(vars::cfg::cfgDirectory);

	G_Init();
}
void g::R_GetID3D11_Device(IDXGISwapChain* p_swap_chain)
{
	static bool get_once = true;

	if (!get_once)
		return;

	get_once = false;

	if (p_swap_chain->GetDevice(__uuidof(ID3D11Device), (void**)&pDevice) != S_OK) {
		MessageBox(NULL, "failed", "p_swap_chain->GetDevice(__uuidof(ID3D11Device), (void**)&pDevice) != S_OK", 0);
		exit(-1);
	}
	pDevice->GetImmediateContext(&pContext);
	ID3D11Texture2D* pBackBuffer;
	p_swap_chain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);

	D3D11_RENDER_TARGET_VIEW_DESC desc = {};
	memset(&desc, 0, sizeof(desc));
	desc.Format = DXGI_FORMAT_R8G8B8A8_UNORM; // most important change!
	desc.ViewDimension = D3D11_RTV_DIMENSION_TEXTURE2D;

	pDevice->CreateRenderTargetView(pBackBuffer, &desc, &mainRenderTargetView);
	pBackBuffer->Release();

	oWndProc = (WNDPROC)SetWindowLongPtr(FindWindowA(NULL, "Redmatch 2"), GWLP_WNDPROC, (LONG_PTR)WndProc);
	R_InitImGui();
	std::cout << "directx is now active and ready!\n";


}
void g::R_InitImGui()
{
	if (!pDevice || !pContext) {
		MessageBox(NULL, "failed", "!pDevice || !pContext", 0);
		return;
	}
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;
	ImGui_ImplWin32_Init(FindWindowA(NULL, "Redmatch 2"));
	ImGui_ImplDX11_Init(pDevice, pContext);


}