--
-- Premake4.x build configuration script
-- http://industriousone.com/scripting-premake
--

local BOOST_DIR = os.getenv("BOOST_DIR")

--
-- DBServer解决方案
--
solution "DBServer"
    configurations { "Release", "Debug" }
    location "DBServer"
    targetdir "../../Run/dbserver"
    language    "C++"
    platforms { "x32", "x64" }
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
            "WIN32_LEAN_AND_MEAN",
        }
        buildoptions "-Zm200 /FI\"stdafx.h\" /wd\"4996\""

    configuration "gmake"
        linkoptions "-lpthread -ldl"

    -- DBServer项目
    project "DBServer"
        kind "ConsoleApp"
        uuid "1EFC1D41-464B-3147-94E8-25FAD0F1E1AA"
        buildoptions '/I"../../../"'
        defines
        {
            "__DB_SERVER__",            
            "MARKUP_STL",
            "RCF_USE_BOOST_ASIO",
            "MYSQLPP_NO_DLL",
            "NOT_USE_ATOM_ALLOCATOR",
        }

        -- 源代码文件
        files
        {
            "../DBServer/**.h",
            "../DBServer/**.cpp",
            
            "../RPC/IDBRpcService.h",
            
            "../Utility/Markup.h",
            "../Utility/Markup.cpp",
            "../Utility/MyConnectionPool.h",
            "../Utility/MyConnectionPool.cpp",
            "../Utility/Utility.h",
            "../Utility/Utility.cpp",
            "../Utility/Singleton.h",
            "../Utility/ScopeGuard.h",
        }

        -- 预编译头
        pchheader "stdafx.h"
        pchsource "../DBServer/stdafx.cpp"

        -- 包含目录
        includedirs
        {
            "../Utility",
            "../../3rdParty/",
            "../../3rdParty/atom",
            "../../3rdParty/glog/src/windows/",
            "../../3rdParty/libmysql/include",
            "../../3rdParty/mysql++/lib",
            "../../3rdParty/RCF/include",
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
            "libmysql",
            "libmysqlpp",
            "librcf",
            "libatom",
        }
