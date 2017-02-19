#include <iostream>
#include <algorithm>
#include <map>
#include <iterator>
#include <string>

using namespace std;

typedef istream_iterator<string> iis;
typedef ostream_iterator<string> ois;
typedef map<string, int>::iterator msi;

struct counted{
	map<string, int> mp;
	void operator() (string s){
		mp[s]++;
	}
};

struct printed{
	string operator() (pair<string, int> psi){
		return psi.first + ' ' + to_string(psi.second);
	}
};


int main(){

	freopen("txt.in", "r", stdin);
	freopen("txt.out", "w", stdout);
	iis beg = iis (cin);
	iis end = iis ();
	counted f;

	f = for_each(beg, end, f);

	map<string, int> m = f.mp;
	msi b = m.begin();
	msi e = m.end();
	ois it = ois (cout, "\n");
	printed p;
	
	transform(b, e, it, p);

	return 0;
}