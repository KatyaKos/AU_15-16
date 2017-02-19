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
#include <queue>
#include <unordered_map>
 
#define INF 1000000009
#define ll long long
#define ui unsigned int
#define mp make_pair
#define pb push_back

using namespace std;

const int ca = int('a');
const int c1 = int('1');

vector <int> d, p;
vector < vector <int> > g;

int count(int i, int j, int u, int k){
	return i + j * 10 + u * 100 + k * 1000;
}

void bfs(int s){
	queue <int> q;
	q.push(s);
	while (!q.empty()){
		int v = q.front();
		q.pop();
		for (int i = 0; i < g[v].size(); i++){
			int u = g[v][i];
			if (d[u] == -1){
				d[u] = d[v] + 1;
				p[u] = v;
				q.push(u);
			}
		}
	}
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("knight2.in", "r", stdin);
	freopen("knight2.out", "w", stdout);

	string b1, b2, e1, e2;
	cin >> b1 >> b2 >> e1 >> e2;
	int s = count(int(b1[1]) - c1, int(b1[0]) - ca, int(b2[1]) - c1, int(b2[0]) - ca);
	int se = count(int(e1[1]) - c1, int(e1[0]) - ca, int(e2[1]) - c1, int(e2[0]) - ca);
	int n = count(7, 7, 7, 7) + 1;
	g.resize(n);
	d.assign(n, -1);
	p.resize(n);
	p[s] = -1;
	d[s] = 0;

	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			for (int u = 0; u < 8; u++){
				for (int k = 0; k < 8; k++){
					if (i == u && j == k) continue;
					int t = count(i, j, u, k);
					if (i - 2 >= 0){
						if (j - 1 >= 0 && (i - 2 != u || j - 1 != k)) g[t].pb(count(i - 2, j - 1, u, k));
						if (j + 1 < 8 && (i - 2 != u || j + 1 != k)) g[t].pb(count(i - 2, j + 1, u, k));
					}
					if (i - 1 >= 0){
						if (j - 2 >= 0 && (i - 1 != u || j - 2 != k)) g[t].pb(count(i - 1, j - 2, u, k));
						if (j + 2 < 8 && (i - 1 != u || j + 2 != k)) g[t].pb(count(i - 1, j + 2, u, k));
					}
					if (i + 1 < 8){
						if (j - 2 >= 0 && (i + 1 != u || j - 2 != k)) g[t].pb(count(i + 1, j - 2, u, k));
						if (j + 2 < 8 && (i + 1 != u || j + 2 != k)) g[t].pb(count(i + 1, j + 2, u, k));
					}
					if (i + 2 < 8){
						if (j - 1 >= 0 && (i + 2 != u || j - 1 != k)) g[t].pb(count(i + 2, j - 1, u, k));
						if (j + 1 < 8 && (i + 2 != u || j + 1 != k)) g[t].pb(count(i + 2, j + 1, u, k));
					}
					if (u - 2 >= 0){
						if (k - 1 >= 0 && (u - 2 != i || k - 1 != j)) g[t].pb(count(i, j, u - 2, k - 1));
						if (k + 1 < 8 && (u - 2 != i || k + 1 != j)) g[t].pb(count(i, j, u - 2, k + 1));
					}
					if (u - 1 >= 0){
						if (k - 2 >= 0 && (u - 1 != i || k - 2 != j)) g[t].pb(count(i, j, u - 1, k - 2));
						if (k + 2 < 8 && (u - 1 != i || k + 2 != j)) g[t].pb(count(i, j, u - 1, k + 2));
					}
					if (u + 1 < 8){
						if (k - 2 >= 0 && (u + 1 != i || k - 2 != j)) g[t].pb(count(i, j, u + 1, k - 2));
						if (k + 2 < 8 && (u + 1 != i || k + 2 != j)) g[t].pb(count(i, j, u + 1, k + 2));
					}
					if (u + 2 < 8){
						if (k - 1 >= 0 && (u + 2 != i || k - 1 != j)) g[t].pb(count(i, j, u + 2, k - 1));
						if (k + 1 < 8 && (u + 2 != i || k + 1 != j)) g[t].pb(count(i, j, u + 2, k + 1));
					}
				}
			}
		}
	}

	bfs(s);
	int u = se;
	vector <int> ans;
	while (u != -1){
		ans.pb(u);
		u = p[u];
	}
	reverse(ans.begin(), ans.end());

	int m = d[se];

	for (int i = 0; i < m; i++){
		int t = ans[i + 1];
		if (abs(ans[i] - t) < 100){
			cout << 1 << ' ';
		} else{
			t /= 100;
			cout << 2 << ' ';
		}
		cout << char(t / 10 % 10 + ca) << t % 10 + 1 << '\n';
	}

	return 0;
}