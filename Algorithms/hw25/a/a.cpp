#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define pi pair <int, int>
#define forn(i, n) for(int i = 0; i < (int)(n); i++)

typedef long long ll;

const int INF = 1000000000;
const int MAXN = 105;
const int MAXM = 1005;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("unequal.in", "r", stdin);
	freopen("unequal.out", "w", stdout);

	string s;
	set <string> ans;
	cin >> s;
	int n = s.size();
	forn(i, n){
		for (int j = 1; j <= n - i; j++){
			//cout << i << ' ' << j << s.substr(i, j) << endl;
			ans.insert(s.substr(i, j));
			//cout << ans.size() << endl;
		}
	}

	cout << ans.size() << endl;
	
	return 0;
}