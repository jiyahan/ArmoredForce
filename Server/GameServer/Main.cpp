#include "stdafx.h"
#include "GameServer.h"
#include <iostream>
#include <filesystem>
#include <glog/logging.h>
#include <RCF/RCF.hpp>
#include "Server/Utility/Utility.h"
#include "AppConfig.h"

using namespace std;
namespace fs = std::tr2::sys;

// ��ʼ����־
void InitLogging(int argc, const char* argv[])
{
    fs::path dir("log");
    if (!fs::exists(dir))
    {
        fs::create_directory(dir);
    }

    // ������־·��
    google::InitGoogleLogging(argv[0]);

    FLAGS_log_dir = dir.string();
    FLAGS_alsologtostderr = true;
}


// �����
int main(int argc, const char* argv[])
{
    try
    {        
        // ��ʼ����־����
        InitLogging(argc, argv);

        // ��ȡ��������
        AppConfig cfg = LoadAppConfig("game.config.xml");

        // ��ʼ��RPC���
        RCF::RcfInitDeinit rcfInit;

        // ��ʼ��atom
        AtomAutoInit atomInit(cfg.pool_size, cfg.thread_num);

        // ���з�����
        GameServer& theApp = GameServer::GetInstance();
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
