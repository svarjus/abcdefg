#pragma once

#ifndef gameobject
#define gameobject

#include "pch.h"

namespace g
{
	struct players_s
	{
		GameObject* gameObj;
		vec3_t origin;
		vec3_t originXYZ;
	};


	uintptr_t getComponentById(uintptr_t ComponentList, int id);
	GameObject* GetPlayer(int playerIndex);
}

#endif