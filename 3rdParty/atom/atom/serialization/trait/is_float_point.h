#ifndef IS_FLOAT_POINT_H
#define IS_FLOAT_POINT_H

namespace atom
{

	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_IS2L8KxLEdyUN_dz_O82bQ"
	template <typename T>
	struct is_float_point
	{
	
        static const bool value = false;
	
	};  //end struct is_float_point
	
	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_IS2L8KxLEdyUN_dz_O82bQ"
	template <>
	struct is_float_point<float>
	{
	
        static const bool value = true;
	
	};  //end struct is_float_point

	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_IS2L8KxLEdyUN_dz_O82bQ"
	template <>
	struct is_float_point<double>
	{
	
        static const bool value = true;
	
	};  //end struct is_float_point

} // end namespace si

#endif
