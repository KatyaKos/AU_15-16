#define _CRT_SECURE_NO_WARNINGS
#pragma comment (linker, "/STACK:10000000000")

#include <vector>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <numeric>
#include <stack>

 
#define INF 1000000009
#define ll long long
#define ui unsigned int

using namespace std;

ui n, q, a, b, lp, rp;
vector < pair<ui, ui> > mass;
vector <ui> psum;
vector <ui> val;
vector <ui> coord;
ui cur = 0;

ui nextRand24() {
	cur = cur * a + b; 
	return cur >> 8; 
}

ui nextRand32() {
	ui a = nextRand24(), b = nextRand24();
	return (a << 8) ^ b; 
}

int main() {

	freopen("linesum.in", "r", stdin);
	freopen("linesum.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q >> a >> b;
	mass.resize(n);
	coord.resize(n);
	val.resize(n);

	for (ui i = 0; i < n; i++){
		mass[i].second = nextRand32(); 
		mass[i].first = nextRand32();
	}

	sort(mass.begin(), mass.end());
	//for (int i = 0; i < n; i++) cout << mass[i].first << ' ' << mass[i].second << '\n';
	for (ui i = 0; i < n; i++){
		coord[i] = mass[i].first;
		val[i] = mass[i].second;
	}
	//mass.clear();

	psum.resize(n + 1);
	psum[0] = 0;
	for (ui i = 0; i < n; i++){
		psum[i + 1] = psum[i] + val[i];
	}

	ui ans = 0;
	for (ui i = 0; i < q; i++){

		lp = nextRand32();
		rp = nextRand32();
		if (lp > rp) swap(lp, rp);

		ui tl = lower_bound(coord.begin(), coord.end(), lp) - coord.begin(), tr = upper_bound(coord.begin(), coord.end(), rp) - coord.begin() - 1;
		
		if (tl <= tr && tl <= n && tr <= n) ans += psum[tr + 1] - psum[tl];
		//cout << ans << '\n';

	}	

	cout << ans << '\n';


	return 0;
}


