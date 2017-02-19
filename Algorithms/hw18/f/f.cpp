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

struct Point{
	int x, y, xx, yy;
	Point(int x, int xx, int y, int yy): x(x), xx(xx), y(y), yy(yy) {};
	bool operator < (const Point& p) const{
		return (p.x > x || p.xx < xx && p.x == x);
	}
};

int n, ans, ansx, ansy;
const int m = 2*100000;
vector <int> mass;
vector <int> psh;
vector <Point> crd;

inline void push(int v, int l, int r){
	int x = psh[v];
	psh[v] = 0;
	if (l == r) return;
	mass[2 * v] += x;
	mass[2 * v + 1] += x;
	psh[2 * v] += x;
	psh[2 * v + 1] += x;
}

void add(int v, int l, int r, int fl, int fr, int x){
	if (fl > fr) return;
	if (l == fl && fr == r){
		mass[v] += x;
		psh[v] += x;
		return;
	}
	push(v, l, r);
	int m = (l + r) / 2;
	add(2 * v, l, m, fl, min(m, fr), x);
	add(2 * v + 1, m + 1, r, max(m + 1, fl), fr, x);
	mass[v] = max(mass[2 * v], mass[2 * v + 1]);
}

void find(int v, int l, int r, int x){
	if (l == r){
		if (ans < mass[v]){
			ans = mass[v];
			ansx = x;
			ansy = l;
		}
		return;
	}
	push(v, l, r);
	int m = (l + r) / 2;
	if (mass[2 * v] > mass[2 * v + 1]) find(2 * v, l, m, x);
	else find(2 * v + 1, m + 1, r, x);
}


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("windows.in", "r", stdin);
	freopen("windows.out", "w", stdout);

	cin >> n;
	mass.assign(8 * m + 100, 0);
	psh.assign(8 * m + 100, 0);
	int x, xx, y, yy;
	for (int i = 0; i < n; i++){
		cin >> x >> y >> xx >> yy;
		x+= m + 1; xx += m + 1; y += m + 1; yy += m + 1;
		crd.pb(Point(x, 1, y, yy));
		crd.pb(Point(xx, -1, y, yy));
	}
	sort(crd.begin(), crd.end());
	ans = -1;
	for (int i = 0; i < 2 * n; i++){
		add(1, 1, 2 * m + 10, crd[i].y, crd[i].yy, crd[i].xx);
		find(1, 1, 2 * m + 10, crd[i].x);
	}
	cout << ans << '\n' << ansx - m - 1 << ' ' << ansy - m - 1 << '\n';

	return 0;
}