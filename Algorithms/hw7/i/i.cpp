#define _CRT_SECURE_NO_WARNINGS
//#pragma comment (linker, "/STACK:10000000000")

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
 
#define INF 1000000009
#define ll long long
#define ui unsigned int
#define mp make_pair

using namespace std;

int n, m;
vector <int> d;
vector < vector <int> > g;

int go(int i){
	if (g[i].size() == 0) return 0;
	if (d[i] != -1) return d[i];
	for (int j = 0; j < g[i].size(); j++){
		d[i] = max(d[i], go(g[i][j]) + 1);
	}
	return d[i];
}

int main() {

	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("longpath.in", "r", stdin);
	freopen("longpath.out", "w", stdout);

	cin >> n >> m;
	d.assign(n, -1);
	g.resize(n);

	int a, b, maxi = -1;
	for (int i = 0; i < m; i++){
		cin >> a >> b;
		g[a - 1].push_back(b - 1);
	}

	for (int i = 0; i < n; i++){
		d[i] = go(i);
		if (d[i] > maxi) maxi = d[i];
	}

	cout << maxi << '\n';
	

	return 0;
}