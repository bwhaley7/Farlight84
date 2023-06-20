#pragma once
extern ImFont* m_FVisuals;
extern ImFont* bold;
extern ImFont* weapons;
namespace Icons
{
	extern GLuint Logo;

}
namespace GL3
{

	extern void InitImGui(GLFWwindow* hWindow);
	extern void GL3Render(GLFWwindow* hWindow);
	extern void release(GLFWwindow* hWindow);

}

