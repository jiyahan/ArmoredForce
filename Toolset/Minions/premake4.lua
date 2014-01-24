--
-- Premake4.x build configuration script
-- http://industriousone.com/scripting-premake
--

local BOOST_DIR = os.getenv('BOOST_DIR')

solution "Minions"
    configurations { "Release", "Debug" }
    language    "C++"
    targetdir   "bin"
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
            "_WIN32_WINNT=0x0502",
        }
        

    project "Minions"
        kind "ConsoleApp"
        uuid "FCB57495-BF77-44E3-9D5B-152CF5ADF10C"
        buildoptions "-Zm200 /FI\"pch.h\" /wd\"4996\"" 
        defines
        {
        }
        
        -- 源代码文件
        files
        {
            "src/**.h",
            "src/**.cpp",
            "src/**.c",
            
            "../../Server/Utility/easylogging++.h",
            "../../Server/Utility/Utility.h",
            "../../Server/Utility/Utility.cpp",
        }

        pchheader "pch.h"
        pchsource "src/pch.cpp"
        
        -- 包含目录
        includedirs 
        {
            "../../3rdParty/atom",
            "../../3rdParty/lua/src",
            "../../Server/Utility",
            BOOST_DIR,
        }
        
        libdirs 
        {
            "../../3rdParty/libs",
            BOOST_DIR .. '/stage/lib',
        }
        
        links 
        {            
            "ws2_32",
            "mswsock",
            "liblua",
            "libatom",
        }
    
    -- Lua
    project "liblua"
        kind "StaticLib"
        uuid "80B63F61-585A-49CC-B70F-71E13B1D1D9C"
        language "C"
        defines
        {
        }
        
        files
        {
            "../../3rdParty/lua/src/*.h",
            "../../3rdParty/lua/src/*.c",
        }
        excludes 
        {
            "../../3rdParty/lua/src/lua.c",
            "../../3rdParty/lua/src/luac.c",
            "../../3rdParty/lua/src/print.c",
        }
        includedirs 
        {
            "../../3rdParty/lua/src/",
        }           
