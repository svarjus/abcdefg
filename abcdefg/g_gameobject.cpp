
#include "pch.h"

g::GameObject* g::GetPlayer(int playerIndex)
{
	GameObject* lastTaggedGameObject = GameObjectManager->GameObjectManagerObj->LastTaggedObject2->gameObject;
	BaseObject* nextNode = GameObjectManager->GameObjectManagerObj->TaggedObject2;

	char* name = GameObjectManager->GameObjectManagerObj->TaggedObject2->gameObject->name;



	return nullptr;
}
uintptr_t g::getComponentById(uintptr_t ComponentList, int id)
{
	return *(uintptr_t*)(ComponentList + (0x8 + (id * 0x10)));
}
int g::GetAlivePlayers()
{
	int count(0);
	GameObject* lastTaggedGameObject = GameObjectManager->GameObjectManagerObj->LastTaggedObject2->gameObject;
	BaseObject* nextNode = GameObjectManager->GameObjectManagerObj->TaggedObject2;

	if (nextNode) {
		while (true) {

			GameObject* gameObject = nextNode->gameObject;
			if (!gameObject)
				break;

			if (!&gameObject->name)
				break;

			const uintptr_t validLoc = (uintptr_t)(gameObject->name);

			if (!validLoc || validLoc > 0xFFFFFFFFFFFFFFF) {
				break;
			}

			try {
				if (strstr(gameObject->name, "PlayerAvatar")) {
					count++;
				}
			}
			catch (std::exception& ex) {

				std::cout << "exception caught: " << ex.what() << '\n';

				break;
			}



			if (gameObject == lastTaggedGameObject)
				break;
			nextNode = nextNode->nextObject;

		}
		return count;
	}

}