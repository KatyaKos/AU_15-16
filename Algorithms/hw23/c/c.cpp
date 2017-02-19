#include <bits/stdc++.h>

using namespace std;

#define INF 1000000005
#define mp make_pair
#define pb push_back
#define pi pair <int, int>
#define forn(i, n) for(int i = 0; i < (int)(n); i++)

typedef long long ll;

const int MAXN = 100;
const int MAXM = 5000;
const int POW = 14;

struct Ed{
	int i, c, f;
	int v, to;

	Ed(int i, int c, int v, int to): i(i), c(c), f(0), v(v), to(to){}
};

int prevv[MAXN], used[MAXN];
vector<int> nums[MAXN];
vector<Ed> g;
int n, m;

int bfs(){
	memset(used, 0, sizeof(int) * n);
	memset(prevv, -1, sizeof(int) * n);

	int s = 0, t = n - 1;

	queue<int> q;
	q.push(s);
	int flow = INF;

	used[s] = 1;
	while(!q.empty()){
		int v = q.front(); q.pop();
		forn(i, nums[v].size()){
			int j = nums[v][i];
			int u = g[j].to, delta = g[j].c - g[j].f;

			if (!used[u] && delta > 0){
				flow = min(delta, flow);
				q.push(u);
				prevv[u] = j;
				used[u] = 1;
			}
		}
	}

	if (used[t]) return flow;
	else return 0;
}

int dfs(int v, int flow){
	if (v == n - 1) return flow;

	forn(i, nums[v].size()){
		int j = nums[v][i], u = g[j].to, f = g[j].f;
		if (f > 0){
			f = dfs(u, min(flow, f));
			g[j].f -= f;
			return f;
		}
	}
	return 0;
}

void maxFlow(){
	int s = 0, t = n - 1;
	int v, u, j, f;

	while((f = bfs())){
		for (v = t; v != s; v = g[prevv[v]].v){
			j = prevv[v];
			g[j].f += f;
			g[j ^ 1].f -= f;
		}
	}

	vector<int> fl;
	for(int i = 0; i < 2 * m; i+= 2){
		fl.pb(g[i].f);
	}

	int ans = 0, tmp;
	while((tmp = dfs(0, INF))){
		ans += tmp;
	}

	cout << ans << '\n';
	forn(i, m) cout << fl[i] << '\n';

}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("flow.in", "r", stdin);
	freopen("flow.out", "w", stdout);

	cin >> n >> m;

	int v, u, c, j = 0;
	forn(i, m){
		cin >> v >> u >> c; v--; u--;
		g.pb(Ed(i + 1, c, v, u));
		g.pb(Ed(-1, c, u, v));
		nums[v].pb(j);
		nums[u].pb(j + 1);
		j += 2;
	}

	maxFlow();

	return 0;
}