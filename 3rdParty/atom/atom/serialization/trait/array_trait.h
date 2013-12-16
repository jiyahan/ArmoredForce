#ifndef ARRAY_TRAIT_H
#define ARRAY_TRAIT_H
//Begin section for file array_trait.h
//TODO: Add definitions that you want preserved
//End section for file array_trait.h

namespace atom
{
	
	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_cm8lMKx1EdyG2OUyJIn0qA"
	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	template <typename T>
	struct array_trait
	{
	
	    //Begin section for si::array_trait
	    //TODO: Add attributes that you want preserved
	    //End section for si::array_trait
	    typedef T type;
	    static const size_t bound = 1;
	
	};  //end struct array_trait

	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_cm8lMKx1EdyG2OUyJIn0qA"
	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	template <typename T, size_t N>
	struct array_trait<T[N]>
	{
	
	    //Begin section for si::array_trait
	    //TODO: Add attributes that you want preserved
	    //End section for si::array_trait
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
