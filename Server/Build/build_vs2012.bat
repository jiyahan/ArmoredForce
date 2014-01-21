copy ..\..\Toolset\premake\premake4.exe .

premake4 --file=build_db.lua      vs2012
premake4 --file=build_login.lua   vs2012
premake4 --file=build_cs.lua      vs2012
premake4 --file=build_gs.lua      vs2012
premake4 --file=build_test.lua    vs2012

del premake4.exe

pause