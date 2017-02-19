#include "binary.h"
using namespace std;

Bin_Heap::Bin_Heap(): sz(0){}

Bin_Heap::~Bin_Heap(){
	heap.clear();
}

int Bin_Heap::size(){
	return sz;
}

void Bin_Heap::Add(int x){
	heap.push_back(x);
	SiftUp(sz);
	sz++;
}

int Bin_Heap::ExtractMin(){
	sz--;
	int ans = heap[0];
	swap(heap[0], heap[sz]);
	SiftDown(0);
	heap.pop_back();
	return ans;
}