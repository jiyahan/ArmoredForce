#include "minion.h"
#include "minion_app.h"
#include "net/compress.h"


Minion::Minion(TcpClientPtr ptr)
    : tcp_conn_(ptr)
{
}

Minion::~Minion()
{
}

void Minion::Write(electron::CMessage* msg)
{
    CHECK_NOTNULL(msg);
    SendCompressedMessage(msg, [this](const void* data, size_t bytes)
    {
        tcp_conn_->AsynWrite(data, bytes);
    });
}

void  Minion::Read()
{
    tcp_conn_->AsynRead();
}
