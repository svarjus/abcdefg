#pragma once

#ifndef gobjects
#define gobjects

#include "pch.h"

#define UE_GET_WIDTH "UnityEngine.Screen::get_width()"
#define UE_GET_HEIGHT "UnityEngine.Screen::get_height()"


#define EXPORT_IL2CPP_STRING_NEW  "il2cpp_string_new"
#define EXPORT_IL2CPP_RESOLVE_ICALL "il2cpp_resolve_icall"

#define NOT_KNOWN 1

namespace g
{
	//w2s pasted from redmatchhax
	typedef void(__fastcall tp_WorldToScreenPoint)(uint64_t camera, vec3_t m_vWorld, int m_iEye, vec3_t m_vScreen);
	inline tp_WorldToScreenPoint* fnWorldToScreenPoint;

	typedef void* tpGetMainCamera();
	inline tpGetMainCamera* fnGetMainCamera;

	typedef void* (tpIl2cpp_resolve_icall)(const char*);
	inline tpIl2cpp_resolve_icall* fnIl2cpp_resolve_icall;
	typedef vec3_t UnityEngine_Transform_o; //probably very untrue

	struct Il2CppClass;
	struct MethodInfo;

	typedef void(*Il2CppMethodPointer)();


	struct VirtualInvokeData
	{
		Il2CppMethodPointer methodPtr;
		const MethodInfo* method;
	};

	typedef uintptr_t il2cpp_array_size_t;
	typedef int32_t il2cpp_array_lower_bound_t;
	struct Il2CppArrayBounds
	{
		il2cpp_array_size_t length;
		il2cpp_array_lower_bound_t lower_bound;
	};

	struct Il2CppObject
	{
		Il2CppClass* klass;
		void* monitor;
	};
	struct Il2CppType
	{
		void* data;
		unsigned int bits;
	};
	union Il2CppRGCTXData
	{
		void* rgctxDataDummy;
		const MethodInfo* method;
		const Il2CppType* type;
		Il2CppClass* klass;
	};
	struct Il2CppRuntimeInterfaceOffsetPair
	{
		Il2CppClass* interfaceType;
		int32_t offset;
	};
	struct Il2CppClass_1
	{
		void* image;
		void* gc_desc;
		const char* name;
		const char* namespaze;
		Il2CppType byval_arg;
		Il2CppType this_arg;
		Il2CppClass* element_class;
		Il2CppClass* castClass;
		Il2CppClass* declaringType;
		Il2CppClass* parent;
		void* generic_class;
		void* typeDefinition;
		void* interopData;
		Il2CppClass* klass;
		void* fields;
		void* events;
		void* properties;
		void* methods;
		Il2CppClass** nestedTypes;
		Il2CppClass** implementedInterfaces;
		Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
	};

	struct Il2CppClass_2
	{
		Il2CppClass** typeHierarchy;
		void* unity_user_data;
		uint32_t initializationExceptionGCHandle;
		uint32_t cctor_started;
		uint32_t cctor_finished;
		size_t cctor_thread;
		int32_t genericContainerIndex;
		uint32_t instance_size;
		uint32_t actualSize;
		uint32_t element_size;
		int32_t native_size;
		uint32_t static_fields_size;
		uint32_t thread_static_fields_size;
		int32_t thread_static_fields_offset;
		uint32_t flags;
		uint32_t token;
		uint16_t method_count;
		uint16_t property_count;
		uint16_t field_count;
		uint16_t event_count;
		uint16_t nested_type_count;
		uint16_t vtable_count;
		uint16_t interfaces_count;
		uint16_t interface_offsets_count;
		uint8_t typeHierarchyDepth;
		uint8_t genericRecursionDepth;
		uint8_t rank;
		uint8_t minimumAlignment;
		uint8_t naturalAligment;
		uint8_t packingSize;
		uint8_t bitflags1;
		uint8_t bitflags2;
	};
	struct System_String_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_CompareTo;
		VirtualInvokeData _5_Clone;
		VirtualInvokeData _6_GetTypeCode;
		VirtualInvokeData _7_System_IConvertible_ToBoolean;
		VirtualInvokeData _8_System_IConvertible_ToChar;
		VirtualInvokeData _9_System_IConvertible_ToSByte;
		VirtualInvokeData _10_System_IConvertible_ToByte;
		VirtualInvokeData _11_System_IConvertible_ToInt16;
		VirtualInvokeData _12_System_IConvertible_ToUInt16;
		VirtualInvokeData _13_System_IConvertible_ToInt32;
		VirtualInvokeData _14_System_IConvertible_ToUInt32;
		VirtualInvokeData _15_System_IConvertible_ToInt64;
		VirtualInvokeData _16_System_IConvertible_ToUInt64;
		VirtualInvokeData _17_System_IConvertible_ToSingle;
		VirtualInvokeData _18_System_IConvertible_ToDouble;
		VirtualInvokeData _19_System_IConvertible_ToDecimal;
		VirtualInvokeData _20_System_IConvertible_ToDateTime;
		VirtualInvokeData _21_ToString;
		VirtualInvokeData _22_System_IConvertible_ToType;
		VirtualInvokeData _23_System_Collections_IEnumerable_GetEnumerator;
		VirtualInvokeData _24_CompareTo;
		VirtualInvokeData _25_System_Collections_Generic_IEnumerable_System_Char__GetEnumerator;
		VirtualInvokeData _26_Equals;
	};
	struct System_String_c {
		Il2CppClass_1 _1;
		struct System_String_StaticFields* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		System_String_VTable vtable;
	};
	struct Il2CppClass
	{
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		VirtualInvokeData vtable[255];
	};
	struct __declspec(align(8)) System_String_Fields {
		int32_t m_stringLength;
		uint16_t m_firstChar;
	};
	struct System_String_o {
		System_String_c* klass;
		void* monitor;
		System_String_Fields fields;
	};
	struct ObscuredInt
	{
		uint32_t offset;
		uint32_t value;
	};
	struct LastObjectBase
	{
		char pad_0000[16]; //0x0000
		class GameObject* gameObject; //0x0010
	}; //Size: 0x0018


	struct BaseObject
	{
		char pad_0000[8]; //0x0000
		class BaseObject* nextObject; //0x0008
		class GameObject* gameObject; //0x0010
	}; //Size: 0x0018


	struct GameObject
	{
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

	struct GameObjectManager_s
	{
		class LastObjectBase* LastTaggedObject; //0x0000
		class BaseObject* TaggedObjects; //0x0008
		class LastObjectBase* LastActiveObject; //0x0010
		class BaseObject* ActiveObjects; //0x0018
		class LastObjectBase* LastTaggedObject2; //0x0020
		class BaseObject* TaggedObject2; //0x0028
	}; 
	struct WeaponModPart_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct WeaponModPart_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		WeaponModPart_VTable vtable;
	};
	struct WeaponModPart_Fields {
		System_String_o* saveString;
		int32_t playerDataKey;
		struct WeaponModAlternatePart_array* alternateParts;
		struct PlayerController_c* player;
		int32_t enabledIndex;
	};
	struct WeaponModPart_o {
		WeaponModPart_c* klass;
		void* monitor;
		WeaponModPart_Fields fields;
	};

	struct WeaponModPart_array {
		Il2CppObject obj;
		Il2CppArrayBounds* bounds;
		il2cpp_array_size_t max_length;
		WeaponModPart_o* m_Items[65535];
	};


	struct Item
	{
		char pad_0000[24]; //0x0000
		class WeaponStats* info; //0x0018
		char pad_0020[8]; //0x0020
		float bulletSpread; //0x0028
		ObscuredInt ammo; //0x002C
		ObscuredInt totalAmmo; //0x0034
		float nextTimeToUse; //0x003C
		void* weaponModSight; //0x0040
		void* directionalParticles; //0x0048
		void* effectParticles; //0x0050
	}; //Size: 0x0058


	struct ItemPointer
	{
	    Item* item;
	}; 

	struct ItemArray
	{
		char pad_0000[24]; 
		uint32_t count; 
		char pad_001C[4]; 
		ItemPointer elements[3]; 
	};

	struct WeaponStats
	{
		char pad_0000[24];
		uint32_t type; 
		uint32_t damage;
		float kickback;
		float useDelay;
		uint32_t shots;
		float cameraShake; 
		float adsCameraShake; 
		float reloadTime; 
		uint32_t magazineSize; 
		uint32_t startingAmmo; 
		uint32_t individualReload; 
		float bulletSpread; 
		float adsBulletSpread; 
		float maxbulletSpread; 
		float bulletSpreadDecrease; 
		float normalSpread; 
		float adsSpread; 
		float movementSpreadMultiplier;
		float adsMovementSpreadMultiplier; 
		float movementADSAnimationMultiplier;
		float adsFOVChange;
		float cameraADSBobMultiplier;
		bool useScopedMouseSensitivity; 
		char pad_006D[3]; 
		void* animationLayers; 
		void* fireSound;
		void* icon;
		uint32_t damageData;
		char pad_008C[4]; 
		void* permanentEffectPrefab; 
		uint32_t projectileColliderMask;
		uint32_t crosshairType; 
		uint32_t damageMultiplierRoomSetting; 
		bool noscope; 
	}; 

	struct PlayerController_fields
	{
		int collisionMask;
		int damagerMask;
		char flybyAudioManager[32];
		char cameraHolder[16];
		char shieldObject[16];
		char cam[16];
		char rainEffects[16];
		char battleRoyalEffects[16];
		char spotLight[16];
		ItemArray* items;
		char pad_0070[136]; 
		class N000006E5* N0000035F;
		char pad_0100[72];
		bool toJump;
		bool ads;
		bool reloading;
		bool meleeing;
		bool sprinting;
		bool dead;
		float bulletSpread;
		char pad[12]; //Interactable_o* lastInteractable;
		bool wasInteractable;
		char pad_0154[47]; 
		float lastTimeTookDamage;
		float nextTimeToRegen;
		int32_t regenAmount;
		float regenInterval;
		float lastTimeGrounded;
		float lastTimeJumped;
		float lastTimePulledOutItem;
		float nextTimeToCircleDamage;
		char rigidbody_pad[16];
		vec3_t rigid_origin; //forward, up, right
		float rigid_time; 
		int crosshairIndex; 
		char stressReceiver_pad[12];
		bool isActingAsLocalPlayer;
		vec3_t constantForce;
		vec3_t pushForce;
		char idk_pad[36];
		float additiveFov;
		int16_t lastDamagePacketID;

	}; 
	struct PlayerController_staticfields
	{
		char pad_0000[24];
		PlayerController_fields* LocalPlayer; //0x0018
	};

	struct PlayerController_o
	{
		char pad_0000[184]; 
		char pad[40];
		PlayerController_staticfields* static_fields;
	}; 

	struct PlayerController_c
	{
		PlayerController_o* object; 
	}; 

}

#endif