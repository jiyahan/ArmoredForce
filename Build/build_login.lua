--
-- Premake4.x build configuration script
-- http://industriousone.com/scripting-premake
--

local BOOST_DIR = os.getenv("BOOST_DIR")

-- LoginServer解决方案
solution "LoginServer"
    configurations { "Release", "Debug" }
    location "LoginServer"
    targetdir "../Run/loginserver"
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
        buildoptions "-Zm200 /FI\"stdafx.h\""

    configuration "gmake"
        linkoptions "-lpthread -ldl"

    -- LoginServer项目
    project "LoginServer"
        kind "ConsoleApp"
        uuid "2A54CE18-82AB-7246-8653-EFF4A3FB9BC8"
        buildoptions '/I"../../"'
        defines
        {
            "__LOGIN_SERVER__",
            "MARKUP_STL",
            "GOOGLE_GLOG_DLL_DECL=",
            "GLOG_NO_ABBREVIATED_SEVERITIES",
        }

        -- 源代码文件
        files
        {
            "../common/MESSAGE_ID.h",
            "../common/MSGCode.h",
            "../common/MSGLogin.h",
            "../common/update/*.h",

            "../Server/LoginServer/**.h",
            "../Server/LoginServer/**.cpp",

            "../Server/Utility/MyConnectionPool.h",
            "../Server/Utility/MyConnectionPool.cpp",
            "../Server/Utility/Markup.h",
            "../Server/Utility/Markup.cpp",
            "../Server/Utility/Utility.h",
            "../Server/Utility/Utility.cpp",

            "../Server/RPC/ICenterRpcService.h",
        }

        -- 预编译头
        pchheader "stdafx.h"
        pchsource "../Server/LoginServer/stdafx.cpp"

        -- 包含目录
        includedirs
        {
            "../Server/Utility/",
            "../3rdParty/",
            "../3rdParty/atom/",
            "../3rdParty/RCF/include/",
            "../3rdParty/glog/src/windows/",
            "../3rdParty/libmysql/include/",
            "../3rdParty/mysql++/lib/",
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
            "libAtom",
            "libglog",
            "libmysqlpp",
            "libmysql",
        }
