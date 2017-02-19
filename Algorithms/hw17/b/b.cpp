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
 
#define INF 10000000
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



struct Node{
	int x;
	Node* l;
	Node* r;
	Node(): l(NULL), r(NULL), x(-1) {};
};

int n, m, nn, h;
vector <Node*> root;

void find_n(){
	int tmp = 1;
	int tmph = 0;
	while(1){
		if (tmp >= n){
			nn = tmp;
			h = tmph;
			break;
		}
		tmp <<= 1;
		tmph++;
	}
}

void Build(int ht, Node* v){
	if (ht == h){
		if (m >= n) return;
		m++;
		v->x = readInt();
	}else{
		v->l = new Node;
		Build(ht + 1, v->l);
		v->r = new Node;
		Build(ht + 1, v->r);
	}
}

Node* create(Node* v, int i, int x, int l, int r){
	Node* u = new Node;
	if (v->x != -1){
		u->x = x;
	}else{
		if (i * 2 < l + r){
			u->r = v->r;
			u->l = create(v->l, i, x, l, (l + r) / 2);
		}else{
			u->l = v->l;
			u->r = create(v->r, i, x, (l + r) / 2, r);
		}
	}
	return u;
}

int get(Node* v, int i, int l, int r){
	if (v->x != -1){
		return v->x;
	}else{
		if (i * 2 < l + r){
			return get(v->l, i, l, (l + r) / 2);
		}else{
			return get(v->r, i, (l + r) / 2, r);
		}
	}
}


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("parray.in", "r", stdin);
	freopen("parray.out", "w", stdout);

	n = readInt();
	find_n();
	//cout << nn << '\n';
	Node* r0 = new Node;
	root.pb(r0);
	m = 0;
	Build(0, r0);

	m = readInt();
	char s;
	int vers, j, x;
	for (int i = 0; i < m; i++){
		s = readChar();
		if (s == 'c'){
			for (j = 0; j < 5; j++){
				s = readChar();
			}
			vers = readInt(); j = readInt(); x = readInt();
			root.pb(create(root[vers - 1], j - 1, x, 0, nn));
		}else{
			for (j = 0; j < 2; j++){
				s = readChar();
			}
			vers = readInt(); j = readInt();
			writeInt(get(root[vers - 1], j - 1, 0, nn)); writeChar('\n');
		}
	}

	flush();
	return 0;
}