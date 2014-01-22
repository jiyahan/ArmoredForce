#ifndef NOT_H
#define NOT_H

namespace atom
{

	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_9sHt4KrWEdyD0JEDwWRqLg"
	template <bool C>
	struct atom_not
	{
	
	    static const bool value = false;
	
	};  //end struct not

	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_9sHt4KrWEdyD0JEDwWRqLg"
	template <>
	struct atom_not<false>
	{
	
	    static const bool value = true;
	
	};  //end struct not
	
} // end namespace atom

#endif
