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
int flag;

void dfs(int v){
	used[v] = 1;
	int u;
	for (int i = 0; i < g[v].size(); i++){
		if (used[g[v][i]] == 0){
			dfs(g[v][i]);
		}
	}
	used[v] = 2;
	ans.push_back(v);
}

int main() {

	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("unitopsort.in", "r", stdin);
	freopen("unitopsort.out", "w", stdout);

	cin >> n >> m;
	g.resize(n);
	int u, v;
	for (int i = 0; i < m; i++){
		cin >> u >> v;
		g[u - 1].push_back(v - 1);
	}

	used.assign(n, 0);
	for (int i = 0; i < n; i++){
		if (used[i] == 0){
			dfs(i);
		}
	}
	reverse(ans.begin(), ans.end());

	for (int i = 0; i < n - 1; i++){
		flag = 0;
		for (int j = 0; j < g[ans[i]].size(); j++){
			if (g[ans[i]][j] == ans[i + 1]){
				flag = 1;
				break;
			}
		}
		if (flag == 0){
			cout << "NO" << '\n';
			return 0;
		}
	}

	cout << "YES" << '\n';
	for (int i = 0; i < n; i++){
		cout << ans[i] + 1 << ' ';
	}
	cout << '\n';
	

	return 0;
}