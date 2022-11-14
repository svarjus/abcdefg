#pragma once

#ifndef rinit
#define rinit

#include "pch.h"
extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

namespace g
{
	typedef long(__stdcall* endScene)(IDXGISwapChain*, UINT, UINT);
	inline endScene pEndScene;
	inline ID3D11Device* pDevice;
	inline ID3D11DeviceContext* pContext;
	inline ID3D11RenderTargetView* mainRenderTargetView = NULL;

	inline HWND gameWindow;

	endScene GetEndScene();
	void R_Init();
	long __stdcall D3D_Draw(IDXGISwapChain* p_swap_chain, UINT sync_interval, UINT flags);
	void R_InitImGui();
	void R_GetID3D11_Device(IDXGISwapChain* p_swap_chain);
	void R_DrawThroughWalls();

	void R_MainLoop();

	inline WNDPROC oWndProc;
	extern LRESULT WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
}

#endif