#define _CRT_SECURE_NO_WARNINGS
//#pragma comment (linker, "/STACK:10000000000")

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
#define ui unsigned int
#define mp make_pair

using namespace std;

ll n, k;
map <ll, ll> f;

ll go(ll i){
	if (i <= k) return 1;
	if (f[i] != 0) return f[i];
	if (i % 2 == 0) f[i] = 2 * go(i / 2);
	else f[i] = go(i / 2) + go(i / 2 + 1);
	return f[i];
}

int main() {

	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("kittens.in", "r", stdin);
	freopen("kittens.out", "w", stdout);

	cin >> n >> k;
	cout << go(n) << '\n';

	return 0;
}