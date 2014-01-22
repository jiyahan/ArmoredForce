#ifndef IS_VOID_H
#define IS_VOID_H

namespace atom
{

	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_YCqgoKrTEdyD0JEDwWRqLg"
	template <class T>
	struct is_void
	{
	
        static const bool value = false;
	
	};  //end struct is_void

	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_YCqgoKrTEdyD0JEDwWRqLg"
	template <>
	struct is_void<void>
	{
	
        static const bool value = true;
	
	};  //end struct is_void

} //end namespace atom

#endif
