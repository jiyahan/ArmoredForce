#ifndef IFLUSHDEVICE_H
#define IFLUSHDEVICE_H
//Begin section for file IFlushDevice.h
//TODO: Add definitions that you want preserved
//End section for file IFlushDevice.h
#include "IEmbedInterface.h"
#include "../os/memory/CMemory.h"



namespace atom
{



     //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
     class IFlushDevice : public IEmbedInterface
     {

         //Begin section for atom::IFlushDevice
         //TODO: Add attributes that you want preserved
         //End section for atom::IFlushDevice



         public:

             //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
             virtual bool OnFlush(CMemory & value) = 0; 



     };  //end class IFlushDevice


}//end namespace atom


#endif
