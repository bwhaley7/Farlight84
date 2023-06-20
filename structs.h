#pragma once


struct FMinimalViewInfo {
	FVector Location; // 0x00(0x0c)
	FRotator Rotation; // 0x0c(0x0c)
	float FOV; // 0x18(0x04)
};

struct FRepMovement {
	FVector LinearVelocity; // 0x00(0x0c)
	FVector AngularVelocity; // 0x0c(0x0c)
	FVector Location; // 0x18(0x0c)
	FRotator Rotation; // 0x24(0x0c)
};

typedef struct
{
	char szCN[0x100];
	char szEN[0x100];
	char szTexture[0x100];
}ITEM_NAME, * PITEM_NAME;
typedef struct _Players
{
	uint64_t ptr;
	int status;
	float Health;
	float HealthMax;
	int SpectatorNum;
	int AccountFlag;
	int KillNum;
	std::wstring OS;
	FVector origin;
	FLOAT Distance;
	std::wstring Name;
	std::wstring WeaponName;
	float InitSpeed;
	float ProjectileMaxGravity;
	int Team;
	bool bIsCrouched;
	bool IsBot;
	float MaxShieldValue;
	float CurrShieldValue;
	int CurrShieldLevel;
	int WeaponType;
	int PrimaryAmmoCap;
	int CurrentClipAmmo;
	FRotator RelativeRotation;
	FVector ComponentVelocity;
	struct _ESPPrediction
	{
		FVector ROOT;
		FVector HEAD;
	}ESPPrediction;
	struct _Bones
	{
		FVector vHeadBone;
		FVector vHip;
		FVector vNeck;
		FVector vUpperArmLeft;
		FVector vUpperArmRight;
		FVector vLeftHand;
		FVector vRightHand;
		FVector vLeftHand1;
		FVector vRightHand1;
		FVector vRightThigh;
		FVector vLeftThigh;
		FVector vRightCalf;
		FVector vLeftCalf;
		FVector vLeftFoot;
		FVector vRightFoot;
		FVector VRoot;
	}Bones;
	struct _AimBones
	{
		FVector ROOT;
		FVector HEAD;
		FVector NECK;
		FVector Chest;
		FVector NerstBone;

	}AimBones;

	struct _ESPDirectionLine
	{
		FVector ROOT;
		FVector HEAD;
	}ESPDirectionLine;
}A_Players;
typedef struct _Vehicle
{

	uint64_t ptr;
	std::string FnameType;
	FVector origin;
	FLOAT Distance = 0;
}A_Vehicle;
typedef struct _Pickup
{
	uint64_t ptr;
	FVector origin;
	FLOAT Distance;
	std::wstring items;
	int type;
	int Quality;
}A_Pickup;
extern FMinimalViewInfo CameraCacheEntry;
extern A_Players MyLocalPlayer;
extern A_Vehicle MyLocalVehicle;
extern std::vector<A_Pickup> EntityPickups;
extern std::vector<A_Vehicle> EntityVehicle;
extern std::vector<A_Players> EntityList;
extern std::vector<uint64_t> TempEntityList;
extern std::vector<uint64_t> TempEntityList2;
extern int TotalEnemy, TotalBots;

