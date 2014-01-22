#ifndef IS_PRIMITIVE_H
#define IS_PRIMITIVE_H

#include "is_integral.h"
#include "is_float_point.h"
#include "is_character.h"
#include "or.h"

namespace atom
{
	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_yOuikKxMEdyUN_dz_O82bQ"
	template <typename T>
	struct is_primitive
	{
	
	    static const bool value = 
            atom_or< atom_or<
                is_character  <T>::value,
                is_integral   <T>::value>::value,
                is_float_point<T>::value>::value;
	
	};  //end struct is_primitive
	
} // end namespace si

#endif
