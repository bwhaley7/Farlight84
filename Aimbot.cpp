#include "Includes.h"

namespace Aimbot
{
	FVector CopyBONE = FVector();
	FVector CopyHITBONE = FVector();
	FVector CopyRoot = FVector();
	bool CopyEnableWeapon = false;

	void Aimbot()
	{
		for (;;)
		{
			Manager gm(Globals::width, Globals::height);

			if (GetAsyncKeyState(VK_F2)) {
				Settings::Aimbot::enable = !Settings::Aimbot::enable;
				Sleep(150);
			}

			bool enable = false;
			int aimkey = 1;
			bool autolock = false;
			bool nearestbone = false;
			Share::AimFov = 0;
			Share::distance = 0;
			float smooth = 0;
			int hitbox = 0;
			if (gm.LocalPlayer.WeaponType == (int)EWeaponType::AssualtRifle && gm.LocalPlayer.CurrentClipAmmo > 0)
			{
				enable = Settings::Aimbot::AssualtRifle::enable;
				aimkey = Settings::Aimbot::AssualtRifle::aimkey;
				autolock = Settings::Aimbot::AssualtRifle::autolock;
				nearestbone = Settings::Aimbot::AssualtRifle::legitaim;
				Share::AimFov = Settings::Aimbot::AssualtRifle::fov;
				Share::distance = Settings::Aimbot::AssualtRifle::distance;
				smooth = Settings::Aimbot::AssualtRifle::smooth;
				hitbox = Settings::Aimbot::AssualtRifle::hitbox;
			}
			else if (gm.LocalPlayer.WeaponType == (int)EWeaponType::Submachinegun && gm.LocalPlayer.CurrentClipAmmo > 0)
			{
				enable = Settings::Aimbot::Submachinegun::enable;
				aimkey = Settings::Aimbot::Submachinegun::aimkey;
				autolock = Settings::Aimbot::Submachinegun::autolock;
				nearestbone = Settings::Aimbot::Submachinegun::legitaim;
				Share::AimFov = Settings::Aimbot::Submachinegun::fov;
				Share::distance = Settings::Aimbot::Submachinegun::distance;
				smooth = Settings::Aimbot::Submachinegun::smooth;
				hitbox = Settings::Aimbot::Submachinegun::hitbox;

			}
			else if (gm.LocalPlayer.WeaponType == (int)EWeaponType::Shotgun && gm.LocalPlayer.CurrentClipAmmo > 0)
			{
				enable = Settings::Aimbot::Shotgun::enable;
				aimkey = Settings::Aimbot::Shotgun::aimkey;
				autolock = Settings::Aimbot::Shotgun::autolock;
				nearestbone = Settings::Aimbot::Shotgun::legitaim;
				Share::AimFov = Settings::Aimbot::Shotgun::fov;
				Share::distance = Settings::Aimbot::Shotgun::distance;
				smooth = Settings::Aimbot::Shotgun::smooth;
				hitbox = Settings::Aimbot::Shotgun::hitbox;

			}
			else if (gm.LocalPlayer.WeaponType == (int)EWeaponType::Sniper && gm.LocalPlayer.CurrentClipAmmo > 0)
			{
				enable = Settings::Aimbot::Sniper::enable;
				aimkey = Settings::Aimbot::Sniper::aimkey;
				autolock = Settings::Aimbot::Sniper::autolock;
				nearestbone = Settings::Aimbot::Sniper::legitaim;
				Share::AimFov = Settings::Aimbot::Sniper::fov;
				Share::distance = Settings::Aimbot::Sniper::distance;
				smooth = Settings::Aimbot::Sniper::smooth;
				hitbox = Settings::Aimbot::Sniper::hitbox;

			}
			else
			{
				enable = false;
				aimkey = 1;
				autolock = false;
				nearestbone = false;
				Share::AimFov = 0;
				Share::distance = 0;
				smooth = 0;
				hitbox = 0;
			}

			CopyEnableWeapon = enable;
			CopyBONE = { 0,0,0 };
			CopyHITBONE = { 0,0,0 };
			CopyRoot = { 0,0,0 };

			if ((Utils::keydown(aimkey) || autolock) && Settings::Aimbot::enable)
			{
				if (gm.LocalPlayer.CurrentClipAmmo > 0 && enable)
				{
					std::vector<FVector> HitBoxesToScan = std::vector<FVector>();
					if (Settings::Aimbot::mode == 0)
					{
						if (nearestbone)
							hitbox = 3;

						switch (hitbox)
						{
						case 0:
							HitBoxesToScan.push_back(gm.PlayersCenterCrossDistance.AimBones.HEAD);
							break;
						case 1:
							HitBoxesToScan.push_back(gm.PlayersCenterCrossDistance.AimBones.NECK);
							break;
						case 2:
							HitBoxesToScan.push_back(gm.PlayersCenterCrossDistance.AimBones.Chest);
							break;
						case 3:
							HitBoxesToScan.push_back(gm.PlayersCenterCrossDistance.AimBones.NerstBone);
							break;

						default:
							break;
						}

					}
					else
					{
						if (nearestbone)
							hitbox = 3;

						switch (hitbox)
						{
						case 0:
							HitBoxesToScan.push_back(gm.PlayersClosetCrossDistance.AimBones.HEAD);
							break;
						case 1:
							HitBoxesToScan.push_back(gm.PlayersClosetCrossDistance.AimBones.NECK);
							break;
						case 2:
							HitBoxesToScan.push_back(gm.PlayersClosetCrossDistance.AimBones.Chest);
							break;
						case 3:
							HitBoxesToScan.push_back(gm.PlayersClosetCrossDistance.AimBones.NerstBone);
							break;


						default:
							break;
						}

					}
					for (auto hitbox : HitBoxesToScan)
					{
						if (hitbox.X != 0)
						{
							FVector BONE = hitbox;
							FVector	HITBONE = hitbox;
							if (Settings::Aimbot::prediction)
							{

								float InitialSpeed = gm.LocalPlayer.InitSpeed;
								float BulletGravity = gm.LocalPlayer.ProjectileMaxGravity;
								auto Distance = CameraCacheEntry.Location.Distance(BONE) / 100.f;
								FVector velocity = { 0,0,0 };

								if (Settings::Aimbot::mode == 0)
								{
									velocity = gm.PlayersCenterCrossDistance.ComponentVelocity;
								}
								else
								{
									velocity = gm.PlayersClosetCrossDistance.ComponentVelocity;

								}

								FVector AimCorrection = Utils::AimbotCorrection(InitialSpeed, BulletGravity, Distance, BONE, velocity);
								BONE.X = AimCorrection.X;
								BONE.Y = AimCorrection.Y;
								BONE.Z = AimCorrection.Z;
							}
							FVector HitBone = gm.CalcSoldierFuturePos(FVector(BONE.X, BONE.Y, BONE.Z));
							auto HitBonePos = FVector2D(HitBone.X, HitBone.Y);
							Utils::AimAtPosV2(Globals::width, Globals::height, HitBonePos.X, HitBonePos.Y, smooth, Settings::Aimbot::humanspeed, Settings::Aimbot::humanscale);
							CopyBONE = BONE;
							CopyHITBONE = HITBONE;
							if (Settings::Aimbot::mode == 0)
								CopyRoot = gm.PlayersCenterCrossDistance.AimBones.ROOT;
							else
								CopyRoot = gm.PlayersClosetCrossDistance.AimBones.ROOT;

						}
					}
				}
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(1));

		}
	}

	void RunDraw()
	{
		Manager gm(Globals::width, Globals::height);
		if (Settings::Aimbot::drawfov && Settings::Aimbot::enable && CopyEnableWeapon)
			GL3Draw::GetInstance()->RenderCircle(ImVec2(Globals::width / 2, Globals::height / 2), Share::AimFov * 8, D3DXCOLOR(1.f, 1.f, 1.f, .3), 1);

		if (Settings::Aimbot::enable && Settings::Aimbot::drawhitbox)
		{
			if (CopyBONE.X > 0 && CopyHITBONE.X > 0 && CopyRoot.X > 0) {
				FVector OUTBONE, ovecScreenOrgin, OUTHEAD;
				if (gm.WorldToScreen(CopyBONE, OUTBONE) && gm.WorldToScreen(CopyRoot, ovecScreenOrgin) && gm.WorldToScreen(CopyHITBONE, OUTHEAD))
				{
					if (Settings::Aimbot::hitboxtype == 0)
					{
						GL3Draw::GetInstance()->DrawCrosshair(GL3Draw::CrosshairStyle::Diagonal, OUTBONE.X, OUTBONE.Y, (ovecScreenOrgin.Y - OUTHEAD.Y) / 10, 4.f, D3DXCOLOR(1.f, 0.f, 0.f, 1.f));
						GL3Draw::GetInstance()->RenderCircle(ImVec2(OUTBONE.X, OUTBONE.Y), (ovecScreenOrgin.Y - OUTHEAD.Y) / 4, D3DXCOLOR(1.f, 1.f, 1.f, 1.f), 2.f);
						GL3Draw::GetInstance()->RenderLine(ImVec2(OUTHEAD.X, OUTHEAD.Y), ImVec2(OUTBONE.X, OUTBONE.Y), D3DXCOLOR(1.f, 1.f, 1.f, 1.f), 2.f);
					}
					else if (Settings::Aimbot::hitboxtype == 1)
					{
						//DX11Draw::GetInstance()->DrawCrosshair(DX11Draw::CrosshairStyle::Plus, OUTBONE.X, OUTBONE.Y, (ovecScreenOrgin.Y - OUTHEAD.Y) / 10, 4.f, D3DXCOLOR(1.f, 0.f, 0.f, 1.f));
						GL3Draw::GetInstance()->RenderCircle(ImVec2(OUTBONE.X, OUTBONE.Y), (ovecScreenOrgin.Y - OUTHEAD.Y) / 4, D3DXCOLOR(1.f, 1.f, 1.f, 1.f), 2.f);
						GL3Draw::GetInstance()->RenderLine(ImVec2(OUTHEAD.X, OUTHEAD.Y), ImVec2(OUTBONE.X, OUTBONE.Y), D3DXCOLOR(1.f, 1.f, 1.f, 1.f), 2.f);
					}
					else
					{
						GL3Draw::GetInstance()->DrawCrosshair(GL3Draw::CrosshairStyle::Dot, OUTBONE.X, OUTBONE.Y, (ovecScreenOrgin.Y - OUTHEAD.Y) / 4, 4.f, D3DXCOLOR(1.f, 0.f, 0.f, 1.f));

					}
				}
			}
		}


	}
	void Run()
	{
		Aimbot();
	}
}