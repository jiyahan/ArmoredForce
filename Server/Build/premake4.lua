--
-- Premake4.x build configuration script
-- http://industriousone.com/scripting-premake
--

local BOOST_DIR = os.getenv("BOOST_ROOT")


--
-- LoginServer解决方案
--
solution "LoginServer"
    configurations { "Release", "Debug" }
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
        }
        buildoptions "-Zm200 /FI\"stdafx.h\" /wd\"4996\""

    configuration "gmake"
        linkoptions "-lpthread -ldl"

    -- LoginServer项目
    project "LoginServer"
        location "LoginServer"        
        kind "ConsoleApp"
        uuid "2A54CE18-82AB-7246-8653-EFF4A3FB9BC8"
        buildoptions '/I"../../../"'
        defines
        {
            "__LOGIN_SERVER__",
            "MARKUP_STL",
            "MYSQLPP_NO_DLL",
            "RCF_USE_BOOST_ASIO",
            "BOOST_ASIO_SEPARATE_COMPILATION",
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
            
            "../Script/*.h",
            "../Script/*.cpp",

            "../Utility/MyConnectionPool.h",
            "../Utility/MyConnectionPool.cpp",
            "../Utility/Markup.h",
            "../Utility/Markup.cpp",
            "../Utility/Utility.h",
            "../Utility/Utility.cpp",
            "../Utility/pbkdf2.h",
            "../Utility/pbkdf2.cpp",

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
            "../../3rdParty/openssl/include/",
            "../../3rdParty/lua/src/",
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
            "libeay32",
            "liblua",
        }

        

-- GameServer解决方案
solution "GameServer"
    configurations { "Release", "Debug" }
    targetdir "../../Run/gameserver"
    language    "C++"
    platforms { "x32", "x64" }
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
            "WIN32_LEAN_AND_MEAN",
        }
        buildoptions "-Zm200 /FI\"stdafx.h\" /wd\"4996\""

    configuration "gmake"
        linkoptions "-lpthread -ldl"

    -- GameServer项目
    project "GameServer"
        location "GameServer"
        kind "ConsoleApp"
        uuid "7C68D073-DD0F-C84B-BBD5-9941309F6D52"
        buildoptions '/I"../../../"'
        defines
        {
            "__GAME_SERVER__",
            "MARKUP_STL",
            "RCF_USE_BOOST_ASIO",
            "BOOST_ASIO_SEPARATE_COMPILATION",
            "NOT_USE_ATOM_ALLOCATOR",
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
        }

--
-- CenterServer解决方案
--
solution "CenterServer"
    configurations { "Release", "Debug" }    
    targetdir "../../Run/centerserver"
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

    -- CenterServer项目
    project "CenterServer"
        location "CenterServer"
        kind "ConsoleApp"
        uuid "755FAC6C-5706-A74D-8D5B-C88B7A728C90"
        buildoptions '/I"../../../"'
        defines
        {
            "__CENTER_SERVER__",
            "MARKUP_STL",
            "RCF_USE_BOOST_ASIO",
            "BOOST_ASIO_SEPARATE_COMPILATION",
            "NOT_USE_ATOM_ALLOCATOR",
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
            "libatom",
        }


--
-- DBServer解决方案
--
solution "DBServer"
    configurations { "Release", "Debug" }
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
        location "DBServer"
        kind "ConsoleApp"
        uuid "1EFC1D41-464B-3147-94E8-25FAD0F1E1AA"
        buildoptions '/I"../../../"'
        defines
        {
            "__DB_SERVER__",            
            "MARKUP_STL",
            "RCF_USE_BOOST_ASIO",
            "BOOST_ASIO_SEPARATE_COMPILATION",
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


--
-- unittest和benchmark
--
solution "UnitTest"
    configurations { "Release", "Debug" }
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

    -- UnitTest项目
    project "UnitTest"
        location "UnitTest"        
        kind "ConsoleApp"  
        uuid "3C53977F-705F-7746-9DB1-AD248EE761F0"
        defines
        {
            "GTEST_HAS_TR1_TUPLE=0",
            "MYSQLPP_NO_DLL",
            "NOT_USE_ATOM_ALLOCATOR",
        }

        -- 源代码文件
        files
        {
            "../Utility/*.h",
            "../Utility/*.cpp",
            "../UnitTest/**.h",
            "../UnitTest/**.cpp",
        }
        excludes
        {
            "../Utility/Markup.cpp",
        }

        pchheader "stdafx.h"
        pchsource "../UnitTest/stdafx.cpp"

        -- 包含目录
        includedirs
        {
            "../Utility",
            "../../3rdParty/atom",
            "../../3rdParty/gtest/include",
            "../../3rdParty/glog/src/windows/",
            "../../3rdParty/mysql++/lib",
            "../../3rdParty/libmysql/include",
            BOOST_DIR,
        }

        libdirs
        {
            "../../3rdParty/libs",
            BOOST_DIR .. '/stage/lib',
        }

        links
        {
            "libgtest",
            "libatom",
        }

        