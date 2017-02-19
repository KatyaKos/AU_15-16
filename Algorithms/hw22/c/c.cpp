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

const int MAXN = 305;

int n, m, a, b;
vector<int> g[MAXN * MAXN];
int mt[2][MAXN * MAXN], used[MAXN * MAXN];

int kuhn(int v){
	if (used[v]) return 0;
	used[v] = 1;
	forn(i, g[v].size()){
		int to = g[v][i];
		if (mt[1][to] == -1 || (kuhn(mt[1][to]))){
			if (mt[1][to] != -1){
				mt[0][mt[1][to]] = -1;
				mt[1][mt[1][to]] = -1;
			}
			mt[1][to] = v;
			mt[0][to] = v;
			if (mt[0][v] != -1){
				mt[1][mt[0][v]] = -1;
				mt[0][mt[0][v]] = -1;
			}
			mt[0][v] = to;
			mt[1][v] = to;
			return 1;
		}
	}
	return 0;
}

inline int cell(int i, int j){
	return i * (m + 2) + j;
}


int main(){
	//cin.tie(0);
	//ios_base::sync_with_stdio(0);
	freopen("floor.in", "r", stdin);
	freopen("floor.out", "w", stdout);

	int brokennum = 0;
	cin >> n >> m >> b >> a;

	int matrix[n + 2][m + 2];
	memset(matrix[0], 0, sizeof(int) * (m + 2));

	char buff[MAXN];
	for (int i = 1; i <= n; i++){
		memset(matrix[i], 0, sizeof(int) * (m + 2));
		cin >> buff;
		for (int j = 1; j <= m; j++){
			if (buff[j - 1] == '*'){
				matrix[i][j] = 1;
				brokennum++;
			}
		}
	}

	if (a * 2 <= b){
		cout << a * brokennum << '\n';
		return 0;
	}

	memset(matrix[n + 1], 0, sizeof(int) * (m + 2));
	memset(mt[1], -1, sizeof(int) * (m + 2) * (n + 2));
	memset(mt[0], -1, sizeof(int) * (m + 2) * (n + 2));

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			if (!matrix[i][j]) continue;
			int v = cell(i, j);
			if (matrix[i - 1][j]) g[v].pb(cell(i - 1, j));
			if (matrix[i][j - 1]) g[v].pb(cell(i, j - 1));
			if (matrix[i][j + 1]) g[v].pb(cell(i, j + 1));
			if (matrix[i + 1][j]) g[v].pb(cell(i + 1, j));
		}
	}
	
	int run = 1;
	while(run){
		memset(used, 0, sizeof(int) * (m + 2) * (n + 2));
		run = 0;
		forn(i, (n + 2) * (m + 2)){
			if (mt[0][i] == -1 && kuhn(i)) run = 1;
		}
	}

	int vertnum = 0;
	forn(i, (n + 2) * (m + 2)){
		if (mt[0][i] != -1) vertnum++;
	}

	cout << a * (brokennum - vertnum) + b * vertnum / 2 << '\n';
	//flush();

	return 0;
}