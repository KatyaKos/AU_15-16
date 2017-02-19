#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define pi pair <int, int>
#define forn(i, n) for(int i = 0; i < (int)(n); i++)

typedef long long ll;

const int INF = 1000000000;
const int MAXN = 400005;
const int MAXM = 300005;
const int alph = 256;

string s;
int n, k;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("shifts.in", "r", stdin);
	freopen("shifts.out", "w", stdout);

	cin >> s >> k;
	n = s.size();
	int p[MAXN], cnt[MAXN], c[MAXN];
	fill(cnt, cnt + alph, 0);

	forn(i, n) ++cnt[s[i]];
	for (int i = 1; i<alph; ++i)
		cnt[i] += cnt[i-1];
	forn(i, n) p[--cnt[s[i]]] = i;

	c[p[0]] = 0;
	int classes = 1;
	for (int i = 1; i<n; ++i) {
		if (s[p[i]] != s[p[i-1]])  ++classes;
		c[p[i]] = classes-1;
	}

	int pn[MAXN], cn[MAXN];
	for (int h = 0; (1<<h) < n; ++h) {
		forn(i, n){
			pn[i] = p[i] - (1<<h);
			if (pn[i] < 0)  pn[i] += n;
		}
		fill(cnt, cnt + classes, 0);
		forn(i, n) ++cnt[c[pn[i]]];

		for (int i = 1; i < classes; ++i)
			cnt[i] += cnt[i-1];
		for (int i = n - 1; i >= 0; --i)
			p[--cnt[c[pn[i]]]] = pn[i];
		cn[p[0]] = 0;
		classes = 1;
		for (int i = 1; i < n; ++i){
			int mid1 = (p[i] + (1<<h)) % n,  mid2 = (p[i-1] + (1<<h)) % n;
			if (c[p[i]] != c[p[i-1]] || c[mid1] != c[mid2])
				++classes;
			cn[p[i]] = classes-1;
		}
		memcpy (c, cn, n * sizeof(int));
	}

	if (classes < k){
		cout << "IMPOSSIBLE\n";
		return 0;
	}
	
	forn(i, n)
		if (c[i] == k - 1){
			cout << s.substr(i, n - i) << s.substr(0, i - 0) << '\n';
			return 0;
		}

	return 0;
}