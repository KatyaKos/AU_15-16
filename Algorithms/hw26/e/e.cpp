#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define pi pair <int, int>
#define forn(i, n) for(int i = 0; i < (int)(n); i++)

typedef long long ll;

const int INF = 1000000000;
const int MAXN = 250005;
const int MAXM = 255;
const int S = 26;

int n;
int p[MAXN], pp[MAXN], num[MAXN], col[MAXN], sz[MAXN];
string t, s, ss;
 
void build(){
	int m = max(n, 256);
	forn(i, n){
		col[i] = t[i];
		p[i] = i;
	}
 
	for (int kk = 1; kk < n * 2; kk *= 2){
		int k = kk / 2;
		fill(num, num + MAXN, 0);

		forn(i, n)
			num[col[i] + 1]++;
		forn(i, m)
			num[i + 1] += num[i];
		forn(i, n){
			pp[num[col[(p[i] - k + n) % n]]] = (p[i] - k + n) % n;
			num[col[(p[i] - k + n) % n]]++;
		}
 
		int cc = 0;
		forn(i, n){
			if (i && (col[pp[i]] != col[pp[i - 1]] || col[(pp[i] + k) % n] != col[(pp[i - 1] + k) % n]))
				cc++;
			num[pp[i]] = cc;
		}
		forn(i, n){
			p[i] = pp[i];
			col[i] = num[i];
		}
	}

	fill(num, num + MAXN, 0);
	forn(i, n)
		num[col[i] + 1]++;
	forn(i, m)
		num[i + 1] += num[i];
	forn(i, n){
		pp[num[col[i]]] = i;
		num[col[i]]++;
	}
	forn(i, n)
		p[i] = pp[i];

	forn(i, n)
		pp[p[i]] = i;
}
 
void build2(){
	int tmp = 0;
	forn(i, n){
		int j = pp[i];
		tmp = max(0, tmp - 1);

		if (j != n - 1)
			while (tmp < n && t[(p[j] + tmp) % n] == t[(p[j + 1] + tmp) % n])
				tmp++;

		sz[j] = tmp;
		if (j != n - 1 && p[j + 1] == n - 1)
			tmp = 0;
	}
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("freedom.in", "r", stdin);
	freopen("freedom.out", "w", stdout);

	cin >> n;
	getline(cin, s);
	getline(cin, s);
	getline(cin, ss);
	t = s + '#' + ss + '$';

	int nn = n;
	n = 2 * n + 2;
	build();
	build2();
	int ans = 0, m = 0, mm = 0, pos = -1;

	forn(i, n){
		if (p[i] < nn){
			if (ans < mm){
				ans = mm;
				pos = p[i];
			}
			m = sz[i];
			mm = min(mm, sz[i]);  
		}else{
			if (ans < m){
				ans = m;
				pos = p[i];
			}
			m = min(m, sz[i]);
			mm = sz[i];
		}
	}

	for (int i = pos; i < pos + ans; i++){
		cout << t[i];
	}
	cout << '\n';
	
	return 0;
}