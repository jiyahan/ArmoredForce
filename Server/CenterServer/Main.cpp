#include "StdAfx.h"
#include "CenterServer.h"
#include <iostream>
#include <boost/filesystem.hpp>
#include <glog/logging.h>
#include <RCF/RCF.hpp>

using namespace std;
namespace fs = boost::filesystem;

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

        CenterServer& theApp = CenterServer::GetInstance();
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
