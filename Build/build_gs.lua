--
-- Premake 4.x build configuration script
--

local BOOST_DIR = os.getenv("BOOST_DIR")

solution "GameServer"
	configurations { "Release", "Debug" }
    location "GameServer" 
    targetdir "../Run/gameserver"
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
            
    configuration "gmake"
        defines {}

	-- GameServer
	project "GameServer"
		kind "ConsoleApp"
		defines 
		{
			"GOOGLE_GLOG_DLL_DECL=",
		}

		files
		{
			"../Server/GameServer/**.h",
			"../Server/GameServer/**.cpp",
			"../Server/Utility/**.h",
			"../Server/Utility/**.cpp",
            "../Server/RPC/ICenterRpcService.h",
            "../common/**.h",
		}
		
        pchheader "StdAfx.h"
		pchsource "StdAfx.cpp"
        
		includedirs 
		{
            "../3rdParty/atom/", 
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
            "libAtom",
			"librcf",
			"libglog",
		}			
