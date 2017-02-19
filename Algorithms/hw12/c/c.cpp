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

/** Begin fast allocation */
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
/** End fast allocation */

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


int n, m;
vector <vector <int> > g;
vector <vector <int> > mass;
vector <int> used;

int dfs(int start, int v, int step, int pr){
	if (step == 2){
		if (mass[v][start] == 1){
			return 1;
		}
		return 0;
	}
	int anst = 0;
	for (int i = 0; i < g[v].size(); i++){
		int u = g[v][i];
		if (u != pr &&  u > v){
			anst += dfs(start, u, step + 1, v);
		}
	}
	return anst;
}
 
int main(){
	//cin.tie(0);
	//ios_base::sync_with_stdio(0);
	freopen("catlover.in", "r", stdin);
	freopen("catlover.out", "w", stdout);

	map < pair<int, int>, int > us;
	//cin >> n >> m;
	n = readInt();
	m = readInt();
	int a, b;
	g.resize(n);
	mass.resize(n);
	for (int i = 0; i < n; i++){
		mass[i].assign(n, 0);
	}
	for (int i = 0; i < m; i++){
		//cin >> a >> b;
		a = readInt();
		b = readInt();
		a--; b--;
		if (us[mp(a, b)] == 0){
			us[mp(a, b)] = 1;
			us[mp(b, a)] = 1;
			g[a].pb(b);
			g[b].pb(a);
			mass[a][b] = 1;
			mass[b][a] = 1;
		}
	}

	/*for (int i = 0; i < n; i++){
		for (int j = 0; j < g[i].size(); j++){
			cout << g[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';*/

	int ans = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < g[i].size(); j++){
			int v = g[i][j];
			if (v < i) continue;
			for (int k = 0; k < g[v].size(); k++){
				int u = g[v][k];
				if (u < v) continue;
				if (mass[u][i] == 1) ans++;
			}
		}
	}

	//cout << ans / 6 << '\n';
	writeInt(ans);
	writeChar('\n');
	flush();

	return 0;
}