

#include "pch.h"



void g::PlayerController_Update(PlayerController_c* playercontroller)
{
	//playercontroller
	Update_h(playercontroller);

 	memcpy(&g::PlayerController, playercontroller, sizeof(PlayerController_c));
	PlayerController_ptr = reinterpret_cast<PlayerController_c*>(playercontroller);;
	g::hasPlayerController = true;

	return;
}
bool g::WorldToScreen(int64_t camFields, vec3_t pos, vec3_t out)
{
	if (!fnWorldToScreenPoint || !&camFields)
		return false;

	fnWorldToScreenPoint(camFields, pos, 2, out);

	if (out[2] < 1.0f) 
		return false; 

	return true;
}

intptr_t __fastcall g::PrintChat(intptr_t* chat_manager, textobject* a2, uint32_t local, char target, intptr_t a5)
{
	//memcpy_s(&chatmanager, 64, chat_manager, 64);
	return PrintChat_f(chat_manager, a2, local, target, a5);

	chatmanager = reinterpret_cast<uintptr_t*>(chat_manager);
	auto TextToBytes = [](const char* text, char* buffer, size_t size) -> void { //123 -> \x31\x00\x32\x00\x33
		int j = 0;
		for (int i = 0; i < size; i++) {
			buffer[i] = (text[j]);
			i++;
			buffer[i] = 0x00;
			j++;
		}

	};
	char message[59*2];

	TextToBytes("Reported Player ID 76561199058900546 ([BLACKS4TRUMP] miche)", message, 58 * 2);

	memcpy(a2->message, &message, 58 *2);


	return PrintChat_f(chat_manager, a2, local, target, a5);
}
void g::PlayerManager__GotKilledByPlayer(MyceliumPlayer_o* killer, void* damageData, float distance, int16_t damagePacketID)
{

	if (killer) {
		std::cout << "killer " << killer << '\n';
		killer->fields._SteamID_k__BackingField.fields.m_SteamID = 76561198049109267;
	}

	return PlayerManager__GotKilledByPlayer_f(killer, damageData, distance, damagePacketID);

}
std::string g::ResolveSystemString(System_String_o* name) {

	std::string result;
	uintptr_t beginOffset = (uintptr_t)name + 20;

	for (int i = 0; i < name->fields.m_stringLength; i++) {

		result.push_back(*(char*)(beginOffset + i * 2));

	}
	return result;

}
void g::AntiCheat_Boost__OnAnyoneDeath(MyceliumPlayer_o* killer, MyceliumPlayer_o* victim, void* damageData)
{
	if (killer) {
		System_String_o* name = ((System_String_o*(*)(MyceliumPlayer_o*))(GameAssembly + 8769712))(killer);
 		if (name) {
			std::cout << "killer name: " << ResolveSystemString(name) << '\n';
		}
		//killer->fields._SteamID_k__BackingField.fields.m_SteamID = 76561199406343798;
		//victim->fields._SteamID_k__BackingField.fields.m_SteamID = 76561199393031416; //me

	}

	return AntiCheat_Boost__OnAnyoneDeath_f(killer, victim, damageData);
}
void g::SpectatorControllerOnAnyoneDeath(void* _this, MyceliumPlayer_o* killer, MyceliumPlayer_o* victim, void* damageData)
{
	if (killer) {
		System_String_o* name = ((System_String_o * (*)(MyceliumPlayer_o*))(GameAssembly + 8769712))(killer);
		if (name) {
			std::cout << "SpectatorControllerOnAnyoneDeath(): killer name: " << ResolveSystemString(name) << '\n';
		}

		killer->fields._SteamID_k__BackingField.fields.m_SteamID = 76561199406343798;
	}

	return SpectatorControllerOnAnyoneDeath_f(_this, killer, victim, damageData);
}
void g::AntiCheat__TakeAction(MyceliumPlayer_o* hacker, System_String_o* code)
{
	if (hacker) {
		System_String_o* name = ((System_String_o * (*)(MyceliumPlayer_o*))(GameAssembly + 8769712))(hacker);
		if (name) {
			std::cout << "hacker name: " << ResolveSystemString(name) << '\n';
		}
		hacker->fields._SteamID_k__BackingField.fields.m_SteamID = 76561199406343798;
		//victim->fields._SteamID_k__BackingField.fields.m_SteamID = 76561199393031416; //me

	}
}