#pragma once

#ifndef gobjects
#define gobjects

#include "pch.h"

#define UE_GET_WIDTH "UnityEngine.Screen::get_width()"
#define UE_GET_HEIGHT "UnityEngine.Screen::get_height()"

#define SENDCHATMESSAGE "ChatManager::SendChatMessage()"


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
	struct MethodInfo
	{
		Il2CppMethodPointer methodPointer;
		void* invoker_method;
		const char* name;
		Il2CppClass* klass;
		const Il2CppType* return_type;
		const void* parameters;
		union
		{
			const Il2CppRGCTXData* rgctx_data;
			const void* methodDefinition;
		};
		union
		{
			const void* genericMethod;
			const void* genericContainer;
		};
		uint32_t token;
		uint16_t flags;
		uint16_t iflags;
		uint16_t slot;
		uint8_t parameters_count;
		uint8_t bitflags;
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
	struct UnityEngine_Vector3_Fields {
		float x;
		float y;
		float z;
	};
	struct UnityEngine_Vector3_o {
		UnityEngine_Vector3_Fields fields;
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
	struct GameObjectManager_o
	{
		LastObjectBase* LastTaggedObject; //0x0000
		BaseObject* TaggedObjects; //0x0008
		LastObjectBase* LastActiveObject; //0x0010
		BaseObject* ActiveObjects; //0x0018
		LastObjectBase* LastTaggedObject2; //0x0020
		BaseObject* TaggedObject2; //0x0028
	};
	struct GameObjectManager_s
	{
		GameObjectManager_o* GameObjectManagerObj;
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

	struct ItemSway_o {
		float moveAmount;
		float rotateAmount;
		float maxMove;
		float maxRotate;
		float moveSmoothAmount;
		float rotateSmoothAmount;
		struct MyceliumIdentity_o* identity;
		vec3_t initialPosition;
		vec4_t initialRotation;
		float weight;
	};
	struct Item
	{
		char pad_0000[24]; //0x0000
		struct WeaponStats* info; //0x0018
		struct UnityEngine_GameObject_o* graphics;
		ItemSway_o* sway;
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
	struct UnityEngine_LayerMask_Fields {
		int32_t m_Mask;
	};
	struct UnityEngine_LayerMask_o {
		UnityEngine_LayerMask_Fields fields;
	};
	struct WeaponStats
	{
		char pad_0000[24];
		int32_t type;
		int32_t itemEnum;
		int32_t damage;
		float useDelay;
		int32_t shots;
		float cameraShake;
		float adsCameraShake;
		float reloadTime;
		int32_t magazineSize;
		int32_t startingAmmo;
		bool individualReload;
		bool walkWhileReloading;
		float bulletSpread;
		float adsBulletSpread;
		float maxBulletSpread;
		float bulletSpreadDecrease;
		float normalSpread;
		float adsSpread;
		float movementSpreadMultiplier;
		float adsMovementSpreadMultiplier;
		float movementADSAnimationMultiplier;
		float adsFOVChange;
		float cameraADSBobMultiplier;
		bool useScopedMouseSensitivity;
		struct System_Int32_array* animationLayers;
		struct System_String_o* fireSound;
		struct UnityEngine_Sprite_o* icon;
		int32_t damageData;
		struct UnityEngine_GameObject_o* permanentEffectPrefab;
		struct UnityEngine_LayerMask_o projectileColliderMask;
		int32_t crosshairType;
		int32_t damageLobbyData;
		bool noscope;
	}; 

	struct PlayerController_fields
	{
		//int collisionMask;
		//int damagerMask;
		//char flybyAudioManager[32];
		//char cameraHolder[16];
		//char shieldObject[16];
		//char cam[16];
		//char rainEffects[16];
		//char battleRoyalEffects[16];
		//char spotLight[16];
		char _pad00[0x58];
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
		struct UnityEngine_Rigidbody_o* rb;
		struct MyceliumIdentity_o* _identity_k__BackingField;
		struct UnityEngine_Animator_o* anim;
		struct AudioManager_o* am;
		struct IDamageable_o* myDamagable;
		float lastTimeTookDamage;
		float nextTimeToRegen;
		int32_t regenAmount;
		float regenInterval;
		float lastTimeGrounded;
		float lastTimeJumped;
		float lastTimePulledOutItem;
		float nextTimeToCircleDamage;
		void* lastDamager;
		void* lastDamageData;
		vec3_t lastNonLocalPos;
		float footstepDistance;
		float footstepInterval;
		struct UnityEngine_Coroutine_o* individualReloadCoroutine;
		struct System_Collections_Generic_List_ItemIcon__o* itemIcons;
		int32_t crosshairIndex;
		struct StressReceiver_o* stressReceiver;
		bool isActingAsLocalPlayer;
		vec3_t constantForce;
		vec3_t pushForce;
		float additiveFOV;
		vec3_t focusedPosition;
		int16_t lastDamagePacketID;
		struct ShadowOnlyIfLocalPlayer_array* shadowOnlyIfLocalPlayers;
		struct Hat_o* hat;
		bool identityIsMine;
		bool leftTriggerDownLastFrame;
		bool firstSwitch;


	}; 
	struct __declspec(align(8)) System_Collections_Generic_List_byte__Fields {
		struct System_Byte_array* _items;
		int32_t _size;
		int32_t _version;
		Il2CppObject* _syncRoot;
	};
	struct System_Collections_Generic_List_byte__o {
		struct System_Collections_Generic_List_byte__c* klass;
		void* monitor;
		System_Collections_Generic_List_byte__Fields fields;
	};
	struct __declspec(align(8)) Message_Fields {
		int32_t _Header_k__BackingField;
		struct System_Collections_Generic_List_byte__o* buffer;
		struct System_Byte_array* readableBuffer;
		int32_t readPos;
		bool disposed;
	};
	struct Message_o {
		struct Message_c* klass;
		void* monitor;
		Message_Fields fields;
	};
	struct PlayerController_staticfields
	{
		char pad_0000[24];
		PlayerController_fields* LocalPlayer; //0x0018
	};

	struct PlayerController_o
	{ 
		char pad_0000[184]; //0x0000
		PlayerController_staticfields* static_fields;
	}; 

	constexpr int ah = sizeof(struct System_Collections_Generic_Dictionary_int__int__o*);
	struct Interactable_Fields {
		bool interacting;
	};
	struct Interactable_o {
		Interactable_Fields fields;
	};
	struct PlayerController_c
	{
		struct UnityEngine_LayerMask_o collisionMask;
		struct UnityEngine_LayerMask_o damagerMask;
		struct UnityEngine_LayerMask_o interactionMask;
		struct AudioManager_o* flybyAudioManager;
		struct UnityEngine_GameObject_o* cameraHolder;
		struct UnityEngine_GameObject_o* shieldObject;
		struct UnityEngine_Camera_o* cam;
		struct UnityEngine_GameObject_o* rainEffects;
		struct UnityEngine_GameObject_o* battleRoyalEffects;
		struct UnityEngine_Light_o* spotLight;
		char pad[60 - 8];
		ItemArray* items;
		
		struct ItemInfo_array* ownedItems;
		struct System_Collections_Generic_Dictionary_int__int__o* itemToOwnedItemIndex;
		struct System_Collections_Generic_Dictionary_int__int__o* ownedItemToItemIndexLookup;
		struct WeaponModPart_array* weaponModParts;
		struct UnityEngine_GameObject_array* deactivateIfNotOwner;
		char crosshair[20];
		struct UnityEngine_Renderer_o* renderer;
		struct UnityEngine_GameObject_o* damageIndicatorCanvasPrefab;
		//char pad22[16];
		float smoothTime;
		float animationSmoothTime;
		struct UnityEngine_LayerMask_o localCullingMask;
		struct System_Action_o* OnShowLocalParts;
		struct System_Action_o* OnHideLocalParts;
		int32_t itemIndex;
		bool shielded;
		struct System_Collections_Generic_Dictionary_string__StatInfo__o* stats;
		float verticalLookRotation;
		vec3_t moveAmount;
		vec3_t smoothMoveVelocity;
		bool grounded;
		bool groundedLastTick;
		struct UnityEngine_Transform_o* groundedTransform;
		struct UnityEngine_Transform_o* lastGroundedTransform;
		vec3_t groundedTransformLastPosition;
		vec3_t momentum;
		bool toJump;
		bool ads;
		bool reloading;
		bool meleeing;
		bool sprinting;
		bool dead;
		float bulletSpread;
		struct Interactable_o* lastInteractable;
		bool wasInteractable;
		struct UnityEngine_Rigidbody_o* rb;
		struct MyceliumIdentity_o* _identity_k__BackingField;
		struct UnityEngine_Animator_o* anim;
		struct AudioManager_o* am;
		struct IDamageable_o* myDamagable;
		float lastTimeTookDamage;
		float nextTimeToRegen;
		int32_t regenAmount;
		float regenInterval;
		float lastTimeGrounded;
		float lastTimeJumped;
		float lastTimePulledOutItem;
		float nextTimeToCircleDamage;
		struct MyceliumPlayer_o* lastDamager;
		struct DamageData_array* lastDamageData;
		struct UnityEngine_Vector3_o lastNonLocalPos;
		float footstepDistance;
		float footstepInterval;
		struct UnityEngine_Coroutine_o* individualReloadCoroutine;
		struct System_Collections_Generic_List_ItemIcon__o* itemIcons;
		int32_t crosshairIndex;
		struct StressReceiver_o* stressReceiver;
		bool isActingAsLocalPlayer;
		vec3_t constantForce;
		vec3_t pushForce;
		float additiveFOV;
		struct UnityEngine_Vector3_o focusedPosition;
		int16_t lastDamagePacketID;
		struct ShadowOnlyIfLocalPlayer_array* shadowOnlyIfLocalPlayers;
		bool identityIsMine;
		bool leftTriggerDownLastFrame;
		struct MovingAverage_o* fireTimeDifference;
		float antiCheat_lastFireTime;
		int32_t antiCheat_offenses;
		bool firstSwitch;
	};
	struct Steamworks_CSteamID_Fields {
		uint64_t m_SteamID;
	};
	struct Steamworks_CSteamID_o {
		Steamworks_CSteamID_Fields fields;
	};
	struct __declspec(align(8)) MyceliumPlayer_Fields {
		struct Steamworks_CSteamID_o _SteamID_k__BackingField;
		struct System_String_o* _name;
	};

	struct MyceliumPlayer_o {
		struct MyceliumPlayer_c* klass;
		void* monitor;
		MyceliumPlayer_Fields fields;
	};


	struct MyceliumNetwork_Fields
	{
		float SendRate;
		void* _Players_k__BackingField;
		struct MyceliumPlayer_o* _localPlayer;
		bool InLobby;
	};
	struct MyceliumNetwork_o
	{
		void* HUH;
		MyceliumNetwork_Fields fields;
		void* monitor;
		//MyceliumNetwork_Fields fields;
	};
	
	struct KillData_Fields {
		struct MyceliumPlayer_o* victim;
		struct DamageData_array* damageData;
		float distance;
		int16_t damagePacketID;
	};
	struct KillData_o {
		KillData_Fields fields;
	};
	struct ChatManager_Fields {
		struct InputFieldAutoComplete_o* autoComplete;
		struct UnityEngine_CanvasGroup_o* canvasGroup;
		struct TMPro_TMP_InputField_o* inputField;
		struct UnityEngine_UI_Mask_o* hardMask;
		struct UnityEngine_UI_ScrollRect_o* scrollRect;
		struct UnityEngine_GameObject_o* messagePrefab;
		struct UnityEngine_Transform_o* container;
		bool chatWasOpen;
		bool open;
		struct ChatManager_Callback_o* onChatClosed;
		struct ChatManager_Callback_o* onChatOpened;
		struct System_Collections_Generic_List_ChatMessageItem__o* currentChatMessageItems;
		float spamLimiter;
		int32_t blockCount;
	};
	struct ChatManager_StaticFields;

	struct ChatManager_c {
		//Il2CppClass_1 _1;
		ChatManager_StaticFields* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		void* vtable;
	};
	struct ChatManager_o {
		void* klass;
		void* monitor;
		ChatManager_Fields fields;
	};
	struct ChatManager_StaticFields {
		struct ChatManager_o* Instance;
		struct System_Collections_Generic_Dictionary_MyceliumPlayer__int__o* rateLimitTokens;
		int32_t TOKEN_MAX;
	};
	struct TimeoutManager_Fields {
		struct Steamworks_Callback_PersonaStateChange_t__o* personaStateChangeCallback;
		bool first;
		struct System_Collections_Generic_Dictionary_CSteamID__string__o* banMessageQueue;
	};
	struct TimeoutManager_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct TimeoutManager_c {
		Il2CppClass_1 _1;
		struct TimeoutManager_StaticFields* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		TimeoutManager_VTable vtable;
	};
	struct TimeoutManager_o {
		TimeoutManager_c* klass;
		void* monitor;
		TimeoutManager_Fields fields;
	};
	struct System_UInt64_array {
		Il2CppObject obj;
		Il2CppArrayBounds* bounds;
		il2cpp_array_size_t max_length;
		uint64_t m_Items[65535];
	};
	struct TimeoutManager_StaticFields {
		struct TimeoutManager_o* instance;
		bool Muted;
		struct System_String_o* MutedText;
		System_UInt64_array* bannedIDs;
		System_UInt64_array* mutedIDs;
	};
	struct PlayerManager_o;

	struct PlayerManager_StaticFields {
		struct PlayerManager_o* Instance;
		struct System_Action_KillData__o* OnKill;
		struct System_Action_o* OnStartedSpectating;
		struct System_Action_o* OnStoppedSpectating;
	};
	struct PlayerManager_Fields {
		struct UnityEngine_GameObject_o* avatarPrefab;
		struct UnityEngine_GameObject_o* spectatorPrefab;
		struct UnityEngine_GameObject_o* cinematicSpectatorPrefab;
		struct UnityEngine_GameObject_o* deathCameraPrefab;
		int32_t kills;
		int32_t deaths;
		bool spectating;
		struct UnityEngine_GameObject_o* spectatorObject;
		bool _dead_k__BackingField;
		bool wasHereAtStartOfRound;
		struct UnityEngine_Transform_o* customSpawnpoint;
	};
	struct PlayerManager_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct PlayerManager_c {
		Il2CppClass_1 _1;
		struct PlayerManager_StaticFields* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		PlayerManager_VTable vtable;
	};
	struct PlayerManager_o {
		PlayerManager_c* klass;
		void* monitor;
		PlayerManager_Fields fields;
	};
	struct UnityEngine_Color_o
	{
		float r;
		float g;
		float b;
		float a;
	};
	struct System_Int32_array {
		Il2CppObject obj;
		Il2CppArrayBounds* bounds;
		il2cpp_array_size_t max_length;
		int32_t m_Items[65535];
	};
	struct OutskirtsCodeGenerator_Fields {
		struct System_Int32_array* code;
	};
	struct OutskirtsCodeGenerator_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct OutskirtsCodeGenerator_c {
		Il2CppClass_1 _1;
		struct OutskirtsCodeGenerator_StaticFields* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		OutskirtsCodeGenerator_VTable vtable;
	};
	struct OutskirtsCodeGenerator_o {
		OutskirtsCodeGenerator_c* klass;
		void* monitor;
		OutskirtsCodeGenerator_Fields fields;
	};
	struct OutskirtsCodeGenerator_StaticFields {
		struct OutskirtsCodeGenerator_o* instance;
	};
	struct OutskirtsKeypad_Fields {
		struct UnityEngine_AudioSource_o* keyPressAudio;
		struct UnityEngine_AudioSource_o* wrongPressAudio;
		struct TMPro_TMP_Text_o* codeText;
		struct UnityEngine_Color_o normalColor;
		struct UnityEngine_Color_o correctColor;
		struct UnityEngine_Color_o incorrectColor;
		struct UnityEngine_Events_UnityEvent_o* onComplete;
		struct System_String_o* codeProgress;
		bool acceptingInput;
		bool completed;
		struct MyceliumIdentity_o* identity;
	};
	struct OutskirtsKeypad_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct OutskirtsKeypad_c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		OutskirtsKeypad_VTable vtable;
	};
	struct OutskirtsKeypad_o {
		OutskirtsKeypad_c* klass;
		void* monitor;
		OutskirtsKeypad_Fields fields;
	};
	struct MethodInfo_104F630
	{
		Il2CppMethodPointer methodPointer;
		void* invoker_method;
		const char* name;
		struct System_Collections_Generic_Dictionary_TKey__TValue__c* klass;
		const Il2CppType* return_type;
		const void* parameters;
		const Il2CppRGCTXData* rgctx_data;
		union
		{
			const void* genericMethod;
			const void* genericContainer;
		};
		uint32_t token;
		uint16_t flags;
		uint16_t iflags;
		uint16_t slot;
		uint8_t parameters_count;
		uint8_t bitflags;
	};

	struct __declspec(align(8)) System_Collections_Generic_Dictionary_object__int__Fields {
		struct System_Int32_array* buckets;
		struct System_Collections_Generic_Dictionary_Entry_TKey__TValue__array* entries;
		int32_t count;
		int32_t version;
		int32_t freeList;
		int32_t freeCount;
		struct System_Collections_Generic_IEqualityComparer_TKey__o* comparer;
		struct System_Collections_Generic_Dictionary_KeyCollection_TKey__TValue__o* keys;
		struct System_Collections_Generic_Dictionary_ValueCollection_TKey__TValue__o* values;
		Il2CppObject* _syncRoot;
	};
	struct System_Collections_Generic_Dictionary_object__int__VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_get_Item;
		VirtualInvokeData _5_set_Item;
		VirtualInvokeData _6_Add;
		VirtualInvokeData _7_Remove;
		VirtualInvokeData _8_unknown;
		VirtualInvokeData _9_unknown;
		VirtualInvokeData _10_System_Collections_Generic_ICollection_System_Collections_Generic_KeyValuePair_TKey_TValue___get_IsReadOnly;
		VirtualInvokeData _11_System_Collections_Generic_ICollection_System_Collections_Generic_KeyValuePair_TKey_TValue___Add;
		VirtualInvokeData _12_Clear;
		VirtualInvokeData _13_System_Collections_Generic_ICollection_System_Collections_Generic_KeyValuePair_TKey_TValue___Contains;
		VirtualInvokeData _14_System_Collections_Generic_ICollection_System_Collections_Generic_KeyValuePair_TKey_TValue___CopyTo;
		VirtualInvokeData _15_System_Collections_Generic_ICollection_System_Collections_Generic_KeyValuePair_TKey_TValue___Remove;
		VirtualInvokeData _16_System_Collections_Generic_IEnumerable_System_Collections_Generic_KeyValuePair_TKey_TValue___GetEnumerator;
		VirtualInvokeData _17_System_Collections_IEnumerable_GetEnumerator;
		VirtualInvokeData _18_System_Collections_IDictionary_get_Item;
		VirtualInvokeData _19_System_Collections_IDictionary_set_Item;
		VirtualInvokeData _20_System_Collections_IDictionary_Contains;
		VirtualInvokeData _21_System_Collections_IDictionary_GetEnumerator;
		VirtualInvokeData _22_System_Collections_IDictionary_Remove;
		VirtualInvokeData _23_System_Collections_ICollection_CopyTo;
		VirtualInvokeData _24_unknown;
		VirtualInvokeData _25_System_Collections_ICollection_get_SyncRoot;
		VirtualInvokeData _26_System_Collections_ICollection_get_IsSynchronized;
		VirtualInvokeData _27_TryGetValue;
		VirtualInvokeData _28_get_Count;
		VirtualInvokeData _29_unknown;
		VirtualInvokeData _30_unknown;
		VirtualInvokeData _31_ContainsKey;
		VirtualInvokeData _32_GetObjectData;
		VirtualInvokeData _33_OnDeserialization;
	};
	struct System_Collections_Generic_Dictionary_object__int__c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		System_Collections_Generic_Dictionary_object__int__VTable vtable;
	};
	struct System_Collections_Generic_Dictionary_object__int__o {
		System_Collections_Generic_Dictionary_object__int__c* klass;
		void* monitor;
		System_Collections_Generic_Dictionary_object__int__Fields fields;
	};
	struct __declspec(align(8)) System_Collections_Generic_Dictionary_MyceliumPlayer__float__Fields {
		struct System_Int32_array* buckets;
		struct System_Collections_Generic_Dictionary_Entry_TKey__TValue__array* entries;
		int32_t count;
		int32_t version;
		int32_t freeList;
		int32_t freeCount;
		struct System_Collections_Generic_IEqualityComparer_TKey__o* comparer;
		struct System_Collections_Generic_Dictionary_KeyCollection_TKey__TValue__o* keys;
		struct System_Collections_Generic_Dictionary_ValueCollection_TKey__TValue__o* values;
		Il2CppObject* _syncRoot;
	};
	struct System_Collections_Generic_Dictionary_MyceliumPlayer__float__VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_get_Item;
		VirtualInvokeData _5_set_Item;
		VirtualInvokeData _6_Add;
		VirtualInvokeData _7_Remove;
		VirtualInvokeData _8_unknown;
		VirtualInvokeData _9_unknown;
		VirtualInvokeData _10_System_Collections_Generic_ICollection_System_Collections_Generic_KeyValuePair_TKey_TValue___get_IsReadOnly;
		VirtualInvokeData _11_System_Collections_Generic_ICollection_System_Collections_Generic_KeyValuePair_TKey_TValue___Add;
		VirtualInvokeData _12_Clear;
		VirtualInvokeData _13_System_Collections_Generic_ICollection_System_Collections_Generic_KeyValuePair_TKey_TValue___Contains;
		VirtualInvokeData _14_System_Collections_Generic_ICollection_System_Collections_Generic_KeyValuePair_TKey_TValue___CopyTo;
		VirtualInvokeData _15_System_Collections_Generic_ICollection_System_Collections_Generic_KeyValuePair_TKey_TValue___Remove;
		VirtualInvokeData _16_System_Collections_Generic_IEnumerable_System_Collections_Generic_KeyValuePair_TKey_TValue___GetEnumerator;
		VirtualInvokeData _17_System_Collections_IEnumerable_GetEnumerator;
		VirtualInvokeData _18_System_Collections_IDictionary_get_Item;
		VirtualInvokeData _19_System_Collections_IDictionary_set_Item;
		VirtualInvokeData _20_System_Collections_IDictionary_Contains;
		VirtualInvokeData _21_System_Collections_IDictionary_GetEnumerator;
		VirtualInvokeData _22_System_Collections_IDictionary_Remove;
		VirtualInvokeData _23_System_Collections_ICollection_CopyTo;
		VirtualInvokeData _24_unknown;
		VirtualInvokeData _25_System_Collections_ICollection_get_SyncRoot;
		VirtualInvokeData _26_System_Collections_ICollection_get_IsSynchronized;
		VirtualInvokeData _27_TryGetValue;
		VirtualInvokeData _28_get_Count;
		VirtualInvokeData _29_unknown;
		VirtualInvokeData _30_unknown;
		VirtualInvokeData _31_ContainsKey;
		VirtualInvokeData _32_GetObjectData;
		VirtualInvokeData _33_OnDeserialization;
	};
	struct System_Collections_Generic_Dictionary_MyceliumPlayer__float__c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		System_Collections_Generic_Dictionary_MyceliumPlayer__float__VTable vtable;
	};
	struct System_Collections_Generic_Dictionary_MyceliumPlayer__float__o {
		System_Collections_Generic_Dictionary_MyceliumPlayer__float__c* klass;
		void* monitor;
		System_Collections_Generic_Dictionary_MyceliumPlayer__float__Fields fields;
	};
	struct __declspec(align(8)) System_Collections_Generic_Dictionary_MyceliumPlayer__int__Fields {
		struct System_Int32_array* buckets;
		struct System_Collections_Generic_Dictionary_Entry_TKey__TValue__array* entries;
		int32_t count;
		int32_t version;
		int32_t freeList;
		int32_t freeCount;
		struct System_Collections_Generic_IEqualityComparer_TKey__o* comparer;
		struct System_Collections_Generic_Dictionary_KeyCollection_TKey__TValue__o* keys;
		struct System_Collections_Generic_Dictionary_ValueCollection_TKey__TValue__o* values;
		Il2CppObject* _syncRoot;
	};
	struct System_Collections_Generic_Dictionary_MyceliumPlayer__int__VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
		VirtualInvokeData _4_get_Item;
		VirtualInvokeData _5_set_Item;
		VirtualInvokeData _6_Add;
		VirtualInvokeData _7_Remove;
		VirtualInvokeData _8_unknown;
		VirtualInvokeData _9_unknown;
		VirtualInvokeData _10_System_Collections_Generic_ICollection_System_Collections_Generic_KeyValuePair_TKey_TValue___get_IsReadOnly;
		VirtualInvokeData _11_System_Collections_Generic_ICollection_System_Collections_Generic_KeyValuePair_TKey_TValue___Add;
		VirtualInvokeData _12_Clear;
		VirtualInvokeData _13_System_Collections_Generic_ICollection_System_Collections_Generic_KeyValuePair_TKey_TValue___Contains;
		VirtualInvokeData _14_System_Collections_Generic_ICollection_System_Collections_Generic_KeyValuePair_TKey_TValue___CopyTo;
		VirtualInvokeData _15_System_Collections_Generic_ICollection_System_Collections_Generic_KeyValuePair_TKey_TValue___Remove;
		VirtualInvokeData _16_System_Collections_Generic_IEnumerable_System_Collections_Generic_KeyValuePair_TKey_TValue___GetEnumerator;
		VirtualInvokeData _17_System_Collections_IEnumerable_GetEnumerator;
		VirtualInvokeData _18_System_Collections_IDictionary_get_Item;
		VirtualInvokeData _19_System_Collections_IDictionary_set_Item;
		VirtualInvokeData _20_System_Collections_IDictionary_Contains;
		VirtualInvokeData _21_System_Collections_IDictionary_GetEnumerator;
		VirtualInvokeData _22_System_Collections_IDictionary_Remove;
		VirtualInvokeData _23_System_Collections_ICollection_CopyTo;
		VirtualInvokeData _24_unknown;
		VirtualInvokeData _25_System_Collections_ICollection_get_SyncRoot;
		VirtualInvokeData _26_System_Collections_ICollection_get_IsSynchronized;
		VirtualInvokeData _27_TryGetValue;
		VirtualInvokeData _28_get_Count;
		VirtualInvokeData _29_unknown;
		VirtualInvokeData _30_unknown;
		VirtualInvokeData _31_ContainsKey;
		VirtualInvokeData _32_GetObjectData;
		VirtualInvokeData _33_OnDeserialization;
	};
	struct System_Collections_Generic_Dictionary_MyceliumPlayer__int__c {
		Il2CppClass_1 _1;
		void* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		System_Collections_Generic_Dictionary_MyceliumPlayer__int__VTable vtable;
	};
	struct System_Collections_Generic_Dictionary_MyceliumPlayer__int__o {
		System_Collections_Generic_Dictionary_MyceliumPlayer__int__c* klass;
		void* monitor;
		System_Collections_Generic_Dictionary_MyceliumPlayer__int__Fields fields;
	};
	struct __declspec(align(8)) AntiCheat_Boost_Fields {
	};
	struct AntiCheat_Boost_VTable {
		VirtualInvokeData _0_Equals;
		VirtualInvokeData _1_Finalize;
		VirtualInvokeData _2_GetHashCode;
		VirtualInvokeData _3_ToString;
	};
	struct AntiCheat_Boost_c {
		Il2CppClass_1 _1;
		struct AntiCheat_Boost_StaticFields* static_fields;
		Il2CppRGCTXData* rgctx_data;
		Il2CppClass_2 _2;
		AntiCheat_Boost_VTable vtable;
	};

	struct AntiCheat_Boost_o {
		AntiCheat_Boost_c* klass;
		void* monitor;
		AntiCheat_Boost_Fields fields;
	};
	struct AntiCheat_Boost_StaticFields {
		struct System_Collections_Generic_Dictionary_MyceliumPlayer__float__o* dieTime;
		struct System_Collections_Generic_Dictionary_MyceliumPlayer__int__o* offenses;
	};
}

#endif