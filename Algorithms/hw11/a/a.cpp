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

vector < vector<int> > g;
vector <int> w;
vector <int> d1, d0;
int n;

int dfs1(int v);

int dfs0(int v){

	if (d0[v] != -10) return d0[v];

	if (g[v].size() == 0){
		return 0;
	}else{
		int s = 0;
		for (int i = 0; i < g[v].size(); i++){
			int u = g[v][i];
			s += max(dfs1(u), dfs0(u));
		}
		d0[v] = s;
		return s;
	}
}

int dfs1(int v){

	if (d1[v] != -10) return d1[v];

	if (g[v].size() == 0){
		return max(w[v], 0);
	}else{
		int s = 0;
		for (int i = 0; i < g[v].size(); i++){
			int u = g[v][i];
			s += dfs0(u);
		}
		d1[v] = s + max(0, w[v]);
		return s + max(0, w[v]);
	}
}
 
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("selectw.in", "r", stdin);
	freopen("selectw.out", "w", stdout);

	int flag = 0;
	cin >> n;
	g.resize(n);
	w.resize(n);
	int t1, t2, s;
	for (int i = 0; i < n; i++){
		cin >> t1 >> t2;
		if (t1 != 0){
			g[t1 - 1].pb(i);
			w[i] = t2;
		}else{
			s = i;
			w[i] = t2;
		}
		if (t2 > 0){
			flag = 1;
		}
	}
	//Нет ни одного больше 0, все плохо
	if (flag == 0){
		cout << 0 << '\n';
		return 0;
	}

	d1.assign(n, -10);
	d0.assign(n, -10);
	cout << max(dfs1(s), dfs0(s)) << '\n';

	return 0;
}