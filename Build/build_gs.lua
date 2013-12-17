--
-- Premake4.x build configuration script
-- http://industriousone.com/scripting-premake
--

local BOOST_DIR = os.getenv("BOOST_DIR")

-- GameServer解决方案
solution "GameServer"
	configurations { "Release", "Debug" }
    location "GameServer" 
    targetdir "../Run/gameserver"
	language    "C++"
	flags       { "No64BitChecks", "StaticRuntime" }
    uuid "8BC9CEB8-8B4A-11D0-8D11-00A0C91BC942"
	
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
        linkoptions "-lpthread -ldl"

	-- GameServer项目
	project "GameServer"
		kind "ConsoleApp"
        uuid "7C68D073-DD0F-C84B-BBD5-9941309F6D52"
		defines 
		{
            "__GAME_SERVER__",
			"GOOGLE_GLOG_DLL_DECL=",
		}

        -- 源代码文件
		files
		{
			"../Server/GameServer/**.h",
			"../Server/GameServer/**.cpp",
			"../Server/Utility/**.h",
			"../Server/Utility/**.cpp",
            "../Server/RPC/ICenterRpcService.h",
            "../common/**.h",
		}
        excludes 
        {
            "../Server/Utility/MyConnectionPool.h",
            "../Server/Utility/MyConnectionPool.cpp",
        }        
        excludes
        {
        }		
        -- 预编译头
        pchheader "stdafx.h"
		pchsource "../Server/GameServer/stdafx.cpp"
        
        -- 包含目录
		includedirs 
		{
            "../3rdParty/folly",
            "../3rdParty/atom/",             
			"../3rdParty/glog/src/windows/",
			"../3rdParty/RCF/include",
			BOOST_DIR,
		}        
		
        -- 库目录
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
