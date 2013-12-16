#ifndef ATOM_STL_ALLOCATOR_H_
#define ATOM_STL_ALLOCATOR_H_
#include "../../Common.h"
#include "../../os/memory/CMemoryScheduler.h"



namespace atom
{

    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    template<class T1, class T2> 
    inline void __atom_allocate(T1* p, const T2& v)
    {
        //TODO Auto-generated method stub
        if( p ) new(p) T1(v);
    }

    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    template<class T> 
    inline void __atom_destruct(T* p)
    {
        //TODO Auto-generated method stub
        if( p ) p -> ~T();
    }

    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    template<> 
    inline void __atom_destruct(char*)
    {
        //TODO Auto-generated method stub
    }

    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    template<> 
    inline void __atom_destruct(wchar_t*)
    {
        //TODO Auto-generated method stub
    }

    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    template<class T>
    struct atom_base_allocator
    {
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        typedef T value_type;

        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        atom_base_allocator()
        {
            //TODO Auto-generated method stub
        }

        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        virtual ~atom_base_allocator()
        {
            //TODO Auto-generated method stub
        }
    };

    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    template<class T>
    struct atom_base_allocator<const T>
    {
        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        typedef T value_type;

        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        atom_base_allocator()
        {
            //TODO Auto-generated method stub
        }

        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        virtual ~atom_base_allocator()
        {
            //TODO Auto-generated method stub
        }
    };


    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    template<class T>
    class atom_allocator : public atom_base_allocator<T>
    {
        public:

        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        typedef atom_base_allocator<T> base;

        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        typedef typename base::value_type value_type;

        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        typedef value_type* pointer;

        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        typedef value_type& reference;

        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        typedef const value_type* const_pointer;

        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        typedef const value_type& const_reference;

        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        typedef size_t size_type;

        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        typedef ptrdiff_t difference_type;

        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        template<class U>
        struct rebind
        {
            typedef atom_allocator<U> other;
        };

        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        pointer address(reference value) const
        {
            //TODO Auto-generated method stub
            return( &value );
        }

        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        const_pointer address(const_reference value) const
        {
            //TODO Auto-generated method stub
            return( &value );
        }

        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        atom_allocator()
        {
            //TODO Auto-generated method stub
        }

        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        atom_allocator(const atom_allocator<T>&) 
        {
            //TODO Auto-generated method stub
        }

        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        template<class U>
        atom_allocator(const atom_allocator<U>&) 
        {
            //TODO Auto-generated method stub
        }

        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        virtual ~atom_allocator() 
        {
            //TODO Auto-generated method stub
        }

        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        template<class U>
        atom_allocator<T>& operator=(const atom_allocator<U>&)
        {
            //TODO Auto-generated method stub
            return( *this );
        }

        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        void deallocate(pointer p, size_type)
        {
            //TODO Auto-generated method stub
            CMemoryScheduler::GetInstance() -> Released( p );
        }

        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        pointer allocate(size_type count)
        {
            //TODO Auto-generated method stub
            return (T*)CMemoryScheduler::GetInstance() -> Allocate( NULL, count * sizeof(T) );
        }

        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        pointer allocate(size_type count, const void*)
        {
            //TODO Auto-generated method stub
            return allocate( count );
        }

        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        void construct(pointer ptr, const T& val)
        {
            //TODO Auto-generated method stub
            __atom_allocate(ptr, val);
        }

        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        void destroy(pointer ptr)
        {
            //TODO Auto-generated method stub
            __atom_destruct(ptr);
        }

        //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
        size_type max_size() const
        {
            //TODO Auto-generated method stub
            size_type count = (size_type)(-1) / sizeof (T);
            return( 0 < count ? count : 1 );
        }
    };

    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    template<typename T>
    inline bool operator==(const atom_allocator<T>&, const atom_allocator<T>&)
    { 
        //TODO Auto-generated method stub
        return true; 
    }

    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    template<typename T>
    inline bool operator!=(const atom_allocator<T>&, const atom_allocator<T>&)
    { 
        //TODO Auto-generated method stub
        return false; 
    }

}  //end namespace atom

#endif
