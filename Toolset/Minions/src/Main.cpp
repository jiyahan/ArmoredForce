#include "StdAfx.h"
#include <iostream>
#include <exception>
#include <glog/logging.h>
#include "Minons.h"
#include "Utility.h"

using namespace std;


// 初始化日志
void InitLogging(int argc, const char* argv[])
{
    google::InitGoogleLogging(argv[0]);
}


int main(int argc, const char* argv[])
{
    try
    {
        AtomAutoInit init(1024*32, 1);

        InitLogging(argc, argv);    // 初始化日志      

        Minions&  app = Minions::GetInstance();
        if (app.Init())
        {
            while (app.Run())
                ;
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