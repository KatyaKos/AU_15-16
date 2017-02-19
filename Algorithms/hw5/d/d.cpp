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
#include <map>
#include <set>
#include <string>
#include <iomanip>
 
#define INF 1000000009
#define ll long long
#define ui unsigned int

using namespace std;

ui cur = 0;
vector <ui> mass;
int n, a, b;

ui nextRand24(){
  cur = cur * a + b;
  return cur >> 8;
}

ui nextRand32(){
  ui a = nextRand24(), b = nextRand24();
  return (a << 8) ^ b;
}

int main() {

	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("postman.in", "r", stdin);
	freopen("postman.out", "w", stdout);

  cin >> n >> a >> b;
  mass.resize(n);
  for (int i = 0; i < n; i++){
    mass[i] = nextRand32();
  }

  nth_element(mass.begin(), mass.begin() + n / 2, mass.end());

  //sort(mass.begin(), mass.end());
  
  ui mid = mass[n / 2];
  int i_m = n / 2;
  ll ans = 0;

  for (int i = 0; i < i_m; i++){
    ans += mid - mass[i];
  }
  for (int i = i_m + 1; i < n; i++){
    ans += mass[i] - mid;
  }

  cout << ans << '\n';

	return 0;
}








