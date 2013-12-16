#ifdef _MSC_VER
	#ifndef SAFE_ERASE
	#define SAFE_ERASE(c,i) (i)=(c).erase(i)
	#endif

	#ifndef HASH_MAP_DEF
	#define HASH_MAP_DEF(K,V) stdext::hash_map<K, V, atom_hash_compare<K, less<K> >, atom_allocator<pair<K, V> > >
	#endif
#endif