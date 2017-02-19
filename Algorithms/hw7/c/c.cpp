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

	freopen("badsubs.in", "r", stdin);
	freopen("badsubs.out", "w", stdout);

  int n;
  cin >> n;
  vector <int> f;
  f.resize(n + 1);

  if (n == 0){
    cout << 1 << '\n';
    return 0;
  }

  f[0] = 1;
  f[1] = 3;
  for (int i = 2; i <= n; i++){
    f[i] = 3 * f[i - 1] - f[i - 2];
  }

  cout << f[n] << '\n';

	return 0;
}