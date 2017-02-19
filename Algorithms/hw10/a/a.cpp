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
	freopen("incident.in", "r", stdin);
	freopen("incident.out", "w", stdout);

	int n, m;
	vector < vector<int> > ans;
	cin >> n >> m;
	if (m == 0){
		for (int i = 0; i < n; i++){
			cout << '\n';
		}
		return 0;
	}
	ans.resize(n);
	for (int i = 0; i < n; i++){
		ans[i].assign(m, 0);
	}
	int u, v;
	for (int i = 0; i < m; i++){
		cin >> u >> v;
		ans[u-1][i] = 1;
		ans[v-1][i] = 1;
	}

	for (int i = 0; i < n; i++){
		for (int j = 0; j < m - 1; j++){
			cout << ans[i][j] << ' ';
		}
		cout << ans[i][m-1] << '\n';
	}

	return 0;
}