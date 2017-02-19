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
#include <unordered_map>
#include <queue>
#include <set>
#include <iomanip>
#include <cassert>
 
#define INF 1000000009
#define ll long long
#define ui unsigned int

using namespace std;

unordered_map<ll, ui> mp;
ui f(ll x){
  if (x <= 2) return 1;
  ui res = mp[x];
  if (res != 0) return res;
  if (x%2==1) mp[x] = f(6*x/7)+f(2*x/3);
  if (x%2==0) mp[x] = f(x-1)+f(x-3);
  return mp[x];
}

int main() {

	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("function.in", "r", stdin);
	freopen("function.out", "w", stdout);

  ll n;
  cin >>n;
  cout << f(n) << '\n';
	return 0;
}