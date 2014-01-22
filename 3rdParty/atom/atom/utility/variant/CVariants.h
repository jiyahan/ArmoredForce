#ifndef CVARIANTS_H
#define CVARIANTS_H
#include "CVariantsBind.h"
#include "CVariant.h"
#include "../stl/stl_extend.h"



namespace atom
{



    class CVariants
    {


        private:


            CVariantsBind variants;




        public:

            CVariants(); 



            CVariants(const CVariants & value); 



            ~CVariants(); 



            void Clear(); 



            size_t Amount()const ; 



            bool Append(const char * name, const CVariant & data); 



            bool Remove(const char * name); 



            bool Remove(size_t offset); 



            bool Obtain(const char * name, CVariant & data)const ; 



            bool Obtain(size_t offset, CVariant & data)const ; 



            bool Obtain(size_t offset, a_string & name)const ; 



            CVariants & operator =(const CVariants & value); 



			template<class T>
			const T Obtain(const char * name)
			{
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



			template<class T>
			const T Obtain(size_t offset)
			{
                T value; 
				initialize<T> method; method( value );

				if( offset < variants.size() ) {
					value = static_cast<T>( variants[offset].second );
				}
				return value;
			}



            template<class A>
            void Serialize(A & ar, bool is_save)
            {
                UNREFERENCED_PARAMETER( is_save );
                ar.Bind( variants );
            }



    };  //end class CVariants



} //end namespace atom



#endif
