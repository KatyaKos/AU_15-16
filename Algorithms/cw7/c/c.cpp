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
#include <vector>
 
#define INF 1000000009
#define ll long long
#define ui unsigned int

using namespace std;
/*
struct Triple {
  int a, b, c;
};

Triple t = {1, 2, 3};
t.a, t.b, t.c;
*/
int main() {

	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("threeseq.in", "r", stdin);
	freopen("threeseq.out", "w", stdout);

  int n, m, l;
  vector <int> s, t, q, ans;
  vector < vector < vector < pair <int, vector<int> > > > > f;
  cin >> n;
  n++;
  f.resize(n);
  s.resize(n);
  for (int i = 1; i < n; i++) cin >> s[i];
  s[0] = -12;
  cin >> m;
  m++;
  t.resize(m);
  for (int i = 1; i < m; i++) cin >> t[i];
  t[0] = -14;
  cin >> l;
  l++;
  q.resize(l);
  for (int i = 1; i < l; i++) cin >> q[i];
  q[0] = -13;

  for (int i = 0; i < n; i++){
    f[i].resize(m);
    for (int j = 0; j < m; j++){
      f[i][j].resize(l);
      for (int u = 0; u <l; u++){
        f[i][j][u] = make_pair(0, vector<int>(3, 0));
      }
    }
  }
  
  for (int i = 1; i < n; i++){
    for (int j = 1; j < m; j++){
      for (int u = 1; u < l; u++){
        auto &p = f[i][j][u];
        if (s[i]==t[j] && s[i]==q[u]){
          if (f[i-1][j-1][u-1].first >p.first){
            p.first = f[i-1][j-1][u-1].first+1;
            p.second[0] = i-1;
            p.second[1] = j-1;
            p.second[2] = u - 1;
          }else p.first++;
        }
        if (f[i][j][u-1].first>p.first){
          p.first = f[i][j][u-1].first;
          p.second[0] = i;
          p.second[1] = j;
          p.second[2] = u-1;
        }
        if (p.first<f[i][j-1][u].first){
          p.first = f[i][j-1][u].first;
          p.second[0] = i;
          p.second[1] = j-1;
          p.second[2] = u;
        }
        if (p.first<f[i-1][j][u].first){
          p.first = f[i-1][j][u].first;
          p.second[0] = i-1;
          p.second[1] = j;
          p.second[2] = u;
        }
      }
    }
  }

  cout << f[n-1][m-1][l-1].first << '\n';
  int i = n-1, j = m-1, u=l-1;
  while (i!=0 && j!=0 && u!=0){
    if (s[i] == t[j] && s[i] == q[u]){
      ans.push_back(s[i]);
    }
    auto &p = f[i][j][u];
    i = p.second[0];
    j = p.second[1];
    u = p.second[2];
  }

  for (int i = ans.size()-1; i>=0; i--) cout << ans[i] << ' ';
  cout << '\n';

	return 0;
}