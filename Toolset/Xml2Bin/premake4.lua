--
-- Premake4.x build configuration script
-- http://industriousone.com/scripting-premake
--


-- 读取xml转换为二进制
solution "Xml2Bin"
	configurations { "Release", "Debug" }
	language    "C++"
	flags       { "No64BitChecks", "StaticRuntime" }
	
	configuration "Debug"
        defines { "DEBUG" }
        flags { "Symbols" }

	configuration "Release"
        defines { "NDEBUG" }
        flags { "Optimize", "Symbols" }

	configuration "vs*"
		defines 
        { 
            "_CRT_SECURE_NO_WARNINGS",
        }
        buildoptions "-Zm200 /FI\"stdafx.h\""

    -- Test项目
	project "Xml2Bin"
		kind "ConsoleApp"
        uuid "3C53977F-705F-7746-9DB1-AD248EE761F0"
        defines
        {
            "MARKUP_STL",
            "GOOGLE_GLOG_DLL_DECL=",
            "GTEST_HAS_TR1_TUPLE=0",
        }
        
        -- 源代码文件
		files
		{
            "src/**.h",
            "src/**.cpp",            
            "../../common/setup/*.h",            
            "../../Server/Utility/Markup.h",
            "../../Server/Utility/Markup.cpp",
            "../../Server/Setup/LoadSetup.h",
            "../../Server/Setup/LoadSetup.cpp",
		}

        pchheader "stdafx.h"
		pchsource "src/stdafx.cpp"
        
        -- 包含目录
		includedirs 
		{ 			
            "../../Server/Utility",
            "../../3rdParty/atom",
		}
        
        libdirs 
        { 
            "../../3rdParty/libs", 
        }
		
		links 
		{
			"libatom",
		}
        
