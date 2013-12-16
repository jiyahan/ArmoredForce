--
-- Premake 4.x build configuration script
--

local BOOST_DIR = os.getenv("BOOST_DIR")

solution "DBServer"
	configurations { "Release", "Debug" }
    location "DBServer" 
    targetdir "../Run/dbserver"
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
        linkoptions "/INCREMENTAL:NO"

	-- DBServer
	project "DBServer"
		kind "ConsoleApp"
		defines 
		{
			"GOOGLE_GLOG_DLL_DECL=",
            "MARKUP_STL",
		}

		files
		{
			"../Server/DBServer/**.h",
			"../Server/DBServer/**.cpp",
			"../Server/Utility/**.h",
			"../Server/Utility/**.cpp",
            "../Server/RPC/IDBRpcService.h",
		}
		
        pchheader "StdAfx.h"
		pchsource "StdAfx.cpp"
        
		includedirs 
		{ 
			"../3rdParty/glog/src/windows/",
			"../3rdParty/libmysql/include",
			"../3rdParty/MySQL++/include",
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
			"libmysql",
			"libmysqlpp",
			"librcf",
			"libglog",
		}			
