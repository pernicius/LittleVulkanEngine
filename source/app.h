#pragma once

#include "lve_device.h"
#include "lve_pipeline.h"
#include "lve_swapchain.h"
#include "lve_window.h"

namespace lve {


	class App
	{
	public:
		App();
		~App();

		App(const App&) = delete;
		App& operator=(const App&) = delete;

		void Run();

	private:
		void CreatePipelineLayout();
		void CreatePipeline();
		void CreateCommandBuffers();
		void DrawFrame();

	private:
		static constexpr int WIDTH = 800;
		static constexpr int HEIGHT = 600;

		LveWindow m_lveWindow{ WIDTH, HEIGHT, "Hello Vulkan!" };
		LveDevice m_lveDevice{ m_lveWindow };
		LveSwapChain m_lveSwapChain{ m_lveDevice, m_lveWindow.GetExtent() };
		std::unique_ptr<LvePipeline> m_lvePipeline;
		VkPipelineLayout m_pipelineLayout;
		std::vector<VkCommandBuffer> m_commandBuffers;
	};


} // namespace lve
