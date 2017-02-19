#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define pi pair <int, int>
#define forn(i, n) for(int i = 0; i < (int)(n); i++)

typedef long long ll;

const ll INF = (unsigned long long)1<<63 - 1;
const int MAXN = 105;
const int MAXM = 1005;
const int POW = 30;

struct Ed{
	int i, c, f, cost;
	int v, to;

	Ed(int i, int c, int v, int to, int cost): i(i), c(c), f(0), v(v), to(to), cost(cost){}
};


vector<vector<int>> nums;
vector<Ed> g;
int n, m, s , t, k;
ll cost;
ll d[MAXN];
int p[MAXN];

int fblmn(){
	fill(d, d + n, INF);
	d[s] = 0ll;
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

void maxFlowminCost(){
	int v, u, j;

	int flow = 0, f;

	forn(i, k){
		if (fblmn()){
			f = 1000000000;
			for (int v = t; v != s; v = g[p[v]].v){
				int j = p[v];
				f = min(f, g[j].c - g[j].f);
			}
			for (int v = t; v != s; v = g[p[v]].v){
				int j = p[v];
				g[j].f += f;
				g[j^1].f -= f;
				cost += (ll)g[j].cost * (ll)f;
			}
		}else break;
	}

	cout << cost << endl;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("mincost.in", "r", stdin);
	freopen("mincost.out", "w", stdout);

	cin >> n >> m;
	nums.resize(n);
	s = 0; t = n - 1; k = 1000000000;
	cost = 0ll;

	int v, u, c, j = 0, cc = 0;
	forn(i, m){
		cin >> v >> u >> c >> cc; v--; u--;
		g.pb(Ed(i + 1, c, v, u, cc));
		g.pb(Ed(-1, 0, u, v, -cc));
		nums[v].pb(j);
		nums[u].pb(j + 1);
		j += 2;
	}

	maxFlowminCost();

	return 0;
}