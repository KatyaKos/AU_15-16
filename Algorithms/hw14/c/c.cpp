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
	freopen("sumdiff.in", "r", stdin);
	freopen("sumdiff.out", "w", stdout);

	int n;
	cin >> n;
	vector <int> ans;
	int i = 1, tmp = 0, m = 0;
	while (1){
		if (tmp + i == n){
			m++;
			ans.pb(i);
			break;
		}else if (tmp + 2 * i + 1 <= n){
			m++;
			ans.pb(i);
			tmp += i;
		}
		i++;
	}
	cout << m << '\n';
	for (int i = 0; i < m; i++){
		cout << ans[i] << ' ';
	}
	cout << '\n';

	return 0;
}