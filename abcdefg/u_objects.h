#pragma once

#ifndef ubojects
#define ubojects

#include "pch.h"

namespace g
{
	

	struct PlayerTransform_s
	{
		float pad[15];
		float yaw;
		vec3_t origin; //xzy

	};
	inline PlayerTransform_s PlayerTransform;
}

#endif