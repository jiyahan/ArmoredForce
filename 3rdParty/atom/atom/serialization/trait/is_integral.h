#ifndef IS_INTEGRAL_H
#define IS_INTEGRAL_H



namespace atom
{

	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_nfJ28KxLEdyUN_dz_O82bQ"
	template <typename T>
	struct is_integral
	{
	
        static const bool value = false;
	
	};  //end struct is_integral
	
	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_nfJ28KxLEdyUN_dz_O82bQ"
	template <>
	struct is_integral<I08>
	{
	
        static const bool value = true;
	
	};  //end struct is_integral

	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_nfJ28KxLEdyUN_dz_O82bQ"
	template <>
	struct is_integral<I16>
	{
	
        static const bool value = true;
	
	};  //end struct is_integral

	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_nfJ28KxLEdyUN_dz_O82bQ"
	template <>
	struct is_integral<I32>
	{
	
        static const bool value = true;
	
	};  //end struct is_integral

	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_nfJ28KxLEdyUN_dz_O82bQ"
	template <>
	struct is_integral<I64>
	{
	
        static const bool value = true;
	
	};  //end struct is_integral

	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_nfJ28KxLEdyUN_dz_O82bQ"
	template <>
	struct is_integral<U08>
	{
	
        static const bool value = true;
	
	};  //end struct is_integral

	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_nfJ28KxLEdyUN_dz_O82bQ"
	template <>
	struct is_integral<U16>
	{
	
        static const bool value = true;
	
	};  //end struct is_integral

	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_nfJ28KxLEdyUN_dz_O82bQ"
	template <>
	struct is_integral<U32>
	{
	
        static const bool value = true;
	
	};  //end struct is_integral

	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_nfJ28KxLEdyUN_dz_O82bQ"
	template <>
	struct is_integral<U64>
	{
	
        static const bool value = true;
	
	};  //end struct is_integral

} // end namespace atom

#endif
