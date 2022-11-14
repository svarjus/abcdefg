#pragma once

#ifndef gdlc
#define gdlc

#include "pch.h"

namespace g
{
	inline bool(*SteamDLCManager__HasDLC_h)(int32_t dlc);
	bool SteamDLCManager__HasDLC(int32_t dlc);
	
}

#endif