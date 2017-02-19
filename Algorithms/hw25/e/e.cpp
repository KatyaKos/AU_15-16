#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define pi pair <int, int>
#define forn(i, n) for(int i = 0; i < (int)(n); i++)

typedef long long ll;

const int INF = 1000000000;
const int MAXN = 3000005;
const int P = 239;
const int M = 1e9 + 7;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("decimal.in", "r", stdin);
	freopen("decimal.out", "w", stdout);

	string s; char c;
	cin >> c;
	if (c == '1'){
		cout << "1.(0)\n";
		return 0;
	}
	cin >> c >> s;
	int n = s.size();
	reverse(s.begin(), s.end());

	int p[n];
	p[0] = 0;
	for (int i = 1; i < n; i++){
		int pf = p[i - 1];
		while (pf > 0 && s[pf] != s[i]) pf = p[pf - 1];

		if (s[pf] == s[i]) pf++;
		p[i] = pf;
	}

	int r = n + 1, l = n + 1;
    forn(i, n){
        int len = n - i, j = len - p[len - 1];
        if (i + j < r + l)
            r = i, l = j;
    }

    cout << "0.";
    forn(i, r) cout << s[n - i - 1];
    cout << '(';
    forn(i, l) cout << s[n - r - i - 1];
    cout << ")\n";
	
	return 0;
}