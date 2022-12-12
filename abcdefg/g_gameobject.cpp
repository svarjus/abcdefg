
#include "pch.h"

g::GameObject* g::GetPlayer(const int playerIndex)
{
	return players.size() > playerIndex ? players[playerIndex] : nullptr;
}
uintptr_t g::getComponentById(const uintptr_t ComponentList, const int id)
{
	return *(uintptr_t*)(ComponentList + (0x8 + (id * 0x10)));
}
int g::GetAlivePlayers()
{
	return players.size();

}
void g::GetAllPlayers()
{
	players.clear();
	players.resize(0);

	const GameObject* lastTaggedGameObject = GameObjectManager->GameObjectManagerObj->LastTaggedObject2->gameObject;
	BaseObject* nextNode = GameObjectManager->GameObjectManagerObj->TaggedObject2;

	if (nextNode) {
		while (true) {
			GameObject* gameObject = nextNode->gameObject;
			if (!gameObject)
				break;

			if (!&gameObject->name)
				break;

			const uintptr_t validLoc = (uintptr_t)(gameObject->name);

			if (!validLoc || validLoc > 0xFFFFFFFFFFFFFFF)
				break;

			if (strstr(gameObject->name, "PlayerAvatar")) 
				players.push_back(gameObject);
			
			if (gameObject == lastTaggedGameObject)
				break;
			nextNode = nextNode->nextObject;


		}
	}
	//if (GetAsyncKeyState(VK_NUMPAD4) & 1 && players.empty() == false) {
	//	int hits(0);
	//	for (auto& i : players) {
	//		printf("localplayer: 0x%p\n", PlayerController_ptr);
	//		printf("gameobject: 0x%p\n", players[0]);

	//		if ((void*)i == (void*)PlayerController_ptr)
	//			hits++;
	//	}
	//	if (hits > 0) {
	//		printf("localplayer == gameobject\n");

	//	}else
	//		printf("localplayer != gameobject\n");


	//}
}
void g::GetPlayerOrigin(const GameObject* obj, vec3_t out)
{
	if (!obj)
		return;

	if (!&obj->name)
		return;

	const uintptr_t validLoc = (uintptr_t)(obj->name);

	if (!validLoc || validLoc > 0xFFFFFFFFFFFFFFF)
		return;

	const uint64_t compList = (uint64_t)obj->ComponentList;
	const uint64_t tranform = getComponentById(compList, 0);
	uint64_t tranform_internal = *(uint64_t*)(tranform + 0x38);
	tranform_internal += 144;

	if (GetAsyncKeyState(VK_NUMPAD1) & 1)
		std::cout << "tranform_internal.x: 0x" << std::hex << tranform_internal << '\n';

	out[0] = *(float*)(tranform_internal);
	out[1] = *(float*)(tranform_internal + 4);
	out[2] = *(float*)(tranform_internal + 8);
}
void g::GetPlayerAngles(const GameObject* obj, vec3_t out)
{
	const uint64_t compList = (uint64_t)obj->ComponentList;
	const uint64_t transform = getComponentById(compList, 0);
	uint64_t transform_internal = *(uint64_t*)(transform + 0x38);
	transform_internal += 144 + 20;

	out[0] = *(float*)(transform_internal);
	out[1] = *(float*)(transform_internal + 4);
	out[2] = *(float*)(transform_internal + 8);
}