--
-- Premake4.x build configuration script
-- http://industriousone.com/scripting-premake
--

local BOOST_DIR = os.getenv("BOOST_DIR")

--
-- CenterServer解决方案
--
solution "CenterServer"
    configurations { "Release", "Debug" }
    location "CenterServer"
    targetdir "../../Run/centerserver"
    language    "C++"
    flags       { "StaticRuntime" }

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
        buildoptions '/I"../../../"'
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
            "../../common/setup/**.h",

            "../Setup/*.h",
            "../Setup/*.cpp",

            "../CenterServer/**.h",
            "../CenterServer/**.cpp",

            "../Utility/Markup.h",
            "../Utility/Markup.cpp",
            "../Utility/Utility.h",
            "../Utility/Utility.cpp",

            "../RPC/ICenterRpcService.h",
        }

        -- 预编译头
        pchheader "stdafx.h"
        pchsource "../CenterServer/stdafx.cpp"

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
            "librcf",
            "libglog",
            "libatom",
        }
