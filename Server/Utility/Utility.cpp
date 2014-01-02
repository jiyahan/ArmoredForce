#include "Utility.h"
#include <glog/logging.h>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/random_generator.hpp>
#include <atom/CAtom.h>
#include <electron/CElectron.h>


using atom::CAtom;
using electron::CElectron;


std::string  GetUniqueID()
{
    using namespace boost::uuids;
    return std::move(to_string(random_generator()()));
}

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

