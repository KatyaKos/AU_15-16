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
#include <queue>
 
#define INF 1000000009
#define ll long long
#define ui unsigned int
#define mp make_pair
#define pb push_back

using namespace std;

vector < vector <int> > d;
vector < vector <int> > g;

void bfs(int s){
	queue <int> q;
	q.push(s);
	while (!q.empty()){
		int v = q.front();
		q.pop();
		for (int i = 0; i < g[v].size(); i++){
			int u = g[v][i];
			if (d[s][u] == 0){
				d[s][u] = d[s][v] + 1;
				q.push(u);
			}
		}
	}
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("sumdist.in", "r", stdin);
	freopen("sumdist.out", "w", stdout);

	int n, m;
	cin >> n >> m;
	g.resize(n);
	int a, b;
	for (int i = 0; i < m; i++){
		cin >> a >> b;
		g[b - 1].pb(a - 1);
		g[a - 1].pb(b - 1);
	}

	d.resize(n);
	for (int i = 0; i < n; i++){
		d[i].assign(n, 0);
	}	

	for (int i = 0; i < n; i++){
		bfs(i);
	}

	int ans = 0;
	for (int i = 0; i < n; i++){
		for (int j = i + 1; j < n; j++){
			ans += d[i][j];
		}
	}

	cout << ans << '\n';

	return 0;
}