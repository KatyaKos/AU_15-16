#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define pi pair <int, int>
#define forn(i, n) for(int i = 0; i < (int)(n); i++)

typedef long long ll;

const int INF = 1000000000;
const int MAXN = 3000005;
const int P = 239;
const int M = 1e9 + 7;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("substrcmp.in", "r", stdin);
	freopen("substrcmp.out", "w", stdout);

	string s, t;
	int n, k;
	cin >> s >> k;
	n = s.size();

	long long h[n + 1], pw[n+1];
	pw[0] = 1ll;
	h[0] = 0ll;
	for (int i = 1; i <= n; i++){
		h[i] = (h[i - 1] + (s[i - 1] - 'a' + 1ll) * pw[i - 1]) % M;
		pw[i] = pw[i - 1] * P % M;
	}

	int a, b, c, d;
	forn(i, k){
		cin >> a >> b >> c >> d;
		//cout << (h[b] - h[a - 1] + M) * pw[c - 1] % M << ' ' << (h[d] - h[c - 1] + M) * pw[a - 1] % M << endl;
		if ((h[b] - h[a - 1] + M) * pw[c - 1] % M == (h[d] - h[c - 1] + M) * pw[a - 1] % M) cout << "Yes\n";
		else cout << "No\n";

	}
	
	return 0;
}