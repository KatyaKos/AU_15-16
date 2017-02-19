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

vector <int> used, tin, tmin, ans, pt;
vector < vector <int> > g;
int n, m, t;
 
void dfs(int v, int p) {
	used[v] = 1;
	tin[v] = tmin[v] = t++;
	int flag = 0;
	for (int i = 0; i < g[v].size(); i++){
		int u = g[v][i];
		if (u != p){
			if (used[u] == 1){
				tmin[v] = min(tmin[v], tin[u]);
			}
			else {
				flag++;
				dfs(u, v);
				tmin[v] = min(tmin[v], tmin[u]);
				if (tmin[u] >= tin[v] && p != -1){
					pt.push_back(v);
				}
			}
		}
	}
	if (p == -1 && flag > 1){
		pt.push_back(v);
	}
}
 
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("points.in", "r", stdin);
	freopen("points.out", "w", stdout);

	cin >> n >> m;
	g.resize(n);
	int u, v;
	vector < pair <int, int> > mass; 
	for (int i = 0; i < m; i++){
		cin >> u >> v;
		mass.push_back(make_pair(u - 1, v - 1));
		g[u - 1].push_back(v - 1);
		g[v - 1].push_back(u - 1);
	}

	used.assign(n, 0);
	tin.resize(n);
	tmin.resize(n);

	t = 0;
	for (int i = 0; i < n; i++){
		if (used[i] == 0){
			dfs(i, -1);
		}
	}
	
	sort(pt.begin(), pt.end());
	pt.resize(unique(pt.begin(), pt.end()) - pt.begin());
	cout << pt.size() << '\n';
	for (int i = 0; i < pt.size(); i++){
		cout << pt[i] + 1 << '\n';
	}

	return 0;
}