#pragma once

#include <string>
#include <vector>

namespace lve {


	class LvePipeline
	{
	public:
		LvePipeline(const std::string& vertFilepath, const std::string& fragFilepath);
		~LvePipeline();

	private:
		static std::vector<char> ReadFile(const std::string& filepath);
		void CreateGraphicsPipeline(const std::string& vertFilepath, const std::string& fragFilepath);
	};


}  // namespace lve
