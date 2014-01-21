#include "tcp_client.h"
#include <iostream>
#include <functional>

using namespace boost::asio;
using namespace std::placeholders;
using boost::system::error_code;



TcpClient::TcpClient(boost::asio::io_service& io_service,
                     connect_handler on_connect,
                     read_handler on_read,
                     error_handler on_error)
    : io_service_(io_service), 
      socket_(io_service),
      on_connect_(on_connect),
      on_read_(on_read),
      on_error_(on_error)
{
    CHECK(on_connect_ && on_read_ && on_error_);
}

TcpClient::~TcpClient()
{
    socket_.close();
}

void TcpClient::AsynClose()
{
    io_service_.post([this]()
    {
        socket_.close();
    });
}

void TcpClient::AsynConnect(const std::string& host, int16_t port)
{
    ip::tcp::endpoint peer(ip::address::from_string(host), port);
    socket_.async_connect(peer, [this, host, port](const error_code& ec)
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
        [this](const error_code& ec, size_t bytes)
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
        [this](const error_code& ec, size_t bytes)
    {
        if (!ec)
        {

        }
        else
        {
            on_error_(shared_from_this(), ec);
        }
    });
}

