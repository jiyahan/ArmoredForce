#ifndef CINDICES_H
#define CINDICES_H
//Begin section for file CIndices.h
//TODO: Add definitions that you want preserved
//End section for file CIndices.h
#include "../../os/thread/CCriticalSection.h"
#include "../stl/allocator.h"



namespace atom
{
	


	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	template <class T>
	class CIndices
	{

		//Begin section for atom::CIndices
		//TODO: Add attributes that you want preserved
		//End section for atom::CIndices

		public:


			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			typedef list<T, atom_allocator<T> >  CIndicesBind;

		private:


			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			size_t limit;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CIndicesBind index;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CCriticalSection entry;




		public:


			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CIndices(): 
			limit(0)
			{
				//TODO Auto-generated method stub
			}


			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual ~CIndices()
			{
				//TODO Auto-generated method stub
				Clear();
			}


			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			void  Clear()
			{
				//TODO Auto-generated method stub
				entry.Enter();
				index.clear(); limit = 0;
				entry.Leave();
			}


			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			void  SetLimit(size_t value)
			{
				//TODO Auto-generated method stub
				entry.Enter();
				limit = value;
				entry.Leave();
			}


			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			bool  Insert(const T & value)
			{
				//TODO Auto-generated method stub
			    bool result = false;
			    entry.Enter();
			    if( ( limit == 0 ) || ( limit >= index.size() ) ) {
			    	index.push_back( value ); result = true;
			    }
				entry.Leave();
			    return result;
			}


			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			template <class A>
			bool  Insert(const vector<T, A> & value)
			{
				//TODO Auto-generated method stub
			    bool result = false;
			    if( value.empty() == false )
			    {
				    entry.Enter();
				    if( ( limit == 0 ) || 
				    	( limit >= index.size() + value.size() ) )
				    {
				    	std::copy( value.begin(), value.end(), back_inserter(index) );
						result = true;
				    }
				    entry.Leave();
			    }
			    return result;
			}


			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			bool  Obtain(T & output)
			{
				//TODO Auto-generated method stub
	        	bool result = false;
			    entry.Enter();
			    if( index.empty() == false ) 
			    {
					result = true;
			    	output = index.back(); index.pop_back();
			    }
			    entry.Leave();
			    return result;
			}


			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            template<class A>
			void  Obtain(vector<T, A> & value, bool is_union = false)
			{
				//TODO Auto-generated method stub
			    CIndicesBind set;
			    
			    // �Ƚ��������ݣ�Ȼ���ٿ�����
			    entry.Enter();
			    index.swap ( set );
			    entry.Leave();
			    
			    // ���û��Ҫ���ǲ�������ֱ�ӿ��������Ҫ���ǲ��������Ƚ����
			    // �����ٽ����������out������
			    if( is_union == false )
			    {
					// ֱ�ӿ�����ĩβ��
                    value.reserve( value.size() + set.size() );
			    	std::copy( set.begin(), set.end(), back_inserter(value) );
			    }
			    else
			    {
					// Ԥ�ȷ����㹻���ڴ棻
			    	vector<T,A> result;
                    result.reserve( set.size() + value.size() );

					// ��������������
                    set.sort();
                    std::sort( value.begin(), value.end() );

					// ��������������н�����
					typename CIndicesBind::iterator it = 
						std::unique( set.begin(), set.end() );
			    	std::set_union ( set.begin(), it,					
			    		value.begin(), value.end(), back_inserter(result) );
			    	value.swap( result );
				}
			}

	};  //end class CIndices



} //end namespace atom



#endif
