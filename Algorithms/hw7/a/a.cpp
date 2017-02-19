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

	freopen("joseph.in", "r", stdin);
	freopen("joseph.out", "w", stdout);

  int n, p;
  cin >> n >> p;
  vector <int> f;
  f.resize(n + 1);
  f[1] = 1;
  for (int i = 2; i < n + 1; i++){
    f[i] = (f[i - 1] + p - 1) % i + 1;;
  }

  cout << f[n] << '\n';

	return 0;
}