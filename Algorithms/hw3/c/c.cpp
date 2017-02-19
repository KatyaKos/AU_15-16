#pragma comment (linker, "/STACK:10000000000")
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

using namespace std;
vector <int> mass;

int BS(int l, int r, int x){
	
	while (l != r - 1){
		//cout << l << ' ' << r << '\n';
		ll m = (l + r) / 2;
		if (mass[m] > x) r = m;
		else l = m;
	}
	return l;
}
  
  
int main() {

	freopen("find2.in", "r", stdin);
	freopen("find2.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	mass.resize(n);
	for (int i = 0; i < n; i++){
		cin >> mass[i];
	}

	int x;
	cin >> x;
	int l = BS(-1, n, x);
	if (mass[l] == x) cout << "YES" << '\n';
	else cout << "NO" << '\n';

	for (int i = 1; i < m; i++){

		cin >> x;
		l = BS(l, n, x);
		if (mass[l] == x) cout << "YES" << '\n';
		else cout << "NO" << '\n';

	}
	return 0;
}
