#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;
typedef bool (*func)(int x);
typedef int (*fun)(int x);

class Enumerator{
public:
	virtual bool HasNext()=0;
	virtual int Next()=0;
};

class VectorEnumerator: public Enumerator{
public:
	vector <int> *v;
	int index;
	VectorEnumerator(vector <int> *vec){
		v = vec;
		index = 0;
	}
	bool HasNext(){
		return index < v->size();
	}
	int Next(){
		return (*v)[index++];
	}
};

class Enumerable{
public:
	Enumerator* enumer;
	Enumerable(vector <int> *v){
		enumer = (Enumerator*) new VectorEnumerator(v);
	}
	~Enumerable(){
		delete enumer;
	}
	Enumerable filter(func f){
		vector <int>* tmp = new vector <int>;
		while (enumer->HasNext()){
			int x = enumer->Next();
			if (f(x) == true){
				(*tmp).push_back(x);
			}
		}
		Enumerable t(tmp);
		return t;
	}
	Enumerable map(fun f){
		vector <int>* tmp = new vector <int>;
		int i = 0;
		while (enumer->HasNext()){
			int x = f(enumer->Next());
			(*tmp).push_back(x);
		}
		Enumerable t(tmp);
		return t;	
	}
	int first(){
		return enumer->Next();
	}
	Enumerator* GetEnumerator(){
		return enumer;
	}

};

bool f1(int x){
	return x < 5;
}

int f2(int x){
	return x + 5;
}

int main(){

	vector <int>* v = new vector <int>;
	(*v).resize(3);
	(*v)[0] = 1; (*v)[1] = 5; (*v)[2] = 3;
	Enumerable ebl(v);
	//Enumerator* e = ebl.GetEnumerator();
	/*while (e->HasNext()){
		cout << e->Next() << ' ';
	}
	cout << '\n';
	cout << ebl.first() << '\n';
	Enumerable ebl1 = ebl.map(f2);
	Enumerator* e = ebl1.GetEnumerator();
	while (e->HasNext()){
		cout << e->Next() << ' ';
	}
	cout << '\n';*/

	

	return 0;
}