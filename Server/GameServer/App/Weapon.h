#pragma once

#include <boost/noncopyable.hpp>

// 军备
class Weapon : private boost::noncopyable
{
public:
    Weapon();
    ~Weapon();

private:
};

typedef std::shared_ptr<Weapon>    WeaponPtr;
