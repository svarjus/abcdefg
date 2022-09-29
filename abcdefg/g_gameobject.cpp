
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