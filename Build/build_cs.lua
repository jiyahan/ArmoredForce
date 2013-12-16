--
-- Premake 4.x build configuration script
--

local BOOST_DIR = os.getenv("BOOST_DIR")

solution "CenterServer"
	configurations { "Release", "Debug" }
    location "CenterServer" 
    targetdir "../Run/centerserver"
	language    "C++"
	flags       { "No64BitChecks", "StaticRuntime" }
	
	configuration "debug"
        defines { "DEBUG" }
        flags { "Symbols" }

	configuration "release"
        defines { "NDEBUG" }
        flags { "Optimize" }

	configuration "vs*"
        defines 
        { 
            "_CRT_SECURE_NO_WARNINGS",
        }
        buildoptions "-Zm200"

	-- CenterServer
	project "CenterServer"
		kind "ConsoleApp"
		defines 
		{
			"GOOGLE_GLOG_DLL_DECL=",
		}		

		files
		{
			"../Server/CenterServer/**.h",
			"../Server/CenterServer/**.cpp",
			"../Server/Utility/**.h",
			"../Server/Utility/**.cpp",
            "../Server/RPC/ICenterRpcService.h",
		}
		
        pchheader "StdAfx.h"
		pchsource "StdAfx.cpp"
        
		includedirs 
		{ 
			"../3rdParty/glog/src/windows/",
			"../3rdParty/RCF/include",
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
			"libglog",
		}			
