#ifndef IS_PRIMITIVE_H
#define IS_PRIMITIVE_H
//Begin section for file is_primitive.h
//TODO: Add definitions that you want preserved
//End section for file is_primitive.h

#include "is_integral.h"
#include "is_float_point.h"
#include "is_character.h"
#include "or.h"

namespace atom
{
	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_yOuikKxMEdyUN_dz_O82bQ"
	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	template <typename T>
	struct is_primitive
	{
	
	    //Begin section for si::is_primitive
	    //TODO: Add attributes that you want preserved
	    //End section for si::is_primitive
	    static const bool value = 
            atom_or< atom_or<
                is_character  <T>::value,
                is_integral   <T>::value>::value,
                is_float_point<T>::value>::value;
	
	};  //end struct is_primitive
	
} // end namespace si

#endif
