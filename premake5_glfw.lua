-- TODO: how to use/import a cmake project?
-- TODO: how to use/import a cmake project?
-- TODO: how to use/import a cmake project?


-------------------------
-- [DEPENDANCY HELPER] --
-------------------------
function Lib_GLFW()
	includedirs "%{wks.location}/vendor/glfw/include/"
	defines "GLFW_INCLUDE_NONE"

	filter "kind:*App"
		links "vendor.glfw"
	filter {}
end


-----------------------
-- [ PROJECT CONFIG] --
-----------------------
project "vendor.glfw"
	kind          "StaticLib"
	architecture  "x86_64"
	language      "C"
	cppdialect    "C++20"
	staticruntime "On"
	targetname    "glfw3"
	
	dir_project = "%{string.lower(prj.name)}"
	targetdir (dir_bin   .. dir_group .. dir_config .. dir_project)
	objdir    (dir_build .. dir_group .. dir_config .. dir_project)

	-- move project in the correct dir
	basedir("vendor/glfw")
	
	includedirs {
		"vendor/glfw/include",
		"vendor/glfw/src"
	}
	
	files {
--		"premake5_glfw.lua",
		"vendor/glfw/include/GLFW/glfw3.h",
		"vendor/glfw/include/GLFW/glfw3native.h",
		"vendor/glfw/src/internal.h",
		"vendor/glfw/src/platform.h",
		"vendor/glfw/src/mappings.h",
		"vendor/glfw/src/context.c",
		"vendor/glfw/src/init.c",
		"vendor/glfw/src/input.c",
		"vendor/glfw/src/monitor.c",
		"vendor/glfw/src/platform.c",
		"vendor/glfw/src/vulkan.c",
		"vendor/glfw/src/window.c",
		"vendor/glfw/src/egl_context.c",
		"vendor/glfw/src/osmesa_context.c",
		"vendor/glfw/src/null_platform.h",
		"vendor/glfw/src/null_joystick.h",
		"vendor/glfw/src/null_init.c",
		"vendor/glfw/src/null_monitor.c",
		"vendor/glfw/src/null_window.c",
		"vendor/glfw/src/null_joystick.c"
	}

--[[
	TODO: >>>>>> I CAN'T TEST THIS PART <<<<<<
	TODO: >>>>>> I CAN'T TEST THIS PART <<<<<<
	TODO: >>>>>> I CAN'T TEST THIS PART <<<<<<

	filter "system:linux"
		pic "On"
		systemversion "latest"
		staticruntime "On"

		files {
			-- !APPLE && !WIN32
			"vendor/glfw/src/posix_time.h",
			"vendor/glfw/src/posix_thread.h",
			"vendor/glfw/src/posix_module.c",
			"vendor/glfw/src/posix_time.c",
			"vendor/glfw/src/posix_thread.c".
			-- GLFW_BUILD_X11
			"vendor/glfw/x11_platform.h",
			"vendor/glfw/src/xkb_unicode.h",
			"vendor/glfw/src/x11_init.c",
			"vendor/glfw/src/x11_monitor.c",
			"vendor/glfw/src/x11_window.c",
			"vendor/glfw/src/xkb_unicode.c",
			"vendor/glfw/src/glx_context.c",
			-- "Linux"
			"vendor/glfw/src/linux_joystick.h"
			"vendor/glfw/src/linux_joystick.c",
			-- GLFW_BUILD_WAYLAND
			"vendor/glfw/src/wl_platform.h"
			"vendor/glfw/src/wl_init.c"
			"vendor/glfw/src/wl_monitor.c"
			"vendor/glfw/src/wl_window.c"
			-- GLFW_BUILD_X11 OR GLFW_BUILD_WAYLAND
			"vendor/glfw/src/posix_poll.h",
			"vendor/glfw/src/posix_poll.c"
		}

		defines {
			"_GLFW_X11",
			"_DEFAULT_SOURCE"
		}

	TODO: >>>>>> I CAN'T TEST THIS PART <<<<<<
	TODO: >>>>>> I CAN'T TEST THIS PART <<<<<<
	TODO: >>>>>> I CAN'T TEST THIS PART <<<<<<
]]--

	filter "system:windows"
		systemversion "latest"
		staticruntime "On"

		files {
			-- WIN32
			"vendor/glfw/src/win32_time.h",
			"vendor/glfw/src/win32_thread.h",
			"vendor/glfw/src/win32_module.c",
			"vendor/glfw/src/win32_time.c",
			"vendor/glfw/src/win32_thread.c",
			-- GLFW_BUILD_WIN32
			"vendor/glfw/src/win32_platform.h",
			"vendor/glfw/src/win32_joystick.h",
			"vendor/glfw/src/win32_init.c",
			"vendor/glfw/src/win32_joystick.c",
			"vendor/glfw/src/win32_monitor.c",
			"vendor/glfw/src/win32_window.c",
			"vendor/glfw/src/wgl_context.c"
		}

		defines {
			"_GLFW_WIN32",
			"UNICODE", "_UNICODE",
			"_CRT_SECURE_NO_WARNINGS"
		}

--[[
	TODO: >>>>>> I CAN'T TEST THIS PART <<<<<<
	TODO: >>>>>> I CAN'T TEST THIS PART <<<<<<
	TODO: >>>>>> I CAN'T TEST THIS PART <<<<<<

	filter "system:macosx"

		files {
			-- APPLE
			vendor/glfw/src/cocoa_time.h,
			vendor/glfw/src/cocoa_time.c,
			vendor/glfw/src/posix_thread.h,
			vendor/glfw/src/posix_module.c,
			vendor/glfw/src/posix_thread.c,
			-- GLFW_BUILD_COCOA
			vendor/glfw/src/cocoa_platform.h,
			vendor/glfw/src/cocoa_joystick.h,
			vendor/glfw/src/cocoa_init.m,
			vendor/glfw/src/cocoa_joystick.m,
			vendor/glfw/src/cocoa_monitor.m,
			vendor/glfw/src/cocoa_window.m,
			vendor/glfw/src/nsgl_context.m
		}

		defines {
			_GLFW_COCOA
		}

	TODO: >>>>>> I CAN'T TEST THIS PART <<<<<<
	TODO: >>>>>> I CAN'T TEST THIS PART <<<<<<
	TODO: >>>>>> I CAN'T TEST THIS PART <<<<<<
]]--

	filter "configurations:Debug"
		runtime "Debug"
		symbols "On"
		
	filter "configurations:Release"
		runtime "Release"
		optimize "On"
		
	filter {}
