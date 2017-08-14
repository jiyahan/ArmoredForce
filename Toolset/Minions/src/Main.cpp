/**
 *      Minions
 *  
 *      һ�������Ļ����˳������粿�ֲ���asio�����̹߳����������
 *      ����ʹ��lua�ű�����չ
 */

#include <string>
#include "easylogging++.h"
#include "minion_app.h"


_INITIALIZE_EASYLOGGINGPP;


int main(int argc, char* argv[])
{
    try
    {
        const char* script = "app.lua";
        if (argc >= 2)
        {
            script = argv[1];
        }

        MinionApp app;
        app.Start(script);
    }
    catch(std::exception& ex)
    {
        LOG(FATAL) << ex.what();
    }
    
    return 0;
}
