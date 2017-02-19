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

	freopen("nails.in", "r", stdin);
	freopen("nails.out", "w", stdout);

  int n;
  cin >> n;
  vector <int> mass;
  vector <int> f;
  f.resize(n);
  mass.resize(n);
  for (int i = 0; i < n; i++){
    cin >> mass[i];
  }
  sort(mass.begin(), mass.end());

  f[0] = mass[1] - mass[0];
  f[1] = mass[1] - mass[0];
  for (int i = 2; i < n; i++){
    f[i] = (mass[i] - mass[i - 1]) + min(f[i - 1], f[i - 2]);
  }

  cout << f[n - 1] << '\n';

	return 0;
}