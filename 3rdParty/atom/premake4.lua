
solution "atom"
	configurations { "debug", "release" }
	platforms { "x32", "x64" }
	
	language "C++"
	flags { "ExtraWarnings" }
	
	project "libAtom"
		kind "StaticLib"
		files 
		{ 
			"atom/**.h",
			"atom/**.cpp",
			"atom/**.c",
			"electron/**.h",
			"electron/**.cpp",
			"electron/**.c",
		}
