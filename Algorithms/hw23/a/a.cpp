#include <bits/stdc++.h>

using namespace std;

#define INF 1000000005
#define mp make_pair
#define pb push_back
#define pi pair <int, int>
#define forn(i, n) for(int i = 0; i < (int)(n); i++)

typedef long long ll;

const int MAXN = 500;
const int MAXM = 10000;
const int POW = 30;

struct Ed{
	int i, c, f;
	int v, to;

	Ed(int i, int c, int v, int to): i(i), c(c), f(0), v(v), to(to){}
};

int prevv[MAXN], used[MAXN];
vector<int> nums[MAXN];
vector<int> decomp[MAXM];
vector<Ed> g;
int n, m;

int bfs(int k){
	memset(used, 0, sizeof(int) * n);
	memset(prevv, -1, sizeof(int) * n);

	int s = 0, t = n - 1;

	queue<int> q;
	q.push(s);

	used[s] = 1;
	while(!q.empty()){
		int v = q.front(); q.pop();
		forn(i, nums[v].size()){
			int j = nums[v][i];
			int u = g[j].to, delta = g[j].c - g[j].f;

			if (!used[u] && delta >= k){
				q.push(u);
				prevv[u] = j;
				used[u] = 1;
			}
		}
	}

	return used[t];
}

int dfs(int v, int k, int flow){
	if (v == n - 1) return flow;

	forn(i, nums[v].size()){
		int j = nums[v][i], u = g[j].to, f = g[j].f;
		if (f > 0){
			decomp[k].pb(g[j].i);
			f = dfs(u, k, min(flow, f));
			g[j].f -= f;
			return f;
		}
	}
	return 0;
}

void maxFlow(){
	int s = 0, t = n - 1;
	int v, u, j;

	for (int k = 1 << POW; k > 0; k >>= 1){
		while(bfs(k)){
			for (v = t; v != s; v = g[prevv[v]].v){
				j = prevv[v];
				g[j].f += k;
				g[j ^ 1].f -= k;
			}
		}
	}

	int i = 0, ans[MAXM];

	while((ans[i] = dfs(0, i, INF))){
		i++;
	}

	cout << i << '\n';
	forn(j, i){
		cout << ans[j] << ' ' << decomp[j].size() << ' ';
		forn(y, decomp[j].size()){
			cout << decomp[j][y] << ' ';
		}
		cout << '\n';
	}

}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("decomposition.in", "r", stdin);
	freopen("decomposition.out", "w", stdout);

	cin >> n >> m;

	int v, u, c, j = 0;
	forn(i, m){
		cin >> v >> u >> c; v--; u--;
		g.pb(Ed(i + 1, c, v, u));
		g.pb(Ed(-1, 0, u, v));
		nums[v].pb(j);
		nums[u].pb(j + 1);
		j += 2;
	}

	maxFlow();

	return 0;
}