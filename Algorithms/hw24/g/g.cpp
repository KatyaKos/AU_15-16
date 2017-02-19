#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define pi pair <int, int>
#define forn(i, n) for(int i = 0; i < (int)(n); i++)

typedef long long ll;

const int INF = 100005;
const int MAXN = 205;
const int MAXM = 42050;
const int POW = 17;

struct Ed{
	int i, c, f, l;
	int v, to;

	Ed(int i, int v, int to, int c, int l): i(i), c(c), l(l), f(0), v(v), to(to){}
};

int d[MAXN];
vector<vector<int>> numsl, cnumsl, numsc, cnumsc;
vector<Ed> map, gl, gc;
int n, m, s, t;

bool bfs(int k){
	int qh = 0, qt = 0;
	int q[n];

	q[qt++] = s;
	memset (d, -1, n * sizeof(int));
	d[s] = 0;
	while (qh < qt && d[t] == -1) {
		int v = q[qh++];
		forn(i, nums[v].size()) {
			int id = nums[v][i], to = g[id].to;
			if (d[to] == -1 && g[id].c - g[id].f >= k) {
				q[qt++] = to;
				d[to] = d[v] + 1;
			}
		}
	}
	return d[t] != -1;
}

int dfs (int v, int k){
	if (v == t)  return 1;
	forn(i, nums[v].size()){
		int id = nums[v][i], to = g[id].to;
		if (d[to] != d[v] + 1){
			swap(nums[v][i], nums[v].back());
			nums[v].pop_back();
			i--;
			continue;
		}
		if (g[id].c - g[id].f >= k){
			if(dfs(to, k)){
				g[id].f += k;
				g[id ^ 1].f -= k;
				return 1;
			}else{
				swap(nums[v][i], nums[v].back());
				nums[v].pop_back();
				i--;
			}
		}
	}
	return 0;
}


void maxFlowl(){
	int v, u, j;

	for (int k = 1 << POW; k > 0; k >>= 1){
		while(bfs(k)){
			while(dfs (s, k)){
			}
			numsl = cnumsl;			
		}
	}
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("cooling.in", "r", stdin);
	//freopen("cooling.out", "w", stdout);

	cin >> n >> m;
	numsl.resize(n + 2);
	numsc.resize(n + 2);
	s = 0; t = n + 1;

	int v, u, c, l, j = 0, jj = 0;
	forn(i, m){
		cin >> v >> u >> l >> c;
		map.pb(Ed(i + 1, v, u, c, l));
		gl.pb(Ed(j, v, u, l, 0));
		gl.pb(Ed(j, u, v, -l, 0));
		gc.pb(Ed(j, v, u, c - l, 0));
		gc.pb(Ed(j, u, v, -c + l, 0));
		numsl[v].pb(jj);
		numsl[u].pb(jj + 1);
		numsc[v].pb(jj);
		numsc[u].pb(jj + 1);
		jj += 2; j++;
	}

	cnumsl.resize(n + 2);
	cnumsl = numsl;
	cnumsc.resize(n + 2);
	cnumsc = numsc;

	maxFlowl();

	return 0;
}