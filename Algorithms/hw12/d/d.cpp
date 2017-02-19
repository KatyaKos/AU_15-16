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
#include <map>
#include <queue>
 
#define INF -7000000000000000000
#define ll long long
#define ui unsigned int
#define mp make_pair
#define pb push_back

using namespace std;

int n, m, s;
vector < vector < pair<int,ll> > > g;
vector <ll> d;

 
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("path.in", "r", stdin);
	freopen("path.out", "w", stdout);

	cin >> n >> m >> s;
	s--;
	g.resize(n);
	int a, b; ll c;
	for (int i = 0; i < m; i++){
		cin >> a >> b >> c;
		a--; b--;
		g[a].pb(mp(b, c));
	}

	d.assign(n, -1 * INF);
	d[s] = 0;
	for (int k = 0; k < n; k++){
		for (int i = 0; i < n; i++){
			a = i;
			for (int j = 0; j < g[i].size(); j++){
				b = g[i][j].first;
				if (d[b] > d[a] + g[i][j].second && d[a] != -1 * INF){
					d[b] = max(INF, d[a] + g[i][j].second);
				}
			}
		}
	}

	for (int k = 0; k < n; k++){
		for (int i = 0; i < n; i++){
			a = i;
			for (int j = 0; j < g[i].size(); j++){
				b = g[i][j].first;
				if (d[b] > d[a] + g[i][j].second && d[a] != -1 * INF){
					d[b] = INF;
				}
			}
		}
	}

	for (int i = 0; i < n; i++){
		if (d[i] == -1 * INF) cout << '*' << '\n';
		else if (d[i] == INF) cout << '-' << '\n';
		else cout << d[i] << '\n';
	}

	return 0;
}