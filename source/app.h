#pragma once

#include "lve_device.h"
#include "lve_pipeline.h"
#include "lve_window.h"

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
		LveDevice m_lveDevice{ m_window };
		LvePipeline m_lvePipeline{
			m_lveDevice,
			"shaders/simple_shader.vert.spv",
			"shaders/simple_shader.frag.spv",
			LvePipeline::DefaultPipelineConfigInfo(WIDTH, HEIGHT) };

	};


} // namespace lve
