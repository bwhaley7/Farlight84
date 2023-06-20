#include "Includes.h"
namespace Globals
{
	HANDLE process_handle = 0;
	 std::string overlayName = "";
	HWND hwnd = {};
	GLFWwindow* g_window = {};
	 HWND overlayWindow = 0;
	 int width = 0;
	 int height = 0;
	 int left = 0;
	 int top = 0;
	 bool isopened = true;
	 int FPS = 0;
}