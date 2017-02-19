#ifndef _BINARY_H_
#define _BINARY_H_
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

class Bin_Heap{
private:
	vector <int> heap;
	int sz;

	void SiftDown(int i){
		int j;
		while (2 * i + 1 < sz){
			if (heap[2 * i + 2] <= heap[2 * i + 1]) j = 2 * i + 2;
			else j = 2 * i + 1;

			if (heap[i] > heap[j]){
				swap(heap[i], heap[j]);
				i = j;
			} else break;
		}
	}

	void SiftUp(int i){
		while (i > 0 && heap[(i - 1) / 2] > heap[i]){
			swap(heap[i], heap[(i - 1) / 2]);
			i = (i - 1) / 2;
		}
	}
public:
	Bin_Heap();
	~Bin_Heap();
	int ExtractMin();
	void Add(int x);
	int size();
};
#endif