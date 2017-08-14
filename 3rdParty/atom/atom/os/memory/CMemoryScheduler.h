#ifndef CMEMORYSCHEDULER_H
#define CMEMORYSCHEDULER_H
//Begin section for file CMemoryScheduler.h
//TODO: Add definitions that you want preserved
//End section for file CMemoryScheduler.h
#include "CMemorySchedulerSingletonBind.h"
#include "CMemoryQueues.h"
#include "tagMemoryCounts.h"
#include "tagMemoryTotals.h"
#include "tagMemorySector.h"
#include "../thread/CReference.h"
#include "../thread/CThread.h"
#include "../timer/CMilisecondTimer.h"



namespace atom
{



    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    class CMemoryScheduler : public CMemorySchedulerSingletonBind
    {

        //Begin section for atom::CMemoryScheduler
        //TODO: Add attributes that you want preserved
        //End section for atom::CMemoryScheduler

        private:


            //<p>thread allocated line</p>
            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            static size_t TLS_DECLARE alloc;



            //<p>common memory queue used alloc or free counter</p>
            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CReference refer_1;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CReference refer_2;



            //<p>allocated memory line</p>
            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CReference upper;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CMilisecondTimer timer;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CMemoryQueues lines[MEMORY_AMOUNT_QUEUE];



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            tagMemoryCounts count[MEMORY_AMOUNT_QUEUE];



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            tagMemoryTotals total[MEMORY_AMOUNT_QUEUE];



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            tagMemoryTotals final[MEMORY_AMOUNT_QUEUE];



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            size_t quota[MEMORY_AMOUNT_QUEUE][MEMORY_FRAGMENT_QUEUE];



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            size_t cache;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline void * NewMem(size_t size); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline void DelMem(void * pointer); 




        public:

            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline CMemoryScheduler(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline ~CMemoryScheduler(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline bool Initiate(size_t cache_size); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline void Shutdown(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline bool Register(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline void SetLimit(size_t cache_size); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline tagMemorySector * Allocate(size_t size); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline void * Allocate(void * pointer, size_t size); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline void Released(tagMemorySector * pointer); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline void Released(void * pointer); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline void Maintain(); 



    };  //end class CMemoryScheduler


}//end namespace atom


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CMemoryScheduler::CMemoryScheduler() : 
cache(1048576)
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CMemoryScheduler::~CMemoryScheduler() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void * atom::CMemoryScheduler::NewMem(size_t length) 
{
    //TODO Auto-generated method stub
    #ifdef _WIN32
    void* result = HeapAlloc( GetProcessHeap(), 0, length );
    if( !result )
    {
        // �������ʧ�ܣ����ȳ�������ѣ�����ȡ�ѵ�����ڴ��ĳ��ȣ�
        HeapCompact( GetProcessHeap(), 0 );

        // �������·����ڴ棻
        result = HeapAlloc( GetProcessHeap(), 0, length );
    }
    return result;
    #endif
    
    #if defined(__linux) || defined(__APPLE__)
    return new char[length];
    #endif
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CMemoryScheduler::DelMem(void * pointer) 
{
    //TODO Auto-generated method stub
    #ifdef _WIN32
    HeapFree( GetProcessHeap(), 0, pointer );
    #endif
    
    #if defined(__linux) || defined(__APPLE__)
    delete[] reinterpret_cast<char *>( pointer );
    #endif
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CMemoryScheduler::Initiate(size_t cache_size) 
{
    //TODO Auto-generated method stub
    // ����ͨ�ö�����ռ�ı�ţ���¼��ǰʱ�䣻
    timer.Record();
    upper.Assign( MEMORY_COMMON_QUEUE );

    // ���ó�ʼ�Ļ��泤�ȣ�
    cache = cache_size; 
    memset( quota, 0, sizeof(quota) );
    
    #ifdef _WIN32
    #define HEAP_LFH 2

    ULONG type(HEAP_LFH);
    if( FALSE == HeapSetInformation( GetProcessHeap(), 
        HeapCompatibilityInformation, &type, sizeof(type) ) )
    {
        // NOTE: ����LFHҲ���ʧ�ܣ���Ϊ����ϵͳҲ��ȱʡ�Ѿ�������LFH��vista����
        // ���⣬�����debugger������Ҳ������ʹ��LFH��������Ǻ������еĴ���
        //si::CAnsiLog log;
        //log << "Failed change heap type to LFH." << si::end_error;
    }

    #endif

    return true;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CMemoryScheduler::Shutdown() 
{
    //TODO Auto-generated method stub
    for( size_t i = 0, j = upper.GetReference(); 
        i < j && 
        i < MEMORY_AMOUNT_QUEUE; ++ i )
    {
        CMemoryQueueBind data; lines[i].GetAll( data );
        for( size_t m = 0, n = data.size(); m < n; ++ m ) {
            DelMem( data[m] );
        }
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CMemoryScheduler::Register() 
{
    //TODO Auto-generated method stub
	#if defined(TLS_NOT_SUPPORT)
	return false;
	#else
    alloc = upper.Increase();

    bool result( false );
    if( alloc < MEMORY_AMOUNT_QUEUE ) {
        result = true;
    }
    return result;
	#endif
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CMemoryScheduler::SetLimit(size_t cache_size) 
{
    //TODO Auto-generated method stub
    cache = cache_size;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::tagMemorySector * atom::CMemoryScheduler::Allocate(size_t size) 
{
    //TODO Auto-generated method stub
    // �������ճ��ȣ��򷵻ؿգ�
    if( !size ) return NULL;

    // �ڴ���룻
    size_t align, level;
    level = ( size + (MEMORY_FRAGMENT_LOWER - 1) + sizeof( tagMemorySector ) ) / MEMORY_FRAGMENT_LOWER;
    align = level * MEMORY_FRAGMENT_LOWER;
    level = level - 1;

    // �������ȷ�ļ��𣬲��Ҽ���С����󼶱���ӻ�����ڻ�ȡ�ڴ棻
    tagMemorySector* result(NULL);
    if( align <= MEMORY_FRAGMENT_UPPER ) 
    {
        if( alloc < MEMORY_AMOUNT_QUEUE ) 
        {
            result = lines[alloc].Get( level );

            if( !result ) 
            count[alloc].stages[level].IncMCount();
            count[alloc].stages[level].IncACount();
        } 
        else 
        {
            size_t index = size_t( refer_1.Increase() ) % MEMORY_COMMON_QUEUE;
            result = lines[index].Get( level );

            if( !result ) 
            count[index].stages[level].IncMCount();
            count[index].stages[level].IncACount();
        }
    }

    // �������ֵΪ�գ����·����ڴ棻
    if( result == NULL ) {
        result = reinterpret_cast<tagMemorySector*>( NewMem(align) );
    }

    // ���ú�����ͷ��
    if( result ) 
    {
        #ifndef _SHIPPING_
        // ����ڴ�飻
        memset( result, 0, align );
        #endif

        // ���ð�ͷ���ݣ�
		result -> Reset( align );
    }

    // ���ʧ�ܣ����׳��쳣��
    if( result == NULL ) {
        throw std::bad_alloc();
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void * atom::CMemoryScheduler::Allocate(void * pointer, size_t n_width) 
{
    //TODO Auto-generated method stub
    // �������Ϊ0��������ڴ沢���ؿգ�
    if( !n_width ) {
        if( pointer ) Released( pointer ); return NULL;
    }

    // ������ݽ�����ָ��Ϊ�գ���ֱ�ӷ����ڴ棬�����أ�������ݽ�����ָ�벻Ϊ�գ���Ҫ
    // ����ڴ泤��С�ڵ������е��ڴ���������ֱ�ӷ���ԭ���ڴ��ַ�����Ҫ����ڴ泤��
    // �������е��ڴ����������·���һ���ڴ����������ڴ棬Ȼ���ͷžɵĻ���������������
    // �Ļ��������������ʧ�ܣ����ڴ��������������򷵻ؿգ����ǲ��ͷ�ԭ�е��ڴ档
    if( !pointer )
    {
        void* result = Allocate( n_width );
        if( result ) { result = 
            reinterpret_cast<char*>(result) + sizeof( tagMemorySector );
        }
        return result;
    }

    // ȷ�ϳ����Ƿ����Ҫ���������Ҫ����ֱ�ӷ��أ�
    tagMemorySector* prior =  
        reinterpret_cast<tagMemorySector*>( 
        reinterpret_cast<char*>(pointer) - sizeof(tagMemorySector) );
    if( n_width <= prior -> limit ) return pointer;

    // ���Ȳ�����Ҫ����׼���������ڴ�ռ䣬��������֮�󣬻���ԭ���ڴ棻
    tagMemorySector* after = Allocate( n_width );
    if( after )
    {
        void* result = 
            reinterpret_cast<void*>( 
            reinterpret_cast<char*>(after) + sizeof(tagMemorySector) );
        memcpy( result, pointer, prior -> limit ); Released( prior ); 
        return result;
    }

    // ����ʧ�ܣ������ڴ�󷵻ؿգ�
    Released( prior ); return NULL;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CMemoryScheduler::Released(tagMemorySector * header) 
{
    //TODO Auto-generated method stub
    if( !header ) return;

    // �����ڴ������Ϊ0xEE��
    #ifndef _SHIPPING_
    memset( reinterpret_cast<char*>(header) + sizeof(tagMemorySector), 0xee, header -> limit );
    #endif

    // �����ڴ��ĳ��ȣ�ȷ���ڴ��ļ��𣬲����Է��������ڣ�
    bool destroy(true);
    if( header -> level <= MEMORY_FRAGMENT_UPPER ) 
    {
        // ���ڴ��ļ���
        size_t level = header -> level / MEMORY_FRAGMENT_LOWER - 1;

        // �����̵߳ķ�������������Ƿ�ʹ���̶߳�ռģʽ
        if( alloc < MEMORY_AMOUNT_QUEUE )
        {
            destroy = !lines[alloc].Put( level, header );
            count[alloc].stages[level].IncRCount();
        } 
        else
        {
            size_t index = size_t( refer_2.Increase() ) % MEMORY_COMMON_QUEUE;
            destroy = !lines[index].Put( level, header );
            count[index].stages[level].IncRCount();
        }
    }

    // �����Ҫɾ���ڴ�飬��ɾ�����ڴ�顣
    if( destroy ) DelMem( header );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CMemoryScheduler::Released(void * pointer) 
{
    //TODO Auto-generated method stub
    if( !pointer ) return;

    // �ָ���ͷ��
    tagMemorySector* header( 
        reinterpret_cast<tagMemorySector*>( 
        reinterpret_cast<char*>(pointer) - sizeof(tagMemorySector) ) );

    // �Ƴ���ͷ
    Released( header );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CMemoryScheduler::Maintain() 
{
    //TODO Auto-generated method stub
    if( timer.GetElapsedTime() >= MEMORY_MAINTAIN_TIME )
    {
        timer.Record();

        float tc[MEMORY_AMOUNT_QUEUE][MEMORY_FRAGMENT_QUEUE];

        float at = 0.0f, mt = 0.0f;

        // ͳ���ڴ���䡢�ͷš�δ���е�������
        for( size_t i = 0, j = upper.GetReference(); 
            i < j && 
            i < MEMORY_AMOUNT_QUEUE; ++ i )
        for( size_t k = 0; k < MEMORY_FRAGMENT_QUEUE; ++ k )
        {
            long a, r, m;
            count[i].stages[k].Reset( a, r, m );

            total[i].stages[k].a_count += a;
            total[i].stages[k].r_count += r;
            total[i].stages[k].m_count += m;

            final[i].stages[k].a_count  = a;
            final[i].stages[k].r_count  = r;
            final[i].stages[k].m_count  = m;

            at += a; mt += m;

			if( a <= 0 )
            {
                // �����ȥ��һ�����ڣ�û�з���������������һ�룻
                tc[i][k] = quota[i][k] / 2.0f;
            }
            else
            if( a  > 0 )
            {
                if( m  > 0 )
                {
                    if( quota[i][k] == 0 )
                    {
                        // ��һ�μ�����Ԥ����һ�������ڴ潫���ͷţ�
                        float value = ( a - r ) / 2.0f; 

                        // ����������5%��Ϊ��С���ϣ�ȷ���ڹ��������У�
                        // ��ĳЩ���߿���r�����a���ܹ���ȷ�ĵõ�������
                        // �����Ӷ����⻺��ʧ�ܣ�
                        tc[i][k] = atom_max( a * 0.05f , value );
                    }
                    else
                    {
                        // ����δ�����ʣ����Ҹ���δ����������������
                        // ��1.0��2.0�����˴���a�ض�����0����Ϊ��������
					    // �����жϡ�
                        float ratio = static_cast<float>( m ) / static_cast<float>( a ) + 1.0f;

                        // ����֮ǰ�Ļ����������������������һȷ����С
                        // ������Ҳ����ȷ������
                        float value = static_cast<float>( quota[i][k] ) * ratio + 1.0f;

                        // ���������ͷ�������֮��ȡС�����������������
                        // ָ����ȷ�����١���ȷ�������������յõ���
                        static float bias = 2;
                        tc[i][k] = atom_min( value, a ) + log10( static_cast<float>(a) ) + bias;
                    }
                }
                else
                {
                    // ����з��䣬��ȫ�����У�������ǻ����ڵ��������ࣻ
                    // ���Ը����ͷ�/��������ʵ��ĵ�����������С���˴�a
				    // �ض����� 0����Ϊ֮ǰ�����жϡ�
                    float ratio = static_cast<float>( r ) / static_cast<float>( a ); 
                          ratio = atom_max( 1.0f, ratio ); 
                          ratio = atom_min( 1.2f, ratio );

				    // ratio ������[1.0f, 1.2f]֮��
                    float value = static_cast<float>( quota[i][k] ) / ratio;

                    // ���յ���
                    tc[i][k] = value;
                }
            }
        }

        // ��������̵߳��ڴ��������
        float prior[MEMORY_AMOUNT_QUEUE];
        float after[MEMORY_AMOUNT_QUEUE];
        memset( prior, 0, sizeof(prior) );
        memset( after, 0, sizeof(after) );

        float total = 0.0f;
        for( size_t i = 0, j = upper.GetReference(); 
            i < j && 
            i < MEMORY_AMOUNT_QUEUE; ++ i )
        {
            // ����ÿһ��line����Ļ���������
            for( size_t k = 0; k < MEMORY_FRAGMENT_QUEUE; ++ k ) {
                prior[i] += tc[i][k] * ( k + 1 ) * MEMORY_FRAGMENT_LOWER;
            }

            // ����������
            total += prior[i];
        }

        // ���ÿһ���̵߳���
        for( size_t i = 0, j = upper.GetReference(); 
            i < j && 
            i < MEMORY_AMOUNT_QUEUE; ++ i )
        {
            cache < total ?
                after[i] = prior[i] * static_cast<float>( cache ) / total :
                after[i] = prior[i];
        }

        // ���ÿһ���߳��ڣ�ÿһ���������
        for( size_t i = 0, j = upper.GetReference(); 
            i < j && 
            i < MEMORY_AMOUNT_QUEUE; ++ i )
        {
            // �������ÿһ����������ı���
            for( size_t k = 0; k < MEMORY_FRAGMENT_QUEUE; ++ k ) 
            {
				prior[i] > 0.0f ?
                quota[i][k] += static_cast<size_t>( tc[i][k] * ( after[i] / prior[i] ) ) :
                quota[i][k] += static_cast<size_t>( tc[i][k] * ( after[i] / 1.0f ) );
                quota[i][k] += 1;
                quota[i][k] /= 2;
                lines[i].SetLimit( k, quota[i][k] );
            }
        }

        //#ifndef _SHIPPING_
        //char msg[256];
        //sprintf( msg, "[Memory Scheduler]alloc time: %f, miss time: %f, ratio: %f\n\n", at, mt, 1.0f - mt / at );
        //#endif
    }
}

#endif
