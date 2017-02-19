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
#include <queue>
#include <string.h>
#include <bitset>
 
#define INF 1000000009
#define ll long long
#define ui unsigned int
#define mp make_pair
#define pb push_back

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
	freopen("segments.in", "r", stdin);
	freopen("segments.out", "w", stdout);

	int n, l, r;
	vector <pair<int, int> > s;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> l >> r;
		s.pb(mp(r, l));
	}
	sort(s.begin(), s.end());

	r = 0;
	int ans = 0;
	for (int i = 0; i < n; i++){
		if (s[i].second >= r){
			r = s[i].first;
			ans++;
		}
	}

	cout << ans << '\n';

	return 0;
}