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
#include <deque>
#include <map>
 
#define INF 1000000009
#define ll long long
#define ui unsigned int
#define mp make_pair
#define pb push_back

using namespace std;

vector <int> d, p, own;
vector < vector <int> > g;
map < pair<int, int>, int> way;

void bfs(int s){
	deque <int> q;
	q.push_front(s);
	while (!q.empty()){
		int v = q.front();
		q.pop_front();
		for (int i = 0; i < g[v].size(); i++){
			int u = g[v][i];
			if (d[u] == -1){
				d[u] = d[v] + 1;
				p[u] = v;
				if (way[mp(v, u)] == 0){
					q.push_front(u);
				}else{
					q.push_back(u);
				}
			}
		}
	}
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("island.in", "r", stdin);
	freopen("island.out", "w", stdout);

	int n, m;
	cin >> n >> m;
	own.resize(n);
	g.resize(n);
	d.assign(n, -1);
	p.resize(n);
	p[0] = -1;
	d[0] = 0;
	for (int i = 0; i < n; i++){
		cin >> own[i];
	}
	for (int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		a--; b--;
		if (own[a] != own[b]){
			g[a].pb(b); way[mp(a, b)] = 1;
			g[b].pb(a); way[mp(b, a)] = 1;
		}else{
			g[a].pb(b);
			g[b].pb(a);
		}
	}

	bfs(0);
	
	if (d[n - 1] == -1){
		cout << "impossible" << '\n';
	}else{
		vector <int> ans;
		int cost = 0, i = n - 1;
		while (i != 0){
			ans.pb(i);
			cost += way[mp(i, p[i])];
			i = p[i];
		}
		ans.pb(0);
		cout << cost << ' ' << ans.size() << '\n';
		for (int j = ans.size() - 1; j >= 0; j--){
			cout << ans[j] + 1 << ' ';
		}
		cout << '\n';
	}

	return 0;
}