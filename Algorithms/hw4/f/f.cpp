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
#define ui unsigned int

using namespace std;

#include <cstdio>




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


struct Event{
	int x;
	int type;
	int num;
	Event(int xx, int ttype, int nnum)
	{
		x = xx;
		type = ttype;
		num = nnum;
	}
	Event(){}

};
bool cmp(Event a, Event b)
{
	if (a.x == b.x)
		return a.type < b.type;
	return a.x < b.x;
}

int main() {

	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("segments.in", "r", stdin);
	freopen("segments.out", "w", stdout);

	
	int n = readInt(), m = readInt();
	vector < Event > poi;
	vector <int> ans;
	ans.resize(m);

	for (int i = 0; i < n; i++){
		int a = readInt(), b = readInt();
		if (a > b) swap(a, b);
		poi.push_back(Event(a, -1, -1));
		poi.push_back(Event(b, 1, -1));
	}
	for (int i = 0; i < m; i++){
		int a = readInt();
		poi.push_back(Event(a, 0, i));
	}
	sort(poi.begin(), poi.end(), cmp);

	int bal = 0;
	for (int i = 0; i < poi.size(); i++){
		if (poi[i].type == -1) bal++;
		else if (poi[i].type == 1) bal--;
		else ans[poi[i].num] = bal;
	}

	for (int i = 0; i < m; i++){
		writeInt(ans[i]);
		writeChar(' ');
	}
	writeChar('\n');

	flush();
	
	return 0;
}








