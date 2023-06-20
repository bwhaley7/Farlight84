#pragma once
namespace apiinfo
{
	extern std::string user;
	extern 	std::string _expire;
	extern 	std::string NumOnlineUsers;
}
namespace Share
{
	extern float AimFov;
	extern float distance;

}

namespace Settings
{
	namespace Aimbot
	{
		extern bool enable;
		extern int mode;
		extern bool prediction;
		extern float humanspeed;
		extern float humanscale;
		extern bool drawfov;
		extern bool drawhitbox;
		extern int hitboxtype;

		namespace AssualtRifle
		{
			extern  bool enable;
			extern 	int aimkey;
			extern	bool autolock;
			extern  float fov;
			extern 	float smooth;
			extern  bool legitaim;
			extern 	int hitbox;
			extern 	int distance;
		}
		namespace Submachinegun
		{
			extern  bool enable;
			extern 	int aimkey;
			extern	bool autolock;
			extern  float fov;
			extern 	float smooth;
			extern  bool legitaim;
			extern 	int hitbox;
			extern 	int distance;
		}
		namespace Shotgun
		{
			extern  bool enable;
			extern 	int aimkey;
			extern	bool autolock;
			extern  float fov;
			extern 	float smooth;
			extern  bool legitaim;
			extern 	int hitbox;
			extern 	int distance;
		}
		namespace Sniper
		{
			extern  bool enable;
			extern 	int aimkey;
			extern	bool autolock;
			extern  float fov;
			extern 	float smooth;
			extern  bool legitaim;
			extern 	int hitbox;
			extern 	int distance;
		}

	}
	namespace ESP
	{
		namespace Players
		{
			namespace Team
			{
				extern bool directionLine;
				extern bool prediction;
				extern bool name;
				extern bool boxes;
				extern bool distance;
				extern bool snaplines;
				extern bool health;
				extern bool filledbox;
				extern bool skeleton;
				extern bool offscreen;
				extern bool weapon;
				extern bool info;


			}
			namespace Enemy
			{
				extern bool directionLine;
				extern bool prediction;
				extern bool name;
				extern bool boxes;
				extern bool distance;
				extern bool snaplines;
				extern bool health;
				extern bool filledbox;
				extern bool skeleton;
				extern bool offscreen;
				extern bool weapon;
				extern bool info;

			}
		}
		namespace Vehicle
		{
			extern bool vehicleName;
			extern bool vehicleBox;
			extern bool vehicleDirectionLine;

		}
		namespace Loot
		{
			extern bool WEAPON;
			extern bool WEAPONPARTS;
			extern bool SHIELD;
			extern bool SHIELDXP;
			extern bool BULLET;
			extern bool CARIRIDGE;

		}
		namespace Inventory
		{
			extern bool Deadbox;
			extern bool AirDrop;
			extern bool ElectricBox;

		}
		namespace Options
		{
			extern bool colorbyteamid;
			extern int boxtype;
			extern int healthbartype;
			extern int DirectionLineSize;
			extern int offscreen_range;
			extern int max_distance_offscreen;
			extern int playersdis;
			extern bool esp_Outline;
			extern int vehiclesdis;
			extern int VehicleDirectionLineSize;
			extern int predictiontype;
			extern int PlayerFontSize;
			namespace Loot
			{
				extern int fontsize;
			}
			namespace WEAPONPARTS
			{
				extern bool lv1;
				extern bool lv2;
				extern bool lv3;
				extern bool lv4;
				extern bool lv5;
				extern bool lv6;
			}
			namespace SHIELD
			{
				extern bool lv1;
				extern bool lv2;
				extern bool lv3;
				extern bool lv4;
				extern bool lv5;
				extern bool lv6;
			}
		}
	}
	namespace Radar
	{
		extern bool enable;
		extern bool teamRadar;
		extern bool enemyRadar;

		extern int radartype;
		extern int distance_Radar;

	}
	namespace Micro
	{
		extern bool micro;
		extern FVector2D microaxis;
	}
	namespace Crosshair
	{
		extern bool c_enable;
		extern int crosshair;
		extern float size;
		extern float stroke;
	}
	namespace Screen
	{
		extern bool PlayerAiming;
		extern bool TotalPlayers;

	}
	namespace Color
	{
		extern float rainbow;
		namespace Players
		{

			namespace Team
			{
				extern float box[3];
				extern float snapline[3];
				extern float skeleton[3];
				extern float directionLine[3];

			}
			namespace Enemy
			{
				extern float box[3];
				extern float snapline[3];
				extern float skeleton[3];
				extern float directionLine[3];

			}


			namespace Bot
			{
				extern float box[3];
				extern float snapline[3];
				extern float skeleton[3];
				extern float directionLine[3];
			}
		}
		namespace Vehicle
		{
			extern float Name[3];
			extern float Box[3];
			extern float DirectionLine[3];
			extern float velocity[3];
		}
		namespace Radar
		{
			extern float Enemy[3];
			extern float Team[3];
			extern float BOT[3];

		}
		namespace Crosshair
		{
			extern float crosshair[3];

		}
		namespace Loot
		{
			extern float WEAPON[3];
			extern float WEAPONPARTS[3];
			extern float SHIELD[3];
			extern float SHIELDXP[3];
			extern float BULLET[3];
			extern float CARIRIDGE[3];
			extern float XPWEAPON[3];


		}
		namespace Inventory
		{
			extern float DeadBox[3];
			extern float AirDrop[3];
			extern float ElectricBox[3];

		}
		namespace Menu
		{
			extern float color[3];
		}
	}
	namespace Setting
	{
		extern bool vsync;
		extern int fps;
	}
	namespace Menu
	{
		extern bool chroma_menu;
		extern bool drawdots;
		extern bool watermark;

	}
	namespace UI
	{
		extern int tab_aimbot;
		extern int player_esp;
		extern int vehicle_esp;
		extern int items_esp;
		extern int other_esp;
		extern int colors_players;
		extern int colors_vehicle;
		extern int colors_items;
		extern int colors_radar;

	}
}

