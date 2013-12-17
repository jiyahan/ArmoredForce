--
-- Premake4.x build configuration script
-- http://industriousone.com/scripting-premake
--

local BOOST_DIR = os.getenv("BOOST_DIR")


-- unittest和benchmark
solution "Test"
	configurations { "Release", "Debug" }
    location "Test"
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
        
    configuration "gmake"
        linkoptions "-lpthread -ldl"        

    -- Test项目
	project "Test"
		kind "ConsoleApp"
        uuid "3C53977F-705F-7746-9DB1-AD248EE761F0"
        
        -- 源代码文件
		files
		{
			"../Toolset/UnitTest/**.h",
			"../Toolset/UnitTest/**.cpp",
		}
        excludes
        {
        }  
        
        -- 预编译头
        pchheader "stdafx.h"
		pchsource "stdafx.cpp"        
		        
        -- 包含目录
		includedirs 
		{ 			
			"../3rdParty/atom",
			"../3rdParty/RCF/include",
            "../3rdParty/gtest/include",
			"../3rdParty/glog/src/windows/",
			"../3rdParty/libmysql/include",
			"../3rdParty/MySQL++/lib",
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
