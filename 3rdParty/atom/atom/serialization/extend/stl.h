#ifndef STL_SERIALIZATION_H_
#define STL_SERIALIZATION_H_
// STL�������л���֧�֣�Ŀǰ��֧��string, vector, pair, map, hash_map, set, multiset��
#include "../../Common.h"
#include "../../utility/stl/stl_extend.h"
#include "../../utility/stl/a_string.h"
#include "../../utility/stl/a_wstring.h"
#include "../../utility/checksum/alogrithm/internet/internet.h"


// std::string�ַ������л�
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

// std::wstring�ַ������л�
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

// std::vector�������л�
template<class Archive, class Item, class Alc>
inline void Serialize(Archive & archive, std::vector<Item, Alc> & container, bool isSave)
{
	if( isSave )
	{
		// ��ȡ�����������������
		U32 bound = static_cast<U32>( container.size() );

        // ����������У��ͣ�
        U16 check = internet_checksum( & bound, sizeof(bound) );

		// ����Ʒ��������ÿһ����Ʒд�뵵���ڣ�
		archive.Bind( bound );
        archive.Bind( check );
		for( size_t i = 0; i < bound; ++ i ) {
            archive.Bind( container[i] );
        }
	}
	else
	{
		// ��ȡ��������Ʒ��������
		U32 bound = 0;
        U16 check = 0;
		archive.Bind( bound );
        archive.Bind( check );

        // �ж�У����Ƿ���ȷ��
        if( check ==
            internet_checksum( & bound, sizeof(bound) ) )
        {
            atom::initialize<Item> initiate;

		    // �����л���Ʒ�������������ڣ�
		    container.clear();
		    for( size_t i = 0; i < bound; ++ i )
		    {
                // ��������ʼ������
			    Item item; initiate( item );

                // �����л����󣬲�����������
			    archive.Bind( item );
			    container.push_back( item );
		    }
        }

        // ���������־��
        else
        {
        }
	}
}

// std::list�������л�
template<class Archive, class Item, class Alc>
inline void Serialize(Archive & archive, std::list<Item, Alc> & container, bool isSave)
{
	if( isSave )
	{
		// ��ȡ�����������������
		U32 bound = static_cast<U32>( container.size() );

        // ����������У��ͣ�
        U16 check = internet_checksum( &bound, sizeof(bound) );

		// ����Ʒ��������ÿһ����Ʒд�뵵���ڣ�
		archive.Bind( bound );
        archive.Bind( check );
		for( typename std::list<Item, Alc>::iterator 
			it = container.begin(); it != container.end(); ++ it ) {
			archive.Bind( *it );
		}
	}
	else
	{
		// ��ȡ��������Ʒ��������
		U32 bound = 0;
        U16 check = 0;
		archive.Bind( bound );
        archive.Bind( check );

        // �ж�У����Ƿ���ȷ��
        if( check == 
            internet_checksum( & bound, sizeof(bound) ) )
        {
            atom::initialize<Item> initiate;

		    // �����л���Ʒ�������������ڣ�
		    container.clear();
		    for( size_t i = 0; i < bound; ++ i )
		    {
			    Item item; initiate( item );

			    archive.Bind( item );
			    container.push_back( item );
		    }
        }

        // ���������־��
        else
        {
        }
	}
}

// std::pair�������л�
template<class Archive, class First, class Second>
inline void Serialize(Archive & archive, std::pair<First, Second> & container, bool isSave)
{
    UNREFERENCED_PARAMETER( isSave );
    archive.Bind( container.first  );
	archive.Bind( container.second );
}

// std::map�������л�
template<class Archive, class Key, class Item, class Cmp, class Alc>
inline void Serialize(Archive & archive, std::map<Key, Item, Cmp, Alc> & container, bool isSave)
{
	if( isSave )
	{
		// ��ȡ�����ڵ����������
		U32 bound = static_cast<U32>( container.size() );

        // ����������У��ͣ�
        U16 check = internet_checksum( & bound, sizeof(bound) );

		// ����Ʒ������ÿһ����Ʒд�뵵���ڣ�
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
		// ��ȡ��Ʒ������
		U32 bound = 0;
        U16 check = 0;
		archive.Bind( bound );
        archive.Bind( check );

        // �ж�У����Ƿ���ȷ��
        if( check == 
            internet_checksum( & bound , sizeof(bound) ) )
        {
            atom::initialize<Key>  k_initiate;
            atom::initialize<Item> i_initiate;

		    // �����л���Ʒ�������������ڣ�
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

        // ���������־��
        else
        {
        }
	}
}

// hash_map�������л�
#if defined(__GNUC__)

template<class Archive, class Key, class Item, class Hash, class Mtd, class Alc>
inline void Serialize(Archive & archive, hash_map<Key, Item, Hash, Mtd, Alc> & container, bool isSave)
{
	if( isSave )
	{
		// ��ȡ�����ڵ����������
		U32 bound = static_cast<U32>( container.size() );

        // ����������У��ͣ�
        U16 check = internet_checksum( & bound, sizeof(bound) );

		// ����Ʒ������ÿһ����Ʒд�뵵���ڣ�
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
		// ��ȡ��Ʒ������
		U32 bound = 0;
        U16 check = 0;
		archive.Bind( bound );
        archive.Bind( check );

        // �ж�У����Ƿ���ȷ��
        if( check == 
            internet_checksum( & bound , sizeof(bound) ) )
        {
            atom::initialize<Key>  k_initiate;
            atom::initialize<Item> i_initiate;

		    // �����л���Ʒ�������������ڣ�
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

        // ʧ�ܣ������־��
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
		// ��ȡ�����ڵ����������
		U32 bound = static_cast<U32>( container.size() );

        // ����������У��ͣ�
        U16 check = internet_checksum( & bound, sizeof(bound) );

		// ����Ʒ������ÿһ����Ʒд�뵵���ڣ�
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
		// ��ȡ��Ʒ������
		U32 bound = 0;
        U16 check = 0;
		archive.Bind( bound );
        archive.Bind( check );

        // �ж�У����Ƿ���ȷ��
        if( check == 
            internet_checksum( & bound , sizeof(bound) ) )
        {
            atom::initialize<Key>  k_initiate;
            atom::initialize<Item> i_initiate;

		    // �����л���Ʒ�������������ڣ�
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

        // ʧ�ܣ������־��
        else
        {
        }
	}
}

#endif

// set�������л�
template<class Archive, typename Item, typename Mtd, typename Alc>
inline void Serialize(Archive & archive, std::set<Item, Mtd, Alc> & container, bool isSave)
{
	if( isSave )
	{
		// ��ȡ�����ڵ����������
		U32 bound = static_cast<U32>( container.size() );

        // ����������У��ͣ�
        U16 check = internet_checksum( & bound, sizeof(bound) );

		// ����Ʒ������ÿһ����Ʒд�뵵���ڣ�
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
		// ��ȡ��Ʒ������
		U32 bound = 0;
        U16 check = 0;
		archive.Bind( bound );
        archive.Bind( check );

        // �ж�У����Ƿ���ȷ��
        if( check == 
            internet_checksum( & bound, sizeof(bound) ) )
        {
            // ������ʼ����
            atom::initialize<Item> initiate;

		    // �����л���Ʒ�������������ڣ�
		    container.clear();
		    for( size_t i = 0; i < bound; ++ i )
		    {
			    Item item; initiate( item );
			    archive.Bind( item );
			    container.insert( item );
		    }
        }

        // ʧ�ܣ������־��
        else
        {
        }
	}
}

// multiset�������л�
template<class Archive, typename Item, typename Mtd, typename Alc>
inline void Serialize(Archive & archive, std::multiset<Item, Mtd, Alc> & container, bool isSave)
{
	if( isSave )
	{
		// ��ȡ�����ڵ����������
		U32 bound = static_cast<U32>( container.size() );

        // ����������У��ͣ�
        U16 check = internet_checksum( & bound, sizeof(bound) );

		// ����Ʒ������ÿһ����Ʒд�뵵���ڣ�
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
		// ��ȡ��Ʒ������
		U32 bound = 0;
        U16 check = 0;
		archive.Bind( bound );
        archive.Bind( check );

        // �ж�У����Ƿ���ȷ��
        if( check == 
            internet_checksum( & bound, sizeof(bound) ) )
        {
            atom::initialize<Item> initiate;

		    // �����л���Ʒ�������������ڣ�
		    container.clear();
		    for( size_t i = 0; i < bound; ++ i )
		    {
			    Item item; initiate( item );
			    archive.Bind( item );
			    container.insert( item );
		    }
        }

        // ʧ�ܣ������־��
        else
        {
        }
	}
}

// multimap�������л�
template<class Archive, class Key, class Item, class Mtd, class Alc>
inline void Serialize(Archive & archive, multimap<Key, Item, Mtd, Alc> & container, bool isSave)
{
	if( isSave )
	{
		// ��ȡ�����ڵ����������
		U32 bound = static_cast<U32>( container.size() );

        // ����������У��ͣ�
        U16 check = internet_checksum( & bound, sizeof(bound) );

		// ����Ʒ������ÿһ����Ʒд�뵵���ڣ�
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
		// ��ȡ��Ʒ������
		U32 bound = 0;
        U16 check = 0;
		archive.Bind( bound );
        archive.Bind( check );

        // �ж�У����Ƿ���ȷ��
        if( check == 
            internet_checksum( & bound , sizeof(bound) ) )
        {
            atom::initialize<Key>  k_initiate;
            atom::initialize<Item> i_initiate;

		    // �����л���Ʒ�������������ڣ�
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

        // ʧ�ܣ������־��
        else
        {
        }
	}
}

#endif /*STL_SERIALIZATION_H_*/
