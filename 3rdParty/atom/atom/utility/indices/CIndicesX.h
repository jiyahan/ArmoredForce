#ifndef CINDICESX_H
#define CINDICESX_H
#include "CIndices.h"
#include "../../os/thread/CReference.h"


namespace atom
{
	


	template <class T, size_t S = 4>
	class CIndicesX
	{


		private:


			CIndices<T> indices[S];



			CReference acquire;



			CReference release;




		public:


			CIndicesX()
			{
			}


			virtual ~CIndicesX()
			{
				Clear();
			}


			void  Clear()
			{
				for( size_t i = 0; i < S; ++ i )
				{
				    indices[i].Clear();
				}
			}


			void  SetLimit(size_t value)
			{
				for( size_t i = 0; i < S; ++ i )
				{
				    indices[i].SetLimit( value );
				}
			}


			bool  Insert(const T & value)
			{
				size_t offset = static_cast<size_t>( release.Increase() ) % S;
				return indices[offset].Insert( value );
			}


            template<class A>
			bool  Insert(const vector<T, A> & value)
			{
				bool result = false;
				size_t offset = static_cast<unsigned>( release.Increase() ) % S;
				for( size_t i = offset, j = offset + S; i < j; ++ i )
				{
				    result = indices[i % S].Insert( value );
					if( result ) break;
				}
				return result;
			}


			bool  Obtain(T & value)
			{
				bool result = false;
				size_t offset = static_cast<unsigned>( acquire.Increase() ) % S;
				for( size_t i = offset, j = offset + S; i < j; ++ i )
				{
				    result = indices[i % S].Obtain( value );
					if( result ) break;
				}
				return result;
			}


            template<class A>
			void  Obtain(vector<T, A> & value, bool is_union = false)
			{
				for( size_t i = 0; i < S; ++ i )
				{
				    indices[i].Obtain( value, is_union );
				}
			}

	};  //end class CIndicesX



} //end namespace atom



#endif
