#ifndef TAGARRAY_H
#define TAGARRAY_H

#include "trait/array_trait.h"

namespace atom
{
	
	//@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_GwgikKxjEdyG2OUyJIn0qA"
	template <class A, class T, bool save>
	struct tagArray
	{
	
	    public:
	
	        inline static void Invoke(A & ar, T & t)
	        {
	        	// ��ȡ��д������ĳ��ȣ�
	        	U32 bound = static_cast<U32>( array_trait<T>::bound );
                U32 limit = bound;
	        	ar.Bind( bound );

                // ȷ������ĳ����Ƿ�Խ�磻
                bound = atom_min( bound, limit );
	        	
	        	// ��ȡ��д�������Ԫ�أ�
	        	for( size_t i = 0; i < bound; ++ i )
	        	{
	        		ar.Bind( t[i] );
	        	}
	        }
	
	};  //end struct tagArray
	
} // end namespace atom

#endif
