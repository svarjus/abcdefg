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


	uintptr_t getComponentById(const uintptr_t ComponentList, const int id);
	GameObject* GetPlayer(const int playerIndex);
	void GetPlayerOrigin(const GameObject* obj, vec3_t out);
	void GetPlayerAngles(const GameObject* obj, vec3_t out);

	void GetAllPlayers();
	int GetAlivePlayers();
}

#endif