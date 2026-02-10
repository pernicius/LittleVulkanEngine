printf("");
printf("Premake version: '%s'", _PREMAKE_VERSION)
printf("Premake target:  '%s'", _TARGET_OS)
printf("Premake action:  '%s'", _ACTION)
printf("");

---------------------------------
-- [ WORKSPACE CONFIGURATION ] --
---------------------------------
workspace "LittleVulkanEngine"

	architecture "x86_64"

	configurations {
		"Debug",
		"Release"
	}

	platforms {
		"Windows",
--		"Linux",
--		"MacOS"
	}
	
	defaultplatform "Windows"
	startproject "lve"

	--------------------------------
	-- [ PLATFORM CONFIGURATION ] --
	--------------------------------
	filter "platforms:Windows"
		system  "windows"
	filter "platforms:Linux"
		system  "linux"
	filter "platforms:MacOS"
		system  "macosx"

	-- Windows/MSVC only
	filter { "system:windows", "action:vs*" }
		multiprocessorcompile ("On")
		minimalrebuild ("Off")
		systemversion "latest"
		-- required by spdlog
		buildoptions "/utf-8"

	filter {}

	-------------------------------------
	-- [ DEBUG/RELEASE CONFIGURATION ] --
	-------------------------------------
	filter "configurations:Debug"
		defines {
			"BUILD_DEBUG",
			"_DEBUG",
		}
		symbols  "On"
		runtime  "Debug"
		fatalwarnings "All"

		optimize "Off"

	filter "configurations:Release"
		defines {
			"BUILD_RELEASE",
			"NDEBUG",
		}
		symbols  "Off"
		runtime  "Release"
		fatalwarnings "All"

		optimize "Off"
--		optimize "On"
--		optimize "Speed"
--		optimize "Full"

	filter {}

	-------------------------------
	-- [ PROJECT CONFIGURATION ] --
	-------------------------------
	dir_bin    = (path.join("%{wks.location}", "_bin") .. "/")
	dir_build  = (path.join("%{wks.location}", "_build") .. "/")
	dir_config = ("%{string.lower(cfg.platform)}-%{string.lower(cfg.buildcfg)}" .. "/")

--	include("premake5_misc.lua")
	group "Vendor"
		dir_group = ("vendor" .. "/")
--		include("vendor/dev-tools/premake/")
		include("premake5_glm.lua")
		include("premake5_glfw.lua")
	group "LVE"
		dir_group = ("lve" .. "/")
		include("premake5_lve.lua")
--	group "Docs"
--		dir_group = ("docs" .. "/")
--		include("premake5_docs.lua")
	group ""
