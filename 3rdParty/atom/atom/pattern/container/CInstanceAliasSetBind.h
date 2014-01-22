#ifndef CINSTANCEALIASSETBIND_H
#define CINSTANCEALIASSETBIND_H
#include "../../Common.h"



namespace atom
{



    template <class T>
    class CInstanceAliasSetBind
    {


        public:


            typedef std::map<T, U64, less<T>, atom_allocator<pair<T, U64> > >  type ;




    };  //end class CInstanceAliasSetBind



} //end namespace atom



#endif
