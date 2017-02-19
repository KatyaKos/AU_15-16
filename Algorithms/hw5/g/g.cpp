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
 
#define INF 1000000009
#define ll long long
#define ui unsigned int

using namespace std;

vector <ll> xs;
vector < pair <ll, ll> > x;
vector < pair <ll, ll> > y;
int n;
     
int main(){
  
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  freopen("union.in", "r", stdin);
  freopen("union.out", "w", stdout);
     
  cin >> n;
  if (n == 0){
    cout << 0 << '\n';
    return 0;
  }

  x.resize(n);
  y.resize(n);
  for (int i = 0; i < n; i++){
    cin >> x[i].first >> y[i].first >> x[i].second >> y[i].second;
    xs.push_back(x[i].first);
    xs.push_back(x[i].second);
  }
  
  sort(xs.begin(), xs.end());
  xs.resize(unique(xs.begin(), xs.end()) - xs.begin());

  ll ans = 0ll;
  for (int i = 0; i < xs.size() - 1; i++){
    vector < pair <int, int> > tmp;
    ll x1 = xs[i], x2 = xs[i + 1];

    for (int j = 0; j < n; j++){
      if (x1 >= x[j].first && x2 <= x[j].second){
        tmp.push_back(make_pair(y[j].first, y[j].second));
      }
    }

    sort(tmp.begin(), tmp.end());
    /*for (int j = 0; j < tmp.size(); j++){
      cout << tmp[j].first << '&' << tmp[j].second << ' ';
    }
    cout << '\n';*/
    ll s = 0ll;
    ll l = tmp[0].first, r = tmp[0].second;
    for (int j = 1; j < tmp.size(); j++){
      if (tmp[j].first <= r){
        if (tmp[j].second >= r){
          r = tmp[j].second;
        }
      } else{
        s += (x2 - x1) * (r - l);
        l = tmp[j].first;
        r = tmp[j].second;
      }
    }
    s += (x2 - x1) * (r - l);
    //cout << s << ' ' << x1 << ' ' << x2 << '\n';
    ans += s;
  }  

  cout << ans << '\n';
     
  return 0;
} 








