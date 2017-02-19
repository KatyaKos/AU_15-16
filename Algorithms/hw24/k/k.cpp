#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define pi pair <int, int>
#define forn(i, n) for(int i = 1; i <= (int)(n); i++)

typedef long long ll;

const int INF = 1000005;
const int MAXN = 105;
const int POW = 30;

int n;
int u[MAXN], v[MAXN], p[MAXN], way[MAXN];
int a[MAXN][MAXN];

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("credit.in", "r", stdin);
	freopen("credit.out", "w", stdout);

	cin >> n;
	memset(a[0], 0, sizeof(int) * (n + 1));

	forn(i, n){
		a[i][0] = 0;
		forn(j, n){
			cin >> a[i][j];
			a[i][j] *= -1;
		}
	}

	memset(u, 0, sizeof(int) * (n + 1));
	memset(v, 0, sizeof(int) * (n + 1));
	memset(way, 0, sizeof(int) * (n + 1));

	int minv[MAXN];
	bool used[MAXN];

	forn(i, n){
		p[0] = i;
		int j0 = 0;

		memset(minv, 1, sizeof(int) * (n + 1));
		memset(used, false, sizeof(int) * (n + 1));

		do{
			used[j0] = true;
			int i0 = p[j0], delta = INF, j1;

			forn(j, n){
				if (!used[j]){

					int cur = a[i0][j]-u[i0]-v[j];
					if (cur < minv[j])
						minv[j] = cur,  way[j] = j0;
					if (minv[j] < delta)
						delta = minv[j],  j1 = j;
				}
			}
			for(int j=0; j <= n; j++){
				if (used[j]){
					u[p[j]] += delta;
					v[j] -= delta;
				}else minv[j] -= delta;
			}
			j0 = j1;

		} while (p[j0] != 0);

		do{
			int j1 = way[j0];
			p[j0] = p[j1];
			j0 = j1;
		} while (j0);
	}

	forn(i, n) cout << -u[i] << ' ';
	cout << endl;
	forn(i, n) cout << -v[i] << ' ';
	cout << endl;

	return 0;
}