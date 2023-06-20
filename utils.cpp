#include "Includes.h"

namespace Utils
{
	const std::string gen_random(const int len) {
		static const char alphanum[] =
			"0123456789"
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
			"abcdefghijklmnopqrstuvwxyz";
		std::string tmp_s;
		tmp_s.reserve(len);

		for (int i = 0; i < len; ++i) {
			tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
		}

		return tmp_s;
	}
	FVector AimbotCorrection(float bulletVelocity, float bulletGravity, float targetDistance, FVector targetPosition, FVector targetVelocity) {
		FVector recalculated = targetPosition;
		float gravity = fabs(bulletGravity);
		float time = targetDistance / fabs(bulletVelocity);
		float bulletDrop = gravity * time * time;
		recalculated.Z += bulletDrop;
		recalculated.X += time * (targetVelocity.X);
		recalculated.Y += time * (targetVelocity.Y);
		recalculated.Z += time * (targetVelocity.Z);
		return recalculated;
	}
	std::string replaceFirstOccurrence(
		std::string& s,
		const std::string& toReplace,
		const std::string& replaceWith)
	{
		std::size_t pos = s.find(toReplace);
		if (pos == std::string::npos) return s;
		return s.replace(pos, toReplace.length(), replaceWith);
	}
	void VectorAnglesRadar(FVector& forward, FVector& angles)
	{
		if (forward.X == 0.f && forward.Y == 0.f)
		{
			angles.X = forward.Z > 0.f ? -90.f : 90.f;
			angles.Y = 0.f;
		}
		else
		{
			angles.X = RAD2DEG(atan2(-forward.Z, forward.Size()));
			angles.Y = RAD2DEG(atan2(forward.Y, forward.X));
		}
		angles.Z = 0.f;
	}
	void RotateTriangle(std::array<FVector, 3>& points, float rotation)
	{
		const auto points_center = (points.at(0) + points.at(1) + points.at(2)) / 3;
		for (auto& point : points)
		{
			point = point - points_center;

			const auto temp_x = point.X;
			const auto temp_y = point.Y;

			const auto theta = DEG2RAD(rotation);
			const auto c = cosf(theta);
			const auto s = sinf(theta);

			point.X = temp_x * c - temp_y * s;
			point.Y = temp_x * s + temp_y * c;

			point = point + points_center;
		}
	}
	FVector2D WorldToRadar(FRotator Rotation, FVector CameraLocation, FVector Origin, FVector2D RadarPosition, FVector2D RadarSize)
	{
		FVector2D DotPos;
		FVector2D Direction;

		// Get Origin Of Entity
		FVector EntityPosition = Origin;

		// Get Origin Of LocalPlayer
		FVector LocalPosition = CameraLocation;

		// Calculate Direction
		Direction.X = EntityPosition.Y - LocalPosition.Y;
		Direction.Y = EntityPosition.X - LocalPosition.X;

		// Get Rotation
		float LocalAngles = Rotation.Yaw;

		float Radian = DEG2RAD(LocalAngles);

		// Calculate Raw DotPos
		DotPos.X = (Direction.X * (float)cos(Radian) - Direction.Y * (float)sin(Radian)) / 150.0f;
		DotPos.Y = (Direction.Y * (float)cos(Radian) + Direction.X * (float)sin(Radian)) / 150.0f;

		// Add RadarPos To Calculated DotPos
		DotPos.X = DotPos.X + RadarPosition.X + RadarSize.X / 2.f;
		DotPos.Y = -DotPos.Y + RadarPosition.Y + RadarSize.Y / 2.f;

		// Clamp Dots To RadarSize ( Where 18 = Width/Height of the Dot)
		if (DotPos.X < RadarPosition.X)
			DotPos.X = RadarPosition.X;

		if (DotPos.X > RadarPosition.X + RadarSize.X - 18)
			DotPos.X = RadarPosition.X + RadarSize.X - 18;

		if (DotPos.Y < RadarPosition.Y)
			DotPos.Y = RadarPosition.Y;

		if (DotPos.Y > RadarPosition.Y + RadarSize.Y - 18)
			DotPos.Y = RadarPosition.Y + RadarSize.Y - 18;

		return DotPos;
	}

	bool keydown(int key)
	{
		return (GetAsyncKeyState(key) & 0x8000) != 0;
	}

	FVector2D Randomize(FVector2D vAngles, float HumanSpeed, float HumanScale)
	{
		float lastX = 0.f;

		float lastY = 0.f;

		float destX = 0.f;

		float destY = 0.f;

		float curX = 0.f;

		float curY = 0.f;

		if (abs(curX - destX) < .05f)
		{
			destX = rand() % (int)(HumanScale * 10) + 1;
			destX /= 500;
			int positive = rand() % 2 + 1;
			if (positive == 2)
				destX = -destX;
		}

		if (abs(curY - destY) < .05f)
		{
			destY = rand() % (int)(HumanScale * 10) + 1;
			destY /= 500;
			int positive = rand() % 2 + 1;
			if (positive == 2)
				destY = -destY;

		}

		int speed = 20 - int(HumanSpeed);
		curX += (destX - curX) / ((15 * speed) + 10);

		curY += (destY - curY) / ((15 * speed) + 10);

		vAngles.X += curX;
		vAngles.Y += curY;

		lastX = curX;
		lastY = curY;



		return vAngles;

	}
	void AimAtPosV2(int screenwidth, int screenheight, float x, float y, float speed, float humanspeed, float humanscale)
	{

		int ScreenCenterX = screenwidth / 2, ScreenCenterY = screenheight / 2;
		float AimSpeed = (speed) * 2.f;
		float TargetX = 0;
		float TargetY = 0;

		//X Axis
		if (x != 0)
		{
			if (x > ScreenCenterX)
			{
				TargetX = -(ScreenCenterX - x);
				TargetX /= AimSpeed;
				if (TargetX + ScreenCenterX > ScreenCenterX * 2) TargetX = 0;
			}

			if (x < ScreenCenterX)
			{
				TargetX = x - ScreenCenterX;
				TargetX /= AimSpeed;
				if (TargetX + ScreenCenterX < 0) TargetX = 0;
			}
		}

		//Y Axis

		if (y != 0)
		{
			if (y > ScreenCenterY)
			{
				TargetY = -(ScreenCenterY - y);
				TargetY /= AimSpeed;
				if (TargetY + ScreenCenterY > ScreenCenterY * 2) TargetY = 0;
			}

			if (y < ScreenCenterY)
			{
				TargetY = y - ScreenCenterY;
				TargetY /= AimSpeed;
				if (TargetY + ScreenCenterY < 0) TargetY = 0;
			}
		}

		FVector2D GetTarget = FVector2D(TargetX, TargetY);

		FVector2D OutTarget = Randomize(GetTarget, humanspeed, humanscale);

		Inputs::mouse_move(OutTarget.X, OutTarget.Y);
	}

	double GetCrossDistance(double x1, double y1, double x2, double y2)
	{
		return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
	}

	int get_fps()
	{
		using namespace std::chrono;
		static int count = 0;
		static auto last = high_resolution_clock::now();
		auto now = high_resolution_clock::now();
		static int fps = 0;

		count++;

		if (duration_cast<milliseconds>(now - last).count() > 1000) {
			fps = count;
			count = 0;
			last = now;
		}

		return fps;
	}

	std::vector<std::string> ConfigList;
	std::string GuiFile = "";

	typedef void(*LPSEARCHFUNC)(LPCTSTR lpszFileName);
	BOOL SearchFiles(LPCTSTR lpszFileName, LPSEARCHFUNC lpSearchFunc, BOOL bInnerFolders = FALSE)
	{
		LPTSTR part;
		char tmp[MAX_PATH];
		char name[MAX_PATH];

		HANDLE hSearch = NULL;
		WIN32_FIND_DATA wfd;
		memset(&wfd, 0, sizeof(WIN32_FIND_DATA));

		if (bInnerFolders)
		{
			if (GetFullPathName(lpszFileName, MAX_PATH, tmp, &part) == 0) return FALSE;
			strcpy(name, part);
			strcpy(part, "*.*");
			wfd.dwFileAttributes = FILE_ATTRIBUTE_DIRECTORY;
			if (!((hSearch = FindFirstFile(tmp, &wfd)) == INVALID_HANDLE_VALUE))
				do
				{
					if (!strncmp(wfd.cFileName, ".", 1) || !strncmp(wfd.cFileName, "..", 2))
						continue;

					if (wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
					{
						char next[MAX_PATH];
						if (GetFullPathName(lpszFileName, MAX_PATH, next, &part) == 0) return FALSE;
						strcpy(part, wfd.cFileName);
						strcat(next, "\\");
						strcat(next, name);

						SearchFiles(next, lpSearchFunc, TRUE);
					}
				} while (FindNextFile(hSearch, &wfd));
				FindClose(hSearch);
		}

		if ((hSearch = FindFirstFile(lpszFileName, &wfd)) == INVALID_HANDLE_VALUE)
			return TRUE;
		do
			if (!(wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
			{
				char file[MAX_PATH];
				if (GetFullPathName(lpszFileName, MAX_PATH, file, &part) == 0) return FALSE;
				strcpy(part, wfd.cFileName);

				lpSearchFunc(wfd.cFileName);
			}
		while (FindNextFile(hSearch, &wfd));
		FindClose(hSearch);
		return TRUE;
	}
	void ReadConfigs(LPCTSTR lpszFileName)
	{
		if (!strstr(lpszFileName, "gui.ini"))
		{
			ConfigList.push_back(lpszFileName);
		}
	}
	void RefreshConfigs(std::string file)
	{
		ConfigList.clear();
		std::string ConfigDir = file;
		SearchFiles(ConfigDir.c_str(), ReadConfigs, FALSE);
	}

}

