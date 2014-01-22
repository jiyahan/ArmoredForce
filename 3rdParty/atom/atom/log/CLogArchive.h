#ifndef CLOGARCHIVE_H
#define CLOGARCHIVE_H
#include "../interface/ILogArchive.h"
#include "../interface/IInterface.h"
#include "../utility/stl/a_string.h"



namespace atom
{



    class CLogArchive : public ILogArchive
    {


        private:


            IInterface * nest;



            a_string data;




        public:

            CLogArchive(); 



            virtual ~CLogArchive(); 



            virtual int IncRef(); 



            virtual int DecRef(); 



            virtual int GetRef(); 



            virtual IInterface * QueryInterface(U32 iid); 



            virtual void SetNest(IInterface * nest); 



            virtual void Append(const char * value); 



            virtual void Finish(U08 level); 



    };  //end class CLogArchive



} //end namespace atom



#endif
