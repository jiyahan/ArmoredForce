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
            "_CRT_SECURE_NO_WARNINGS",
            "WIN32_LEAN_AND_MEAN",
        }
        buildoptions " /wd\"4996\""
            
    -- mysql++
	project "libmysqlpp"
		kind "StaticLib"
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
       
       