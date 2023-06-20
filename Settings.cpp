#include "Includes.h"
namespace apiinfo
{
	std::string user = "";
	std::string _expire = "";
	std::string NumOnlineUsers = "";

}
namespace Share
{
	float AimFov = 0;
	float distance = 0;
}
namespace Settings
{
	namespace Aimbot
	{
		bool enable = false;
		int mode = 0;
		bool prediction = false;
		float humanspeed = 10;
		float humanscale = 1;
		bool drawfov = true;
		bool drawhitbox = true;
		int hitboxtype = 0;
		namespace AssualtRifle
		{
			bool enable = false;
			int aimkey = 1;
			bool autolock = false;
			float fov = 0;
			float smooth = 0;
			bool legitaim = false;
			int hitbox = 0;
			int distance = 0;
		}
		namespace Submachinegun
		{
			bool enable = false;
			int aimkey = 1;
			bool autolock = false;
			float fov = 0;
			float smooth = 0;
			bool legitaim = false;
			int hitbox = 0;
			int distance = 0;
		}
		namespace Shotgun
		{
			bool enable = false;
			int aimkey = 1;
			bool autolock = false;
			float fov = 0;
			float smooth = 0;
			bool legitaim = false;
			int hitbox = 0;
			int distance = 0;
		}
		namespace Sniper
		{
			bool enable = false;
			int aimkey = 1;
			bool autolock = false;
			float fov = 0;
			float smooth = 0;
			bool legitaim = false;
			int hitbox = 0;
			int distance = 0;
		}
	}
	namespace ESP
	{

		namespace Players
		{
			namespace Team
			{
				bool directionLine = false;
				bool prediction = false;
				bool name = false;
				bool boxes = false;
				bool distance = false;
				bool snaplines = false;
				bool health = false;
				bool filledbox = false;
				bool skeleton = false;
				bool offscreen = false;
				bool weapon = false;
				bool info = false;

			}
			namespace Enemy
			{
				bool directionLine = false;
				bool prediction = false;
				bool name = false;
				bool boxes = false;
				bool distance = false;
				bool snaplines = false;
				bool health = false;
				bool filledbox = false;
				bool skeleton = false;
				bool offscreen = false;
				bool weapon = false;
				bool info = false;

			}
		}
		namespace Vehicle
		{
			bool vehicleName = true;
			bool vehicleBox = true;
			bool vehicleDirectionLine = false;

		}
		namespace Loot
		{
			bool WEAPON = false;
			bool WEAPONPARTS = false;
			bool SHIELD = false;
			bool SHIELDXP = false;
			bool BULLET = false;
			bool CARIRIDGE = false;

		}
		namespace Inventory
		{
			bool Deadbox = false;
			bool AirDrop = false;
			bool ElectricBox = false;
		}
		namespace Options
		{
			bool colorbyteamid = false;
			int boxtype = 0;
			int healthbartype = 0;
			int DirectionLineSize = 500;
			int offscreen_range = 100;
			int max_distance_offscreen = 400;
			int playersdis = 400;
			bool esp_Outline = false;
			int vehiclesdis = 600;
			int VehicleDirectionLineSize = 500;
			int predictiontype = 0;
			int PlayerFontSize = 18;

			namespace Loot
			{
				int fontsize = 18;
			}
			namespace WEAPONPARTS
			{
				bool lv1 = false;
				bool lv2 = false;
				bool lv3 = false;
				bool lv4 = false;
				bool lv5 = false;
				bool lv6 = false;

			}
			namespace SHIELD
			{
				bool lv1 = false;
				bool lv2 = false;
				bool lv3 = false;
				bool lv4 = false;
				bool lv5 = false;
				bool lv6 = false;

			}
		}
	}
	namespace Micro
	{
		bool micro = false;
		FVector2D microaxis = {};
	}
	namespace Radar
	{
		bool enable = false;
		bool teamRadar = false;
		bool enemyRadar = false;

		int radartype = 0;
		int distance_Radar = 600;

	}
	namespace Crosshair
	{
		bool c_enable = false;
		int crosshair = 6;
		float size = 0;
		float stroke = 0;
	}
	namespace Screen
	{
		bool PlayerAiming = false;
		bool TotalPlayers = false;

	}

	namespace Color
	{
		float rainbow = 0.f;
		namespace Players
		{
			namespace Team
			{
				float box[3] = { 0.f, 0.f, 1.f };
				float snapline[3] = { 0.f, 0.f, 1.f };
				float skeleton[3] = { 0.f, 0.f, 1.f };
				float directionLine[3] = { 0.f, 0.f, 1.f };

			}
			namespace Enemy
			{
				float box[3] = { 1.f, 1.f, 0.f };
				float snapline[3] = { 1.f, 1.f, 0.f };
				float skeleton[3] = { 1.f, 1.f, 0.f };
				float directionLine[3] = { 1.f, 1.f, 0.f };
			}
			namespace Bot
			{
				float box[3] = { 1.f, 1.f, 1.f };
				float snapline[3] = { 1.f, 1.f, 1.f };
				float skeleton[3] = { 1.f, 1.f, 1.f };
				float directionLine[3] = { 1.f, 1.f, 1.f };
			}
		}
		namespace Radar
		{
			float Enemy[3] = { 1.f, 1.f, 0.f };
			float Team[3] = { 0.f, 0.f, 1.f };
			float BOT[3] = { 1.f, 1.f, 1.f };

		}
		namespace Crosshair
		{
			float crosshair[3] = { 0.f, 1.f, 0.f };
		}
		namespace Loot
		{
			float WEAPON[3] = { 1.f, 0.f, 0.f };
			float WEAPONPARTS[3] = { 1.f, 0.f, 0.f };
			float SHIELD[3] = { 1.f, .64f, 0.f };
			float SHIELDXP[3] = { 1.f, .64f, 0.f };
			float BULLET[3] = { 1.f, .64f, 0.f };
			float CARIRIDGE[3] = { 1.f, 1.f, 1.f };
			float XPWEAPON[3] = { 1.0f, 0.84f, 0.0f };

		}
		namespace Inventory
		{
			float DeadBox[3] = { 1.f, 0.f, 0.f };
			float AirDrop[3] = { 0.f, 1.f, 0.f };
			float ElectricBox[3] = { 1.f, .64f, 0.f };

		}
		namespace Menu
		{
			float color[3] = { 1.f, 0.f, 0.f };
		}
		namespace Vehicle
		{
			float Name[3] = { 1.f, .64, 0.f };
			float Box[3] = { 1.f, .64, 0.f };
			float DirectionLine[3] = { 1.f, .64, 0.f };
			float velocity[3] = { 1.f, 0, 0.f };
		}
	}
	namespace Setting
	{
		bool vsync = true;
		int fps = 1;
	}
	namespace Menu
	{
		bool chroma_menu = false;
		bool drawdots = false;
		bool watermark = true;

	}
	namespace UI
	{
		int tab_aimbot = 0;
		int player_esp = 0;
		int vehicle_esp = 0;
		int items_esp = 0;
		int other_esp = 0;
		int colors_players = 0;
		int colors_vehicle = 0;
		int colors_items = 0;
		int colors_radar = 0;
	}

}