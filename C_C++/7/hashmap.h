#ifndef _HASHMAP_H_
#define _HASHMAP_H_
#include <cstdio>
#include <stdlib.h>
#include <vector>
#include <list>
struct Pair{
	char* key;
	char* val;
};

class HashMap{
private:
	int size;
	int p;
	std::vector < std::list<Pair>* >* map;
	long long Hash(char* s);
public:
	HashMap(int s);
	~HashMap();
	void Add(char* key, char* val);
	void Remove(char* key);
	char* Get(char* key);
	bool Contains(char* key);
};
#endif