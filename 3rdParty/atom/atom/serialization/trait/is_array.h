#ifndef IS_ARRAY_H
#define IS_ARRAY_H

namespace atom
{
	 
	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_-uMWQKrTEdyD0JEDwWRqLg"
	template <class T>
	struct is_array
	{
	
	    static const bool value = false;
	
	};  //end struct is_array

	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_-uMWQKrTEdyD0JEDwWRqLg"
	template <class T, size_t N>
	struct is_array<T[N]>
	{
	
	    static const bool value = true;
	
	};  //end struct is_array

} // end namespace atom

#endif
