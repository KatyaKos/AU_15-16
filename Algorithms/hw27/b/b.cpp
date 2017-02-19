#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define pi pair <int, int>
#define forn(i, n) for(int i = 0; i < (int)(n); i++)

typedef long long ll;

const int INF = 1000000000;
const int MAXN = 300005;
const int MAXM = 300005;

int n, m;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("retro.in", "r", stdin);
	freopen("retro.out", "w", stdout);

	int win[MAXN], lose[MAXN], count[MAXN], deg[MAXN], used[MAXN];
	fill(win, win + MAXN, 0); fill(lose, lose + MAXN, 0);
	fill(count, count + MAXN, 0); fill(deg, deg + MAXN, 0);
	fill(used, used + MAXN, 0);
	int c = 1;

	while (cin >> n >> m){

		vector<int> g[n];
		fill(deg, deg + n, 0);

		int a, b;
		forn(i, m){
			cin >> a >> b;
			g[b - 1].pb(a - 1);
			deg[a - 1]++;
		}

		queue<int> qu;
		forn(i, n){
			count[i] = 0;
			if (!deg[i]){
				lose[i] = c;
				qu.push(i);
			}
		}

		while (!qu.empty()){
			int v = qu.front(); qu.pop();
			if (used[v] == c) continue;
			used[v] = c;
			if (lose[v] == c){
				forn(i, g[v].size()){
					int u = g[v][i];
					win[u] = c;
					qu.push(u);
				}
			}else if (win[v] == c){
				forn(i, g[v].size()){
					int u = g[v][i];
					count[u]++;
					if (count[u] == deg[u]){
						lose[u] = c;
						qu.push(u);
					}
				}
			}
		}

		forn(i, n){
			if (win[i] == c) cout << "FIRST\n";
			else if (lose[i] == c) cout << "SECOND\n";
			else cout << "DRAW\n";
		}
		cout << '\n';

		c++;
	}
	
	return 0;
}