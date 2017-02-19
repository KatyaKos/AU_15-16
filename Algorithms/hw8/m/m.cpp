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

vector <int> a, b;
vector <int> ans;
int n, m;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("lcis.in", "r", stdin);
	freopen("lcis.out", "w", stdout);

	cin >> n >> m;
	a.resize(n);
	b.resize(m);
	ans.resize(3010);

	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	for (int j = 0; j < m; j++){
		cin >> b[j];
	}

	ans.assign(m, 0);
	int tmp;
	for (int i = 0; i < n; i++){
		tmp = 0;
		for (int j = 0; j < m; j++){
			if (a[i] > b[j] && ans[j] > tmp){
				tmp = ans[j];
			}else if (a[i] == b[j] && tmp + 1 > ans[j]){
				ans[j] = tmp + 1;
			}
		}
	}

	int l = 0;
	for (int i = 0; i < m; i++){
		l = max(l, ans[i]);
	}

	cout << l << '\n';

	return 0;
}