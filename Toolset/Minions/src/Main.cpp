/**
 *      Minions
 *  
 *      一个单独的机器人程序，网络部分采用asio，单线程管理大量连接
 *      大量使用lua脚本做扩展
 */

#include <string>
#include "easylogging++.h"
#include "minion_app.h"
#include "Utility.h"


_INITIALIZE_EASYLOGGINGPP;


int main(int argc, char* argv[])
{
    try
    {
        std::string entry_script = "app.lua";
        if (argc >= 2)
        {
            entry_script = argv[1];
        }

        AtomAutoInit  init(1024, 1);

        if (CreateApp())
        {
            GetApp().Start(entry_script);
        }
        DestroyApp();
    }
    catch(std::exception& ex)
    {
        LOG(FATAL) << ex.what();
    }
    
    return 0;
}
