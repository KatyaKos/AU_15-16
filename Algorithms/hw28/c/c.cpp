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
 
int rev (int num, int lg_n) {
	int res = 0;
	for (int i=0; i<lg_n; ++i)
		if (num & (1<<i))
			res |= 1<<(lg_n-1-i);
	return res;
}
 
void fft (vector<base> & a, bool invert) {
	int n = (int) a.size();
	int lg_n = 0;
	while ((1 << lg_n) < n)  ++lg_n;
 
	for (int i=0; i<n; ++i)
		if (i < rev(i,lg_n))
			swap (a[i], a[rev(i,lg_n)]);
 
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

	int carry = 0;
	forn(i, n){
		res[i] += carry;
		carry = res[i] / 10;
		res[i] %= 10;
	}
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("mul.in", "r", stdin);
	freopen("mul.out", "w", stdout);

	int n, m;
	vector<int> a, b;

	string s;
	getline(cin, s);
	n = s.size(); a.resize(n);
	forn(i, n) a[n - i - 1] = s[i] - '0';
	getline(cin, s);
	m = s.size(); b.resize(m);
	forn(i, m) b[m - i - 1] = s[i] - '0';

	vector<int> ans;
	multiply(a, b, ans);
	int j = ans.size() - 1;
	for (int i = ans.size() - 1; i >= 0; i--){
		if (ans[i]) break;
		j--;
	}
	for (int i = j; i >= 0; i--)
		cout << ans[i];
	cout << '\n';

	return 0;
}