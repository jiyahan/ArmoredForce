#include "stdafx.h"
#include "LoginServer.h"
#include <filesystem>
#include <glog/logging.h>
#include <RCF/RCF.hpp>
#include "Utility.h"
#include "AppConfig.h"


using namespace std;
namespace fs = std::tr2::sys;

// 初始化日志
void InitLogging(int argc, const char* argv[])
{
    fs::path dir("log");
    if (!fs::exists(dir))
    {
        fs::create_directory(dir);
    }

    // 设置日志路径
    google::InitGoogleLogging(argv[0]);

    FLAGS_log_dir = dir.string();
    FLAGS_alsologtostderr = true;
}


// 主入口
int main(int argc, const char* argv[])
{
    try
    {
        // 初始化日志
        InitLogging(argc, argv);

        AppConfig cfg = LoadAppConfig("login.config.xml");

        // 初始化RPC框架
        RCF::RcfInitDeinit rcfInit;

        // 初始化Atom
        AtomAutoInit  atomInit(cfg.pool_size, cfg.thread_num);

        // 运行服务器
        LoginServer& theApp = LoginServer::GetInstance();
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

    google::ShutdownGoogleLogging();

    return 0;
}

