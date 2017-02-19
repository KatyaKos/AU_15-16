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

const int MAXN = 250;

int n, m;
vector<int> g[MAXN];
int mt[MAXN], used[MAXN];

int kuhn(int v){
	used[v] = 1;
	forn(i, g[v].size()){
		int to = g[v][i];
		if (mt[to] == -1 || (!used[mt[to]] && kuhn(mt[to]))){
			mt[to] = v;
			return 1;
		}
	}
	return 0;
}


int main(){
	//cin.tie(0);
	//ios_base::sync_with_stdio(0);
	freopen("pairs.in", "r", stdin);
	freopen("pairs.out", "w", stdout);

	n = readInt(); m = readInt();
	for (int i = 0; i < n; i++){
		int v;
		while ((v = readInt()) != 0){
			g[i].pb(v - 1);
		}
	}
	memset(mt, -1, sizeof(int) * m);
	
	int size = 0;
	forn(i, n){
		if (kuhn(i)){
			memset(used, 0, sizeof(int) * n);
			size++;
		}
	}

	writeInt(size); writeChar('\n');
	forn(i, m){
		if (mt[i] != -1){
			writeInt(mt[i] + 1); writeChar(' '); writeInt(i + 1); writeChar('\n');
		}
	}
	
	flush();

	return 0;
}