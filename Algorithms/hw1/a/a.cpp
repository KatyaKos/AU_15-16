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
#define sort stable_sort

using namespace std;

inline int readInt();
template <class T> inline void writeInt( T x );

inline int readInt() {
	int s = 0, c = getchar(), x = 0;
	if (c == '-')
		s = 1, c = getchar();
	while ('0' <= c && c <= '9')
		x = x * 10 + c - '0', c = getchar();
	return s ? -x : x;
}

template <class T> inline void writeInt( T x ) {
	if (x < 0)
		putchar('-'), x = -x;
	char s[24];
	int n = 0;
	while (x || !n)
		s[n++] = '0' + x % 10, x /= 10;
	while (n--)
		putchar(s[n]);
	putchar(' ');
}
  
int main() {
	freopen("io.in", "r", stdin);
	freopen("io.out", "w", stdout);

	vector <int> mass;
	int n = readInt();
	mass.assign(n, 0);

	for (int i = 0; i < n; i++) {
		mass[i] = readInt();
	}

	for (int i = n - 1; i >= 0; i--) {
		writeInt(mass[i]);
	}

	return 0;
}
