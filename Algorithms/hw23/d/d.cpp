#include <bits/stdc++.h>

using namespace std;

#define INF 1000000005
#define mp make_pair
#define pb push_back
#define pi pair <int, int>
#define forn(i, n) for(int i = 0; i < (int)(n); i++)

typedef long long ll;

const int MAXN = 100000;
const int MAXM = 100000;
const int POW = 17;

struct Ed{
	int i, c, f;
	int v, to;

	Ed(int i, int c, int v, int to): i(i), c(c), f(0), v(v), to(to){}
};

int prevv[MAXN], used[MAXN];
vector<int> nums[MAXN];
vector<int> decomp[2];
vector<Ed> g;
int n, m, st, fin;

int bfs(int s, int t){
	memset(used, 0, sizeof(int) * n);
	memset(prevv, -1, sizeof(int) * n);

	queue<int> q;
	q.push(s);

	used[s] = 1;
	while(!q.empty()){
		int v = q.front(); q.pop();
		forn(i, nums[v].size()){
			int j = nums[v][i];
			int u = g[j].to, delta = g[j].c - g[j].f;

			if (!used[u] && delta > 0){
				q.push(u);
				prevv[u] = j;
				used[u] = 1;
			}
		}
	}

	return used[t];
}

int dfs(int v, int t, int k){
	decomp[k].pb(v + 1);
	if (v == t) return 1;

	forn(i, nums[v].size()){
		int j = nums[v][i], u = g[j].to, f = g[j].f;
		if (f > 0){
			dfs(u, t, k);
			g[j].f -= 1;
			return 1;
		}
	}
	return 0;
}

void maxFlow(int s, int t){
	int v, u, j, flow = 0;

	while(bfs(s, t)){
		int flag = 0;
		for (v = t; v != s; v = g[prevv[v]].v){
			j = prevv[v];
			flag |= j % 2;
			g[j].f += 1;
			g[j ^ 1].f -= 1;
		}
		if (flag) flow -= 1;
		else flow += 1;

		if (flow == 2){
			break;
		}
	}

	int i = 0;

	while(dfs(s, t, i)){
		i++;
		if (i == 2) break;
	}
	if (i < 2){
		cout << "NO" << endl;
		return;
	}else cout << "YES" << endl;

	forn(j, 2){
		forn(y, decomp[j].size()){
			v = decomp[j][y];
			cout << v << ' ';
		}
		cout << '\n';
	}

}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("snails.in", "r", stdin);
	freopen("snails.out", "w", stdout);

	int s, t;
	cin >> n >> m >> st >> fin;

	int v, u, j = 0;
	forn(i, m){
		cin >> v >> u; v--; u--;
		if (v == u) continue;
		g.pb(Ed(i + 1, 1, v, u));
		g.pb(Ed(-1, 0, u, v));
		nums[v].pb(j);
		nums[u].pb(j + 1);
		j += 2;
	}

	maxFlow(st - 1, fin - 1);

	return 0;
}