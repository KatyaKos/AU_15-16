#include "vector.h"
#include <iostream>

int main(){

	Vector v;

	v.reserve(10);

	v.push_back(5);
	v.push_back(67);
	v.push_back(-1);
	for (int i = 0; i < 3; i++) std::cout << v.get(i) << ' ';
	std::cout << '\n';

	v.set(1, 24);
	for (int i = 0; i < 3; i++) std::cout << v.get(i) << ' ';
	std::cout << '\n';

	v.shrink();

	std:: cout << v.pop_back() << '\n';

	return 0;
}
