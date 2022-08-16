#pragma once

#ifndef gobjects
#define gobjects

#include "pch.h"

#define PATTERN_PLAYERCONTROLLER (char*)"\x48\x8B\x05\x00\x00\x00\x00\x48\x8B\x88\x00\x00\x00\x00\x44\x88\x71\x20"
#define MASK_PLAYERCONTROLLER (char*)"xxx????xxx????xxxx"


#define EXPORT_GET_WIDTH "UnityEngine.Screen::get_width()"
#define EXPORT_GET_HEIGHT "UnityEngine.Screen::get_height()"
#define EXPORT_LIMITFRAMERATE "UnityEngine.Application::set_targetFrameRate(System.Int32)"
#define EXPORT_OPENURL "UnityEngine.Application::OpenURL(System.String)"
#define EXPORT_QUIT "SteamDLCManager.HasDLC(System.Int32)"

//export from gameAssembly.dll
#define EXPORT_IL2CPP_STRING_NEW  "il2cpp_string_new"
#define EXPORT_IL2CPP_RESOLVE_ICALL "il2cpp_resolve_icall"
namespace g
{

	typedef void* tpIl2cpp_resolve_icall(const char*);
	inline tpIl2cpp_resolve_icall* fnIl2cpp_resolve_icall;
	typedef int tpGetWindowWitdh();
	typedef int tpSetWindowResolution(int width, int height, bool fullscreen);
	typedef void tpSetFPS(int32_t value);
	typedef void tpOpenURL(const char* url);
	typedef bool tpQuit(uint32_t dlc);
	typedef void PC_GetHealth();



	class LastObjectBase
	{
	public:
		char pad_0000[16]; //0x0000
		class GameObject* gameObject; //0x0010
	}; //Size: 0x0018


	class BaseObject
	{
	public:
		char pad_0000[8]; //0x0000
		class BaseObject* nextObject; //0x0008
		class GameObject* gameObject; //0x0010
	}; //Size: 0x0018


	class GameObject
	{
	public:
		char pad_0000[48]; //0x0000
		class CompList* ComponentList; //0x0030
		char pad_0038[8]; //0x0038
		uint32_t ComponentSize; //0x0040
		char pad_0044[12]; //0x0044
		uint32_t layer; //0x0050
		uint16_t tag; //0x0054
		char pad_0056[10]; //0x0056
		char* name; //0x0060
	}; //Size: 0x0068

	class GameObjectManager
	{
	public:
		class LastObjectBase* LastTaggedObject; //0x0000
		class BaseObject* TaggedObjects; //0x0008
		class LastObjectBase* LastActiveObject; //0x0010
		class BaseObject* ActiveObjects; //0x0018
		class LastObjectBase* LastTaggedObject2; //0x0020
		class BaseObject* TaggedObject2; //0x0028
	}; //Size: 0x0030


	class ComponentBase
	{
	public:
		char pad_0000[40]; //0x0000
		class Ilcpp2Object* fields; //0x0028
	}; //Size: 0x0030

	class Ilcpp2Object
	{
	public:
		class Il2CppClass* klass; //0x0000
	}; //Size: 0x0008

	class Il2CppClass
	{
	public:
		char pad_0000[16]; //0x0000
		char* compname; //0x0010
	}; //Size: 0x0018
	class ObscuredInt
	{
	public:
		uint32_t offset; //0x0000
		uint32_t value; //0x0004
		int getValue();
		void setValue(int value);
	}; //Size: 0x0008

	class Item
	{
	public:
		char pad_0000[24]; //0x0000
		class WeaponStats* info; //0x0018
		char pad_0020[8]; //0x0020
		float bulletSpread; //0x0028
		class ObscuredInt ammo; //0x002C
		class ObscuredInt totalAmmo; //0x0034
		float nextTimeToUse; //0x003C
		void* weaponModSight; //0x0040
		void* directionalParticles; //0x0048
		void* effectParticles; //0x0050
	}; //Size: 0x0058


	class ItemPointer
	{
	public:
		class Item* item; //0x0000
	}; //Size: 0x0008

	class ItemArray
	{
	public:
		char pad_0000[24]; //0x0000
		uint32_t count; //0x0018
		char pad_001C[4]; //0x001C
		class ItemPointer elements[3]; //0x0020
	}; //Size: 0x0038

	class WeaponStats
	{
	public:
		char pad_0000[24]; //0x0000
		uint32_t type; //0x0018
		uint32_t damage; //0x001C
		float useDelay; //0x0020
		uint32_t shots; //0x0024
		float cameraShake; //0x0028
		float adsCameraShake; //0x002C
		float reloadTime; //0x0030
		uint32_t magazineSize; //0x0034
		uint32_t startingAmmo; //0x0038
		uint32_t individualReload; //0x003C
		float bulletSpread; //0x0040
		float adsBulletSpread; //0x0044
		float maxbulletSpread; //0x0048
		float bulletSpreadDecrease; //0x004C
		float normalSpread; //0x0050
		float adsSpread; //0x0054
		float movementSpreadMultiplier; //0x0058
		float adsMovementSpreadMultiplier; //0x005C
		float movementADSAnimationMultiplier; //0x0060
		float adsFOVChange; //0x0064
		float cameraADSBobMultiplier; //0x0068
		bool useScopedMouseSensitivity; //0x006C
		char pad_006D[3]; //0x006D
		void* animationLayers; //0x0070
		void* fireSound; //0x0078
		void* icon; //0x0080
		uint32_t damageData; //0x0088
		char pad_008C[4]; //0x008C
		void* permanentEffectPrefab; //0x0090
		uint32_t projectileColliderMask; //0x0098
		uint32_t crosshairType; //0x009C
		uint32_t damageMultiplierRoomSetting; //0x00A0
		bool noscope; //0x00A4
	}; //Size: 0x00A5

	class PlayerController_c__StaticFields
	{
	public:
		char pad_0000[24]; //0x0000
		class PlayerController_fields* LocalPlayer; //0x0018
	}; //Size: 0x0020

	class PlayerController_fields
	{
	public:
		char pad_0000[104]; //0x0000
		class ItemArray* items; //0x0068
		char pad_0070[136]; //0x0070
		class N000006E5* N0000035F; //0x00F8
		char pad_0100[80]; //0x0100
		float bulletSpread; //0x0150
		char pad_0154[52]; //0x0154
	}; //Size: 0x0188

	class PlayerController_c__Class
	{
	public:
		char pad_0000[184]; //0x0000
		class PlayerController_c__StaticFields* static_fields; //0x00B8
	}; //Size: 0x00C0

	class PlayerController_c
	{
	public:
		class PlayerController_c__Class* klass; //0x0000
	}; //Size: 0x0008


}

#endif