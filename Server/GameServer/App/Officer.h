#pragma once

#include <memory>
#include "Card.h"
#include "common/OfficerCommon.h"



// 军官
class Officer : public Card
{
public:
    Officer();
    ~Officer();

private:
    OfficerCommon       property_;  // 基础属性
};


typedef std::shared_ptr<Officer>    OfficerPtr;
