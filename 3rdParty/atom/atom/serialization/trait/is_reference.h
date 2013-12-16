#ifndef IS_REFERENCE_H
#define IS_REFERENCE_H
//Begin section for file is_reference.h
//TODO: Add definitions that you want preserved
//End section for file is_reference.h

namespace atom
{

	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_s_nbsKrTEdyD0JEDwWRqLg"
	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	template <class T>
	struct is_reference
	{
	
	    //Begin section for si::is_reference
	    //TODO: Add attributes that you want preserved
	    //End section for si::is_reference
	    static const bool value = false;
	
	};  //end struct is_reference
	
	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_s_nbsKrTEdyD0JEDwWRqLg"
	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	template <class T>
	struct is_reference<T&>
	{
	
	    //Begin section for si::is_reference
	    //TODO: Add attributes that you want preserved
	    //End section for si::is_reference
	    static const bool value = true;
	
	};  //end struct is_reference

} // end namespace atom

#endif
