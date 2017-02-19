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
	freopen("invtrans.in", "r", stdin);
	freopen("invtrans.out", "w", stdout);

	int n;
	cin >> n;
	int z[n], p[n];
	forn(i, n) cin >> p[i];
	fill(z, z + n, 0);
	z[0] = n;

	for (int i = 1; i < n; i++){
		if (p[i])
			z[i - p[i] + 1] = p[i];
	}

	for (int i = 1; i < n; ){
		int j, m;
		for (j = 1; j < z[i] && (m = min(z[j], z[i] - j)) >= z[i + j]; j++)
			z[i + j] = m;
		i += j;
	}

	forn(i, n) cout << z[i] << ' ';
	cout << endl;
	
	return 0;
}