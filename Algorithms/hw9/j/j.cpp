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
 
#define INF 1000000009
#define ll long long
#define ui unsigned int
#define mp make_pair
#define g21 0x55555555ul
#define g22 0x33333333ul
#define g23 0x0f0f0f0ful

using namespace std;

int main() {

	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("intersectsets.in", "r", stdin);
	freopen("intersectsets.out", "w", stdout);

	int n;
	vector <int> sts;
	cin >> n;
	sts.resize(n);
	int m, tmp;
	char bn[1 << 16];
	for (int i = 0; i < n; i++){
		cin >> m;
		tmp = 0;
		sts[i] = 0;
		for (int j = 0; j < m; j++){
			cin >> tmp;
			sts[i] += (1 << tmp);
		}
	}

	for(int i = 0; i < (1 << 16); i++){
		bn[i] = (i & 1) + bn[i >> 1];
	}

	int ans, ansi, a, b, c, ans1, ans2;
	for (int i = 0; i < n; i++){
		ans = 35;
		for (int j = 0; j < n; j++){
			if (i != j){
				unsigned int x = sts[i] ^ sts[j];
				int num = bn[x >> 16] + bn[x & 65535];
				if (num < ans){
					ans = num;
					ansi = j;
				}
			}
		}
		cout<< ansi + 1 << ' ' << ans << '\n';
	}

	return 0;
}