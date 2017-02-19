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
#define mp make_pair

using namespace std;

int main() {

	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("calcul.in", "r", stdin);
	freopen("calcul.out", "w", stdout);

  int n;
  cin >> n;

  vector <int> f;
  vector<int> p;
  vector<int> ans;
  f.resize(n+1);
  p.resize(n+1);
  f[1] = 0;
  for (int x = 2; x < n+1; x++){
    f[x] = f[x-1];
    p[x] = x-1;
    if (x % 2 == 0 && f[x/2]<f[x]){
      p[x] = x/2;
      f[x] = f[x/2];
    }
    if (x % 3 == 0 && f[x/3]<f[x]){
      p[x]=x/3;
      f[x]=f[x/3];
    }
    f[x]++;
  }
  cout << f[n] <<'\n';
  int x = n;
  while (x != 1){
    ans.push_back(x);
    x = p[x];
  }
  ans.push_back(1);
  for (int i = ans.size()-1; i > -1; i--){
    cout << ans[i] << ' ';
  }
  cout << '\n';

  
  //flush();

	return 0;
}