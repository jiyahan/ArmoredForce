#include "stdafx.h"
#include "LoginServer.h"
#include <filesystem>
#include <easylogging++.h>
#include <RCF/RCF.hpp>
#include "Utility.h"
#include "AppConfig.h"


using namespace std;


_INITIALIZE_EASYLOGGINGPP

    // ��ʼ����־
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
// ����ȫ��Class����(�͵���ģʽ)
// 1, ԭ��Ϊ������Դ(�ڴ棬�ļ���)���ɿأ���Դ�ķ���Ӧ���ڽ���main����У�
//          ��Դ���ͷ�Ӧ����main�˳�֮ǰ���
//          
// 2��ԭ��:
//      C++δ����ȫ�ֱ�����˳��Class���͵�ȫ�ֱ�������main����֮ǰ������Դ(���캯��)��
//      ������main����֮���ͷ���Դ(��������)
//      ���̰߳�ȫ�ĵ���ģʽһ�㶼����main֮ǰִ�г�ʼ��
//
int main(int argc, const char* argv[])
{
    try
    {
        AppConfig cfg = LoadAppConfig("login.config.xml");

        // ��ʼ����־
        InitLogging(cfg.log_config_file, cfg.log_dir);        

        // ��ʼ��RPC���
        RCF::RcfInitDeinit rcfInit;

        // ��ʼ��Atom
        AtomAutoInit  atomInit(cfg.pool_size, cfg.thread_num);

        // ���з�����
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
        LOG(FATAL) << ex.what();
    }
    catch(...)
    {
        LOG(FATAL) << "unexpected exception.\n";
    }

    return 0;
}

