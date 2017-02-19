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
int n, m;

map <char, int> check;
vector <char> ans;

int go(int l, int r){
	if (l >= r) return d[l][r] = 0;
	if (check[s[l]] < 6 && check[s[r]] == check[s[l]] * 2) d[l][r] = go(l + 1, r - 1) + 2;
	for (int i = l; i < r; i++){
		d[l][r] = max(d[l][r], go(l, i) + go(i + 1, r));
	}
	return d[l][r];
}

void answer(int l, int r, int len){
	int flag = 0;
	if (l >= r) return;
	if (check[s[l]] < 6 && check[s[r]] == check[s[l]] * 2){
		if (d[l][r] == d[l + 1][r - 1] + 2){
			ans.pb(s[l]);
			answer(l + 1, r - 1, len + 1);
			ans.pb(s[r]);
			flag = 1;
		}
	}
	if (flag == 0){
		for (int i = l; i < r; i++){
			if (d[l][r] == d[l][i] + d[i + 1][r]){
				answer(l, i, len);
				answer(i + 1, r, len);
			}
		}
	}
	return;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("erase.in", "r", stdin);
	freopen("erase.out", "w", stdout);

	check['('] = 3; check[')'] = 6;
	check['['] = 4; check[']'] = 8;
	check['{'] = 5; check['}'] = 10;

	cin >> s;
	n = strlen(s);
	d.resize(n);
	for (int i = 0; i < n; i++){
		d[i].assign(n, -1);
		d[i][i] = 0;
	}
	m = go(0, n - 1);
	//cout << m;

	answer(0, n - 1, 0);


	for (int i = 0; i < m; i++){
		cout << ans[i];
	}
	cout << '\n';

	return 0;
}