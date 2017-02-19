#include <bits/stdc++.h>

#define FILE_NAME "union"

using namespace std;

template <class T = int> inline T readInt();            
inline int readUInt();           
inline int readChar();           
inline void readWord( char *s ); 
inline bool readLine( char *s ); // do not save '\n'
inline bool isEof();
inline int peekChar();
inline bool seekEof();

template <class T> inline void writeInt( T x, int len );
template <class T> inline void writeUInt( T x, int len );
template <class T> inline void writeInt( T x ) { writeInt(x, -1); };
template <class T> inline void writeUInt( T x ) { writeUInt(x, -1); };
inline void writeChar( int x ); 
inline void writeWord( const char *s );
inline void writeDouble( double x, int len = 0 );
inline void flush();

/** Read */

static const int buf_size = 4096;

static char buf[buf_size];
static int buf_len = 0, pos = 0;

inline bool isEof() {
  if (pos == buf_len) {
    pos = 0, buf_len = fread(buf, 1, buf_size, stdin);
    if (pos == buf_len)
      return 1;
  }
  return 0;
}

inline int getChar() { 
  return isEof() ? -1 : buf[pos++];
}

inline int peekChar() { 
  return isEof() ? -1 : buf[pos];
}

inline bool seekEof() { 
  int c;
  while ((c = peekChar()) != -1 && c <= 32)
    pos++;
  return c == -1;
}

inline int readChar() {
  int c = getChar();
  while (c != -1 && c <= 32)
    c = getChar();
  return c;
}

inline int readUInt() {
  int c = readChar(), x = 0;
  while ('0' <= c && c <= '9')
    x = x * 10 + c - '0', c = getChar();
  return x;
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

inline void readWord( char *s ) { 
  int c = readChar();
  while (c > 32)
    *s++ = c, c = getChar();
  *s = 0;
}

inline bool readLine( char *s ) { 
  int c = getChar();
  while (c != '\n' && c != -1)
    *s++ = c, c = getChar();
  *s = 0;
  return c != -1;
}


inline void skip(int k) {
    while (k-- > 0) getChar();
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
inline void writeInt( T x, int output_len ) {
  if (x < 0)
    writeChar('-'), x = -x;

  char s[24];
  int n = 0;
  while (x || !n)
    s[n++] = '0' + x % 10, x /= 10;
  while (n < output_len)
    s[n++] = '0';
  while (n--)
    writeChar(s[n]);
}

template <class T> 
inline void writeUInt( T x, int output_len ) {
  char s[24];
  int n = 0;
  while (x || !n)
    s[n++] = '0' + x % 10, x /= 10;
  while (n < output_len)
    s[n++] = '0';
  while (n--)
    writeChar(s[n]);
}

inline void writeWord( const char *s ) {
  while (*s)
    writeChar(*s++);
}

inline void writeDouble( double x, int output_len ) {
  if (x < 0)
    writeChar('-'), x = -x;
  int t = (int)x;
  writeUInt(t), x -= t;
  writeChar('.');
  for (int i = output_len - 1; i > 0; i--) {
    x *= 10;
    t = std::min(9, (int)x);
    writeChar('0' + t), x -= t;
  }
  x *= 10;
  t = std::min(9, (int)(x + 0.5));
  writeChar('0' + t);
}


/*  
*********************************************
**********  MEMORY ALLOCATION   *************
*********************************************
*/


const int MAX_MEM = 3e8;
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


/*
********************************************
************   SOLUTION   ******************
********************************************
*/

const int MAXN = 100000;
const int MAXL = 18;

typedef pair<int, int> pii;

int W[MAXN], size[MAXN], in[MAXN], out[MAXN], go[MAXN][MAXL], timer;
int pathId[MAXN], pathPos[MAXN], top[MAXN], len[MAXN], totalPaths;
vector<int> path[MAXN];
vector<pii> g[MAXN];

int buildLCA(int v, int p) {
	in[v] = timer++;

	go[v][0] = p;
	for (int i = 1; i < MAXL; i++)
		go[v][i] = go[go[v][i - 1]][i - 1];

	size[v] = 1;
	for (pii t : g[v]) {
		int to = t.first;
		if (to != p) {
			W[to] = t.second;
			buildLCA(to, v);
			size[v] += size[to];
		}
	}

	out[v] = timer++;
}

inline bool isAncestor(int a, int b) {
	return in[a] <= in[b] && out[a] >= out[b];
} 

int buildHLD(int v, int p, int curPath) {
	if (!len[curPath])
		top[curPath] = v;
	pathId[v] = curPath;
	pathPos[v] = len[curPath];
	len[curPath]++;
	path[curPath].push_back(W[v]);
	int big = -1;
	for (pii t : g[v]) {
		int to = t.first;
		if (to != p && (big == -1 || size[big] < size[to]))
			big = to;
	}
	for (pii t : g[v]) {
		int to = t.first;
		if (to != p)
			buildHLD(to, v, to == big ? curPath : totalPaths++);
	}
}


struct node {
    int sum;
    node *l, *r;

    node() : l(NULL), r(NULL) {}
};

const int MAXW = 1000000;

node *inc(node *v, int tl, int tr, int pos) {
    node *res = new node, *l = v ? v->l : NULL, *r = v ? v->r : NULL;
    if (tl != tr) {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            res->l = inc(l, tl, tm, pos), res->r = r;
        else
            res->r = inc(r, tm + 1, tr, pos), res->l = l;
    }
    res->sum = 1;
    if (v) res->sum += v->sum;
    return res;
}

int getSum(node *v, int tl, int tr, int l, int r) {
    if (!v || tr < l || r < tl)
        return 0;
    if (l <= tl && tr <= r)
        return v->sum;
    int tm = (tl + tr) / 2;
    return getSum(v->l, tl, tm, l, r) + getSum(v->r, tm + 1, tr, l, r);
}

int n;
vector<node*> root[MAXN];


void buildTrees() {
	for (int i = 0; i < totalPaths; i++) {
		root[i].push_back(NULL);

		for (int j = 0; j < len[i]; j++)
			root[i].push_back(inc(root[i][j], 1, MAXW, path[i][j])); 
	}
}

inline int count(int i, int l, int r, int R) {
	return getSum(root[i][r + 1], 1, MAXW, 1, R) - getSum(root[i][l], 1, MAXW, 1, R);     
}


inline int verticalQuery(int up, int down, int k) {
	int res = 0, upPath = pathId[up], downPath = -1;
	while (downPath != upPath) {
		downPath = pathId[down];
		res += count(downPath, downPath == upPath ? pathPos[up] : 0, pathPos[down], k);  
		down = go[top[downPath]][0];			
	}
	return res;
}

inline int under(int a, int b) {
	for (int i = MAXL - 1; i >= 0; i--)
		if (!isAncestor(go[b][i], a))
			b = go[b][i];
	return b;
}

inline int query(int a, int b, int k) {
	if (a == b)
		return 0;
	else if (isAncestor(a, b)) {
		int c = under(a, b);
		return verticalQuery(c, b, k);
	} else if (isAncestor(b, a)) {
		int c = under(b, a);
		return verticalQuery(c, a, k);
	} else {
		int A = under(b, a), B = under(a, b);
		return verticalQuery(A, a, k) + verticalQuery(B, b, k);
	}
}


void solve() {
	int n = readInt();
	for (int i = 0; i < n - 1; i++) {
		int x = readInt() - 1, y = readInt() - 1, w = readInt();
		g[x].push_back(pii(y, w));
		g[y].push_back(pii(x, w));
	}
	buildLCA(0, 0);
	buildHLD(0, 0, totalPaths++);
	buildTrees();
	int q = readInt();
	for (int i = 0; i < q; i++) {
		int v = readInt() - 1, u = readInt() - 1, k = readInt();
		writeInt(query(v, u, k)), writeChar('\n');		
	}
}

int main() {
    freopen(FILE_NAME".in", "r", stdin);
    freopen(FILE_NAME".out", "w", stdout);    
    solve();
    flush();
    return 0;
}