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

int n, k;
vector <pair<int, int> > mass;
vector<int> col;
vector <char> lb;
vector <char> rb;
char bd[2];

inline void push(int v, int l, int r){
	int cl = col[v];
	if (l == r || cl == -1) return;
	int len = (l + r) / 2 - l + 1;
	mass[2 * v] = mp(cl, cl * len);
	mass[2 * v + 1] = mp(cl, cl * (r - l + 1 - len));
	col[2 * v] = col[2 * v + 1] = cl;
	col[v] = -1;
	lb[2 * v] = rb[2 * v] = lb[2 * v + 1] = rb[2 * v + 1] = bd[cl];
}

int flag = 0;
void make(int v, int l, int r, int fl, int fr, int cl){

	//cout << "l: " << l - 500001 << " r: " << r - 500001 << " fl: " << fl - 500001 << " fr: " << fr-500001 << '\n';
	if (fl > fr){
		return;
	}
	if (l == fl && r == fr){
		col[v] = cl;
		mass[v] = mp(cl, cl * (r - l + 1));
		lb[v] = rb[v] = bd[cl];
		return;
	}

	if (col[v] == cl){
		push(v, l, r);
		mass[v] = mp(cl, cl * (r - l + 1));
		lb[v] = rb[v] = bd[cl];
		return;
	}
	push(v, l, r);

	int m = (l + r) / 2;
	make(2 * v, l, m, fl, min(m, fr), cl);
	make(2 * v + 1, m + 1, r, max(m + 1, fl), fr, cl);

	mass[v].first = mass[2 * v].first + mass[2 * v + 1].first;
	mass[v].second = mass[2 * v].second + mass[2 * v + 1].second;
	if (rb[2 * v] == '1' && lb[2 * v + 1] == '1') mass[v].first--;
	lb[v] = lb[2 * v]; rb[v] = rb[2 * v + 1];
}


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("painter.in", "r", stdin);
	freopen("painter.out", "w", stdout);

	k = readInt(); n = 1000010;
	pair<int, int> tp = mp(0, 0);
	mass.assign(4 * n + 1, tp);
	col.assign(4 * n + 1, -1);
	lb.assign(4 * n + 1, 0);
	rb.assign(4 * n + 1, 0);
	bd[0] = '0'; bd[1] = '1';

	char c;
	int x, l;
	for (int i = 0; i < k; i++){
		c = readChar(); x = readInt(); l = readInt();
		if (c == 'W'){
			make(1, 1, n, x + 500001, x + 500000 + l, 0);
			//cout << "\n\n\n\n";
		}else{
			make(1, 1, n, x + 500001, x + 500000 + l, 1);
		}
		tp = mass[1];
		writeInt(tp.first); writeChar(' '); writeInt(tp.second); writeChar('\n');
	}

	flush();

	return 0;
}