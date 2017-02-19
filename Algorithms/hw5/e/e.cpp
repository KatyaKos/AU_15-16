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
int n, a, b;

ui nextRand24(){
  cur = cur * a + b;
  return cur >> 8;
}

ui nextRand32(){
  ui a = nextRand24(), b = nextRand24();
  return (a << 8) ^ b;
}

ui NOD(ui ll x, ui ll y){
  
  while (y){
    x %= y;
    swap(x, y);
  }
  return x;
}

int main() {

	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("finansist.in", "r", stdin);
	freopen("finansist.out", "w", stdout);

  cin >> n >> a >> b;
  unsigned ll sum = 0;

  for (int i = 0; i < n; i++){
    sum += nextRand32();
  }

  ui nod = NOD(sum, n);
  sum /= nod;
  n /= nod;
  cout << sum << "/" << n << '\n';

	return 0;
}








