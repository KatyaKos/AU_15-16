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
#include <set>
#include <string>
#include <iomanip>
 
#define INF 1000000009
#define ll long long
#define ui unsigned int

using namespace std;




#include <cstdio>

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

vector <int> x;
vector <int> y;
vector <float> xf;
vector <float> yf;
int n;
int ans, xans, yans, c1, c2, c3, c4;
vector <int> ci;

void check (int xi, int yi){
  int m = -1;
  int xt, yt;

  
  for (int i = 0; i < 4; i++){
    int s = abs(xi - x[ci[i]]) + abs(yi - y[ci[i]]);
    if (s > m){
      m = s;
      xt = xi;
      yt = yi;
    }
  }
  if (m < ans){
    xans = xt;
    yans = yt;
    ans = m;
  }
}

int main() {

	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("cucarach.in", "r", stdin);
	freopen("cucarach.out", "w", stdout);

  n = readInt();
  x.resize(n);
  y.resize(n);
  xf.resize(n);
  yf.resize(n);
  ci.resize(4);
  c1 = 2000000000;
  c2 = 2000000000;
  c3 = -2000000000;
  c4 = -2000000000;
  for (int i = 0; i < n; i++){
    x[i] = readInt();
    y[i] = readInt();
    xf[i] = (x[i] + y[i]) / 2.0;
    yf[i] = (y[i] - x[i]) / 2.0;
    if (x[i] + y[i] < c1){
      c1 = x[i] + y[i];
      ci[0] = i;
    }
    if (x[i] - y[i] < c2){
      c2 = x[i] - y[i];
      ci[1] = i;
    }
    if (x[i] + y[i] > c3){
      c3 = x[i] + y[i];
      ci[2] = i;
    }
    if (x[i] - y[i] > c4){
      c4 = x[i] - y[i];
      ci[3] = i;
    }
    //cout << xf[i] << ' ' << yf[i] << '\n';
  }

  float xb = *min_element(xf.begin(), xf.end());
  float xn = *max_element(xf.begin(), xf.end());
  float yb = *min_element(yf.begin(), yf.end());
  float yn = *max_element(yf.begin(), yf.end());


  xb = (xb + xn) / 2;
  yb = (yb + yn) / 2;

  int xi = floor(xb - yb);
  int yi = floor(xb + yb);
  xans = xi, yans = yi;
  ans = 2000000000;

  for (int i = -40; i < 40; i++){
    for (int j = -40; j < 40; j++){
      check(xi + i, yi + j);
    }
  }

  cout << xans << ' ' << yans << '\n';

  flush();

	return 0;
}








