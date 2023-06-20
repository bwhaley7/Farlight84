#pragma once

namespace GnameType
{

	extern std::map<std::string, ITEM_NAME> g_ItemHash;

	bool isPlayer(std::string type);
	bool IsVehicle(std::string type);
	std::string VehicleType(std::string type);
	bool IsDeadBox(std::string Type);
	bool IsDropBox(std::string Type);
	bool IsPickup(std::string Type);
	bool IsElectricbox(std::string Type);

	void AddItemName(std::string id, char* pCN, char* pEN, char* pTexture);
	void InitItemName();

}



