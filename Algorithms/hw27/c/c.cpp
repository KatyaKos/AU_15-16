#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define pi pair <int, int>
#define forn(i, n) for(int i = 0; i < (int)(n); i++)

typedef long long ll;

const int INF = 1000000000;
const int MAXN = 5005;
const int MAXM = 300005;


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("cruel.in", "r", stdin);
	freopen("cruel.out", "w", stdout);

	int n;
	cin >> n;
	if (n == 2){
		cout << "Schtirlitz\n1\n2\n";
		return 0;
	}else if (n == 3){
		cout << "Schtirlitz\n2\n";
		return 0;
	}

	int g[MAXN];
	g[0] = 0;
	g[1] = 1; g[2] = 1; g[3] = 2;
	int mark[n + 5];
	fill(mark, mark + n + 5, 0);
	int c = 1;

	for (int i = 4; i <= n; i++){
		for (int j = 1; j <= i; j++){
			if (j == 2 || j == i - 1) mark[g[0] ^ g[i - 2]] = c;
			else mark[g[j - 1] ^ g[i - j]] = c;
		}
		int j = 0;
		while (mark[j] == c) j++;
		c++;
		g[i] = j;
	}

	if (g[n] == 0){
		cout << "Mueller\n";
		return 0;
	}
	cout << "Schtirlitz\n";
	for (int j = 1; j <= n; j++){
		
		if (j == 2 || j == n - 1){
			//cout << (g[0] ^ g[n - 2]) << '\n';
			if ((g[0] ^ g[n - 2]) == 0) cout << j << '\n';
		}
		else{
			//cout << (g[j - 1] ^ g[n - j]) << '\n';
			if ((g[j - 1] ^ g[n - j]) == 0) cout << j << '\n';
		}
	}
	
	return 0;
}