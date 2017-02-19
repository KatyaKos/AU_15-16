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

char s1[10010];
char s2[10010];
int d[2][10010];

int main() {

	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("patterns.in", "r", stdin);
	freopen("patterns.out", "w", stdout);
	int n, m;
	cin >> s1 >> s2;
	n = strlen(s1);
	m = strlen(s2);
	if (m == 0){
		if (n == 0) cout << "YES\n";
		else{
			int flag = 0;
			for (int i = 0; i < n; i++){
				if (s1[i] != '*') flag = 1;
			}
			if (flag == 0){
				cout << "YES\n";
			}else{
				cout << "NO\n";
			}
		}
		return 0;
	} 
	d[1][0] = 1;
	d[0][0] = 1;
	int k = 0;
	int u = 0;
	while (s1[u] == '*'){
		d[0][u + 1] = 1;
		u++;
	}
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			d[1 - k][j + 1] = 0;
			if (s1[j] == '*' && (d[1 - k][j] == 1 || d[k][j + 1] == 1)) d[1 - k][j + 1] = 1;
			if ((s1[j] == s2[i] || s1[j] == '?' || s1[j] == '*') && d[k][j] == 1) d[1 - k][j + 1] = 1;
		}
		k = 1 - k;
		d[1][0] = d[0][0] = 0;
	}

	if (d[k][n] == 1) cout << "YES\n";
	else cout << "NO\n";
	

	return 0;
}