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
 
#define INF 1000000009
#define ll long long
#define ui unsigned int
#define mp make_pair

using namespace std;

int main() {

	freopen("editdist.in", "r", stdin);
	freopen("editdist.out", "w", stdout);

	char s1[101];
	char s2[101];

	cin >> s1 >> s2;
	int n = strlen(s1);
	int m = strlen(s2);
	n++;
	m++;

	vector < vector <int> > f;
	f.resize(n);
	for (int i = 0; i < n; i++) f[i].resize(m);
	for (int i = 0; i < n; i++) f[i][0] = i;
	for (int i = 0; i < m; i++) f[0][i] = i;

	for (int i = 1; i < n; i++){
		for (int j = 1; j < m; j++){
			if (s1[i - 1] == s2[j - 1]) f[i][j] = f[i - 1][j - 1];
			else f[i][j] = f[i - 1][j - 1] + 1;
			f[i][j] = min(f[i][j], f[i - 1][j] + 1);
			f[i][j] = min(f[i][j], f[i][j - 1] + 1);
		}
	}

	cout << f[n - 1][m - 1] << '\n';

	return 0;
}