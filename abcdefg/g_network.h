#pragma once

#ifndef gnetwork
#define gnetwork

#include "pch.h"

namespace g
{
	inline uintptr_t MyceliumNetwork__get_LocalPlayer;
	inline uintptr_t MyceliumNetwork__get_LobbyHost;
	inline uintptr_t MyceliumNetwork__get_LobbyName;
	inline uintptr_t MyceliumNetwork__get_MaxPlayers;
	inline uintptr_t MyceliumNetwork__get_IsHost;
	inline uintptr_t MyceliumNetwork__get_Time;
	inline uintptr_t MyceliumNetwork__get_PlayerCount;

	namespace MyceliumNetwork {
		MyceliumPlayer_o* GetLocalPlayer();
		MyceliumPlayer_o* GetLobbyHost();
		int32_t GetMaxPlayers();
		int32_t GetPlayerCount();
		//std::string GetLobbyName();
		bool AmIHost();
		//float GetLobbyTime();
	}

}

#endif
