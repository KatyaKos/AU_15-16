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
 
#define INF 1000000009
#define ll long long
#define ui unsigned int
#define mp make_pair

using namespace std;

vector <int> used;
vector < vector <int> > g;
vector <int> ans;
vector <char> mass;
int w, h, x, xx, y, yy;
int flag;

void dfs(int v){
	ans.push_back(v);
	used[v] = 1;
	if (v == w * yy + xx && mass[v] != '*'){
		flag = 1;
		return;
	}
	for (int i = 0; i < g[v].size(); i++){
		if (used[g[v][i]] == 0){
			dfs(g[v][i]);
		}
		if (flag == 1){
			return;
		}
	}
	ans.pop_back();
}

int main() {

	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("dfsongrid.in", "r", stdin);
	freopen("dfsongrid.out", "w", stdout);

	cin >> w >> h >> x >> y >> xx >> yy;
	x--; xx--; y--; yy--;
	g.resize(w * h);
	char a;
	mass.resize(w * h);
	for (int i = 0; i < w * h; i++){
		cin >> mass[i];
	}
	for (int i = 0; i < w * h; i++){
		if (mass[i] == '.'){
			if (i + w < w * h && mass[i + w] == '.') g[i].push_back(i + w);
			if ((i + 1) % w != 0 && mass[i + 1] == '.') g[i].push_back(i + 1);
			if ((i - 1) % w != w - 1 && i != 0 && mass[i - 1] == '.') g[i].push_back(i- 1);
			if (i - w >= 0 && mass[i - w] == '.') g[i].push_back(i - w);
		}
	}

	used.assign(w * h, 0);
	flag = 0;
	dfs(w * y + x);
	
	if (flag == 0){
		cout << "NO" << '\n';
	}else{
		cout << "YES" << '\n';
		for (int i = 0; i < ans.size(); i++){
			cout << ans[i] % w + 1 << ' ';
			cout << (ans[i] - ans[i] % w) / w + 1 << ' ';
		}
		cout << '\n';
	}

	return 0;
}