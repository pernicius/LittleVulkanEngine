#include "pch.h"
#include "lve_window.h"

#include "log.h"

#include <stdexcept>

namespace lve {


	LveWindow::LveWindow(int width, int height, std::string title)
		: m_width(width), m_height(height), m_title(title)
	{
		InitWindow();

	}
	
	
	LveWindow::~LveWindow()
	{
		if (m_window)
			glfwDestroyWindow(m_window);
		glfwTerminate();

		LOG_VULKAN("Window destroyed.");
	}
	
	
	void LveWindow::InitWindow()
	{
		glfwInit();

		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
		m_window = glfwCreateWindow(m_width, m_height, m_title.c_str(), nullptr, nullptr);

		LOG_VULKAN("Window created.");
	}


	void LveWindow::CreateWindowSurface(VkInstance instance, VkSurfaceKHR* surface)
	{
		if (glfwCreateWindowSurface(instance, m_window, nullptr, surface) != VK_SUCCESS) {
			throw std::runtime_error("failed to craete window surface");
		}

		LOG_VULKAN("Surface created.");
	}


} // namespace lve
