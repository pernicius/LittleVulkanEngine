-------------------------
-- [DEPENDANCY HELPER] --
-------------------------


function Lib_GLM()
	includedirs "%{wks.location}/vendor/glm/"
	defines {
		"GLM_FORCE_MESSAGES",
--		"GLM_FORCE_RADIANS",

		-- Clip control, define GLM_FORCE_DEPTH_ZERO_TO_ONE before including GLM
		-- to use a clip space between 0 to 1.
--		"GLM_FORCE_DEPTH_ZERO_TO_ONE",

		-- Coordinate system, define GLM_FORCE_LEFT_HANDED before including GLM
		-- to use left handed coordinate system by default.
--		"GLM_FORCE_LEFT_HANDED",
	}
end


-----------------------
-- [ PROJECT CONFIG] --
-----------------------
project "vendor.glm"
	kind "None"
	
	-- move project in the correct dir
	basedir("vendor/glm")
	
	files {
--		"premake5_glm.lua",
		"vendor/glm/glm/**.*",
	}
