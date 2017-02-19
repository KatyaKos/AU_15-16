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
#include <queue>
 
#define INF 1000000009
#define ll long long
#define ui unsigned int
#define mp make_pair
#define pb push_back

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

int n;
vector <vector <int> > g;
vector <int> used;
vector <pair<int,int> > crd;
vector <int> min_e, sel_e;
 
int main(){
	//cin.tie(0);
	//ios_base::sync_with_stdio(0);
	cout.precision(10);
	freopen("unionday.in", "r", stdin);
	freopen("unionday.out", "w", stdout);

	//cin >> n;
	n = readInt();
	crd.resize(n);
	int x, y;
	for (int i = 0; i < n; i++){
		//cin >> x >> y;
		x = readInt(); y = readInt();
		crd[i] = mp(x, y);

	}

	min_e.assign(n, INF);
	sel_e.assign(n, -1);
	used.assign(n, 0);
	min_e[0] = 0;
	int v;
	long double ans = 0;
	int tmp, p;
	for (int i = 0; i < n; i++){
		v = -1;
		for (int j = 0; j < n; j++){
			if (used[j] == 0 && (v == -1 || min_e[j] < min_e[v])){
				v = j;
			}
		}
		used[v] = 1;
		if (sel_e[v] != -1){
			p = sel_e[v];
			tmp = (crd[v].first - crd[p].first) * (crd[v].first - crd[p].first) + (crd[v].second - crd[p].second) * (crd[v].second - crd[p].second);
			ans += sqrt(tmp);
			//cout << v << ' ' << sel_e[v] << '\n';
		}
		for (int to = 0; to < n; to++){
			tmp = (crd[v].first - crd[to].first) * (crd[v].first - crd[to].first) + (crd[v].second - crd[to].second) * (crd[v].second - crd[to].second);
			if (tmp < min_e[to]){
				min_e[to] = tmp;
				sel_e[to] = v;
			}
		}
	}

	cout << fixed << (double)ans << '\n';
	
	flush();

	return 0;
}