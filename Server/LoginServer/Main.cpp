#include "stdafx.h"
#include "LoginServer.h"
#include <filesystem>
#include <easylogging++.h>
#include <RCF/RCF.hpp>
#include "Utility.h"
#include "AppConfig.h"


using namespace std;


_INITIALIZE_EASYLOGGINGPP

    // 初始化日志
void InitLogging(const string& conf_file, const string& dir)
{
    namespace fs = std::tr2::sys;
    fs::path path(dir);
    if (!fs::exists(path))
    {
        fs::create_directory(path);
    }
    el::Configurations conf(conf_file);
    el::Loggers::reconfigureAllLoggers(conf);
}


//
// 慎用全局Class变量(和单件模式)
// 为了让资源(内存，文件等)更可控，资源的分配应该在进入main后进行，相应的释放应该在main退出
// 之前完成。因为C++未定义全局变量的构造顺序，Class类型的全局变量会在main函数之前通过构造
// 函数分配资源，并在在main函数之后通过析构函数释放资源，这样在main函数内部的代码无法对所有
// 的资源进行控制。
//
int main(int argc, const char* argv[])
{
    char buffer[200];
    sprintf_s(buffer, 200, "%d%c", 30, 'c');
    try
    {
        AppConfig cfg = LoadAppConfig("login.config.xml");

        // 初始化日志
        InitLogging(cfg.log_config_file, cfg.log_dir);        

        // 初始化RPC框架
        RCF::RcfInitDeinit rcfInit;

        // 初始化Atom
        AtomAutoInit  atomInit(cfg.pool_size, cfg.thread_num);

        // 运行服务器
        LoginServer::Create();
        LoginServer& theApp = LoginServer::GetInst();
        if (theApp.Init(cfg))
        {
            while (theApp.Run())
                ;
        }
        LoginServer::Destroy();
    }
    catch(std::exception& ex)
    {
        LOG(FATAL) << ex.what();
    }
    catch(...)
    {
        LOG(FATAL) << "unexpected exception.\n";
    }

    return 0;
}

