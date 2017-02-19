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

/** Interface */

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

const int MAX_MEM = 1e8;
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

	//cin.tie(0);
	//ios_base::sync_with_stdio(0);
	freopen("sforce.in", "r", stdin);
	freopen("sforce.out", "w", stdout);

  priority_queue < pair <int, int> > qu;
  unordered_map <int, int> map1;
  unordered_map <int, set <int> > map2;
  int n, q;

  n = readInt();
  int a;
  for (int i = 0; i < n; i++){
    a = readInt();
    map1[i] = a;
    map2[a].insert(i);
  }
  for (auto it = map2.begin(); it != map2.end(); it++){
    int tmp = it->second.size();
    //cout << -tmp << ' ' << -(*it->second.begin()) << '\n';
    qu.push(mp(-tmp, -(*it->second.begin())));
  }

  q = readInt();
  char si;
  int i, y, j, count, ai;
  for (int u = 0; u < q; u++){
    si = readChar();
    if (si == '='){

      i = readInt();
      y = readInt();
      ai = map1[i];
      map2[ai].erase(i);
      int tmp = map2[ai].size();
      qu.push(mp(-tmp, -(*map2[ai].begin()))); 
      map2[y].insert(i);
      map1[i] = y;
      tmp = map2[y].size();
      qu.push(mp(-tmp, -(*map2[y].begin())));

    }else{

      j = -qu.top().second;
      count = -qu.top().first;
      while(count != map2[map1[j]].size()){
        qu.pop();
        j = -qu.top().second;
        count = -qu.top().first;
      }
      writeInt(j);
      writeChar('\n');

    }
  }

  flush();

	return 0;
}