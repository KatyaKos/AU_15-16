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
vector < vector <int> > g, gn;
int n, m, t, maxc;
 
void dfs(int v, int p) {
	used[v] = 1;
	//st.push(v);
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
					if (g[v][i + 1] != u){
						//cout << v << ' ' << u << '\n';
						//paint(u);
						maxc++;

					}else{
						gn[v].push_back(u);
						gn[u].push_back(v);
					}
				}else{
					gn[v].push_back(u);
					gn[u].push_back(v);
				}
			}
		}
	}
	if (p == -1) maxc++;
	/*if (p == -1 && st.size() != 0){
		paint(v);
	}*/
}

void go(int v){
	used[v] = 1;
	ans.push_back(v + 1);
	int u;
	for (int i = 0; i < gn[v].size(); i++){
		if (used[gn[v][i]] == 0){
			go(gn[v][i]);
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
	gn.resize(n);
	int u, v;
	vector < pair <int, int> > mass; 
	for (int i = 0; i < m; i++){
		cin >> u >> v;
		mass.push_back(make_pair(u - 1, v - 1));
		g[u - 1].push_back(v - 1);
		g[v - 1].push_back(u - 1);
	}

	for (int i = 0; i < n; i++){
		sort(g[i].begin(), g[i].end());
	}
	used.assign(n, 0);
	tin.resize(n);
	tmin.resize(n);
	col.resize(n);

	t = 0;
	maxc = 0;
	for (int i = 0; i < n; i++){
		if (used[i] == 0){
			dfs(i, -1);
		}
	}

	cout << maxc << '\n';
	used.clear(); used.assign(n, 0);
	for (int i = 0; i < n; i++){
		if (used[i] == 0){
			go(i);
			sort(ans.begin(), ans.end());
			for (int j = 0; j < ans.size(); j++){
				cout << ans[j] << ' ';
			}
			cout << '\n';
			ans.clear();
		}
	}

	return 0;
}