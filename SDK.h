#pragma once
static int S_width = 1920, S_height = 1080;

class Player {
private:

public:
	Player() {}
	Player(A_Players _Actor) {
		this->ptr = _Actor.ptr;
		this->IsBot = _Actor.IsBot;
		this->Health = _Actor.Health;
		this->HealthMax = _Actor.HealthMax;
		this->MaxShieldValue = _Actor.MaxShieldValue;
		this->CurrShieldValue = _Actor.CurrShieldValue;
		this->CurrShieldLevel = _Actor.CurrShieldLevel;
		this->WeaponType = _Actor.WeaponType;
		this->PrimaryAmmoCap = _Actor.PrimaryAmmoCap;
		this->CurrentClipAmmo = _Actor.CurrentClipAmmo;

		this->KillNum = _Actor.KillNum;
		this->AccountFlag = _Actor.AccountFlag;
		this->SpectatorNum = _Actor.SpectatorNum;

		this->OS = _Actor.OS;
		this->WeaponName = _Actor.WeaponName;

		this->origin = _Actor.origin;
		this->Name = _Actor.Name;
		this->Team = _Actor.Team;
		this->bIsCrouched = _Actor.bIsCrouched;
		this->RelativeRotation = _Actor.RelativeRotation;
		this->ComponentVelocity = _Actor.ComponentVelocity;

		this->ESPPrediction.HEAD = _Actor.ESPPrediction.HEAD;
		this->ESPPrediction.ROOT = _Actor.ESPPrediction.ROOT;

		this->ESPDirectionLine.HEAD = _Actor.ESPDirectionLine.HEAD;
		this->ESPDirectionLine.ROOT = _Actor.ESPDirectionLine.ROOT;

		this->AimBones.HEAD = _Actor.AimBones.HEAD;
		this->AimBones.NECK = _Actor.AimBones.NECK;
		this->AimBones.Chest = _Actor.AimBones.Chest;
		this->AimBones.ROOT = _Actor.AimBones.ROOT;
		this->AimBones.NerstBone = _Actor.AimBones.NerstBone;

		this->Bones.vHeadBone = _Actor.Bones.vHeadBone;
		this->Bones.vHip = _Actor.Bones.vHip;
		this->Bones.vNeck = _Actor.Bones.vNeck;
		this->Bones.vUpperArmLeft = _Actor.Bones.vUpperArmLeft;
		this->Bones.vUpperArmRight = _Actor.Bones.vUpperArmRight;
		this->Bones.vLeftHand = _Actor.Bones.vLeftHand;
		this->Bones.vRightHand = _Actor.Bones.vRightHand;
		this->Bones.vLeftHand1 = _Actor.Bones.vLeftHand1;
		this->Bones.vRightHand1 = _Actor.Bones.vRightHand1;
		this->Bones.vRightThigh = _Actor.Bones.vRightThigh;
		this->Bones.vLeftThigh = _Actor.Bones.vLeftThigh;
		this->Bones.vRightCalf = _Actor.Bones.vRightCalf;
		this->Bones.vLeftCalf = _Actor.Bones.vLeftCalf;
		this->Bones.vLeftFoot = _Actor.Bones.vLeftFoot;
		this->Bones.vRightFoot = _Actor.Bones.vRightFoot;
		this->Bones.VRoot = _Actor.Bones.VRoot;

		this->ProjectileMaxGravity = _Actor.ProjectileMaxGravity;
		this->InitSpeed = _Actor.InitSpeed;

	}
	uint64_t ptr = 0;
	float Health = 0;
	float HealthMax = 0;
	int SpectatorNum = 0;
	int AccountFlag = 0;
	int KillNum = 0;
	float InitSpeed = 0;
	float ProjectileMaxGravity = 0;
	FVector origin = FVector();
	FLOAT Distance = 0;
	std::wstring Name = L"";
	std::wstring WeaponName = L"";
	std::wstring OS = L"";

	float MaxShieldValue = 0;
	float CurrShieldValue = 0;
	int CurrShieldLevel = 0;
	int WeaponType = 0;
	int PrimaryAmmoCap = 0;
	int CurrentClipAmmo = 0;
	int Team = 0;
	bool bIsCrouched = false;
	bool IsBot = false;
	FRotator RelativeRotation = FRotator();
	FVector ComponentVelocity = FVector();
	struct _ESPPrediction
	{
		FVector ROOT = FVector();
		FVector HEAD = FVector();
	}ESPPrediction;
	struct _Bones
	{
		FVector vHeadBone = FVector();
		FVector vHip = FVector();
		FVector vNeck = FVector();
		FVector vUpperArmLeft = FVector();
		FVector vUpperArmRight = FVector();
		FVector vLeftHand = FVector();
		FVector vRightHand = FVector();
		FVector vLeftHand1 = FVector();
		FVector vRightHand1 = FVector();
		FVector vRightThigh = FVector();
		FVector vLeftThigh = FVector();
		FVector vRightCalf = FVector();
		FVector vLeftCalf = FVector();
		FVector vLeftFoot = FVector();
		FVector vRightFoot = FVector();
		FVector VRoot = FVector();
	}Bones;
	struct _AimBones
	{
		FVector HEAD = FVector();
		FVector NECK = FVector();
		FVector Chest = FVector();
		FVector ROOT = FVector();
		FVector NerstBone = FVector();


	}AimBones;

	struct _ESPDirectionLine
	{
		FVector ROOT = FVector();
		FVector HEAD = FVector();
	}ESPDirectionLine;
	BOOL IsValid() {
		if ((this->origin.X != NULL) &&
			(this->Health > 0) &&
			(this->ptr != NULL)) return true;
		return false;
	}
};

class Vehicle {
private:

public:
	Vehicle() {}
	Vehicle(A_Vehicle _Actor) {
		this->ptr = _Actor.ptr;
		this->FnameType = _Actor.FnameType;
		this->origin = _Actor.origin;
		this->Distance = _Actor.Distance;
	}
	uint64_t ptr = 0;
	std::string FnameType = "";
	FVector origin = FVector();
	FLOAT Distance = 0;
	BOOL IsValid() {
		if ((this->origin.X != NULL) &&
			(this->ptr != NULL)) return true;
		return false;
	}
};
class Pickup {
private:
public:
	Pickup() {}
	Pickup(A_Pickup _Actor)
	{
		this->ptr = _Actor.ptr;
		this->items = _Actor.items;
		this->origin = _Actor.origin;
		this->Distance = _Actor.Distance;
		this->type = _Actor.type;
		this->Quality = _Actor.Quality;

	}

	uint64_t ptr = 0;
	FVector origin = FVector();
	FLOAT Distance = 0;
	std::wstring items = L"";
	int type = 0;
	int Quality = 0;

	BOOL IsValid() {
		if ((this->origin.X != NULL) &&
			(this->ptr != NULL)) return true;
		return false;
	}
};

class Manager {
private:
public:
	Player LocalPlayer = {};
	Vehicle LocalVehicles = {};

	std::vector<Player> Players = {};
	std::vector<Vehicle> Vehicles = {};
	std::vector<Pickup> Pickups = {};

	Player PlayersClosetCrossDistance = {};
	Vehicle VehiclesClosetCrossDistance = {};
	Player PlayersCenterCrossDistance = {};
	Vehicle VehiclesCenterCrossDistance = {};
	Player ClosestVisibleEnemy = {};

	Manager(int width, int height) {
		S_width = width;
		S_height = height;
		TotalEnemy = 0;
		TotalBots = 0;

		this->LocalPlayer = Player(MyLocalPlayer);
		this->LocalVehicles = Vehicle(MyLocalVehicle);

		for (size_t i = 0; i < EntityList.size(); i++) {
			Player player(EntityList[i]);


			if (player.IsValid() && player.ptr != this->LocalPlayer.ptr) {
				if (player.IsBot == true && player.Team != LocalPlayer.Team)
				{
					TotalBots++;
				}
				if (player.IsBot == false && player.Team != LocalPlayer.Team)
				{
					TotalEnemy++;
				}

				player.Distance = CameraCacheEntry.Location.Distance(player.origin) / 100.f;
				this->Players.push_back(player);
			}

		}

		for (size_t i = 0; i < EntityVehicle.size(); i++) {
			Vehicle vehicle(EntityVehicle[i]);
			if (vehicle.IsValid() && vehicle.ptr != this->LocalVehicles.ptr) {
				this->Vehicles.push_back(vehicle);
			}
		}
		for (size_t i = 0; i < EntityPickups.size(); i++) {
			Pickup pickup(EntityPickups[i]);
			if (pickup.IsValid() && pickup.ptr != this->LocalPlayer.ptr) {
				this->Pickups.push_back(pickup);
			}

		}

		float MaxPlayersClosetCrossDistance = FLT_MAX;
		for (size_t i = 0; i < this->Players.size(); i++) {
			if (this->LocalPlayer.Health > 1.f && this->Players[i].Team != this->LocalPlayer.Team && this->Players[i].ptr != this->LocalPlayer.ptr && this->Players[i].Distance < Share::distance) {
				FVector Pos = FVector();
				if (WorldToScreen(this->Players[i].origin, Pos)) {
					float Radius = (Share::AimFov * 8);
					if (Pos.X <= ((S_width / 2) + Radius) &&
						Pos.X >= ((S_width / 2) - Radius) &&
						Pos.Y <= ((S_height / 2) + Radius) &&
						Pos.Y >= ((S_height / 2) - Radius))
					{
						if (this->Players[i].Distance < MaxPlayersClosetCrossDistance)
						{
							MaxPlayersClosetCrossDistance = this->Players[i].Distance;
							PlayersClosetCrossDistance = this->Players[i];
						}
					}
				}
			}
		}

		float MaxVehiclesClosetCrossDistance = FLT_MAX;
		for (size_t i = 0; i < this->Vehicles.size(); i++) {
			if (this->LocalPlayer.Health > 1.f && this->Vehicles[i].ptr != this->LocalPlayer.ptr && this->Vehicles[i].Distance < Share::distance) {
				FVector Pos = FVector();
				if (WorldToScreen(this->Vehicles[i].origin, Pos)) {

					float Radius = (Share::AimFov * 8);
					if (Pos.X <= ((S_width / 2) + Radius) &&
						Pos.X >= ((S_width / 2) - Radius) &&
						Pos.Y <= ((S_height / 2) + Radius) &&
						Pos.Y >= ((S_height / 2) - Radius))
					{
						MaxVehiclesClosetCrossDistance = this->Vehicles[i].Distance;
						VehiclesClosetCrossDistance = this->Vehicles[i];
					}

				}

			}
		}

		float MaxPlayersCenterCrossDistance = FLT_MAX;
		for (size_t i = 0; i < this->Players.size(); i++) {
			if (this->LocalPlayer.Health > 1.f && this->Players[i].Team != this->LocalPlayer.Team && this->Players[i].ptr != this->LocalPlayer.ptr && this->Players[i].Distance < Share::distance) {
				FVector Pos = FVector();
				if (WorldToScreen(this->Players[i].origin, Pos)) {
					float Dist = Utils::GetCrossDistance(Pos.X, Pos.Y, S_width / 2, S_height / 2);
					if (Dist < MaxPlayersCenterCrossDistance)
					{
						float Radius = (Share::AimFov * 8);
						if (Pos.X <= ((S_width / 2) + Radius) &&
							Pos.X >= ((S_width / 2) - Radius) &&
							Pos.Y <= ((S_height / 2) + Radius) &&
							Pos.Y >= ((S_height / 2) - Radius))
						{
							MaxPlayersCenterCrossDistance = Dist;
							PlayersCenterCrossDistance = this->Players[i];

						}
					}
				}
			}
		}

		float MaxVehiclesCenterCrossDistance = FLT_MAX;
		for (size_t i = 0; i < this->Vehicles.size(); i++) {
			if (this->LocalPlayer.Health > 0.1f && this->Vehicles[i].ptr != this->LocalPlayer.ptr && this->Vehicles[i].Distance < Share::distance) {
				FVector Pos = FVector();
				if (WorldToScreen(this->Vehicles[i].origin, Pos)) {
					float Dist = Utils::GetCrossDistance(Pos.X, Pos.Y, S_width / 2, S_height / 2);
					if (Dist < MaxVehiclesCenterCrossDistance)
					{
						float Radius = (Share::AimFov * 8);
						if (Pos.X <= ((S_width / 2) + Radius) &&
							Pos.X >= ((S_width / 2) - Radius) &&
							Pos.Y <= ((S_height / 2) + Radius) &&
							Pos.Y >= ((S_height / 2) - Radius))
						{
							MaxVehiclesCenterCrossDistance = Dist;
							VehiclesCenterCrossDistance = this->Vehicles[i];
						}
					}
				}

			}
		}

		float closestdis = FLT_MAX;
		for (int i = 0; i < this->Players.size(); i++) {
			if (this->LocalPlayer.Health > 0.1f && this->Players[i].ptr != this->LocalPlayer.ptr && this->Players[i].Team != this->LocalPlayer.Team)
			{
				if ((this->Players[i].Distance < closestdis)) {
					ClosestVisibleEnemy = this->Players[i];
					closestdis = this->Players[i].Distance;
				}
			}
		}
	}


	bool WorldToScreen(FVector WorldLocation, FVector& Screenlocation)
	{
		FRotator Rotation = CameraCacheEntry.Rotation;
		D3DMATRIX tempMatrix = Math::Matrix(Rotation);

		FVector vAxisX, vAxisY, vAxisZ;

		vAxisX = FVector(tempMatrix.m[0][0], tempMatrix.m[0][1], tempMatrix.m[0][2]);
		vAxisY = FVector(tempMatrix.m[1][0], tempMatrix.m[1][1], tempMatrix.m[1][2]);
		vAxisZ = FVector(tempMatrix.m[2][0], tempMatrix.m[2][1], tempMatrix.m[2][2]);

		FVector vDelta = WorldLocation - CameraCacheEntry.Location;
		FVector vTransformed = FVector(vDelta.Dot(vDelta, vAxisY), vDelta.Dot(vDelta, vAxisZ), vDelta.Dot(vDelta, vAxisX));

		if (vTransformed.Z < 0.0001f) return false;

		float FovAngle = CameraCacheEntry.FOV;
		float ScreenCenterX = S_width / 2;
		float ScreenCenterY = S_height / 2;
		float ScreenCenterZ = S_height / 2;

		Screenlocation.X = ScreenCenterX + vTransformed.X * (ScreenCenterX / tanf(FovAngle * (float)M_PI / 360.f)) / vTransformed.Z;
		Screenlocation.Y = ScreenCenterY - vTransformed.Y * (ScreenCenterX / tanf(FovAngle * (float)M_PI / 360.f)) / vTransformed.Z;
		Screenlocation.Z = ScreenCenterZ - vTransformed.Z * (ScreenCenterX / tanf(FovAngle * (float)M_PI / 360.f)) / vTransformed.Z;

		//if (Screenlocation.X > S_width || Screenlocation.Y > S_height || Screenlocation.X < 0 || Screenlocation.Y < 0)
		//return false;

		return true;
	}

	bool WorldToScreenAim(FVector WorldLocation, FRotator Rot, FVector& Screenlocation)
	{
		FRotator Rotation = Rot;
		D3DMATRIX tempMatrix = Math::Matrix(Rotation);

		FVector vAxisX, vAxisY, vAxisZ;

		vAxisX = FVector(tempMatrix.m[0][0], tempMatrix.m[0][1], tempMatrix.m[0][2]);
		vAxisY = FVector(tempMatrix.m[1][0], tempMatrix.m[1][1], tempMatrix.m[1][2]);
		vAxisZ = FVector(tempMatrix.m[2][0], tempMatrix.m[2][1], tempMatrix.m[2][2]);

		FVector vDelta = WorldLocation - CameraCacheEntry.Location;
		FVector vTransformed = FVector(vDelta.Dot(vDelta, vAxisY), vDelta.Dot(vDelta, vAxisZ), vDelta.Dot(vDelta, vAxisX));

		if (vTransformed.Z < 0.0001f) return false;


		float FovAngle = CameraCacheEntry.FOV;

		float ScreenCenterX = S_width / 2;
		float ScreenCenterY = S_height / 2;
		float ScreenCenterZ = S_height / 2;

		Screenlocation.X = ScreenCenterX + vTransformed.X * (ScreenCenterX / tanf(FovAngle * (float)M_PI / 360.f)) / vTransformed.Z;
		Screenlocation.Y = ScreenCenterY - vTransformed.Y * (ScreenCenterX / tanf(FovAngle * (float)M_PI / 360.f)) / vTransformed.Z;
		Screenlocation.Z = ScreenCenterZ - vTransformed.Z * (ScreenCenterX / tanf(FovAngle * (float)M_PI / 360.f)) / vTransformed.Z;

		//if (Screenlocation.X > S_width || Screenlocation.Y > S_height || Screenlocation.X < 0 || Screenlocation.Y < 0)
		//	return false;

		return true;
	}

	FVector CalcSoldierFuturePos(FVector InVec)
	{
		FVector NewPos = FVector(), OutPos = FVector();
		if (WorldToScreen(InVec, NewPos))
		{
			OutPos.X = NewPos.X;
			OutPos.Y = NewPos.Y;
			OutPos.Z = NewPos.Z;
		}
		else
		{
			OutPos.X = 0;
			OutPos.Y = 0;
			OutPos.Z = 0;

		}
		return OutPos;
	}
};
