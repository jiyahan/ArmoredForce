#include "Utility.h"
#include <glog/logging.h>
#include <atom/CAtom.h>
#include <electron/CElectron.h>


using atom::CAtom;
using electron::CElectron;

AtomAutoInit::AtomAutoInit(int pool_size, int thread_num)
{
    CAtom::Presetup();
    CElectron::Presetup();
    CHECK(CAtom::Initiate(pool_size)) << "初始化atom错误"; 
    CHECK(CElectron::Initiate(thread_num)) << "初始化electron错误";
}

AtomAutoInit::~AtomAutoInit()
{
    CElectron::Shutdown();
    CAtom::Shutdown();
    CElectron::Destruct();
    CAtom::Destruct();
}

