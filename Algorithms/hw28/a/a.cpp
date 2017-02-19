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
vector<int> p, ans;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("mulp.in", "r", stdin);
	freopen("mulp.out", "w", stdout);

	cin >> n >> k >> m;
	p.resize(n);
	forn(i, n) cin >> p[i];
	ans.assign(n + k, 0);
	forn(i, n){
		ans[i] = (-1 * p[i]) % m;
	}
	forn(i, n){
		ans[i + k] = (ans[i + k] + p[i] % m) % m;
	}
	forn(i, n + k) cout << (ans[i] + m) % m << ' ';
	cout << '\n';
	
	return 0;
}