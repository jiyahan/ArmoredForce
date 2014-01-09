--
-- Premake4.x build configuration script
-- http://industriousone.com/scripting-premake
--

local BOOST_DIR = os.getenv("BOOST_DIR")

--
-- unittest和benchmark
--
solution "Test"
    configurations { "Release", "Debug" }
    location "Test"
    targetdir "Test"
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

    -- Test项目
    project "Test"
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

