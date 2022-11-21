#pragma once

#ifndef ubojects
#define ubojects

#include "pch.h"

namespace g
{
	struct vec3
	{
		vec3(float x, float y, float z) {
			this->x = x;
			this->y = y;
			this->z = z;

		}
		bool operator==(vec3 b) {
			return this->x == b.x 
				&& this->y == b.y 
				&& this->z == b.z;
		}
		float x, y, z;
	};

	struct PlayerTransform_s
	{
		float pad[15];
		float yaw;
		vec3_t origin; //xzy
		float pad01[10];
		float zVelocity;

	};
	inline PlayerTransform_s PlayerTransform;
	inline PlayerTransform_s* PlayerTransform_ptr;
}

#endif