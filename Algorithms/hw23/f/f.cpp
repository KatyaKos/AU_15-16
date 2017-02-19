#include <bits/stdc++.h>

using namespace std;

#define INF 1000000005
#define mp make_pair
#define pb push_back
#define pi pair <int, int>
#define forn(i, n) for(int i = 0; i < (int)(n); i++)

typedef long long ll;

const int MAXN = 2510;
const int MAXM = 15000;
const int POW = 2;

struct Ed{
	int c, f;
	int v, to;

	Ed(int c, int v, int to): c(c), f(0), v(v), to(to){}
};

int d[MAXN];
vector<vector<int>> nums, cnums;
vector<Ed> g;
int n, m, a, b, s, t, valsum;

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

void maxFlow(){
	int v, u, j;

	//int flow = 0;

	for (int k = 1 << 2; k > 0; k >>= 1){
		while(bfs(k)){
			while(dfs (s, k)){
				//flow += k;
			}
			nums = cnums;	
		}
	}

	//cout << flow << endl;
	int ans = 0;
	forn(i, g.size()){
		if (g[i].v != s && g[i].v != t && g[i].to != t && g[i].to != s){
			//cout << g[i].v << "->" << g[i].to << ' ' << g[i].c << ' ' << g[i].f << endl;
			if (g[i].f == 1) ans ++;
		}
	}
	if (ans * 2 >= valsum) cout << "Valid" << endl;
	else cout << "Invalid" << endl;
	//cout << ans << endl;
	//cout << valsum << endl;
}

inline int add(int v, int u, int c, int id){
	g.pb(Ed(c, v, u));
	if (v == s || u == t) g.pb(Ed(0, u, v));
	else g.pb(Ed(c, u, v));
	nums[v].pb(id);
	nums[u].pb(id + 1);
	return id + 2;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("molecule.in", "r", stdin);
	freopen("molecule.out", "w", stdout);

	cin >> a >> b;
	n = a * b + 2;
	nums.resize(n);
	s = 0; t = n - 1;

	int matr[a][b];

	char ch;
	valsum = 0;
	forn(i, a){
		forn(j, b){
			cin >> ch;
			if (ch == 'H') matr[i][j] = 1;
			else if (ch == 'O') matr[i][j] = 2;
			else if (ch == 'N') matr[i][j] = 3;
			else if (ch == 'C') matr[i][j] = 4;
			else matr[i][j] = 0;
			valsum += matr[i][j];
		}
	}
	if (valsum % 2 || !valsum){
		cout << "Invalid" << endl;
		return 0;
	}

	int id = 0;
	forn(i, a){
		forn(j, b){
			int k = (i + j) % 2;
			if (!matr[i][j]) continue;
			if (k == 0) id = add(s, i * b + j + 1, matr[i][j], id);
			else id = add(i * b + j + 1, t, matr[i][j], id);
			if (i != a - 1 && matr[i + 1][j]) id = add(i * b + j + 1, (i + 1) * b + j + 1, 1, id);
			if (j != b - 1 && matr[i][j + 1]) id = add(i * b + j + 1, i * b + j + 2, 1, id);
		}
	}
	cnums.resize(n);
	cnums = nums;
	//forn(i, g.size()) cout << g[i].v << "->" << g[i].to << ' ' << g[i].c << '\n';
	maxFlow();

	return 0;
}