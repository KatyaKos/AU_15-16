#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define pi pair <int, int>
#define forn(i, n) for(int i = 0; i < (int)(n); i++)

typedef long long ll;

const int INF = 1000000000;
const int MAXN = 100005;
const int alph = 256;

string s;
int n;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("sufflcp.in", "r", stdin);
	freopen("sufflcp.out", "w", stdout);

	cin >> n >> s;
	int suf[n];
	forn(i, n){
		cin >> suf[i];
		suf[i]--;
	}

	int p[n], lcp[n];
	forn(i, n) p[suf[i]] = i;
	int k = 0;
	forn(j, n){
		int i = p[j];
		k--;
		if (k < 0 || i == n - 1) k = 0;
		if (i != n - 1)
			while (s[suf[i] + k] == s[suf[i + 1] + k]) k++;
		lcp[i] = k;
	}

	forn(i, n - 1) cout << lcp[i] << ' ';
	cout << '\n';

	return 0;
}