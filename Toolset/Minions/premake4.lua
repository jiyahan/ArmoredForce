--
-- Premake4.x build configuration script
-- http://industriousone.com/scripting-premake
--

local BOOST_DIR = os.getenv('BOOST_DIR')

-- 机器人程序
solution "Minions"
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
        buildoptions "-Zm200 /FI\"stdafx.h\" /wd\"4996\"" 

    project "Minions"
        kind "ConsoleApp"
        uuid "0A9699F1-69F2-40E6-AEB9-A81CB4AF2CE2"
        buildoptions '/I"../../"'
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
            
            "../../Server/Script/Message.h",
            "../../Server/Script/Message.cpp",
            "../../Server/Script/LuaVM.h",
            "../../Server/Script/LuaVM.cpp",
            
            "../../Server/Utility/Markup.h",
            "../../Server/Utility/Markup.cpp",
            "../../Server/Utility/Utility.h",
            "../../Server/Utility/Utility.cpp",
           
        }

        pchheader "stdafx.h"
        pchsource "src/stdafx.cpp"
        
        -- 包含目录
        includedirs 
        { 
            "../../Server/Utility",
            "../../3rdParty/atom",
            "../../3rdParty/lua/src",
            BOOST_DIR,
        }
        
        libdirs 
        { 
            "../../3rdParty/libs", 
        }
        
        links 
        {
            "libatom",
            "liblua",
        }
        
