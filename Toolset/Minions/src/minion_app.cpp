#include "minion_app.h"
#include <memory>
#include "net/tcp_client.h"
#include "net/compress.h"
#include "script/minion_script.h"
#include "script/msg_script.h"


using namespace std;
using namespace std::placeholders;
using namespace boost::asio;



//////////////////////////////////////////////////////////////////////////
//
// ctor and dctor
//
MinionApp::MinionApp()
    : current_id_(1000)
{ 
}

MinionApp::~MinionApp()
{
    script_.Release();
}

bool MinionApp::Init(const std::string& file)
{
    CHECK(script_.Init());

    // 执行脚本的on_start函数
    if (!script_.DoFile(file.c_str()))
    {
        return false;
    }

    script_.Call("on_start", "");

    return true;
}

bool MinionApp::Run()
{    
    // 开始I/O事件循环
    io_service::work work(io_service_);
    io_service_.run();

    return true;
}

MinionPtr  MinionApp::CreateMinion(const std::string& host, int16_t port)
{    
    try
    {
        size_t minion_id = current_id_++;
        connect_handler on_connect = std::bind(&MinionApp::OnTcpConnect, this, minion_id, _1, _2, _3);
        read_handler on_read = std::bind(&MinionApp::OnTcpRead, this, minion_id, _1, _2);
        error_handler on_error = std::bind(&MinionApp::OnTcpError, this, minion_id, _1, _2);
        TcpClientPtr ptr = make_shared<TcpClient>(io_service_, on_connect, on_read, on_error);        
        MinionPtr minion = make_shared<Minion>(ptr);
        minion->SetID(minion_id);
        minion_list_[minion_id] = minion;
        ptr->AsynConnect(host, port);
        return minion;
    }
    catch(std::exception& ex)
    {
        LOG(ERROR) << ex.what();
        return nullptr;
    }
}

void MinionApp::DestroyMinion(Minion* ptr)
{
    delete ptr;
}

// 连接上服务器
void MinionApp::OnTcpConnect(size_t minion_id, TcpClientPtr cp, const std::string& host, int16_t port)
{
    const auto& iter = minion_list_.find(minion_id);
    if (iter == minion_list_.end())
    {
        LOG(INFO) << "minion not found: " << minion_id;
        return ;
    }

    MinionPtr ptr = iter->second;
    script_.GetGlobal("on_connect");
    CHECK(script_.IsFunction(-1));
    script_.NewUserData(MINION_META_HANDLE, ptr.get());
    script_.Push(host.c_str());
    script_.Push(port);
    script_.Call(3, 0);

    ptr->Read();
}

// 读取到数据
void MinionApp::OnTcpRead(size_t minion_id, TcpClientPtr cp, size_t bytes_transferred)
{
    const auto& iter = minion_list_.find(minion_id);
    if (iter == minion_list_.end())
    {
        LOG(INFO) << "minion not found: " << minion_id;
        return ;
    }

    MinionPtr ptr = iter->second;
    electron::CMessage* msg = UnCompressMessage(cp->GetDataBuffer().data(), bytes_transferred);
    if (msg)
    {
        script_.GetGlobal("on_read");
        CHECK(script_.IsFunction(-1));
        script_.NewUserData(MINION_META_HANDLE, ptr.get());
        script_.NewUserData(MSG_META_HANDLE, msg);
        script_.Call(2, 0);
    }
    ptr->Read();
}

// 网络错误
void MinionApp::OnTcpError(size_t minion_id, TcpClientPtr cp, const bs::error_code& ec)
{
    const auto& iter = minion_list_.find(minion_id);
    if (iter == minion_list_.end())
    {
        LOG(INFO) << "minion not found: " << minion_id;
        return ;
    }

    MinionPtr ptr = iter->second;
    script_.GetGlobal("on_error");
    CHECK(script_.IsFunction(-1));
    script_.NewUserData(MINION_META_HANDLE, ptr.get());
    script_.Push(ec.message().c_str());
    script_.Call(2, 0);
    minion_list_.erase(minion_id);
}
