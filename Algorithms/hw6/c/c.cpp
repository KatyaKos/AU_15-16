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
#include <unordered_map>
#include <queue>
#include <set>
#include <iomanip>
#include <cassert>
 
#define INF 1000000009
#define ll long long
#define ui unsigned int
#define mp make_pair

using namespace std;

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

const int MAX_MEM = 2e8;
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

int main() {

	freopen("segmentrace.in", "r", stdin);
	freopen("segmentrace.out", "w", stdout);

  int n = readInt(), y = readInt(), x = readInt();
  y++;

  vector < vector <int> > cory;
  cory.resize(y+1);
  int x1, y1, y2;
  for (int i = 0; i < n; i++){
    x1 = readInt();
    y1 = readInt();
    y2 = readInt();
    cory[y1].push_back(x1);
    y2++;
    cory[y2].push_back(x1);
  }

  multiset <int> len;
  len.insert(x);
  set <int> corx;
  corx.insert(0); 
  corx.insert(x);
  int ix;
  for (int it = 0; it < y; it++){
    for (int j = 0; j < cory[it].size(); j++){
      ix = cory[it][j];
      if (!corx.count(ix)){
        auto l = corx.lower_bound(ix), r = l--;
        len.erase(len.find(*r - *l));
        len.insert(*r-ix);
        len.insert(ix-*l);
        corx.insert(ix);
      }else{
        corx.erase(ix);
        auto l = corx.lower_bound(ix), r = l--;
        len.erase(len.find(*r-ix));
        len.erase(len.find(ix-*l));
        len.insert(*r-*l);
      }
    }
    writeInt(*len.rbegin());
    writeChar('\n');
  }

  flush();

	return 0;
}