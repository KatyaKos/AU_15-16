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



int n, k;
vector <ll> mass;

void make(int v, int l, int r, int i, int x){
	if (l == r){
		mass[v] = x;
	}else{
		int m = (l + r) / 2;
		if (m >= i) make(2 * v, l, m, i, x);
		else make(2 * v + 1, m + 1, r, i, x);

		mass[v] = mass[2 * v] + mass[2 * v + 1];
	}
}

ll find(int v, int l, int r, int fl, int fr){

	if (fl > fr) return 0;
	if (l == fl && r == fr){
		return mass[v];
	}
	int m = (l + r) / 2;

	return find(2 * v, l, m, fl, min(m, fr)) + find(2 * v + 1, m + 1, r, max(m + 1, fl), fr);
}


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("sum.in", "r", stdin);
	freopen("sum.out", "w", stdout);

	//cin >> n >> k;
	n = readInt(); k = readInt();
	mass.assign(4 * n, 0);

	char c;
	int a, b;
	for (int i = 0; i < k; i++){
		//cin >> c >> a >> b;
		c = readChar(); a = readInt(); b = readInt();
		if (c == 'A'){
			make(1, 1, n, a, b);
		}else{
			//cout << find(1, 1, n, a, b) << '\n';
			writeInt(find(1, 1, n, a, b)); writeChar('\n');
		}
	}

	flush();

	return 0;
}