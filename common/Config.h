#ifndef COMMON_CONFIG_H
#define COMMON_CONFIG_H

#include <string>
#include <memory>


//
// �Ƿ�ʹ��atom_allocator

#ifdef NOT_USE_ATOM_ALLOCATOR
#define atom_allocator  std::allocator
#define a_string        std::string
#endif



enum 
{
    GRID_AMOUNT = 6,        // ������
    MAX_ROUND = 32,         // ���غ���
    MAX_REGION_STAGE = 3,   // ���׶�
};

#endif // COMMON_CONFIG_H
