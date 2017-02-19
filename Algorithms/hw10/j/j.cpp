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
#include <map>
 
#define INF 1000000009
#define ll long long
#define ui unsigned int
#define mp make_pair

using namespace std;

vector <int> used, mask;
vector < vector <int> > g, grev, comps;
vector <int> top, comp;
int n, m;
 
void dfs1(int v) {
	used[v] = 1;
	for (int i = 0; i < g[v].size(); i++){
		if (used[g[v][i]] == 0){
			dfs1(g[v][i]);
		}
	}
	top.push_back(v);
}
 
void dfs2(int v, int c) {
	used[v] = 1;
	mask[v] = c;
	for (int i = 0; i < grev[v].size(); i++){
		if (used[grev[v][i]] == 0)
			dfs2(grev[v][i], c);
	}
}
 
int main() {

	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("condense2.in", "r", stdin);
	freopen("condense2.out", "w", stdout);

	cin >> n >> m;
	g.resize(n);
	grev.resize(n);
	int u, v;
	for (int i = 0; i < m; i++){
		cin >> u >> v;
		g[u - 1].push_back(v - 1);
		grev[v - 1].push_back(u - 1);
	}
 
	used.assign(n, 0);
	for (int i = 0; i < n; i++){
		if (used[i] == 0){
			dfs1(i);
		}
	}

	used.clear();
	used.assign(n, 0);
	mask.resize(n);
	int c = 0;
	for (int i = 0; i < n; i++){
		int v = top[n - 1 - i];
		if (used[v] == 0){
			dfs2(v, c);
			c++;
			comp.clear();
		}
	}

	int ans = 0;
	map < pair <int, int>, int > us;

	for (int i = 0; i < n; i++){
		for (int j = 0; j < g[i].size(); j++){
			int a = mask[i];
			int b = mask[g[i][j]];
			if (a != b && us[make_pair(a, b)] == 0){
				ans++;
				us[make_pair(a, b)] = 1;
			}
		}
	}


	cout << ans << '\n';

	return 0;
}