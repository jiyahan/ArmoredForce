#ifndef IS_VOID_H
#define IS_VOID_H
//Begin section for file is_void.h
//TODO: Add definitions that you want preserved
//End section for file is_void.h

namespace atom
{

	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_YCqgoKrTEdyD0JEDwWRqLg"
	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	template <class T>
	struct is_void
	{
	
	    //Begin section for si::is_void
	    //TODO: Add attributes that you want preserved
	    //End section for si::is_void
        static const bool value = false;
	
	};  //end struct is_void

	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_YCqgoKrTEdyD0JEDwWRqLg"
	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	template <>
	struct is_void<void>
	{
	
	    //Begin section for si::is_void
	    //TODO: Add attributes that you want preserved
	    //End section for si::is_void
        static const bool value = true;
	
	};  //end struct is_void

} //end namespace atom

#endif
