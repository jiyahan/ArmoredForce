#ifndef DEGRADATION_TRAIT_H
#define DEGRADATION_TRAIT_H
#include "../../utility/stl/stl_extend.h"

namespace atom
{
	
	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_cm8lMKx1EdyG2OUyJIn0qA"
	template <typename T>
	struct degradation_trait
	{
	
	    typedef T type;
	
	};  //end struct degradation_trait

	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_cm8lMKx1EdyG2OUyJIn0qA"
	template <typename T>
	struct degradation_trait<volatile T>
	{
	
	    typedef T type;
	
	};  //end struct degradation_trait
	
	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_cm8lMKx1EdyG2OUyJIn0qA"
	template <typename T>
	struct degradation_trait<T*>
	{
	
	    typedef T type;
	
	};  //end struct degradation_trait
    
	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_cm8lMKx1EdyG2OUyJIn0qA"
	template <typename T>
	struct degradation_trait<volatile T*>
	{
	
	    typedef T type;
	
	};  //end struct degradation_trait

    template <typename T>
	static T & type_cast(T & t)
	{
		return t;
	}	//end function GetArrayBound

	template <typename T>
	static T & type_cast(volatile T & t)
	{
		return (T)(t);
	}	//end function GetArrayBound

	template <typename T>
	static T & type_cast(T* & t)
	{
        if( t == NULL ) 
        {
            printf( "atom::type_cast: pointer of type[%s] is NULL\n", typeid(t).name() );

            static T value;
            atom::initialize<T> initiate;
            initiate(value);
            return value;
        }

		return (*t);
	}	//end function GetArrayBound

	template <typename T>
	static T & type_cast(volatile T* & t)
	{
        if( t == NULL ) 
        {
            printf( "atom::type_cast: pointer of type[%s] is NULL\n", typeid(t).name() );

            static T value;
            atom::initialize<T> initiate;
            initiate(value);
            return value;
        }

		return (T)(*t);
	}	//end function GetArrayBound

} // end namespace atom

#endif
