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
#include <queue>
#include <string.h>
#include <bitset>
 
#define INF 1000000009
#define ll long long
#define ui unsigned int
#define mp make_pair
#define pb push_back
#define ld long double

using namespace std;

#include <cassert>


const int MAX_MEM = 1e9;
int mpos = 0;
char mem[MAX_MEM];
inline void * operator new ( size_t n ) {
  char *res = mem + mpos;
  mpos += n;
  assert(mpos <= MAX_MEM);
  return (void *)res;
}
inline void operator delete ( void * ) { }

inline void * operator new [] ( size_t ) { assert(0); }
inline void operator delete [] ( void * ) { assert(0); }


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cout.precision(5);
	freopen("dust.in", "r", stdin);
	freopen("dust.out", "w", stdout);

	int n, w;
	cin >> n >> w;
	vector <pair<double, pair<int, int> > > g;
	int v, m;
	for(int i = 0; i < n; i++){
		cin >> v >> m;
		g.pb(mp(1.0 * m / v, mp(v, m)));
	}
	sort(g.begin(), g.end());
	int tmp = 0, i = 0;
	double ans = 0.0;
	pair<int, int> p;
	while (tmp < w && i < n){
		p = g[i].second;
		if (tmp + p.second > w){
			ans += 1.0 * (w - tmp) * p.first / p.second;
			tmp = w;
		}else{
			tmp += p.second;
			ans += p.first;
		}
		i++;
	}
	cout << fixed << ans << '\n';

	return 0;
}