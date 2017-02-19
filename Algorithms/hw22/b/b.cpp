#include <bits/stdc++.h>

using namespace std;

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

#define INF 100000000
#define mp make_pair
#define pb push_back
#define pi pair <int, int>
#define forn(i, n) for(int i = 0; i < (int)(n); i++)

typedef long long ll;

const int MAXN = 4000;

int n, m;
vector<int> g[2][MAXN];
int mt[2][MAXN], used[2][MAXN];
vector<int> ans[2];


void dfs(int v, int step){
	used[step][v] = 1;
	if (step){
		if (mt[1][v] != -1 && !used[0][mt[1][v]]) dfs(mt[1][v], 0);
	}else{
		forn(i, g[0][v].size()){
			int to = g[0][v][i];
			if (!used[1][to]) dfs(to, 1);
		}
	}
}

int main(){
	//cin.tie(0);
	//ios_base::sync_with_stdio(0);
	freopen("minimal.in", "r", stdin);
	freopen("minimal.out", "w", stdout);

	n = readInt(); m = readInt();
	forn(i, n){
		int v, num = readInt();
		while(num--){
			v = readInt() - 1;
			g[0][i].pb(v);
			g[1][v].pb(i);
		}
	}
	
	forn(i, n){
		int v = readInt() - 1;
		mt[0][i] = v;
		if (v != -1) mt[1][v] = i;
	}

	forn(i, n){
		if (mt[0][i] == -1 && !used[0][i]){
			dfs(i, 0);
		}
	}

	forn(i, n){
		if (!used[0][i]) ans[0].pb(i + 1);
	}
	forn(i, m){
		if (used[1][i]) ans[1].pb(i + 1);
	}

	n = ans[0].size(); m = ans[1].size();
	writeInt(n + m); writeChar('\n');
	writeInt(n); writeChar(' ');
	forn(i, n){
		writeInt(ans[0][i]); writeChar(' ');
	}
	writeChar('\n'); writeInt(m); writeChar(' ');
	forn(i, m){
		writeInt(ans[1][i]); writeChar(' ');
	}
	writeChar('\n');
	
	flush();

	return 0;
}