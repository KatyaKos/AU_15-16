#include <iostream>
#include <set>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <time.h>

using namespace std;

const int M = 100000;

int main(){
	freopen("boas_test.in", "w", stdout);
	srand(time(NULL));

	int nel, ntests, n, rnd;

	//number of tests
	ntests = rand() % 500;
	cout << ntests << '\n';

	for (int y = 0; y < ntests; y++){
		//number of actions
		rnd = rand();
		if (rnd % 6 == 0) n = rnd % 100;
		else if (rnd % 6 == 1) n = 100 + rnd % 900;
		else n = 1000 + rnd % 9000;
		//else if (rnd % 5 == 2 || rnd % 5 == 3) n = 1000 + rnd % 9000;
		//else n = 10000 + rnd % 90000;
		cout << n <<'\n';

		nel = 0;
		int el, itnum;
		multiset<int>::iterator it;
		multiset <int> mass;
		for (int i = 0; i < n; i++){
			if (nel > 0){
				rnd = rand() % 4;
				if (rnd == 0 || rnd == 2){
					el = rand() % M;
					mass.insert(el);
					cout << "A " << el << '\n';
					nel++;
				}else if (rnd == 1){
					el = *mass.begin();
					mass.erase(mass.begin());
					cout << "E " << el << '\n';
					nel--;
				}else{
					itnum = rand() % mass.size();
					it = mass.begin();
					for (int j = 0; j < itnum; j++){
						it++;
					}
					el = *it;
					mass.erase(it);
					cout << "D " << el << '\n';
					nel--;
				}
			} else{
				el = rand() % M;
				mass.insert(el);
				cout << "A " << el << '\n';
				nel++;
			}
		}

	}


	return 0;
}