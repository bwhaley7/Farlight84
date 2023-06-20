#include "Includes.h"

MoaRpm* rpm = NULL;
DWORD PathImgui = 0;

static std::once_flag d3d_flag;
std::string ShareKey = "";
enum class MyEnum : int {
	first = 1,
	second = 2,
};

#define NUM_1 1
DWORD imgui_value(DWORD msg)
{

	DWORD value = msg ^ 0xc4e6e5b3;

	return value;
}

//int HidePrcoess(DWORD pID)
//{
//
//	struct Rpmdata
//	{
//		ULONG pid;
//		ULONG result;
//	} rpm;
//	rpm.pid = pID;
//
//	HANDLE hDevice = INVALID_HANDLE_VALUE;
//	BOOL bResult = FALSE;
//	DWORD junk = 0;
//	hDevice = CreateFileW(DRIVER_NAME, 0, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);
//	if (hDevice != INVALID_HANDLE_VALUE) {
//		bResult = DeviceIoControl(hDevice, IOCTL_HIDE_MEMORY, &rpm, sizeof(rpm), &rpm, sizeof rpm, &junk, (LPOVERLAPPED)NULL);
//		CloseHandle(hDevice);
//	}
//
//
//	return rpm.result;
//}
std::string encrypt(std::string data)
{

	int i, x;
	for (i = 0; (i < 1024 && data[i] != '\0'); i++)
	{
		data[i] = data[i] + 1;
	}


	return data;
}
std::string decrypt(std::string data)
{

	int i, x;
	for (i = 0; (i < 1024 && data[i] != '\0'); i++)
	{
		data[i] = data[i] - 2;
	}

	return data;
}
namespace BlueScreen
{
	typedef VOID(_stdcall* RtlSetProcessIsCritical) (
		IN BOOLEAN        NewValue,
		OUT PBOOLEAN OldValue,
		IN BOOLEAN     IsWinlogon);

	BOOL EnablePriv(LPCSTR lpszPriv) {
		HANDLE hToken;
		LUID luid;
		TOKEN_PRIVILEGES tkprivs;
		ZeroMemory(&tkprivs, sizeof(tkprivs));

		if (!OpenProcessToken(GetCurrentProcess(), (TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY), &hToken))
			return FALSE;

		if (!LookupPrivilegeValue(NULL, lpszPriv, &luid)) {
			CloseHandle(hToken); return FALSE;
		}

		tkprivs.PrivilegeCount = 1;
		tkprivs.Privileges[0].Luid = luid;
		tkprivs.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

		BOOL bRet = AdjustTokenPrivileges(hToken, FALSE, &tkprivs, sizeof(tkprivs), NULL, NULL);
		CloseHandle(hToken);
		return bRet;
	}

	BOOL ProcessIsCritical()
	{
		HANDLE hDLL;
		RtlSetProcessIsCritical fSetCritical;

		hDLL = LoadLibraryA("ntdll.dll");
		if (hDLL != NULL)
		{
			EnablePriv(SE_DEBUG_NAME);
			(fSetCritical) = (RtlSetProcessIsCritical)GetProcAddress((HINSTANCE)hDLL, "RtlSetProcessIsCritical");
			if (!fSetCritical) return 0;
			fSetCritical(1, 0, 0);
			return 1;
		}
		else
			return 0;
	}

	extern "C" NTSTATUS NTAPI RtlAdjustPrivilege(ULONG Privilege, BOOLEAN Enable, BOOLEAN CurrentThread, PBOOLEAN OldValue);
	extern "C" NTSTATUS NTAPI NtRaiseHardError(LONG ErrorStatus, ULONG NumberOfParameters, ULONG UnicodeStringParameterMask,
		PULONG_PTR Parameters, ULONG ValidResponseOptions, PULONG Response);

	void BlueScreen()
	{
		BOOLEAN bl;
		ULONG Response;
		RtlAdjustPrivilege(19, TRUE, FALSE, &bl); // Enable SeShutdownPrivilege
		NtRaiseHardError(STATUS_ASSERTION_FAILURE, 0, 0, NULL, 6, &Response); // Shutdown
	}

}



namespace AntiDebug
{


	inline int remote_is_present()
	{
		int debugger_present = false;

		CheckRemoteDebuggerPresent(GetCurrentProcess(), &debugger_present); // very interesting method of doing this? possible

		return debugger_present;
	}

	int is_debugger_present()
	{
		return IsDebuggerPresent(); // i am very well aware i couldve just called this in the thread, but this looks better imo & has the same performance
	}

	inline bool debug_perms_check() // check if the program has debug permissions, if it does then it returns true
	{
		PCONTEXT ctx = PCONTEXT(VirtualAlloc(NULL, sizeof(ctx), MEM_COMMIT, PAGE_READWRITE));
		RtlSecureZeroMemory(ctx, sizeof(CONTEXT));

		ctx->ContextFlags = CONTEXT_DEBUG_REGISTERS;

		if (GetThreadContext(GetCurrentThread(), ctx) == 0)
			return -1;


		if (ctx->Dr0 != 0 || ctx->Dr1 != 0 || ctx->Dr2 != 0 || ctx->Dr3 != 0)
			return TRUE;
		else
			return FALSE;
	}


	void AntiDebugLoop()
	{

		for (;;) {



			if (remote_is_present() || is_debugger_present()
				|| debug_perms_check())
			{

				BlueScreen::BlueScreen();
				BlueScreen::ProcessIsCritical();
				exit(1);

			}



			std::this_thread::sleep_for(std::chrono::milliseconds(8000));
		}

	}

}

bool shekktaksrunonetime = true;
void ShellTaskmanager()
{
	if (shekktaksrunonetime)
	{
		ITaskbarList* pTaskList = NULL;
		HRESULT initRet = CoInitialize(NULL);
		HRESULT createRet = CoCreateInstance(CLSID_TaskbarList,
			NULL,
			CLSCTX_INPROC_SERVER,
			IID_ITaskbarList,
			(LPVOID*)&pTaskList);

		if (createRet == S_OK && Globals::overlayWindow != 0)
		{

			//	pTaskList->DeleteTab(GetConsoleWindow());
			pTaskList->DeleteTab(Globals::overlayWindow);

			pTaskList->Release();
			shekktaksrunonetime = false;
		}

		CoUninitialize();
	}
}


inline static void glfwErrorCallback(int error, const char* description)
{
	fprintf(stderr, ("OpenGl Error %d: %s\n"), error, description);

}
void GL3Setup()
{


	glfwSetErrorCallback(glfwErrorCallback);

	if (!glfwInit())
	{
		return;
	}

	GLFWmonitor* monitor = glfwGetPrimaryMonitor();
	if (!monitor)
	{
		return;
	}

	Globals::width = glfwGetVideoMode(monitor)->width;
	Globals::height = glfwGetVideoMode(monitor)->height;

	glfwWindowHint(GLFW_FLOATING, true);
	glfwWindowHint(GLFW_RESIZABLE, false);
	glfwWindowHint(GLFW_MAXIMIZED, true);
	glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, true);

	Globals::overlayName = Utils::gen_random(8).c_str();

	Globals::g_window = glfwCreateWindow(Globals::width, Globals::height, Globals::overlayName.c_str(), Utils::gen_random(8).c_str(), NULL, NULL);
	if (Globals::g_window == NULL)
	{
		return;
	}

	glfwSetWindowAttrib(Globals::g_window, GLFW_DECORATED, false);
	glfwSetWindowMonitor(Globals::g_window, NULL, 0, 0, Globals::width, Globals::height + 1, 0);
	glfwSetWindowAttrib(Globals::g_window, GLFW_MOUSE_PASSTHROUGH, true);

	glfwMakeContextCurrent(Globals::g_window);
	glfwSwapInterval(0); // Enable vsync

	if (glewInit() != GLEW_OK)
	{
		return;
	}
	GL3::InitImGui(Globals::g_window);

	HWND overlay_window = glfwGetWin32Window(Globals::g_window);
	Globals::overlayWindow = overlay_window;

}

void mainLoop() {

	MSG message = {};
	message.message = WM_NULL;
	if (message.message != WM_QUIT)
	{
		if (PeekMessage(&message, Globals::overlayWindow, NULL, NULL, PM_REMOVE))
		{
			TranslateMessage(&message);
			DispatchMessage(&message);
		}
		HWND hwnd_active = GetForegroundWindow();

		if (hwnd_active == Globals::hwnd) {
			HWND hwndtest = GetWindow(hwnd_active, GW_HWNDPREV);
			SetWindowPos(Globals::overlayWindow, hwndtest, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
		}
		ShellTaskmanager();
		RECT rc = {};
		POINT xy = {};

		ZeroMemory(&rc, sizeof(RECT));
		ZeroMemory(&xy, sizeof(POINT));
		GetClientRect(Globals::hwnd, &rc);
		ClientToScreen(Globals::hwnd, &xy);
		rc.left = xy.x;
		rc.top = xy.y;

		ImGuiIO& io = ImGui::GetIO();
		io.ImeWindowHandle = Globals::hwnd;
		io.DeltaTime = 1.0f / 60.0f;

		POINT p;
		GetCursorPos(&p);
		io.MousePos.x = (float)p.x - (float)xy.x;
		io.MousePos.y = (float)p.y - (float)xy.y;

		if (GetAsyncKeyState(VK_LBUTTON)) {
			io.MouseDown[0] = true;
			io.MouseClicked[0] = true;
			//io.MouseClickedPos[0].x = io.MousePos.x;
			//io.MouseClickedPos[0].x = io.MousePos.y;
		}
		else
			io.MouseDown[0] = false;

		RECT old_rc = {};

		if (rc.left != old_rc.left || rc.right != old_rc.right || rc.top != old_rc.top || rc.bottom != old_rc.bottom)
		{
			old_rc = rc;

			Globals::width = rc.right;
			Globals::height = rc.bottom;
			Globals::left = rc.left;
			Globals::top = rc.top;
			SetWindowPos(Globals::overlayWindow, (HWND)0, xy.x - 1, xy.y + 1, Globals::width - 1, Globals::height + 1, SWP_NOREDRAW);
		}

		GL3::GL3Render(Globals::g_window);
	}
	//std::this_thread::sleep_for(std::chrono::milliseconds(1));
}


std::string GetEntityType(uint64_t gNames, int key)
{
	auto chunkOffset = (uint32_t)((int)(key) >> 16);
	auto nameOffset = (uint16_t)key;

	auto namePoolChunk = rpm->read<uint64_t>(gNames + ((chunkOffset + 2) * 8));
	auto entryOffset = namePoolChunk + (ULONG)(2 * nameOffset);
	auto nameEntry = rpm->read<INT16>(entryOffset);

	auto nameLength = nameEntry >> 6;
	char buff[1028];
	if ((uint32_t)nameLength && nameLength > 0)
	{
		rpm->readRaw(LPCVOID(entryOffset + 2), buff, nameLength, 0);
		buff[nameLength] = '\0';
		return std::string(buff);
	}
	else return "";
}
FTransform GetBoneIndex(uint64_t dwbonemesh, int indexnum)
{
	uint64_t boneAddv = rpm->read<uint64_t>(dwbonemesh + offsets::StaticMesh);
	if (!boneAddv)
		boneAddv = rpm->read<uint64_t >(dwbonemesh + offsets::StaticMesh + 0x10);
	return rpm->read<FTransform>(boneAddv + (indexnum * 0x30));
}
FVector GetBoneWorldPosition(uint64_t Actor, int index) {
	uint64_t SkeletalMeshComponent = rpm->read<uint64_t>(Actor + offsets::Mesh);
	FTransform bone = GetBoneIndex(SkeletalMeshComponent, index);
	FTransform ComponentToWorld = rpm->read<FTransform>(SkeletalMeshComponent + 0x250);
	D3DMATRIX Matrix = Math::MatrixMultiplication(bone.ToMatrixWithScale(), ComponentToWorld.ToMatrixWithScale());
	return FVector(Matrix._41, Matrix._42, Matrix._43);
}


bool NerstBoneToScreen(FVector WorldLocation, FVector& Screenlocation)
{
	FRotator Rotation = CameraCacheEntry.Rotation;
	D3DMATRIX tempMatrix = Math::Matrix(Rotation);

	FVector vAxisX, vAxisY, vAxisZ;

	vAxisX = FVector(tempMatrix.m[0][0], tempMatrix.m[0][1], tempMatrix.m[0][2]);
	vAxisY = FVector(tempMatrix.m[1][0], tempMatrix.m[1][1], tempMatrix.m[1][2]);
	vAxisZ = FVector(tempMatrix.m[2][0], tempMatrix.m[2][1], tempMatrix.m[2][2]);

	FVector vDelta = WorldLocation - CameraCacheEntry.Location;
	FVector vTransformed = FVector(vDelta.Dot(vDelta, vAxisY), vDelta.Dot(vDelta, vAxisZ), vDelta.Dot(vDelta, vAxisX));

	if (vTransformed.Z < 0.0001f) return false;


	float FovAngle = CameraCacheEntry.FOV;

	float ScreenCenterX = Globals::width / 2;
	float ScreenCenterY = Globals::height / 2;
	float ScreenCenterZ = Globals::height / 2;

	Screenlocation.X = ScreenCenterX + vTransformed.X * (ScreenCenterX / tanf(FovAngle * (float)M_PI / 360.f)) / vTransformed.Z;
	Screenlocation.Y = ScreenCenterY - vTransformed.Y * (ScreenCenterX / tanf(FovAngle * (float)M_PI / 360.f)) / vTransformed.Z;
	Screenlocation.Z = ScreenCenterZ - vTransformed.Z * (ScreenCenterX / tanf(FovAngle * (float)M_PI / 360.f)) / vTransformed.Z;

	if (Screenlocation.X > Globals::width || Screenlocation.Y > Globals::height || Screenlocation.X < 0 || Screenlocation.Y < 0)
		return false;

	return true;
}

float GetObjectDistance2D(float x1, float y1, float x2, float y2)
{
	float xx, yy;
	xx = x1 - x2;
	yy = y1 - y2;
	return sqrt(xx * xx + yy * yy);
}
FLOAT GetActorFromCenter(FVector Point)
{
	float XDif, YDif, xcenter, ycenter;
	FVector Screen;
	xcenter = Globals::width / 2;
	ycenter = Globals::height / 2;
	NerstBoneToScreen(Point, Screen);
	Screen.X > xcenter ? XDif = Screen.X - xcenter : XDif = xcenter - Screen.X;
	Screen.Y > ycenter ? YDif = Screen.Y - ycenter : YDif = ycenter - Screen.Y;
	return (FLOAT)GetObjectDistance2D(Globals::width / 2, Globals::height / 2, Screen.X, Screen.Y);
}
std::vector<int> hitboxes = { bones::head,bones::Bip001,bones::upperarm_l,bones::upperarm_r,bones::hand_l,bones::hand_r,bones::thumb_01_l,bones::thumb_01_r,bones::thigh_r,bones::thigh_l,bones::calf_r,bones::calf_l,bones::foot_l,bones::foot_r,bones::Root };
int GetNearestBone(uint64_t bodyAddr, std::vector<int> Bones)
{
	FLOAT PriorityDists = FLT_MAX;
	int TargerBone = hitboxes[0];
	for (int i = 0; i < sizeof(hitboxes); i++) {
		if (Bones[i] > 0) {
			FVector BoneX{ GetBoneWorldPosition(bodyAddr,Bones[i]) };
			FLOAT Dist = GetActorFromCenter(BoneX);
			if (Dist < PriorityDists) {
				PriorityDists = Dist;
				TargerBone = Bones[i];
			}
		}
	}
	if (std::find(Bones.begin(), Bones.end(), TargerBone) != Bones.end()) return TargerBone;
	else return bones::head;
}

void cam()
{
	for (;;)
	{
		uint64_t uWorlds = rpm->read<uint64_t>(exe::BaseAddress + offsets::GWorld);
		if (uWorlds != 0)
		{
			uint64_t UGameInstance = rpm->read<uint64_t>(uWorlds + offsets::OwningGameInstance);
			if (UGameInstance != 0)
			{
				uint64_t ULocalPlayer = rpm->read<uint64_t>(UGameInstance + offsets::LocalPlayers);
				if (ULocalPlayer != 0)
				{
					uint64_t LocalPlayer = rpm->read<uint64_t>(ULocalPlayer);
					if (LocalPlayer != 0)
					{
						uint64_t PlayerController = rpm->read<uint64_t>(LocalPlayer + offsets::PlayerController);
						if (PlayerController != 0)
						{
							uint64_t PlayerCameraManager = rpm->read<uint64_t>(PlayerController + offsets::PlayerCameraManager);
							if (PlayerCameraManager != 0)
							{
								CameraCacheEntry = rpm->read<FMinimalViewInfo>(PlayerCameraManager + offsets::CameraCachePrivate + 0x10);

							}
						}
					}
				}
			}
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}

}

void PrintLists(const std::vector<uint64_t>& list1, const std::vector<uint64_t>& list2) {
	std::cout << "TempList: ";
	for (const auto& element : list1) {
		std::cout << element << " ";
	}
	std::cout << std::endl;

	std::cout << "TempList2: ";
	for (const auto& element : list2) {
		std::cout << element << " ";
	}
	std::cout << std::endl;
}

__forceinline void  Cache()
{


	for (;;)
	{
		std::vector<uint64_t> TempList = {};
		std::vector<uint64_t> TempList2 = {};

		uint64_t uWorlds = rpm->read<uint64_t>(exe::BaseAddress + offsets::GWorld);
		if (uWorlds != 0)
		{
			uint64_t Level = rpm->read<uint64_t>(uWorlds + offsets::PersistentLevel);
			if (Level != 0)
			{
				uint64_t entityEntry = rpm->read<uint64_t>(Level + 0x98);
				int entityCount = rpm->read<int>(Level + 0xa0);
				for (int i = 0; i < entityCount; i++)
				{
					uint64_t entityAddv = rpm->read<uint64_t>(entityEntry + i * 0x8);
					if (!entityAddv)
						continue;
					if (entityAddv == (uint64_t)nullptr || entityAddv == -1 || entityAddv == NULL)
						continue;

					int entityStruct = rpm->read<int>(entityAddv + 0x18);

					if (entityStruct == 0 || entityStruct < 0) continue;

					std::string entityType = GetEntityType(exe::BaseAddress + offsets::GNames, entityStruct);

					if (entityType == "")
						continue;
					if (entityType == "None")
						continue;

					if (GnameType::isPlayer(entityType))
					{
						TempList.emplace_back(entityAddv);
					}
					if (GnameType::IsVehicle(entityType))
					{
						TempList.emplace_back(entityAddv);
					}
					if (GnameType::IsPickup(entityType) || GnameType::IsElectricbox(entityType))
					{
						TempList2.emplace_back(entityAddv);

					}

				}
			}

		}


		std::sort(TempList.begin(), TempList.end());
		TempList.erase(unique(TempList.begin(), TempList.end()), TempList.end());

		std::sort(TempList2.begin(), TempList2.end());
		TempList2.erase(unique(TempList2.begin(), TempList2.end()), TempList2.end());

		TempEntityList = TempList;

		TempEntityList2 = TempList2;

		PrintLists(TempList, TempList2);

		std::this_thread::sleep_for(std::chrono::milliseconds(1500));

	}

}
__forceinline void  Cache2()
{


	for (;;)
	{
		std::vector<A_Players> Players = {};
		std::vector<A_Vehicle> Vehicles = {};

		uint64_t uWorlds = rpm->read<uint64_t>(exe::BaseAddress + offsets::GWorld);
		if (uWorlds != 0)
		{
			uint64_t UGameInstance = rpm->read<uint64_t>(uWorlds + offsets::OwningGameInstance);
			if (UGameInstance != 0)
			{
				uint64_t ULocalPlayer = rpm->read<uint64_t>(UGameInstance + offsets::LocalPlayers);
				if (ULocalPlayer != 0)
				{
					uint64_t LocalPlayer = rpm->read<uint64_t>(ULocalPlayer);
					if (LocalPlayer != 0)
					{

						uint64_t PlayerController = rpm->read<uint64_t>(LocalPlayer + offsets::PlayerController);
						if (PlayerController != 0)
						{

							uint64_t Pawn = rpm->read<uint64_t>(PlayerController + offsets::AcknowledgedPawn);

							for (size_t i = 0; i < TempEntityList.size(); i++)
							{
								uint64_t entityAddv = TempEntityList[i];
								if (!entityAddv)
									continue;
								if (entityAddv == (uint64_t)nullptr || entityAddv == -1 || entityAddv == NULL)
									continue;

								int entityStruct = rpm->read<int>(entityAddv + 0x18);
								if (entityStruct == 0 || entityStruct < 0) continue;

								std::string	entityType = GetEntityType(exe::BaseAddress + offsets::GNames, entityStruct);

								if (entityType == "")
									continue;
								if (entityType == "None")
									continue;

								if (GnameType::isPlayer(entityType))
								{

									A_Players AActor = {};
									uint64_t playerWorld = rpm->read<uint64_t>(entityAddv + offsets::RootComponent);
									if (playerWorld != 0)
									{
										AActor.RelativeRotation = rpm->read<FRotator>(playerWorld + offsets::RelativeRotation);
										AActor.ComponentVelocity = rpm->read<FVector>(playerWorld + offsets::ComponentVelocity);

									}
									AActor.origin = GetBoneWorldPosition(entityAddv, bones::Root);

									int dis = CameraCacheEntry.Location.Distance(AActor.origin) / 100.f;
									if (dis > Settings::ESP::Options::playersdis)
										continue;

									AActor.ptr = entityAddv;

									AActor.bIsCrouched = rpm->read<bool>(entityAddv + offsets::bIsCrouched);

									AActor.CurrShieldValue = rpm->read<float>(entityAddv + offsets::CurrShieldValue);
									AActor.MaxShieldValue = rpm->read<float>(entityAddv + offsets::MaxShieldValue);
									AActor.CurrShieldLevel = rpm->read<int>(entityAddv + offsets::CurrShieldLevel);

									uint64_t SolarPlayerWeapon = rpm->read<uint64_t>(entityAddv + offsets::CachedCurrentWeapon);
									if (SolarPlayerWeapon != 0)
									{
										AActor.WeaponName = rpm->read_unicode(rpm->read<uint64_t>(SolarPlayerWeapon + offsets::ItemData + 0x18), 24); 
										AActor.CurrentClipAmmo = rpm->read<int>(SolarPlayerWeapon + offsets::CurrentClipAmmo);

										uint64_t SingleWeaponConfig = rpm->read<uint64_t>(SolarPlayerWeapon + offsets::Config);
										if (SingleWeaponConfig != 0)
										{
											AActor.WeaponType = rpm->read<int>(SingleWeaponConfig + offsets::WeaponType);
											AActor.PrimaryAmmoCap = rpm->read<int>(SingleWeaponConfig + offsets::PrimaryAmmoCap);

										}

										uint64_t WeaponRecoilComponent = rpm->read<uint64_t>(SolarPlayerWeapon + offsets::RecoilComponent);
										if (WeaponRecoilComponent != 0)
										{
											uint64_t SingleWeaponConfig = rpm->read<uint64_t>(WeaponRecoilComponent + offsets::WeaponConfig);
											if (SingleWeaponConfig != 0)
											{
												uint64_t AmmoConfig = rpm->read<uint64_t>(SingleWeaponConfig + offsets::PrimaryAmmo);
												if (AmmoConfig != 0)
												{
													AActor.InitSpeed = rpm->read<float>(AmmoConfig + offsets::InitSpeed) / 100.f;
													AActor.ProjectileMaxGravity = rpm->read<float>(AmmoConfig + offsets::ProjectileMaxGravity);
												}
											}
										}
									}

									uint64_t PlayerState = rpm->read<uint64_t>(entityAddv + offsets::PlayerState);
									if (PlayerState != 0) {

										AActor.Health = rpm->read<float>(PlayerState + offsets::CurrentHealth);
										AActor.HealthMax = rpm->read<float>(PlayerState + offsets::MaxHealth);
										AActor.IsBot = ((rpm->read<BYTE>(PlayerState + 0x232) & 8) == 8); //bool bIsABot;//(ByteOffset: 0, ByteMask: 8, FieldMask: 8)[Offset: 0x232, Size: 1]

										AActor.Team = rpm->read<int>(PlayerState + offsets::TeamID);
										AActor.SpectatorNum = rpm->read<int>(PlayerState + offsets::SpectatorNum);
										AActor.AccountFlag = rpm->read<int>(PlayerState + offsets::AccountFlag);
										AActor.KillNum = rpm->read<int>(PlayerState + offsets::KillNum);

										AActor.OS = rpm->read_unicode(rpm->read<uint64_t>(PlayerState + offsets::OS),24);
										if (AActor.OS == L"")
											AActor.OS = L"---";

										AActor.Name = rpm->read_unicode(rpm->read<uint64_t>(PlayerState + offsets::PlayerNamePrivate),24);
									}
									if (Settings::ESP::Players::Enemy::prediction || Settings::ESP::Players::Team::prediction) {

										AActor.ESPPrediction.ROOT = GetBoneWorldPosition(entityAddv, bones::Root);
										AActor.ESPPrediction.HEAD = GetBoneWorldPosition(entityAddv, bones::head);
									}
									if (Settings::ESP::Players::Enemy::directionLine || Settings::ESP::Players::Team::directionLine) {

										AActor.ESPDirectionLine.ROOT = GetBoneWorldPosition(entityAddv, bones::Root);
										AActor.ESPDirectionLine.HEAD = GetBoneWorldPosition(entityAddv, bones::head);
									}
									if (Settings::Aimbot::enable) {

										AActor.AimBones.HEAD = GetBoneWorldPosition(entityAddv, bones::head);

										AActor.AimBones.NECK = GetBoneWorldPosition(entityAddv, bones::neck_01);

										AActor.AimBones.Chest = GetBoneWorldPosition(entityAddv, bones::spine_02);

										int Point = GetNearestBone(entityAddv, hitboxes);
										AActor.AimBones.NerstBone = GetBoneWorldPosition(entityAddv, Point);

										AActor.AimBones.ROOT = GetBoneWorldPosition(entityAddv, bones::Root);

									}
									if (Settings::ESP::Players::Enemy::skeleton || Settings::ESP::Players::Team::skeleton) {

										AActor.Bones.vHeadBone = GetBoneWorldPosition(entityAddv, bones::head);
										AActor.Bones.vHeadBone.Z += 7.f;

										AActor.Bones.vHip = GetBoneWorldPosition(entityAddv, bones::Bip001);
										AActor.Bones.vNeck = GetBoneWorldPosition(entityAddv, bones::neck_01);
										AActor.Bones.vUpperArmLeft = GetBoneWorldPosition(entityAddv, bones::upperarm_l);
										AActor.Bones.vUpperArmRight = GetBoneWorldPosition(entityAddv, bones::upperarm_r);
										AActor.Bones.vLeftHand = GetBoneWorldPosition(entityAddv, bones::hand_l);
										AActor.Bones.vRightHand = GetBoneWorldPosition(entityAddv, bones::hand_r);
										AActor.Bones.vLeftHand1 = GetBoneWorldPosition(entityAddv, bones::thumb_01_l); //
										AActor.Bones.vRightHand1 = GetBoneWorldPosition(entityAddv, bones::thumb_01_r); //
										AActor.Bones.vRightThigh = GetBoneWorldPosition(entityAddv, bones::thigh_r);
										AActor.Bones.vLeftThigh = GetBoneWorldPosition(entityAddv, bones::thigh_l);
										AActor.Bones.vRightCalf = GetBoneWorldPosition(entityAddv, bones::calf_r);
										AActor.Bones.vLeftCalf = GetBoneWorldPosition(entityAddv, bones::calf_l);
										AActor.Bones.vLeftFoot = GetBoneWorldPosition(entityAddv, bones::foot_l);
										AActor.Bones.vRightFoot = GetBoneWorldPosition(entityAddv, bones::foot_r);

										AActor.Bones.VRoot = GetBoneWorldPosition(entityAddv, bones::Root);

									}

									if (entityAddv == Pawn)
									{
										MyLocalPlayer = AActor;
									}

									Players.push_back(AActor);
								}
								if (GnameType::IsVehicle(entityType))
								{

									A_Vehicle AActor = { };
									uint64_t playerWorld = rpm->read<uint64_t>(entityAddv + offsets::RootComponent);
									if (playerWorld != 0)
									{
										AActor.origin = rpm->read<FVector>(playerWorld + offsets::RelativeLocation);
									}

									int dis = CameraCacheEntry.Location.Distance(AActor.origin) / 100.f;
									if (dis > Settings::ESP::Options::vehiclesdis)
										continue;

									AActor.Distance = dis;
									AActor.ptr = entityAddv;
									AActor.FnameType = entityType;

									if (entityAddv == Pawn)
									{
										MyLocalVehicle = AActor;
									}
									Vehicles.push_back(AActor);
								}


							}
						}
					}

				}
			}
		}

		EntityList = Players;

		EntityVehicle = Vehicles;



		std::this_thread::sleep_for(std::chrono::milliseconds(20));


	}


}
__forceinline void  Cache3()
{
	for (;;)
	{
		std::vector<A_Pickup> pickup = {};

		for (size_t i = 0; i < TempEntityList2.size(); i++)
		{
			uint64_t entityAddv = TempEntityList2[i];
			if (!entityAddv)
				continue;
			if (entityAddv == (uint64_t)nullptr || entityAddv == -1 || entityAddv == NULL)
				continue;

			int entityStruct = rpm->read<int>(entityAddv + 0x18);
			if (entityStruct == 0 || entityStruct < 0) continue;

			std::string	entityType = GetEntityType(exe::BaseAddress + offsets::GNames, entityStruct);
			if (entityType == "")
				continue;
			if (entityType == "None")
				continue;

			if (GnameType::IsPickup(entityType) || GnameType::IsElectricbox(entityType)
				|| GnameType::IsDeadBox(entityType) || GnameType::IsDropBox(entityType))
			{
				A_Pickup AActor = { };
				uint64_t playerWorld = rpm->read<uint64_t>(entityAddv + offsets::RootComponent);
				if (playerWorld != 0)
				{
					AActor.origin = rpm->read<FVector>(playerWorld + offsets::RelativeLocation);
				}

				int dis = CameraCacheEntry.Location.Distance(AActor.origin) / 100.f;
				if (dis > 1000)
					continue;

				int type = rpm->read<int>(entityAddv + offsets::SolarItemData + 0x4c);
				if (type == 0 || type < 0)
					continue;

				if (type == (int)EItemType::WEAPON && Settings::ESP::Loot::WEAPON)
				{
					if (dis < 100)
					{
						int Quality = rpm->read<int>(entityAddv + offsets::SolarItemData + 0x50);
						AActor.ptr = entityAddv;
						AActor.Distance = dis;
						AActor.items = rpm->read_unicode(rpm->read<uint64_t>(entityAddv + offsets::SolarItemData + 0x18),24);
						AActor.type = type;
						AActor.Quality = Quality;

						pickup.push_back(AActor);

					}
				}
				if (type == (int)EItemType::WEAPON_PARTS && Settings::ESP::Loot::WEAPONPARTS)
				{
					if (dis < 100)
					{
						int Quality = rpm->read<int>(entityAddv + offsets::SolarItemData + 0x50);

						if (Quality == 1 && !Settings::ESP::Options::WEAPONPARTS::lv1)
							continue;
						if (Quality == 2 && !Settings::ESP::Options::WEAPONPARTS::lv2)
							continue;
						if (Quality == 3 && !Settings::ESP::Options::WEAPONPARTS::lv3)
							continue;
						if (Quality == 4 && !Settings::ESP::Options::WEAPONPARTS::lv4)
							continue;
						if (Quality == 5 && !Settings::ESP::Options::WEAPONPARTS::lv5)
							continue;
						if (Quality == 6 && !Settings::ESP::Options::WEAPONPARTS::lv6)
							continue;

						AActor.ptr = entityAddv;
						AActor.Distance = dis;
						AActor.items = rpm->read_unicode(rpm->read<uint64_t>(entityAddv + offsets::SolarItemData + 0x18),24);
						AActor.type = type;
						AActor.Quality = Quality;

						pickup.push_back(AActor);

					}
				}
				if (type == (int)EItemType::SHIELD && Settings::ESP::Loot::SHIELD)
				{

					if (dis < 100)
					{
						int Quality = rpm->read<int>(entityAddv + offsets::SolarItemData + 0x50);

						if (Quality == 1 && !Settings::ESP::Options::SHIELD::lv1)
							continue;
						if (Quality == 2 && !Settings::ESP::Options::SHIELD::lv2)
							continue;
						if (Quality == 3 && !Settings::ESP::Options::SHIELD::lv3)
							continue;
						if (Quality == 4 && !Settings::ESP::Options::SHIELD::lv4)
							continue;
						if (Quality == 5 && !Settings::ESP::Options::SHIELD::lv5)
							continue;
						if (Quality == 6 && !Settings::ESP::Options::SHIELD::lv6)
							continue;

						AActor.ptr = entityAddv;
						AActor.Distance = dis;
						AActor.items = rpm->read_unicode(rpm->read<uint64_t>(entityAddv + offsets::SolarItemData + 0x18),24);
						AActor.type = type;
						AActor.Quality = Quality;

						pickup.push_back(AActor);

					}
				}
				if (type == (int)EItemType::SHIELD_UPGRADE_MATERIAL && Settings::ESP::Loot::SHIELDXP)
				{
					if (dis < 100)
					{
						AActor.ptr = entityAddv;
						AActor.Distance = dis;
						AActor.items = rpm->read_unicode(rpm->read<uint64_t>(entityAddv + offsets::SolarItemData + 0x18),24);
						AActor.type = type;
						pickup.push_back(AActor);

					}
				}
				if (type == (int)EItemType::BULLET && Settings::ESP::Loot::BULLET)
				{
					if (dis < 100)
					{
						AActor.ptr = entityAddv;
						AActor.Distance = dis;
						AActor.items = rpm->read_unicode(rpm->read<uint64_t>(entityAddv + offsets::SolarItemData + 0x18),24);
						AActor.type = type;

						pickup.push_back(AActor);

					}
				}
				if (type == (int)EItemType::CARIRIDGE_BAG && Settings::ESP::Loot::CARIRIDGE)
				{
					if (dis < 100)
					{
						AActor.ptr = entityAddv;
						AActor.Distance = dis;
						AActor.items = rpm->read_unicode(rpm->read<uint64_t>(entityAddv + offsets::SolarItemData + 0x18),24);
						AActor.type = type;
						pickup.push_back(AActor);

					}
				}
				if (type == (int)EItemType::AIRDROPBOX && Settings::ESP::Inventory::AirDrop)
				{
					if (dis < 1000)
					{
						AActor.ptr = entityAddv;
						AActor.Distance = dis;
						AActor.items = rpm->read_unicode(rpm->read<uint64_t>(entityAddv + offsets::SolarItemData + 0x18),24);
						AActor.type = type;

						pickup.push_back(AActor);

					}
				}
				if (type == (int)EItemType::DEATHBOX && Settings::ESP::Inventory::Deadbox)
				{
					if (dis < 100)
					{
						AActor.ptr = entityAddv;
						AActor.Distance = dis;
						AActor.items = rpm->read_unicode(rpm->read<uint64_t>(entityAddv + offsets::SolarItemData + 0x18),24);
						AActor.type = type;

						pickup.push_back(AActor);

					}
				}
				if (type == (int)EItemType::TREASUREBOX && Settings::ESP::Inventory::ElectricBox)
				{
					if (dis < 100)
					{
						AActor.ptr = entityAddv;
						AActor.Distance = dis;
						AActor.items = rpm->read_unicode(rpm->read<uint64_t>(entityAddv + offsets::SolarItemData + 0x18),24);
						AActor.type = type;

						pickup.push_back(AActor);

					}
				}
			}

		}
		EntityPickups = pickup;
		std::this_thread::sleep_for(std::chrono::milliseconds(1500));

	}
}
void OverlayThread()
{
	Globals::hwnd = FindWindowA("UnrealWindow", 0);
	if (Globals::hwnd == 0)
	{
		std::cout << "Cant Find Window" << std::endl;
		return;
	}
	GL3Setup();
	Sleep(800);
	while (!glfwWindowShouldClose(Globals::g_window)) {
		mainLoop();
	}


}

bool FixDriveBlockList()
{
	system("cls");
	bool isChange = false;

	RegKey VulnerableDriverBlocklist{ HKEY_LOCAL_MACHINE, L"SYSTEM\\ControlSet001\\Control\\CI\\Config" };
	if (VulnerableDriverBlocklist.IsValid()) {
		if (auto VulnerableDriverBlocklistEnable = VulnerableDriverBlocklist.TryGetDwordValue(L"VulnerableDriverBlocklistEnable"))
		{
			if (VulnerableDriverBlocklistEnable.GetValue() != 0)
			{
				VulnerableDriverBlocklist.SetDwordValue(L"VulnerableDriverBlocklistEnable", 0x0);
				isChange = true;
			}
		}
	}
	VulnerableDriverBlocklist.Close();

	RegKey DeviceGuard{ HKEY_LOCAL_MACHINE, L"SYSTEM\\ControlSet001\\Control\\DeviceGuard" };
	if (DeviceGuard.IsValid()) {

		if (auto EnableVirtualizationBasedSecurity = DeviceGuard.TryGetDwordValue(L"EnableVirtualizationBasedSecurity"))
		{
			if (EnableVirtualizationBasedSecurity.GetValue() != 0)
			{
				DeviceGuard.SetDwordValue(L"EnableVirtualizationBasedSecurity", 0x0);
				isChange = true;
			}

		}
		if (auto RequireMicrosoftSignedBootChain = DeviceGuard.TryGetDwordValue(L"RequireMicrosoftSignedBootChain"))
		{
			if (RequireMicrosoftSignedBootChain.GetValue() != 0)
			{
				DeviceGuard.SetDwordValue(L"RequireMicrosoftSignedBootChain", 0x0);
				isChange = true;
			}

		}

	}
	DeviceGuard.Close();

	RegKey DeviceGuard2{ HKEY_LOCAL_MACHINE, L"SYSTEM\\ControlSet001\\Control\\DeviceGuard\\Scenarios" };
	if (DeviceGuard2.IsValid())
	{
		if (DeviceGuard2.TrySetDwordValue(L"HypervisorEnforcedCodeIntegrity", 0x0).IsOk())
		{
			DeviceGuard2.SetDwordValue(L"HypervisorEnforcedCodeIntegrity", 0x0);
		}
	}
	DeviceGuard2.Close();

	if (isChange)
	{
		std::cout << xorstr_("Settings have been prepared and will be restarted after 10 seconds") << std::endl;
		Sleep(10 * 1000);
		system("shutdown /r");
		return false;
	}
	return true;
}
/*bool load_driver()
{

	auto expid = othermem::FindProcessId(decrypt("gzrnqtgt0gzg"));
	MoaRpm* ckrpm = new MoaRpm(expid, MoaRpm::MOA_MODE::KERNEL);
	if (ValidPointer(ckrpm->ImageBase())) {

		return true;
	}


	system("sc config vgc start= disabled & sc config vgk start= disabled & net stop vgc & net stop vgk & sc delete vgc & sc delete vgk & taskkill /IM vgtray.exe");
	bool free = false; //
	bool mdlMode = true;
	bool passAllocationPtr = false;

	HANDLE iqvw64e_device_handle = 0;

	if (intel_driver::IsRunning())
	{
		return false;
	}

	iqvw64e_device_handle = intel_driver::Load();
	std::vector<uint8_t> raw_image;
	for (size_t i = 0; i <= sizeof(Driver); i++)
	{
		raw_image.push_back(Driver[i]);
	}
	NTSTATUS exitCode = 0;
	if (!kdmapper::MapDriver(iqvw64e_device_handle, raw_image, 0, 0, free, true, mdlMode, passAllocationPtr, nullptr, &exitCode))
	{

		intel_driver::Unload(iqvw64e_device_handle);
		return false;

	}
	intel_driver::Unload(iqvw64e_device_handle);
	system("cls");
	Sleep(500);


	return true;


}*/

int main()
{

	std::thread(AntiDebug::AntiDebugLoop).detach();

	//othermem::killProcessByName(decrypt("CrrOctmgv0gzg").c_str());
	//othermem::killProcessByName(decrypt("CpftqkfGowncvqtGp0gzg").c_str());
	//othermem::killProcessByName(decrypt("CpftqkfGowncvqt0gzg").c_str());

	system(xorstr_("cls"));


	Globals::process_handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, GetCurrentProcessId());


	if (!FixDriveBlockList())
	{
		std::cout << decrypt("EcpvaRtgrctcvkqpaEjgcv") << std::endl; //helpo
		Sleep(8000);
		exit(1);
	}
	/*if (!load_driver())
	{
		std::cout << decrypt("EcpvaNqcfaEjgcv") << std::endl;
		Sleep(8000);
		exit(1);
	}*/
	Sleep(2000);
	DWORD pid = GetCurrentProcessId();
	CreateDirectory(decrypt("0^Tgu").c_str(), NULL);

	if (1)
	{

		std::cout << std::endl;



		std::cout << "Wait_Game_Open" << std::endl;
		while (othermem::GetProcessIdByName("SolarlandClient-Win64-Shipping.exe") ==  NULL) { Sleep(500); }
		Sleep(6000);

	re:
		auto pID = othermem::GetProcessIdByName("SolarlandClient-Win64-Shipping.exe");
		if (pID > 0)
		{

			rpm = new MoaRpm(pID, MoaRpm::MOA_MODE::KERNEL);
			uint64_t Base = rpm->ImageBase();
			if (!ValidPointer(Base))
				goto re;

			exe::BaseAddress = Base;

			system("cls");
			CreateDirectory(decrypt("0^Tgu^Eqphki").c_str(), NULL);

			Utils::GuiFile = decrypt("0^Tgu^Eqphki^iwk0kpk");
			Utils::RefreshConfigs(decrypt("0^Tgu^Eqphki^,0kpk").c_str());



			std::thread(Cache).detach();
			std::thread(Cache2).detach();
			std::thread(Cache3).detach();
			std::thread(cam).detach();
			std::thread(Misc::Run).detach();
			std::thread(Aimbot::Run).detach();
			std::thread(OverlayThread).detach();


		}


		//::ShowWindow(::GetConsoleWindow(), SW_HIDE);

		for (;;) {
			if (GetAsyncKeyState(VK_END)) {
				ImGui::SaveIniSettingsToDisk(decrypt("0^Tgu^Eqphki^iwk0kpk").c_str());				
				Globals::isopened = false;
				FreeConsole();
				ExitProcess(1);
			}
			Sleep(500);
		}

	}
	else
	{
		Sleep(8000);
		exit(0);
	}


	return 0;
}

