#ifndef IS_POINTER_H
#define IS_POINTER_H

namespace atom
{

	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_SkdA8KrSEdyD0JEDwWRqLg"
	template <class T>
	struct is_pointer
	{
	
	    static const bool value = false;
	
	};  //end Class is_pointer
	

	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_SkdA8KrSEdyD0JEDwWRqLg"
	template <class T>
	struct is_pointer<T*>
	{
	
	    static const bool value = true;
	
	};  //end Class is_pointer
	
} // end namespace atom

#endif
