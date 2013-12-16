#ifndef IF_ELSE_H
#define IF_ELSE_H
//Begin section for file if_else.h
//TODO: Add definitions that you want preserved
//End section for file if_else.h

namespace atom
{

	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_kFtJ0KrVEdyD0JEDwWRqLg"
	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	template <bool C, typename T1, typename T2>
	struct if_else
	{
	
	    //Begin section for si::if_else
	    //TODO: Add attributes that you want preserved
	    //End section for si::if_else
	    typedef T1 type;
	
	};  //end struct if_else

	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_kFtJ0KrVEdyD0JEDwWRqLg"
	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	template <typename T1, typename T2>
	struct if_else<false, T1, T2>
	{
	
	    //Begin section for si::if_else
	    //TODO: Add attributes that you want preserved
	    //End section for si::if_else
	    typedef T2 type;
	
	};  //end struct if_else

} // end namespace atom

#endif
