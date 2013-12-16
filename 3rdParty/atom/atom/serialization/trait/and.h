#ifndef AND_H
#define AND_H
//Begin section for file and.h
//TODO: Add definitions that you want preserved
//End section for file and.h

namespace atom
{
	
	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_JSBPcKrWEdyD0JEDwWRqLg"
	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	template <bool C1, bool C2>
	struct atom_and
	{
	
	    //Begin section for si::and
	    //TODO: Add attributes that you want preserved
	    //End section for si::and
        static const bool value = false;
	
	};  //end struct and

	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_JSBPcKrWEdyD0JEDwWRqLg"
	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	template <>
	struct atom_and<true, true>
	{
	
	    //Begin section for si::and
	    //TODO: Add attributes that you want preserved
	    //End section for si::and
	    static const bool value = true;
	
	};  //end struct and
	
} // end namespace atom

#endif
