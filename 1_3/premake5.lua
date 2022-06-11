project "1_3"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "On"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp",
	}

	includedirs
	{
		"src",
		"vendor/spdlog/include",
	}

	links
	{
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines "1_3DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "1_3RELEASE"
		optimize "On"