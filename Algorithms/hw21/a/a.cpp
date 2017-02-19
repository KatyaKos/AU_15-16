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
 
#define INF 100000000
#define ui unsigned int
#define mp make_pair
#define pb push_back
#define pi pair <int, int>

const int MAXI = 1e5 + 100;

typedef long long ll;

using namespace std;

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

inline void writeWord( const char *s ) {
  while (*s)
    writeChar(*s++);
}

int n, q, timer, m;
int tin[MAXI], tout[MAXI];
int sz[MAXI], par[MAXI], num[MAXI];
int root[MAXI], ind[MAXI], pth_sz[MAXI];
vector <vector <int> > g;
int* tree[MAXI];

void dfs(int v, int pr){
	int u;
	sz[v] = 1; par[v] = pr;
	tin[v] = timer++;

	for (int i = 0; i < g[v].size(); i++){
		u = g[v][i];
		if (u == pr) continue;
		dfs(u, v);
		sz[v] += sz[u];
	}
	tout[v] = timer++;
}

inline bool is_anc(int u, int v){
	return (tin[u] <= tin[v] && tout[u] >= tin[v]);
}

void build(int v, int nm){
	int sv = sz[v], u, su, pr = par[v];
	num[v] = nm; ind[v] = pth_sz[nm]++;

	for (int i = 0; i < g[v].size(); i++){
		u = g[v][i]; su = sz[u];
		if (u != pr){
			if (su * 2 > sv){
				build(u, nm);
			}
			else{
				root[m] = u;
				build(u, m++);
			}
		}
	}
}

inline void inc(int delta, int i, int j){
	j += pth_sz[i];
	tree[i][j] += delta;
	for (j /= 2; j > 0; j /= 2){
		tree[i][j] = max(tree[i][2 * j], tree[i][2 * j + 1]);
	}
}

inline int get(int i, int l, int r){
	int* t = tree[i];
	int k = pth_sz[i], ans = 0;
	for (l += k, r += k; l <= r; l /= 2, r /= 2){
		if (l % 2 == 1) ans = max(ans, t[l++]);
		if (r % 2 == 0) ans = max(ans, t[r--]);
	}
	return ans;
}


int main(){
	//cin.tie(0);
	//ios_base::sync_with_stdio(0);
	freopen("caves.in", "r", stdin);
	freopen("caves.out", "w", stdout);

	n = readInt();
	g.resize(n);
	int u, v;
	for (int i = 0; i < n - 1; i++){
		v = readInt() - 1; u = readInt() - 1;
		g[u].pb(v);
		g[v].pb(u);
	}

	timer = 0; m = 0;
	dfs(0, -1);
	root[m] = 0;
	m++;
	build(0, 0);

	for (int i = 0; i < m; i++){
		tree[i] = new int[pth_sz[i] * 4];
		memset(tree[i], 0, sizeof(int) * pth_sz[i] * 4);
	}

	char c;
	int q = readInt(), ans;
	pair<int, pi > pri;
	for (int i = 0; i < q; i++){
		c = readChar(); v = readInt() - 1; u = readInt();
		if (c == 'I'){
			inc(u, num[v], ind[v]);
		}else{
			u--;
			ans = 0;
			int x = root[num[v]];
			while(!is_anc(x, u)){
				ans = max(ans, get(num[v], 0, ind[v]));
				v = par[x];
				x = root[num[v]];
			}
			swap(v, u);
			x = root[num[v]];
			while(!is_anc(x, u)){
				ans = max(ans, get(num[v], 0, ind[v]));
				v = par[x];
				x = root[num[v]];
			}
			writeInt(max(ans, get(num[v], min(ind[v], ind[u]), max(ind[v], ind[u]))));
			writeChar('\n');
		}
	}

	flush();

	return 0;
}