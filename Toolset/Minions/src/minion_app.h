/**
 *  @file   minion_app.h
 *  @author chenqiang01@7aurora.com
 *  @date   Jan 21, 2014
 *  @brief  hold all minions
 *
 */

#pragma once


#include <string>
#include <unordered_map>
#include <boost/noncopyable.hpp>
#include <boost/asio.hpp>
#include "script/script_rt.h"
#include "minion.h"



class MinionApp : boost::noncopyable
{
public:
    MinionApp();
    ~MinionApp();

    bool Start(const std::string& script);

    int32_t  CreateRobot(const std::string& host, int16_t port);


private:
    // io_service object
    boost::asio::io_service     io_service_;

    // all robots
    std::unordered_map<int32_t, MinionPtr>   robots_;

    ScriptRuntime   script_;
};


