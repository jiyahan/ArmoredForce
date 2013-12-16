#ifndef CMEMORY_H
#define CMEMORY_H
//Begin section for file CMemory.h
//TODO: Add definitions that you want preserved
//End section for file CMemory.h
#include "tagMemorySector.h"
#include "CMemoryScheduler.h"

#define DEFAULT_MEMORY_SIZE 4096 - sizeof(atom::tagMemorySector)


namespace atom
{



    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    class CMemory
    {

        //Begin section for atom::CMemory
        //TODO: Add attributes that you want preserved
        //End section for atom::CMemory

        private:


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            tagMemorySector * sector;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline bool Acquire(tagMemorySector * value); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline void Release(); 




        public:

            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline CMemory(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline CMemory(const CMemory & value); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline virtual ~CMemory(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline size_t GetCapacity() const ; 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline size_t GetLength() const ; 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline void SetLength(size_t value); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline bool Alloc(size_t length = 0, CMemoryScheduler * scheduler = NULL); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline bool Store(const void * source, size_t bytes); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            template<class T>
            inline T * Query() const ; 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline void Clear(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline CMemory Clone() const; 

			
			
			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline CMemory & operator =(const CMemory & value); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline operator bool() const ; 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline operator void *() const ; 



    };  //end class CMemory


}//end namespace atom


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CMemory::CMemory() : sector(NULL)
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CMemory::CMemory(const CMemory & value) : sector(NULL)
{
    //TODO Auto-generated method stub
    * this = value;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CMemory::~CMemory() 
{
    //TODO Auto-generated method stub
    Release();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CMemory::Acquire(tagMemorySector * value) 
{
    //TODO Auto-generated method stub
    Release();

    bool result = false;
    if( value && value -> IncRef() ) {
        result = true; sector = value;
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CMemory::Release() 
{
    //TODO Auto-generated method stub
    if( sector )
    {
        if( sector -> DecRef() == 0 ) {
            CMemoryScheduler::GetInstance() -> Released( sector );
        }
        sector = NULL;
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
size_t atom::CMemory::GetCapacity() const 
{
    //TODO Auto-generated method stub
    return( sector ? sector -> limit : 0 );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
size_t atom::CMemory::GetLength() const 
{
    //TODO Auto-generated method stub
    return( sector ? sector -> valid : 0 );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CMemory::SetLength(size_t value) 
{
    //TODO Auto-generated method stub
    if( sector ) {
        sector -> valid  = value;
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CMemory::Alloc(size_t allocsize, CMemoryScheduler * scheduler) 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CMemory::Store(const void * source, size_t bytes) 
{
    //TODO Auto-generated method stub
    if( !source || !bytes ) return true;

    bool result = false;
    if( sector && bytes <= sector -> limit )
    {
        memcpy( reinterpret_cast<char *>(sector) + sizeof(tagMemorySector), source, bytes );
        sector -> valid = bytes; result = true;
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
template<class T>
T * atom::CMemory::Query() const 
{
    //TODO Auto-generated method stub
    return reinterpret_cast<T *>( (void *)(* this) );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CMemory::Clear() 
{
    //TODO Auto-generated method stub
    Release();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CMemory atom::CMemory::Clone() const
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CMemory & atom::CMemory::operator =(const CMemory & value) 
{
    //TODO Auto-generated method stub
    Acquire( value.sector );
    return( * this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CMemory::operator bool() const 
{
    //TODO Auto-generated method stub
    return( sector != NULL );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CMemory::operator void *() const 
{
    //TODO Auto-generated method stub
    char * result = reinterpret_cast<char *>( sector );
    if( result ) {
        result += sizeof( tagMemorySector );
    }
    return result;
}

#endif
