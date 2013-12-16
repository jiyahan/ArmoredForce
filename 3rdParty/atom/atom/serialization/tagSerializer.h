#ifndef TAGSERIALIZER_H
#define TAGSERIALIZER_H
//Begin section for file tagSerializer.h
//TODO: Add definitions that you want preserved
//End section for file tagSerializer.h

#include "trait/is_primitive.h"
#include "trait/is_array.h"
#include "trait/is_class.h"
#include "trait/is_pointer.h"
#include "trait/if_else.h"
#include "trait/degradation_trait.h"
#include "tagPrimitive.h"
#include "tagArray.h" 
#include "tagClass.h"
#include "tagInvalid.h"

namespace atom
{
	
	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_BTpPEKxUEdyG2OUyJIn0qA"
	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	template <class A, class T, bool B>
	struct tagSerializer
	{
	
	    //Begin section for si::tagSerializer
	    //TODO: Add attributes that you want preserved
	    //End section for si::tagSerializer
	    public:
	
	        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	        inline static void Serialize(A & archive, T & data)
	        {
	        	//TODO Auto-generated method stub
                typedef typename 
                degradation_trait<T>::type C;

				typedef 
				typename
				if_else<is_array<C>::value,
					tagArray<A, C, B>, 
					typename
					if_else<is_class<C>::value, 
						tagClass<A, C, B>, 
						typename
						if_else<is_primitive<C>::value,
						    tagPrimitive<A, C, B>,
						    tagInvalid  <A, C, B>
						>::type 
					>::type 
				>::type Invoker;
		
				Invoker::Invoke( archive, type_cast(data) );
			}
	
	};  //end struct tagSerializer
	
} // end namespace atom

#endif
