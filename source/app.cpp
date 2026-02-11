#include "pch.h"
#include "app.h"

#include "log.h"

namespace lve {
	
	
	App::App()
	{
		LOG_INFO("App created.");
	}
	
	
	App::~App()
	{
		LOG_INFO("App destroyed.");
	}


	void App::Run()
	{
		LOG_INFO("Run loop entered.");

		while (!m_window.ShouldClose()) {
			glfwPollEvents();
		}
		
		LOG_INFO("Run loop exited.");
	}


} // namespace lve

