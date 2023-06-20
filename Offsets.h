#pragma once
namespace exe
{
	extern DWORD_PTR BaseAddress;
}
namespace offsets
{
	extern	DWORD GWorld;
	extern	DWORD GNames;
	extern	DWORD PersistentLevel;
	extern	DWORD OwningGameInstance;
	extern	DWORD LocalPlayers;
	extern	DWORD PlayerController;
	extern	DWORD AcknowledgedPawn;
	extern	DWORD PlayerCameraManager;
	extern	DWORD CameraCachePrivate;
	extern	DWORD Mesh;
	extern	DWORD StaticMesh;
	extern	DWORD RootComponent;
	extern	DWORD RelativeLocation;
	extern	DWORD RelativeRotation;
	extern  DWORD ComponentVelocity;
	extern	DWORD PlayerState;
	extern	DWORD TeamID;
	extern	DWORD CurrentHealth;
	extern	DWORD MaxHealth;
	extern	DWORD bIsCrouched;
	extern  DWORD bIsABot;
	extern	DWORD MaxShieldValue;
	extern	DWORD CurrShieldValue;
	extern  DWORD CurrShieldLevel;

	extern  DWORD PlayerNamePrivate;
	extern  DWORD SpectatorNum;
	extern  DWORD AccountFlag;
	extern  DWORD KillNum;
	extern  DWORD OS;
	extern  DWORD CachedCurrentWeapon;
	extern  DWORD Config;
	extern  DWORD WeaponType;
	extern	DWORD PrimaryAmmoCap;
	extern  DWORD CurrentClipAmmo;
	extern  DWORD RecoilComponent;
	extern	DWORD WeaponConfig;
	extern	DWORD PrimaryAmmo;
	extern	DWORD InitSpeed;
	extern	DWORD ProjectileMaxGravity;
	extern  DWORD ItemData;
	extern  DWORD SolarItemData;
}

enum bones
{
	Root = 0,
	Bip001 = 1,
	pelvis = 2,
	spine_01 = 3,
	spine_02 = 4,
	spine_03 = 5,
	clavicle_l = 6,
	upperarm_l = 7,
	lowerarm_l = 8,
	hand_l = 9,
	thumb_01_l = 10,
	thumb_02_l = 11,
	thumb_03_l = 12,
	index_01_l = 13,
	index_02_l = 14,
	index_03_l = 15,
	middle_01_l = 16,
	middle_02_l = 17,
	middle_03_l = 18,
	ring_01_l = 19,
	ring_02_l = 20,
	ring_03_l = 21,
	pinky_01_l = 22,
	pinky_02_l = 23,
	pinky_03_l = 24,
	clavicle_r = 25,
	upperarm_r = 26,
	lowerarm_r = 27,
	hand_r = 28,
	thumb_01_r = 29,
	thumb_02_r = 30,
	thumb_03_r = 31,
	index_01_r = 32,
	index_02_r = 33,
	index_03_r = 34,
	middle_01_r = 35,
	middle_02_r = 36,
	middle_03_r = 37,
	ring_01_r = 38,
	ring_02_r = 39,
	ring_03_r = 40,
	pinky_01_r = 41,
	pinky_02_r = 42,
	pinky_03_r = 43,
	RightHandWeaponAttach = 44,
	neck_01 = 45,
	head = 46,
	BackpackAttach = 47,
	thigh_l = 48,
	calf_l = 49,
	foot_l = 50,
	ball_l = 51,
	thigh_r = 52,
	calf_r = 53,
	foot_r = 54,
	ball_r = 55,
	VB_spine_03_RightHandWeaponAttach = 56,
	VB_VB_spine_03_RightHandWeaponAttach_hand_r = 57,
	VB_VB_VB_spine_03_RightHandWeaponAttach_hand_r_lowerarm_r = 58,
};
enum class EItemType : uint32_t {
	NONE = 0,
	SHIELD = 101,
	ARMOR = 102,
	BULLET = 103,
	CARIRIDGE_BAG = 104,
	ARMOR_MATERIAL = 105,
	ENERGY_MODULE = 106,
	EXTRA_ENERGY = 107,
	RADAR_OPERATOR = 108,
	BACKPACK_ENERGY = 109,
	BACKUP_ENERGY = 110,
	SHIELD_RECHARGER = 112,
	BACKPACK_ITEM = 113,
	WEAPON_PARTS = 114,
	JETPACK_MODULE_HORIZONTAL = 111,
	JETPACK_MODULE_VERTICAL = 115,
	REVIVE_ITEM = 116,
	TREASUREBOX = 120,
	AIRDROPBOX = 121,
	DEATHBOX = 122,
	NEUTRAL_CARD = 130,
	SHIELD_UPGRADE_MATERIAL = 148,
	EXP_ITEM = 149,
	WEAPON = 151,
	WEAPON_SKIN = 171,
	BACKPACK = 201,
	TAILFLAME = 202,
	CARDPOSE = 203,
	CARDBACKGROUND = 204,
	CAPSULE = 251,
	CHAR_SKIN_MIN = 301,
	CHAR_ANIMATION_MVP = 302,
	CHAR_SKIN_MAX = 350,
	CHARACTER = 351,
	EXPERIENCE = 401,
	GIFTBAG = 404,
	CHARACTER_TRIALCARD = 405,
	CHARACTERSKIN_TRIALCARD = 406,
	ACTIVENESS = 411,
	WEAPONSKIN_TRIALCARD = 412,
	GIFTBAG_ONBACKPACK = 414,
	BACKPACK_TRIALCARD = 415,
	TAILFLAME_TRIALCARD = 416,
	DIAMOND_VOUCHER = 417,
	LOTCOIN = 421,
	ZOMBORG = 422,
	WISHCOIN = 423,
	SURPRISECOIN = 424,
	TOKEN = 430,
	BUSINESSCARDFRAME = 432,
	AVATARFRAME = 434,
	CHARACTER_SHARD = 435,
	CHARACTER_SKIN_SHARD = 436,
	WEAPON_SKIN_SHARD = 437,
	BACKPACK_SHARD = 438,
	TAILFLAME_SHARD = 439,
	CAPSULE_SHARD = 440,
	VEHICLE_SKIN_SHARD = 441,
	ACCOUNT_AVATAR = 443,
	EMOTE = 444,
	HOMEBUILD = 501,
	HOMEINSTALLATION = 502,
	HOMEITEM = 503,
	HOMEDRAWING = 504,
	HOMEPART = 505,
	HOMEDEVICE = 506,
	HOMEMAX = 520,
	VEHICLE_SKIN = 701,
	SUPPLYBOX = 801,
	EItemType_MAX = 802
};

enum class EWeaponType : uint8_t {
	AssualtRifle = 0,
	Submachinegun = 1,
	Shotgun = 2,
	Sniper = 3,
	VehicleMounted = 4,
	ItemWeapon = 5,
	SummonWeapon = 6,
	AntiVehicle = 7,
	Unarm = 8,
	Unknown = 9,
	EWeaponType_MAX = 10
};




