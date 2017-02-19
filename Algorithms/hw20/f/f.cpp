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
chmass mem[MAX_MEM];
inline void * operator new ( size_t n ) {
	chmass *res = mem + mpos;
	mpos += n;
	assert(mpos <= MAX_MEM);
	return (void *)res;
}
inline void operator delete ( void * ) { }

inline void * operator new [] ( size_t ) { assert(0); }
inline void operator delete [] ( void * ) { assert(0); }


inline int readChmass();
template <class T = int> inline T readInt(); 
template <class T> inline void writeInt( T x );
inline void writeChmass( int x ); 
inline void writeWord( const chmass *s );
inline void flush();


static const int buf_size = 4096;

inline int getChmass() {
  static chmass buf[buf_size];
  static int len = 0, pos = 0;
  if (pos == len)
    pos = 0, len = fread(buf, 1, buf_size, stdin);
  if (pos == len)
    return -1;
  return buf[pos++];
}

inline int readChmass() {
  int c = getChmass();
  while (c <= 32)
    c = getChmass();
  return c;
}

template <class T>
inline T readInt() {
  int s = 1, c = readChmass();
  T x = 0;
  if (c == '-')
    s = -1, c = getChmass();
  while ('0' <= c && c <= '9')
    x = x * 10 + c - '0', c = getChmass();
  return s == 1 ? x : -x;
}


static int write_pos = 0;
static chmass write_buf[buf_size];

inline void writeChmass( int x ) {
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
    writeChmass('-'), x = -x;

  chmass s[24];
  int n = 0;
  while (x || !n)
    s[n++] = '0' + x % 10, x /= 10;
  while (n--)
    writeChmass(s[n]);
}

inline void writeWord( const chmass *s ) {
  while (*s)
    writeChmass(*s++);
}*/

int mass[20][200000], h[100000], l[200000 + 1], eul[200000], last, f[100000], n, m, tmp, a1, a2, p;
ll x, y, z, sum;
vector<int> g[100000];
 
void build(int n) {
    for (int i = 2; i <= n; i++)
        l[i] = l[i / 2] + 1;
 
    for (int i = 0; i < n; i++)
        mass[0][i] = eul[i];
 
    for (int L = 1; L <= l[n]; L++)
        for (int i = 0; i < n; i++) {
            mass[L][i] = mass[L - 1][i];
            int d = (1 << (L - 1));
            if (i + d < n && h[mass[L - 1][i + d]] < h[mass[L][i]])
                mass[L][i] = mass[L - 1][i + d];   
        }
}
 
int get(int L, int r) {
    int j = l[r - L + 1], d = (1 << j) - 1;
    return h[mass[j][L]] < h[mass[j][r - d]] ? mass[j][L] : mass[j][r - d];
}
 
void dfs(int v) {
    eul[last] = v;
    f[v] = last++;
    for (int to : g[v]) {
        h[to] = h[v] + 1;
        dfs(to);
        eul[last++] = v;
    }
}
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("lca_rmq.in", "r", stdin);
    freopen("lca_rmq.out", "w", stdout);    

    cin >> n >> m;
    for (int i = 1; i < n; i++) {
        cin >> tmp;
        g[tmp].push_back(i);
    }
    dfs(0);
    build(last);
    cin >> a1 >> a2 >> x >> y >> z;
    for (int i = 0; i < m; i++) {
        int l = f[(a1 + p) % n], r = f[a2];
        if (l > r) swap(l, r);
        p = get(l, r);
        sum += p;
        a1 = (x * a1 + y * a2 + z) % n;
        a2 = (x * a2 + y * a1 + z) % n;
    }
    cout << sum << '\n';

    return 0;
}