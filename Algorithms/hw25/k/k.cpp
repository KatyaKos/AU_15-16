#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define pi pair <int, int>
#define forn(i, n) for(int i = 0; i < (int)(n); i++)

typedef long long ll;

const int INF = 1000000000;
const int MAXN = 200005;
const int P = 31;
const int M = 1e9 + 7;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("trans.in", "r", stdin);
	freopen("trans.out", "w", stdout);

	int n;
	cin >> n;
	int z[n], p[n];
	forn(i, n) cin >> z[i];
	fill(p, p + n, 0);

	for (int i = 1; i < n; i++){
		if (z[i])
			for (int j = z[i] - 1; j >= 0 && !p[i + j]; j--)
				p[i + j] = j + 1;
	}

	forn(i, n) cout << p[i] << ' ';
	cout << endl;
	
	return 0;
}