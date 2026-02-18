#include "pch.h"
#include "app.h"

#include "log.h"

#include <memory>
#include <vector>

namespace lve {
	
	
	App::App()
	{
		LOG_INFO("App created.");

		CreatePipelineLayout();
		CreatePipeline();
		CreateCommandBuffers();
	}
	
	
	App::~App()
	{
		vkDestroyPipelineLayout(m_lveDevice.Device(), m_pipelineLayout, nullptr);

		LOG_INFO("App destroyed.");
	}


	void App::Run()
	{
		LOG_INFO("Run loop entered.");

		while (!m_lveWindow.ShouldClose()) {
			glfwPollEvents();
		}
		vkDeviceWaitIdle(m_lveDevice.Device());
		
		LOG_INFO("Run loop exited.");
	}


	void App::CreatePipelineLayout()
	{
		VkPipelineLayoutCreateInfo pipelineLayoutInfo{};
		pipelineLayoutInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
		pipelineLayoutInfo.setLayoutCount = 0;
		pipelineLayoutInfo.pSetLayouts = nullptr;
		pipelineLayoutInfo.pushConstantRangeCount = 0;
		pipelineLayoutInfo.pPushConstantRanges = nullptr;
		if (vkCreatePipelineLayout(m_lveDevice.Device(), &pipelineLayoutInfo, nullptr, &m_pipelineLayout) != VK_SUCCESS) {
			throw std::runtime_error("failed to create pipeline layout!");
		}
	}


	void App::CreatePipeline()
	{
		auto pipelineConfig = LvePipeline::DefaultPipelineConfigInfo(m_lveSwapChain.Width(), m_lveSwapChain.Height());
		pipelineConfig.renderPass = m_lveSwapChain.GetRenderPass();
		pipelineConfig.pipelineLayout = m_pipelineLayout;
		m_lvePipeline = std::make_unique<LvePipeline>(
			m_lveDevice,
			"shaders/simple_shader.vert.spv",
			"shaders/simple_shader.frag.spv",
			pipelineConfig);
	}


	void App::CreateCommandBuffers()
	{
		m_commandBuffers.resize(m_lveSwapChain.ImageCount());

		VkCommandBufferAllocateInfo allocInfo{};
		allocInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
		allocInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
		allocInfo.commandPool = m_lveDevice.GetCommandPool();
		allocInfo.commandBufferCount = static_cast<uint32_t>(m_commandBuffers.size());

		if (vkAllocateCommandBuffers(m_lveDevice.Device(), &allocInfo, m_commandBuffers.data()) != VK_SUCCESS) {
			throw std::runtime_error("failed to allocate command buffers!");
		}

		for (int i = 0; i < m_commandBuffers.size(); i++) {
			VkCommandBufferBeginInfo beginInfo{};
			beginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;

			if (vkBeginCommandBuffer(m_commandBuffers[i], &beginInfo) != VK_SUCCESS) {
				throw std::runtime_error("failed to begin recording command buffer!");
			}

			VkRenderPassBeginInfo renderPassInfo{};
			renderPassInfo.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
			renderPassInfo.renderPass = m_lveSwapChain.GetRenderPass();
			renderPassInfo.framebuffer = m_lveSwapChain.GetFrameBuffer(i);

			renderPassInfo.renderArea.offset = { 0, 0 };
			renderPassInfo.renderArea.extent = m_lveSwapChain.GetSwapChainExtent();

			std::array<VkClearValue, 2> clearValues{};
			clearValues[0].color = { 0.1f, 0.1f, 0.1f, 1.0f };
			clearValues[1].depthStencil = { 1.0f, 0 };
			renderPassInfo.clearValueCount = static_cast<uint32_t>(clearValues.size());
			renderPassInfo.pClearValues = clearValues.data();

			vkCmdBeginRenderPass(m_commandBuffers[i], &renderPassInfo, VK_SUBPASS_CONTENTS_INLINE);

			m_lvePipeline->Bind(m_commandBuffers[i]);
			vkCmdDraw(m_commandBuffers[i], 3, 1, 0, 0);

			vkCmdEndRenderPass(m_commandBuffers[i]);
			if (vkEndCommandBuffer(m_commandBuffers[i]) != VK_SUCCESS) {
				throw std::runtime_error("failed to record command buffer!");
			}
		}
	}


	void App::DrawFrame()
	{
		uint32_t imageIndex;
		auto result = m_lveSwapChain.AcquireNextImage(&imageIndex);
		if (result != VK_SUCCESS && result != VK_SUBOPTIMAL_KHR) {
			throw std::runtime_error("failed to acquire swap chain image!");
		}

		result = m_lveSwapChain.SubmitCommandBuffers(&m_commandBuffers[imageIndex], &imageIndex);
		if (result != VK_SUCCESS) {
			throw std::runtime_error("failed to present swap chain image!");
		}
	}


} // namespace lve

