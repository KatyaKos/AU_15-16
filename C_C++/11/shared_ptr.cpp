#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

class MyClass{
public:
	MyClass(){
		cout << "+1\n";
	}
	~MyClass(){
		cout << "-1\n";
	}
};

class Internal{
private:
	MyClass* myobj;
	int count;
public:
	Internal(MyClass* obj){
		myobj = obj;
		count = 1;
	}
	~Internal(){
		delete myobj;
	}
	void lock(){
		count++;
	}
	void release(){
		count--;
		if (count == 0){
			delete this;
		}
	}
	MyClass* get(){
		return myobj;
	}

};

class Shared_ptr{
private:
	Internal* inter;
public:
	Shared_ptr(MyClass* obj){
		inter = new Internal(obj);
	}
	Shared_ptr(const Shared_ptr& shr){
		inter = shr.inter;
		inter->lock();
	}
	~Shared_ptr(){
		inter->release();
	}
	MyClass* operator->() const{
		return inter->get();
	}
	MyClass& operator*() const{
		return *inter->get();
	}

};

bool operator==(const Shared_ptr &p1, const Shared_ptr &p2){
	return p1.operator->() == p2.operator->();
}
bool operator!=(const Shared_ptr &p1, const Shared_ptr &p2){
	return p1.operator->() != p2.operator->();
}
bool operator<(const Shared_ptr &p1, const Shared_ptr &p2){
	return p1.operator->() < p2.operator->();
}
bool operator>(const Shared_ptr &p1, const Shared_ptr &p2){
	return p1.operator->() > p2.operator->();
}
bool operator>=(const Shared_ptr &p1, const Shared_ptr &p2){
	return p1.operator->() >= p2.operator->();
}
bool operator<=(const Shared_ptr &p1, const Shared_ptr &p2){
	return p1.operator->() <= p2.operator->();
}


int main(){
	MyClass* m = new MyClass;
	Shared_ptr shr(m);
	Shared_ptr shr1(shr);
}