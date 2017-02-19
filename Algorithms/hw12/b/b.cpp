#define _CRT_SECURE_NO_WARNINGS
#pragma comment (linker, "/STACK:10000000000")

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
#include <set>
#include <queue>
 
#define INF 1000000009
#define ll long long
#define ui unsigned int
#define mp make_pair
#define pb push_back

using namespace std;
 
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("rootdist.in", "r", stdin);
	freopen("rootdist.out", "w", stdout);

	vector < vector <int> > g;
	int n;
	cin >> n;
	g.resize(n);

	int a;
	for (int i = 1; i < n; i++){
		cin >> a;
		g[a - 1].pb(i);
	}

	vector <int> d;
	d.assign(n, -1);
	d[0] = 0;
	queue <int> q;
	q.push(0);
	while(!q.empty()){
		int v = q.front(); q.pop();
		for (int i = 0; i < g[v].size(); i++){
			int u = g[v][i];
			if (d[u] == -1){
				d[u] = d[v] + 1;
				q.push(u);
			}
		}
	}

	int ansn = 0, ansd = -1;
	vector <int> ans;
	for (int i = 0; i < n; i++){
		if (d[i] > ansd){
			ansd = d[i];
		}
	}

	for (int i = 0; i < n; i++){
		if (d[i] == ansd){
			ansn++;
			ans.pb(i + 1);
		}
	}

	cout << ansd << '\n' << ansn << '\n';
	for (int i = 0; i < ans.size(); i++){
		cout << ans[i] << ' ';
	}
	cout << '\n';

	return 0;
}