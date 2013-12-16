#ifndef IS_FLOAT_POINT_H
#define IS_FLOAT_POINT_H
//Begin section for file is_float_point.h
//TODO: Add definitions that you want preserved
//End section for file is_float_point.h

namespace atom
{

	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_IS2L8KxLEdyUN_dz_O82bQ"
	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	template <typename T>
	struct is_float_point
	{
	
	    //Begin section for si::is_float_point
	    //TODO: Add attributes that you want preserved
	    //End section for si::is_float_point
        static const bool value = false;
	
	};  //end struct is_float_point
	
	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_IS2L8KxLEdyUN_dz_O82bQ"
	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	template <>
	struct is_float_point<float>
	{
	
	    //Begin section for si::is_float_point
	    //TODO: Add attributes that you want preserved
	    //End section for si::is_float_point
        static const bool value = true;
	
	};  //end struct is_float_point

	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_IS2L8KxLEdyUN_dz_O82bQ"
	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	template <>
	struct is_float_point<double>
	{
	
	    //Begin section for si::is_float_point
	    //TODO: Add attributes that you want preserved
	    //End section for si::is_float_point
        static const bool value = true;
	
	};  //end struct is_float_point

} // end namespace si

#endif
