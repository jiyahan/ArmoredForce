#ifndef NOT_H
#define NOT_H
//Begin section for file not.h
//TODO: Add definitions that you want preserved
//End section for file not.h

namespace atom
{

	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_9sHt4KrWEdyD0JEDwWRqLg"
	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	template <bool C>
	struct atom_not
	{
	
	    //Begin section for si::not
	    //TODO: Add attributes that you want preserved
	    //End section for si::not
	    static const bool value = false;
	
	};  //end struct not

	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_9sHt4KrWEdyD0JEDwWRqLg"
	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	template <>
	struct atom_not<false>
	{
	
	    //Begin section for si::not
	    //TODO: Add attributes that you want preserved
	    //End section for si::not
	    static const bool value = true;
	
	};  //end struct not
	
} // end namespace atom

#endif
