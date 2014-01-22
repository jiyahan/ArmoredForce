#ifndef OR_H
#define OR_H

namespace atom
{
	
	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_3npqAKrWEdyD0JEDwWRqLg"
	template <bool C1, bool C2>
	struct atom_or
	{
	
        static const bool value = true;
	
	};  //end struct or

	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_3npqAKrWEdyD0JEDwWRqLg"
	template <>
	struct atom_or<false, false>
	{
	
        static const bool value = false;
	
	};  //end struct or 
	
} // end namespace atom

#endif
