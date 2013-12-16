#ifndef TAGINVALID_H
#define TAGINVALID_H
//Begin section for file tagInvalid.h
//TODO: Add definitions that you want preserved
//End section for file tagInvalid.h

namespace atom
{
	
	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_sf1OoKxjEdyG2OUyJIn0qA"
	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	template <class A, class T, bool save>
	struct tagInvalid
	{
	
	    //Begin section for si::tagInvalid
	    //TODO: Add attributes that you want preserved
	    //End section for si::tagInvalid
	    public:
	
	        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	        inline static void Invoke(A & a, T & t)
	        {
                UNREFERENCED_PARAMETER(a);
                UNREFERENCED_PARAMETER(t);

	        	//TODO Auto-generated method stub
				printf( "Serialization NOT support these keyword: mutable\n" );
	        }
	
	};  //end struct tagInvalid
	
} // end namespace atom

#endif
