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

vector<int> g[MAXN];
int gg[MAXN][MAXN], match[MAXN], f[MAXN], used[MAXN], used1[MAXN], used2[MAXN], bad[MAXN];
int iter;


int dfs(int v){
	used[v] = iter;
	for (int to : g[v])
		if (match[to] == -1 || (used[match[to]] != iter && dfs(match[to]))){
			match[to] = v, f[v] = to;
			return 1;
		}
	return 0;
}
 
void dfs2(int v){
	used1[v] = 1;
	for (int to : g[v])
		if (!used2[to]){
			used2[to] = 1;
			if (match[to] != -1 && !used1[match[to]])
				dfs2(match[to]);                
		}
}


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("hobbits.in", "r", stdin);
	freopen("hobbits.out", "w", stdout);

	int n;
	cin >> n;
	forn(i, n)
		forn(j, n)
			cin >> gg[i][j];

	forn(u, n)
		forn(i, n)
			forn(j, n)
				gg[i][j] |= gg[i][u] & gg[u][j];

	forn(i, n)
		forn(j, n)
			if (gg[i][j])
				g[i].push_back(j);
 
	fill(match, match + n, -1);
	fill(f, f + n, -1);

	for (int run = 1; run; ){
		run = 0;
		iter++;
		forn(i, n)
			if (f[i] == -1 && dfs(i))
				run = 1;
	}
   
	forn(i, n)
		if (f[i] == -1)
			dfs2(i);
	forn(i, n)
		if (!used1[i])
			bad[i] = 1;

	forn(i, n)
		if (used2[i])
			bad[i] = 1;
 
	int cnt = 0;
	forn(i, n)
		if (!bad[i])
			cnt++;

	cout << cnt << '\n';
	forn(i, n)
		if (!bad[i]){
			cout << i + 1 << ' ';
		}
	cout << '\n';

	return 0;
}