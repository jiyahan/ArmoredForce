#include "Utility.h"
#include <glog/logging.h>
#include <atom/atom/CAtom.h>
#include <atom/electron/CElectron.h>
#include "Random.h"

using namespace atom;
using namespace electron;

namespace  {

    Random 		g_rand; // 不是线程安全

}

uint32_t random(uint32_t max)
{
    return rnd.Uniform(max);
}

AtomAutoInit::AtomAutoInit(int pool_size, int thread_num)
{
    CAtom::Presetup();
    CElectron::Presetup();
    CHECK(CAtom::Initiate(pool_size)) << "初始化atom错误"; 
    CHECK(CElectron::Initiate(pool_size)) << "初始化electron错误";
}

AtomAutoInit::~AtomAutoInit()
{
    CElectron::Shutdown();
    CAtom::Shutdown();
    CElectron::Destruct();
    CAtom::Destruct();
}

