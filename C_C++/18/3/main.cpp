#include <iostream>
#include <algorithm>
#include <map>
#include <iterator>
#include <string>

using namespace std;

typedef istream_iterator<int> iii;
typedef ostream_iterator<int> oii;
typedef vector<int>::iterator vi;

struct printed{
	int operator()(int x){
		return x;
	}
};

int a;

bool Part1(int x){
	return (x < a);
}

bool Part2(int x){
	return (x == a);
}

void quicki_sort(vi l, vi r){
	a = *(l + distance(l, r) / 2);
	vi b1 = stable_partition(l, r, Part1);
	vi b2 = stable_partition(b1, r, Part2);
	if (l < b1) quicki_sort(l, b1 - 1);
	if (r > b2) quicki_sort(b2, r);
}


int main(){

	freopen("test.in", "r", stdin);
	iii beg = iii (cin);
	iii end = iii ();
	vector <int> mass;
	mass.resize(distance(beg, end));
	printed p;
	transform(beg, end, mass.begin(), p);
	quicki_sort(mass.begin(), mass.end());

	oii it = oii (cout, " ");
	transform(mass.begin(), mass.end(), it, p);
	cout << '\n';

	return 0;
}