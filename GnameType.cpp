#include "Includes.h"

namespace GnameType
{
	bool isPlayer(std::string type)
	{

		if (type == xorstr_("BP_SolarLobbyCharacter_C") || type == xorstr_("BP_Character_BattleRoyaleMap01_C")
			|| type == xorstr_("BP_Character_BattleRoyale_C") || type == xorstr_("BP_Character_TrainingMode_C")
			|| type == xorstr_("BP_Character_TeamDeathMatch_C") || type == xorstr_("BP_Character_HunterXHunterTeamVer2_C")
			|| type == xorstr_("BP_Character_Solo_C") || type == xorstr_("BP_Character_Bounty_C")
			)
			return true;
		else
			return false;
		return false;
	}
	bool IsVehicle(std::string type)
	{
		if (type == xorstr_("BP_VH_Hover_WL04_C") || type == xorstr_("BP_VH_Hover_9A03_C")
			|| type == xorstr_("BP_VH_Hover_Soroll02_C") || type == xorstr_("BP_VH_Hover_Soroll03_C")
			|| type == xorstr_("BP_VH_Hover_Soroll04_C") || type == xorstr_("BP_VH_TransTL_WL07_C")
			|| type == xorstr_("BP_SolarVH_Tire_9A04_new_C") || type == xorstr_("BP_SolarVH_Tire_WL01_new_C")
			|| type == xorstr_("VH_Leg_9A02_New_C") || type == xorstr_("BP_VH_Leg_WL03_New_Procedural_C")
			|| type == xorstr_("BP_VH_Leg_WL06_New_C")
			)
			return true;
		else
			return false;
		return false;
	}

	std::string VehicleType(std::string type)
	{
		if (type == xorstr_("BP_VH_Hover_WL04_C")) return xorstr_("Wasteland HoverCraft");
		else if (type == xorstr_("BP_VH_Hover_9A03_C")) return xorstr_("GunBoat");
		else if (type == xorstr_("BP_VH_Hover_Soroll02_C")) return xorstr_("Hovercar");
		else if (type == xorstr_("BP_VH_Hover_Soroll04_C")) return xorstr_("Air Beast");
		else if (type == xorstr_("BP_VH_Hover_Soroll03_C")) return xorstr_("Hoverbike");
		else if (type == xorstr_("BP_VH_TransTL_WL07_C")) return xorstr_("Blazing Infantry");
		else if (type == xorstr_("BP_SolarVH_Tire_9A04_new_C")) return xorstr_("Mobile Turret");
		else if (type == xorstr_("BP_SolarVH_Tire_WL01_new_C")) return xorstr_("Flamethrower");
		else if (type == xorstr_("VH_Leg_9A02_New_C")) return xorstr_("Single-Poilt Mecha");
		else if (type == xorstr_("BP_VH_Leg_WL03_New_Procedural_C")) return xorstr_("4-Legged-Lizard");
		else if (type == xorstr_("BP_VH_Leg_WL06_New_C")) return xorstr_("War Spider");
		else return xorstr_("Unknown Vehicle!");
	}

	bool IsDeadBox(std::string Type)
	{
		if (Type == xorstr_("BP_DI_DeathBoxA_TreasureBox_C"))
			return true;
		else
			return false;
		return false;
	}
	bool IsDropBox(std::string Type)
	{
		if (Type == xorstr_("BP_SI_AirdropBox_TreasureBox_Hoarder_C") || Type == xorstr_("BP_SI_AirdropBox_Signal_C"))
			return true;
		else
			return false;
		return false;
	}
	bool IsPickup(std::string Type)
	{
		if (Type == xorstr_("SolarItemActor") || Type == xorstr_("SolarGroundPreviewActor"))
			return true;
		else
			return false;
		return false;
	}

	bool IsElectricbox(std::string Type)
	{
		if (Type == xorstr_("BP_SI_ElectricboxB_C") || Type == xorstr_("BP_SI_ElectricboxC_C"))
			return true;
		else
			return false;
		return false;
	}
	std::map<std::string, ITEM_NAME> g_ItemHash = {};
	void AddItemName(std::string id, char* pCN, char* pEN, char* pTexture)
	{
		ITEM_NAME in;
		lstrcpyA(in.szCN, pCN);
		lstrcpyA(in.szEN, pEN);
		lstrcpyA(in.szTexture, pTexture);
		g_ItemHash[id] = in;
	}

	void InitItemName()
	{
		g_ItemHash.clear();
		//AddItemName(xorstr_("BP_Rifle_M762_Wrapper_C"), "", "M762", "Rifle_M762_Wrapper");


	}

}