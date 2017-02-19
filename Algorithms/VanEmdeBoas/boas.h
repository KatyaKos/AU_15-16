#ifndef _BOAS_H_
#define _BOAS_H_
#include <unordered_map>
#include <string.h>
#include <new>
using namespace std;

class VAB_Heap{
private:
	int min;
	int sz;
	int k;
	VAB_Heap* index;
	unordered_map <int, VAB_Heap*> hmap;
public:
	VAB_Heap();
	~VAB_Heap();
	int ExtractMin();
	void Delete(int x, int c);
	void Add(int x, int c);
	int size();
};
#endif