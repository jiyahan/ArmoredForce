/**
 *  @file   minion.h
 *  @author chenqiang01@7aurora.com
 *  @date   Jan 21, 2014
 *  @brief  
 *
 */

#pragma once

#include <memory>
#include "net/tcp_client.h"

class Minion : public TcpClient
{
public:

private:

};

typedef std::shared_ptr<Minion>  MinionPtr;