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

void dfs(int v, int col){
	used[v] = col;
	int u;
	for (int i = 0; i < g[v].size(); i++){
		if (used[g[v][i]] == 0){
			dfs(g[v][i], col);
		}
	}
}

int main() {

	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("connect.in", "r", stdin);
	freopen("connect.out", "w", stdout);

	cin >> n >> m;
	g.resize(n);
	int u, v;
	for (int i = 0; i < m; i++){
		cin >> u >> v;
		g[u - 1].push_back(v - 1);
		g[v - 1].push_back(u - 1);
	}

	used.assign(n, 0);
	int col = 1;
	for (int i = 0; i < n; i++){
		if (used[i] == 0){
			dfs(i, col);
			col++;
		}
	}

	cout << col-1 << '\n';
	for (int i = 0; i < n; i++){
		cout << used[i] << ' ';
	}
	cout << '\n';
	

	return 0;
}