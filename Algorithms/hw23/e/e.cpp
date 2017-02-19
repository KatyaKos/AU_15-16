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

int prevv[MAXN], used[MAXN], d[MAXN];
vector<vector<int>> nums, cnums;
vector<Ed> g;
int n, m;

bool bfs(int k){
	int s = 0, t = n - 1;
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
	if (v == n - 1)  return 1;
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

void maxFlow(){
	int s = 0, t = n - 1;
	int v, u, j;

	ll flow = 0l;
	//for(;;){
	for (int k = 1 << POW; k > 0; k >>= 1){
		while(bfs(k)){
			while(dfs (s, k)){
				flow += k;
			}
			nums = cnums;			
		}
	}

	cout << flow << endl;
	for(int i = 0; i < 2 * m; i+= 2){
		cout << g[i].f << endl;
	}
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("flow2.in", "r", stdin);
	freopen("flow2.out", "w", stdout);

	cin >> n >> m;
	nums.resize(n);

	int v, u, c, j = 0;
	forn(i, m){
		cin >> v >> u >> c; v--; u--;
		g.pb(Ed(i + 1, c, v, u));
		g.pb(Ed(-1, 0, u, v));
		nums[v].pb(j);
		nums[u].pb(j + 1);
		j += 2;
	}
	cnums.resize(n);
	//forn(i, n) memcpy(cnums[i].begin(), nums[i].begin(), sizeof(int) * nums[i].size());
	cnums = nums;
	maxFlow();

	return 0;
}