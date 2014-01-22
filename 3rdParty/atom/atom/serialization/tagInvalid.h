#ifndef TAGINVALID_H
#define TAGINVALID_H

namespace atom
{
	
	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_sf1OoKxjEdyG2OUyJIn0qA"
	template <class A, class T, bool save>
	struct tagInvalid
	{
	
	    public:
	
	        inline static void Invoke(A & a, T & t)
	        {
                UNREFERENCED_PARAMETER(a);
                UNREFERENCED_PARAMETER(t);

				printf( "Serialization NOT support these keyword: mutable\n" );
	        }
	
	};  //end struct tagInvalid
	
} // end namespace atom

#endif
