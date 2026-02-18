#include "pch.h"

#include "log.h"
#include "app.h"

#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <filesystem>

int main(int argc, char* argv[])
{
	// change cwd to path of the executable
	if (argc > 0) {
		std::filesystem::path exePath = std::filesystem::absolute(argv[0]);
		std::filesystem::current_path(exePath.parent_path());
		LOG_INFO("Current working directory changed to:");
		LOG("'" << std::filesystem::current_path().string() << "'");
	}

	LOG_INFO("----------[ INITIALIZATION ]----------");

	lve::App app{};

	LOG_INFO("----------[ RUN-LOOP ]----------");

	try {
		app.Run();
	}
	catch (const std::exception& e) {
		std::cerr << "ERROR: " << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	LOG_INFO("----------[ CLEANUP ]----------");

	return EXIT_SUCCESS;
}
