#ifndef CVARIANTS_H
#define CVARIANTS_H
//Begin section for file CVariants.h
//TODO: Add definitions that you want preserved
//End section for file CVariants.h
#include "CVariantsBind.h"
#include "CVariant.h"
#include "../stl/stl_extend.h"



namespace atom
{



    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    class CVariants
    {

        //Begin section for atom::CVariants
        //TODO: Add attributes that you want preserved
        //End section for atom::CVariants

        private:


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CVariantsBind variants;




        public:

            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CVariants(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CVariants(const CVariants & value); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            ~CVariants(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            void Clear(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            size_t Amount()const ; 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            bool Append(const char * name, const CVariant & data); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            bool Remove(const char * name); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            bool Remove(size_t offset); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            bool Obtain(const char * name, CVariant & data)const ; 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            bool Obtain(size_t offset, CVariant & data)const ; 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            bool Obtain(size_t offset, a_string & name)const ; 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CVariants & operator =(const CVariants & value); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			template<class T>
			const T Obtain(const char * name)
			{
				//TODO Auto-generated method stub
                T value; 
				initialize<T> method; method( value );

                if( name )
				{
					for( size_t i = 0, j = variants.size(); i < j; ++ i )
					{
						if( variants[i].first == name ) {
							value = static_cast<T>( variants[i].second );
							break;
						}
					}
				}
				return value;
			}



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			template<class T>
			const T Obtain(size_t offset)
			{
				//TODO Auto-generated method stub
                T value; 
				initialize<T> method; method( value );

				if( offset < variants.size() ) {
					value = static_cast<T>( variants[offset].second );
				}
				return value;
			}



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            template<class A>
            void Serialize(A & ar, bool is_save)
            {
                //TODO Auto-generated method stub
                UNREFERENCED_PARAMETER( is_save );
                ar.Bind( variants );
            }



    };  //end class CVariants



} //end namespace atom



#endif
