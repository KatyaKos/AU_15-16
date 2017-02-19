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
 
#define INF 100000000
#define ll long long
#define ui unsigned int
#define mp make_pair
#define pb push_back
#define pi pair <int, int>

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


/** Interface */

inline int readChar();
template <class T = int> inline T readInt(); 
template <class T> inline void writeInt( T x );
inline void writeChar( int x ); 
inline void writeWord( const char *s );
inline void flush();

/** Read */

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

/** Write */

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

inline void writeWord( const char *s ) {
  while (*s)
    writeChar(*s++);
}

int n, l, m;
vector <vector <pi> > g;
vector < vector<int> > up;
vector<int> tin, tout, s;
int timer;

void dfs (int v, int p, int sl) {
	tin[v] = ++timer;
	up[v][0] = p;
	for (int i=1; i<=l; ++i) up[v][i] = up[up[v][i-1]][i-1];

	for (size_t i=0; i < g[v].size(); ++i) {
		int u = g[v][i].first;
		int w = g[v][i].second;
		if (u != p){
			s[u] = sl + w;
			dfs(u, v, sl + w);
		}
	}
	tout[v] = ++timer;
}

bool upper (int a, int b) {
	return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca (int a, int b) {
	if (upper (a, b))  return a;
	if (upper (b, a))  return b;
	for (int i=l; i>=0; --i)
		if (! upper (up[a][i], b))
			a = up[a][i];
	return up[a][0];
}


int main(){
	//cin.tie(0);
	//ios_base::sync_with_stdio(0);
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);

	n = readInt();
	g.resize(n);
	tin.resize (n);
	tout.resize (n);
	up.resize(n);
	s.assign(n, 0);
	l = 1;
	while ((1<<l) <= n)  ++l;
	for (int i=0; i<n; ++i) up[i].resize (l+1);

	int a, b, w, c;
	for (int i = 1; i < n; i++){
		a = readInt(); b = readInt(); w = readInt();
		g[a].pb(mp(b, w));
		g[b].pb(mp(a, w));
	}
	timer = 0;
	dfs(0, 0 , 0);

	m = readInt();
	for (int i = 0; i < m; i++){
		a = readInt(); b = readInt();
		c = lca(a, b);
		writeInt(s[a] + s[b] - 2* s[c]);
		writeChar('\n');
	}


	flush();

	return 0;
}