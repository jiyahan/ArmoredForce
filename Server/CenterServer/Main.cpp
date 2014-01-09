#include "CenterServer.h"
#include <iostream>
#include <filesystem>
#include <easylogging++.h>#include <RCF/RCF.hpp>
#include "Utility.h"
#include "AppConfig.h"

using namespace std;
namespace fs = std::tr2::sys;

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


// 主入口
int main(int argc, const char* argv[])
{
    try
    {
        // 读取基础配置
        AppConfig cfg = LoadAppConfig("center.config.xml");

        // 初始化日志配置
        InitLogging(cfg.log_config_file, cfg.log_dir);

        // 初始化RPC框架
        RCF::RcfInitDeinit rcfInit;

        // 初始化atom
        AtomAutoInit atomInit(cfg.pool_size, cfg.thread_num);

        // 运行服务器
        CenterServer& theApp = CenterServer::GetInstance();
        if (theApp.Init(cfg))
        {
            while (theApp.Run())
                ; 
            theApp.Release();
        }        
    }
    catch(std::exception& ex)
    {
        LOG(ERROR) << ex.what();
    }
    catch(...)
    {
        LOG(ERROR) << "unexpected exception.\n";
    }

    return 0;
}
