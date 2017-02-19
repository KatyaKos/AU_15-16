#include <vector>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <stack>
#include <map>
#include <queue>
#include <string.h>
#include <bitset>
 
#define INF 1000000009
#define ll long long
#define ui unsigned int
#define mp make_pair
#define pb push_back

using namespace std;

int n, m, k;
vector <int> used;
vector <string> s;
 
int dfs(int v){
	used[v] = 1;
	int ans = 1;
	for(int i = 0; i < n; i++){
		if(s[v][i] == '1' && used[i] == 0) ans += dfs(i);
	}
	
	return ans;
}
 

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("wires.in", "r", stdin);
	freopen("wires.out", "w", stdout);

	cin >> n;
	s.resize(n);
	used.assign(n, 0);

	for (int i = 0; i < n; i++){
		cin >> s[i];
	}

	cin >> m;
	vector <int> g;
	g.resize(m);
	int ans = 0;

	int a;
	for (int i = 0; i < m; i++){
		cin >> a;
		g[i] = dfs(a);
	}
	sort(g.begin(), g.end());


	k = 0;
	for (int i = 0; i < n; i++){
		k += 1 - used[i];
	}

	ans += (k + g[m - 1]) * (k + g[m - 1] - 1);
	for(int i = 0; i < m - 1; i++){
		ans += (g[i] - 1) * g[i];
	}

	int tmp = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			tmp += s[i][j] - '0';
		}
	}
	
	cout << (ans - tmp) / 2 << '\n';

	return 0;
}