#ifndef CMEMORY_H
#define CMEMORY_H
#include "tagMemorySector.h"
#include "CMemoryScheduler.h"

#define DEFAULT_MEMORY_SIZE 4096 - sizeof(atom::tagMemorySector)


namespace atom
{



    class CMemory
    {


        private:


            tagMemorySector * sector;



            inline bool Acquire(tagMemorySector * value); 



            inline void Release(); 




        public:

            inline CMemory(); 



            inline CMemory(const CMemory & value); 



            inline virtual ~CMemory(); 



            inline size_t GetCapacity() const ; 



            inline size_t GetLength() const ; 



            inline void SetLength(size_t value); 



            inline bool Alloc(size_t length = 0, CMemoryScheduler * scheduler = NULL); 



            inline bool Store(const void * source, size_t bytes); 



            template<class T>
            inline T * Query() const ; 



            inline void Clear(); 



            inline CMemory Clone() const; 

			
			
            inline CMemory & operator =(const CMemory & value); 



            inline operator bool() const ; 



            inline operator void *() const ; 



    };  //end class CMemory


}//end namespace atom


atom::CMemory::CMemory() : sector(NULL)
{
}

atom::CMemory::CMemory(const CMemory & value) : sector(NULL)
{
    * this = value;
}

atom::CMemory::~CMemory() 
{
    Release();
}

bool atom::CMemory::Acquire(tagMemorySector * value) 
{
    Release();

    bool result = false;
    if( value && value -> IncRef() ) {
        result = true; sector = value;
    }
    return result;
}

void atom::CMemory::Release() 
{
    if( sector )
    {
        if( sector -> DecRef() == 0 ) {
            CMemoryScheduler::GetInstance() -> Released( sector );
        }
        sector = NULL;
    }
}

size_t atom::CMemory::GetCapacity() const 
{
    return( sector ? sector -> limit : 0 );
}

size_t atom::CMemory::GetLength() const 
{
    return( sector ? sector -> valid : 0 );
}

void atom::CMemory::SetLength(size_t value) 
{
    if( sector ) {
        sector -> valid  = value;
    }
}

bool atom::CMemory::Alloc(size_t allocsize, CMemoryScheduler * scheduler) 
{
    bool result = false;
    if( !allocsize ) allocsize = DEFAULT_MEMORY_SIZE;
    if( !scheduler ) scheduler = CMemoryScheduler::GetInstance();

    tagMemorySector * value = reinterpret_cast<tagMemorySector *>( 
        scheduler -> Allocate( allocsize ) );
    if( value ) 
    {
        value -> Reset(); 
        result = Acquire( value ); 
    }
    return result;
}

bool atom::CMemory::Store(const void * source, size_t bytes) 
{
    if( !source || !bytes ) return true;

    bool result = false;
    if( sector && bytes <= sector -> limit )
    {
        memcpy( reinterpret_cast<char *>(sector) + sizeof(tagMemorySector), source, bytes );
        sector -> valid = bytes; result = true;
    }
    return result;
}

template<class T>
T * atom::CMemory::Query() const 
{
    return reinterpret_cast<T *>( (void *)(* this) );
}

void atom::CMemory::Clear() 
{
    Release();
}

atom::CMemory atom::CMemory::Clone() const
{
    CMemory result;
	if( sector )
	{
		if( result.Alloc( GetLength() ) )
		{
			memset( result, 0, result.GetCapacity() );
			result.Store( * this, GetLength() );
		}
	}
	return result;
}

atom::CMemory & atom::CMemory::operator =(const CMemory & value) 
{
    Acquire( value.sector );
    return( * this );
}

atom::CMemory::operator bool() const 
{
    return( sector != NULL );
}

atom::CMemory::operator void *() const 
{
    char * result = reinterpret_cast<char *>( sector );
    if( result ) {
        result += sizeof( tagMemorySector );
    }
    return result;
}

#endif
