/**
 *  @file   ProcessGameBattle.h
 *  @author chenqiang01@7aurora.cm
 *  @date   Jan 21, 2014
 *  @brief  �����¼��ص���Ϣ
 */


#pragma once

// forward declaration
namespace electron {class CMessage;}

// �汾��֤
void HandleVerifyResponse(electron::CMessage&);

// ��¼
void HandleLoginResponse(electron::CMessage&);

// ע��
void HandleRegisterResponse(electron::CMessage&);

// ��֤
void HandleAuthResponse(electron::CMessage&);


// ������LS��Ĵ���
void    OnConnectLoginServer();
