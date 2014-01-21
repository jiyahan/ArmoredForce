/**
 *  @file   tcp_client.h
 *  @author chenqiang01@7aurora.com
 *  @date   Jan 21, 2014
 *  @brief  abstract a TCP client connection
 *
 */
#pragma once

#include <array>
#include <string>
#include <functional>
#include <boost/noncopyable.hpp>
#include "message.h"

namespace asio_ip = boost::asio::ip;
namespace bs = boost::system;


class TcpClient;
typedef std::shared_ptr<TcpClient>  TcpClientPtr;

typedef std::function<void (TcpClientPtr, const bs::error_code&)>       error_handler;
typedef std::function<void (TcpClientPtr, const std::string&, int16_t)> connect_handler;
typedef std::function<void (TcpClientPtr, size_t)>                      read_handler;


class TcpClient 
    :   boost::noncopyable,
        std::enable_shared_from_this<TcpClient>
{
public:
    explicit TcpClient(boost::asio::io_service& io_service,
                       connect_handler on_connect,
                       read_handler on_read,
                       error_handler on_error);
    virtual ~TcpClient();    

    void AsynConnect(const std::string& host, int16_t port);

    void AsynWrite(const void* data, size_t bytes);

    void AsynRead();

    void AsynClose();

private:
    

private:
    boost::asio::io_service&            io_service_;
    asio_ip::tcp::socket                socket_;
    std::array<uint8_t, MAX_MSG_SIZE>   data_buffer_;

    error_handler       on_error_;
    connect_handler     on_connect_;
    read_handler        on_read_;
};