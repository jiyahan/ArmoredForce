#ifndef STL_SERIALIZATION_H_
#define STL_SERIALIZATION_H_
// STL容器序列化的支持，目前仅支持string, vector, pair, map, hash_map, set, multiset。
#include "../../Common.h"
#include "../../utility/stl/stl_extend.h"
#include "../../utility/stl/a_string.h"
#include "../../utility/stl/a_wstring.h"
#include "../../utility/checksum/alogrithm/internet/internet.h"


// std::string字符串序列化
template<class Archive>
inline void Serialize(Archive & archive, std::string & characters, bool isSave)
{
	if( isSave )
	{
        atom::a_string data;
        data = characters.c_str();
		archive.Bind( data );
	}
	else
	{
        atom::a_string data;
		archive.Bind( data );
        characters = data.c_str();
	}
}

// std::wstring字符串序列化
template<class Archive>
inline void Serialize(Archive & archive, std::wstring & characters, bool isSave)
{
	if( isSave )
	{
        atom::a_wstring data;
        data = characters.c_str();
		archive.Bind( data );
	}
	else
	{
        atom::a_wstring data;
		archive.Bind( data );
        characters = data.c_str();
	}
}

// std::vector容器序列化
template<class Archive, class Item, class Alc>
inline void Serialize(Archive & archive, std::vector<Item, Alc> & container, bool isSave)
{
	if( isSave )
	{
		// 获取容器内物件的数量；
		U32 bound = static_cast<U32>( container.size() );

        // 计算数量的校验和；
        U16 check = internet_checksum( & bound, sizeof(bound) );

		// 将物品的数量与每一个物品写入档案内；
		archive.Bind( bound );
        archive.Bind( check );
		for( size_t i = 0; i < bound; ++ i ) {
            archive.Bind( container[i] );
        }
	}
	else
	{
		// 获取容器内物品的数量；
		U32 bound = 0;
        U16 check = 0;
		archive.Bind( bound );
        archive.Bind( check );

        // 判断校验和是否正确；
        if( check ==
            internet_checksum( & bound, sizeof(bound) ) )
        {
            atom::initialize<Item> initiate;

		    // 反序列化物品，并放入容器内；
		    container.clear();
		    for( size_t i = 0; i < bound; ++ i )
		    {
                // 申明并初始化对象；
			    Item item; initiate( item );

                // 反序列化对象，并放入容器；
			    archive.Bind( item );
			    container.push_back( item );
		    }
        }

        // 出错，输出日志；
        else
        {
        }
	}
}

// std::list容器序列化
template<class Archive, class Item, class Alc>
inline void Serialize(Archive & archive, std::list<Item, Alc> & container, bool isSave)
{
	if( isSave )
	{
		// 获取容器内物件的数量；
		U32 bound = static_cast<U32>( container.size() );

        // 计算数量的校验和；
        U16 check = internet_checksum( &bound, sizeof(bound) );

		// 将物品的数量与每一个物品写入档案内；
		archive.Bind( bound );
        archive.Bind( check );
		for( typename std::list<Item, Alc>::iterator 
			it = container.begin(); it != container.end(); ++ it ) {
			archive.Bind( *it );
		}
	}
	else
	{
		// 获取容器内物品的数量；
		U32 bound = 0;
        U16 check = 0;
		archive.Bind( bound );
        archive.Bind( check );

        // 判断校验和是否正确；
        if( check == 
            internet_checksum( & bound, sizeof(bound) ) )
        {
            atom::initialize<Item> initiate;

		    // 反序列化物品，并放入容器内；
		    container.clear();
		    for( size_t i = 0; i < bound; ++ i )
		    {
			    Item item; initiate( item );

			    archive.Bind( item );
			    container.push_back( item );
		    }
        }

        // 出错，输出日志；
        else
        {
        }
	}
}

// std::pair容器序列化
template<class Archive, class First, class Second>
inline void Serialize(Archive & archive, std::pair<First, Second> & container, bool isSave)
{
    UNREFERENCED_PARAMETER( isSave );
    archive.Bind( container.first  );
	archive.Bind( container.second );
}

// std::map容器序列化
template<class Archive, class Key, class Item, class Cmp, class Alc>
inline void Serialize(Archive & archive, std::map<Key, Item, Cmp, Alc> & container, bool isSave)
{
	if( isSave )
	{
		// 获取容器内的物件数量；
		U32 bound = static_cast<U32>( container.size() );

        // 计算数量的校验和；
        U16 check = internet_checksum( & bound, sizeof(bound) );

		// 将物品数量与每一个物品写入档案内；
		archive.Bind( bound );
        archive.Bind( check );
		typename std::map<Key, Item, Cmp, Alc>::
            iterator it = container.begin();
		for( ; it != container.end(); ++ it )
		{
            Key key = (*it).first;
			archive.Bind( key );
			archive.Bind( (*it).second );
		}
	}
	else
	{
		// 获取物品的数量
		U32 bound = 0;
        U16 check = 0;
		archive.Bind( bound );
        archive.Bind( check );

        // 判断校验和是否正确；
        if( check == 
            internet_checksum( & bound , sizeof(bound) ) )
        {
            atom::initialize<Key>  k_initiate;
            atom::initialize<Item> i_initiate;

		    // 反序列化物品，并放入容器内；
		    container.clear();
		    for( size_t z = 0; z < bound; ++ z )
		    {
			    Key  k; k_initiate( k );
			    Item i; i_initiate( i );

			    archive.Bind( k );
			    archive.Bind( i );
			    container.insert( make_pair(k, i) );
		    }
        }

        // 出错，输出日志；
        else
        {
        }
	}
}

// hash_map容器序列化
#if defined(__GNUC__)

template<class Archive, class Key, class Item, class Hash, class Mtd, class Alc>
inline void Serialize(Archive & archive, hash_map<Key, Item, Hash, Mtd, Alc> & container, bool isSave)
{
	if( isSave )
	{
		// 获取容器内的物件数量；
		U32 bound = static_cast<U32>( container.size() );

        // 计算数量的校验和；
        U16 check = internet_checksum( & bound, sizeof(bound) );

		// 将物品数量与每一个物品写入档案内；
		archive.Bind( bound );
        archive.Bind( check );
		typename hash_map<Key, Item, Hash, Mtd, Alc>::
            iterator it = container.begin();
		for( ; it != container.end(); ++ it )
		{
            Key key = (*it).first;
			archive.Bind( key );
			archive.Bind( (*it).second );
		}
    }
	else
	{
		// 获取物品的数量
		U32 bound = 0;
        U16 check = 0;
		archive.Bind( bound );
        archive.Bind( check );

        // 判断校验和是否正确；
        if( check == 
            internet_checksum( & bound , sizeof(bound) ) )
        {
            atom::initialize<Key>  k_initiate;
            atom::initialize<Item> i_initiate;

		    // 反序列化物品，并放入容器内；
		    container.clear();
		    for( size_t z = 0; z < bound; ++ z )
		    {
			    Key  k; k_initiate( k );
			    Item i; i_initiate( i );

			    archive.Bind( k );
			    archive.Bind( i );
			    container.insert( make_pair(k, i) );
		    }
        }

        // 失败，输出日志；
        else
        {
        }
	}
}

#elif defined(_MSC_VER) || defined(__INTEL_COMPILER)

template<class Archive, class Key, class Item, class Mtd, class Alc>
inline void Serialize(Archive & archive, stdext::hash_map<Key, Item, Mtd, Alc> & container, bool isSave)
{
	if( isSave )
	{
		// 获取容器内的物件数量；
		U32 bound = static_cast<U32>( container.size() );

        // 计算数量的校验和；
        U16 check = internet_checksum( & bound, sizeof(bound) );

		// 将物品数量与每一个物品写入档案内；
		archive.Bind( bound );
        archive.Bind( check );
		typename stdext::hash_map<Key, Item, Mtd, Alc>::
            iterator it = container.begin();
		for( ; it != container.end(); ++ it )
		{
            Key key = (*it).first;
			archive.Bind( key );
			archive.Bind( (*it).second );
		}
	}
	else
	{
		// 获取物品的数量
		U32 bound = 0;
        U16 check = 0;
		archive.Bind( bound );
        archive.Bind( check );

        // 判断校验和是否正确；
        if( check == 
            internet_checksum( & bound , sizeof(bound) ) )
        {
            atom::initialize<Key>  k_initiate;
            atom::initialize<Item> i_initiate;

		    // 反序列化物品，并放入容器内；
		    container.clear();
		    for( size_t z = 0; z < bound; ++ z )
		    {
			    Key  k; k_initiate( k );
			    Item i; i_initiate( i );

			    archive.Bind( k );
			    archive.Bind( i );
			    container.insert( make_pair(k, i) );
		    }
        }

        // 失败，输出日志；
        else
        {
        }
	}
}

#endif

// set容器序列化
template<class Archive, typename Item, typename Mtd, typename Alc>
inline void Serialize(Archive & archive, std::set<Item, Mtd, Alc> & container, bool isSave)
{
	if( isSave )
	{
		// 获取容器内的物件数量；
		U32 bound = static_cast<U32>( container.size() );

        // 计算数量的校验和；
        U16 check = internet_checksum( & bound, sizeof(bound) );

		// 将物品数量与每一个物品写入档案内；
		archive.Bind( bound );
        archive.Bind( check );
		typename std::set<Item, Mtd, Alc>::iterator it = container.begin();
		for( ; it != container.end(); ++ it )
		{
			archive.Bind( *it );
		}
	}
	else
	{
		// 获取物品的数量
		U32 bound = 0;
        U16 check = 0;
		archive.Bind( bound );
        archive.Bind( check );

        // 判断校验和是否正确；
        if( check == 
            internet_checksum( & bound, sizeof(bound) ) )
        {
            // 申明初始化；
            atom::initialize<Item> initiate;

		    // 反序列化物品，并放入容器内；
		    container.clear();
		    for( size_t i = 0; i < bound; ++ i )
		    {
			    Item item; initiate( item );
			    archive.Bind( item );
			    container.insert( item );
		    }
        }

        // 失败，输出日志；
        else
        {
        }
	}
}

// multiset容器序列化
template<class Archive, typename Item, typename Mtd, typename Alc>
inline void Serialize(Archive & archive, std::multiset<Item, Mtd, Alc> & container, bool isSave)
{
	if( isSave )
	{
		// 获取容器内的物件数量；
		U32 bound = static_cast<U32>( container.size() );

        // 计算数量的校验和；
        U16 check = internet_checksum( & bound, sizeof(bound) );

		// 将物品数量与每一个物品写入档案内；
		archive.Bind( bound );
        archive.Bind( check );
		typename multiset<Item, Mtd, Alc>::iterator it = container.begin();
		for( ; it != container.end(); ++ it )
		{
			archive.Bind( *it );
		}
	}
	else
	{
		// 获取物品的数量
		U32 bound = 0;
        U16 check = 0;
		archive.Bind( bound );
        archive.Bind( check );

        // 判断校验和是否正确；
        if( check == 
            internet_checksum( & bound, sizeof(bound) ) )
        {
            atom::initialize<Item> initiate;

		    // 反序列化物品，并放入容器内；
		    container.clear();
		    for( size_t i = 0; i < bound; ++ i )
		    {
			    Item item; initiate( item );
			    archive.Bind( item );
			    container.insert( item );
		    }
        }

        // 失败，输出日志；
        else
        {
        }
	}
}

// multimap容器序列化
template<class Archive, class Key, class Item, class Mtd, class Alc>
inline void Serialize(Archive & archive, multimap<Key, Item, Mtd, Alc> & container, bool isSave)
{
	if( isSave )
	{
		// 获取容器内的物件数量；
		U32 bound = static_cast<U32>( container.size() );

        // 计算数量的校验和；
        U16 check = internet_checksum( & bound, sizeof(bound) );

		// 将物品数量与每一个物品写入档案内；
		archive.Bind( bound );
        archive.Bind( check );
		typename std::multimap<Key, Item, Mtd, Alc>::
            iterator it = container.begin();
		for( ; it != container.end(); ++ it )
		{
            Key key = (*it).first;
			archive.Bind( key );
			archive.Bind( (*it).second );
		}
	}
	else
	{
		// 获取物品的数量
		U32 bound = 0;
        U16 check = 0;
		archive.Bind( bound );
        archive.Bind( check );

        // 判断校验和是否正确；
        if( check == 
            internet_checksum( & bound , sizeof(bound) ) )
        {
            atom::initialize<Key>  k_initiate;
            atom::initialize<Item> i_initiate;

		    // 反序列化物品，并放入容器内；
		    container.clear();
		    for( size_t z = 0; z < bound; ++ z )
		    {
			    Key  k; k_initiate( k );
			    Item i; i_initiate( i );

			    archive.Bind( k );
			    archive.Bind( i );
			    container.insert( make_pair(k, i) );
		    }
        }

        // 失败，输出日志；
        else
        {
        }
	}
}

#endif /*STL_SERIALIZATION_H_*/
