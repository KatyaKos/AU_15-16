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
#define sort stable_sort

using namespace std;
int m, q;
const int S = 1 << 24;
unsigned int a, b, cur = 0;
vector <unsigned int> mass(S + 1, 0);
vector <unsigned int> psum(S + 1, 0);

unsigned int nextRand() {
	cur = cur * a + b;
	return cur >> 8;   
}

int main() {

	freopen("fastadd.in", "r", stdin);
	freopen("fastadd.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> m >> q >> a >> b;

	int l, r, add;
	for (int i = 0; i < m; i++){
		add = nextRand();
		l = nextRand();
		r = nextRand();
		if (l > r) swap(l, r);
		mass[l] += add;
		mass[r + 1] -= add;
	}

	psum[0] = 0;
	for (int i = 1; i < S; i++){
		mass[i] = mass[i] + mass[i - 1];
		psum[i] = psum[i - 1] + mass[i - 1];
	}
	psum[S] = psum[S - 1] + mass[S - 1];

	unsigned int ans = 0;
	for (int i = 0; i < q; i++){
		l = nextRand();
		r = nextRand();
		if (l > r) swap(l, r);
		ans = psum[r + 1] - psum[l] + ans;
	}

	cout << ans << '\n';

	return 0;
}

