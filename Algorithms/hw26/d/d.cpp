#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define pi pair <int, int>
#define forn(i, n) for(int i = 0; i < (int)(n); i++)

typedef long long ll;

const int INF = 1000000000;
const int MAXN = 3005;
const int MAXM = 255;
const int S = 26;
	 
string str;
int z[MAXN], n, lim[MAXN];
	 
void count(int pos){

	for (int i = pos + 1, l = pos, r = pos; i < n; i++){

		if (i <= r)
			z[i] = min(r - i + 1, z[i - l + pos]);
		while (i + z[i] < n && str[z[i] + pos] == str[i + z[i]])
			z[i]++;
		if (i + z[i] - 1 > r)
			l = i, r = i + z[i] - 1;
	}
}


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("prof.in", "r", stdin);
	freopen("prof.out", "w", stdout);

	getline(cin, str);
	n = str.size();
	int ans = 0;

	forn(pos, n - 1){
		memset(z, 0, sizeof(int) * n);
		count(pos);
		int cur = 0;

		for (int i = pos + 1; i < n; i++) cur = max(cur, min(z[i], i - pos));
		ans += max(0, cur - lim[pos]);
		for (int i = pos + 1; i < n; i++) lim[i] = max(lim[i], min(z[i], cur));  
	}
	cout << ans << '\n';
	
	return 0;
}