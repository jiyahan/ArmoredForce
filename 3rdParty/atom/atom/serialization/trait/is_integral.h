#ifndef IS_INTEGRAL_H
#define IS_INTEGRAL_H
//Begin section for file is_integral.h
//TODO: Add definitions that you want preserved
//End section for file is_integral.h



namespace atom
{

	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_nfJ28KxLEdyUN_dz_O82bQ"
	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	template <typename T>
	struct is_integral
	{
	
	    //Begin section for si::is_integral
	    //TODO: Add attributes that you want preserved
	    //End section for si::is_integral
        static const bool value = false;
	
	};  //end struct is_integral
	
	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_nfJ28KxLEdyUN_dz_O82bQ"
	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	template <>
	struct is_integral<I08>
	{
	
	    //Begin section for si::is_integral
	    //TODO: Add attributes that you want preserved
	    //End section for si::is_integral
        static const bool value = true;
	
	};  //end struct is_integral

	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_nfJ28KxLEdyUN_dz_O82bQ"
	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	template <>
	struct is_integral<I16>
	{
	
	    //Begin section for si::is_integral
	    //TODO: Add attributes that you want preserved
	    //End section for si::is_integral
        static const bool value = true;
	
	};  //end struct is_integral

	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_nfJ28KxLEdyUN_dz_O82bQ"
	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	template <>
	struct is_integral<I32>
	{
	
	    //Begin section for si::is_integral
	    //TODO: Add attributes that you want preserved
	    //End section for si::is_integral
        static const bool value = true;
	
	};  //end struct is_integral

	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_nfJ28KxLEdyUN_dz_O82bQ"
	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	template <>
	struct is_integral<I64>
	{
	
	    //Begin section for si::is_integral
	    //TODO: Add attributes that you want preserved
	    //End section for si::is_integral
        static const bool value = true;
	
	};  //end struct is_integral

	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_nfJ28KxLEdyUN_dz_O82bQ"
	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	template <>
	struct is_integral<U08>
	{
	
	    //Begin section for si::is_integral
	    //TODO: Add attributes that you want preserved
	    //End section for si::is_integral
        static const bool value = true;
	
	};  //end struct is_integral

	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_nfJ28KxLEdyUN_dz_O82bQ"
	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	template <>
	struct is_integral<U16>
	{
	
	    //Begin section for si::is_integral
	    //TODO: Add attributes that you want preserved
	    //End section for si::is_integral
        static const bool value = true;
	
	};  //end struct is_integral

	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_nfJ28KxLEdyUN_dz_O82bQ"
	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	template <>
	struct is_integral<U32>
	{
	
	    //Begin section for si::is_integral
	    //TODO: Add attributes that you want preserved
	    //End section for si::is_integral
        static const bool value = true;
	
	};  //end struct is_integral

	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_nfJ28KxLEdyUN_dz_O82bQ"
	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	template <>
	struct is_integral<U64>
	{
	
	    //Begin section for si::is_integral
	    //TODO: Add attributes that you want preserved
	    //End section for si::is_integral
        static const bool value = true;
	
	};  //end struct is_integral

} // end namespace atom

#endif
