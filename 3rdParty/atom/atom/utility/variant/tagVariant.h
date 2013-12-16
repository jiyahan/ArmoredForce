#ifndef TAGVARIANT_H
#define TAGVARIANT_H
//Begin section for file tagVariant.h
//TODO: Add definitions that you want preserved
//End section for file tagVariant.h
#include "../../os/memory/CMemory.h"



namespace atom
{
	


	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	struct tagVariant
	{

		//Begin section for atom::tagVariant
		//TODO: Add attributes that you want preserved
		//End section for atom::tagVariant

		public:


			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			union tagVariantPrimitive
			{

				//Begin section for atom::tagVariant::tagVariantPrimitive
				//TODO: Add attributes that you want preserved
				//End section for atom::tagVariant::tagVariantPrimitive



				public:


					//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
					I64 i;



					//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
					U64 u;



					//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
					double f;



			};  //end union tagVariantPrimitive




		public:


			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			U32 type;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			tagVariantPrimitive base;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CMemory data;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			tagVariant(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			tagVariant(const tagVariant & value); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			~tagVariant(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
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
