#ifndef OR_H
#define OR_H
//Begin section for file or.h
//TODO: Add definitions that you want preserved
//End section for file or.h

namespace atom
{
	
	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_3npqAKrWEdyD0JEDwWRqLg"
	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	template <bool C1, bool C2>
	struct atom_or
	{
	
	    //Begin section for si::or
	    //TODO: Add attributes that you want preserved
	    //End section for si::or
        static const bool value = true;
	
	};  //end struct or

	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_3npqAKrWEdyD0JEDwWRqLg"
	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	template <>
	struct atom_or<false, false>
	{
	
	    //Begin section for si::or
	    //TODO: Add attributes that you want preserved
	    //End section for si::or
        static const bool value = false;
	
	};  //end struct or 
	
} // end namespace atom

#endif
