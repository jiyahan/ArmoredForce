--
-- Premake4.x build configuration script
-- http://industriousone.com/scripting-premake
--

local BOOST_DIR = os.getenv('BOOST_ROOT')

-- 测试客户端
solution "ClientTest"
    configurations { "Release", "Debug" }
    targetdir   "bin"
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

    project "ClientTest"
        location ("msvc")
        kind "ConsoleApp"
        uuid "0A9699F1-69F2-40E6-AEB9-A81CB4AF2CE2"
        buildoptions "" 
        buildoptions '/I"../../../" -Zm200 /FI"stdafx.h" /wd"4996" '
        defines
        {
            "MARKUP_STL",
            "GOOGLE_GLOG_DLL_DECL=",
            "GLOG_NO_ABBREVIATED_SEVERITIES",
            "GTEST_HAS_TR1_TUPLE=0",
        }
        
        -- 源代码文件
        files
        {
            "src/**.h",
            "src/**.cpp",      
            
            "../../common/**.h",
            "../../common/**.cpp",
            
            "../../Server/Utility/Markup.h",
            "../../Server/Utility/Markup.cpp",
            "../../Server/Utility/Utility.h",
            "../../Server/Utility/Utility.cpp",
            "../../Server/Utility/easylogging.h",
        }

        pchheader "stdafx.h"
        pchsource "src/stdafx.cpp"
        
        -- 包含目录
        includedirs 
        { 
            "../../Server/Utility",
            "../../3rdParty/atom",            
            BOOST_DIR,
        }
        
        libdirs 
        { 
            "../../3rdParty/libs", 
        }
        
        links 
        {
            "libatom",
        }
        
