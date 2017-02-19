#ifndef _BMP_H_
#define _BMP_H_
#include <iostream>
#include <cstdlib>
using namespace std;

template <class T>
class Vector{
private:
	size_t sz;
	size_t cap;
	T* ptr;
public:
	Vector(){
		cap = 1; sz = 0;
		ptr = (T*) operator new(sizeof(T));
	}
	Vector(size_t size){
		cap = size; sz = 0;
		ptr = (T*) operator new(sizeof(T) * size);
	}
	~Vector(){
		for (int i = 0; i < cap; i++){
			ptr[i].~T();
		}
		free(ptr);
	}
	T& operator[](size_t i){
		return ptr[i];
	}
	void pop_back(){
		if (sz == 0) cout << "You are jerk!\n";
		else{
			sz--;
			ptr[sz].~T();
		}
	}
	size_t size(){
		return sz;
	}

	void push_back(const T& t) {
		if(sz < cap) {
			new (ptr2+sz) T(t);
			sz++;
		} else {
			size_t capacity = cap * 2;
			T* ptr2 = (T*) operator new(sizeof(T) * capacity);
			T *p2, *p;
			size_t i, flag = 0;

			try {
				p2 = ptr2;
				p = ptr;

				for(i = 0; i < sz; i++){
					new(p2) T(*p);
					flag++;
					p2 += 1; p++;				}

				new(&ptr2[sz]) T(t);
			}
			catch(...) {
				p2 = ptr2;
				for(size_t j = 0; j < flag; j++) {
					p2->~T();
					p2++
				}
				delete [] ptr2;
				throw;
			}

			sz++;
			delete [] ptr;
			ptr = ptr2;
			cap = capacity;
		}
	}
};

#endif