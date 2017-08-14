#pragma once

#include <atom/CAtom.h>
#include <electron/CElectron.h>
#include "easylogging++.h"


#ifndef NOT_USE_ATOM_ALLOCATOR
#define AS2Std(s)  as2std((s).c_str())
#else
#define AS2Std(s)   (s)
#endif


// �Զ���ʼ��atom
class AtomAutoInit : boost::noncopyable
{
public:
    AtomAutoInit(int32_t pool_size, int32_t thread_num)
    {
        atom::CAtom::Presetup();
        electron::CElectron::Presetup();
        CHECK(atom::CAtom::Initiate(pool_size)) << "��ʼ��atom����";
        CHECK(electron::CElectron::Initiate(thread_num)) << "��ʼ��electron����";
    }

    ~AtomAutoInit()
    {
        electron::CElectron::Shutdown();
        atom::CAtom::Shutdown();
        electron::CElectron::Destruct();
        atom::CAtom::Destruct();
    }
};
