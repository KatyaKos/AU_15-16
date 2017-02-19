#define _CRT_SECURE_NO_WARNINGS
#pragma comment (linker, "/STACK:10000000000")

#include <vector>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <stack>
#include <map>
#include <queue>
#include <string.h>
#include <bitset>
 
#define INF 1000000009
#define ll long long
#define ui unsigned int
#define mp make_pair
#define pb push_back

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

const int n = 26;
const int a = (int)'a';

struct Node{
	Node* l;
	Node* r;
	int c;
	Node(int ct){
		c = ct;
		//l = 0;
		//r = 0;
	}
	Node(Node* lt, Node* rt){
		l = lt;
		r = rt;
		c = -1;
	}
};

char ans[n][100010];
char tmp[100010];

void dfs(Node* nd, int t){
	if (nd->c != -1){
		strcpy(ans[nd->c], tmp);
		//cout << ans[t] << '\n';
	}else{
		tmp[t] = '1';
		dfs(nd->l, t + 1);
		tmp[t] = '0';
		dfs(nd->r, t + 1);
		tmp[t] = 0;
	}
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("encoding.in", "r", stdin);
	freopen("encoding.out", "w", stdout);

	char s[100000];
	//cin.get(s, 100000);
	scanf("%s\n", s);
	int m = strlen(s), k = 0, l = 0;
	vector <int> txt;
	txt.assign(n, 0);
	for (int i = 0; i < m; i++){
		txt[(int)s[i] - a]++;
	}
	
	priority_queue <pair<int, Node*> > code;
	for (int i = 0; i < n; i++){
		if (txt[i] != 0){
			Node* nd = new Node(i);
			code.push(mp(-txt[i], nd));
			k++;
		}
	}

	pair <int, Node*> p, q;
	while (code.size() != 1){
		p = code.top();
		code.pop();
		q = code.top();
		code.pop();
		Node* nd = new Node(p.second, q.second);
		code.push(mp(p.first+q.first, nd));
	}
	/*for (int i = 0; i < 100000; i++){
		cout << 'a';
	}*/

	if (k == 1){
		strcpy(ans[code.top().second->c], "0");
	}else{
		dfs(code.top().second, 0);
	}
	for (int i = 0; i < n; i++){
		l += txt[i] * strlen(ans[i]);
	}
	cout << k << ' ' << l << '\n';
	for (int i = 0; i < n; i++){
		if (txt[i] == 0) continue;
		cout << (char)(i + a) << ": " << ans[i] << '\n';
	}
	for (int i = 0; i < m; i++){
		cout << ans[(int)s[i] - a];
	}
	cout << '\n';

	return 0;
}