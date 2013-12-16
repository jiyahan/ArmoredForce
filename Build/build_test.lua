--
-- Premake 4.x build configuration script
--

local BOOST_DIR = os.getenv("BOOST_DIR")

solution "UnitTest"
	configurations { "Release", "Debug" }
    location "UnitTest"
	language    "C++"
	flags       { "No64BitChecks", "StaticRuntime" }
	
	configuration "debug"
        defines { "DEBUG" }
        flags { "Symbols" }

	configuration "release"
        defines { "NDEBUG" }
        flags { "Optimize", "Symbols" }

	configuration "vs*"
		defines 
        { 
            "_CRT_SECURE_NO_WARNINGS",
        }
        buildoptions "-Zm200"
        linkoptions "/INCREMENTAL:NO"

	project "UnitTest"
		kind "ConsoleApp"
		defines 
		{
		}

		files
		{
			"../Toolset/UnitTest/**.h",
			"../Toolset/UnitTest/**.cpp",
		}
		
        pchheader "StdAfx.h"
		pchsource "StdAfx.cpp"
        
		includedirs 
		{ 			
			"../3rdParty/atom",
			"../3rdParty/RCF/include",
            "../3rdParty/gtest/include",
			"../3rdParty/glog/src/windows/",
			"../3rdParty/libmysql/include",
			"../3rdParty/MySQL++/include",
			BOOST_DIR,
		}
        
        libdirs 
        { 
            "../3rdParty/libs", 
            BOOST_DIR .. '/stage/lib',
        }
		
		links 
		{
			"librcf",
			"libAtom",
			"libglog",
            "libgtest",
			"libmysqlpp",
			"libmysql",
		}
