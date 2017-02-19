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

vector <int> used, tin, tmin, ans;
vector < vector <int> > g;
vector < pair <int, int> > bridge;
int n, m, t;
 
void dfs(int v, int p) {
	used[v] = 1;
	tin[v] = tmin[v] = t++;
	for (int i = 0; i < g[v].size(); i++){
		int u = g[v][i];
		if (u != p){
			if (used[u] == 1){
				tmin[v] = min(tmin[v], tin[u]);
			}
			else {
				dfs(u, v);
				tmin[v] = min(tmin[v], tmin[u]);
				if (tmin[u] > tin[v]){
					bridge.push_back(make_pair(v, u));
				}
			}
		}
	}
}
 
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("bridges.in", "r", stdin);
	freopen("bridges.out", "w", stdout);

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

	for (int i = 0; i < bridge.size(); i++){
		for (int j = 0; j < mass.size(); j++){
			if (bridge[i].first == mass[j].first && bridge[i].second == mass[j].second || bridge[i].first == mass[j].second && bridge[i].second == mass[j].first){
				ans.push_back(j + 1);
				break;
			}
		}
	}
	
	sort(ans.begin(), ans.end());
	ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++){
		cout << ans[i] << ' ';
	}
	cout << '\n';

	return 0;
}