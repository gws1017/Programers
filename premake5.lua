workspace "Programers"
	architecture "x64"
	startproject "1_1"

	configurations
	{
		"Debug",
		"Release"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.architecture}"

IncludeDir = {}

group "Dependencies"
group ""

include "1_1"
include "1_2"
