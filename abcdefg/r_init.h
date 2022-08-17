#pragma once

#ifndef rinit
#define rinit

#include "pch.h"

namespace g
{
	typedef long(__stdcall* endScene)(IDXGISwapChain*, UINT, UINT);
	inline endScene pEndScene;

	endScene GetEndScene();
	void R_Init();
	long __stdcall D3D_Draw(IDXGISwapChain* p_swap_chain, UINT sync_interval, UINT flags);
}

#endif