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
int flag, pr;

void dfs(int v, int pr){
	used[v] = 1;

	int u;
	for (int i = 0; i < g[v].size(); i++){
		u = g[v][i];
		if (used[u] == 0){
			dfs(u, v);
		} else if (used[u] == 1 && u != pr){
			flag = 1;
		}
	}
	used[v] = 2;
}

int main() {

	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);

	cin >> n >> m;
	g.resize(n);
	int u, v;
	for (int i = 0; i < m; i++){
		cin >> u >> v;
		g[u - 1].push_back(v - 1);
		g[v - 1].push_back(u - 1);
	}

	used.assign(n, 0);
	flag = 0;
	dfs(0, -1);

	for (int i = 0; i < n; i++){
		if (used[i] != 2){
			flag = 1;
		}
	}

	if (flag == 0){
		cout << "YES" << '\n';
	} else{
		cout << "NO" << '\n';
	}

	return 0;
}