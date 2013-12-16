#ifndef TAGPRIMITIVE_H
#define TAGPRIMITIVE_H
//Begin section for file tagPrimitive.h
//TODO: Add definitions that you want preserved
//End section for file tagPrimitive.h

namespace atom
{

	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_eC45YKxiEdyG2OUyJIn0qA"
	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	template <class A, class T, bool save>
	struct tagPrimitive
	{
	
	    //Begin section for si::tagPrimitive
	    //TODO: Add attributes that you want preserved
	    //End section for si::tagPrimitive
	    public:
	
	        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	        inline static void Invoke(A & ar, T & t)
	        {
	        	//TODO Auto-generated method stub
	        	ar.Bind( t );
	        }
	
	};  //end struct tagPrimitive

} // end namespace atom

#endif
