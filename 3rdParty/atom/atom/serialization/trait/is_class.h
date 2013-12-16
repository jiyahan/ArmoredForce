#ifndef IS_CLASS_H
#define IS_CLASS_H
//Begin section for file is_class.h
//TODO: Add definitions that you want preserved
//End section for file is_class.h

namespace atom
{
	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_sQjg0KrUEdyD0JEDwWRqLg"
	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	template <typename T>
	struct is_class_impl
	{
	    //Begin section for si::is_class
	    //TODO: Add attributes that you want preserved
	    //End section for si::is_class
	    
	    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
		template<typename U>
		static long is_class_tester( void(U::*)(void) );
	    
	    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
		template<typename U>
		static char is_class_tester( ... );
		
		//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
		static const bool value =
			sizeof( is_class_tester<T>(0) ) == sizeof( long );
	
	};  //end struct is_class_tester
	
	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_sQjg0KrUEdyD0JEDwWRqLg"
	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	template <typename T>
	struct is_class
	{
	
	    //Begin section for si::is_class
	    //TODO: Add attributes that you want preserved
	    //End section for si::is_class
	    static const bool value = is_class_impl<T>::value;
	
	};  //end struct is_class

} // end namespace atom

#endif
