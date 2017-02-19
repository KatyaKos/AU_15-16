#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define pi pair <int, int>
#define forn(i, n) for(int i = 0; i < (int)(n); i++)

typedef long long ll;

const int INF = 1000000000;
const int MAXN = 1000005;
const int MAXM = 100005;

int n, k, m;
vector<int> p, q, r;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("divp.in", "r", stdin);
	freopen("divp.out", "w", stdout);

	cin >> n >> k >> m;
	p.resize(n);
	forn(i, n) cin >> p[i];
	if (k >= n){
		cout << "0\n";
		forn(i, n) cout << p[i] << ' ';
		forn(i, k - n) cout << "0 ";
		cout << '\n';
		return 0;
	}
	q.assign(n - k, 0);
	r.assign(k, 0);

	for (int i = n - 1; i >= 0; i--){
		if (k > i)
			break;
		q[i - k] = (q[i - k] + p[i]) % m;
		p[i - k] = (p[i - k] + p[i]) % m;
		p[i] = 0;
	}
	
	forn(i, k)
		r[i] = p[i];

	forn(i, n - k) cout << (q[i] + m) % m << ' ';
	cout << '\n';
	forn(i, k) cout << (r[i] + m) % m << ' ';
	cout << '\n';

	return 0;
}