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

ll Euc(ll a, ll m, ll&x, ll& y){
	if (!a){
		x = 0; y = 1;
		return m;
	}

	ll xx, yy;
	ll d = Euc(m % a, a, xx, yy);
	x = yy - (m / a) * xx;
	y = xx;
	return d;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("inverse.in", "r", stdin);
	freopen("inverse.out", "w", stdout);

	ll a, m, x, y;
	cin >> a >> m;
	if (!a) cout << -1 << '\n';
	else{
		ll d = Euc(a, m, x, y);
		if (d != 1) cout << -1 << '\n';
		else{
			x = (x % m + m) % m;
			cout << x << '\n';
		}
	}
	
	return 0;
}