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

vector <vector <int> > t;
int n, k;

inline int sum(int x, int y)
{
	if (x < 0 || y < 0) return 0;
	int result = 0;
	for (int i = x; i >= 0; i = (i & (i+1)) - 1)
		for (int j = y; j >= 0; j = (j & (j+1)) - 1)
			result += t[i][j];
	return result;
}

inline void add(int x, int y)
{
	for (int i = x; i < n; i = (i | (i+1)))
		for (int j = y; j < n; j = (j | (j+1)))
			t[i][j] += 1;
}

inline int get(int x, int y, int xx, int yy)
{
	return sum(xx, yy) + sum(x - 1, y - 1) - sum(x - 1, yy) - sum(xx, y - 1);
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("fenwick.in", "r", stdin);
	freopen("fenwick.out", "w", stdout);

	n = readInt(); k = readInt();
	t.resize(n);
	for (int i = 0; i < n; i++) t[i].assign(n, 0);
	char c;
	int x, y, xx, yy;
	for (int i = 0; i < k; i++){
		c = readChar(); c = readChar(); c = readChar();
		if (c == 'D'){
			x = readInt() - 1; y = readInt() - 1;
			add(x, y);
		}else{
			x = readInt() - 1; y = readInt() - 1; xx = readInt() - 1; yy = readInt() - 1;
			if (x > xx) swap(x, xx);
			if (y > yy) swap(y, yy);
			writeInt(get(x, y, xx, yy)); writeChar('\n');
		}
	}

	flush();

	return 0;
}