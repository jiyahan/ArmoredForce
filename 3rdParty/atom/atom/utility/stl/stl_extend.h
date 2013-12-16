#ifndef ATOM_STL_H_
#define ATOM_STL_H_
#include "../../Common.h"



// Define initialize structure
namespace atom
{

	template<class T>
	struct initialize
	{
	    inline void operator()(T & value) 
        {
            UNREFERENCED_PARAMETER(value);
	    }
	};

	template<>
	struct initialize<char>
	{
	    inline void operator()(char & value) 
        {
            value = 0;
	    }
	};

	template<>
	struct initialize<I08>
	{
	    inline void operator()(I08 & value) 
        {
            value = 0;
	    }
	};

	template<>
	struct initialize<I16>
	{
	    inline void operator()(I16 & value) 
        {
            value = 0;
	    }
	};

	template<>
	struct initialize<I32>
	{
	    inline void operator()(I32 & value) 
        {
            value = 0;
	    }
	};

	template<>
	struct initialize<I64>
	{
	    inline void operator()(I64& value) 
        {
            value = 0;
	    }
	};

	template<>
	struct initialize<U08>
	{
	    inline void operator()(U08 & value) 
        {
            value = 0;
	    }
	};

	template<>
	struct initialize<U16>
	{
	    inline void operator()(U16 & value) 
        {
            value = 0;
	    }
	};

	template<>
	struct initialize<U32>
	{
	    inline void operator()(U32 & value) 
        {
            value = 0;
	    }
	};

	template<>
	struct initialize<U64>
	{
	    inline void operator()(U64 & value) 
        {
            value = 0;
	    }
	};

	template<>
	struct initialize<float>
	{
	    inline void operator()(float & value) 
        {
            value = 0.0f;
	    }
	};

	template<>
	struct initialize<double>
	{
	    inline void operator()(double & value) 
        {
            value = 0.0;
	    }
	};

	template<>
	struct initialize<long double>
	{
	    inline void operator()(long double & value) 
        {
            value = 0.0;
	    }
	};

	template<>
	struct initialize<char *>
	{
	    inline void operator()(char * & value) 
        {
            value = NULL;
	    }
	};

	template<>
	struct initialize<wchar_t *>
	{
	    inline void operator()(wchar_t * & value) 
        {
            value = NULL;
	    }
	};

	template<>
	struct initialize<void *>
	{
	    inline void operator()(void * & value) 
        {
            value = NULL;
	    }
	};

    template<typename T>
    struct select1st
    {
        typedef typename T::first_type   key;
        typedef typename T::second_type  value;

        inline const key & operator()(const T & data) const 
        {
            return data.first;
        }
    };
	
    template<typename T>
    struct select2nd
    {
        typedef typename T::first_type   key;
        typedef typename T::second_type  value;

        inline const value & operator()(const T & data) const 
        {
            return data.second;
        }
    };

} //end namespace atom


#if defined(_MSC_VER)

// 定义MSVC或者INTEL编译器的一些参数；
namespace atom
{
	template<class T>
	struct atom_hash
	{
	    inline size_t operator()(const T & value) const
	    {
			return stdext::hash_value( value );
	    }
	};
		
    template<class key, class compare = less<key> >
    class atom_hash_compare
    {
    protected:
        compare comp;

    public:

	    // parameters for hash table
        enum
        {
            bucket_size = 1,
            min_buckets = 262144
        };

        inline atom_hash_compare() : comp()
        {	
            // construct with default comparator
        }

        inline atom_hash_compare(compare value) : comp(value)
        {	
            // construct with compare comparator
        }

        inline size_t operator()(const key & value) const
        {	
            atom_hash<key> hasher;
            return hasher( value );
        }

        inline bool operator()(const key & value1, const key & value2) const
        {
            return comp( value1, value2 );
        }
    };

} //end namespace atom

#endif //end #if defined(_MSC_VER)


#if defined(__GNUC__)

// 以下是GNUC的定义，包括GCC和MINGW等GUNC的编译器；
namespace std
{
	
	template<>
	struct equal_to<I64>
	{
        inline bool operator()(const I64 & a, const I64 & b) const
        {
			return( a == b );
        }
	};
	
	template<>
	struct equal_to<U64>
	{
        inline bool operator()(const U64 & a, const U64 & b) const
        {
			return( a == b );
        }
	}; 
	
	template<class E, class T, class A> 
	struct equal_to<basic_string<E, T, A> >
	{
        inline bool operator()(const basic_string<E, T, A> & a, const basic_string<E, T, A> & b) const 
        {
        	return a == b;
        }
	};
	
} //end namespace std

namespace atom
{
	template<class T>
	struct atom_hash
	{
	    inline size_t operator()(const T & value) const
	    {
			#define HASH_SEED (size_t) 0xdeadbeef
			return( (size_t)value ^ HASH_SEED );
	    }
	};

	template <class T>
	inline size_t atom_hash_value(T begin, T end)
	{
		size_t result = 2166136261U;
		while( begin != end )
			result = 16777619U * result ^ (size_t) * begin ++;
		return result;
	}

	template<>
	struct atom_hash<I64>
	{
        inline size_t operator()(const I64 & value) const
        {
		    union { I64 i64; I32 i32[2]; } i;
		    i.i64 = value;
			return atom_hash_value( & i.i32[0], & i.i32[1] );
        }
	};
	
	template<>
	struct atom_hash<U64>
	{
        inline size_t operator()(const U64 & value) const
        {
		    union { U64 u64; U32 u32[2]; } i;
		    i.u64 = value;
		    return atom_hash_value( & i.u32[0], & i.u32[1] );
        }
	}; 
	
	template<class E, class T, class A> 
	struct atom_hash<std::basic_string<E, T, A> >
	{
		inline size_t operator()(const std::basic_string<E, T, A> & str)
		{
			const E * ptr = str.c_str();
			return atom_hash_value( ptr, ptr + str.size() );
		}
	};

	template<>
	struct atom_hash<const char *>
	{
		inline size_t operator()(const char * str)
		{
			return atom_hash_value( str, str + strlen(str) );
		}
	};

	template<>
	struct atom_hash<const wchar_t *>
	{
		inline size_t operator()(const wchar_t * str)
		{
			return atom_hash_value( str, str + wcslen(str) );
		}
	};

}  //end namespace __gnu_cxx

#endif //end #if defined(__GNUC__)
#endif //end ATOM_STL_H_
