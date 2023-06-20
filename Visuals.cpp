#include "Includes.h"
namespace Visuals
{
#pragma region utils drawing

	float ClaculateDistance(float distanceValue)
	{
		float kalinlik;
		if (distanceValue > 200)
			kalinlik = 0.2f;
		else if (distanceValue > 150)
			kalinlik = 0.5f;
		else if (distanceValue > 100)
			kalinlik = 0.7f;
		else if (distanceValue > 50)
			kalinlik = 1.f;
		else
			kalinlik = 1.f;

		return kalinlik;
	}
	void DrawBoneHead(Manager gm, Player pEnemySoldier, FVector from, D3DXCOLOR color, float distanceValue)
	{
		float kalinlik = ClaculateDistance(distanceValue);

		FVector W2S_from = from;
		FVector oW2S_from;
		FVector vecScreenOrgin;
		FVector ovecScreenOrgin;
		if (!gm.WorldToScreen(W2S_from, oW2S_from)) return;
		if (!gm.WorldToScreen(pEnemySoldier.Bones.VRoot, ovecScreenOrgin)) return;

		GL3Draw::GetInstance()->RenderCircle(ImVec2(oW2S_from.X, oW2S_from.Y), (ovecScreenOrgin.Y - oW2S_from.Y) / 10, color, kalinlik);
	}
	void DrawBone(Manager gm, FVector from, FVector to, D3DXCOLOR color, float distanceValue)
	{
		float kalinlik = ClaculateDistance(distanceValue);
		FVector W2S_from = from;
		FVector oW2S_from;
		if (!gm.WorldToScreen(W2S_from, oW2S_from)) return;
		FVector  W2S_to = to;
		FVector oW2S_to;
		if (!gm.WorldToScreen(W2S_to, oW2S_to)) return;
		GL3Draw::GetInstance()->RenderLine(ImVec2(oW2S_from.X, oW2S_from.Y), ImVec2(oW2S_to.X, oW2S_to.Y), color, kalinlik);
	}
	void DrawSkeletonESP(Manager gm, Player pEnemySoldier, D3DXCOLOR Color)
	{
		DrawBoneHead(gm, pEnemySoldier, pEnemySoldier.Bones.vHeadBone, Color, pEnemySoldier.Distance);

		DrawBone(gm, pEnemySoldier.Bones.vHeadBone, pEnemySoldier.Bones.vNeck, Color, pEnemySoldier.Distance);
		DrawBone(gm, pEnemySoldier.Bones.vHip, pEnemySoldier.Bones.vNeck, Color, pEnemySoldier.Distance);
		DrawBone(gm, pEnemySoldier.Bones.vUpperArmLeft, pEnemySoldier.Bones.vNeck, Color, pEnemySoldier.Distance);
		DrawBone(gm, pEnemySoldier.Bones.vUpperArmRight, pEnemySoldier.Bones.vNeck, Color, pEnemySoldier.Distance);
		DrawBone(gm, pEnemySoldier.Bones.vLeftHand, pEnemySoldier.Bones.vUpperArmLeft, Color, pEnemySoldier.Distance);
		DrawBone(gm, pEnemySoldier.Bones.vRightHand, pEnemySoldier.Bones.vUpperArmRight, Color, pEnemySoldier.Distance);
		DrawBone(gm, pEnemySoldier.Bones.vLeftHand, pEnemySoldier.Bones.vLeftHand, Color, pEnemySoldier.Distance);
		DrawBone(gm, pEnemySoldier.Bones.vRightHand, pEnemySoldier.Bones.vRightHand, Color, pEnemySoldier.Distance);
		DrawBone(gm, pEnemySoldier.Bones.vLeftThigh, pEnemySoldier.Bones.vHip, Color, pEnemySoldier.Distance);
		DrawBone(gm, pEnemySoldier.Bones.vRightThigh, pEnemySoldier.Bones.vHip, Color, pEnemySoldier.Distance);
		DrawBone(gm, pEnemySoldier.Bones.vLeftCalf, pEnemySoldier.Bones.vLeftThigh, Color, pEnemySoldier.Distance);
		DrawBone(gm, pEnemySoldier.Bones.vRightCalf, pEnemySoldier.Bones.vRightThigh, Color, pEnemySoldier.Distance);
		DrawBone(gm, pEnemySoldier.Bones.vLeftFoot, pEnemySoldier.Bones.vLeftCalf, Color, pEnemySoldier.Distance);
		DrawBone(gm, pEnemySoldier.Bones.vRightFoot, pEnemySoldier.Bones.vRightCalf, Color, pEnemySoldier.Distance);
	}



	static void box3d_lines(Manager gm, FVector center, float x1, float y1, float z1, float x2, float y2, float z2, D3DXCOLOR col)
	{
		FVector pointPos1 = { center.X + x1, center.Y + y1, center.Z + z1 };
		FVector pointPos2 = { center.X + x2, center.Y + y2, center.Z + z2 };

		FVector sxy1;
		if (!gm.WorldToScreen(pointPos1, sxy1)) return;
		FVector sxy2;
		if (!gm.WorldToScreen(pointPos2, sxy2)) return;

		if (sxy1.X != 0 || sxy1.Y != 0 || sxy2.X != 0 || sxy2.Y != 0)
			GL3Draw::GetInstance()->RenderLine(ImVec2(sxy1.X, sxy1.Y), ImVec2(sxy2.X, sxy2.Y), col, 1.f);
	}

	static void box3d(Manager gm, FVector center, float w, float h, D3DXCOLOR col)
	{
#define padding 10
		box3d_lines(gm, center, -w, -w, 0, w, -w, 0, col);
		box3d_lines(gm, center, -w, -w, h, w, -w, h, col);

		box3d_lines(gm, center, -w, -w, 0, -w, -w, h, col);
		box3d_lines(gm, center, w, -w, 0, w, -w, h, col);

		box3d_lines(gm, center, w, w + padding, 0, w, w + padding, h, col);
		box3d_lines(gm, center, -w, w + padding, 0, -w, w + padding, h, col);
		box3d_lines(gm, center, w, w + padding, 0, -w, w + padding, 0, col);
		box3d_lines(gm, center, w, w + padding, h, -w, w + padding, h, col);

		box3d_lines(gm, center, -w, -w, 0, -w, w + padding, 0, col);
		box3d_lines(gm, center, w, w + padding, 0, w, -w, 0, col);
		box3d_lines(gm, center, -w, -w, h, -w, w + padding, h, col);
		box3d_lines(gm, center, w, w + padding, h, w, -w, h, col);
	}

#pragma endregion
	void ESP()
	{

		Manager gm(Globals::width, Globals::height);
		for (Player& player : gm.Players) {
			FVector footLocation = player.origin;
			footLocation.Z -= 50;
			FVector headLocation = footLocation;
			FVector oheadLocation = FVector();
			FVector ofootLocation = FVector();

			D3DXCOLOR PlayerBox = D3DXCOLOR();
			D3DXCOLOR PlayerSnapline = D3DXCOLOR();
			D3DXCOLOR PlayerSkeleton = D3DXCOLOR();
			D3DXCOLOR PlayerDirectionLine = D3DXCOLOR();
			std::vector<Text> PlayerTexts = std::vector<Text>();
			if (player.Team == gm.LocalPlayer.Team) {
				PlayerBox = D3DXCOLOR(Settings::Color::Players::Team::box[0], Settings::Color::Players::Team::box[1], Settings::Color::Players::Team::box[2], 1.f);
				PlayerSnapline = D3DXCOLOR(Settings::Color::Players::Team::snapline[0], Settings::Color::Players::Team::snapline[1], Settings::Color::Players::Team::snapline[2], 1.f);
				PlayerSkeleton = D3DXCOLOR(Settings::Color::Players::Team::skeleton[0], Settings::Color::Players::Team::skeleton[1], Settings::Color::Players::Team::skeleton[2], 1.f);
				PlayerDirectionLine = D3DXCOLOR(Settings::Color::Players::Team::directionLine[0], Settings::Color::Players::Team::directionLine[1], Settings::Color::Players::Team::directionLine[2], 1.f);

			}
			else if (player.IsBot == true)
			{
				PlayerBox = D3DXCOLOR(Settings::Color::Players::Bot::box[0], Settings::Color::Players::Bot::box[1], Settings::Color::Players::Bot::box[2], 1.f);
				PlayerSnapline = D3DXCOLOR(Settings::Color::Players::Bot::snapline[0], Settings::Color::Players::Bot::snapline[1], Settings::Color::Players::Bot::snapline[2], 1.f);
				PlayerSkeleton = D3DXCOLOR(Settings::Color::Players::Bot::skeleton[0], Settings::Color::Players::Bot::skeleton[1], Settings::Color::Players::Bot::skeleton[2], 1.f);
				PlayerDirectionLine = D3DXCOLOR(Settings::Color::Players::Bot::directionLine[0], Settings::Color::Players::Bot::directionLine[1], Settings::Color::Players::Bot::directionLine[2], 1.f);

			}
			else {

				if (Settings::ESP::Options::colorbyteamid)
				{
					std::srand(player.Team);
					float R = (BYTE)(rand() % 255) / 255.f;
					float G = (BYTE)(rand() % 255) / 255.f;
					float B = (BYTE)(rand() % 255) / 255.f;
					float A = 1.f;

					PlayerBox.r = R;
					PlayerBox.g = G;
					PlayerBox.b = B;
					PlayerBox.a = A;

					PlayerSnapline.r = R;
					PlayerSnapline.g = G;
					PlayerSnapline.b = B;
					PlayerSnapline.a = A;

					PlayerSkeleton.r = R;
					PlayerSkeleton.g = G;
					PlayerSkeleton.b = B;
					PlayerSkeleton.a = A;

					PlayerDirectionLine.r = R;
					PlayerDirectionLine.g = G;
					PlayerDirectionLine.b = B;
					PlayerDirectionLine.a = A;

				}
				else
				{
					PlayerBox = D3DXCOLOR(Settings::Color::Players::Enemy::box[0], Settings::Color::Players::Enemy::box[1], Settings::Color::Players::Enemy::box[2], 1.f);
					PlayerSnapline = D3DXCOLOR(Settings::Color::Players::Enemy::snapline[0], Settings::Color::Players::Enemy::snapline[1], Settings::Color::Players::Enemy::snapline[2], 1.f);
					PlayerSkeleton = D3DXCOLOR(Settings::Color::Players::Enemy::skeleton[0], Settings::Color::Players::Enemy::skeleton[1], Settings::Color::Players::Enemy::skeleton[2], 1.f);
					PlayerDirectionLine = D3DXCOLOR(Settings::Color::Players::Enemy::directionLine[0], Settings::Color::Players::Enemy::directionLine[1], Settings::Color::Players::Enemy::directionLine[2], 1.f);

				}
			}

			GL3Draw::GetInstance()->RenderText(m_FVisuals, std::string("Spectators:").append(std::to_string((int)gm.LocalPlayer.SpectatorNum)), ImVec2(10, 10), 18, D3DXCOLOR(1, 1, 1, 1));

			if checkSetting(Settings::ESP::Players::Team::skeleton, Settings::ESP::Players::Enemy::skeleton) {
				DrawSkeletonESP(gm, player, PlayerSkeleton);
			}
			if checkSetting(Settings::ESP::Players::Team::boxes, Settings::ESP::Players::Enemy::boxes)
			{
				if (Settings::ESP::Options::boxtype == 5)
				{
					if (player.bIsCrouched == true)  box3d(gm, footLocation, 40, 143, PlayerBox);
					//else if (player.bIsDowned == true)  box3d(gm, footLocation, 80, 100, PlayerBox);
					else
						box3d(gm, footLocation, 40, 190, PlayerBox);
				}
			}
			if checkSetting(Settings::ESP::Players::Team::directionLine, Settings::ESP::Players::Enemy::directionLine)
			{
				FVector start = player.ESPDirectionLine.HEAD;
				FVector angles = player.RelativeRotation.ToVector();
				FVector end = angles * (Settings::ESP::Options::DirectionLineSize)+start;
				FVector screen_start, screen_end;
				if (gm.WorldToScreen(start, screen_start) && gm.WorldToScreen(end, screen_end)) {
					GL3Draw::GetInstance()->RenderLine(ImVec2(screen_start.X, screen_start.Y), ImVec2(screen_end.X, screen_end.Y), PlayerDirectionLine, 1.f);
					GL3Draw::GetInstance()->RenderCircleFilled(ImVec2(screen_end.X, screen_end.Y), 4, PlayerDirectionLine);
				}

			}
			if (checkSetting(Settings::ESP::Players::Team::prediction, Settings::ESP::Players::Enemy::prediction) && Settings::Aimbot::enable == false)
			{
				if (player.ComponentVelocity.Size() > 500 && Settings::Aimbot::enable == false)
				{

					float bulletspeed = gm.LocalPlayer.InitSpeed;
					FVector BONE = player.ESPPrediction.HEAD;
					FVector velocity = player.ComponentVelocity;

					auto Distance = CameraCacheEntry.Location.Distance(BONE) / 100.f;

					FVector AimCorrection = Utils::AimbotCorrection(bulletspeed, gm.LocalPlayer.ProjectileMaxGravity, Distance, BONE, velocity);
					BONE.X = AimCorrection.X;
					BONE.Y = AimCorrection.Y;
					BONE.Z = AimCorrection.Z;

					FVector OUTBONE, ovecScreenOrgin, OUTHEAD;
					if (gm.WorldToScreen(BONE, OUTBONE) && gm.WorldToScreen(player.ESPPrediction.ROOT, ovecScreenOrgin) && gm.WorldToScreen(player.ESPPrediction.HEAD, OUTHEAD))
					{
						if (Settings::ESP::Options::predictiontype == 0)
						{
							GL3Draw::GetInstance()->DrawCrosshair(GL3Draw::CrosshairStyle::Diagonal, OUTBONE.X, OUTBONE.Y, (ovecScreenOrgin.Y - OUTHEAD.Y) / 10, 4.f, D3DXCOLOR(1.f, 0.f, 0.f, 1.f));
							GL3Draw::GetInstance()->RenderCircle(ImVec2(OUTBONE.X, OUTBONE.Y), (ovecScreenOrgin.Y - OUTHEAD.Y) / 4, D3DXCOLOR(1.f, 1.f, 1.f, 1.f), 2.f);
							GL3Draw::GetInstance()->RenderLine(ImVec2(OUTHEAD.X, OUTHEAD.Y), ImVec2(OUTBONE.X, OUTBONE.Y), D3DXCOLOR(1.f, 1.f, 1.f, 1.f), 2.f);
						}
						else if (Settings::ESP::Options::predictiontype == 1)
						{
							//	GL3Draw::GetInstance()->DrawCrosshair(GL3Draw::CrosshairStyle::Plus, OUTBONE.X, OUTBONE.Y, (ovecScreenOrgin.Y - OUTHEAD.Y) / 10, 4.f, D3DXCOLOR(1.f, 0.f, 0.f, 1.f));
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

			if (player.bIsCrouched == true) headLocation.Z += 60.f;
			//else if (player.bIsDowned == true) headLocation.Z += 20.f;
			else
				headLocation.Z += 200.f;

			if ((gm.WorldToScreen(footLocation, ofootLocation) && (gm.WorldToScreen(headLocation, oheadLocation)))) {
				float w2sHeight = Math::Distance3D(ofootLocation, oheadLocation);
				float w2sWidth = w2sHeight;
				float heightoffset = Math::Distance3D(ofootLocation, oheadLocation);
				float H = w2sHeight;
				float W = H / 2;
				float X = oheadLocation.X - W / 2;

				if (player.bIsCrouched == true) w2sWidth /= 2;

				if checkSetting(Settings::ESP::Players::Team::snaplines, Settings::ESP::Players::Enemy::snaplines) {
					GL3Draw::GetInstance()->RenderLine(ImVec2(Globals::width / 2, 0), ImVec2(oheadLocation.X, oheadLocation.Y), PlayerSnapline, 1.f);
				}
				if checkSetting(Settings::ESP::Players::Team::boxes, Settings::ESP::Players::Enemy::boxes) {

					if (Settings::ESP::Options::boxtype == 0)
					{
						if (!Settings::ESP::Options::esp_Outline)
							GL3Draw::GetInstance()->DrawBox(X, oheadLocation.Y, W, H, PlayerBox, 1.f);
						else if (Settings::ESP::Options::esp_Outline)
							GL3Draw::GetInstance()->DrawOutlineBox(X, oheadLocation.Y, W, H, PlayerBox, 1.f);

					}
					if (Settings::ESP::Options::boxtype == 1)
					{
						if (!Settings::ESP::Options::esp_Outline)
							GL3Draw::GetInstance()->DrawCoalBox(X, oheadLocation.Y, W, H, PlayerBox, 1.f);
						else if (Settings::ESP::Options::esp_Outline)
							GL3Draw::GetInstance()->DrawOutlineCoalBox(X, oheadLocation.Y, W, H, PlayerBox, 1.f);

					}
					if (Settings::ESP::Options::boxtype == 2)
					{
						if (!Settings::ESP::Options::esp_Outline)
							GL3Draw::GetInstance()->GenuineBox(X, oheadLocation.Y, W, H, PlayerBox);
						else if (Settings::ESP::Options::esp_Outline)
							GL3Draw::GetInstance()->GenuineOutlineBox(X, oheadLocation.Y, W, H, PlayerBox);
					}
					if (Settings::ESP::Options::boxtype == 3)
					{
						GL3Draw::GetInstance()->DrawOctagonBox(X, oheadLocation.Y, W, H, PlayerBox);
					}
					if (Settings::ESP::Options::boxtype == 4)
					{
						GL3Draw::GetInstance()->DrawOctagonCoalBox(X, oheadLocation.Y, W, H, PlayerBox);

					}


				}
				if checkSetting(Settings::ESP::Players::Team::filledbox, Settings::ESP::Players::Enemy::filledbox) {
					GL3Draw::GetInstance()->DrawBox(X, oheadLocation.Y, W, H, PlayerBox, 1.f);

				}
				if checkSetting(Settings::ESP::Players::Team::health, Settings::ESP::Players::Enemy::health) {

					float Shield = 0;
					D3DXCOLOR Color = D3DXCOLOR();
					if (player.CurrShieldValue > 0)
					{
						Shield = player.CurrShieldValue;
						if (player.CurrShieldLevel == 1)
							Color = D3DXCOLOR(.77f, .77f, .77f, 1.f);
						else if (player.CurrShieldLevel == 2)
							Color = D3DXCOLOR(.52f, .84f, 0.f, 1.f);
						else if (player.CurrShieldLevel == 3)
							Color = D3DXCOLOR(.40f, .92f, .96f, 1.f);
						else if (player.CurrShieldLevel == 4)
							Color = D3DXCOLOR(.86f, .45f, 1.f, 1.f);
						else if (player.CurrShieldLevel == 5)
							Color = D3DXCOLOR(1.f, .51f, .24f, 1.f);
						else if (player.CurrShieldLevel == 6)
							Color = D3DXCOLOR(.98f, .25f, .14f, 1.f);
						else
							Color = D3DXCOLOR(1.0f, 0.84f, 0.0f, 1.f);
					}

					float HP = 0;
					D3DXCOLOR Color2 = D3DXCOLOR();
					if (player.Health > 0)
					{
						HP = player.Health;
						Color2 = D3DXCOLOR(.90f, .90f, .90f, 1.f);
					}

					if (Settings::ESP::Options::healthbartype == 0) {
						if (player.CurrShieldValue > 0)
							GL3Draw::GetInstance()->HorizontalDrawHealth(X, oheadLocation.Y - 7, W, 4, (int)Shield, (int)player.MaxShieldValue, Color, D3DXCOLOR(0.f, 0.f, 0.f, 1.f));

						GL3Draw::GetInstance()->HorizontalDrawHealth(X, oheadLocation.Y - 3, W, 4, (int)HP, (int)player.HealthMax, Color2, D3DXCOLOR(0.f, 0.f, 0.f, 1.f));
					}
					else if (Settings::ESP::Options::healthbartype == 1)
					{
						if (player.CurrShieldValue > 0)
							GL3Draw::GetInstance()->VerticalHealthBar(X - 7, oheadLocation.Y, 4, H, (int)Shield, (int)player.MaxShieldValue, Color, D3DXCOLOR(0.f, 0.f, 0.f, 1.f));

						GL3Draw::GetInstance()->VerticalHealthBar(X - 3, oheadLocation.Y, 4, H, (int)HP, (int)player.HealthMax, Color2, D3DXCOLOR(0.f, 0.f, 0.f, 1.f));
					}
					else
					{
						PlayerTexts.push_back(Text(m_FVisuals, std::string("hp ").append(std::to_string((int)HP)).append("%"), 2, 14, Color));
						if (player.CurrShieldValue > 0)
							PlayerTexts.push_back(Text(m_FVisuals, std::string("sp ").append(std::to_string((int)Shield)).append("%"), 2, 14, Color));

					}
				}
				if checkSetting(Settings::ESP::Players::Team::weapon, Settings::ESP::Players::Enemy::weapon) {

					PlayerTexts.push_back(Text(m_FVisuals, std::string(ReverseWord(wstring_utf8(player.Name))).append("[").append(std::to_string((int)player.CurrentClipAmmo)).append(":").append(to_string((int)player.PrimaryAmmoCap)), 1, 14, D3DXCOLOR(1.f, 1.f, 1.f, 1.f)));
				}
				if checkSetting(Settings::ESP::Players::Team::distance, Settings::ESP::Players::Enemy::distance) {
					if (player.Distance > 0)
						PlayerTexts.push_back(Text(m_FVisuals, std::to_string((int)player.Distance) + "M", 1, 14, D3DXCOLOR(1.f, 1.f, 1.f, 1.f)));
				}
				if (checkSetting(Settings::ESP::Players::Team::name, Settings::ESP::Players::Enemy::name)) {
					const auto pOsPlate = ReverseWord(wstring_utf8(player.OS));
					std::string PlayerName = "---";
					if (player.IsBot)
						PlayerName = "Bot";
					else
						PlayerName = ReverseWord(wstring_utf8(player.Name));

					PlayerTexts.push_back(Text(m_FVisuals, std::string("[").append(pOsPlate).append("]").append(PlayerName), 0, Settings::ESP::Options::PlayerFontSize, D3DXCOLOR(1.f, 1.f, 1.f, 1.f)));
				}
				if checkSetting(Settings::ESP::Players::Team::info, Settings::ESP::Players::Enemy::info) {
					const auto pkillsPlate = player.KillNum;

					PlayerTexts.push_back(Text(m_FVisuals, std::string("Kills:").append(std::to_string((int)pkillsPlate)), 2, 14, D3DXCOLOR(1.f, 1.f, 1.f, 1.f)));
				}
				int middle = oheadLocation.X;
				int Top[3] = { oheadLocation.Y,ofootLocation.Y, oheadLocation.Y };
				for (auto text : PlayerTexts)
				{
					int fontsize = text.size;
					switch (text.side)
					{
					case 0:
						Top[0] -= fontsize + 15;
						GL3Draw::GetInstance()->RenderText(m_FVisuals, text.text.c_str(), ImVec2(middle - 60, Top[0] + 8), text.size, text.color);
						break;
					case 1:
						GL3Draw::GetInstance()->RenderText(m_FVisuals, text.text.c_str(), ImVec2(ofootLocation.X - 11, Top[1] + 2), text.size, text.color);
						Top[1] += fontsize + 1;
						break;
					case 2:
						GL3Draw::GetInstance()->RenderText(m_FVisuals, text.text.c_str(), ImVec2(middle + (heightoffset / 5) + fontsize, Top[2] - 8), text.size, text.color);
						Top[2] += fontsize + 1;
						break;
					}
				}
			}
			else
			{
				if (player.Distance > Settings::ESP::Options::max_distance_offscreen)
					continue;
				if checkSetting(Settings::ESP::Players::Team::offscreen, Settings::ESP::Players::Enemy::offscreen)
				{
					FVector2D EntityPos = Utils::WorldToRadar(CameraCacheEntry.Rotation, CameraCacheEntry.Location, player.origin, FVector2D(0, 0), FVector2D(Globals::width, Globals::height));
					int radar_range = Settings::ESP::Options::offscreen_range;
					int x, y;
					x = EntityPos.X;
					y = EntityPos.Y;

					auto angle = FVector();
					Utils::VectorAnglesRadar(FVector((float)(Globals::width / 2) - x, (float)(Globals::height / 2) - y, 0.f), angle);

					const auto angle_yaw_rad = DEG2RAD(angle.Y + 180.f);
					const auto new_point_x = (Globals::width / 2) + (radar_range) / 2 * 8 * cosf(angle_yaw_rad);
					const auto new_point_y = (Globals::height / 2) + (radar_range) / 2 * 8 * sinf(angle_yaw_rad);

					std::array<FVector, 3> points
					{
						FVector(new_point_x - ((90) / 4 + 3.5f) / 2, new_point_y - ((radar_range) / 4 + 3.5f) / 2, 0.f),
							FVector(new_point_x + ((90) / 4 + 3.5f) / 4, new_point_y, 0.f),
							FVector(new_point_x - ((90) / 4 + 3.5f) / 2, new_point_y + ((radar_range) / 4 + 3.5f) / 2, 0.f)
					};

					Utils::RotateTriangle(points, angle.Y + 180.f);

					GL3Draw::GetInstance()->RenderTriangleFilled(ImVec2(points.at(0).X, points.at(0).Y), ImVec2(points.at(1).X, points.at(1).Y), ImVec2(points.at(2).X, points.at(2).Y), ImColor(1.f, 0.f, 0.f));
				}
			}
			PlayerTexts.clear();
		}
		for (Vehicle& vehicle : gm.Vehicles) {
			FVector Location = vehicle.origin;
			FVector screen = FVector();
			std::vector<Text> VehicleTexts = std::vector<Text>();
			D3DXCOLOR Color3DBOX = D3DXCOLOR();
			D3DXCOLOR ColorName = D3DXCOLOR();
			/*		if (vehicle.ReplicatedMovement.LinearVelocity.Size() > 100)
					{
						Color3DBOX = D3DXCOLOR(Settings::Color::Vehicle::velocity[0], Settings::Color::Vehicle::velocity[1], Settings::Color::Vehicle::velocity[2], 1.f);
						ColorName = D3DXCOLOR(Settings::Color::Vehicle::velocity[0], Settings::Color::Vehicle::velocity[1], Settings::Color::Vehicle::velocity[2], 1.f);
					}
					else
					{
					}
					if (Settings::ESP::Vehicle::vehicleDirectionLine)
					{
						if (vehicle.ReplicatedMovement.LinearVelocity.Size() > 100)
						{
							FVector start = FVector(Location.X, Location.Y, Location.Z + 100.f);
							FVector angles = vehicle.ReplicatedMovement.Rotation.ToVector();
							FVector end = angles * Settings::ESP::Options::VehicleDirectionLineSize + start;
							FVector screen_start, screen_end;
							if (gm.WorldToScreen(start, screen_start) && gm.WorldToScreen(end, screen_end)) {
								GL3Draw::GetInstance()->RenderLine(ImVec2(screen_start.X, screen_start.Y), ImVec2(screen_end.X, screen_end.Y), D3DXCOLOR(Settings::Color::Vehicle::DirectionLine[0], Settings::Color::Vehicle::DirectionLine[1], Settings::Color::Vehicle::DirectionLine[2], 1.f), 1.f);
								GL3Draw::GetInstance()->RenderCircleFilled(ImVec2(screen_end.X, screen_end.Y), 2, D3DXCOLOR(Settings::Color::Vehicle::DirectionLine[0], Settings::Color::Vehicle::DirectionLine[1], Settings::Color::Vehicle::DirectionLine[2], 1.f));
							}
						}
					}*/

			Color3DBOX = D3DXCOLOR(Settings::Color::Vehicle::Box[0], Settings::Color::Vehicle::Box[1], Settings::Color::Vehicle::Box[2], 1.f);
			ColorName = D3DXCOLOR(Settings::Color::Vehicle::Name[0], Settings::Color::Vehicle::Name[1], Settings::Color::Vehicle::Name[2], 1.f);

			if (Settings::ESP::Vehicle::vehicleBox)
				box3d(gm, Location, 240.f, 225.f, Color3DBOX);

			if (gm.WorldToScreen(Location, screen)) {
				if (Settings::ESP::Vehicle::vehicleName)
					VehicleTexts.push_back(Text(m_FVisuals, (GnameType::VehicleType(vehicle.FnameType)).append(" ").append(std::to_string((int)vehicle.Distance).append(" M").c_str()), 1, 14, ColorName));

				for (auto text : VehicleTexts)
				{
					GL3Draw::GetInstance()->RenderText(m_FVisuals, text.text.c_str(), ImVec2(screen.X, screen.Y), text.size, text.color);
				}
			}
			VehicleTexts.clear();
		}
		for (Pickup& pickup : gm.Pickups) {
			FVector Location = pickup.origin;
			FVector screen = FVector();
			std::vector<Text> LootTexts = std::vector<Text>();

			if (gm.WorldToScreen(Location, screen))
			{
				auto pItemPlate = ReverseWord(wstring_utf8(pickup.items));

				if (pickup.type == (int)EItemType::WEAPON && Settings::ESP::Loot::WEAPON)
				{
					GL3Draw::GetInstance()->RenderText(m_FVisuals, pItemPlate.append(" LV").append(std::to_string((int)pickup.Quality)), ImVec2(screen.X, screen.Y), Settings::ESP::Options::Loot::fontsize, D3DXCOLOR(Settings::Color::Loot::WEAPON[0], Settings::Color::Loot::WEAPON[1], Settings::Color::Loot::WEAPON[2], 1.f));
				}
				if (pickup.type == (int)EItemType::WEAPON_PARTS && Settings::ESP::Loot::WEAPONPARTS)
				{
					GL3Draw::GetInstance()->RenderText(m_FVisuals, pItemPlate.append(" LV").append(std::to_string((int)pickup.Quality)), ImVec2(screen.X, screen.Y), Settings::ESP::Options::Loot::fontsize, D3DXCOLOR(Settings::Color::Loot::WEAPONPARTS[0], Settings::Color::Loot::WEAPONPARTS[1], Settings::Color::Loot::WEAPONPARTS[2], 1.f));
				}
				if (pickup.type == (int)EItemType::SHIELD && Settings::ESP::Loot::SHIELD)
				{
					GL3Draw::GetInstance()->RenderText(m_FVisuals, pItemPlate.append(" LV").append(std::to_string((int)pickup.Quality)), ImVec2(screen.X, screen.Y), Settings::ESP::Options::Loot::fontsize, D3DXCOLOR(Settings::Color::Loot::SHIELD[0], Settings::Color::Loot::SHIELD[1], Settings::Color::Loot::SHIELD[2], 1.f));
				}
				if (pickup.type == (int)EItemType::SHIELD_UPGRADE_MATERIAL && Settings::ESP::Loot::SHIELDXP)
				{
					GL3Draw::GetInstance()->RenderText(m_FVisuals, pItemPlate, ImVec2(screen.X, screen.Y), Settings::ESP::Options::Loot::fontsize, D3DXCOLOR(Settings::Color::Loot::SHIELDXP[0], Settings::Color::Loot::SHIELDXP[1], Settings::Color::Loot::SHIELDXP[2], 1.f));
				}
				if (pickup.type == (int)EItemType::BULLET && Settings::ESP::Loot::BULLET)
				{
					GL3Draw::GetInstance()->RenderText(m_FVisuals, pItemPlate, ImVec2(screen.X, screen.Y), Settings::ESP::Options::Loot::fontsize, D3DXCOLOR(Settings::Color::Loot::BULLET[0], Settings::Color::Loot::BULLET[1], Settings::Color::Loot::BULLET[2], 1.f));
				}
				if (pickup.type == (int)EItemType::CARIRIDGE_BAG && Settings::ESP::Loot::CARIRIDGE)
				{
					GL3Draw::GetInstance()->RenderText(m_FVisuals, pItemPlate, ImVec2(screen.X, screen.Y), Settings::ESP::Options::Loot::fontsize, D3DXCOLOR(Settings::Color::Loot::CARIRIDGE[0], Settings::Color::Loot::CARIRIDGE[1], Settings::Color::Loot::CARIRIDGE[2], 1.f));
				}
				if (pickup.type == (int)EItemType::AIRDROPBOX && Settings::ESP::Inventory::AirDrop)
				{
					GL3Draw::GetInstance()->RenderText(m_FVisuals, pItemPlate.append(" ").append(std::to_string((int)pickup.Distance)).append("M"), ImVec2(screen.X, screen.Y), Settings::ESP::Options::Loot::fontsize, D3DXCOLOR(Settings::Color::Inventory::AirDrop[0], Settings::Color::Inventory::AirDrop[1], Settings::Color::Inventory::AirDrop[2], 1.f));
				}
				if (pickup.type == (int)EItemType::DEATHBOX && Settings::ESP::Inventory::Deadbox)
				{
					GL3Draw::GetInstance()->RenderText(m_FVisuals, pItemPlate, ImVec2(screen.X, screen.Y), Settings::ESP::Options::Loot::fontsize, D3DXCOLOR(Settings::Color::Inventory::DeadBox[0], Settings::Color::Inventory::DeadBox[1], Settings::Color::Inventory::DeadBox[2], 1.f));
				}
				if (pickup.type == (int)EItemType::TREASUREBOX && Settings::ESP::Inventory::ElectricBox)
				{
					GL3Draw::GetInstance()->RenderText(m_FVisuals, pItemPlate, ImVec2(screen.X, screen.Y), Settings::ESP::Options::Loot::fontsize, D3DXCOLOR(Settings::Color::Inventory::ElectricBox[0], Settings::Color::Inventory::ElectricBox[1], Settings::Color::Inventory::ElectricBox[2], 1.f));

				}


			}
		}

	}

	void RunDraw()
	{
		ESP();
	}
}