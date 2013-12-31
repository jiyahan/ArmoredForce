--
-- Premake4.x build configuration script
-- http://industriousone.com/scripting-premake
--

local BOOST_DIR = os.getenv("BOOST_DIR")


-- unittest和benchmark
solution "Test"
    configurations { "Release", "Debug" }
    location "Test"
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

    -- Test项目
    project "Test"
        kind "ConsoleApp"
        uuid "3C53977F-705F-7746-9DB1-AD248EE761F0"
        defines
        {
            "GOOGLE_GLOG_DLL_DECL=",
            "GTEST_HAS_TR1_TUPLE=0",
        }

        -- 源代码文件
        files
        {
            "../Server/Utility/*.h",
            "../Server/Utility/*.cpp",
            "../Server/UnitTest/**.h",
            "../Server/UnitTest/**.cpp",
        }
        excludes
        {
            "../Server/Utility/Markup.cpp",
            "../Server/Utility/MyConnectionPool.cpp",
        }

        pchheader "stdafx.h"
        pchsource "../Server/UnitTest/stdafx.cpp"

        -- 包含目录
        includedirs
        {
            "../Server/Utility",
            "../3rdParty/atom",
            "../3rdParty/gtest/include",
            "../3rdParty/glog/src/windows/",
            "../3rdParty/mysql++/lib",
            BOOST_DIR,
        }

        libdirs
        {
            "../3rdParty/libs",
            BOOST_DIR .. '/stage/lib',
        }

        links
        {
            "libglog",
            "libgtest",
            "libatom",
        }

