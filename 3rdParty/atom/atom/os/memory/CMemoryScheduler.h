#ifndef CMEMORYSCHEDULER_H
#define CMEMORYSCHEDULER_H
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



    class CMemoryScheduler : public CMemorySchedulerSingletonBind
    {


        private:


            //<p>thread allocated line</p>
            static size_t TLS_DECLARE alloc;



            //<p>common memory queue used alloc or free counter</p>
            CReference refer_1;



            CReference refer_2;



            //<p>allocated memory line</p>
            CReference upper;



            CMilisecondTimer timer;



            CMemoryQueues lines[MEMORY_AMOUNT_QUEUE];



            tagMemoryCounts count[MEMORY_AMOUNT_QUEUE];



            tagMemoryTotals total[MEMORY_AMOUNT_QUEUE];



            tagMemoryTotals final[MEMORY_AMOUNT_QUEUE];



            size_t quota[MEMORY_AMOUNT_QUEUE][MEMORY_FRAGMENT_QUEUE];



            size_t cache;



            inline void * NewMem(size_t size); 



            inline void DelMem(void * pointer); 




        public:

            inline CMemoryScheduler(); 



            inline ~CMemoryScheduler(); 



            inline bool Initiate(size_t cache_size); 



            inline void Shutdown(); 



            inline bool Register(); 



            inline void SetLimit(size_t cache_size); 



            inline tagMemorySector * Allocate(size_t size); 



            inline void * Allocate(void * pointer, size_t size); 



            inline void Released(tagMemorySector * pointer); 



            inline void Released(void * pointer); 



            inline void Maintain(); 



    };  //end class CMemoryScheduler


}//end namespace atom


atom::CMemoryScheduler::CMemoryScheduler() : 
cache(1048576)
{
}

atom::CMemoryScheduler::~CMemoryScheduler() 
{
}

void * atom::CMemoryScheduler::NewMem(size_t length) 
{
    #ifdef _WIN32
    void* result = HeapAlloc( GetProcessHeap(), 0, length );
    if( !result )
    {
        // 如果分配失败，则先尝试整理堆，并获取堆的最大内存块的长度；
        HeapCompact( GetProcessHeap(), 0 );

        // 尝试重新分配内存；
        result = HeapAlloc( GetProcessHeap(), 0, length );
    }
    return result;
    #endif
    
    #if defined(__linux) || defined(__APPLE__)
    return new char[length];
    #endif
}

void atom::CMemoryScheduler::DelMem(void * pointer) 
{
    #ifdef _WIN32
    HeapFree( GetProcessHeap(), 0, pointer );
    #endif
    
    #if defined(__linux) || defined(__APPLE__)
    delete[] reinterpret_cast<char *>( pointer );
    #endif
}

bool atom::CMemoryScheduler::Initiate(size_t cache_size) 
{
    // 分配通用队列所占的编号，记录当前时间；
    timer.Record();
    upper.Assign( MEMORY_COMMON_QUEUE );

    // 设置初始的缓存长度；
    cache = cache_size; 
    memset( quota, 0, sizeof(quota) );
    
    #ifdef _WIN32
    #define HEAP_LFH 2

    ULONG type(HEAP_LFH);
    if( FALSE == HeapSetInformation( GetProcessHeap(), 
        HeapCompatibilityInformation, &type, sizeof(type) ) )
    {
        // NOTE: 设置LFH也许会失败，因为操作系统也许缺省已经开启了LFH（vista），
        // 另外，如果由debugger启动，也不允许使用LFH，因此我们忽略所有的错误；
        //si::CAnsiLog log;
        //log << "Failed change heap type to LFH." << si::end_error;
    }

    #endif

    return true;
}

void atom::CMemoryScheduler::Shutdown() 
{
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

bool atom::CMemoryScheduler::Register() 
{
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

void atom::CMemoryScheduler::SetLimit(size_t cache_size) 
{
    cache = cache_size;
}

atom::tagMemorySector * atom::CMemoryScheduler::Allocate(size_t size) 
{
    // 如果请求空长度，则返回空；
    if( !size ) return NULL;

    // 内存对齐；
    size_t align, level;
    level = ( size + (MEMORY_FRAGMENT_LOWER - 1) + sizeof( tagMemorySector ) ) / MEMORY_FRAGMENT_LOWER;
    align = level * MEMORY_FRAGMENT_LOWER;
    level = level - 1;

    // 如果有明确的级别，并且级别小于最大级别，则从缓冲池内获取内存；
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

    // 如果返回值为空，则新分配内存；
    if( result == NULL ) {
        result = reinterpret_cast<tagMemorySector*>( NewMem(align) );
    }

    // 重置好数据头；
    if( result ) 
    {
        #ifndef _SHIPPING_
        // 清空内存块；
        memset( result, 0, align );
        #endif

        // 重置包头数据；
		result -> Reset( align );
    }

    // 如果失败，则抛出异常；
    if( result == NULL ) {
        throw std::bad_alloc();
    }
    return result;
}

void * atom::CMemoryScheduler::Allocate(void * pointer, size_t n_width) 
{
    // 如果长度为0，则回收内存并返回空；
    if( !n_width ) {
        if( pointer ) Released( pointer ); return NULL;
    }

    // 如果传递进来的指针为空，则直接分配内存，并返回；如果传递进来的指针不为空，且要
    // 求的内存长度小于等于现有的内存容量，则直接返回原有内存地址，如果要求的内存长度
    // 大于现有的内存容量，则新分配一个内存区，拷贝内存，然后释放旧的缓冲区，并返回新
    // 的缓冲区，如果分配失败（无内存或其他情况），则返回空，但是不释放原有的内存。
    if( !pointer )
    {
        void* result = Allocate( n_width );
        if( result ) { result = 
            reinterpret_cast<char*>(result) + sizeof( tagMemorySector );
        }
        return result;
    }

    // 确认长度是否符合要求，如果符合要求则直接返回；
    tagMemorySector* prior =  
        reinterpret_cast<tagMemorySector*>( 
        reinterpret_cast<char*>(pointer) - sizeof(tagMemorySector) );
    if( n_width <= prior -> limit ) return pointer;

    // 长度不符合要求，则准备分配新内存空间，拷贝数据之后，回收原有内存；
    tagMemorySector* after = Allocate( n_width );
    if( after )
    {
        void* result = 
            reinterpret_cast<void*>( 
            reinterpret_cast<char*>(after) + sizeof(tagMemorySector) );
        memcpy( result, pointer, prior -> limit ); Released( prior ); 
        return result;
    }

    // 分配失败，回收内存后返回空；
    Released( prior ); return NULL;
}

void atom::CMemoryScheduler::Released(tagMemorySector * header) 
{
    if( !header ) return;

    // 设置内存的数据为0xEE；
    #ifndef _SHIPPING_
    memset( reinterpret_cast<char*>(header) + sizeof(tagMemorySector), 0xee, header -> limit );
    #endif

    // 根据内存块的长度，确定内存块的级别，并尝试放入容器内；
    bool destroy(true);
    if( header -> level <= MEMORY_FRAGMENT_UPPER ) 
    {
        // 求内存块的级别；
        size_t level = header -> level / MEMORY_FRAGMENT_LOWER - 1;

        // 根据线程的分配队列来决定是否使用线程独占模式
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

    // 如果需要删除内存块，则删除该内存块。
    if( destroy ) DelMem( header );
}

void atom::CMemoryScheduler::Released(void * pointer) 
{
    if( !pointer ) return;

    // 恢复包头；
    tagMemorySector* header( 
        reinterpret_cast<tagMemorySector*>( 
        reinterpret_cast<char*>(pointer) - sizeof(tagMemorySector) ) );

    // 移除包头
    Released( header );
}

void atom::CMemoryScheduler::Maintain() 
{
    if( timer.GetElapsedTime() >= MEMORY_MAINTAIN_TIME )
    {
        timer.Record();

        float tc[MEMORY_AMOUNT_QUEUE][MEMORY_FRAGMENT_QUEUE];

        float at = 0.0f, mt = 0.0f;

        // 统计内存分配、释放、未命中的数量；
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
                // 如果过去的一分钟内，没有分配请求，则将配额减少一半；
                tc[i][k] = quota[i][k] / 2.0f;
            }
            else
            if( a  > 0 )
            {
                if( m  > 0 )
                {
                    if( quota[i][k] == 0 )
                    {
                        // 第一次计算配额，预计有一半分配的内存将被释放；
                        float value = ( a - r ) / 2.0f; 

                        // 分配数量的5%作为最小保障，确保在公共管线中，
                        // （某些管线可能r会大于a）能够正确的得到缓存数
                        // 量，从而避免缓存失败；
                        tc[i][k] = atom_max( a * 0.05f , value );
                    }
                    else
                    {
                        // 计算未命中率，并且根据未命中率增加配额，区间
                        // 【1.0，2.0】；此处，a必定大于0，因为上面条件
					    // 做了判断。
                        float ratio = static_cast<float>( m ) / static_cast<float>( a ) + 1.0f;

                        // 根据之前的缓存数量求出增长量，并加一确保极小
                        // 的数量也能正确增长；
                        float value = static_cast<float>( quota[i][k] ) * ratio + 1.0f;

                        // 在增长量和分配数量之间取小，并计算分配数量的
                        // 指数（确保快速、正确的增长），最终得到配额；
                        static float bias = 2;
                        tc[i][k] = atom_min( value, a ) + log10( static_cast<float>(a) ) + bias;
                    }
                }
                else
                {
                    // 如果有分配，且全部命中，则可能是缓存内的数量过多；
                    // 可以根据释放/分配比例适当的调整缓冲区大小；此处a
				    // 必定大于 0，因为之前做了判断。
                    float ratio = static_cast<float>( r ) / static_cast<float>( a ); 
                          ratio = atom_max( 1.0f, ratio ); 
                          ratio = atom_min( 1.2f, ratio );

				    // ratio 在区间[1.0f, 1.2f]之间
                    float value = static_cast<float>( quota[i][k] ) / ratio;

                    // 最终的配额；
                    tc[i][k] = value;
                }
            }
        }

        // 计算各个线程的内存分配数量
        float prior[MEMORY_AMOUNT_QUEUE];
        float after[MEMORY_AMOUNT_QUEUE];
        memset( prior, 0, sizeof(prior) );
        memset( after, 0, sizeof(after) );

        float total = 0.0f;
        for( size_t i = 0, j = upper.GetReference(); 
            i < j && 
            i < MEMORY_AMOUNT_QUEUE; ++ i )
        {
            // 计算每一个line所需的缓存总量；
            for( size_t k = 0; k < MEMORY_FRAGMENT_QUEUE; ++ k ) {
                prior[i] += tc[i][k] * ( k + 1 ) * MEMORY_FRAGMENT_LOWER;
            }

            // 增加总量；
            total += prior[i];
        }

        // 求出每一个线程的配额；
        for( size_t i = 0, j = upper.GetReference(); 
            i < j && 
            i < MEMORY_AMOUNT_QUEUE; ++ i )
        {
            cache < total ?
                after[i] = prior[i] * static_cast<float>( cache ) / total :
                after[i] = prior[i];
        }

        // 求出每一个线程内，每一个缓存的配额；
        for( size_t i = 0, j = upper.GetReference(); 
            i < j && 
            i < MEMORY_AMOUNT_QUEUE; ++ i )
        {
            // 首先求出每一个缓存次数的比例
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
