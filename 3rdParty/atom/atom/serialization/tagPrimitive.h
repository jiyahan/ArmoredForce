#ifndef TAGPRIMITIVE_H
#define TAGPRIMITIVE_H

namespace atom
{

	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_eC45YKxiEdyG2OUyJIn0qA"
	template <class A, class T, bool save>
	struct tagPrimitive
	{
	
	    public:
	
	        inline static void Invoke(A & ar, T & t)
	        {
	        	ar.Bind( t );
	        }
	
	};  //end struct tagPrimitive

} // end namespace atom

#endif
