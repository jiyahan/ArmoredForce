/**
 *  @file   message.h
 *  @author chenqiang01@7aurora.com
 *  @date   Jan 21, 2014
 *  @brief  ��Ϣ��ʽ����
 *
 */

#pragma once

#include <cstdint>
#include <functional>



typedef uint8_t byte;

namespace electron {class CMessage;}

typedef std::function<void (const void* data, size_t)>   sender_type;

// ����Ϣѹ�������͸�������
void SendCompressedMessage(electron::CMessage* msg, sender_type sender);

// �Ӷ������н�ѹ����ȷ����Ϣ
electron::CMessage* UnCompressMessage(const void* data, size_t bytes);
