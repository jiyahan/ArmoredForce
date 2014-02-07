--
--
-- 生成所有依赖库
--
--

local BOOST_DIR = os.getenv("BOOST_ROOT")

solution "DependLibs"    
    targetdir "libs"    
    language "C++"
    platforms { "x32", "x64" }
    configurations { "Debug", "Release" }
    flags { "StaticRuntime" }
    
    configuration "Debug"
        defines { "DEBUG", "_DEBUG" }
        flags { "Symbols" }

    configuration "Release"
        defines { "NDEBUG" }
        flags { "Symbols", "Optimize"}

    configuration "vs*"
        defines 
        {
            "_CRT_SECURE_NO_WARNINGS",
            "WIN32_LEAN_AND_MEAN",
            "_WIN32_WINNT=0x0601",
        }
        buildoptions " /wd\"4996\""
            
    -- MySQL++
    project "libmysqlpp"
        location ("msvc")
        kind "StaticLib"
        uuid "85BDBF0E-8BCC-6342-ACC3-F3B0D2EC54DC"
        defines 
        { 
            "HAVE_MYSQL_SSL_SET",
            "MYSQLPP_NO_DLL",
        }
        files 
        { 
            "mysql++/lib/**.h",
            "mysql++/lib/**.cpp",
        }

        includedirs 
        {
            "MySQL++/include",
            "libmysql/include",
        }
        libdirs 
        {
            "libs",
        }
        
        links "libmysql"
        
    -- Atom
    project "libAtom"
        location ("msvc")
        kind "StaticLib"
        uuid "95269177-9BA3-1B42-98F3-8A901CA1B415"
        buildoptions "-Zm200 /FI\"pch.h\" "
        files
        {
            "atom/atom/**.cpp",
            "atom/atom/**.h",
            "atom/electron/**.c",
            "atom/electron/**.cpp",
            "atom/electron/**.h",
            "atom/pch.cpp",
        }
        
        -- minilzo.c文件需要单独设置为不使用预编译头
        pchheader "pch.h"
        pchsource "atom/pch.cpp"
        
    -- RCF
    project "librcf"
        location ("msvc")
        kind "StaticLib"
        uuid "953B98EE-A11F-B44E-AF70-E1A6704A143E"
        defines 
        {
            "RCF_USE_BOOST_ASIO",
            "BOOST_ASIO_SEPARATE_COMPILATION",
        }
        files
        {
            "RCF/src/RCF/RCF.cpp",
            "RCF/src/RCF/AsioSrc.cpp",
        }
        includedirs 
        {
            "RCF/include",
            BOOST_DIR,
        }
    
    -- gtest
    project "libgtest"
        location ("msvc")
        kind "StaticLib"
        uuid "F6820085-B31D-1B44-BC9D-E3F65615604C"
        defines
        {
            "GTEST_HAS_TR1_TUPLE=0",
        }
        
        files
        {
            "gtest/src/gtest-all.cc",
        }
        includedirs 
        {
            "gtest",
            "gtest/include",
        }
        
    -- Lua
    project "liblua"
        location ("msvc")
        kind "StaticLib"
        uuid "DDBAFE27-F999-E24B-91CC-E51FEBE65EE2"
        language "C"
        files
        {
            "lua/src/*.h",
            "lua/src/*.c",
        }
        excludes 
        {
            "lua/src/lua.c",
            "lua/src/luac.c",
            "lua/src/print.c",
        }
        includedirs 
        {
            "lua/src",
        }       
       
       -- luabind
    project "libluabind"
        location ("msvc")
        kind "StaticLib"
        uuid "D14147C5-6030-40D9-91E6-EC674DBE5BB8"
        language "C++"
        files
        {
            "luabind/luabind/*.h",
            "luabind/src/*.cpp",
        }
        includedirs 
        {
            "lua/src",
            "luabind",
            BOOST_DIR,
        }
        