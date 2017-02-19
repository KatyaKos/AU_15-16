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
vector <int> ans;
int n, m;
int beg, en;

int dfs(int v){
	used[v] = 1;
	int u;
	for (int i = 0; i < g[v].size(); i++){
		u = g[v][i];
		if (used[u] == 0 ){
			ans[u] = v;
			if (dfs(u) == 1) return 1;
		} else if(used[u] == 1){
			beg = u;
			en = v;
			return 1;
		}
	}
	used[v] = 2;
	return 0;
}

int main() {

	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("cycle.in", "r", stdin);
	freopen("cycle.out", "w", stdout);

	cin >> n >> m;
	g.resize(n);
	int u, v;
	for (int i = 0; i < m; i++){
		cin >> u >> v;
		g[u - 1].push_back(v - 1);
	}

	/*for (int i = 0; i < n; i++){
		for (int j = 0; j < g[i].size(); j++){
			cout << g[i][j] << ' ';
		}
		cout << '\n';
	}*/

	used.assign(n, 0);
	ans.assign(n, -1);
	beg = -1;
	for (int i = 0; i < n; i++){
		if (used[i] == 0){
			if (dfs(i) == 1){
				cout << "YES" << '\n';
				vector <int> mass;
				for (int j = en; j != beg; j = ans[j]){
					mass.push_back(j + 1);
				}
				mass.push_back(beg + 1);
				for (int j = mass.size() - 1; j >= 0; j--){
					cout << mass[j] << ' ';
				}
				cout << '\n';
				return 0;
			}
		}
	}

	cout << "NO" << '\n';
	

	return 0;
}