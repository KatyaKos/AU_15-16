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
 
#define INF 1000000009
#define ll long long
#define sort stable_sort

using namespace std;
int n, l;
vector < vector <int> > matr;




#include <cstdio>

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

int matmin(int i, int j){
	int ans = matr[i][j];
	for (int k = i + 1; k < i + l; k++){
		if (matr[k][j] < ans) ans = matr[k][j];
	}
	return ans;
}

int main() {

	freopen("matrixmin.in", "r", stdin);
	freopen("matrixmin.out", "w", stdout);
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	n = readInt();
	l = readInt();
	matr.resize(n);
	for (int i = 0; i < n; i++){
		matr[i].resize(n);
		for (int j = 0; j < n; j++) matr[i][j] = readInt();
	}

	vector < vector <int> > mini;
	mini.resize(n - l + 1);
	for (int i = 0; i < n - l + 1; i++){
		mini[i].resize(n);
		for (int j = 0; j < n; j++) mini[i][j] = matmin(i, j);
	}

	//for (int i = 0; i < mini.size(); i++){
	//	for (int j = 0; j < mini[i].size(); j++){
	//		cout << mini[i][j] << ' ';
	//	}
	//	cout << '\n';
	//}
	
	for (int i = 0; i < n - l + 1; i++){
		for (int j = 0; j < n - l + 1; j++){
			int ans = mini[i][j];
			for (int k = j + 1; k < j + l; k++){
				if (mini[i][k] < ans) ans = mini[i][k];
			}
			writeInt(ans);
			writeChar(' ');
		}
		writeChar('\n');
	}
	flush();
	return 0;
}




