--
-- Premake4.x build configuration script
-- http://industriousone.com/scripting-premake
--

local BOOST_DIR = os.getenv("BOOST_DIR")

--
-- LoginServer解决方案
--
solution "LoginServer"
    configurations { "Release", "Debug" }
    location "LoginServer"
    targetdir "../../Run/loginserver"
    language    "C++"
    platforms { "x32", "x64" }
    flags       { "StaticRuntime" }

    configuration "Debug"
        defines { "DEBUG" }
        flags { "Symbols" }

    configuration "Release"
        defines { "NDEBUG" }
        flags { "Optimize", "Symbols" }

    configuration "vs*"
        defines
        {
            "WIN32_LEAN_AND_MEAN",
            "_CRT_SECURE_NO_WARNINGS",
        }
        buildoptions "-Zm200 /FI\"stdafx.h\" /wd\"4996\""

    configuration "gmake"
        linkoptions "-lpthread -ldl"

    -- LoginServer项目
    project "LoginServer"
        kind "ConsoleApp"
        uuid "2A54CE18-82AB-7246-8653-EFF4A3FB9BC8"
        buildoptions '/I"../../../"'
        defines
        {
            "__LOGIN_SERVER__",
            "MARKUP_STL",
            "MYSQLPP_NO_DLL",
            "RCF_USE_BOOST_ASIO",
            "NOT_USE_ATOM_ALLOCATOR",
        }

        -- 源代码文件
        files
        {
            "../../common/MESSAGE_ID.h",
            "../../common/MSGCode.h",
            "../../common/MSGLogin.h",
            "../../common/update/*.h",

            "../LoginServer/**.h",
            "../LoginServer/**.cpp",

            "../Utility/MyConnectionPool.h",
            "../Utility/MyConnectionPool.cpp",
            "../Utility/Markup.h",
            "../Utility/Markup.cpp",
            "../Utility/Utility.h",
            "../Utility/Utility.cpp",

            "../RPC/ICenterRpcService.h",
        }

        -- 预编译头
        pchheader "stdafx.h"
        pchsource "../LoginServer/stdafx.cpp"

        -- 包含目录
        includedirs
        {
            "../Utility/",
            "../../3rdParty/",
            "../../3rdParty/atom/",
            "../../3rdParty/RCF/include/",
            "../../3rdParty/glog/src/windows/",
            "../../3rdParty/libmysql/include/",
            "../../3rdParty/mysql++/lib/",
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
            "libAtom",
            "libmysqlpp",
            "libmysql",
        }
