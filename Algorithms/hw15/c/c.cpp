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
 
#define INF 1500000000
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
vector <unordered_map<int, int> > s;
vector <vector<pair <int, pi> > > st;

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

void distance(int v, int par, int root, int dist){
	s[root][v] = min(INF - 1, dist);
	int u;
	for (int i = 0; i < g[v].size(); i++){
		u = g[v][i].first;
		if (d[u] == -1 && u != par){
			distance(u, v, root, min(dist + g[v][i].second, INF));
		}
	}
}

void decompose(int root, int parent, int level){
	nn = 0;
	int centr = find_centroid(root, -1);
	distance(centr, -1, centr, 0);
	//cout << centr << '\n';
	p[centr] = parent;
	d[centr] = level;
	int v;

	for (int i = 0; i < g[centr].size(); i++){
		v = g[centr][i].first;
		if (d[v] == -1){
			decompose(v, centr, level + 1);
		}
	}
}


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("lwdb.in", "r", stdin);
	//freopen("lwdb.out", "w", stdout);

	cin >> n;
	g.resize(n);
	p.resize(n); d.assign(n, -1); tsize.resize(n); tneigh.resize(n); st.resize(n); s.resize(n);
	int v, w, u;
	st[0].pb(mp(-INF, mp(-1, 0)));
	for (int i = 1; i < n; i++){
		st[i].pb(mp(-INF, mp(-1, 0)));
		cin >> v >> u >> w;
		v--;u--;
		g[v].pb(mp(u, w));
		g[u].pb(mp(v, w));
	}
	decompose(0, -1, 0);


	cin >> m;
	int k, dst, col, dtmp, j, date, ans;
	for (int i = 0; i < m; i++){
		cin >> k;
		if (k == 1){
			cin >> v >> dst >> col;
			v--;
			u = v; dtmp = dst;
			while (u != -1 && dst >= s[u][v]){
				dtmp = dst - s[u][v];
				while (-st[u].back().first <= dtmp) st[u].pop_back();
				st[u].pb(mp(-dtmp, mp(i, col)));
				u = p[u];
			}
		}else{
			cin >> v;
			v--;
			u = v;
			date = -2; 
			while (u != -1){
				dst = s[u][v];
				j = lower_bound(st[u].begin(), st[u].end(), mp(-dst, mp(n, 0))) - st[u].begin();
				//cout << j << ' ' << u << ", ";
				w = st[u][j - 1].second.first;
				if (date < w){
					date = w;
					ans = st[u][j - 1].second.second;
				}
				u = p[u];
			}
			cout << ans << '\n';
		}
	}
	/*for (int i = 0; i < n; i++){
		for (int j = 0; j < st[i].size(); j++){
			cout << st[i][j].first << ", " << st[i][j].second.second << "; ";
		}
		cout << '\n';
	}

	cout << lower_bound(st[3].begin(), st[3].end(), mp(-50, mp(n, 0))) - st[3].begin() << '\n';*/

	return 0;
}