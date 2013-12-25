#pragma once

#include <memory>


class Monster;
typedef std::shared_ptr<Monster>    MonsterPtr;

class Monster
{
public:
    Monster();
    ~Monster();

    void    Attack(OfficerPtr defender);
    void    Defense(OfficerPtr attacker);

private:

};


