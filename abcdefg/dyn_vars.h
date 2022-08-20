#pragma once


#ifndef dynvars
#define dynvars

#include "pch.h"

namespace vars
{
	namespace cfg
	{
		inline std::string cfgDirectory;
	}
	inline evar_s invincibility;
	inline evar_s no_fire_delay;

	inline evar_s spread_angle;
	inline evar_s weapon_damage;
	inline evar_s weapon_spread;
	inline evar_s weapon_magazineSize;

	inline evar_s world_skywalk;
	inline evar_s world_skywalk_z;
}

#endif