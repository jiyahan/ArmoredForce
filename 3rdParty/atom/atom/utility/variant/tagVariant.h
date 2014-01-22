#ifndef TAGVARIANT_H
#define TAGVARIANT_H
#include "../../os/memory/CMemory.h"



namespace atom
{
	


	struct tagVariant
	{


		public:


			union tagVariantPrimitive
			{




				public:


					I64 i;



					U64 u;



					double f;



			};  //end union tagVariantPrimitive




		public:


			U32 type;



			tagVariantPrimitive base;



			CMemory data;



			tagVariant(); 



			tagVariant(const tagVariant & value); 



			~tagVariant(); 



			tagVariant & operator=(const tagVariant & value); 



	};  //end struct tagVariant



} //end namespace atom


template<class A>
inline void Serialize(A & ar, atom::tagVariant & t, bool save)
{
	UNREFERENCED_PARAMETER(save);
    ar.Bind( t.type   );
    ar.Bind( t.base.u );
    ar.Bind( t.data   );
}

#endif
