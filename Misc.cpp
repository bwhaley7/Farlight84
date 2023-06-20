#include "Includes.h"

namespace Misc
{
	void Crosshair()
	{
		switch (Settings::Crosshair::crosshair)
		{
		case GL3Draw::CrosshairStyle::Dot:
			GL3Draw::GetInstance()->DrawCrosshair(GL3Draw::CrosshairStyle::Dot, Globals::width / 2, Globals::height / 2, Settings::Crosshair::size, Settings::Crosshair::stroke, D3DXCOLOR(Settings::Color::Crosshair::crosshair[0], Settings::Color::Crosshair::crosshair[1], Settings::Color::Crosshair::crosshair[2], 1.f));
			break;
		case GL3Draw::CrosshairStyle::Plus:
			GL3Draw::GetInstance()->DrawCrosshair(GL3Draw::CrosshairStyle::Plus, Globals::width / 2, Globals::height / 2, Settings::Crosshair::size, Settings::Crosshair::stroke, D3DXCOLOR(Settings::Color::Crosshair::crosshair[0], Settings::Color::Crosshair::crosshair[1], Settings::Color::Crosshair::crosshair[2], 1.f));
			break;
		case GL3Draw::CrosshairStyle::Cross:
			GL3Draw::GetInstance()->DrawCrosshair(GL3Draw::CrosshairStyle::Cross, Globals::width / 2, Globals::height / 2, Settings::Crosshair::size, Settings::Crosshair::stroke, D3DXCOLOR(Settings::Color::Crosshair::crosshair[0], Settings::Color::Crosshair::crosshair[1], Settings::Color::Crosshair::crosshair[2], 1.f));
			break;
		case GL3Draw::CrosshairStyle::Gap:
			GL3Draw::GetInstance()->DrawCrosshair(GL3Draw::CrosshairStyle::Gap, Globals::width / 2, Globals::height / 2, Settings::Crosshair::size, Settings::Crosshair::stroke, D3DXCOLOR(Settings::Color::Crosshair::crosshair[0], Settings::Color::Crosshair::crosshair[1], Settings::Color::Crosshair::crosshair[2], 1.f));
			break;
		case GL3Draw::CrosshairStyle::Diagonal:
			GL3Draw::GetInstance()->DrawCrosshair(GL3Draw::CrosshairStyle::Diagonal, Globals::width / 2, Globals::height / 2, Settings::Crosshair::size, Settings::Crosshair::stroke, D3DXCOLOR(Settings::Color::Crosshair::crosshair[0], Settings::Color::Crosshair::crosshair[1], Settings::Color::Crosshair::crosshair[2], 1.f));
			break;
		case GL3Draw::CrosshairStyle::Swastika:
			GL3Draw::GetInstance()->DrawCrosshair(GL3Draw::CrosshairStyle::Swastika, Globals::width / 2, Globals::height / 2, Settings::Crosshair::size, Settings::Crosshair::stroke, D3DXCOLOR(Settings::Color::Crosshair::crosshair[0], Settings::Color::Crosshair::crosshair[1], Settings::Color::Crosshair::crosshair[2], 1.f));
			break;
		case GL3Draw::CrosshairStyle::HitMaker:
			GL3Draw::GetInstance()->DrawCrosshair(GL3Draw::CrosshairStyle::HitMaker, Globals::width / 2, Globals::height / 2, Settings::Crosshair::size, Settings::Crosshair::stroke, D3DXCOLOR(Settings::Color::Crosshair::crosshair[0], Settings::Color::Crosshair::crosshair[1], Settings::Color::Crosshair::crosshair[2], 1.f));
			break;
		default:
			break;
		}

	}

	void DrawingAimingList()
	{
		Manager gm(Globals::width, Globals::height);
		int players = 0;
		int weapons = 0;
		int scopes = 0;
		std::string PlayerName = "";
		std::string WeaponName = "";
		std::string ScopeName = "";
		for (Player& player : gm.Players) {

		}
		auto& style = ImGui::GetStyle();
		style.Alpha = 1.f;
		style.Colors[ImGuiCol_WindowBg] = ImVec4(0.1f, 0.1, 0.1f, 1.f);
		if (ImGui::Begin(xorstr_("Aiming At You"), &Settings::Screen::PlayerAiming, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar))
		{
			if (players > 0) PlayerName += "\n";
			if (weapons > 0) WeaponName += "\n";
			if (scopes > 0) ScopeName += "\n";
			ImVec2 size = ImGui::CalcTextSize(PlayerName.c_str());
			ImGui::SetWindowSize(ImVec2(200, 80 + size.y));
			ImGui::Columns(3);
			ImGui::Separator();

			ImGui::Text("Player");
			ImGui::NextColumn();

			ImGui::Text("Weapon");
			ImGui::NextColumn();

			ImGui::Text("Scope");
			ImGui::NextColumn();
			ImGui::Separator();

			ImGui::Text(PlayerName.c_str());
			ImGui::NextColumn();

			ImGui::Text(WeaponName.c_str());
			ImGui::NextColumn();

			ImGui::Text(ScopeName.c_str());
			ImGui::Columns(1);
			ImGui::Separator();
			ImGui::End();
		}

	}
	void DrawingTotalPlayers()
	{
		Manager gm(Globals::width, Globals::height);
		std::string dis = std::to_string((int)gm.ClosestVisibleEnemy.Distance).append(" M").c_str();
		std::string c_players = "Player ";
		std::string c_bots = "Bot ";
		std::string c_Dis = "Closest Distance ";

		auto& style = ImGui::GetStyle();
		style.Alpha = 1.f;
		style.Colors[ImGuiCol_WindowBg] = ImVec4(0.1f, 0.1, 0.1f, 1.f);
		if (ImGui::Begin(xorstr_("TotalPlayers"), &Settings::Screen::TotalPlayers, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar))
		{
			ImGui::SetWindowSize(ImVec2(200, 55));
			ImGui::Separator();
			ImGui::PushFont(m_FVisuals);
			ImGui::Text(c_players.append(std::to_string((int)TotalEnemy)).c_str());
			ImGui::SameLine(100);
			ImGui::Text(c_bots.append(std::to_string((int)TotalBots)).c_str());
			ImGui::Separator();
			ImGui::Text(c_Dis.append(dis).c_str());
			ImGui::PopFont();
			ImGui::Separator();
			ImGui::End();
		}

	}
	void DrawRadars()
	{
		auto& style = ImGui::GetStyle();
		style.Alpha = 1.f;
		style.Colors[ImGuiCol_TitleBg] = ImColor(21, 21, 21, 255);
		style.Colors[ImGuiCol_TitleBgCollapsed] = ImColor(21, 21, 21, 255);
		style.Colors[ImGuiCol_TitleBgActive] = ImColor(21, 21, 21, 255);
		style.Colors[ImGuiCol_WindowBg] = ImVec4(0.1f, 0.1, 0.1f, 1.f);

		if (ImGui::Begin("Radar", &Settings::Radar::enable, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar))
		{
			ImVec2 siz = ImGui::GetContentRegionAvail();
			ImVec2 pos = ImGui::GetCursorScreenPos();
			float RadarCenterX = pos.x + (siz.x / 2);
			float RadarCenterY = pos.y + (siz.y / 2);
			if (!Settings::Menu::chroma_menu)
				GL3Draw::GetInstance()->RenderRect(ImVec2(pos.x, pos.y), ImVec2(pos.x + siz.x, pos.y + siz.y), D3DXCOLOR(Settings::Color::Menu::color[0], Settings::Color::Menu::color[1], Settings::Color::Menu::color[2], 1.f), 0.0F, -1, 1.5f);
			else
				GL3Draw::GetInstance()->RenderRect(ImVec2(pos.x, pos.y), ImVec2(pos.x + siz.x, pos.y + siz.y), ImColor::HSV(Settings::Color::rainbow, 1.f, 1.f, 1.f), 0.0F, -1, 1.5f);

			GL3Draw::GetInstance()->RenderCircleFilled(ImVec2(RadarCenterX, RadarCenterY), 2, ImGui::GetColorU32(ImVec4(100, 100, 100, 100)));
			D3DXCOLOR Chosencolor = D3DXCOLOR();
			Manager gm(Globals::width, Globals::height);
			D3DXCOLOR PlayerColor = D3DXCOLOR();
			D3DXCOLOR VehicleColor = D3DXCOLOR();
			D3DXCOLOR AirDrop = D3DXCOLOR();

			for (Player& player : gm.Players) {
				if (player.Team == gm.LocalPlayer.Team)
				{
					PlayerColor = D3DXCOLOR(Settings::Color::Radar::Team[0], Settings::Color::Radar::Team[1], Settings::Color::Radar::Team[2], 1.f);

				}
				else if (player.IsBot == true)
				{
					PlayerColor = D3DXCOLOR(Settings::Color::Radar::BOT[0], Settings::Color::Radar::BOT[1], Settings::Color::Radar::BOT[2], 1.f);
				}
				else
				{
					PlayerColor = D3DXCOLOR(Settings::Color::Radar::Enemy[0], Settings::Color::Radar::Enemy[1], Settings::Color::Radar::Enemy[2], 1.f);

				}
				float dis = CameraCacheEntry.Location.Distance(player.origin) / 100.f;

				FVector2D single = Utils::WorldToRadar(CameraCacheEntry.Rotation, CameraCacheEntry.Location, player.origin, FVector2D(pos.x, pos.y), FVector2D(siz.x, siz.y));
				if checkSetting(Settings::Radar::teamRadar, Settings::Radar::enemyRadar)
				{
					if (dis >= 0.f && dis < Settings::Radar::distance_Radar)
					{
						if (Settings::Radar::radartype == 0)
							GL3Draw::GetInstance()->RenderText(m_FVisuals, std::to_string((int)dis), ImVec2(single.X, single.Y), 12, PlayerColor);
						else
							GL3Draw::GetInstance()->RenderCircleFilled(ImVec2(single.X, single.Y), 3, PlayerColor);

					}
				}
			}
		}ImGui::End();
	}
	void RCS()
	{
		for (;;)
		{
			if ((Utils::keydown(VK_LBUTTON)) && Settings::Micro::micro)
			{
				FVector2D MicroAxis = {};
				MicroAxis.X = Settings::Micro::microaxis.X;
				MicroAxis.Y = Settings::Micro::microaxis.Y;

				FVector2D GetMicroAxis = MicroAxis;
				FVector2D OutMicroAxis = Utils::Randomize(GetMicroAxis, 6.f, 1.f);
				Inputs::mouse_move(OutMicroAxis.X, OutMicroAxis.Y);

			}
			std::this_thread::sleep_for(std::chrono::milliseconds(50));

		}
	}


	void RunDraw()
	{
		if (Settings::Crosshair::c_enable)
			Crosshair();

		if (Settings::Screen::PlayerAiming)
			DrawingAimingList();

		if (Settings::Screen::TotalPlayers)
			DrawingTotalPlayers();

		if (Settings::Radar::enable)
			DrawRadars();


	}
	void Run()
	{
		RCS();
	}
}