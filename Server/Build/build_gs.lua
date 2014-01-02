--
-- Premake4.x build configuration script
-- http://industriousone.com/scripting-premake
--

local BOOST_DIR = os.getenv("BOOST_DIR")

-- GameServer解决方案
solution "GameServer"
    configurations { "Release", "Debug" }
    location "GameServer"
    targetdir "../../Run/gameserver"
    language    "C++"
    flags       { "StaticRuntime" }

    configuration "Debug"
        defines { "DEBUG" }
        flags { "Symbols" }

    configuration "Release"
        defines { "NDEBUG" }
        flags { "Optimize" }

    configuration "vs*"
        defines
        {
            "_USING_V110_SDK71_",
            "_CRT_SECURE_NO_WARNINGS",
        }
        buildoptions "-Zm200 /FI\"stdafx.h\" /wd\"4996\""

    configuration "gmake"
        linkoptions "-lpthread -ldl"

    -- GameServer项目
    project "GameServer"
        kind "ConsoleApp"
        uuid "7C68D073-DD0F-C84B-BBD5-9941309F6D52"
        buildoptions '/I"../../../"'
        defines
        {
            "__GAME_SERVER__",
            "MARKUP_STL",
            "GOOGLE_GLOG_DLL_DECL=",
            "GLOG_NO_ABBREVIATED_SEVERITIES",
        }

        -- 源代码文件
        files
        {
            "../../common/**.h",
            "../../common/**.cpp",

            "../Utility/Markup.h",
            "../Utility/Markup.cpp",
            "../Utility/Utility.h",
            "../Utility/Utility.cpp",

            "../GameServer/**.h",
            "../GameServer/**.cpp",

            "../Setup/LoadSetup.h",
            "../Setup/LoadSetup.cpp",

            "../RPC/ICenterRpcService.h",
        }

        -- 预编译头
        pchheader "stdafx.h"
        pchsource "../GameServer/stdafx.cpp"

        -- 包含目录
        includedirs
        {
            "../Utility",
            "../../3rdParty/",
            "../../3rdParty/atom/",
            "../../3rdParty/glog/src/windows/",
            "../../3rdParty/RCF/include/",
            BOOST_DIR,
        }

        -- 库目录
        libdirs
        {
            "../../3rdParty/libs",
            BOOST_DIR .. '/stage/lib',
        }

        links
        {
            "libAtom",
            "librcf",
            "libglog",
        }
