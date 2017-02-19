#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define pi pair <int, int>
#define forn(i, n) for(int i = 0; i < (int)(n); i++)

typedef long long ll;

const int INF = 1000000000;
const int MAXN = 3000005;
const int P = 31;
const int M = 1e9 + 7;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("cyclic.in", "r", stdin);
	freopen("cyclic.out", "w", stdout);

	string s, t;
	int n, m;
	cin >> s;
	m = s.size();

	if (m == 1){
		cout << 1 << endl;
		return 0;
	}

	t = s + '0' + s + s;
	n = 3 * m + 1;
	int z[n];
	fill(z, z + n, 0);

	for (int i = 1, l = 0, r = 0; i < n; i++){
		if (i <= r) z[i] = min(z[i - l], r - i + 1);

		while (i + z[i] < n && t[z[i]] == t[i+z[i]]) z[i]++;

		if (i + z[i] - 1 > r){
			l = i;
			r = i + z[i] - 1;
		}
	}


	int ans = 0;
	for (int i = m + 1; i <= n - m; i++){
		//cout << z[i] << ' ';
		if (t[i + z[i]] < t[z[i]]) ans++;
	}
	cout << ans << endl;
	
	return 0;
}