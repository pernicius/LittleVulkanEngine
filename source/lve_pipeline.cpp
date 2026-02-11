#include "pch.h"
#include "lve_pipeline.h"

#include "log.h"

#include <fstream>
#include <iostream>
#include <stdexcept>

namespace lve {


	LvePipeline::LvePipeline(const std::string& vertFilepath, const std::string& fragFilepath)
	{
		LOG_INFO("Creating graphics pipeline...");

		CreateGraphicsPipeline(vertFilepath, fragFilepath);

		LOG_INFO("Graphics pipeline created.");
	}


	LvePipeline::~LvePipeline()
	{
		LOG_INFO("Destroying graphics pipeline...");
		// Cleanup code for the graphics pipeline would go here
		LOG_INFO("Graphics pipeline destroyed.");
	}


	std::vector<char> LvePipeline::ReadFile(const std::string& filepath)
	{
		std::ifstream file{ filepath, std::ios::ate | std::ios::binary };

		if (!file.is_open()) {
			throw std::runtime_error("failed to open file: " + filepath);
		}

		size_t fileSize = static_cast<size_t>(file.tellg());
		std::vector<char> buffer(fileSize);

		file.seekg(0);
		file.read(buffer.data(), fileSize);

		file.close();
		return buffer;
	}


	void LvePipeline::CreateGraphicsPipeline(const std::string& vertFilepath, const std::string& fragFilepath)
	{
		auto vertCode = ReadFile(vertFilepath);
		auto fragCode = ReadFile(fragFilepath);

		LOG_INFO("Vertex Shader Code Size: " << vertCode.size());
		LOG_INFO("Fragment Shader Code Size: " << fragCode.size());
	}


}  // namespace lve
