#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define pi pair <int, int>
#define forn(i, n) for(int i = 0; i < (int)(n); i++)

typedef long long ll;

const ll INF = 2000000009;
const int MAXN = 205;
const int MAXM = 2005;
const int MAXK = 105;
const int POW = 30;

struct Ed{
	int i, c, f, cost;
	int v, to;

	Ed(int i, int c, int v, int to, int cost): i(i), c(c), f(0), v(v), to(to), cost(cost){}
};


vector<vector<int>> nums;
vector<Ed> g;
int n, m, s , t, k, cost;
vector<int> decomp[MAXK];
int d[MAXN], p[MAXN];

int fblmn(){
	fill(d, d + n, INF);
	d[s] = 0;
	//memset(p, -1, sizeof(int) * n);
	for (;;) {
		bool any = false;
		forn(j, g.size()){
			Ed edg = g[j];
			if (edg.c - edg.f && d[edg.v] < INF){
				if (d[edg.to] > d[edg.v] + edg.cost) {
					d[edg.to] = d[edg.v] + edg.cost;
					p[edg.to] = j;
					any = true;
				}
			}
		}
		if (!any)  break;
	}

	if (d[t] != INF) return 1;
	else return 0;

}

int dfs(int v, int num){
	if (v == t) return 1;

	forn(i, nums[v].size()){
		int j = nums[v][i], u = g[j].to, f = g[j].f;
		if (f > 0){
			decomp[num].pb(g[j].i);
			dfs(u, num);
			g[j].f -= 1;
			cost += g[j].cost;
			return 1;
		}
	}
	return 0;
}

void maxFlowminCost(){
	int v, u, j;

	int f, flow = 0;
	forn(i, k){
		if (fblmn()){
			flow++;
			for (int v = t; v != s; v = g[p[v]].v){
				int j = p[v];
				g[j].f += 1;
				g[j^1].f -= 1;
			}
		}else break;
	}
	
	if (flow < k){
		cout << -1 << endl;
		return;
	}


	int i = 0; cost = 0;

	while(dfs(0, i)){
		i++;
	}

	cout.precision(5);
	cout << fixed << cost * 1.0 / k << endl;
	forn(j, i){
		cout << decomp[j].size() << ' ';
		forn(y, decomp[j].size()){
			cout << decomp[j][y] << ' ';
		}
		cout << endl;
	}

}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("brides.in", "r", stdin);
	freopen("brides.out", "w", stdout);

	cin >> n >> m >> k;
	nums.resize(n);
	s = 0; t = n - 1;

	int v, u, c, j = 0;
	forn(i, m){
		cin >> v >> u >> c; v--; u--;
		g.pb(Ed(i + 1, 1, v, u, c));
		g.pb(Ed(-1, 0, u, v, -c));
		g.pb(Ed(i + 1, 1, u, v, c));
		g.pb(Ed(-1, 0, v, u, -c));
		nums[v].pb(j);
		nums[u].pb(j + 1);
		nums[u].pb(j + 2);
		nums[v].pb(j + 3);
		j += 4;
	}

	maxFlowminCost();

	return 0;
}