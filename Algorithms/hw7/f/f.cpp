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

using namespace std;

int main() {

	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("knapsack.in", "r", stdin);
	freopen("knapsack.out", "w", stdout);

	int n, w;
	cin >> w >> n;
	vector <int> mass;
	mass.resize(n);
	for (int i = 0; i < n; i++){
		cin >> mass[i];
	}

	vector <int> is;
	is.resize(w + 1);
	is[0] = 1;
	for (int i = 0; i < n; i++){
		for (int s = w - mass[i]; s >= 0; s--){
			if (is[s] == 1){
				is[s + mass[i]] = 1;
			}
		}
	}

	for (int i = w; i >= 0; i--){
		if (is[i] == 1){
			cout << i << '\n';
			return 0;
		}
	}

	return 0;
}