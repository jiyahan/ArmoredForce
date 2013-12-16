#ifndef IS_POINTER_H
#define IS_POINTER_H
//Begin section for file is_pointer.h
//TODO: Add definitions that you want preserved
//End section for file is_pointer.h

namespace atom
{

	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_SkdA8KrSEdyD0JEDwWRqLg"
	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	template <class T>
	struct is_pointer
	{
	
	    //Begin section for si::is_pointer
	    //TODO: Add attributes that you want preserved
	    //End section for si::is_pointer
	    static const bool value = false;
	
	};  //end Class is_pointer
	

	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_SkdA8KrSEdyD0JEDwWRqLg"
	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	template <class T>
	struct is_pointer<T*>
	{
	
	    //Begin section for si::is_pointer
	    //TODO: Add attributes that you want preserved
	    //End section for si::is_pointer
	    static const bool value = true;
	
	};  //end Class is_pointer
	
} // end namespace atom

#endif
