#include "stdafx.h"
#include "GameServer.h"
#include <iostream>
#include <filesystem>
#include <glog/logging.h>
#include <RCF/RCF.hpp>

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
        InitLogging(argc, argv);    // ��ʼ����־        
        RCF::RcfInitDeinit rcfInit; // ��ʼ��RPC���

        GameServer& theApp = GameServer::GetInstance();
        if (theApp.Init())
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
