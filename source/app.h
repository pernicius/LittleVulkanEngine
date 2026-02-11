#pragma once

#include "lve_window.h"
#include "lve_pipeline.h"

namespace lve {


	class App
	{
	public:
		App();
		~App();

		void Run();

	private:
		static constexpr int WIDTH = 800;
		static constexpr int HEIGHT = 600;

		LveWindow m_window{ WIDTH, HEIGHT, "Hello Vulkan!" };
		LvePipeline m_pipeline{"shaders/simple_shader.vert.spv", "shaders/simple_shader.frag.spv"};

	};


} // namespace lve
