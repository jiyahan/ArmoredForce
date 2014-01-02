--
--
-- 生成所有依赖库
--
--

local BOOST_DIR = os.getenv("BOOST_DIR")

solution "DenpendLibs"
	location (_ACTION or "")
    targetdir "libs"
	configurations { "Debug", "Release" }
	platforms { "x32", "x64" }

	language "C++"
	flags { "No64BitChecks", "StaticRuntime" }
	
    configuration "Debug"
        defines { "DEBUG" }
        flags { "Symbols" }

	configuration "Release"
		defines { "NDEBUG" }
		flags { "Optimize", "StaticRuntime", }

	configuration "vs*"
		defines 
        { 
            "_USING_V110_SDK71_",
            "_CRT_SECURE_NO_WARNINGS",
            "WIN32_LEAN_AND_MEAN",
        }
        buildoptions " /wd\"4996\""
            
    -- mysql++
	project "libmysqlpp"
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
			"libs/"
		}
		
		links "libmysql"
        
	-- libAtom
	project "libAtom"
		kind "StaticLib"
		uuid "95269177-9BA3-1B42-98F3-8A901CA1B415"
		files
		{
			"atom/atom/**.cpp",
			"atom/atom/**.h",
			"atom/electron/**.c",
			"atom/electron/**.cpp",
			"atom/electron/**.h",
		}
        
	-- RCF
	project "librcf"
		kind "StaticLib"
        uuid "953B98EE-A11F-B44E-AF70-E1A6704A143E"
		defines 
		{
		}
		files
		{
			"RCF/src/RCF/RCF.cpp",
		}
		includedirs 
		{
			"RCF/include",
			BOOST_DIR,
		}
	
    -- gtest
	project "libgtest"
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
        
	-- glog
	project "libglog"
		kind "StaticLib"
        uuid "17B9249C-63B6-564C-89EF-BE3288E483F8"
		defines {"GOOGLE_GLOG_DLL_DECL= "}
		files
		{
			"glog/src/logging.cc",
			"glog/src/raw_logging.cc",
			"glog/src/utilities.cc",
			"glog/src/vlog_is_on.cc",
			"glog/src/windows/port.cc",
			"glog/src/utilities.h",
			"glog/src/base/googleinit.h",
			"glog/src/base/commandlineflags.h",
			"glog/src/base/mutex.h",
			"glog/src/windows/port.h",
			"glog/src/windows/config.h",
			"glog/src/windows/glog/logging.h",
			"glog/src/windows/glog/log_severity.h",
			"glog/src/windows/glog/raw_logging.h",
			"glog/src/windows/glog/stl_logging.h",
			"glog/src/windows/glog/vlog_is_on.h",
		}
		includedirs
		{
			"glog/src/windows",
		}
        
    -- lua
	project "liblua"
		kind "StaticLib"
        uuid "DDBAFE27-F999-E24B-91CC-E51FEBE65EE2"
        language "C"
        defines
        {
            "",
        }
		
		files
		{
			"lua/src/*.h",
            "lua/src/*.c",
		}
        excludes 
        {
            "lua/src/lua.c",
            "lua/src/luac.c",
        }
        includedirs 
        {
            "lua/src",
        }       
       