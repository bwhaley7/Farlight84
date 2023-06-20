#include "Includes.h"
namespace exe
{
	DWORD_PTR BaseAddress = 0x0;
}
namespace offsets
{
	DWORD GWorld = 0x62C8610;
	DWORD GNames = 0x6158C40;

	DWORD offset_actor_array = 0x98; //UNetConnection->OwningActor
	DWORD offset_actor_count = 0xa0; //UNetConnection->MaxPacket

	DWORD PersistentLevel = 0x30;
	DWORD OwningGameInstance = 0x220;
	DWORD LocalPlayers = 0x38;
	DWORD PlayerController = 0x30;
	DWORD AcknowledgedPawn = 0x2c0;
	DWORD PlayerCameraManager = 0x2d8;
	DWORD CameraCachePrivate = 0x1bf0;
	DWORD Mesh = 0x288;
	DWORD StaticMesh = 0x588;
	DWORD RootComponent = 0x138;
	DWORD RelativeLocation = 0x11c; //+ 0x144;
	DWORD RelativeRotation = 0x128;
	DWORD ComponentVelocity = 0x140;
	DWORD bIsCrouched = 0x330;
	DWORD bIsABot = 0x232;//bool bIsABot (ByteOffset: 0, ByteMask: 8, FieldMask: 8)[Offset: 0x232, Size: 1]
	DWORD MaxShieldValue = 0x1224;
	DWORD CurrShieldValue = 0x1230;
	DWORD CurrShieldLevel = 0x1238;

	DWORD PlayerState = 0x248;
	DWORD TeamID = 0x3fc;
	DWORD CurrentHealth = 0x578;
	DWORD MaxHealth = 0x57c;
	DWORD PlayerNamePrivate = 0x310;
	DWORD SpectatorNum = 0x598;
	DWORD AccountFlag = 0x618;
	DWORD KillNum = 0x708;
	DWORD OS = 0x630;
	DWORD CachedCurrentWeapon = 0x1ed8;
	DWORD Config = 0x5d8;
	DWORD WeaponType = 0x35;
	DWORD PrimaryAmmoCap = 0x2c4;
	DWORD CurrentClipAmmo = 0x678;
	DWORD RecoilComponent = 0x600;
	DWORD WeaponConfig = 0xd0;
	DWORD PrimaryAmmo = 0x2b8;
	DWORD InitSpeed = 0xe0;
	DWORD ProjectileMaxGravity = 0x544;

	DWORD ItemData = 0xd40;
	DWORD SolarItemData = 0x268; //SolarItemData ItemData;//[Offset: 0x268, Size: 1]
}


