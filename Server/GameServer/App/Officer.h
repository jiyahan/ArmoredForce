#pragma once

#include <memory>
#include "common/OfficerCommon.h"


class Officer;
typedef std::shared_ptr<Officer>    OfficerPtr;

// 军官
class Officer
{
public:
    Officer();
    ~Officer();

    void    Attack(OfficerPtr defender);
    void    Defense(OfficerPtr attacker);

private:
    OfficerCommon       property_;  // 基础属性
};



