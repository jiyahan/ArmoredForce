#include "tcp_client.h"
#include <iostream>
#include <functional>

using namespace boost::asio;
using namespace std::placeholders;



TcpClient::TcpClient(boost::asio::io_service& io_service,
                     connect_handler on_connect,
                     read_handler on_read,
                     error_handler on_error)
    : socket_(io_service),
      on_connect_(on_connect),
      on_read_(on_read),
      on_error_(on_error),
      write_bytes_(0)
{
    CHECK(on_connect_ && on_read_ && on_error_);
}

TcpClient::~TcpClient()
{
    socket_.close();
}


void TcpClient::AsynClose()
{
    socket_.get_io_service().post([this]()
    {
        socket_.close();
    });
}

// asio的异步连接默认没有使用ConnectEx，而是采用另启线程的方案
void TcpClient::AsynConnect(const std::string& host, int16_t port)
{
    ip::tcp::endpoint peer(ip::address::from_string(host), port);
    socket_.async_connect(peer, [this, host, port](const bs::error_code& ec)
    {
        if (!ec)
        {
            on_connect_(shared_from_this(), host, port);
        }
        else
        {
            on_error_(shared_from_this(), ec);
        }
    });
}

void TcpClient::AsynRead()
{
    socket_.async_read_some(buffer(data_buffer_.data(), data_buffer_.size()), 
        [this](const bs::error_code& ec, size_t bytes)
    {
        if (!ec)
        {
            on_read_(shared_from_this(), bytes);
        }
        else
        {
            on_error_(shared_from_this(), ec);
        }
    });
}

void TcpClient::AsynWrite(const void* data, size_t bytes)
{
    socket_.async_write_some(buffer(data, bytes), 
        [this](const bs::error_code& ec, size_t bytes)
    {
        if (!ec)
        {
            write_bytes_ += bytes;
        }
        else
        {
            on_error_(shared_from_this(), ec);
        }
    });
}

