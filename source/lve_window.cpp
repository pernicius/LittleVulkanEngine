#include "pch.h"
#include "lve_window.h"

#include "log.h"

namespace lve {


	LveWindow::LveWindow(int width, int height, std::string title)
		: m_width(width), m_height(height), m_title(title)
	{
		LOG_INFO("Window creating...");

		InitWindow();

		LOG_INFO("Window created.");
	}
	
	
	LveWindow::~LveWindow()
	{
		LOG_INFO("Window destroying...");

		if (m_window)
			glfwDestroyWindow(m_window);

		glfwTerminate();

		LOG_INFO("Window destroyed.");
	}
	
	
	void LveWindow::InitWindow()
	{
		glfwInit();

		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
		m_window = glfwCreateWindow(m_width, m_height, m_title.c_str(), nullptr, nullptr);
	}


} // namespace lve
