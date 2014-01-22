#ifndef IF_ELSE_H
#define IF_ELSE_H

namespace atom
{

	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_kFtJ0KrVEdyD0JEDwWRqLg"
	template <bool C, typename T1, typename T2>
	struct if_else
	{
	
	    typedef T1 type;
	
	};  //end struct if_else

	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_kFtJ0KrVEdyD0JEDwWRqLg"
	template <typename T1, typename T2>
	struct if_else<false, T1, T2>
	{
	
	    typedef T2 type;
	
	};  //end struct if_else

} // end namespace atom

#endif
