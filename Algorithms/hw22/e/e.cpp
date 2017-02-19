#include <bits/stdc++.h>

using namespace std;

/*inline int readChar();
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

#define INF 100000000
#define mp make_pair
#define pb push_back
#define pi pair <int, int>
#define forn(i, n) for(int i = 0; i < (int)(n); i++)

typedef long long ll;

const int Hr = 24;
const int Min = 60;
const int MAXN = 500;

int n;
vector<int> g[MAXN];
int mt[2][MAXN], used[MAXN];

struct Node{
	int start;
	int end;
	int a;
	int b;
	int c;
	int d;

	Node(){}
	Node(int h, int m, int aa, int bb, int cc, int dd): a(aa), b(bb), c(cc), d(dd){
		if (aa < cc) swap(aa, cc);
		if (bb < dd) swap(bb, dd);
		start = h * Min + m;
		end = start + (aa - cc) + (bb - dd);
	}	
};



int kuhn(int v){
	if (used[v]) return 0;
	used[v] = 1;
	forn(i, g[v].size()){
		int to = g[v][i];
		if (mt[1][to] == -1 || (kuhn(mt[1][to]))){
			if (mt[1][to] != -1){
				mt[0][mt[1][to]] = -1;
			}
			mt[1][to] = v;
			if (mt[0][v] != -1){
				mt[1][mt[0][v]] = -1;
			}
			mt[0][v] = to;
			return 1;
		}
	}
	return 0;
}


int main(){
	//cin.tie(0);
	//ios_base::sync_with_stdio(0);
	freopen("taxi.in", "r", stdin);
	freopen("taxi.out", "w", stdout);

	cin >> n;

	Node order[MAXN];

	forn(i, n){
		char ch;
		int h, m, a, c, b, d;
		cin >> h >> ch >> m >> a >> b >> c >> d;
		order[i] = Node(h, m, a, b, c, d);;
	}
	forn(i, n){
		int en = order[i].end, c = order[i].c, d = order[i].d;
		for (int j = i + 1; j < n; j++){
			if (order[j].start > en + abs(order[j].a - c) + abs(order[j].b - d)) g[i].pb(j);
		}
	}

	memset(mt[1], -1, sizeof(int) * n);
	memset(mt[0], -1, sizeof(int) * n);
	
	int run = 1;
	while(run){
		memset(used, 0, sizeof(int) * n);
		run = 0;
		forn(i, n){
			if (mt[0][i] == -1 && kuhn(i)) run = 1;
		}
	}

	int size = 0;
	forn(i, n){
		if (mt[0][i] != -1) size++;
	}
	cout << n - size << '\n';

	return 0;
}