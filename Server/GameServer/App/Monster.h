#pragma once

#include <memory>
#include "Card.h"

class Monster : public Card
{
public:
    Monster();
    ~Monster();

private:

};

typedef std::shared_ptr<Monster>    MonsterPtr;
