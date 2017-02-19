#include <bits/stdc++.h>

using namespace std;

#define INF 100000000
#define mp make_pair
#define pb push_back
#define pi pair <int, int>
#define forn(i, n) for(int i = 0; i < (int)(n); i++)

typedef long long ll;

const int MAXN = 100;
const int MAXM = 400;

int g[MAXN][MAXN], parent[MAXN], used[MAXN];
map<pi, pi> edge;
int n, m;

int bfs(int s, int t){
	memset(used, 0, sizeof(int) * n);
	queue<int> q;
	q.push(s);

	used[s] = 1;
	parent[s] = -1;
	while(!q.empty()){
		int u = q.front(); q.pop();
		forn(v, n){
			if (!used[v] && g[u][v] > 0){
				q.push(v);
				parent[v] = u;
				used[v] = 1;
			}
		}
	}

	return used[t];
}

void dfs(int v){
	used[v] = 1;
	forn(i, n){
		if (g[v][i] && !used[i]) dfs(i);
	}
}

void minCut(int s, int t){
	int v, u;

	while(bfs(s, t)){
		int flow = INF;
		for (v = t; v != s; v = parent[v]){
			u = parent[v];
			flow = min(flow, g[u][v]);
		}

		for (v = t; v != s; v = parent[v]){
			u = parent[v];
			g[u][v] -= flow;
			g[v][u] += flow;
		}
	}

	memset(used, 0, sizeof(int) * n);
	dfs(s);

	int ansc = 0;
	vector <int> ans;

	forn(i, n){
		forn(j, n){
			pi tmp = edge[mp(i, j)];
			if (used[i] && !used[j] && tmp.second){
				ansc += tmp.second;
				ans.pb(tmp.first);
			}
		}
	}

	cout << ans.size() << ' ' << ansc << endl;
	forn(i, ans.size()) cout << ans[i] << ' ';
	cout << '\n';
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("cut.in", "r", stdin);
	freopen("cut.out", "w", stdout);

	cin >> n >> m;
	forn(i, n) memset(g[i], 0, sizeof(int) * n);

	int v, u, c;
	forn(i, m){
		cin >> v >> u >> c; v--; u--;
		edge[mp(v, u)] = mp(i + 1, c);
		edge[mp(u, v)] = mp(i + 1, c);
		g[v][u] = c;
		g[u][v] = c;
	}

	minCut(0, n - 1);

	return 0;
}