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

	freopen("field.in", "r", stdin);
	freopen("field.out", "w", stdout);

  int n, m;
  cin >> m >> n;
  vector < vector <int> > mass;
  vector < vector <int> > f;
  f.resize(n);
  mass.resize(n);

  for (int i = 0; i < n; i++){
    f[i].resize(m);
    mass[i].resize(m);
    for (int j = 0; j < m; j++){
      cin >> mass[i][j];
    }
  }

  f[0][0] = 0;
  for (int i = 1; i < m; i++) f[0][i] = f[0][i - 1] + abs(mass[0][i] - mass[0][i - 1]);
  for (int i = 1; i < n; i++) f[i][0] = f[i - 1][0] + abs(mass[i][0] - mass[i - 1][0]);

  for (int i = 1; i < n; i++){
    for (int j = 1; j < m; j++){
      f[i][j] = min(f[i - 1][j] + abs(mass[i][j] - mass[i - 1][j]), f[i][j - 1] + abs(mass[i][j] - mass[i][j - 1]));
    }
  }

  cout << f[n - 1][m - 1] << '\n';

	return 0;
}