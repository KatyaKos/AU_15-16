#define _CRT_SECURE_NO_WARNINGS
#pragma comment (linker, "/STACK:10000000000")

#include <vector>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <stack>
#include <map>
 
#define INF 1000000009
#define ll long long
#define sort stable_sort

using namespace std;



#include <cstdio>

int main() {

	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("queries.in", "r", stdin);
	freopen("queries.out", "w", stdout);

	int n, q;
	cin >> n;
	vector < pair<int, int> > town;
	town.resize(n);
	for (int i = 0; i < n; i++){
		cin >> town[i].first;
		town[i].second = i;
	}

	sort(town.begin(), town.end());
	
	cin >> q;
	int l, r, x;
	for (int i = 0; i < q; i++){
		cin >> l >> r >> x;
		if (upper_bound(town.begin(), town.end(), make_pair(x, r - 1)) - lower_bound(town.begin(), town.end(), make_pair(x, l - 1)) != 0){
			cout << 1;
		}else{
			cout << 0;
		}
	}
	cout << '\n';

	return 0;
}





