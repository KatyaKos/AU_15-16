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
#include <string.h>
#include <bitset>
 
#define INF 10000000
#define ll long long
#define ui unsigned int
#define mp make_pair
#define pb push_back
#define pi pair <int, int>

using namespace std;

#include <cassert>


const int MAX_MEM = 1e9;
int mpos = 0;
char mem[MAX_MEM];
inline void * operator new ( size_t n ) {
  char *res = mem + mpos;
  mpos += n;
  assert(mpos <= MAX_MEM);
  return (void *)res;
}
inline void operator delete ( void * ) { }

inline void * operator new [] ( size_t ) { assert(0); }
inline void operator delete [] ( void * ) { assert(0); }

int n, m, nn;
vector <vector <pi> > g;
vector <int> p, d, tsize, tneigh;
vector <vector<int> > mine;

int find_centroid(int v, int par){
	int u, tmp;
	tsize[v] = 1;
	nn++;

	for (int i = 0; i < g[v].size(); i++){
		u = g[v][i].first;
		if (d[u] == -1 && u != par){
			tneigh[u] = find_centroid(u, v);
			tsize[v] += tsize[u];
		}
	}
	for (int i = 0; i < g[v].size(); i++){
		u = g[v][i].first;
		if (d[u] == -1 && u != par){
			if (tsize[u] * 2 > nn){
				return tneigh[u];
			}
		}
	}
	return v;
}

void min_edge(int dep, int v, int minn, int par){
	mine[v][dep] = minn;
	for (int i = 0; i < g[v].size(); i++){
		int u = g[v][i].first;
		if (d[u] == -1 && u != par){
			min_edge(dep, u, min(minn, g[v][i].second), v);
		}
	}
}

void decompose(int root, int parent, int level){
	nn = 0;
	int centr = find_centroid(root, -1);
	//cout << centr << '\n';
	p[centr] = parent;
	d[centr] = level;
	int v;
	for (int i = 0; i < g[centr].size(); i++){
		v = g[centr][i].first;
		if (d[v] == -1){
			min_edge(level, v, g[centr][i].second, centr);
			decompose(v, centr, level + 1);
		}
	}
}


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("minonpath.in", "r", stdin);
	freopen("minonpath.out", "w", stdout);

	cin >> n;
	g.resize(n);
	p.resize(n); d.assign(n, -1); tsize.resize(n); tneigh.resize(n); mine.resize(n);
	int v, w;
	mine[0].assign(30, INF);
	for (int i = 1; i < n; i++){
		mine[i].assign(30, INF);
		cin >> v >> w;
		g[v - 1].pb(mp(i, w));
		g[i].pb(mp(v - 1, w));
	}
	decompose(0, -1, 0);
	/*for (int i = 0; i < n; i++){
		cout << p[i] << ' ';
	}
	cout << '\n';
	for (int i = 0; i < n; i++){
		cout << d[i] << ' ';
	}
	cout << '\n';
	for (int i = 0; i < n; i++){
		for (int j = 0; j < mine[i].size(); j++){
			cout << mine[i][j] << "; ";
		}
		cout << '\n';
	}*/

	cin >> m;
	int a, b, lca, lcb, lc;
	for (int i = 0; i < m; i++){
		cin >> a >> b;
		a--; b--;
		if (d[a] > d[b]) swap(a, b);
		lcb = b;
		lca = a;
		while (d[lca] < d[lcb]){
			lcb = p[lcb];
		}
		while (lca != lcb){
			lca = p[lca];
			lcb = p[lcb];
		}
		lc = lca;
		cout << min(mine[a][d[lc]], mine[b][d[lc]]) << '\n';
	}

	return 0;
}