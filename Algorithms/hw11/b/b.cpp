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

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("bfsrev.in", "r", stdin);
	freopen("bfsrev.out", "w", stdout);

	int n, m, s;
	vector <int> d, used; 
	vector < vector <int> > g;
	cin >> n >> s >> m;
	s--;
	d.assign(n, -1);
	d[s] = 0;
	used.assign(n, 0);
	g.resize(n);
	int a, b;
	for (int i = 0; i < m; i++){
		cin >> a >> b;
		g[b - 1].pb(a - 1);
	}
	
	queue <int> q;
	q.push(s);
	while (!q.empty()){
		int v = q.front();
		q.pop();
		for (int i = 0; i < g[v].size(); i++){
			int u = g[v][i];
			if (d[u] == -1){
				d[u] = d[v] + 1;
				q.push(u);
			}
		}
	}

	for (int i = 0; i < n; i++){
		cout << d[i] << ' ';
	}
	cout << '\n';

	return 0;
}