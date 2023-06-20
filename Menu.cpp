#include "Includes.h"
namespace menu
{
	int	iVisualsSubTab = 0;
	int	iMiscSubTab = 0;

	void InputHandler() {
		for (int i = 0; i < 5; i++) ImGui::GetIO().MouseDown[i] = false;
		int button = -1;
		if (GetAsyncKeyState(VK_LBUTTON)) button = 0;
		if (button != -1) ImGui::GetIO().MouseDown[button] = true;
	}


	void CreateStyle()
	{
		auto& colors = ImGui::GetStyle().Colors;

		colors[ImGuiCol_WindowBg] = ImVec4{ 0.10f , 0.10f , 0.10f , 0.10f };
		colors[ImGuiCol_MenuBarBg] = ImVec4{ 0.20f ,0.20f ,0.20f ,0.20f };

		// Border
		colors[ImGuiCol_Border] = ImVec4{ 0.20f ,0.20f ,0.20f ,0.20f };
		colors[ImGuiCol_BorderShadow] = ImVec4{ 0.10f , 0.10f , 0.10f , 0.10f };

		// Text
		colors[ImGuiCol_Text] = ImVec4{ 1.0f, 1.0f, 1.0f, 1.0f };
		colors[ImGuiCol_TextDisabled] = ImVec4{ 0.5f, 0.5f, 0.5f, 1.0f };

		// Headers
		colors[ImGuiCol_Header] = ImVec4{ 0.20f ,0.20f ,0.20f ,0.20f };
		colors[ImGuiCol_HeaderHovered] = ImVec4{ 0.19f, 0.2f, 0.25f, 1.0f };
		colors[ImGuiCol_HeaderActive] = ImVec4{ 0.12f , 0.40f , 0.78f ,1.f };

		// Buttons
		colors[ImGuiCol_Button] = ImVec4{ 0.20f ,0.20f ,0.20f ,0.20f };
		colors[ImGuiCol_ButtonHovered] = ImVec4{ 0.12f , 0.40f , 0.78f ,1.f };
		colors[ImGuiCol_ButtonActive] = ImVec4{ 0.12f , 0.40f , 0.78f ,1.f };
		colors[ImGuiCol_CheckMark] = ImVec4{ 0.74f, 0.58f, 0.98f, 1.0f };

		// Popups
		colors[ImGuiCol_PopupBg] = ImVec4{ .20f ,0.20f ,0.20f ,0.20f };

		// Slider
		colors[ImGuiCol_SliderGrab] = ImVec4{ 0.44f, 0.37f, 0.61f, 0.54f };
		colors[ImGuiCol_SliderGrabActive] = ImVec4{ 0.20f ,0.20f ,0.20f ,0.20f };

		// Frame BG
		colors[ImGuiCol_FrameBg] = ImVec4{ 0.276f, 0.276f, 0.276f, 0.540f };
		colors[ImGuiCol_FrameBgHovered] = ImVec4{ 0.276f, 0.276f, 0.276f, 0.540f };
		colors[ImGuiCol_FrameBgActive] = ImVec4{ 0.276f, 0.276f, 0.276f, 0.540f };

		// Tabs
		colors[ImGuiCol_Tab] = ImVec4{ .20f ,0.20f ,0.20f ,0.20f };
		colors[ImGuiCol_TabHovered] = ImVec4{ 0.24, 0.24f, 0.32f, 1.0f };
		colors[ImGuiCol_TabActive] = ImVec4{ 0.2f, 0.22f, 0.27f, 1.0f };
		colors[ImGuiCol_TabUnfocused] = ImVec4{ 0.16f, 0.16f, 0.21f, 1.0f };
		colors[ImGuiCol_TabUnfocusedActive] = ImVec4{ 0.16f, 0.16f, 0.21f, 1.0f };

		// Title
		colors[ImGuiCol_TitleBg] = ImVec4{ 0.16f, 0.16f, 0.21f, 1.0f };
		colors[ImGuiCol_TitleBgActive] = ImVec4{ 0.16f, 0.16f, 0.21f, 1.0f };
		colors[ImGuiCol_TitleBgCollapsed] = ImVec4{ 0.16f, 0.16f, 0.21f, 1.0f };

		// Scrollbar
		colors[ImGuiCol_ScrollbarBg] = ImVec4{ .20f ,0.20f ,0.20f ,0.20f };
		colors[ImGuiCol_ScrollbarGrab] = ImVec4{ .20f ,0.20f ,0.20f ,0.20f };
		colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4{ 0.19f, 0.2f, 0.25f, 1.0f };
		colors[ImGuiCol_ScrollbarGrabActive] = ImVec4{ 0.12f , 0.40f , 0.78f ,1.f };

		// Seperator
		colors[ImGuiCol_Separator] = ImVec4{ .20f ,0.20f ,0.20f ,0.20f };
		colors[ImGuiCol_SeparatorHovered] = ImVec4{ 0.74f, 0.58f, 0.98f, 1.0f };
		colors[ImGuiCol_SeparatorActive] = ImVec4{ 0.84f, 0.58f, 1.0f, 1.0f };

		// Resize Grip
		colors[ImGuiCol_ResizeGrip] = ImVec4{ 0.20f ,0.20f ,0.20f ,0.20f };
		colors[ImGuiCol_ResizeGripHovered] = ImVec4{ 0.12f , 0.40f , 0.78f ,1.f };
		colors[ImGuiCol_ResizeGripActive] = ImVec4{ 0.12f , 0.40f , 0.78f ,1.f };

		// Docking FrameRounding


		auto& style = ImGui::GetStyle();
		style.TabRounding = 4;
		style.ScrollbarRounding = 9;
		style.WindowRounding = 7;
		style.FrameRounding = 12.000f;
		style.GrabRounding = 12.000f;
		style.GrabMinSize = 5.0f;
		style.FrameRounding = 3;
		style.PopupRounding = 4;
		style.ChildRounding = 4;
		style.Alpha = 100.0f;


	}


#define loop(n) for(int ii = 0; ii < n; ++ ii)
	template<size_t N>
	void RENDER_TAB_SAMELINE(char* (&names)[N], int& activetab, float w, float h)
	{
		bool values[N] = { false };
		values[activetab] = true;
		for (auto i = 0; i < N; ++i) {
			if (ImGui::ToggleButton(names[i], &values[i], 6, ImVec2{ w, h }))
				activetab = i;
			ImGui::SameLine();
		}
	}
	template<size_t N>
	void RENDER_TAB(char* (&names)[N], int& activetab, float w, float h)
	{
		ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 255);
		bool values[N] = { false };
		values[activetab] = true;
		for (auto i = 0; i < N; ++i) {
			ImGui::NewLine(); ImGui::NewLine();
			ImGui::SameLine((190 / 2) - (w / 2));
			if (ImGui::ToggleButton(names[i], &values[i], i, ImVec2{ w, h }))
				activetab = i;
		}
		ImGui::PopStyleVar();
	}


	void tab_Aimbot()
	{
		ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.15, 0.12, 0.21, 10));
		ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.08, 0.07, 0.11, 1.0));
		ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.11, 0.09, 0.16, 1.0));
		ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 0.0f);
		ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 0.0f);
		ImGui::PushStyleVar(ImGuiStyleVar_ChildBorderSize, 1.0f);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 1.0f);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(5, 2));
		loop(3)ImGui::Spacing();

		ImGui::Columns(2, NULL, false);
		ImGui::PushFont(bold);
		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 7);
		ImGui::Text(xorstr_("Main"));
		ImGui::PopFont();
		ImGui::BeginChild(xorstr_("##aimbot-1"), ImVec2(290, 300), true);
		ImGui::SetCursorPosX(ImGui::GetCursorPosX() - 3);

		ImGui::NewLine();
		ImGui::Checkbox("Enable ##aimbot", &Settings::Aimbot::enable);

		ImGui::Combo(xorstr_("Mode"), &Settings::Aimbot::mode, xorstr_("crosshair\0Distance"));
		ImGui::SliderFloat(xorstr_("Human Scale"), &Settings::Aimbot::humanscale, 1.0f, 20.0f, "%0.1f");
		ImGui::SliderFloat(xorstr_("Human Speed"), &Settings::Aimbot::humanspeed, 1.0f, 100.0f, "%1.0f");

		ImGui::EndChild();
		ImGui::NextColumn();
		ImGui::PushFont(bold);
		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 7);
		ImGui::Text("Extra");
		ImGui::PopFont();
		ImGui::BeginChild(xorstr_("##aimbot-2"), ImVec2(290, 300), true);
		ImGui::NewLine();

		ImGui::Checkbox(xorstr_("Aim Prediction"), &Settings::Aimbot::prediction);

		ImGui::Checkbox(xorstr_("Draw Fov"), &Settings::Aimbot::drawfov);
		ImGui::Checkbox(xorstr_("Draw HitBox"), &Settings::Aimbot::drawhitbox);

		if (Settings::Aimbot::drawhitbox)
			ImGui::Combo(xorstr_("HitBox Type"), &Settings::Aimbot::hitboxtype, xorstr_("type1\0type2\0type3"));

		ImGui::EndChild();

		ImGui::Columns(1, NULL, false);
		ImGui::PushFont(bold);
		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 7);
		ImGui::Text("Weapons Config");
		ImGui::PopFont();
		ImGui::BeginChild(xorstr_("##aimbot-3"), ImVec2(608, 260), true);

		ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 0));
		ImGui::PushFont(weapons);
		static char* guns[] = { "A","C","D","E" };
		RENDER_TAB_SAMELINE(guns, Settings::UI::tab_aimbot, 588 / 4, 30);
		ImGui::PopStyleVar();

		ImGui::PopFont();

		ImGui::NewLine(); ImGui::NewLine();
		switch (Settings::UI::tab_aimbot)
		{
		case 0:
			ImGui::Checkbox(xorstr_("Enable##1"), &Settings::Aimbot::AssualtRifle::enable);
			ImGui::Text(xorstr_("Aim Key##1"));
			ImGui::SameLine(80);
			ImGui::Hotkey(&Settings::Aimbot::AssualtRifle::aimkey);
			ImGui::Checkbox(xorstr_("Autolock##1"), &Settings::Aimbot::AssualtRifle::autolock);
			ImGui::SliderInt(xorstr_("Distance##1"), &Settings::Aimbot::AssualtRifle::distance, 1, 400);
			ImGui::SliderFloat(xorstr_("Fov##1"), &Settings::Aimbot::AssualtRifle::fov, 1.f, 180.0f, "%1.0f");
			ImGui::SliderFloat(xorstr_("Smooth##1"), &Settings::Aimbot::AssualtRifle::smooth, 1.0f, 100.0f, "%1.0f");
			ImGui::Checkbox(xorstr_("Nearest Bone##1"), &Settings::Aimbot::AssualtRifle::legitaim);
			if (!Settings::Aimbot::AssualtRifle::legitaim)
				ImGui::Combo(xorstr_("HitBox##1"), &Settings::Aimbot::AssualtRifle::hitbox, xorstr_("Head\0Neck\0Spine"));
			break;

		case 1:
			ImGui::Checkbox(xorstr_("Enable##2"), &Settings::Aimbot::Sniper::enable);
			ImGui::Text(xorstr_("Aim Key##2"));
			ImGui::SameLine(80);
			ImGui::Hotkey(&Settings::Aimbot::Sniper::aimkey);
			ImGui::Checkbox(xorstr_("Autolock##2"), &Settings::Aimbot::Sniper::autolock);
			ImGui::SliderInt(xorstr_("Distance##2"), &Settings::Aimbot::Sniper::distance, 1, 400);
			ImGui::SliderFloat(xorstr_("Fov##2"), &Settings::Aimbot::Sniper::fov, 1.f, 180.0f, "%1.0f");
			ImGui::SliderFloat(xorstr_("Smooth##2"), &Settings::Aimbot::Sniper::smooth, 1.0f, 100.0f, "%1.0f");

			ImGui::Checkbox("Nearest Bone##2", &Settings::Aimbot::Sniper::legitaim);
			if (!Settings::Aimbot::Sniper::legitaim)
				ImGui::Combo(xorstr_("HitBox##2"), &Settings::Aimbot::Sniper::hitbox, xorstr_("Head\0Neck\0Spine"));

			break;
		case 2:
			ImGui::Checkbox(xorstr_("Enable##3"), &Settings::Aimbot::Submachinegun::enable);
			ImGui::Text(xorstr_("Aim Key##3"));
			ImGui::SameLine(80);
			ImGui::Hotkey(&Settings::Aimbot::Submachinegun::aimkey);
			ImGui::Checkbox(xorstr_("Autolock##3"), &Settings::Aimbot::Submachinegun::autolock);
			ImGui::SliderInt(xorstr_("Distance##3"), &Settings::Aimbot::Submachinegun::distance, 1, 400);
			ImGui::SliderFloat(xorstr_("Fov##3"), &Settings::Aimbot::Submachinegun::fov, 1.f, 180.0f, "%1.0f");
			ImGui::SliderFloat(xorstr_("Smooth##3"), &Settings::Aimbot::Submachinegun::smooth, 1.0f, 100.0f, "%1.0f");
			ImGui::Checkbox(xorstr_("Nearest Bone##3"), &Settings::Aimbot::Submachinegun::legitaim);
			if (!Settings::Aimbot::Submachinegun::legitaim)
				ImGui::Combo(xorstr_("HitBox##3"), &Settings::Aimbot::Submachinegun::hitbox, xorstr_("Head\0Neck\0Spine"));

			break;
		case 3:
			ImGui::Checkbox(xorstr_("Enable##4"), &Settings::Aimbot::Shotgun::enable);
			ImGui::Text(xorstr_("Aim Key##4"));
			ImGui::SameLine(80);
			ImGui::Hotkey(&Settings::Aimbot::Shotgun::aimkey);
			ImGui::Checkbox(xorstr_("Autolock##4"), &Settings::Aimbot::Shotgun::autolock);
			ImGui::SliderInt(xorstr_("Distance##4"), &Settings::Aimbot::Shotgun::distance, 1, 400);
			ImGui::SliderFloat(xorstr_("Fov##4"), &Settings::Aimbot::Shotgun::fov, 1.f, 180.0f, "%1.0f");
			ImGui::SliderFloat(xorstr_("Smooth##4"), &Settings::Aimbot::Shotgun::smooth, 1.0f, 100.0f, "%1.0f");

			ImGui::Checkbox("Nearest Bone##4", &Settings::Aimbot::Shotgun::legitaim);
			if (!Settings::Aimbot::Shotgun::legitaim)
				ImGui::Combo(xorstr_("HitBox##4"), &Settings::Aimbot::Shotgun::hitbox, xorstr_("Head\0Neck\0Spine"));

			break;

		default:
			break;
		}
		ImGui::EndChild();
		ImGui::PopStyleVar();
		ImGui::PopStyleVar();
		ImGui::PopStyleVar();
		ImGui::PopStyleVar();
		ImGui::PopStyleVar();
		ImGui::PopStyleColor();
		ImGui::PopStyleColor();
		ImGui::PopStyleColor();
	}
	void tab_Visuals()
	{
		loop(3)ImGui::Spacing();
		ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.15, 0.12, 0.21, 10));
		ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.08, 0.07, 0.11, 1.0));
		ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.11, 0.09, 0.16, 1.0));
		ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 0.0f);
		ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 0.0f);
		ImGui::PushStyleVar(ImGuiStyleVar_ChildBorderSize, 1.0f);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 1.0f);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(5, 2));
		ImGui::Columns(2, NULL, false);
		ImGui::PushFont(bold);
		ImGui::SameLine((290 / 2) - (75 / 2));
		ImGui::Text("Player");
		ImGui::PopFont();
		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 10);
		ImGui::BeginChild("##visuals-1", ImVec2(290, 362), true);

		ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 0));
		static char* player_esp[] = { "Enemy","Team","Settings" };
		RENDER_TAB_SAMELINE(player_esp, Settings::UI::player_esp, 280 / 3, 20);
		ImGui::NewLine();   ImGui::NewLine();
		ImGui::PopStyleVar();

		switch (Settings::UI::player_esp)
		{
		case 0:
			ImGui::Checkbox(xorstr_("Box"), &Settings::ESP::Players::Enemy::boxes);
			ImGui::Checkbox(xorstr_("Name"), &Settings::ESP::Players::Enemy::name);
			ImGui::Checkbox(xorstr_("Distance"), &Settings::ESP::Players::Enemy::distance);
			ImGui::Checkbox(xorstr_("Snapline"), &Settings::ESP::Players::Enemy::snaplines);
			ImGui::Checkbox(xorstr_("Health"), &Settings::ESP::Players::Enemy::health);
			ImGui::Checkbox(xorstr_("Filledbox"), &Settings::ESP::Players::Enemy::filledbox);
			ImGui::Checkbox(xorstr_("Skeleton"), &Settings::ESP::Players::Enemy::skeleton);
			ImGui::Checkbox(xorstr_("Offscreen"), &Settings::ESP::Players::Enemy::offscreen);
			ImGui::Checkbox(xorstr_("Direction Line"), &Settings::ESP::Players::Enemy::directionLine);
			ImGui::Checkbox(xorstr_("Weapon"), &Settings::ESP::Players::Enemy::weapon);
			ImGui::Checkbox(xorstr_("Info"), &Settings::ESP::Players::Enemy::info);
			ImGui::Checkbox(xorstr_("Prediction"), &Settings::ESP::Players::Enemy::prediction);

			break;
		case 1:
			ImGui::Checkbox(xorstr_("Box##1"), &Settings::ESP::Players::Team::boxes);
			ImGui::Checkbox(xorstr_("Name##1"), &Settings::ESP::Players::Team::name);
			ImGui::Checkbox(xorstr_("Distance##1"), &Settings::ESP::Players::Team::distance);
			ImGui::Checkbox(xorstr_("Snapline##1"), &Settings::ESP::Players::Team::snaplines);
			ImGui::Checkbox(xorstr_("Health##1"), &Settings::ESP::Players::Team::health);
			ImGui::Checkbox(xorstr_("Filledbox##1"), &Settings::ESP::Players::Team::filledbox);
			ImGui::Checkbox(xorstr_("Skeleton##1"), &Settings::ESP::Players::Team::skeleton);
			ImGui::Checkbox(xorstr_("Offscreen##1"), &Settings::ESP::Players::Team::offscreen);
			ImGui::Checkbox(xorstr_("Direction Line##1"), &Settings::ESP::Players::Team::directionLine);
			ImGui::Checkbox(xorstr_("Weapon##1"), &Settings::ESP::Players::Team::weapon);
			ImGui::Checkbox(xorstr_("Info##1"), &Settings::ESP::Players::Team::info);
			ImGui::Checkbox(xorstr_("Prediction##1"), &Settings::ESP::Players::Team::prediction);

			break;
		case 2:
			ImGui::Checkbox(xorstr_("Color By TeamID"), &Settings::ESP::Options::colorbyteamid);
			ImGui::Checkbox(xorstr_("Outline"), &Settings::ESP::Options::esp_Outline);
			ImGui::Combo(xorstr_("Box Type"), &Settings::ESP::Options::boxtype, xorstr_("Box\0CornersBox\0GenuineBox\0OctagonBox\0OctagonCornersBox\0ThreeD"));
			ImGui::Combo(xorstr_("Health Type"), &Settings::ESP::Options::healthbartype, xorstr_("Horizontal\0Vertical"));
			ImGui::SliderInt(xorstr_("Direction Line Size"), &Settings::ESP::Options::DirectionLineSize, 1, 500);
			ImGui::SliderInt(xorstr_("Distance Offscreen"), &Settings::ESP::Options::max_distance_offscreen, 1, 180);
			ImGui::SliderInt(xorstr_("Offscreen Range"), &Settings::ESP::Options::offscreen_range, 1, 180);
			ImGui::SliderInt(xorstr_("Players Distance"), &Settings::ESP::Options::playersdis, 1, 400);
			ImGui::SliderInt(xorstr_("Players Name Size"), &Settings::ESP::Options::PlayerFontSize, 1, 20);

			break;
		}

		ImGui::EndChild();


		ImGui::PushFont(bold);
		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + (290 / 2) - (115 / 2));
		ImGui::Text("Vehicles");
		ImGui::PopFont();
		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 10);
		ImGui::BeginChild("##visuals-2", ImVec2(290, 208), true, ImGuiWindowFlags_NoScrollbar);
		ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 0));
		static char* colored_models_char[] = { "Vehicle","Settings" };
		RENDER_TAB_SAMELINE(colored_models_char, Settings::UI::vehicle_esp, 280 / 2, 20);
		ImGui::NewLine();   ImGui::NewLine();
		ImGui::PopStyleVar();
		switch (Settings::UI::vehicle_esp)
		{
		case 0:
			ImGui::Checkbox(xorstr_("Name##2"), &Settings::ESP::Vehicle::vehicleName);
			ImGui::Checkbox(xorstr_("Box##2"), &Settings::ESP::Vehicle::vehicleBox);
			ImGui::Checkbox(xorstr_("Direction Line##2"), &Settings::ESP::Vehicle::vehicleDirectionLine);

			break;
		case 1:
			ImGui::SliderInt(xorstr_("Direction Line Size##2"), &Settings::ESP::Options::VehicleDirectionLineSize, 1, 500);
			ImGui::SliderInt(xorstr_("Vehicle Distance"), &Settings::ESP::Options::vehiclesdis, 1, 600);

			break;
		default:
			break;
		}

		ImGui::EndChild();


		ImGui::NextColumn();

		ImGui::PushFont(bold);
		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + (290 / 2) - (70 / 2));
		ImGui::Text("Items");
		ImGui::PopFont();
		ImGui::SetCursorPosY(ImGui::GetCursorPosY() - 2);
		ImGui::BeginChild("##visuals-3", ImVec2(290, 362), true, ImGuiWindowFlags_NoScrollbar);
		ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 0));
		static char* other_esp_char[] = { "Items","Settings" };
		RENDER_TAB_SAMELINE(other_esp_char, Settings::UI::items_esp, 280 / 2, 20);
		ImGui::NewLine();   ImGui::NewLine();
		ImGui::PopStyleVar();

		switch (Settings::UI::items_esp)
		{
		case 0:
			ImGui::Checkbox(xorstr_("Weapon"), &Settings::ESP::Loot::WEAPON);
			ImGui::Checkbox(xorstr_("Shield"), &Settings::ESP::Loot::SHIELD);
			ImGui::Checkbox(xorstr_("Bullet"), &Settings::ESP::Loot::BULLET);
			ImGui::Checkbox(xorstr_("Weapon Parts"), &Settings::ESP::Loot::WEAPONPARTS);
			ImGui::Checkbox(xorstr_("Shield XP"), &Settings::ESP::Loot::SHIELDXP);
			ImGui::Checkbox(xorstr_("Cariridge"), &Settings::ESP::Loot::CARIRIDGE);
			break;
		case 1:
			ImGui::Text("Weapon Parts");
			ImGui::Separator();
			ImGui::Checkbox(xorstr_("Lv1"), &Settings::ESP::Options::WEAPONPARTS::lv1);
			ImGui::SameLine(50);
			ImGui::Checkbox(xorstr_("Lv2"), &Settings::ESP::Options::WEAPONPARTS::lv2);
			ImGui::Checkbox(xorstr_("Lv3"), &Settings::ESP::Options::WEAPONPARTS::lv3);
			ImGui::SameLine(50);
			ImGui::Checkbox(xorstr_("Lv4"), &Settings::ESP::Options::WEAPONPARTS::lv4);
			ImGui::Checkbox(xorstr_("Lv5"), &Settings::ESP::Options::WEAPONPARTS::lv5);
			ImGui::SameLine(50);
			ImGui::Checkbox(xorstr_("Lv6"), &Settings::ESP::Options::WEAPONPARTS::lv6);
			ImGui::NewLine();

			ImGui::Text("Shield");
			ImGui::Separator();
			ImGui::Checkbox(xorstr_("Lv1##2"), &Settings::ESP::Options::SHIELD::lv1);
			ImGui::SameLine(50);
			ImGui::Checkbox(xorstr_("Lv2##2"), &Settings::ESP::Options::SHIELD::lv2);
			ImGui::Checkbox(xorstr_("Lv3##2"), &Settings::ESP::Options::SHIELD::lv3);
			ImGui::SameLine(50);
			ImGui::Checkbox(xorstr_("Lv4##2"), &Settings::ESP::Options::SHIELD::lv4);
			ImGui::Checkbox(xorstr_("Lv5##2"), &Settings::ESP::Options::SHIELD::lv5);
			ImGui::SameLine(50);
			ImGui::Checkbox(xorstr_("Lv6##2"), &Settings::ESP::Options::SHIELD::lv6);
			ImGui::NewLine();

			ImGui::Text("Options");
			ImGui::Separator();
			ImGui::SliderInt(xorstr_("Font Size"), &Settings::ESP::Options::Loot::fontsize, 1, 20);

			break;
		default:
			break;
		}
		ImGui::EndChild();

		ImGui::PushFont(bold);
		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + (290 / 2) - (52 / 2));
		ImGui::Text("Inventory");
		ImGui::PopFont();
		ImGui::SetCursorPosY(ImGui::GetCursorPosY() - 3);
		ImGui::BeginChild("##visuals-4", ImVec2(290, 208), true, ImGuiWindowFlags_NoScrollbar);
		ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 0));
		ImGui::NewLine();
		ImGui::PopStyleVar();
		ImGui::Checkbox(xorstr_("AirDrop"), &Settings::ESP::Inventory::AirDrop);
		ImGui::Checkbox(xorstr_("Deadbox"), &Settings::ESP::Inventory::Deadbox);
		ImGui::Checkbox(xorstr_("TreasureBox"), &Settings::ESP::Inventory::ElectricBox);

		ImGui::EndChild();


		ImGui::PopStyleVar();
		ImGui::PopStyleVar();
		ImGui::PopStyleVar();
		ImGui::PopStyleVar();
		ImGui::PopStyleVar();
		ImGui::PopStyleColor();
		ImGui::PopStyleColor();
		ImGui::PopStyleColor();

	}
	void tab_Misc()
	{

		loop(3)ImGui::Spacing();
		ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.15, 0.12, 0.21, 10));
		ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.08, 0.07, 0.11, 1.0));
		ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.11, 0.09, 0.16, 1.0));
		ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 0.0f);
		ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 0.0f);
		ImGui::PushStyleVar(ImGuiStyleVar_ChildBorderSize, 1.0f);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 1.0f);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(5, 2));
		ImGui::Columns(2, NULL, false);
		ImGui::PushFont(bold);
		ImGui::SameLine((290 / 2) - (75 / 2));
		ImGui::Text(xorstr_("Radar"));
		ImGui::PopFont();
		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 10);
		ImGui::BeginChild(xorstr_("##misc-1"), ImVec2(290, 362), true);

		ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 0));
		ImGui::NewLine();
		ImGui::PopStyleVar();

		ImGui::Checkbox(xorstr_("Enable"), &Settings::Radar::enable);
		ImGui::Checkbox(xorstr_("Team"), &Settings::Radar::teamRadar);
		ImGui::Checkbox(xorstr_("Enemy"), &Settings::Radar::enemyRadar);
		ImGui::Combo(xorstr_("Radar type"), &Settings::Radar::radartype, xorstr_("Distance\0Dot"));
		ImGui::SliderInt(xorstr_("Distance"), &Settings::Radar::distance_Radar, 1, 1000);


		ImGui::EndChild();

		ImGui::PushFont(bold);
		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + (290 / 2) - (115 / 2));
		ImGui::Text(xorstr_("Crosshair"));
		ImGui::PopFont();
		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 10);
		ImGui::BeginChild(xorstr_("##misc-2"), ImVec2(290, 208), true, ImGuiWindowFlags_NoScrollbar);
		ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 0));
		ImGui::NewLine();
		ImGui::PopStyleVar();
		ImGui::Checkbox(xorstr_("Enable"), &Settings::Crosshair::c_enable);
		ImGui::Combo(xorstr_("Crosshair Type"), &Settings::Crosshair::crosshair, xorstr_("Dot\0Plus\0Cross\0Gap\0Diagonal\0Swastika\0HitMaker"));
		ImGui::SliderFloat(xorstr_("size"), &Settings::Crosshair::size, 1.f, 10.0f, "%1.0f");
		ImGui::SliderFloat(xorstr_("stroke"), &Settings::Crosshair::stroke, 1.f, 10.0f, "%1.0f");
		ImGui::ColorEdit3(xorstr_("Color"), Settings::Color::Crosshair::crosshair);

		ImGui::EndChild();


		ImGui::NextColumn();

		ImGui::PushFont(bold);
		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + (290 / 2) - (70 / 2));
		ImGui::Text(xorstr_("Micro"));
		ImGui::PopFont();
		ImGui::SetCursorPosY(ImGui::GetCursorPosY() - 2);
		ImGui::BeginChild(xorstr_("##misc-3"), ImVec2(290, 362), true, ImGuiWindowFlags_NoScrollbar);
		ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 0));
		ImGui::NewLine();
		ImGui::PopStyleVar();
		ImGui::Checkbox(xorstr_("Enable"), &Settings::Micro::micro);
		ImGui::SliderFloat(xorstr_("Axis X"), &Settings::Micro::microaxis.X, -10.f, 10.0f, "%0.1f");
		ImGui::SliderFloat(xorstr_("Axis Y"), &Settings::Micro::microaxis.Y, 1.0f, 10.0f, "%0.1f");

		ImGui::EndChild();

		ImGui::PushFont(bold);
		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + (290 / 2) - (52 / 2));
		ImGui::Text(xorstr_("General"));
		ImGui::PopFont();
		ImGui::SetCursorPosY(ImGui::GetCursorPosY() - 3);
		ImGui::BeginChild(xorstr_("##misc-4"), ImVec2(290, 208), true, ImGuiWindowFlags_NoScrollbar);
		ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 0));
		ImGui::NewLine();
		ImGui::PopStyleVar();
		ImGui::Checkbox(xorstr_("Total Players"), &Settings::Screen::TotalPlayers);
		ImGui::Checkbox(xorstr_("Player Aiming"), &Settings::Screen::PlayerAiming);
		ImGui::EndChild();


		ImGui::PopStyleVar();
		ImGui::PopStyleVar();
		ImGui::PopStyleVar();
		ImGui::PopStyleVar();
		ImGui::PopStyleVar();
		ImGui::PopStyleColor();
		ImGui::PopStyleColor();
		ImGui::PopStyleColor();



	}
	void tab_Color()
	{
		loop(3)ImGui::Spacing();
		ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.15, 0.12, 0.21, 10));
		ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.08, 0.07, 0.11, 1.0));
		ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.11, 0.09, 0.16, 1.0));
		ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 0.0f);
		ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 0.0f);
		ImGui::PushStyleVar(ImGuiStyleVar_ChildBorderSize, 1.0f);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 1.0f);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(5, 2));
		ImGui::Columns(2, NULL, false);
		ImGui::PushFont(bold);
		ImGui::SameLine((290 / 2) - (75 / 2));
		ImGui::Text("Players");
		ImGui::PopFont();
		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 10);
		ImGui::BeginChild("##colors-1", ImVec2(290, 362), true);

		ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 0));
		static char* player_esp[] = { "Enemy","Team", "Bot" };
		RENDER_TAB_SAMELINE(player_esp, Settings::UI::colors_players, 280 / 3, 20);
		ImGui::NewLine();   ImGui::NewLine();
		ImGui::PopStyleVar();

		switch (Settings::UI::colors_players)
		{
		case 0:
			ImGui::ColorEdit3(xorstr_("Box"), Settings::Color::Players::Enemy::box);
			ImGui::ColorEdit3(xorstr_("Snapline"), Settings::Color::Players::Enemy::snapline);
			ImGui::ColorEdit3(xorstr_("Skeleton"), Settings::Color::Players::Enemy::skeleton);
			ImGui::ColorEdit3(xorstr_("DirectionLine"), Settings::Color::Players::Enemy::directionLine);
			break;
		case 1:
			ImGui::ColorEdit3(xorstr_("Box##2"), Settings::Color::Players::Team::box);
			ImGui::ColorEdit3(xorstr_("Snapline##2"), Settings::Color::Players::Team::snapline);
			ImGui::ColorEdit3(xorstr_("Skeleton##2"), Settings::Color::Players::Team::skeleton);
			ImGui::ColorEdit3(xorstr_("DirectionLine##2"), Settings::Color::Players::Team::directionLine);
			break;
		case 2:
			ImGui::ColorEdit3(xorstr_("Box##3"), Settings::Color::Players::Bot::box);
			ImGui::ColorEdit3(xorstr_("Snapline##3"), Settings::Color::Players::Bot::snapline);
			ImGui::ColorEdit3(xorstr_("Skeleton##3"), Settings::Color::Players::Bot::skeleton);
			ImGui::ColorEdit3(xorstr_("DirectionLine##3"), Settings::Color::Players::Bot::directionLine);
			break;
		}

		ImGui::EndChild();



		ImGui::PushFont(bold);
		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + (290 / 2) - (115 / 2));
		ImGui::Text("Vehicles");
		ImGui::PopFont();
		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 10);
		ImGui::BeginChild("##colors-2", ImVec2(290, 208), true, ImGuiWindowFlags_NoScrollbar);
		ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 0));
		ImGui::NewLine();
		ImGui::PopStyleVar();
		ImGui::ColorEdit3(xorstr_("Box##4"), Settings::Color::Vehicle::Box);
		ImGui::ColorEdit3(xorstr_("Name##4"), Settings::Color::Vehicle::Name);
		ImGui::ColorEdit3(xorstr_("DirectionLine##4"), Settings::Color::Vehicle::DirectionLine);
		ImGui::ColorEdit3(xorstr_("Velocity##4"), Settings::Color::Vehicle::velocity);

		ImGui::EndChild();


		ImGui::NextColumn();

		ImGui::PushFont(bold);
		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + (290 / 2) - (70 / 2));
		ImGui::Text("Items");
		ImGui::PopFont();
		ImGui::SetCursorPosY(ImGui::GetCursorPosY() - 2);
		ImGui::BeginChild("##colors-3", ImVec2(290, 362), true, ImGuiWindowFlags_NoScrollbar);
		ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 0));
		static char* other_esp_char[] = { "Items","Other" };
		RENDER_TAB_SAMELINE(other_esp_char, Settings::UI::colors_items, 280 / 2, 20);
		ImGui::NewLine();   ImGui::NewLine();
		ImGui::PopStyleVar();

		switch (Settings::UI::colors_items)
		{
		case 0:
			ImGui::ColorEdit3(xorstr_("Weapon"), Settings::Color::Loot::WEAPON);
			ImGui::ColorEdit3(xorstr_("Shield"), Settings::Color::Loot::SHIELD);
			ImGui::ColorEdit3(xorstr_("Bullet"), Settings::Color::Loot::BULLET);
			ImGui::ColorEdit3(xorstr_("Weapon Parts"), Settings::Color::Loot::WEAPONPARTS);
			ImGui::ColorEdit3(xorstr_("Shield XP"), Settings::Color::Loot::SHIELDXP);
			ImGui::ColorEdit3(xorstr_("Cariridge"), Settings::Color::Loot::CARIRIDGE);
			ImGui::ColorEdit3(xorstr_("XP Weapon"), Settings::Color::Loot::XPWEAPON);

			break;
		case 1:
			ImGui::ColorEdit3(xorstr_("AirDrop"), Settings::Color::Inventory::AirDrop);
			ImGui::ColorEdit3(xorstr_("DeadBox"), Settings::Color::Inventory::DeadBox);
			ImGui::ColorEdit3(xorstr_("ElectricBox"), Settings::Color::Inventory::ElectricBox);

			break;
		default:
			break;
		}



		ImGui::EndChild();

		ImGui::PushFont(bold);
		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + (290 / 2) - (52 / 2));
		ImGui::Text("Radar");
		ImGui::PopFont();
		ImGui::SetCursorPosY(ImGui::GetCursorPosY() - 3);
		ImGui::BeginChild("##colors-4", ImVec2(290, 362), true, ImGuiWindowFlags_NoScrollbar);
		ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 0));
		ImGui::NewLine();
		ImGui::PopStyleVar();
		ImGui::ColorEdit3(xorstr_("Enemy##5"), Settings::Color::Radar::Enemy);
		ImGui::ColorEdit3(xorstr_("Team##5"), Settings::Color::Radar::Team);
		ImGui::ColorEdit3(xorstr_("Bot##5"), Settings::Color::Radar::BOT);

		ImGui::EndChild();


		ImGui::PopStyleVar();
		ImGui::PopStyleVar();
		ImGui::PopStyleVar();
		ImGui::PopStyleVar();
		ImGui::PopStyleVar();
		ImGui::PopStyleColor();
		ImGui::PopStyleColor();
		ImGui::PopStyleColor();

	}
	void tab_Settings()
	{
		loop(2) ImGui::Spacing();
		ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.12f, 0.40f, 0.78f, 1.f));
		ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.12f, 0.40f, 0.78f, 1.f));
		ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.20f, 0.20f, 0.20f, 0.20f));
		ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 0.0f);
		ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 0.0f);
		ImGui::PushStyleVar(ImGuiStyleVar_ChildBorderSize, 1.0f);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 1.0f);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(5, 2));
		/**/
		ImGui::Columns(2, NULL, false);
		ImGui::PushFont(bold);
		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + (290 / 2) - (35 / 2));
		ImGui::Text(xorstr_("Config"));
		ImGui::PopFont();
		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 10);
		ImGui::BeginChild(xorstr_("##settings-1"), ImVec2(290, 300), true, ImGuiWindowFlags_NoScrollbar);
		ImGui::NewLine();
		static int iConfigSelect = 0;
		static int iMenuSheme = 1;
		std::string ConfigName = "Config";
		ImGui::ComboBoxArray(xorstr_("Select Config"), &iConfigSelect, Utils::ConfigList);
		ImGui::Separator();
		if (ImGui::Button(xorstr_("Create")))
		{
			std::string ConfigFileName = ConfigName.append(std::to_string((int)Utils::ConfigList.size() + 1));

			if (ConfigFileName.size() < 1)
			{
				ConfigFileName = "";
			}
			if (ConfigFileName != "") {
				Config::SaveSettings(xorstr_(".\\Res\\Config\\") + ConfigFileName + ".ini");
				Utils::RefreshConfigs(xorstr_(".\\Res\\Config\\*.ini"));
			}
		}
		ImGui::SameLine();
		if (ImGui::Button(xorstr_("Save")))
		{
			if (Utils::ConfigList.size() != 0)
			{
				Config::SaveSettings(xorstr_(".\\Res\\Config\\") + Utils::ConfigList[iConfigSelect]);
				Utils::RefreshConfigs(xorstr_(".\\Res\\Config\\*.ini"));
			}
		}
		ImGui::SameLine();
		if (ImGui::Button(xorstr_("Load")))
		{
			if (Utils::ConfigList.size() != 0)
			{
				Config::LoadSettings(xorstr_(".\\Res\\Config\\") + Utils::ConfigList[iConfigSelect]);
				Utils::RefreshConfigs(xorstr_(".\\Res\\Config\\*.ini"));
			}
		}
		ImGui::SameLine();
		if (ImGui::Button(xorstr_("Delete")))
		{
			if (Utils::ConfigList.size() != 0)
			{
				std::string szIniFile = xorstr_(".\\Res\\Config\\") + Utils::ConfigList[iConfigSelect];
				remove(szIniFile.c_str());
				Utils::RefreshConfigs(xorstr_(".\\Res\\Config\\*.ini"));
			}
		}
		ImGui::NewLine();
		ImGui::EndChild();
		/**/
		ImGui::NextColumn();
		/**/
		ImGui::PushFont(bold);
		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + (290 / 2) - (ImGui::CalcTextSize("General").x / 2));
		ImGui::Text(xorstr_("General"));
		ImGui::PopFont();
		ImGui::BeginChild(xorstr_("##settings-2"), ImVec2(290, 300), true);
		ImGui::NewLine();
		ImGui::Checkbox(xorstr_("Vsync"), &Settings::Setting::vsync);
		if (Settings::Setting::vsync == true)
			ImGui::Combo(xorstr_("FPS"), &Settings::Setting::fps, xorstr_("30\0 60\0 90"));
		ImGui::Checkbox("Watermark", &Settings::Menu::watermark);
		ImGui::Checkbox("Draw Dots", &Settings::Menu::drawdots);
		ImGui::Checkbox("Chroma Menu", &Settings::Menu::chroma_menu);
		if (Settings::Menu::chroma_menu == false)
			ImGui::ColorEdit3("##menu_color", Settings::Color::Menu::color, ImGuiColorEditFlags_NoInputs);  ImGui::SameLine(); ImGui::Text("Menu color");

		ImGui::Separator();
		ImGui::Text(xorstr_("Anti Streamer"));

		if (ImGui::Button(xorstr_("Enable")))
		{
			HWND Ovarlay_window = FindWindowA(0, Globals::overlayName.c_str());
			DWORD Ovarlay_pid = 0;
			GetWindowThreadProcessId(Ovarlay_window, &Ovarlay_pid);
			if (!Ovarlay_pid)
			{
				return;
			}

			/*bool status = wndhide::hide_window(Ovarlay_pid, Ovarlay_window);
			if (!status)
			{
				return;
			}*/
		}
		ImGui::SameLine();
		if (ImGui::Button(xorstr_("Disable")))
		{
			HWND Ovarlay_window = FindWindowA(0, Globals::overlayName.c_str());
			DWORD Ovarlay_pid = 0;
			GetWindowThreadProcessId(Ovarlay_window, &Ovarlay_pid);
			if (!Ovarlay_pid)
			{
				return;
			}
			/*bool status = wndhide::hide_window(Ovarlay_pid, Ovarlay_window, false);
			if (!status)
			{
				return;
			}*/
		}
		ImGui::Separator();



		ImGui::EndChild();

		ImGui::PopStyleVar();
		ImGui::PopStyleVar();
		ImGui::PopStyleVar();
		ImGui::PopStyleVar();
		ImGui::PopStyleVar();
		ImGui::PopStyleColor();
		ImGui::PopStyleColor();
		ImGui::PopStyleColor();
		ImGui::NextColumn();
		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + (290 / 2) - (290 / 2));
		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 10);
		ImGui::BeginChild(xorstr_("##settings-3"), ImVec2(500, 600), true);
		ImGui::NewLine();
		ImGui::Separator();
		ImGui::Text(xorstr_("User Information"));
		ImGui::Text(xorstr_("User Name: "));
		ImGui::SameLine();
		ImGui::Text(apiinfo::user.c_str());
		ImGui::Text(xorstr_("User Online: "));
		ImGui::SameLine();
		ImGui::Text(apiinfo::NumOnlineUsers.c_str());

		ImGui::Text(xorstr_("Expire Date: "));
		ImGui::SameLine();
		ImGui::Text(apiinfo::_expire.c_str());
		ImGui::Separator();

		ImGui::EndChild();
	}

	void tab_Main()
	{

		static int Tab = 0;
		char* tabs[] = { "Aimbot","Visuals","Misc","Colors","Settings" };

		ImGui::SetNextWindowSize(ImVec2(850, 660));
		ImGui::Begin(xorstr_("##teste"), &Globals::isopened, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoScrollbar);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));
		ImVec2 p = ImGui::GetCursorScreenPos();
		ImGui::GetWindowDrawList()->AddRectFilled(ImVec2(p.x, p.y), ImVec2(p.x + 850, p.y + +5), ImGui::GetColorU32(ImGuiCol_ButtonActive));
		ImGui::PopStyleVar();
		ImGui::Columns(2, NULL, false);

		static float initial_spacing = 225.f;
		if (initial_spacing)
			ImGui::SetColumnWidth(0, initial_spacing), initial_spacing = 0;

		ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 16);
		ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 20);
		ImGui::BeginChild("##1", ImVec2(190, 605), true);
		ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 5);
		ImGui::NewLine(); ImGui::NewLine();
		ImGui::SameLine((160 / 2) - (100 / 2));
		ImGui::Image((void*)(intptr_t)Icons::Logo, ImVec2(128, 128));
		ImGui::NewLine();



		ImGui::NewLine(); ImGui::NewLine(); ImGui::NewLine();
		RENDER_TAB(tabs, Tab, 160, 40);

		ImGui::EndChild();

		ImGui::NextColumn();

		ImGui::PushItemWidth(623);
		ImGui::BeginChild(xorstr_("##2"), ImVec2(623, 660), false);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));
		ImGui::GetWindowDrawList()->AddRectFilled(ImVec2(p.x, p.y), ImVec2(p.x + 850, p.y + +5), ImGui::GetColorU32(ImGuiCol_ButtonActive) /*ImColor::HSV(rainbow,1.f,1.f)*/);
		ImGui::PopStyleVar();
		ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing();
		switch (Tab)
		{
		case 0:
			tab_Aimbot();
			break;
		case 1:
			tab_Visuals();
			break;
		case 2:
			tab_Misc();
			break;
		case 3:
			tab_Color();
			break;
		case 4:
			tab_Settings();
			break;
		default:
			break;
		}



		ImGui::EndChild();
		ImGui::PopItemWidth();

		ImGui::Columns(1, NULL, false);

		ImGui::End();
	}
	void init()
	{
		Settings::Color::rainbow += 0.0005f;
		if (Settings::Color::rainbow > 1.f)
			Settings::Color::rainbow = 0.f;

		float c[3] = { 1.f,1.f,1.f };
		if (Settings::Color::Menu::color != c)
			CreateStyle();
		if (Settings::Menu::chroma_menu)
			CreateStyle();

		if (Globals::isopened)
		{
			tab_Main();
		}
	}


	


}