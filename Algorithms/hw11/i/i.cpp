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
#include <queue>
#include <map>
 
#define INF 2000000000
#define ll long long
#define ui unsigned int
#define mp make_pair
#define pb push_back

using namespace std;

#include <cassert>

/** Begin fast allocation */
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

int main(){
	freopen("shortest.in", "r", stdin);
	freopen("shortest.out", "w", stdout);

	int n, m, k;
	n = readInt();
	m = readInt();

	vector< vector< pair<int,int> > > g;
	g.resize(n);
	vector <int> d, ans;
	int maxD = (n - 1) * 2 + 1;

	for (int i = 0; i < m; i++){
		int a = readInt(), b = readInt(), c = readInt();
		a--; b--;
		g[a].pb(mp(b, c));
	}

	k = readInt();
	vector < queue<int> > q;
	int num, D;
	for (int i = 0; i < k; i++){
		int a = readInt(), b = readInt();
		a--; b--;

		d.assign(n, INF);

		d[a] = 0;
		q.resize(maxD);
		q[0].push(a);
		num = 1; D = 0;

		while(num > 0){
			while (q[D].size() != 0){
				int v = q[D].front(); q[D].pop();
				num--;
				if (d[v] / 1000 != D) continue;
				for (int i = 0; i < g[v].size(); i++){
					pair <int, int> p = g[v][i];
					if (d[p.first] > d[v] + p.second){
						int u = d[v] + p.second;
						d[p.first] = u;
						//ans[p.first] = u;
						q[u / 1000].push(p.first);
						num++;
					}
				}
			}
			D++;
		}
		if (d[b] == INF) writeInt(-1);
		else writeInt(d[b]);
		writeChar('\n');
	}

	flush();

	return 0;
}