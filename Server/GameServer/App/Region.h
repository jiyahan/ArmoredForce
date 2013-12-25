#pragma once

#include <memory>
#include <boost/noncopyable.hpp>

class Region : private boost::noncopyable
{
public:
    Region();
    ~Region();

private:

};

typedef std::shared_ptr<Region>     RegionPtr;
