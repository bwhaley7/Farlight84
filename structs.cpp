#include "Includes.h"
FMinimalViewInfo CameraCacheEntry = FMinimalViewInfo();
A_Players MyLocalPlayer = {};
A_Vehicle MyLocalVehicle = {};

std::vector<A_Pickup> EntityPickups = {};
std::vector<A_Vehicle> EntityVehicle = {};
std::vector<A_Players> EntityList = {};
std::vector<uint64_t> TempEntityList = {};
std::vector<uint64_t> TempEntityList2 = {};

int TotalEnemy = 0, TotalBots = 0;

