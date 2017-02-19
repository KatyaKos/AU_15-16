#ifndef DEQUE_H
#define DEQUE_H
#include <iostream>

using namespace std;

template <class T, int sz>
class Deque{
private:
	T** deq; //массив T*
	int size, cap;

public:
	class iterator{
	private:
		Deque* d;
		T* el;
		int i, j;
		friend class Deque;
	public:

		iterator();
		iterator(Deque* d): i(0), j(0), d(d){
			el = &(d->deq[0][0]);
		}
		iterator(Deque* dq, int i, int j): d(dq), i(i), j(j){
			el = &(d->deq[i][j]);
		}
		iterator(Deque* d, iterator& it): d(d), el(it.el), i(it.i), j(it.j){}

		bool operator==(const iterator& it) const{
			return (el == it.el);
		}
		bool operator!=(const iterator &it) const{
			return !(it == *this);
		}

		iterator& operator++(){
			if (j < sz - 1){
				el = &d->deq[i][j + 1];
				j++;
			}
			else if (j == sz - 1 && i < d->cap - 1){
				el = &d->deq[i + 1][0];
				i++; j = 0;
			}
			else{
				el = NULL;
				i = -1; j = -1;
			}

			return *this;
		}

		iterator& operator--(){
			if (j > 0){
				el = &d->deq[i][j - 1];
				j--;
			}
			else if (j == 0 && i > 0){
				el = &d->deq[i - 1][sz - 1];
				i--; j = sz - 1;
			}
			else{
				el = NULL;
				i = -1; j = -1;
			}
			return *this;
		}

		T& operator*() const{
			return d->deq[i][j];
		}
	};

	Deque(){
		size = 0; cap = 1;
		deq = (T**) operator new(sizeof(T*));
		deq[0] = (T*) operator new(sizeof(T) * sz);
	}

	Deque(int len){
		size = 0; cap = len / sz  + 1;
		deq = (T**) operator new(sizeof(T*) * cap);
		for (int u = 0; u < cap; u++){
			deq[u] = (T*) operator new(sizeof(T) * sz);
		}
	}

	~Deque(){
		T** del_deq = deq;
		for (int u = 0; u < cap; u++){
			delete [] deq[u];
		}
	    delete del_deq;
	}

	bool isEmpty() const{
		return (size == 0);
	}
	int mysize() const{
		return size;
	}

	iterator begin(){
		return iterator(this, 0, 0);
	}
	iterator end(){
		if (size == 0) return iterator(this, 0, 0);
		if (size % sz == 0) return iterator(this, size / sz - 1, sz - 1);
		int i = size / sz, j = size - i * sz - 1;
		return iterator(this, i, j);
	}

	void push_back(const T& t){
		int i = size / sz;
		int j = size - i * sz;

		if(i < cap){
			new (deq[i] + j) T(t);
			size++;
		}else{
			int capacity = cap * 2;
			T** ptr = (T**) operator new(sizeof(T*) * capacity);
			for (int u = 0; u < cap; u++){
				ptr[u] = (T*) operator new(sizeof(T) * sz);
				for (int y = 0; y < sz; y++){
					ptr[u][y] = deq[u][y];
				}
			}
			ptr[cap] = (T*) operator new(sizeof(T) * sz);
			new (ptr[cap]) T(t);

			size++;
			delete [] deq;
			deq = ptr;
			cap = capacity;
		}
	}

	void pop_back(){
		if (size == 0) cout << "You are jerk!\n";
		else{
			size--;
			int i = size / sz;
			int j = size - i * sz; 
			deq[i][j].~T();
		}
	}
};


#endif