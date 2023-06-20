#include "Includes.h"
namespace Config {
	bool ScanColorFromCvar(const char* str, float* colors)
	{
		int len = strlen(str);
		if (len > 11)return false;
		int clrnum = 0;
		int clrsum = 0;
		for (int i = 0; i < len; i++)
		{
			if (clrnum >= 3)return false;
			if (str[i] >= '0' && str[i] <= '9')
			{
				clrsum = clrsum * 10 + str[i] - (int)'0';
			}
			else
			{
				colors[clrnum++] = (float)clrsum / 255.f;
				clrsum = 0;
			}
		}
		colors[clrnum] = (float)clrsum / 255.f;
		return true;
	}

	void LoadSettings(std::string szIniFile)
	{
		CSX::Cvar::InitPath(szIniFile.c_str());
#pragma region Screen
		Settings::Screen::TotalPlayers = CSX::Cvar::LoadCvar("SCREEN", "S_TotalPlayers", Settings::Screen::TotalPlayers) != false;
		Settings::Screen::PlayerAiming = CSX::Cvar::LoadCvar("SCREEN", "S_PlayerAiming", Settings::Screen::PlayerAiming) != false;

#pragma endregion 
#pragma region Aimbot

		Settings::Aimbot::enable = CSX::Cvar::LoadCvar("AIMBOT", "A_Enable", Settings::Aimbot::enable) != false;

		Settings::Aimbot::humanscale = CSX::Cvar::LoadCvar("AIMBOT", "A_Humanscale", Settings::Aimbot::humanscale);
		Settings::Aimbot::humanspeed = CSX::Cvar::LoadCvar("AIMBOT", "A_Humanspeed", Settings::Aimbot::humanspeed);

		Settings::Aimbot::prediction = CSX::Cvar::LoadCvar("AIMBOT", "A_prediction", Settings::Aimbot::prediction) != false;
		Settings::Aimbot::drawfov = CSX::Cvar::LoadCvar("AIMBOT", "A_Drawfov", Settings::Aimbot::drawfov) != false;
		Settings::Aimbot::drawhitbox = CSX::Cvar::LoadCvar("AIMBOT", "A_Drawhitbox", Settings::Aimbot::drawhitbox) != false;

		Settings::Aimbot::AssualtRifle::aimkey = CSX::Cvar::LoadCvar("AIMBOT", "A_AssualtRifleAimkey", Settings::Aimbot::AssualtRifle::aimkey);
		Settings::Aimbot::AssualtRifle::autolock = CSX::Cvar::LoadCvar("AIMBOT", "A_AssualtRifleAutolock", Settings::Aimbot::AssualtRifle::autolock) != false;
		Settings::Aimbot::AssualtRifle::distance = CSX::Cvar::LoadCvar("AIMBOT", "A_AssualtRifleDistance", Settings::Aimbot::AssualtRifle::distance);
		Settings::Aimbot::AssualtRifle::enable = CSX::Cvar::LoadCvar("AIMBOT", "A_AssualtRifleEnable", Settings::Aimbot::AssualtRifle::enable) != false;
		Settings::Aimbot::AssualtRifle::fov = CSX::Cvar::LoadCvar("AIMBOT", "A_AssualtRifleFov", Settings::Aimbot::AssualtRifle::fov);
		Settings::Aimbot::AssualtRifle::hitbox = CSX::Cvar::LoadCvar("AIMBOT", "A_AssualtRifleHitbox", Settings::Aimbot::AssualtRifle::hitbox);
		Settings::Aimbot::AssualtRifle::legitaim = CSX::Cvar::LoadCvar("AIMBOT", "A_AssualtRifleLegitaim", Settings::Aimbot::AssualtRifle::legitaim) != false;
		Settings::Aimbot::AssualtRifle::smooth = CSX::Cvar::LoadCvar("AIMBOT", "A_AssualtRifleLegitaim", Settings::Aimbot::AssualtRifle::smooth);

		Settings::Aimbot::Shotgun::aimkey = CSX::Cvar::LoadCvar("AIMBOT", "A_ShotgunAimkey", Settings::Aimbot::Shotgun::aimkey);
		Settings::Aimbot::Shotgun::autolock = CSX::Cvar::LoadCvar("AIMBOT", "A_ShotgunAutolock", Settings::Aimbot::Shotgun::autolock) != false;
		Settings::Aimbot::Shotgun::distance = CSX::Cvar::LoadCvar("AIMBOT", "A_ShotgunDistance", Settings::Aimbot::Shotgun::distance);
		Settings::Aimbot::Shotgun::enable = CSX::Cvar::LoadCvar("AIMBOT", "A_ShotgunEnable", Settings::Aimbot::Shotgun::enable) != false;
		Settings::Aimbot::Shotgun::fov = CSX::Cvar::LoadCvar("AIMBOT", "A_ShotgunFov", Settings::Aimbot::Shotgun::fov);
		Settings::Aimbot::Shotgun::hitbox = CSX::Cvar::LoadCvar("AIMBOT", "A_ShotgunHitbox", Settings::Aimbot::Shotgun::hitbox);
		Settings::Aimbot::Shotgun::legitaim = CSX::Cvar::LoadCvar("AIMBOT", "A_ShotgunLegitaim", Settings::Aimbot::Shotgun::legitaim) != false;
		Settings::Aimbot::Shotgun::smooth = CSX::Cvar::LoadCvar("AIMBOT", "A_ShotgunLegitaim", Settings::Aimbot::Shotgun::smooth);

		Settings::Aimbot::Sniper::aimkey = CSX::Cvar::LoadCvar("AIMBOT", "A_SniperAimkey", Settings::Aimbot::Sniper::aimkey);
		Settings::Aimbot::Sniper::autolock = CSX::Cvar::LoadCvar("AIMBOT", "A_SniperAutolock", Settings::Aimbot::Sniper::autolock) != false;
		Settings::Aimbot::Sniper::distance = CSX::Cvar::LoadCvar("AIMBOT", "A_SniperDistance", Settings::Aimbot::Sniper::distance);
		Settings::Aimbot::Sniper::enable = CSX::Cvar::LoadCvar("AIMBOT", "A_SniperEnable", Settings::Aimbot::Sniper::enable) != false;
		Settings::Aimbot::Sniper::fov = CSX::Cvar::LoadCvar("AIMBOT", "A_SniperFov", Settings::Aimbot::Sniper::fov);
		Settings::Aimbot::Sniper::hitbox = CSX::Cvar::LoadCvar("AIMBOT", "A_SniperHitbox", Settings::Aimbot::Sniper::hitbox);
		Settings::Aimbot::Sniper::legitaim = CSX::Cvar::LoadCvar("AIMBOT", "A_SniperLegitaim", Settings::Aimbot::Sniper::legitaim) != false;
		Settings::Aimbot::Sniper::smooth = CSX::Cvar::LoadCvar("AIMBOT", "A_SniperLegitaim", Settings::Aimbot::Sniper::smooth);

		Settings::Aimbot::Submachinegun::aimkey = CSX::Cvar::LoadCvar("AIMBOT", "A_SubmachinegunAimkey", Settings::Aimbot::Submachinegun::aimkey);
		Settings::Aimbot::Submachinegun::autolock = CSX::Cvar::LoadCvar("AIMBOT", "A_SubmachinegunAutolock", Settings::Aimbot::Submachinegun::autolock) != false;
		Settings::Aimbot::Submachinegun::distance = CSX::Cvar::LoadCvar("AIMBOT", "A_SubmachinegunDistance", Settings::Aimbot::Submachinegun::distance);
		Settings::Aimbot::Submachinegun::enable = CSX::Cvar::LoadCvar("AIMBOT", "A_SubmachinegunEnable", Settings::Aimbot::Submachinegun::enable) != false;
		Settings::Aimbot::Submachinegun::fov = CSX::Cvar::LoadCvar("AIMBOT", "A_SubmachinegunFov", Settings::Aimbot::Submachinegun::fov);
		Settings::Aimbot::Submachinegun::hitbox = CSX::Cvar::LoadCvar("AIMBOT", "A_SubmachinegunHitbox", Settings::Aimbot::Submachinegun::hitbox);
		Settings::Aimbot::Submachinegun::legitaim = CSX::Cvar::LoadCvar("AIMBOT", "A_SubmachinegunLegitaim", Settings::Aimbot::Submachinegun::legitaim) != false;
		Settings::Aimbot::Submachinegun::smooth = CSX::Cvar::LoadCvar("AIMBOT", "A_SubmachinegunLegitaim", Settings::Aimbot::Submachinegun::smooth);

#pragma endregion
#pragma region Esp
		Settings::ESP::Players::Team::name = CSX::Cvar::LoadCvar("ESP", "E_TeamName", Settings::ESP::Players::Team::name) != false;
		Settings::ESP::Players::Team::boxes = CSX::Cvar::LoadCvar("ESP", "E_TeamBox", Settings::ESP::Players::Team::boxes) != false;
		Settings::ESP::Players::Team::distance = CSX::Cvar::LoadCvar("ESP", "E_TeamDistance", Settings::ESP::Players::Team::distance) != false;
		Settings::ESP::Players::Team::snaplines = CSX::Cvar::LoadCvar("ESP", "E_TeamSnaplines", Settings::ESP::Players::Team::snaplines) != false;
		Settings::ESP::Players::Team::health = CSX::Cvar::LoadCvar("ESP", "E_TeamHealth", Settings::ESP::Players::Team::health) != false;
		Settings::ESP::Players::Team::filledbox = CSX::Cvar::LoadCvar("ESP", "E_TeamFilledbox", Settings::ESP::Players::Team::filledbox) != false;
		Settings::ESP::Players::Team::skeleton = CSX::Cvar::LoadCvar("ESP", "E_TeamSkeleton", Settings::ESP::Players::Team::skeleton) != false;
		Settings::ESP::Players::Team::offscreen = CSX::Cvar::LoadCvar("ESP", "E_TeamOffscreen", Settings::ESP::Players::Team::offscreen) != false;
		Settings::ESP::Players::Team::directionLine = CSX::Cvar::LoadCvar("ESP", "E_TeamDirectionLine", Settings::ESP::Players::Team::directionLine) != false;
		Settings::ESP::Players::Team::weapon = CSX::Cvar::LoadCvar("ESP", "E_TeamWeapon", Settings::ESP::Players::Team::weapon) != false;
		Settings::ESP::Players::Team::info = CSX::Cvar::LoadCvar("ESP", "E_Teaminfo", Settings::ESP::Players::Team::info) != false;

		Settings::ESP::Players::Enemy::name = CSX::Cvar::LoadCvar("ESP", "E_EnemyName", Settings::ESP::Players::Enemy::name) != false;
		Settings::ESP::Players::Enemy::boxes = CSX::Cvar::LoadCvar("ESP", "E_EnemyBox", Settings::ESP::Players::Enemy::boxes) != false;
		Settings::ESP::Players::Enemy::distance = CSX::Cvar::LoadCvar("ESP", "E_EnemyDistance", Settings::ESP::Players::Enemy::distance) != false;
		Settings::ESP::Players::Enemy::snaplines = CSX::Cvar::LoadCvar("ESP", "E_EnemySnaplines", Settings::ESP::Players::Enemy::snaplines) != false;
		Settings::ESP::Players::Enemy::health = CSX::Cvar::LoadCvar("ESP", "E_EnemyHealth", Settings::ESP::Players::Enemy::health) != false;
		Settings::ESP::Players::Enemy::filledbox = CSX::Cvar::LoadCvar("ESP", "E_EnemyFilledbox", Settings::ESP::Players::Enemy::filledbox) != false;
		Settings::ESP::Players::Enemy::skeleton = CSX::Cvar::LoadCvar("ESP", "E_EnemySkull", Settings::ESP::Players::Enemy::skeleton) != false;
		Settings::ESP::Players::Enemy::offscreen = CSX::Cvar::LoadCvar("ESP", "E_EnemyOffscreen", Settings::ESP::Players::Enemy::offscreen) != false;
		Settings::ESP::Players::Enemy::directionLine = CSX::Cvar::LoadCvar("ESP", "E_EnemyDirectionLine", Settings::ESP::Players::Enemy::directionLine) != false;
		Settings::ESP::Players::Enemy::weapon = CSX::Cvar::LoadCvar("ESP", "E_EnemyWeapon", Settings::ESP::Players::Enemy::weapon) != false;
		Settings::ESP::Players::Enemy::info = CSX::Cvar::LoadCvar("ESP", "E_Enemyinfo", Settings::ESP::Players::Enemy::info) != false;

		Settings::ESP::Loot::BULLET = CSX::Cvar::LoadCvar("ESP", "E_LootBULLET", Settings::ESP::Loot::BULLET) != false;
		Settings::ESP::Loot::SHIELD = CSX::Cvar::LoadCvar("ESP", "E_LootSHIELD", Settings::ESP::Loot::SHIELD) != false;
		Settings::ESP::Loot::SHIELDXP = CSX::Cvar::LoadCvar("ESP", "E_LootSHIELDXP", Settings::ESP::Loot::SHIELDXP) != false;
		Settings::ESP::Loot::WEAPON = CSX::Cvar::LoadCvar("ESP", "E_LootWEAPON", Settings::ESP::Loot::WEAPON) != false;
		Settings::ESP::Loot::WEAPONPARTS = CSX::Cvar::LoadCvar("ESP", "E_LootWEAPONPARTS", Settings::ESP::Loot::WEAPONPARTS) != false;
		Settings::ESP::Loot::CARIRIDGE = CSX::Cvar::LoadCvar("ESP", "E_LootCARIRIDGE", Settings::ESP::Loot::CARIRIDGE) != false;

		Settings::ESP::Inventory::AirDrop = CSX::Cvar::LoadCvar("ESP", "E_InventoryAirDrop", Settings::ESP::Inventory::AirDrop) != false;
		Settings::ESP::Inventory::Deadbox = CSX::Cvar::LoadCvar("ESP", "E_InventoryDeadbox", Settings::ESP::Inventory::Deadbox) != false;
		Settings::ESP::Inventory::ElectricBox = CSX::Cvar::LoadCvar("ESP", "E_InventoryElectricBox", Settings::ESP::Inventory::ElectricBox) != false;

		Settings::ESP::Options::colorbyteamid = CSX::Cvar::LoadCvar("ESP", "E_ColorByTeamID", Settings::ESP::Options::colorbyteamid);
		Settings::ESP::Options::playersdis = CSX::Cvar::LoadCvar("ESP", "E_PlayersDistance", Settings::ESP::Options::playersdis);
		Settings::ESP::Options::max_distance_offscreen = CSX::Cvar::LoadCvar("ESP", "E_OffscreenDistance", Settings::ESP::Options::max_distance_offscreen);
		Settings::ESP::Options::boxtype = CSX::Cvar::LoadCvar("ESP", "E_boxType", Settings::ESP::Options::boxtype);
		Settings::ESP::Options::healthbartype = CSX::Cvar::LoadCvar("ESP", "E_HealthBartype", Settings::ESP::Options::healthbartype);
		Settings::ESP::Options::offscreen_range = CSX::Cvar::LoadCvar("ESP", "E_OffscreenRange", Settings::ESP::Options::offscreen_range);
		Settings::ESP::Options::esp_Outline = CSX::Cvar::LoadCvar("ESP", "E_Outline", Settings::ESP::Options::esp_Outline) != false;
		Settings::ESP::Options::PlayerFontSize = CSX::Cvar::LoadCvar("ESP", "E_PlayerFontSize", Settings::ESP::Options::PlayerFontSize) != false;

		Settings::ESP::Options::WEAPONPARTS::lv1 = CSX::Cvar::LoadCvar("ESP", "E_WeaponPartLv1", Settings::ESP::Options::WEAPONPARTS::lv1) != false;
		Settings::ESP::Options::WEAPONPARTS::lv2 = CSX::Cvar::LoadCvar("ESP", "E_WeaponPartLv2", Settings::ESP::Options::WEAPONPARTS::lv2) != false;
		Settings::ESP::Options::WEAPONPARTS::lv3 = CSX::Cvar::LoadCvar("ESP", "E_WeaponPartLv3", Settings::ESP::Options::WEAPONPARTS::lv3) != false;
		Settings::ESP::Options::WEAPONPARTS::lv4 = CSX::Cvar::LoadCvar("ESP", "E_WeaponPartLv4", Settings::ESP::Options::WEAPONPARTS::lv4) != false;
		Settings::ESP::Options::WEAPONPARTS::lv5 = CSX::Cvar::LoadCvar("ESP", "E_WeaponPartLv5", Settings::ESP::Options::WEAPONPARTS::lv5) != false;
		Settings::ESP::Options::WEAPONPARTS::lv6 = CSX::Cvar::LoadCvar("ESP", "E_WeaponPartLv6", Settings::ESP::Options::WEAPONPARTS::lv6) != false;

		Settings::ESP::Options::SHIELD::lv1 = CSX::Cvar::LoadCvar("ESP", "E_ShieldLv1", Settings::ESP::Options::SHIELD::lv1) != false;
		Settings::ESP::Options::SHIELD::lv2 = CSX::Cvar::LoadCvar("ESP", "E_ShieldLv2", Settings::ESP::Options::SHIELD::lv2) != false;
		Settings::ESP::Options::SHIELD::lv3 = CSX::Cvar::LoadCvar("ESP", "E_ShieldLv3", Settings::ESP::Options::SHIELD::lv3) != false;
		Settings::ESP::Options::SHIELD::lv4 = CSX::Cvar::LoadCvar("ESP", "E_ShieldLv4", Settings::ESP::Options::SHIELD::lv4) != false;
		Settings::ESP::Options::SHIELD::lv5 = CSX::Cvar::LoadCvar("ESP", "E_ShieldLv5", Settings::ESP::Options::SHIELD::lv5) != false;
		Settings::ESP::Options::SHIELD::lv6 = CSX::Cvar::LoadCvar("ESP", "E_ShieldLv6", Settings::ESP::Options::SHIELD::lv6) != false;

		Settings::ESP::Options::Loot::fontsize = CSX::Cvar::LoadCvar("ESP", "E_LootFontSize", Settings::ESP::Options::Loot::fontsize);

#pragma endregion
#pragma region Radar
		Settings::Radar::enable = CSX::Cvar::LoadCvar("RADAR", "R_Enable", Settings::Radar::enable) != false;
		Settings::Radar::teamRadar = CSX::Cvar::LoadCvar("RADAR", "R_TeamPlayers", Settings::Radar::teamRadar) != false;
		Settings::Radar::enemyRadar = CSX::Cvar::LoadCvar("RADAR", "R_EnemyPlayers", Settings::Radar::enemyRadar) != false;

		Settings::Radar::radartype = CSX::Cvar::LoadCvar("RADAR", "R_RadarType", Settings::Radar::radartype);
		Settings::Radar::distance_Radar = CSX::Cvar::LoadCvar("RADAR", "R_Playersdistance", Settings::Radar::distance_Radar);
#pragma endregion
#pragma region Micro
		Settings::Micro::micro = CSX::Cvar::LoadCvar("MICRO", "M_Micro", Settings::Micro::micro) != false;
		Settings::Micro::microaxis.X = CSX::Cvar::LoadCvar("MICRO", "M_MicroAxisX", Settings::Micro::microaxis.X);
		Settings::Micro::microaxis.Y = CSX::Cvar::LoadCvar("MICRO", "M_MicroAxisY", Settings::Micro::microaxis.Y);

#pragma endregion
#pragma region Crosshair
		Settings::Crosshair::c_enable = CSX::Cvar::LoadCvar("CROSSHAIR", "C_Enable", Settings::Crosshair::c_enable) != false;
		Settings::Crosshair::crosshair = CSX::Cvar::LoadCvar("CROSSHAIR", "C_Crosshair", Settings::Crosshair::crosshair);
		Settings::Crosshair::size = CSX::Cvar::LoadCvar("CROSSHAIR", "C_Size", Settings::Crosshair::size);
		Settings::Crosshair::stroke = CSX::Cvar::LoadCvar("CROSSHAIR", "C_Stroke", Settings::Crosshair::stroke);
#pragma endregion
#pragma region Colors
		std::string TeamBox = CSX::Cvar::LoadCvar("COLORS", "CLR_TeamBox", "0,0,0");
		std::string TeamDirectionLine = CSX::Cvar::LoadCvar("COLORS", "CLR_TeamDirectionLine", "0,0,0");
		std::string TeamSkeleton = CSX::Cvar::LoadCvar("COLORS", "CLR_TeamSkeleton", "0,0,0");
		std::string TeamSnapline = CSX::Cvar::LoadCvar("COLORS", "CLR_TeamSnapline", "0,0,0");

		std::string EnemyBox = CSX::Cvar::LoadCvar("COLORS", "CLR_EnemyBox", "0,0,0");
		std::string EnemyDirectionLine = CSX::Cvar::LoadCvar("COLORS", "CLR_EnemyDirectionLine", "0,0,0");
		std::string EnemySkeleton = CSX::Cvar::LoadCvar("COLORS", "CLR_EnemySkeleton", "0,0,0");
		std::string EnemySnapline = CSX::Cvar::LoadCvar("COLORS", "CLR_EnemySnapline", "0,0,0");


		std::string BOTBox = CSX::Cvar::LoadCvar("COLORS", "CLR_BOTBox", "0,0,0");
		std::string BOTDirectionLine = CSX::Cvar::LoadCvar("COLORS", "CLR_BOTDirectionLine", "0,0,0");
		std::string BOTSkeleton = CSX::Cvar::LoadCvar("COLORS", "CLR_BOTSkeleton", "0,0,0");
		std::string BOTSnapline = CSX::Cvar::LoadCvar("COLORS", "CLR_BOTSnapline", "0,0,0");

		std::string RadarBOT = CSX::Cvar::LoadCvar("COLORS", "CLR_RadarBOT", "0,0,0");
		std::string RadarEnemy = CSX::Cvar::LoadCvar("COLORS", "CLR_RadarEnemy", "0,0,0");
		std::string RadarTeam = CSX::Cvar::LoadCvar("COLORS", "CLR_RadarTeam", "0,0,0");

		std::string Crosshair = CSX::Cvar::LoadCvar("COLORS", "CLR_Crosshair", "0,0,0");

		std::string ARMOR = CSX::Cvar::LoadCvar("COLORS", "CLR_LootARMOR", "0,0,0");
		std::string BACKPACK = CSX::Cvar::LoadCvar("COLORS", "CLR_LootBACKPACK", "0,0,0");
		std::string BULLET = CSX::Cvar::LoadCvar("COLORS", "CLR_LootBULLET", "0,0,0");
		std::string SHIELD = CSX::Cvar::LoadCvar("COLORS", "CLR_LootSHIELD", "0,0,0");
		std::string SHIELDXP = CSX::Cvar::LoadCvar("COLORS", "CLR_LootSHIELDXP", "0,0,0");
		std::string WEAPON = CSX::Cvar::LoadCvar("COLORS", "CLR_LootWEAPON", "0,0,0");
		std::string WEAPONPARTS = CSX::Cvar::LoadCvar("COLORS", "CLR_LootWEAPONPARTS", "0,0,0");
		std::string CARIRIDGE = CSX::Cvar::LoadCvar("COLORS", "CLR_LootCARIRIDGE", "0,0,0");
		std::string AirDrop = CSX::Cvar::LoadCvar("COLORS", "CLR_InventoryAirDrop", "0,0,0");
		std::string DeadBox = CSX::Cvar::LoadCvar("COLORS", "CLR_InventoryDeadBox", "0,0,0");
		std::string ElectricBox = CSX::Cvar::LoadCvar("COLORS", "CLR_InventoryElectricBox", "0,0,0");

		ScanColorFromCvar(TeamBox.c_str(), Settings::Color::Players::Team::box);
		ScanColorFromCvar(TeamDirectionLine.c_str(), Settings::Color::Players::Team::directionLine);
		ScanColorFromCvar(TeamSkeleton.c_str(), Settings::Color::Players::Team::skeleton);
		ScanColorFromCvar(TeamSnapline.c_str(), Settings::Color::Players::Team::snapline);

		ScanColorFromCvar(EnemyBox.c_str(), Settings::Color::Players::Enemy::box);
		ScanColorFromCvar(EnemyDirectionLine.c_str(), Settings::Color::Players::Enemy::directionLine);
		ScanColorFromCvar(EnemySkeleton.c_str(), Settings::Color::Players::Enemy::skeleton);
		ScanColorFromCvar(EnemySnapline.c_str(), Settings::Color::Players::Enemy::snapline);


		ScanColorFromCvar(BOTBox.c_str(), Settings::Color::Players::Bot::box);
		ScanColorFromCvar(BOTDirectionLine.c_str(), Settings::Color::Players::Bot::directionLine);
		ScanColorFromCvar(BOTSkeleton.c_str(), Settings::Color::Players::Bot::skeleton);
		ScanColorFromCvar(BOTSnapline.c_str(), Settings::Color::Players::Bot::snapline);

		ScanColorFromCvar(RadarBOT.c_str(), Settings::Color::Radar::BOT);
		ScanColorFromCvar(RadarEnemy.c_str(), Settings::Color::Radar::Enemy);
		ScanColorFromCvar(RadarTeam.c_str(), Settings::Color::Radar::Team);

		ScanColorFromCvar(Crosshair.c_str(), Settings::Color::Crosshair::crosshair);

		ScanColorFromCvar(BULLET.c_str(), Settings::Color::Loot::BULLET);
		ScanColorFromCvar(SHIELD.c_str(), Settings::Color::Loot::SHIELD);
		ScanColorFromCvar(SHIELDXP.c_str(), Settings::Color::Loot::SHIELDXP);
		ScanColorFromCvar(WEAPON.c_str(), Settings::Color::Loot::WEAPON);
		ScanColorFromCvar(WEAPONPARTS.c_str(), Settings::Color::Loot::WEAPONPARTS);
		ScanColorFromCvar(CARIRIDGE.c_str(), Settings::Color::Loot::CARIRIDGE);

		ScanColorFromCvar(AirDrop.c_str(), Settings::Color::Inventory::AirDrop);
		ScanColorFromCvar(DeadBox.c_str(), Settings::Color::Inventory::DeadBox);
		ScanColorFromCvar(ElectricBox.c_str(), Settings::Color::Inventory::ElectricBox);

#pragma endregion
#pragma region Setting
		Settings::Setting::vsync = CSX::Cvar::LoadCvar(xorstr_("Setting"), xorstr_("vsync"), Settings::Setting::vsync) != false;
		Settings::Setting::fps = CSX::Cvar::LoadCvar(xorstr_("Setting"), xorstr_("fps"), Settings::Setting::fps);
		Settings::Menu::chroma_menu = CSX::Cvar::LoadCvar(xorstr_("Menu"), xorstr_("chroma"), Settings::Menu::chroma_menu) != false;
		Settings::Menu::drawdots = CSX::Cvar::LoadCvar(xorstr_("Menu"), xorstr_("drawdots"), Settings::Menu::drawdots) != false;
		Settings::Menu::watermark = CSX::Cvar::LoadCvar(xorstr_("Menu"), xorstr_("watermark"), Settings::Menu::watermark) != false;

#pragma endregion
	}
	void SaveSettings(std::string szIniFile)
	{
		CSX::Cvar::InitPath(szIniFile.c_str());
#pragma region Screen
		CSX::Cvar::SaveCvar("SCREEN", "S_TotalPlayers", Settings::Screen::TotalPlayers);
		CSX::Cvar::SaveCvar("SCREEN", "S_PlayerAiming", Settings::Screen::PlayerAiming);

#pragma endregion 
#pragma region Aimbot

		CSX::Cvar::SaveCvar("AIMBOT", "A_Enable", Settings::Aimbot::enable);

		CSX::Cvar::SaveCvar("AIMBOT", "A_Humanscale", Settings::Aimbot::humanscale);
		CSX::Cvar::SaveCvar("AIMBOT", "A_Humanspeed", Settings::Aimbot::humanspeed);

		CSX::Cvar::SaveCvar("AIMBOT", "A_Drawfov", Settings::Aimbot::drawfov);
		CSX::Cvar::SaveCvar("AIMBOT", "A_Drawhitbox", Settings::Aimbot::drawhitbox);
		CSX::Cvar::SaveCvar("AIMBOT", "A_prediction", Settings::Aimbot::prediction);


		CSX::Cvar::SaveCvar("AIMBOT", "A_AssualtRifleAimkey", Settings::Aimbot::AssualtRifle::aimkey);
		CSX::Cvar::SaveCvar("AIMBOT", "A_AssualtRifleAutolock", Settings::Aimbot::AssualtRifle::autolock);
		CSX::Cvar::SaveCvar("AIMBOT", "A_AssualtRifleDistance", Settings::Aimbot::AssualtRifle::distance);
		CSX::Cvar::SaveCvar("AIMBOT", "A_AssualtRifleEnable", Settings::Aimbot::AssualtRifle::enable);
		CSX::Cvar::SaveCvar("AIMBOT", "A_AssualtRifleFov", Settings::Aimbot::AssualtRifle::fov);
		CSX::Cvar::SaveCvar("AIMBOT", "A_AssualtRifleHitbox", Settings::Aimbot::AssualtRifle::hitbox);
		CSX::Cvar::SaveCvar("AIMBOT", "A_AssualtRifleLegitaim", Settings::Aimbot::AssualtRifle::legitaim);
		CSX::Cvar::SaveCvar("AIMBOT", "A_AssualtRifleLegitaim", Settings::Aimbot::AssualtRifle::smooth);

		CSX::Cvar::SaveCvar("AIMBOT", "A_ShotgunAimkey", Settings::Aimbot::Shotgun::aimkey);
		CSX::Cvar::SaveCvar("AIMBOT", "A_ShotgunAutolock", Settings::Aimbot::Shotgun::autolock);
		CSX::Cvar::SaveCvar("AIMBOT", "A_ShotgunDistance", Settings::Aimbot::Shotgun::distance);
		CSX::Cvar::SaveCvar("AIMBOT", "A_ShotgunEnable", Settings::Aimbot::Shotgun::enable);
		CSX::Cvar::SaveCvar("AIMBOT", "A_ShotgunFov", Settings::Aimbot::Shotgun::fov);
		CSX::Cvar::SaveCvar("AIMBOT", "A_ShotgunHitbox", Settings::Aimbot::Shotgun::hitbox);
		CSX::Cvar::SaveCvar("AIMBOT", "A_ShotgunLegitaim", Settings::Aimbot::Shotgun::legitaim);
		CSX::Cvar::SaveCvar("AIMBOT", "A_ShotgunLegitaim", Settings::Aimbot::Shotgun::smooth);

		CSX::Cvar::SaveCvar("AIMBOT", "A_SniperAimkey", Settings::Aimbot::Sniper::aimkey);
		CSX::Cvar::SaveCvar("AIMBOT", "A_SniperAutolock", Settings::Aimbot::Sniper::autolock);
		CSX::Cvar::SaveCvar("AIMBOT", "A_SniperDistance", Settings::Aimbot::Sniper::distance);
		CSX::Cvar::SaveCvar("AIMBOT", "A_SniperEnable", Settings::Aimbot::Sniper::enable);
		CSX::Cvar::SaveCvar("AIMBOT", "A_SniperFov", Settings::Aimbot::Sniper::fov);
		CSX::Cvar::SaveCvar("AIMBOT", "A_SniperHitbox", Settings::Aimbot::Sniper::hitbox);
		CSX::Cvar::SaveCvar("AIMBOT", "A_SniperLegitaim", Settings::Aimbot::Sniper::legitaim);
		CSX::Cvar::SaveCvar("AIMBOT", "A_SniperLegitaim", Settings::Aimbot::Sniper::smooth);

		CSX::Cvar::SaveCvar("AIMBOT", "A_SubmachinegunAimkey", Settings::Aimbot::Submachinegun::aimkey);
		CSX::Cvar::SaveCvar("AIMBOT", "A_SubmachinegunAutolock", Settings::Aimbot::Submachinegun::autolock);
		CSX::Cvar::SaveCvar("AIMBOT", "A_SubmachinegunDistance", Settings::Aimbot::Submachinegun::distance);
		CSX::Cvar::SaveCvar("AIMBOT", "A_SubmachinegunEnable", Settings::Aimbot::Submachinegun::enable);
		CSX::Cvar::SaveCvar("AIMBOT", "A_SubmachinegunFov", Settings::Aimbot::Submachinegun::fov);
		CSX::Cvar::SaveCvar("AIMBOT", "A_SubmachinegunHitbox", Settings::Aimbot::Submachinegun::hitbox);
		CSX::Cvar::SaveCvar("AIMBOT", "A_SubmachinegunLegitaim", Settings::Aimbot::Submachinegun::legitaim);
		CSX::Cvar::SaveCvar("AIMBOT", "A_SubmachinegunLegitaim", Settings::Aimbot::Submachinegun::smooth);

#pragma endregion
#pragma region Esp
		CSX::Cvar::SaveCvar("ESP", "E_TeamName", Settings::ESP::Players::Team::name);
		CSX::Cvar::SaveCvar("ESP", "E_TeamBox", Settings::ESP::Players::Team::boxes);
		CSX::Cvar::SaveCvar("ESP", "E_TeamDistance", Settings::ESP::Players::Team::distance);
		CSX::Cvar::SaveCvar("ESP", "E_TeamSnaplines", Settings::ESP::Players::Team::snaplines);
		CSX::Cvar::SaveCvar("ESP", "E_TeamHealth", Settings::ESP::Players::Team::health);
		CSX::Cvar::SaveCvar("ESP", "E_TeamFilledbox", Settings::ESP::Players::Team::filledbox);
		CSX::Cvar::SaveCvar("ESP", "E_TeamSkeleton", Settings::ESP::Players::Team::skeleton);
		CSX::Cvar::SaveCvar("ESP", "E_TeamOffscreen", Settings::ESP::Players::Team::offscreen);
		CSX::Cvar::SaveCvar("ESP", "E_TeamDirectionLine", Settings::ESP::Players::Team::directionLine);

		CSX::Cvar::SaveCvar("ESP", "E_EnemyName", Settings::ESP::Players::Enemy::name);
		CSX::Cvar::SaveCvar("ESP", "E_EnemyBox", Settings::ESP::Players::Enemy::boxes);
		CSX::Cvar::SaveCvar("ESP", "E_EnemyDistance", Settings::ESP::Players::Enemy::distance);
		CSX::Cvar::SaveCvar("ESP", "E_EnemySnaplines", Settings::ESP::Players::Enemy::snaplines);
		CSX::Cvar::SaveCvar("ESP", "E_EnemyHealth", Settings::ESP::Players::Enemy::health);
		CSX::Cvar::SaveCvar("ESP", "E_EnemyFilledbox", Settings::ESP::Players::Enemy::filledbox);
		CSX::Cvar::SaveCvar("ESP", "E_EnemySkull", Settings::ESP::Players::Enemy::skeleton);
		CSX::Cvar::SaveCvar("ESP", "E_EnemyOffscreen", Settings::ESP::Players::Enemy::offscreen);
		CSX::Cvar::SaveCvar("ESP", "E_EnemyDirectionLine", Settings::ESP::Players::Enemy::directionLine);
		CSX::Cvar::SaveCvar("ESP", "E_EnemyWeapon", Settings::ESP::Players::Enemy::weapon);
		CSX::Cvar::SaveCvar("ESP", "E_Enemyinfo", Settings::ESP::Players::Enemy::info);


		CSX::Cvar::SaveCvar("ESP", "E_LootBULLET", Settings::ESP::Loot::BULLET);
		CSX::Cvar::SaveCvar("ESP", "E_LootSHIELD", Settings::ESP::Loot::SHIELD);
		CSX::Cvar::SaveCvar("ESP", "E_LootSHIELDXP", Settings::ESP::Loot::SHIELDXP);
		CSX::Cvar::SaveCvar("ESP", "E_LootWEAPON", Settings::ESP::Loot::WEAPON);
		CSX::Cvar::SaveCvar("ESP", "E_LootWEAPONPARTS", Settings::ESP::Loot::WEAPONPARTS);
		CSX::Cvar::SaveCvar("ESP", "E_LootCARIRIDGE", Settings::ESP::Loot::CARIRIDGE);

		CSX::Cvar::SaveCvar("ESP", "E_InventoryAirDrop", Settings::ESP::Inventory::AirDrop);
		CSX::Cvar::SaveCvar("ESP", "E_InventoryDeadbox", Settings::ESP::Inventory::Deadbox);
		CSX::Cvar::SaveCvar("ESP", "E_InventoryElectricBox", Settings::ESP::Inventory::ElectricBox);

		CSX::Cvar::SaveCvar("ESP", "E_ColorByTeamID", Settings::ESP::Options::colorbyteamid);
		CSX::Cvar::SaveCvar("ESP", "E_PlayersDistance", Settings::ESP::Options::playersdis);

		CSX::Cvar::SaveCvar("ESP", "E_OffscreenDistance", Settings::ESP::Options::max_distance_offscreen);
		CSX::Cvar::SaveCvar("ESP", "E_boxType", Settings::ESP::Options::boxtype);
		CSX::Cvar::SaveCvar("ESP", "E_HealthBartype", Settings::ESP::Options::healthbartype);
		CSX::Cvar::SaveCvar("ESP", "E_OffscreenRange", Settings::ESP::Options::offscreen_range);
		CSX::Cvar::SaveCvar("ESP", "E_Outline", Settings::ESP::Options::esp_Outline);
		CSX::Cvar::SaveCvar("ESP", "E_PlayerFontSize", Settings::ESP::Options::PlayerFontSize);

		CSX::Cvar::SaveCvar("ESP", "E_WeaponPartLv1", Settings::ESP::Options::WEAPONPARTS::lv1);
		CSX::Cvar::SaveCvar("ESP", "E_WeaponPartLv2", Settings::ESP::Options::WEAPONPARTS::lv2);
		CSX::Cvar::SaveCvar("ESP", "E_WeaponPartLv3", Settings::ESP::Options::WEAPONPARTS::lv3);
		CSX::Cvar::SaveCvar("ESP", "E_WeaponPartLv4", Settings::ESP::Options::WEAPONPARTS::lv4);
		CSX::Cvar::SaveCvar("ESP", "E_WeaponPartLv5", Settings::ESP::Options::WEAPONPARTS::lv5);
		CSX::Cvar::SaveCvar("ESP", "E_WeaponPartLv6", Settings::ESP::Options::WEAPONPARTS::lv6);

		CSX::Cvar::SaveCvar("ESP", "E_ShieldLv1", Settings::ESP::Options::SHIELD::lv1);
		CSX::Cvar::SaveCvar("ESP", "E_ShieldLv2", Settings::ESP::Options::SHIELD::lv2);
		CSX::Cvar::SaveCvar("ESP", "E_ShieldLv3", Settings::ESP::Options::SHIELD::lv3);
		CSX::Cvar::SaveCvar("ESP", "E_ShieldLv4", Settings::ESP::Options::SHIELD::lv4);
		CSX::Cvar::SaveCvar("ESP", "E_ShieldLv5", Settings::ESP::Options::SHIELD::lv5);
		CSX::Cvar::SaveCvar("ESP", "E_ShieldLv6", Settings::ESP::Options::SHIELD::lv6);

		CSX::Cvar::SaveCvar("ESP", "E_LootFontSize", Settings::ESP::Options::Loot::fontsize);

#pragma endregion
#pragma region Radar
		CSX::Cvar::SaveCvar("RADAR", "R_Enable", Settings::Radar::enable);
		CSX::Cvar::SaveCvar("RADAR", "R_TeamPlayers", Settings::Radar::teamRadar);
		CSX::Cvar::SaveCvar("RADAR", "R_EnemyPlayers", Settings::Radar::enemyRadar);

		CSX::Cvar::SaveCvar("RADAR", "R_RadarType", Settings::Radar::radartype);
		CSX::Cvar::SaveCvar("RADAR", "R_Playersdistance", Settings::Radar::distance_Radar);
#pragma endregion
#pragma region Micro
		CSX::Cvar::SaveCvar("MICRO", "M_Micro", Settings::Micro::micro);
		CSX::Cvar::SaveCvar("MICRO", "M_MicroAxisX", Settings::Micro::microaxis.X);
		CSX::Cvar::SaveCvar("MICRO", "M_MicroAxisY", Settings::Micro::microaxis.Y);
#pragma endregion
#pragma region Crosshair
		CSX::Cvar::SaveCvar("CROSSHAIR", "C_Enable", Settings::Crosshair::c_enable);
		CSX::Cvar::SaveCvar("CROSSHAIR", "C_Crosshair", Settings::Crosshair::crosshair);
		CSX::Cvar::SaveCvar("CROSSHAIR", "C_Size", Settings::Crosshair::size);
		CSX::Cvar::SaveCvar("CROSSHAIR", "C_Stroke", Settings::Crosshair::stroke);
#pragma endregion
#pragma region Colors
		std::string TeamBox =
			std::to_string(int(Settings::Color::Players::Team::box[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Players::Team::box[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Players::Team::box[2] * 255.f));

		std::string TeamDirectionLine =
			std::to_string(int(Settings::Color::Players::Team::directionLine[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Players::Team::directionLine[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Players::Team::directionLine[2] * 255.f));

		std::string TeamSkeleton =
			std::to_string(int(Settings::Color::Players::Team::skeleton[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Players::Team::skeleton[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Players::Team::skeleton[2] * 255.f));

		std::string TeamSnapline =
			std::to_string(int(Settings::Color::Players::Team::snapline[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Players::Team::snapline[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Players::Team::snapline[2] * 255.f));

		std::string EnemyBox =
			std::to_string(int(Settings::Color::Players::Enemy::snapline[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Players::Enemy::snapline[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Players::Enemy::snapline[2] * 255.f));

		std::string EnemyDirectionLine =
			std::to_string(int(Settings::Color::Players::Enemy::directionLine[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Players::Enemy::directionLine[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Players::Enemy::directionLine[2] * 255.f));

		std::string EnemySkeleton =
			std::to_string(int(Settings::Color::Players::Enemy::skeleton[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Players::Enemy::skeleton[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Players::Enemy::skeleton[2] * 255.f));

		std::string EnemySnapline =
			std::to_string(int(Settings::Color::Players::Enemy::snapline[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Players::Enemy::snapline[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Players::Enemy::snapline[2] * 255.f));

		std::string BOTBox =
			std::to_string(int(Settings::Color::Players::Bot::box[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Players::Bot::box[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Players::Bot::box[2] * 255.f));

		std::string BOTDirectionLine =
			std::to_string(int(Settings::Color::Players::Bot::directionLine[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Players::Bot::directionLine[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Players::Bot::directionLine[2] * 255.f));

		std::string BOTSkeleton =
			std::to_string(int(Settings::Color::Players::Bot::skeleton[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Players::Bot::skeleton[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Players::Bot::skeleton[2] * 255.f));

		std::string BOTSnapline =
			std::to_string(int(Settings::Color::Players::Bot::snapline[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Players::Bot::snapline[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Players::Bot::snapline[2] * 255.f));

		std::string RadarEnemy =
			std::to_string(int(Settings::Color::Radar::Enemy[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Radar::Enemy[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Radar::Enemy[2] * 255.f));

		std::string RadarTeam =
			std::to_string(int(Settings::Color::Radar::Team[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Radar::Team[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Radar::Team[2] * 255.f));

		std::string RadarBOT =
			std::to_string(int(Settings::Color::Radar::BOT[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Radar::BOT[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Radar::BOT[2] * 255.f));

		std::string Crosshair =
			std::to_string(int(Settings::Color::Crosshair::crosshair[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Crosshair::crosshair[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Crosshair::crosshair[2] * 255.f));


		std::string BULLET =
			std::to_string(int(Settings::Color::Loot::BULLET[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Loot::BULLET[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Loot::BULLET[2] * 255.f));

		std::string SHIELD =
			std::to_string(int(Settings::Color::Loot::SHIELD[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Loot::SHIELD[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Loot::SHIELD[2] * 255.f));

		std::string SHIELDXP =
			std::to_string(int(Settings::Color::Loot::SHIELDXP[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Loot::SHIELDXP[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Loot::SHIELDXP[2] * 255.f));

		std::string WEAPON =
			std::to_string(int(Settings::Color::Loot::WEAPON[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Loot::WEAPON[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Loot::WEAPON[2] * 255.f));

		std::string WEAPONPARTS =
			std::to_string(int(Settings::Color::Loot::WEAPONPARTS[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Loot::WEAPONPARTS[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Loot::WEAPONPARTS[2] * 255.f));

		std::string CARIRIDGE =
			std::to_string(int(Settings::Color::Loot::CARIRIDGE[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Loot::CARIRIDGE[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Loot::CARIRIDGE[2] * 255.f));

		std::string AirDrop =
			std::to_string(int(Settings::Color::Inventory::AirDrop[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Inventory::AirDrop[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Inventory::AirDrop[2] * 255.f));

		std::string DeadBox =
			std::to_string(int(Settings::Color::Inventory::DeadBox[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Inventory::DeadBox[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Inventory::DeadBox[2] * 255.f));

		std::string ElectricBox =
			std::to_string(int(Settings::Color::Inventory::ElectricBox[0] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Inventory::ElectricBox[1] * 255.f)) + "," +
			std::to_string(int(Settings::Color::Inventory::ElectricBox[2] * 255.f));

		CSX::Cvar::SaveCvar("COLORS", "CLR_TeamBox", TeamBox);
		CSX::Cvar::SaveCvar("COLORS", "CLR_TeamDirectionLine", TeamDirectionLine);
		CSX::Cvar::SaveCvar("COLORS", "CLR_TeamSkeleton", TeamSkeleton);
		CSX::Cvar::SaveCvar("COLORS", "CLR_TeamSnapline", TeamSnapline);

		CSX::Cvar::SaveCvar("COLORS", "CLR_EnemyBox", EnemyBox);
		CSX::Cvar::SaveCvar("COLORS", "CLR_EnemyDirectionLine", EnemyDirectionLine);
		CSX::Cvar::SaveCvar("COLORS", "CLR_EnemySkeleton", EnemySkeleton);
		CSX::Cvar::SaveCvar("COLORS", "CLR_EnemySnapline", EnemySnapline);


		CSX::Cvar::SaveCvar("COLORS", "CLR_BOTBox", BOTBox);
		CSX::Cvar::SaveCvar("COLORS", "CLR_BOTDirectionLine", BOTDirectionLine);
		CSX::Cvar::SaveCvar("COLORS", "CLR_BOTSkeleton", BOTSkeleton);
		CSX::Cvar::SaveCvar("COLORS", "CLR_BOTSnapline", BOTSnapline);

		CSX::Cvar::SaveCvar("COLORS", "CLR_RadarEnemy", RadarEnemy);
		CSX::Cvar::SaveCvar("COLORS", "CLR_RadarTeam", RadarTeam);
		CSX::Cvar::SaveCvar("COLORS", "CLR_RadarBOT", RadarBOT);


		CSX::Cvar::SaveCvar("COLORS", "CLR_Crosshair", Crosshair);

		CSX::Cvar::SaveCvar("COLORS", "CLR_LootBULLET", BULLET);
		CSX::Cvar::SaveCvar("COLORS", "CLR_LootSHIELD", SHIELD);
		CSX::Cvar::SaveCvar("COLORS", "CLR_LootSHIELDXP", SHIELDXP);
		CSX::Cvar::SaveCvar("COLORS", "CLR_LootWEAPON", WEAPON);
		CSX::Cvar::SaveCvar("COLORS", "CLR_LootWEAPONPARTS", WEAPONPARTS);
		CSX::Cvar::SaveCvar("COLORS", "CLR_LootCARIRIDGE", CARIRIDGE);

		CSX::Cvar::SaveCvar("COLORS", "CLR_InventoryAirDrop", AirDrop);
		CSX::Cvar::SaveCvar("COLORS", "CLR_InventoryDeadBox", DeadBox);
		CSX::Cvar::SaveCvar("COLORS", "CLR_InventoryElectricBox", ElectricBox);

#pragma endregion
#pragma region Setting
		CSX::Cvar::SaveCvar(xorstr_("Setting"), xorstr_("vsync"), Settings::Setting::vsync);
		CSX::Cvar::SaveCvar(xorstr_("Setting"), xorstr_("fps"), Settings::Setting::fps);
		CSX::Cvar::SaveCvar(xorstr_("Menu"), xorstr_("chroma"), Settings::Menu::chroma_menu);
		CSX::Cvar::SaveCvar(xorstr_("Menu"), xorstr_("drawdots"), Settings::Menu::drawdots);
		CSX::Cvar::SaveCvar(xorstr_("Menu"), xorstr_("watermark"), Settings::Menu::watermark);
#pragma endregion
	}
}