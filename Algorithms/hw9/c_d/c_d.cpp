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
 
#define INF 1000000009
#define ll long long
#define ui unsigned int
#define mp make_pair

using namespace std;

/*

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
}*/

int main() {

	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("modsum2.in", "r", stdin);
	freopen("modsum2.out", "w", stdout);

	int n;
	vector <int> s;
	//n = readInt();
	cin >> n;
	s.resize(n);
	for (int i = 0; i < n; i++){
		//s[i] = readInt();
		cin >> s[i];
	}

	vector <int> sums;
	sums.assign(1<<n, 0);
	for (int i = 0; i < (1<<n); i++){
		for (int j = 0; j < n; j++){
			if (((1<<j) & i) != 0){
				sums[i] += s[j];
			} 
		}
	}

	ll ans = 0;

	for (int i = 1; i <= (1<<n); i++){
		for (int j = (i - 1) & i; j > 0; j = (j - 1) & i){
			ans += sums[j] % sums[i - j];
		}
	}

	//writeInt(ans);
	//writeChar('\n');

	//flush();

	cout << ans << '\n';

	return 0;
}