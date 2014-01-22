#ifndef IS_CLASS_H
#define IS_CLASS_H

namespace atom
{
	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_sQjg0KrUEdyD0JEDwWRqLg"
	template <typename T>
	struct is_class_impl
	{
	    
		template<typename U>
		static long is_class_tester( void(U::*)(void) );
	    
		template<typename U>
		static char is_class_tester( ... );
		
		static const bool value =
			sizeof( is_class_tester<T>(0) ) == sizeof( long );
	
	};  //end struct is_class_tester
	
	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_sQjg0KrUEdyD0JEDwWRqLg"
	template <typename T>
	struct is_class
	{
	
	    static const bool value = is_class_impl<T>::value;
	
	};  //end struct is_class

} // end namespace atom

#endif
