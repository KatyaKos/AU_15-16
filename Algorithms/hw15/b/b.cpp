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
#include <unordered_map>
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
vector <vector <int> > g;
vector <int> p, d, tsize, tneigh, col;
vector <unordered_map<int, int> > cd, s;

int find_centroid(int v, int par){
	int u, tmp;
	tsize[v] = 1;
	nn++;

	for (int i = 0; i < g[v].size(); i++){
		u = g[v][i];
		if (d[u] == -1 && u != par){
			tneigh[u] = find_centroid(u, v);
			tsize[v] += tsize[u];
		}
	}
	for (int i = 0; i < g[v].size(); i++){
		u = g[v][i];
		if (d[u] == -1 && u != par){
			if (tsize[u] * 2 > nn){
				return tneigh[u];
			}
		}
	}
	return v;
}

void colour(int v, int par, int root, int dist){
	int cl = col[v];
	if (cd[root][cl] != 0) cd[root][cl] = min(cd[root][cl], dist + 1);
	else cd[root][cl] = dist + 1;
	s[root][v] = dist;
	int u;
	for (int i = 0; i < g[v].size(); i++){
		u = g[v][i];
		if (d[u] == -1 && u != par){
			colour(u, v, root, dist + 1);
		}
	}
}

void decompose(int root, int parent, int level){
	nn = 0;
	int centr = find_centroid(root, -1);
	colour(centr, -1, centr, 0);
	//cout << centr << '\n';
	p[centr] = parent;
	d[centr] = level;
	int v;

	for (int i = 0; i < g[centr].size(); i++){
		v = g[centr][i];
		if (d[v] == -1){
			decompose(v, centr, level + 1);
		}
	}
}


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("centroid.in", "r", stdin);
	freopen("centroid.out", "w", stdout);

	cin >> n;
	g.resize(n);
	p.resize(n); d.assign(n, -1); tsize.resize(n); tneigh.resize(n); col.resize(n); s.resize(n); cd.resize(n);
	int v, w;
	for (int i = 1; i < n; i++){
		cin >> v;
		g[v].pb(i);
		g[i].pb(v);
	}
	for (int i = 0;i < n; i++){
		cin >> col[i];
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
		for (auto j = s[i].begin(); j != s[i].end(); j++){
			cout << (*j).first << ", " << (*j).second << "; ";
		}
		cout << '\n';
	}
	for (int i = 0; i < n; i++){
		for (auto j = cd[i].begin(); j != cd[i].end(); j++){
			cout << (*j).first << ", " << (*j).second << "; ";
		}
		cout << '\n';
	}*/
	cin >> m;
	int c, u, mpath;
	for (int i = 0; i < m; i++){
		mpath = INF;
		cin >> u >> c;
		v = u;
		while (v != -1){
			if (cd[v][c] == 0){
				v = p[v];
			}else{
				mpath = min(mpath, s[v][u] + cd[v][c] - 1);
				v = p[v];
			}
		}
		if (mpath == INF) cout << -1 << ' ';
		else cout << mpath << ' ';
	}
	cout << '\n';

	return 0;
}