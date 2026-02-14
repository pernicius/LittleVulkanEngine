#pragma once

#include <iostream>

#define LOG_INFO(msg)   { std::cout << "[INFO]   " << msg << std::endl; }
#define LOG_VULKAN(msg) { std::cout << "[VULKAN] " << msg << std::endl; }
#define LOG(msg)        { std::cout << "    " << msg << std::endl; }

#define LOG_ERROR(msg)  { std::cerr << "[ERROR]  " << msg << std::endl; }
