#ifndef CINDICES_H
#define CINDICES_H
#include "../../os/thread/CCriticalSection.h"
#include "../stl/allocator.h"



namespace atom
{
	


	template <class T>
	class CIndices
	{


		public:


			typedef list<T, atom_allocator<T> >  CIndicesBind;

		private:


			size_t limit;



			CIndicesBind index;



			CCriticalSection entry;




		public:


			CIndices(): 
			limit(0)
			{
			}


			virtual ~CIndices()
			{
				Clear();
			}


			void  Clear()
			{
				entry.Enter();
				index.clear(); limit = 0;
				entry.Leave();
			}


			void  SetLimit(size_t value)
			{
				entry.Enter();
				limit = value;
				entry.Leave();
			}


			bool  Insert(const T & value)
			{
			    bool result = false;
			    entry.Enter();
			    if( ( limit == 0 ) || ( limit >= index.size() ) ) {
			    	index.push_back( value ); result = true;
			    }
				entry.Leave();
			    return result;
			}


			template <class A>
			bool  Insert(const vector<T, A> & value)
			{
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


			bool  Obtain(T & output)
			{
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


            template<class A>
			void  Obtain(vector<T, A> & value, bool is_union = false)
			{
			    CIndicesBind set;
			    
			    // 先交换出数据，然后再拷贝。
			    entry.Enter();
			    index.swap ( set );
			    entry.Leave();
			    
			    // 如果没有要求是并集，则直接拷贝，如果要求是并集，则先将求出
			    // 并集再将结果交换给out参数。
			    if( is_union == false )
			    {
					// 直接拷贝到末尾；
                    value.reserve( value.size() + set.size() );
			    	std::copy( set.begin(), set.end(), back_inserter(value) );
			    }
			    else
			    {
					// 预先分配足够的内存；
			    	vector<T,A> result;
                    result.reserve( set.size() + value.size() );

					// 对两个容器排序；
                    set.sort();
                    std::sort( value.begin(), value.end() );

					// 求出并集，并进行交换；
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
