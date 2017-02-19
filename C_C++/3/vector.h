#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <cstdlib>

struct Vector{

	int* p;
	int size;
	int capacity;

	Vector(){
		size = 0;
		capacity = 1;
		p = (int* )malloc(capacity*sizeof(int));

	}

	void resize_mem(int mem){

		int capacity2 = mem;
		int* p2 = malloc(capacity2*sizeof(int));
		for (int i = 0; i < size; i++){
			p2[i] = p[i];
		}
		free(p);
		p = p2;
		capacity = capacity2;

	}

	void push_back(int x){

		if (capacity == size){
			int capacity2 = capacity * 2;
			int* p2 = (int* )malloc(capacity2*sizeof(int));
			for (int i = 0; i < size; i++){
				p2[i] = p[i];
			}
			free(p);
			p = p2;
			capacity = capacity2;
		}
		
		p[size] = x;
		size += 1;

		
	}

	int get(int i){
		return p[i];
	}
	
	void set(int i, int x){
		p[i] = x;
	}

	void reserve(int n){

		int capacity2 = n;
		int* p2 = (int* )malloc(capacity2*sizeof(int));
		for (int i = 0; i < size; i++){
			p2[i] = p[i];
		}
		free(p);
		p = p2;
		capacity = capacity2;

	}

	void shrink(){

		int capacity2 = size;
		int* p2 = (int* )malloc(capacity2*sizeof(int));
		for (int i = 0; i < size; i++){
			p2[i] = p[i];
		}
		free(p);
		p = p2;
		capacity = capacity2;

	}

	int pop_back(){

		int tmp = p[size - 1];
		size -= 1;
		return tmp;

	}

	
	
	~Vector(){
		free(p);
	}
};

#endif
