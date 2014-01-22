#ifndef ARRAY_TRAIT_H
#define ARRAY_TRAIT_H

namespace atom
{
	
	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_cm8lMKx1EdyG2OUyJIn0qA"
	template <typename T>
	struct array_trait
	{
	
	    typedef T type;
	    static const size_t bound = 1;
	
	};  //end struct array_trait

	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_cm8lMKx1EdyG2OUyJIn0qA"
	template <typename T, size_t N>
	struct array_trait<T[N]>
	{
	
	    typedef T type;
	    static const size_t bound = N;
	
	};  //end struct array_trait
	
	// Function GetArrayBound, retrieve array's bound;
	template <typename T>
	static size_t GetArrayBound(T& t)
	{
		return array_trait<T>::bound;
	}	//end function GetArrayBound
	
} // end namespace atom

#endif
