#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <numeric>

#define INF 1000000009
#define ll long long
#define sort stable_sort

using namespace std;

ifstream in("count.in");
ofstream out("count.out");

int main() {
	int n, m;
	in >> m;
	in >> n;

	vector < vector<ll> > mass;
	mass.resize(m + 1);
	for (int i = 0; i <= m; i++) mass[i].assign(n + 1, 0);
	for (int i = 0; i <= m; i++) mass[i][0] = 1;
	for (int i = 1; i <= m; i++){
		for (int j = 1; j <= n; j++){
			for (int u = 0; u <= j; u++){
				mass[i][j] += mass[i - 1][u];
			}
		}
	}	
	ll ans = 0;
	for (int i = 0; i <= n; i++){
		ans += mass[m][i];
	}

	out << ans << '\n';
	return 0;
}
