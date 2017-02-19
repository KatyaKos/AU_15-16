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
 
#define INF -1000000009
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

inline int readChar();
template <class T = int> inline T readInt(); 
template <class T> inline void writeInt( T x );
inline void writeChar( int x ); 
inline void writeWord( const char *s );
inline void flush();

static const int buf_size = 4096;

inline int getChar() {
  static char buf[buf_size];
  static int len = 0, pos = 0;
  if (pos == len)
    pos = 0, len = fread(buf, 1, buf_size, stdin);
  if (pos == len)
    return -1;
  return buf[pos++];
}

inline int readChar() {
  int c = getChar();
  while (c <= 32)
    c = getChar();
  return c;
}

template <class T>
inline T readInt() {
  int s = 1, c = readChar();
  T x = 0;
  if (c == '-')
    s = -1, c = getChar();
  while ('0' <= c && c <= '9')
    x = x * 10 + c - '0', c = getChar();
  return s == 1 ? x : -x;
}

static int write_pos = 0;
static char write_buf[buf_size];

inline void writeChar( int x ) {
  if (write_pos == buf_size)
    fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;
  write_buf[write_pos++] = x;
}

inline void flush() {
  if (write_pos)
    fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
}

template <class T> 
inline void writeInt( T x ) {
  if (x < 0)
    writeChar('-'), x = -x;

  char s[24];
  int n = 0;
  while (x || !n)
    s[n++] = '0' + x % 10, x /= 10;
  while (n--)
    writeChar(s[n]);
}

int n, m, k, col;
vector <vector <int> > g;
vector <int> used;
//priority_queue <pair<int, int> > q;
//vector <int> min_e, sel_e;
vector <int> rnk;
vector <pair<int,int> > par;
vector <bool> bipartite;

void make_set (int v) {
	par[v] = mp(v, 0);
	rnk[v] = 0;
	bipartite[v] = true;
}
 
pair<int,int> find_set (int v) {
	if (v != par[v].first) {
		int parity = par[v].second;
		par[v] = find_set (par[v].first);
		par[v].second ^= parity;
	}
	return par[v];
}
 
void add_edge (int a, int b) {
	pair<int,int> pa = find_set (a);
	a = pa.first;
	int x = pa.second;
 
	pair<int,int> pb = find_set (b);
	b = pb.first;
	int y = pb.second;
 
	if (a == b) {
		if (x == y)
			bipartite[a] = false;
	}
	else {
		if (rnk[a] < rnk[b])
			swap (a, b);
		par[b] = mp(a, x ^ y ^ 1);
		bipartite[a] = bipartite[a] & bipartite[b];
		if (rnk[a] == rnk[b])
			++rnk[a];
	}
}
 
bool is_bipartite (int v) {
	return bipartite[ find_set(v).first ];
}

 
int main(){
	//cin.tie(0);
	//ios_base::sync_with_stdio(0);
	freopen("addedge.in", "r", stdin);
	freopen("addedge.out", "w", stdout);

	//cin >> n;
	n = readInt(); m = readInt();
	par.resize(n);
	rnk.resize(n);
	bipartite.resize(n);
	for (int i = 0; i < n; i++) make_set(i);
	int a, b;
	int i;
	for (i = 0; i < m; i++){
		a = readInt() - 1; b = readInt() - 1;
		add_edge(a, b);
		if (is_bipartite(a) == true) cout << 1;
		else break;
	}
	for (int j = i; j < m; j++){
		cout << 0;
	}
	cout << '\n';
	
	flush();

	return 0;
}