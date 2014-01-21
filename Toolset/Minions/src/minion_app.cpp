#include "minion_app.h"

using namespace boost::asio::ip;


MinionApp::MinionApp()
{
    CHECK(script_.Init());
}

MinionApp::~MinionApp()
{
    script_.Release();
}


bool MinionApp::Start(const std::string& script)
{
    if (!script_.DoFile(script.c_str()))
    {
        return false;
    }

    while (io_service_.run_one())
    {
        ;
    }
    return true;
}