#include "Utility.h"
#include "easylogging++.h"
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/random_generator.hpp>
#include <atom/CAtom.h>
#include <electron/CElectron.h>


using namespace atom;
using namespace electron;


std::string  CreateUniqueID()
{
    using namespace boost::uuids;
    return std::move(to_string(random_generator()()));
}

AtomAutoInit::AtomAutoInit(int32_t pool_size, int32_t thread_num)
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

