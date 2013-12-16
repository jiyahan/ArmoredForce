--
-- Premake 4.x build configuration script
--

local BOOST_DIR = os.getenv("BOOST_DIR")

solution "LoginServer"
	configurations { "Release", "Debug" }
    location "LoginServer"
    targetdir "../Run/loginserver"
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

	-- LoginServer
	project "LoginServer"
		kind "ConsoleApp"
		defines 
		{
			"GOOGLE_GLOG_DLL_DECL=",
		}

		files
		{
			"../Server/LoginServer/**.h",
			"../Server/LoginServer/**.cpp",
			"../Server/Utility/**.h",
			"../Server/Utility/**.cpp",
            "../Server/RPC/ICenterRpcService.h",
			"../common/**.h",
		}
		
        pchheader "StdAfx.h"
		pchsource "StdAfx.cpp"
        
		includedirs 
		{ 			
			"../3rdParty/atom",
			"../3rdParty/RCF/include",
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
			"libmysqlpp",
			"libmysql",
		}
