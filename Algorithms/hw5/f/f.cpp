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
 
#define INF 1000000009
#define ll long long
#define sort stable_sort

using namespace std;
int n, m, l, r;
vector <int> mass;

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


int main() {

	freopen("segpnt.in", "r", stdin);
	freopen("segpnt.out", "w", stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	n = readInt();
  m = readInt();
  //cin >> n;
	mass.resize(n);
	for (int i = 0; i < n; i++){
    mass[i] = readInt();
    //cin >> mass[i];
  }
	sort(mass.begin(), mass.end());

  //cin >> k;
	for (int i = 0; i < m; i++){
		l = readInt();
		r = readInt();
    //cin >> l >> r;
		int li = lower_bound(mass.begin(), mass.end(), l) - mass.begin(), ri = upper_bound(mass.begin(), mass.end(), r) - mass.begin() - 1;

		writeInt(ri - li + 1);
		writeChar(' ');
    //cout << ri - li + 1 << ' ';
	}
	writeChar('\n');
	flush();
  //cout << '\n';
	return 0;
}