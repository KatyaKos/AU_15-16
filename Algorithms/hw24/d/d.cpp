#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define pi pair <int, int>
#define forn(i, n) for(int i = 1; i <= (int)(n); i++)

typedef long long ll;

const ll INF = 3000000000;
const int MAXN = 105;
const int MAXM = 2005;
const int MAXK = 105;
const int POW = 30;

struct Ed{
	int i, c, f, cost;
	int v, to;

	Ed(int i, int c, int v, int to, int cost): i(i), c(c), f(0), v(v), to(to), cost(cost){}
};


vector<vector<int>> nums, pars;
vector<Ed> g;
int n, m, s, t, k;
ll cst;
int decomp[MAXK][MAXN];
ll d[MAXN];
int p[MAXN], used[MAXN], mt[MAXN];

int fblmn(){

	fill(d, d + 2 * n + 2, INF);
	d[s] = 0ll;

	for (;;){
		bool any = false;
		for (int j = 0; j < g.size(); j++){
			Ed edg = g[j];
			if (edg.c - edg.f > 0 && d[edg.v] < INF){
				if (d[edg.to] > d[edg.v] + (ll)edg.cost) {
					//cout << edg.v << "->" << edg.to << ' ' << edg.c << "->" << edg.f << endl;
					d[edg.to] = d[edg.v] + (ll)edg.cost;
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


int kuhn(int v){
	used[v] = 1;
	for (int i = 0; i < pars[v].size(); i++){
		int to = pars[v][i];
		if (mt[to] == -1 || (!used[mt[to]] && kuhn(mt[to]))){
			mt[to] = v;
			//cout << v << "->" << to << endl;
			return 1;
		}
	}
	return 0;
}


void maxFlowminCost(){
	int v, u, j;

	int f;

	forn(step, k){
		forn(i, n){
			fblmn();
			for (int v = t; v != s; v = g[p[v]].v){
				int j = p[v];
				g[j].f += 1;
				g[j^1].f -= 1;
			}
		}
	}

	cst = 0ll;
	for (int i = 0; i < g.size(); i++){
		if (g[i].v != s && g[i].to != t && g[i].f == 1){
			pars[g[i].to - n].pb(g[i].v);
			cst += g[i].cost;
		}
	}


	//for (int i = 0; i < g.size(); i++) cout << g[i].v << "->" << g[i].to << ' ' << g[i].c << "->" << g[i].f << endl;

	cout << cst << endl;
	fill(used, used + 2 * n + 2, 0);

	forn(j, k){
		fill(mt, mt + 2 * n + 2, -1);
		forn(i, n){
			if (kuhn(i)){
				fill(used, used + 2 * n + 2, 0);
			}
		}
		forn(i, n){
			int to = mt[i];
			cout << to << ' ';
			for (int ii = 0; ii < pars[to].size(); ii++){
				if (pars[to][ii] == i) pars[to].erase(pars[to].begin() + ii);
			}
		}
		cout << endl;
	}

}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("multiassignment.in", "r", stdin);
	freopen("multiassignment.out", "w", stdout);

	cin >> n >> k;
	nums.resize(2 * n + 2);
	pars.resize(2 * n + 2);
	s = 0; t = 2 * n + 1;

	int c, j = 0;
	forn(u, n){
		g.pb(Ed(-1, k, s, u, 0));
		g.pb(Ed(-1, 0, u, s, 0));
		nums[s].pb(j);
		nums[u].pb(j + 1);
		j += 2;
		g.pb(Ed(-1, k, n + u, t, 0));
		g.pb(Ed(-1, 0, t, n + u, 0));
		nums[n + u].pb(j);
		nums[t].pb(j + 1);
		j += 2;
		
		forn(v, n){
			cin >> c;
			g.pb(Ed(-1, 1, u, n + v, c));
			g.pb(Ed(-1, 0, n + v, u, -c));
			nums[n + v].pb(j + 1);
			nums[u].pb(j);
			j += 2;
		}
	}

	maxFlowminCost();

	return 0;
}