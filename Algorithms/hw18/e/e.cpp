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
 
#define INF 20000000000
#define ll long long
#define ui unsigned int
#define mp make_pair
#define pb push_back
#define pi pair <int, int>

using namespace std;
/*
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

inline void writeWord( const char *s ) {
  while (*s)
    writeChar(*s++);
}*/

int m;
const int n = 35000;
int mass[4 * n];
int ans[15000];

int find(int v, int l, int r, int fl, int fr){
	if (fl > fr) return 0;
	if (l == fl && r == fr) return mass[v];
	int m = (l + r) / 2;
	return find(2 * v, l, m, fl, min(fr, m)) + find(2 * v + 1, m + 1, r, max(m + 1, fl), fr);
}

void add(int v, int l, int r, int x){
	if (l == r){
		mass[v]++;
		return;
	}
	int m = (l + r) / 2;
	if (x <= m){
		add(2 * v, l, m, x);
	}else{
		add(2 * v + 1, m + 1, r, x);
	}
	mass[v] = mass[2 * v] + mass[2 * v + 1];
}


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("stars.in", "r", stdin);
	freopen("stars.out", "w", stdout);

	int x, y;
	while(cin >> m){
		memset(ans, 0, 15000 * sizeof(int));
		memset(mass, 0, 4 * n * sizeof(int));
		for (int i = 0; i < m; i++){
			cin >> x >> y;
			ans[find(1, 0, n, 0, x)]++;
			add(1, 0, n, x);
		}
		for (int i = 0; i < m; i++){
			cout << ans[i] << '\n';
		}
	}

	return 0;
}