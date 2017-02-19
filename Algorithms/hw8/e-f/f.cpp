#include <vector>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <math.h>
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
#define ld long double

using namespace std;

char s[1010];
int n, m;
vector <vector <int> > pref;
vector <vector <int> > d;
vector <vector <int> > del;

void answer(int l, int r){
	if (l > r) return;
	if (l == r){
		cout << s[l];
		return;
	}
	int len = r - l + 1;
	if (d[l][r] == len){
		for (int i = l; i <= r; i++){
			cout << s[i];
		}
		return;
	}
	for (int k = 0; k < del[len].size(); k++){
		int i = del[len][k];
		if (pref[l][l + i] >= len - i){
			if (i + 3 == d[l][r]){
				cout << len / i << '(';
				for (int j = l; j < l + i; j++){
					cout << s[j];
				}
				cout << ')';
				return;
			}else if (d[l][l + i - 1] + 3 == d[l][r]){
				cout << len / i << '(';
				answer(l, l + i - 1);
				cout << ')';
				return;
			}
		}
	}

	for (int i = l; i < r; i++){
		if (d[l][r] == d[l][i] + d[i + 1][r]){
			answer(l, i);
			answer(i + 1, r);
			return;
		}
	}
	return;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("folding2.in", "r", stdin);
	freopen("folding2.out", "w", stdout);

	scanf("%s", s);
	n = strlen(s);
	pref.resize(n + 1);
	d.resize(n + 1);
	del.resize(n + 1);
	for (int i = 0; i <= n; i++){
		pref[i].assign(n + 1, 0);
		d[i].assign(n + 1, 0);
	}
	for (int i = n - 1; i >= 0; i--){
		for (int j = n - 1; j >= 0; j--){
			if (s[i] == s[j]) pref[i][j] = 1 + pref[i + 1][j + 1];
		}
	}

	for (int i = 1; i <= n; i++){
		for (int j = 1; j * 2 <= i; j++){
			if (i % j == 0){
				del[i].pb(j);
			}
		}
	}

	for (int l = n - 2; l >= 0; l--){
		for (int r = l; r < n; r++){
			if (l == r) d[l][r] = 1;
			if (d[l][r] != 0) continue;
			d[l][r] = r - l + 1;
			int len = r - l + 1, flag = 0;
			for (int j = 0; j < del[len].size(); j++){
				int i = del[len][j];
				if (pref[l][l + i] >= len - i){
					if (i + 3 < d[l][r]){
						flag = 1;
						d[l][r] = i + 3;
					}
					int u = d[l][l + i - 1] + 3;
					if (u < d[l][r]){
						flag = 1;
						d[l][r] = u;
					}
					break;
				}
			}

			if (flag == 0 || len < 50){
				for (int i = l; i < r; i++){
					int u = d[l][i] + d[i + 1][r];
					if (d[l][r] > u) d[l][r] = u;
				}
			}
		}
	}

	answer(0, n - 1);

	cout << '\n';

	return 0;
}