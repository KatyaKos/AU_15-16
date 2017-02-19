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
#include <queue>
#include <map>
 
#define INF 20000009
#define ll long long
#define ui unsigned int
#define mp make_pair
#define pb push_back

using namespace std;

vector <int> used;
priority_queue < pair<int, int> > q;
vector <int> d; 
vector < vector < pair<int, int > > > g;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("distance.in", "r", stdin);
	freopen("distance.out", "w", stdout);

	int n, m, s, f;
	cin >> n >> m >> s >> f;
	s--; f--;
	g.resize(n);
	q.push(mp(0, s));
	used.assign(n, 0);
	d.assign(n, INF);
	d[s] = 0;

	for (int i = 0; i < m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		g[a].pb(mp(b, c));
		g[b].pb(mp(a, c));
	}

	int ans = INF;
	while (!q.empty()){
		pair <int, int> u = q.top();
		q.pop();
		while (used[u.second] == 1){
			u = q.top();
			q.pop();
		}
		int v = u.second;
		if (v == f){
			ans = u.first;
			break;
		}
		used[v] = 1;
		for (int j = 0; j < g[v].size(); j++){
			int to = g[v][j].first, l = g[v][j].second;
			if (d[to] > d[v] + l){
				d[to] = d[v] + l;
				q.push(mp(u.first - l, to));
			}
		}

	}

	if (ans == INF){
		cout << -1 << '\n';
		return 0;
	}
	cout << -1 * ans << '\n';

	return 0;
}