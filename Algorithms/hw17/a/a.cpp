#pragma comment (linker, "/STACK:10000000000")

#include <vector>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <stack>
#include <map>
#include <queue>
 
#define INF 10000000
#define ll long long
#define ui unsigned int
#define mp make_pair
#define pb push_back
#define pi pair <int, int>

using namespace std;

/*#include <cassert>

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
inline void operator delete [] ( void * ) { assert(0); }*/

struct Node{
public:
	int i;
	ll m;
	Node() {};
	Node(int ii, ll mm): i(ii), m(mm) {};
};

vector <Node> pst;
int n;

void pop(int i, int sz){
	Node tmp = pst[i];
	tmp = pst[tmp.i];
	pst[sz].i = tmp.i;
	pst[sz].m = tmp.m;
}

void push(int i, int m, int sz){
	Node tmp = pst[i];
	pst[sz].i = i;
	pst[sz].m = tmp.m + m;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("snowmen.in", "r", stdin);
	freopen("snowmen.out", "w", stdout);

	cin >> n;
	pst.resize(n + 1);
	pst[0] = Node(0, 0);

	int t, m;
	for (int i = 1; i <= n; i++){
		cin >> t >> m;
		if (m == 0) pop(t, i);
		else push(t, m, i);
	}

	ll ans = 0;
	for (int i = 1; i <= n; i++){
		ans += pst[i].m;
	}

	cout << ans << '\n';

	return 0;
}