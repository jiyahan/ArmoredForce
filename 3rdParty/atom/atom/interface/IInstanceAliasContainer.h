#ifndef IINSTANCEALIASCONTAINER_H
#define IINSTANCEALIASCONTAINER_H
#include "IEmbedInterface.h"
#include "../utility/tool/CObjectPtr.h"
#include "../utility/stl/allocator.h"



namespace atom
{



    template <class T>
    class IInstanceAliasContainer : public IEmbedInterface
    {




        public:


            virtual bool  Insert(const T & alias, CObjectPtr & instance) = 0;



            virtual CObjectPtr  Obtain(const T & alias) = 0;



            virtual void  Obtain(std::vector<T, atom_allocator<T> > & out) = 0;

        

            virtual bool  Inside(const T & alias) = 0;



            virtual U64  Amount() = 0;



            virtual bool  Remove(const T & alias) = 0;



            virtual void  RemoveAll() = 0;



    };  //end class IInstanceAliasContainer



} //end namespace atom



#endif
