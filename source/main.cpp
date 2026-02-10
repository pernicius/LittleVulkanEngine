#include "pch.h"

#include "app.h"

#include <cstdlib>
#include <iostream>
#include <stdexcept>

int main()
{
	lve::App app{};

	try {
		app.Run();
	}
	catch (const std::exception& e) {
		std::cerr << "ERROR: " << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
