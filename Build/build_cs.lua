--
-- Premake4.x build configuration script
-- http://industriousone.com/scripting-premake
--

local BOOST_DIR = os.getenv("BOOST_DIR")

-- CenterServer解决方案
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
        flags { "Optimize", "Symbols"}

	configuration "vs*"
        defines 
        { 
            "_CRT_SECURE_NO_WARNINGS",
        }
        buildoptions "-Zm200"
        
    configuration "gmake"
        linkoptions "-lpthread -ldl"        

	-- CenterServer项目
	project "CenterServer"
		kind "ConsoleApp"
        uuid "755FAC6C-5706-A74D-8D5B-C88B7A728C90"
		defines 
		{
            "__CENTER_SERVER__",
			"GOOGLE_GLOG_DLL_DECL=",
		}		

        -- 源代码文件
		files
		{
			"../Server/CenterServer/**.h",
			"../Server/CenterServer/**.cpp",
            "../Server/RPC/ICenterRpcService.h",
			"../Server/Utility/**.h",
			"../Server/Utility/**.cpp",            
		}
        excludes 
        {
            "../Server/Utility/MyConnectionPool.h",
            "../Server/Utility/MyConnectionPool.cpp",
        }
		
        -- 预编译头
        pchheader "stdafx.h"
		pchsource "../Server/CenterServer/stdafx.cpp"
        
        -- 包含目录
		includedirs 
		{ 
            "../3rdParty/folly",
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
			"librcf",
			"libglog",
		}
