#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include "boas.h"

using namespace std;

VAB_Heap::VAB_Heap(): sz(0), k(-1), index(NULL){}

VAB_Heap::~VAB_Heap(){
	if (index != NULL) delete index;
	for (int i = 0; i < sqrt(k) + 1; i++){
		if (hmap[i] != NULL) delete hmap[i];
	}
}

void VAB_Heap::Add(int x, int c){
	if (sz == 0){
		sz = 1;
		min = x;
		k = c;
		return;
	}

	if (x < min){
		swap(x, min);
	}

	int i = x / sqrt(c);
	if (hmap[i] == NULL) hmap[i] = new VAB_Heap;
	if (hmap[i]->sz == 0){
		if (index == NULL) index = new VAB_Heap;
		index->Add(i, sqrt(c));
	}
	hmap[i]->Add(x, sqrt(c));
	sz++;
}

void VAB_Heap::Delete(int x, int c){
	if (min == x) ExtractMin();
	else{
		int i = x / sqrt(c);
		hmap[i]->Delete(x, sqrt(c));
		if (hmap[i]->sz == 0) index->Delete(i, sqrt(c));
		sz--;
		//if (sz == 0) index->Delete(i)
	}
}

int VAB_Heap::ExtractMin(){
	int ans = min;
	sz--;
	if (sz == 0){
		return ans;
	}

	VAB_Heap* h = hmap[index->min];
	min = h->ExtractMin();
	if (h->sz == 0) index->ExtractMin();
	return ans;
}

int VAB_Heap::size(){
	return sz;
}
