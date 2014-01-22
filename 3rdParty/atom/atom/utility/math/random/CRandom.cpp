#include "CRandom.h"


void atom::CRandom::Initiate() 
{
    srand( static_cast<unsigned int>( time(NULL) ) );
}
