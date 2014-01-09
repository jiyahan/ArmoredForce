--
-- Premake4.x build configuration script
-- http://industriousone.com/scripting-premake
--

local BOOST_DIR = os.getenv('BOOST_DIR')

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
        buildoptions '/I"../../"'
        defines
        {
            "MARKUP_STL",                       
            "GTEST_HAS_TR1_TUPLE=0",
            "NOT_USE_ATOM_ALLOCATOR",
        }
        
        -- 源代码文件
        files
        {
            "src/**.h",
            "src/**.cpp",      
            
            "../../common/setup/*.h",
            "../../common/setup/*.cpp",
            
            "../../Server/Utility/Markup.h",
            "../../Server/Utility/Markup.cpp",
            "../../Server/Utility/Utility.h",
            "../../Server/Utility/Utility.cpp",
            
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
            "../../3rdParty/glog/src/windows/",
            BOOST_DIR,
        }
        
        libdirs 
        { 
            "../../3rdParty/libs", 
            BOOST_DIR .. '/stage/lib',
        }
        
        links 
        {
            "libatom",
            "libglog",
        }
        
