#include "Utility.h"
#include <glog/logging.h>
#include <atom/atom/CAtom.h>
#include <atom/electron/CElectron.h>


using namespace atom;
using namespace electron;


AtomAutoInit::AtomAutoInit(int pool_size, int thread_num)
{
    CAtom::Presetup();
    CElectron::Presetup();
    CHECK(CAtom::Initiate(pool_size)) << "��ʼ��atom����"; 
    CHECK(CElectron::Initiate(pool_size)) << "��ʼ��electron����";
}

AtomAutoInit::~AtomAutoInit()
{
    CElectron::Shutdown();
    CAtom::Shutdown();
    CElectron::Destruct();
    CAtom::Destruct();
}
