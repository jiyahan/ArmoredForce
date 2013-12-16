#ifdef __GNUC__
	#ifndef SAFE_ERASE
	#define SAFE_ERASE(c,i) (c).erase((i)++)
	#endif

	#ifndef HASH_MAP_DEF
	#define HASH_MAP_DEF(K,V) hash_map<K, V, atom_hash<K>, equal_to<K>, atom_allocator<V> >
	#endif
#endif