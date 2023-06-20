#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "Includes.h"

ImFont* m_FVisuals = NULL;
ImFont* bold = NULL;
ImFont* weapons = NULL;

int ticks = 0;
int beforeclock = 0;

namespace Icons
{
	GLuint Logo;

}
namespace GL3 {
	void toglemenu()
	{
		if (GetAsyncKeyState(VK_INSERT) & 1)
		{
			Globals::isopened = !Globals::isopened;
			//glfwSetWindowAttrib(Globals::g_window, GLFW_MOUSE_PASSTHROUGH, !Globals::isopened);
			if (Globals::isopened)
			{
				/*	glClearColor(0.0, 0.0, 0.0, 0.8);
					HWND overlay_window = glfwGetWin32Window(Globals::g_window);
					SetForegroundWindow(overlay_window);*/
				SetWindowLongA(Globals::overlayWindow, GWL_EXSTYLE, WS_EX_LAYERED | WS_EX_TOOLWINDOW);
			}
			else
			{
				/*glClearColor(0.0, 0.0, 0.0, 0.0);
				SetForegroundWindow(Globals::hwnd);*/
				SetWindowLongA(Globals::overlayWindow, GWL_EXSTYLE, (int)GetWindowLongA(Globals::overlayWindow, GWL_EXSTYLE) | WS_EX_TRANSPARENT);

			}
		}
	}
	void InitItemesIcon()
	{
		Icons::Logo;
		{
			int w, h, bits;
			unsigned char* pixels = stbi_load_from_memory(Logo_Icon, sizeof(Logo_Icon), &w, &h, &bits, STBI_rgb_alpha);
			glCreateTextures(GL_TEXTURE_2D, 1, &Icons::Logo);
			glBindTexture(GL_TEXTURE_2D, Icons::Logo);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
			stbi_image_free(pixels);
		}
	}
	void InitImGui(GLFWwindow* hWindow)
	{
		static const ImWchar rangesXX[] = {
0x0020, 0x00FF,
0x0600, 0x06FF,
0x2010, 0x205E,
0xFB50, 0xFBFF,
0xFE00, 0xFEFF,
0x0100, 0x017F,
0x0300, 0x03ff,
0xf000, 0xf3ff,
0x0400, 0x044F,
0xe000, 0xf8ff,
0x3131, 0x3163,
0xAC00, 0xD7A3,
0x2000, 0x206F,
0x3000, 0x30FF,
0x31F0, 0x31FF,
0xFF00, 0xFFEF,
0x4e00, 0x9FAF,
0x0400, 0x052F,
0x2DE0, 0x2DFF,
0xA640, 0xA69F,
0x0E00, 0x0E7F,
0x0102, 0x0103,
0x0110, 0x0111,
0x0128, 0x0129,
0x0168, 0x0169,
0x01A0, 0x01A1,
0x01AF, 0x01B0,
0x1EA0, 0x1EF9,
0x02BC, 0x0384,
0,
		};

		IMGUI_CHECKVERSION();
		ImGui::CreateContext();

		ImGuiIO& io = ImGui::GetIO();
		io.IniFilename = nullptr;
		io.LogFilename = nullptr;
		ImGui::LoadIniSettingsFromDisk(xorstr_(".\\Res\\Config\\gui.ini"));

		ImFontConfig FontConfig = {};
		FontConfig.OversampleH = 1;
		FontConfig.OversampleV = 1;
		FontConfig.PixelSnapH = 1;

		ImGui::GetIO().FontDefault = io.Fonts->AddFontFromFileTTF(xorstr_(".\\Res\\Fonts\\bold.ttf"), 14.0f, &FontConfig, rangesXX);
		bold = io.Fonts->AddFontFromFileTTF(xorstr_(".\\Res\\Fonts\\bold.ttf"), 20.0f, &FontConfig, rangesXX);
		m_FVisuals = io.Fonts->AddFontFromFileTTF(xorstr_(".\\Res\\Fonts\\bold.ttf"), 18.0f, &FontConfig, rangesXX);// io.Fonts->AddFontFromFileTTF(skCrypt(".\\Res\\Fonts\\esp.ttf"), 18.0f, &FontConfig, rangesXX);
		weapons = io.Fonts->AddFontFromMemoryCompressedTTF(Weapons_compressed_data, Weapons_compressed_size, 30);


		ImGuiStyle& style = ImGui::GetStyle();
		style.Alpha = 1.0f;
		style.WindowPadding = ImVec2(8, 8);
		style.WindowMinSize = ImVec2(32, 32);
		style.WindowRounding = 0.5f;
		style.WindowTitleAlign = ImVec2(0.5f, 0.5f);
		style.FramePadding = ImVec2(4, 2);
		style.FrameRounding = 0.0f;
		style.ItemSpacing = ImVec2(8, 4);
		style.ItemInnerSpacing = ImVec2(4, 4);
		style.TouchExtraPadding = ImVec2(0, 0);
		style.IndentSpacing = 21.0f;
		style.ColumnsMinSpacing = 3.0f;
		style.ScrollbarSize = 12.0f;
		style.ScrollbarRounding = 0.0f;
		style.GrabMinSize = 0.1f;
		style.GrabRounding = 0.0f;
		style.ButtonTextAlign = ImVec2(0.5f, 0.5f);
		style.DisplayWindowPadding = ImVec2(22, 22);
		style.DisplaySafeAreaPadding = ImVec2(4, 4);
		style.AntiAliasedLines = true;
		style.CurveTessellationTol = 1.25f;

		ImGui_ImplGlfw_InitForOpenGL(hWindow, true);
		ImGui_ImplOpenGL3_Init(xorstr_("#version 130"));


		InitItemesIcon();

	}

	void GL3Render(GLFWwindow* hWindow)
	{
		int choisefps = 0;
		int vsyncA = clock();
		ticks += 1;
		if (beforeclock == 0) {
			beforeclock = clock();
		}
		toglemenu();

		glfwPollEvents();
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		GL3Draw::GetInstance()->BeginScene();
		GL3Draw::GetInstance()->DrawScene();
		GL3Draw::GetInstance()->EndScene();
		menu::init();

		ImGui::Render();
		int display_w, display_h;
		glfwGetFramebufferSize(hWindow, &display_w, &display_h);
		glViewport(0, 0, display_w, display_h);
		glClear(GL_COLOR_BUFFER_BIT);
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		glfwSwapBuffers(hWindow);

		if (Settings::Setting::fps == 0)
			choisefps = 25;
		else if (Settings::Setting::fps == 1)
			choisefps = 14;
		else
			choisefps = 9;


		if (Settings::Setting::vsync) {
			int pausetime = choisefps - (clock() - vsyncA);
			if (pausetime > 0 && pausetime < 30) {
				std::this_thread::sleep_for(std::chrono::milliseconds(pausetime));
			}
		}
		int afterclock = clock();
		if (afterclock - beforeclock > 1000) {
			Globals::FPS = ticks;
			beforeclock = 0;
			ticks = 0;
		}
	}

	void release(GLFWwindow* hWindow)
	{
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();

		glfwDestroyWindow(hWindow);
		glfwTerminate();

	}
}
