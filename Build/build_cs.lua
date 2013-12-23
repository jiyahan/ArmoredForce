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
	
	configuration "Debug"
        defines { "DEBUG" }
        flags { "Symbols" }

	configuration "Release"
        defines { "NDEBUG" }
        flags { "Optimize", "Symbols"}

	configuration "vs*"
        defines 
        { 
            "_CRT_SECURE_NO_WARNINGS",
        }
        buildoptions "-Zm200 /FI\"stdafx.h\""
        
    configuration "gmake"
        linkoptions "-lpthread -ldl"        

	-- CenterServer项目
	project "CenterServer"
		kind "ConsoleApp"
        uuid "755FAC6C-5706-A74D-8D5B-C88B7A728C90"
		defines 
		{
            "__CENTER_SERVER__",
            "MARKUP_STL",
			"GOOGLE_GLOG_DLL_DECL=",            
            "GLOG_NO_ABBREVIATED_SEVERITIES",
		}		

        -- 源代码文件
		files
		{
            "../common/setup/**.h",
            
            "../Server/Setup/*.h",
            "../Server/Setup/*.cpp",

			"../Server/CenterServer/**.h",
			"../Server/CenterServer/**.cpp",
            
			"../Server/Utility/Markup.h",
			"../Server/Utility/Markup.cpp",
            "../Server/Utility/Utility.h",
            "../Server/Utility/Utility.cpp",
            
            "../Server/RPC/ICenterRpcService.h",
         
		}

        -- 预编译头
        pchheader "stdafx.h"
		pchsource "../Server/CenterServer/stdafx.cpp"
        
        -- 包含目录
		includedirs 
		{ 
            "../",
            "../3rdParty/",
            "../Server/Utility/",
            "../3rdParty/atom/",
			"../3rdParty/glog/src/windows/",
			"../3rdParty/RCF/include/",
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
            "libatom",
		}
