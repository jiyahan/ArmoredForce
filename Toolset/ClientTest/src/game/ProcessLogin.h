/**
 *  @file   ProcessGameBattle.h
 *  @author chenqiang01@7aurora.cm
 *  @date   Jan 21, 2014
 *  @brief  处理登录相关的消息
 */


#pragma once

// forward declaration
namespace electron {class CMessage;}

// 版本验证
void HandleVerifyResponse(electron::CMessage&);

// 登录
void HandleLoginResponse(electron::CMessage&);

// 注册
void HandleRegisterResponse(electron::CMessage&);

// 认证
void HandleAuthResponse(electron::CMessage&);


// 连接上LS后的处理
void    OnConnectLoginServer();
