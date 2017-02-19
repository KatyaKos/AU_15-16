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
#include <set>
 
#define INF 1000000009
#define ll long long
#define ui unsigned int
#define mp make_pair

using namespace std;


int main() {

	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("m2e.in", "r", stdin);
	freopen("m2e.out", "w", stdout);

	int n;
	cin >> n;
	
	int u;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= i; j++){
			cin >> u;
		}
		for (int j = i + 1; j <= n; j++){
			cin >> u;
			if (u == 1){
				cout << i << ' ' << j << '\n';
			}
		}
	}

	return 0;
}