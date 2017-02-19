#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
#define mp make_pair
#define pb push_back
#define ui unsigned short int

using namespace std;

int n, step;
vector <pair<int, int> > ans;
vector <vector <ui> > g;

bool check(int i, int j, ui m, int ii, int jj){
	if (i >= 0 && i < n && j >= 0 && j < n){
		g[i][j]--;
		if (g[i][j] < m){
			return true;
		}else if (g[i][j] == m){
			if (min(ii, n - ii) > min(i, n - i) || min(jj, n - jj) > min(j, n - j)){
				return true;
			}
		}
		return false;
	}
	return false;
}


void go (int i, int j){
	ans[step].first = i; ans[step].second = j;
	step++;
	g[i][j] = 50000;
	ui m = 20;
	int ii = 2000, jj = 2000;
	if (check(i + 2, j + 1, m, ii, jj)){
		m = g[i + 2][j + 1];
		ii = i + 2; jj = j + 1;
	}
	if (check(i + 2, j - 1, m, ii, jj)){
		m = g[i + 2][j - 1];
		ii = i + 2; jj = j - 1;
	}
	if (check(i + 1, j + 2, m, ii, jj)){
		m = g[i + 1][j + 2];
		ii = i + 1; jj = j + 2;
	}
	if (check(i + 1, j - 2, m, ii, jj)){
		m = g[i + 1][j - 2];
		ii = i + 1; jj = j - 2;
	}
	if (check(i - 1, j + 2, m, ii, jj)){
		m = g[i - 1][j + 2];
		ii = i - 1; jj = j + 2;
	}
	if (check(i - 1, j - 2, m, ii, jj)){
		m = g[i - 1][j - 2];
		ii = i - 1; jj = j - 2;
	}
	if (check(i - 2, j + 1, m, ii, jj)){
		m = g[i - 2][j + 1];
		ii = i - 2; jj = j + 1;
	}
	if (check(i - 2, j - 1, m, ii, jj)){
		m = g[i - 2][j - 1];
		ii = i - 2; jj = j - 1;
	}

	if (m < 20) go(ii, jj);
}

int main(){
	srand(time(NULL));
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("hamknight.in", "r", stdin);
	freopen("hamknight.out", "w", stdout);

	cin >> n;
	g.resize(n);
	for (int i = 0; i < n; i++){
		g[i].resize(n);
	}
	step = 0;
	int nn = n * n;
	ans.assign(nn, mp(0, 0));
	while (step != nn){
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				int tmp = 0;
				if (i + 2 < n){
					if (j + 1 < n) tmp++;
					if (j - 1 >= 0) tmp++;
				}
				if (i + 1 < n){
					if (j + 2 < n) tmp++;
					if (j - 2 >= 0) tmp++;
				}
				if (i - 1 >= 0){
					if (j + 2 < n) tmp++;
					if (j - 2 >= 0) tmp++;
				}
				if (i - 2 >= 0){
					if (j + 1 < n) tmp++;
					if (j - 1 >= 0) tmp++;
				}
				g[i][j] = tmp;
			}
		}
		step = 0;
		go(rand() % n, rand() % n);
	}

	for (int i = 0; i < ans.size(); i++){
		cout << ans[i].first << ' ' << ans[i].second << '\n';
	}
	//cout << ans.size() << '\n';

	return 0;
}