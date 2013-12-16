#ifndef IS_ARRAY_H
#define IS_ARRAY_H
//Begin section for file is_array.h
//TODO: Add definitions that you want preserved
//End section for file is_array.h

namespace atom
{
	 
	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_-uMWQKrTEdyD0JEDwWRqLg"
	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	template <class T>
	struct is_array
	{
	
	    //Begin section for si::is_array
	    //TODO: Add attributes that you want preserved
	    //End section for si::is_array
	    static const bool value = false;
	
	};  //end struct is_array

	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_-uMWQKrTEdyD0JEDwWRqLg"
	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	template <class T, size_t N>
	struct is_array<T[N]>
	{
	
	    //Begin section for si::is_array
	    //TODO: Add attributes that you want preserved
	    //End section for si::is_array
	    static const bool value = true;
	
	};  //end struct is_array

} // end namespace atom

#endif
