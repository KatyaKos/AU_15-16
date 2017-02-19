#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define pi pair <int, int>
#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define PI M_PI

typedef long long ll;

const int INF = 1000000000;
const int MAXN = 1<<18 + 5;
const int MAXM = 100005;

typedef complex<double> base;
 
void fft (vector<base> & a, bool invert) {
	int n = (int) a.size();
 
	for (int i=1, j=0; i<n; ++i) {
		int bit = n >> 1;
		for (; j>=bit; bit>>=1)
			j -= bit;
		j += bit;
		if (i < j)
			swap (a[i], a[j]);
	}
 
	for (int len=2; len<=n; len<<=1) {
		double ang = 2*PI/len * (invert ? -1 : 1);
		base wlen (cos(ang), sin(ang));
		for (int i=0; i<n; i+=len) {
			base w (1);
			for (int j=0; j<len/2; ++j) {
				base u = a[i+j],  v = a[i+j+len/2] * w;
				a[i+j] = u + v;
				a[i+j+len/2] = u - v;
				w *= wlen;
			}
		}
	}
	if (invert)
		for (int i=0; i<n; ++i)
			a[i] /= n;
}

void multiply(const vector<int>& a, const vector<int>& b, vector<int>& res){
	vector<base> fa(a.begin(), a.end()),  fb(b.begin(), b.end());
	int n = 1;
	while (n < max (a.size(), b.size()))  n <<= 1;
	n <<= 1;
	fa.resize(n), fb.resize(n);
 
	fft (fa, false),  fft (fb, false);
	forn(i, n)
		fa[i] *= fb[i];
	fft (fa, true);
 
	res.resize (n);
	forn(i, n)
		res[i] = int (fa[i].real() + 0.5);
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);

	int n, m;
	vector<int> a;

	string s;
	getline(cin, s);
	n = s.size(); a.resize(n);
	forn(i, n) a[n - i - 1] = s[i] - '0';
	vector<int> aa(a);
	vector<int> old(a);

	vector<int> b;
	multiply(a, aa, b);
	long long ans = 0ll;
	forn(i, n)
		if (old[i])
			ans += b[2 * i] - 1ll;
	cout << ans / 2ll << '\n';

	return 0;
}