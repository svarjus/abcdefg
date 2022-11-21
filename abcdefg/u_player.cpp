#include "pch.h"

uint32_t __fastcall g::UE_PlayerTransform(PlayerTransform_s* transform, void* a2, float a3, void* a4)
{
	memcpy(&PlayerTransform, transform, sizeof(PlayerTransform_s));
	PlayerTransform_ptr = reinterpret_cast<PlayerTransform_s*>(transform);
	//UE_Noclip(transform);

	XZY2XYZ(transform->origin, _tp.myCoords);


	if (v::world_skywalk.isEnabled())
		transform->origin[1] = v::world_skywalk_z.GetFloat();

	//transform->yaw = 0.5;

	if (v::tp_spam.isEnabled()) {

		if (players.size() > 0) {
			int pNum = rand() % players.size();
			vec3_t test;
			vec3_t org;
			GameObject* player = players[pNum];
			GetPlayerOrigin(player, org);
			VectorCopy(org, test);
			test[1] -= v::tp_spam_offset.GetFloat();
			VectorCopy(test, transform->origin); 


		}
		else
			VectorCopy(_tp.tpcoords, transform->origin);
	}

	if (v::epic_jump.isEnabled()) {
		if (GetAsyncKeyState(VK_SPACE) & 1 && PlayerController_ptr) {
			transform->zVelocity += 5;
		}
		
	}
	//if (GetAlivePlayers() > 0) {
	//	GameObject* p = players[0];
	//	vec3_t org, out;
	//	GetPlayerOrigin(p, org);
	//	VectorToAngles(PlayerTransform.origin, org, out);

	//	PlayerTransform_ptr->yaw = out[YAW] / 180.f;
	//}

	return UE_PlayerTransform_h(transform, a2, a3, a4);
}
//int64_t __fastcall g::UE_OpenURL(intptr_t* unsure)
//{
//
//	auto TextToBytes = [](const char* text, char* buffer, size_t size) -> void { //123 -> \x31\x00\x32\x00\x33
//		int j = 0;
//		for (int i = 0; i < size; i++) {
//			buffer[i] = (text[j]);
//			i++;
//			buffer[i] = 0x00;
//			j++;
//		}
//
//	};
//
//	hook* a = nullptr;
//
//	std::cout << "opening url: ["; 
//	
//	std::string oj;
//
//	intptr_t* steamid_offset{};
//	intptr_t* ban_offset{};
//
//	for (int i = 2; i < 128; i++) {
//
//		char ah = *((char*)unsure + i);
//
//		if (*((char*)unsure + i) == 'i' && *((char*)unsure + i + 2) == 'n' && *((char*)unsure + i + 4) == 'f' && *((char*)unsure + i + 6) == 'o')
//			steamid_offset = (intptr_t*)(((char*)unsure+i+10));
//		
//		else if (*((char*)unsure + i) == 'b' && *((char*)unsure + i + 2) == 'a' && *((char*)unsure + i + 4) == 'n' && *((char*)unsure + i + 6) == 's')
//			ban_offset = (intptr_t*)(((char*)unsure + i));
//
//		if (std::isalnum(ah) || ah == '\\' || ah == '/' || ah == '.' || ah == ':') {
//			std::cout << ah;
//			oj.push_back(ah);
//		}
//
//
//	}
//	bool isSteamID = oj.find("info\\7") != std::string::npos;
//	bool isBan = oj.find(".com/bans") != std::string::npos;
//
//	std::string idFound = isSteamID == true ? "   <-- is steamID" : "";
//	std::string wantsBan = isBan == true ? "   <-- ban!" : "";
//
//	std::cout << "] from: 0x" << std::hex << (unsure) << idFound << wantsBan << '\n';
//	if (isSteamID) {
//
//
//		std::cout << "steamid_offset: [0x" << std::hex << steamid_offset << "]\n";
//
//			char buff[17 * 2 + 1];
//
//			TextToBytes("76561198057087288", buff, 17 * 2);
//
//			a->write_addr(steamid_offset, buff, 17 * 2 + 1); 
//		
//		//a->write_addr((GameAssembly + 0x3FF06B), "\x84", 1); //jump not equal (skip the if(isBanned) { crash game; } )
//
//		//once = false;
//		
//		
//
//	}else if(isBan) { 
//		char buff[8];
//		TextToBytes("fuck", buff, 8);
//		std::cout << "ban_offset: [0x" << std::hex << ban_offset << "]\n";
//		a->write_addr(unsure+4, buff, 8); //changing the url does not evade; maybe the url is being read elsewhere!
//
//	}
//
//	//1538200691488
//
//	intptr_t url = OpenURL_h(unsure);
//
//	if(isSteamID)
//		std::cout << "url returns: 0x" << std::hex << url << '\n';  
//
//	return url;
//
//}
void __fastcall g::UE_PlayerInfo(float* a1, DWORD* a2)
{
	PlayerInfo_f(a1, a2);
	if (GetAsyncKeyState(VK_HOME) & 1) {
		system("cls"); 
		for (int i = 8; i < 11; i++) {
			std::cout << "a1[" << i << "]: " << (float)a1[i] << '\n';
		}
		_tp.needs_teleport = true;

	}
	vec3_t coords = { a1[8], a1[9] - 1.5f, a1[10] };
	VectorCopy(coords, _tp.tpcoords);


}
char g::UE_PlayerData(uintptr_t* a1, float *a2, char a3)
{

	if (GetAsyncKeyState(VK_NUMPAD7) & 1) {
		printf("arg1: 0x%p\n", a1);
	}

	return PlayerData_f(a1, a2, a3);
}