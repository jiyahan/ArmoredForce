#ifndef ATOM_STL_ALLOCATOR_H_
#define ATOM_STL_ALLOCATOR_H_
#include "../../Common.h"
#include "../../os/memory/CMemoryScheduler.h"



namespace atom
{

    template<class T1, class T2> 
    inline void __atom_allocate(T1* p, const T2& v)
    {
        if( p ) new(p) T1(v);
    }

    template<class T> 
    inline void __atom_destruct(T* p)
    {
        if( p ) p -> ~T();
    }

    template<> 
    inline void __atom_destruct(char*)
    {
    }

    template<> 
    inline void __atom_destruct(wchar_t*)
    {
    }

    template<class T>
    struct atom_base_allocator
    {
        typedef T value_type;

        atom_base_allocator()
        {
        }

        virtual ~atom_base_allocator()
        {
        }
    };

    template<class T>
    struct atom_base_allocator<const T>
    {
        typedef T value_type;

        atom_base_allocator()
        {
        }

        virtual ~atom_base_allocator()
        {
        }
    };


    template<class T>
    class atom_allocator : public atom_base_allocator<T>
    {
        public:

        typedef atom_base_allocator<T> base;

        typedef typename base::value_type value_type;

        typedef value_type* pointer;

        typedef value_type& reference;

        typedef const value_type* const_pointer;

        typedef const value_type& const_reference;

        typedef size_t size_type;

        typedef ptrdiff_t difference_type;

        template<class U>
        struct rebind
        {
            typedef atom_allocator<U> other;
        };

        pointer address(reference value) const
        {
            return( &value );
        }

        const_pointer address(const_reference value) const
        {
            return( &value );
        }

        atom_allocator()
        {
        }

        atom_allocator(const atom_allocator<T>&) 
        {
        }

        template<class U>
        atom_allocator(const atom_allocator<U>&) 
        {
        }

        virtual ~atom_allocator() 
        {
        }

        template<class U>
        atom_allocator<T>& operator=(const atom_allocator<U>&)
        {
            return( *this );
        }

        void deallocate(pointer p, size_type)
        {
            CMemoryScheduler::GetInstance() -> Released( p );
        }

        pointer allocate(size_type count)
        {
            return (T*)CMemoryScheduler::GetInstance() -> Allocate( NULL, count * sizeof(T) );
        }

        pointer allocate(size_type count, const void*)
        {
            return allocate( count );
        }

        void construct(pointer ptr, const T& val)
        {
            __atom_allocate(ptr, val);
        }

        void destroy(pointer ptr)
        {
            __atom_destruct(ptr);
        }

        size_type max_size() const
        {
            size_type count = (size_type)(-1) / sizeof (T);
            return( 0 < count ? count : 1 );
        }
    };

    template<typename T>
    inline bool operator==(const atom_allocator<T>&, const atom_allocator<T>&)
    { 
        return true; 
    }

    template<typename T>
    inline bool operator!=(const atom_allocator<T>&, const atom_allocator<T>&)
    { 
        return false; 
    }

}  //end namespace atom

#endif
