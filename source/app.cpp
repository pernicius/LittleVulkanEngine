#include "pch.h"
#include "app.h"

namespace lve {


	void App::Run()
	{
		while (!m_window.ShouldClose()) {
			glfwPollEvents();
		}
	}


} // namespace lve

