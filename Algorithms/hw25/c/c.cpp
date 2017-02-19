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
	freopen("basis.in", "r", stdin);
	freopen("basis.out", "w", stdout);

	string s, t;
	int n;
	cin >> s;
	n = s.size();

	if (!n){
		cout << endl;
		return 0;
	}else if (n == 1){
		cout << 1 << endl;
		return 0;
	}


	int z[MAXN];
	fill(z, z + n, 0);

	for (int i = 1, l = 0, r = 0; i < n; i++){
		if (i <= r) z[i] = min(z[i - l], r - i + 1);

		while (i + z[i] < n && s[z[i]] == s[i+z[i]]) z[i]++;

		if (i + z[i] - 1 > r){
			l = i;
			r = i + z[i] - 1;
		}
	}

	for (int t = 1; t < n; t++){
		if (z[t] >= n - t){
			cout << t << endl;
			return 0;
		}
	}
	cout << n << endl;
	
	return 0;
}