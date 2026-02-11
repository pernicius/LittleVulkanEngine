----------------------
-- [PROJECT CONFIG] --
----------------------
project "lve"
	language              "C++"
	cppdialect            "C++20"
	staticruntime         "On"
	kind                  "ConsoleApp"

	dir_project = ("%{string.lower(prj.name)}" .. "/")
	targetdir   (dir_bin   .. dir_group .. dir_config .. dir_project)
	objdir      (dir_build .. dir_group .. dir_config .. dir_project)
	
	basedir("source")

--	pchheader "pch.h"
--	pchsource "pch.cpp"

	files {
		"premake5_lve.lua",
		"source/**.c",
		"source/**.cpp",
		"source/**.h",
		"source/**.hpp",
		"source/**.glsl",
		"source/**.spv",
	}
	
	Lib_GLM{}
	Lib_GLFW{}

	-- Vulkan stuff
	includedirs "%VULKAN_SDK%/Include"
	libdirs     "%VULKAN_SDK%/Lib"
	links       "vulkan-1"
	
	-- Debug/Release Configuration
	filter "configurations:Debug"
		defines {
		}
	filter "configurations:Release"
		defines {
		}
	filter {}

	-- Shader compilation (GLSL -> SPIR-V (glslangValidator) -> HLSL (spirv-cross) -> DXIL/CSO (dxc))
	filter { "system:windows", "files:**.glsl" }
		buildmessage "Compiling %{file.name} -> %{file.basename}.spv"
		buildcommands {
			"\"%{(os.getenv('VULKAN_SDK') .. '/Bin/glslangValidator.exe')}\" -V \"%{file.relpath}\" -o \"%{(cfg.buildtarget.directory .. '/shaders/' .. file.basename)}.spv\"",
			-- glslangValidator.exe leaves *.spv files in the working directory
			"del *.spv",
		}
		buildoutputs {
			"%{(cfg.buildtarget.directory .. '/shaders/' .. file.basename)}.spv",
		}
	filter {}
