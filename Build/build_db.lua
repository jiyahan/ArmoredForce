--
-- Premake4.x build configuration script
-- http://industriousone.com/scripting-premake
--

local BOOST_DIR = os.getenv("BOOST_DIR")

-- DBServer解决方案
solution "DBServer"
    configurations { "Release", "Debug" }
    location "DBServer"
    targetdir "../Run/dbserver"
    language    "C++"
    flags       { "No64BitChecks", "StaticRuntime" }

    configuration "debug"
        defines { "DEBUG" }
        flags { "Symbols" }

    configuration "release"
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

    -- DBServer项目
    project "DBServer"
        kind "ConsoleApp"
        uuid "1EFC1D41-464B-3147-94E8-25FAD0F1E1AA"
        buildoptions '/I"../../"'
        defines
        {
            "__DB_SERVER__",            
            "MARKUP_STL",
            "GOOGLE_GLOG_DLL_DECL=",
            "GLOG_NO_ABBREVIATED_SEVERITIES",
            "MYSQLPP_NO_DLL",
        }

        -- 源代码文件
        files
        {
            "../Server/DBServer/**.h",
            "../Server/DBServer/**.cpp",
            "../Server/Utility/**.h",
            "../Server/Utility/**.cpp",
            "../Server/RPC/IDBRpcService.h",
        }

        -- 预编译头
        pchheader "stdafx.h"
        pchsource "../Server/DBServer/stdafx.cpp"

        -- 包含目录
        includedirs
        {
            "../Server/Utility",
            "../3rdParty/",
            "../3rdParty/atom",
            "../3rdParty/glog/src/windows/",
            "../3rdParty/libmysql/include",
            "../3rdParty/mysql++/lib",
            "../3rdParty/RCF/include",
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
            "libmysql",
            "libmysqlpp",
            "librcf",
            "libglog",
            "libatom",
        }
