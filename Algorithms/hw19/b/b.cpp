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

vector <Node*> mass;
map <vector<pair<int, int> > > beg;
int n, q, nn;

void Build(int i, int l, int r){
	if (l == r){
		if (nn < n){
			nn++;
			mass[i].pb(readInt());
		}else{
			mass[i].pb(-1);
		}
		return;
	}
	int m = (l + r) / 2;
	Build(2 * i, l, m);
	Build(2 * i + 1, m + 1, r);
	mass[i].resize(mass[2 * i].size() + mass[2 * i + 1].size());
	merge(mass[2 * i].begin(), mass[2 * i].end(), mass[2 * i + 1].begin(), mass[2 * i + 1].end(), mass[i].begin());
}

int get(int i, int l, int r, int fl, int fr, int x, int y){
	if (fl > fr) return 0;
	if (l == fl && r == fr){
		return upper_bound(mass[i].begin(), mass[i].end(), y) - lower_bound(mass[i].begin(), mass[i].end(), x);
	}
	int m = (l + r) / 2;
	return get(2 * i, l, m, fl, min(fr, m), x, y) + get(2 * i + 1, m + 1, r, max(fl, m + 1), fr, x, y);
}

int main(){
	//cin.tie(0);
	//ios_base::sync_with_stdio(0);
	freopen("countoffline.in", "r", stdin);
	freopen("countoffline.out", "w", stdout);

	n = readInt(); m = readInt();
	mass.resize(4 * n + 1);
	nn = 0;
	Build(1, 1, n);
	int l, r, x, y;
	for (int i = 0; i < m; i++){
		l = readInt(); r = readInt(); x = readInt(); y = readInt();
		writeInt(get(1, 1, n, l, r, x, y)); writeChar('\n');
	}

	flush();

	return 0;
}