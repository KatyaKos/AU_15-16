#pragma comment (linker, "/STACK:10000000000")
#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <numeric>

 
#define INF 1000000009
#define ll long long

using namespace std;

/** Interface */

inline int readChar();
template <class T = int> inline T readInt(); 
template <class T> inline void writeInt( T x );
inline void writeChar( int x ); 
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


int h[1000003];
const int m = 1000003;
int mass[1000003];

int Find(int x){

	int i = x % m;
	while (h[i] != -1 && h[i] != x) i = (i + 1) % m;
	if (h[i] == -1){
		h[i] = x;
		mass[i] = x;
	}
	return i;

}

int main() {

	freopen("swap.in", "r", stdin);
	freopen("swap.out", "w", stdout);

	int n;
	n = readInt();
	for (int u = 0; u < m; u++){
		h[u] = -1;
		mass[u] = -1;
	}

	for (int u = 0; u < n; u++){

		int a = readInt(), b = readInt();
		int i = Find(a), j = Find(b);
		//cout << a << ' ' << i << ' ' << b << ' ' << j << '\n';

		writeInt(abs(mass[i] - mass[j]));
		writeChar('\n');
		swap(mass[i], mass[j]);

		//cout << h[0] << ' ' << h[1] << ' ' << h[2] << ' ' << h[3] << ' ' << h[4] << ' ' << h[5] << ' ' << h[245] << '\n';
		//cout << mass[0] << ' ' << mass[1] << ' ' << mass[2] << ' ' << mass[3] << ' ' << mass[4] << ' ' << mass[5] << ' ' << mass[245] << '\n';

	}

	flush();

	return 0;
}
