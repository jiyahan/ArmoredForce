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

                // ��������뵽ʱ�����ڣ�
                pair<typename CTimeLineDefine<T>::
                    timeline_type::iterator, bool> 
                    retval_1 = line.insert( tagTimeLine<T>(time, value) ); 

                // �������ʧ�ܣ�������Ѿ����ڸ�ʱ��㣻
                if( retval_1.second == false )
                {
                    // C++ 0x��׼�ڣ���ֹͨ��set�ĵ������޸�Ԫ�ص����ݣ���Ϊ�޸Ŀ��ܻᵼ��set��˳����
                    // ʧЧ�����Ǵ˴���timeline�ڵ�data���в��������ʵ���ᵼ���κ�˳�������⣬�����
                    // ת��ǿ���Ե�����const���Ե�Ӱ�죻
                    typename tagTimeLine<T>::CTimeDataArray & data_ref = 
                        const_cast<tagTimeLine<T> &>(*retval_1.first).data;

                    // ȷ�϶�����û���ظ����
                    if( find( 
                        data_ref.begin(), data_ref.end(), value ) ==
                        data_ref.end() ) {
                        data_ref.push_back( value );
                    }
                }

                // ���Ҫ�󵥽ڵ㣬�������
                if( sole == true )
                {
                    // �����������б��ڲ��Ҹö����Ƿ��Ѿ����ڣ�
				    pair<typename CTimeLineDefine<T>::
					    timedata_type::iterator, bool> 
                        retval_2 = data.insert( make_pair(value, time) );
                    if( retval_2.second == false && 
                        comp(
                        retval_2.first -> second, time ) )
				    {
                        // ��������Ѵ��ڣ����жϸ�ֵ��������ʱ��㣻
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
	        		// ����ȷ���Ƿ�С�ڵ�ǰʱ�䣻 
	        		if( (*it1).time > time ) {
	        			result = (*it1).time; break;
	        		}

                    // ������ǵ������ã��򿽱����ݺ������
                    if( sole == false )
                    {
	        		    // �������ݺ�ɾ��ʱ�����ڵĽڵ㣻
                        std::copy( (*it1).data.begin(), (*it1).data.end(), std::back_inserter(out) );
                        SAFE_ERASE( line, it1 ); continue;
                    }

                    // ������������ʱ���Ķ���
                    for( typename tagTimeLine<T>::CTimeDataArray::const_iterator
                        it2 = (*it1).data.begin(); it2 != (*it1).data.end(); ++ it2 )
                    {
	        		    // Ȼ����ȷ�ϸ����ݵ����ʱ���Ƿ��Ǻϣ�
	        		    typename CTimeLineDefine<T>::
	        			    timedata_type::iterator it3 = data.find( (*it2) );
	        		    if( it3 != data.end() )
	        		    {
                            // ���ʱ���Ǻϣ�����뵽��������ڣ�
	        			    if( it3 -> second == (*it1).time ) {
	        				    data.erase( it3 ); out.push_back( (*it2) );
	        			    }
	        		    }
                    }
	        		
                    // ���ɾ��ʱ�����ڵĽڵ㣻
                    SAFE_ERASE( line, it1 );
	        	}
                area.Leave();

                // ����ǵ�������׼���ų��ظ����ݣ�
                if( sole == false )
                {
                    CTimeLineResult set; set.reserve( out.size() );
                    std::sort  ( out.begin(), out.end() );
                    std::copy  ( out.begin(), 
                    std::unique( out.begin(), out.end() ), back_inserter(set) );
                    set.swap( out );
                }
	        	
                // ������һ�λ��ѵľ���ʱ��
                return result;
            }

    };  //end class CTimeLine



} //end namespace atom



#endif
