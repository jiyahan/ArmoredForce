#include "Troop.h"


Troop::Troop()
{
    last_attacker_ = 0;
    last_defender_ = 0;
}

Troop::~Troop()
{

}

Officer*  Troop::GetOfficer(U16 pos)
{
    if (pos > 0 && pos <= formation_.max_size())
    {
        return formation_.at(pos-1);
    }
    return nullptr;
}

U16  Troop::GetNextAttacker()
{
    for ()
    return 0;
}

U16    Troop::GetNextDefender()
{
    return 0;
}