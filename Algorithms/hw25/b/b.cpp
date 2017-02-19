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
	freopen("search.in", "r", stdin);
	freopen("search.out", "w", stdout);

	string s, t, str;
	int n, m;
	cin >> t >> s;
	m = s.size(); n = t.size();

	if (!n || !m){
		cout << 0 << endl << endl;
		return 0;
	}else if (n == 1){
		if (m > 1) cout << 0 << endl << endl;
		else{
			if (t[0] == s[0]) cout << 1 << endl << 1 << endl;
			else cout << endl;
		}
		return 0;
	}


	int z[MAXN];
	fill(z, z + n, 0);
	str = s + '0' + t;
	n += m + 1;
	for (int i = 1, l = 0, r = 0; i < n; i++){
		if (i <= r) z[i] = min(z[i - l], r - i + 1);

		while (i + z[i] < n && str[z[i]] == str[i+z[i]]) z[i]++;

		if (i + z[i] - 1 > r){
			l = i;
			r = i + z[i] - 1;
		}
	}

	vector <int> ans;
	for (int i = m + 1; i < n; i++){
		if (z[i] == m) ans.pb(i - m);
	}
	
	cout << ans.size() << endl;
	forn(i, ans.size()) cout << ans[i] << ' ';
	cout << endl;
	
	return 0;
}