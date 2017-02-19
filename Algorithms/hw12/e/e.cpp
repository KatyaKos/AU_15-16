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
 
#define INF 1000000000
#define ll long long
#define ui unsigned int
#define mp make_pair
#define pb push_back

using namespace std;

#include <cassert>

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

int n;
vector < vector <int> > m, rm;
vector <int> used, rused;

void dfs(int v, int cost){
	used[v] = 1;
	for (int i = 0; i < n; i++){
		int u = m[v][i];
		if (used[i] == 0 && u <= cost){
			dfs(i, cost);
		}
	}
}

void rdfs(int v, int cost){
	rused[v] = 1;
	for (int i = 0; i < n; i++){
		int u = rm[v][i];
		if (rused[i] == 0 && u <= cost){
			rdfs(i, cost);
		}
	}
}
 
int main(){
	//cin.tie(0);
	//ios_base::sync_with_stdio(0);
	freopen("avia.in", "r", stdin);
	freopen("avia.out", "w", stdout);

	n = readInt();
	m.resize(n);
	rm.resize(n);
	for (int i = 0; i < n; i++){
		m[i].resize(n);
		rm[i].resize(n);
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			m[i][j] = readInt();
			rm[j][i] = m[i][j];
		}
	}

	int l = -1, r = INF, me, s1, s2;

	while (l + 1 < r){
		int me = (l + r) / 2;
		used.assign(n, 0);
		dfs(0, me);
		s1 = 0;
		for (int i = 0; i < n; i++) s1 += used[i];
		rused.assign(n, 0);
		rdfs(0, me);
		s2 = 0;
		for (int i = 0; i < n; i++) s2 += rused[i];
		if (s1 == n && s2 == n) r = me;
		else l = me;
	}
	writeInt(r);
	writeChar('\n');
	
	flush();

	return 0;
}