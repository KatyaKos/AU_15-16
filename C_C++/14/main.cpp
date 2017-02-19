#include <cstdio>
#include <cstring>
#include <new>
#include "vector.h"

using namespace std;

int main(){

	Vector<int> v(5);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	cout << v.size() << '\n';
	cout << v[2] << '\n';
	v.push_back(60);
	v.push_back(80);
	cout << v.size() << '\n';
	cout << v[4] << '\n';
	v.push_back(90);
	v.push_back(100);
	cout << v.size() << '\n';
	cout << v[6] << '\n';

	return 0;
}