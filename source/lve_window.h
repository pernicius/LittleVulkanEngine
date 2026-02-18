#pragma once

#include <vulkan/vulkan.hpp>
#include <GLFW/glfw3.h>

#include <string>

namespace lve {


	class LveWindow
	{
	public:
		LveWindow(int width, int height, std::string title);
		~LveWindow();

		// Delete copy constructor and copy assignment operator to prevent copying of the window
		LveWindow(const LveWindow&) = delete;
		LveWindow& operator=(const LveWindow&) = delete;
		
		bool ShouldClose() { return glfwWindowShouldClose(m_window); }
		GLFWwindow* GetGLFWwindow() const { return m_window; }
		VkExtent2D GetExtent() { return { static_cast<uint32_t>(m_width), static_cast<uint32_t>(m_height) }; }

		void CreateWindowSurface(VkInstance instance, VkSurfaceKHR* surface);

	private:
		void InitWindow();

		GLFWwindow* m_window{ nullptr };
		const int m_width;
		const int m_height;
		std::string m_title;
	};


} // namespace lve
