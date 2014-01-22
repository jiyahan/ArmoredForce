#ifndef IS_REFERENCE_H
#define IS_REFERENCE_H

namespace atom
{

	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_s_nbsKrTEdyD0JEDwWRqLg"
	template <class T>
	struct is_reference
	{
	
	    static const bool value = false;
	
	};  //end struct is_reference
	
	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_s_nbsKrTEdyD0JEDwWRqLg"
	template <class T>
	struct is_reference<T&>
	{
	
	    static const bool value = true;
	
	};  //end struct is_reference

} // end namespace atom

#endif
