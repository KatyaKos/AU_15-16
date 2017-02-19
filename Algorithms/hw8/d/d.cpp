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

char s[1000];
vector <vector <int> > d;
int n;

int go(int l, int r){
	if (l > r) return 0;
	if (d[l][r] != -1) return d[l][r];
	if (s[l] == s[r]) return d[l][r] = go(l + 1, r - 1) + 2;
	return d[l][r] = max(go(l + 1, r), go(l, r - 1));
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("palindr.in", "r", stdin);
	freopen("palindr.out", "w", stdout);

	cin >> s;
	n = strlen(s);
	d.resize(n);
	for (int i = 0; i < n; i++){
		d[i].assign(n, -1);
	}
	for (int i = 0; i < n; i++){
		d[i][i] = 1;
	}
	int m = go(0, n - 1);
	vector <char> ans;
	ans.resize(m);

	int tmp = 0;
	int l = 0, r = n - 1;
	while (tmp * 2 < m){
		if (s[l] == s[r]){
			ans[tmp] = s[l];
			ans[m - 1 - tmp] = s[r];
			tmp += 1;
			l++;
			r--;
		}else{
			if (d[l + 1][r] == d[l][r]){
				l++;
			}else{
				r--;
			}
		}
	}

	for (int i = 0; i < m; i++){
		cout << ans[i];
	}
	cout << '\n';

	return 0;
}