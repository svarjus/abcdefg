

#include "pch.h"



void g::PlayerController_Update(PlayerController_c* playercontroller)
{
	memcpy(&g::PlayerController, playercontroller, sizeof(playercontroller));
	g::hasPlayerController = true;

	return Update_h(playercontroller);
}
//void g::UE_Noclip(PlayerTransform_s* transform) //unusable until viewangles are fixed
//{
//	vec3_t org;
//
//	float yaw = UE_ConvertGameYaw(transform->yaw);
//
//
//	if (GetAsyncKeyState('W') < 0) {
//		XZY2XYZ(transform->origin, org);
//
//		vec3_t angles = { 0, 0, 0};
//		vec3_t out;
//		AnglesToForward(angles, org, 1.01, out);
//
//		XYZ2XZY(out, transform->origin);
//	}
//}
uint32_t __fastcall g::UE_PlayerTransform(PlayerTransform_s* transform, void* a2, float a3, void* a4)
{
	memcpy(&PlayerTransform, transform, sizeof(PlayerTransform_s));
	//UE_Noclip(transform);
	if(vars::world_skywalk.enabled)
		transform->origin[1] = vars::world_skywalk_z.floatValue;
	return UE_PlayerTransform_h(transform, a2, a3, a4);
}
int64_t __fastcall g::UE_OpenURL(intptr_t* unsure)
{

	auto TextToBytes = [](const char* text, char* buffer, size_t size) -> void { //123 -> \x31\x00\x32\x00\x33
		int j = 0;
		for (int i = 0; i < size; i++) {
			buffer[i] = (text[j]);
			i++;
			buffer[i] = 0x00;
			j++;
		}

	};

	hook* a = nullptr;

	std::cout << "opening url: ["; 
	
	std::string oj;

	intptr_t* steamid_offset{};
	intptr_t* ban_offset{};

	for (int i = 2; i < 128; i++) {

		char ah = *((char*)unsure + i);

		if (*((char*)unsure + i) == 'i' && *((char*)unsure + i + 2) == 'n' && *((char*)unsure + i + 4) == 'f' && *((char*)unsure + i + 6) == 'o')
			steamid_offset = (intptr_t*)(((char*)unsure+i+10));
		
		else if (*((char*)unsure + i) == 'b' && *((char*)unsure + i + 2) == 'a' && *((char*)unsure + i + 4) == 'n' && *((char*)unsure + i + 6) == 's')
			ban_offset = (intptr_t*)(((char*)unsure + i));

		if (std::isalnum(ah) || ah == '\\' || ah == '/' || ah == '.' || ah == ':') {
			std::cout << ah;
			oj.push_back(ah);
		}


	}
	bool isSteamID = oj.find("info\\7") != std::string::npos;
	bool isBan = oj.find(".com/bans") != std::string::npos;

	std::string idFound = isSteamID == true ? "   <-- is steamID" : "";
	std::string wantsBan = isBan == true ? "   <-- ban!" : "";

	std::cout << "] from: 0x" << std::hex << (unsure) << idFound << wantsBan << '\n';
	static bool once = true;
	/*if (isSteamID) {
			
		if (once) {
			std::cout << "steamid_offset: [0x" << std::hex << steamid_offset << "]\n";

			char buff[17 * 2 + 1];

			TextToBytes("76561199250286491", buff, 17 * 2);

			a->write_addr(steamid_offset, buff, 17 * 2 + 1); //doing this kinda fucks up steam sync
		//}
		//once = false;
		

	}else */if(isBan) { 
		char buff[8];
		TextToBytes("fuck", buff, 8);
		std::cout << "ban_offset: [0x" << std::hex << ban_offset << "]\n";
		//a->write_addr(unsure+4, buff, 8); //changing the url does not evade; maybe the url is being read elsewhere!

	}

	//1538200691488

	return OpenURL_h(unsure);
}
void g::Bro_Idk(intptr_t* unknown, intptr_t* unknown2)
{
	static intptr_t* first = unknown;
	static intptr_t* second = unknown2;
	//if (unknown && unknown2) {
	//	std::cout << "unknown: [0x" << std::hex << unknown << "]\n";
	//	std::cout << "unknown2: [0x" << std::hex << unknown2 << "]\n";
	//}
	return bro_idk_h(first, second);
}