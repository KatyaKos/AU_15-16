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

vector <int> used;
vector < vector <int> > g;
int n, m;

void dfs(int v){
	used[v] = 1;
	int u;
	for (int i = 0; i < g[v].size(); i++){
		if (used[g[v][i]] == 0){
			dfs(g[v][i]);
		}
	}
}

int main() {

	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("edges.in", "r", stdin);
	freopen("edges.out", "w", stdout);

	cin >> n >> m;
	g.resize(n);
	int u, v;
	for (int i = 0; i < m; i++){
		cin >> u >> v;
		g[u - 1].push_back(v - 1);
		g[v - 1].push_back(u - 1);
	}

	used.assign(n, 0);
	dfs(0);
	int ans = 0;
	vector <int> mass;
	for (int i = 0; i < n; i++){
		if (used[i] == 0){
			mass.push_back(i + 1);
			ans++;
			dfs(i);
		}
	}

	cout << ans << '\n';
	for (int i = 0; i < mass.size(); i++){
		cout << "1 " << mass[i] << '\n';
	}
	

	return 0;
}