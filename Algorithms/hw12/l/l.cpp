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
#include <set>
#include <queue>
 
#define INF 1000000000
#define ll long long
#define ui unsigned int
#define mp make_pair
#define pb push_back

using namespace std;

#include <cassert>

/** Begin fast allocation */
const int MAX_MEM = 1e8;
int mpos = 0;
char mem[MAX_MEM];
inline void * operator new ( size_t n ) {
  char *res = mem + mpos;
  mpos += n;
  assert(mpos <= MAX_MEM);
  return (void *)res;
}
inline void operator delete ( void * ) { }
/** End fast allocation */

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

int n, m, l;
vector < multiset <int> > g;
vector <int> used;
vector <vector <int> > place;

void dfs(int v){
	used[v] = 1;
	l++;
	for (multiset <int>::iterator it = g[v].begin(); it != g[v].end(); it++){
		int u = (*it);
		if (used[u] == 0){
			dfs(u);
		}
	}
}

 
int main(){
	//cin.tie(0);
	//ios_base::sync_with_stdio(0);
	freopen("roadwork.in", "r", stdin);
	freopen("roadwork.out", "w", stdout);

	n = readInt(); m = readInt();
	char c; int a, b;
	pair <int, int> p;
	g.resize(n);
	int tm = 0;
	for (int i = 0; i < m; i++){
		used.assign(n, 0);
		c = readChar(); a = readInt(); b = readInt();
		a--; b--;
		if (c == 'F'){
			g[a].insert(b);
			g[b].insert(a);
			tm++;
		}else{
			g[a].erase(g[a].find(b));
			g[b].erase(g[b].find(a));
			tm--;
		}
		l = 0;
		if (n - 1 == tm){
			dfs(0);
		}
		if (l == n && n - 1 == tm){
			writeChar('Y');
			writeChar('E');
			writeChar('S');
		}else{
			writeChar('N');
			writeChar('O');
		}
		writeChar('\n');
	}
	
	flush();

	return 0;
}