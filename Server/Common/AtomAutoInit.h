#pragma once

#include <atom/CAtom.h>
#include <electron/CElectron.h>
#include "easylogging++.h"


#ifndef NOT_USE_ATOM_ALLOCATOR
#define AS2Std(s)  as2std((s).c_str())
#else
#define AS2Std(s)   (s)
#endif


// 自动初始化atom
class AtomAutoInit : boost::noncopyable
{
public:
    AtomAutoInit(int32_t pool_size, int32_t thread_num)
    {
        atom::CAtom::Presetup();
        electron::CElectron::Presetup();
        CHECK(atom::CAtom::Initiate(pool_size)) << "初始化atom错误";
        CHECK(electron::CElectron::Initiate(thread_num)) << "初始化electron错误";
    }

    ~AtomAutoInit()
    {
        electron::CElectron::Shutdown();
        atom::CAtom::Shutdown();
        electron::CElectron::Destruct();
        atom::CAtom::Destruct();
    }
};
