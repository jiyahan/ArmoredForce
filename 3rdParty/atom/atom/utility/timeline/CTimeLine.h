#ifndef CTIMELINE_H
#define CTIMELINE_H
//Begin section for file CTimeLine.h
//TODO: Add definitions that you want preserved
//End section for file CTimeLine.h
#include "CTimeLineDefine.h"
#include "../../os/thread/CCriticalSection.h"
#include "../tool/CCriticalSectionScope.h"



namespace atom
{


    
    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    typedef std::greater<U64> time_near;
    
        
        
    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    typedef std::less<U64> time_away;



    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    template <class T, bool E = false, class M = time_away >
    class CTimeLine
    {

        //Begin section for atom::CTimeLine
        //TODO: Add attributes that you want preserved
        //End section for atom::CTimeLine

        public:


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            typedef std::vector<T, atom_allocator<T> >  CTimeLineResult ;

        private:


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            M comp;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            bool sole;


            
            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            typename CTimeLineDefine<T>::timeline_type line;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            typename CTimeLineDefine<T>::timedata_type data;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CCriticalSection area;




        public:


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline CTimeLine() : sole(E)
            {
                    //TODO Auto-generated method stub
            }


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline virtual ~CTimeLine()
            {
                //TODO Auto-generated method stub
            }


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline size_t  Size()
            {
                //TODO Auto-generated method stub
                CCriticalSectionScope scope( area );
                return line.size();
            }


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline void  Mark(U64 time, const T & value)
            {
                //TODO Auto-generated method stub
                if( time == U64(INFINITE) ) return;
                area.Enter();

                // 将对象插入到时间线内；
                pair<typename CTimeLineDefine<T>::
                    timeline_type::iterator, bool> 
                    retval_1 = line.insert( tagTimeLine<T>(time, value) ); 

                // 如果插入失败，则代表已经存在该时间点；
                if( retval_1.second == false )
                {
                    // C++ 0x标准内，禁止通过set的迭代器修改元素的内容，因为修改可能会导致set的顺序性
                    // 失效，但是此处对timeline内的data进行插入操作其实不会导致任何顺序性问题，因此用
                    // 转换强制性的消除const属性的影响；
                    typename tagTimeLine<T>::CTimeDataArray & data_ref = 
                        const_cast<tagTimeLine<T> &>(*retval_1.first).data;

                    // 确认队列中没有重复的项；
                    if( find( 
                        data_ref.begin(), data_ref.end(), value ) ==
                        data_ref.end() ) {
                        data_ref.push_back( value );
                    }
                }

                // 如果要求单节点，则继续；
                if( sole == true )
                {
                    // 首先在索引列表内查找该对象是否已经存在；
				    pair<typename CTimeLineDefine<T>::
					    timedata_type::iterator, bool> 
                        retval_2 = data.insert( make_pair(value, time) );
                    if( retval_2.second == false && 
                        comp(
                        retval_2.first -> second, time ) )
				    {
                        // 如果对象已存在，则判断该值，并重置时间点；
                        retval_2.first -> second = time;
				    }
                }
                area.Leave();
            }


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline U64  Forward(U64 time, CTimeLineResult & out)
            {
                //TODO Auto-generated method stub
                out.reserve( 256 );
	        	U64 result = U64(INFINITE);

                area.Enter();
	        	for( typename CTimeLineDefine<T>::timeline_type::
	        		iterator it1 = line.begin(); it1 != line.end(); )
	        	{
	        		// 首先确认是否小于当前时间； 
	        		if( (*it1).time > time ) {
	        			result = (*it1).time; break;
	        		}

                    // 如果不是单例设置，则拷贝数据后继续；
                    if( sole == false )
                    {
	        		    // 拷贝数据后，删除时间线内的节点；
                        std::copy( (*it1).data.begin(), (*it1).data.end(), std::back_inserter(out) );
                        SAFE_ERASE( line, it1 ); continue;
                    }

                    // 单例，遍历该时间点的对象；
                    for( typename tagTimeLine<T>::CTimeDataArray::const_iterator
                        it2 = (*it1).data.begin(); it2 != (*it1).data.end(); ++ it2 )
                    {
	        		    // 然后再确认该数据的最大时间是否吻合；
	        		    typename CTimeLineDefine<T>::
	        			    timedata_type::iterator it3 = data.find( (*it2) );
	        		    if( it3 != data.end() )
	        		    {
                            // 如果时间吻合，则插入到输出队列内；
	        			    if( it3 -> second == (*it1).time ) {
	        				    data.erase( it3 ); out.push_back( (*it2) );
	        			    }
	        		    }
                    }
	        		
                    // 最后删除时间线内的节点；
                    SAFE_ERASE( line, it1 );
	        	}
                area.Leave();

                // 如果是单例，则准备排除重复数据；
                if( sole == false )
                {
                    CTimeLineResult set; set.reserve( out.size() );
                    std::sort  ( out.begin(), out.end() );
                    std::copy  ( out.begin(), 
                    std::unique( out.begin(), out.end() ), back_inserter(set) );
                    set.swap( out );
                }
	        	
                // 返回下一次唤醒的绝对时间
                return result;
            }

    };  //end class CTimeLine



} //end namespace atom



#endif
