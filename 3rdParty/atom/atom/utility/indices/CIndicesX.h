#ifndef CINDICESX_H
#define CINDICESX_H
//Begin section for file CIndicesX.h
//TODO: Add definitions that you want preserved
//End section for file CIndicesX.h
#include "CIndices.h"
#include "../../os/thread/CReference.h"


namespace atom
{
	


	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	template <class T, size_t S = 4>
	class CIndicesX
	{

		//Begin section for atom::CIndicesX
		//TODO: Add attributes that you want preserved
		//End section for atom::CIndicesX

		private:


			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CIndices<T> indices[S];



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CReference acquire;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CReference release;




		public:


			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CIndicesX()
			{
				//TODO Auto-generated method stub
			}


			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual ~CIndicesX()
			{
				//TODO Auto-generated method stub
				Clear();
			}


			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			void  Clear()
			{
				//TODO Auto-generated method stub
				for( size_t i = 0; i < S; ++ i )
				{
				    indices[i].Clear();
				}
			}


			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			void  SetLimit(size_t value)
			{
				//TODO Auto-generated method stub
				for( size_t i = 0; i < S; ++ i )
				{
				    indices[i].SetLimit( value );
				}
			}


			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			bool  Insert(const T & value)
			{
				//TODO Auto-generated method stub
				size_t offset = static_cast<size_t>( release.Increase() ) % S;
				return indices[offset].Insert( value );
			}


			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            template<class A>
			bool  Insert(const vector<T, A> & value)
			{
				//TODO Auto-generated method stub
				bool result = false;
				size_t offset = static_cast<unsigned>( release.Increase() ) % S;
				for( size_t i = offset, j = offset + S; i < j; ++ i )
				{
				    result = indices[i % S].Insert( value );
					if( result ) break;
				}
				return result;
			}


			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			bool  Obtain(T & value)
			{
				//TODO Auto-generated method stub
				bool result = false;
				size_t offset = static_cast<unsigned>( acquire.Increase() ) % S;
				for( size_t i = offset, j = offset + S; i < j; ++ i )
				{
				    result = indices[i % S].Obtain( value );
					if( result ) break;
				}
				return result;
			}


			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            template<class A>
			void  Obtain(vector<T, A> & value, bool is_union = false)
			{
				//TODO Auto-generated method stub
				for( size_t i = 0; i < S; ++ i )
				{
				    indices[i].Obtain( value, is_union );
				}
			}

	};  //end class CIndicesX



} //end namespace atom



#endif
