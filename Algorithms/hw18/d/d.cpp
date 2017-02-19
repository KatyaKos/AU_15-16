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

int n;

struct Node{
	Node *l, *r;
	int num;
	Node(): l(NULL), r(NULL), num(0) {};
};

void insert(Node* v, ll l, ll r, int x){
	if (l == r){
		v->num++;
		return;
	}
	int m = (l + r) / 2;
	if (x <= m){
		if (!v->l) v->l = new Node;
		insert(v->l, l, m, x);
		v->num = v->l->num;
		if (v->r) v->num = max(v->num, v->r->num);
	}else{
		if (!v->r) v->r = new Node;
		insert(v->r, m + 1, r, x);
		v->num = v->r->num;
		if (v->l) v->num = max(v->num, v->l->num);
	}
}

int findmin(Node* v, ll l, ll r){
	if (l == r){
		v->num--;
		return l;
	}
	int m = (l + r) / 2, ans;
	if (v->l && v->l->num){
		ans = findmin(v->l, l, m);
		v->num = v->l->num;
		if (v->r) v->num = max(v->num, v->r->num);
	}else{
		ans = findmin(v->r, m + 1, r);
		v->num = v->r->num;
		if (v->l) v->num = max(v->num, v->l->num);
	}
	return ans;
}

int findmax(Node* v, ll l, ll r){
	if (l == r){
		v->num--;
		return l;
	}
	int m = (l + r) / 2, ans;
	if (v->r && v->r->num){
		ans = findmax(v->r, m + 1, r);
		v->num = v->r->num;
		if (v->l) v->num = max(v->num, v->l->num);
	}else{
		ans = findmax(v->l, l, m);
		v->num = v->l->num;
		if (v->r) v->num = max(v->num, v->r->num);
	}
	return ans;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("minmax.in", "r", stdin);
	freopen("minmax.out", "w", stdout);

	int mx = (1ll << 31) - 1;
	n = readInt();
	Node* v = new Node;
	char c;
	int x;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < 6; j++) c = readChar();
		if (c == 't'){
			c = readChar(); x = readInt();
			insert(v, 1, mx, x);
		}else if (c == 'n'){
			writeInt(findmin(v, 1, mx)); writeChar('\n');
		}else{
			writeInt(findmax(v, 1, mx)); writeChar('\n');
		}
	}

	flush();

	return 0;
}