#ifndef AND_H
#define AND_H

namespace atom
{
	
	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_JSBPcKrWEdyD0JEDwWRqLg"
	template <bool C1, bool C2>
	struct atom_and
	{
	
        static const bool value = false;
	
	};  //end struct and

	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_JSBPcKrWEdyD0JEDwWRqLg"
	template <>
	struct atom_and<true, true>
	{
	
	    static const bool value = true;
	
	};  //end struct and
	
} // end namespace atom

#endif
