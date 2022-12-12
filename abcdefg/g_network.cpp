
#include "pch.h"


g::MyceliumPlayer_o* g::MyceliumNetwork::GetLocalPlayer()
{
	return ((MyceliumPlayer_o * (*)())MyceliumNetwork__get_LocalPlayer)();
}
g::MyceliumPlayer_o* g::MyceliumNetwork::GetLobbyHost()
{

	return ((MyceliumPlayer_o * (*)())MyceliumNetwork__get_LobbyHost)();

}
int32_t g::MyceliumNetwork::GetMaxPlayers()
{
	return ((int32_t (*)())MyceliumNetwork__get_MaxPlayers)();

}
int32_t g::MyceliumNetwork::GetPlayerCount()
{
	return ((int32_t(*)())MyceliumNetwork__get_PlayerCount)();

}
//std::string g::MyceliumNetwork::GetLobbyName()
//{
//	System_String_o* str = ((System_String_o*(*)())MyceliumNetwork__get_LobbyName)();
//
//	if (!str)
//		return "";
//
//	return ResolveSystemString(str);
//
//}
bool g::MyceliumNetwork::AmIHost()
{
	return ((bool(*)())MyceliumNetwork__get_IsHost)();

}
//float g::MyceliumNetwork::GetLobbyTime()
//{
//	return (float)((double(__stdcall*)(MethodInfo* method))MyceliumNetwork__get_Time)(0i64);
//
//}