#include "deque.h"
#define psb push_back
#define ppb pop_back

using namespace std;

int main(){

	Deque<int, 5> d;

	for (int i = 0; i < 5; i++){
		d.psb(i);
	}
	cout << *d.begin() << '\n';
	cout << *d.end() << '\n';
	cout << d.mysize() << '\n';

	d.psb(6);
	cout << '\n';
	cout << *d.begin() << '\n';
	cout << *d.end() << '\n';
	cout << d.mysize() << '\n';

	d.ppb();
	cout << '\n';
	cout << *d.begin() << '\n';
	cout << *d.end() << '\n';
	cout << d.mysize() << '\n';

	cout << '\n';
	for (Deque<int, 5>::iterator it = d.begin(); it != d.end(); ++it){
		cout << *it << ' ';
	}
	cout << '\n';

	return 0;
}