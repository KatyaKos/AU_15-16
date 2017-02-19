#ifndef _BMP_H_
#define _BMP_H_
#include <iostream>
using namespace std;
template <typename T, size_t sz>
class Array{
private:
	T el[sz];
public:
	Array(){}
	T& operator[](size_t i){
		return el[i];
	}
	T const & operator[](size_t i) const{
		return el[i];
	}

	size_t size() const{
		return sz;
	}
};

int chnum(int i){
	int n = i / sizeof(char);
	if (i % sizeof(char) != 0){
		n++;
	}
	return n;
}

class supCh{
private:
	int i;
	char& c;
public:
	supCh(int ii, char& cc): i(ii), c(cc){
	}
	operator bool(){
		return c & (1 << i);
	}
	bool operator=(bool t){
		if (t == true){
			c |= 255 & (1 << i);
		}else{
			c &= 255 ^ (1 << i);
		}
		return bool();
	}
	bool operator=(supCh& a){
		c = (bool)a;
		return c;
	}

};

template <size_t sz>
class Array<bool, sz>{
private:
	char* el;
	int n;
public:
	Array(){
		n = chnum(sz);
		el = new char[n];
	}
	~Array(){
		delete [] el;
	}
	size_t size() const{
		return sz;
	}
	supCh operator[](size_t i){
		int m = i / sizeof(char);
		return supCh(i % sizeof(char), el[m]);
	}

};

template <typename T, class Cont, const size_t sz>
class Stack{
private:
	Cont arr;
	size_t cap;
public:
	Stack(){
		cap = 0;
	}
	size_t size(){
		return cap;
	}
	T& top(){
		return arr[cap - 1];
	}
	T const& top() const{
		return arr[cap - 1];
	}
	void push(T const& t){
		if (cap == sz) cout << "You are jerk!\n";
		else{
			arr[cap] = t;
			cap++;
		}
	}
	void pop(){
		if (cap == 0) cout << "You are jerk!\n";
		else{
			cap--;
		}
	}
	bool empty(){
		if (cap == 0) return true;
		else return false;
	}
};
#endif