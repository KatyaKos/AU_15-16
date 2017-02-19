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
#define ui unsigned int

using namespace std;

#include <cstdio>

ui cur = 0;
ui n, q, a, b;
vector <ui> mass;

unsigned int nextRand24() {
	cur = cur * a + b;
	return cur >> 8;
}
unsigned int nextRand32() {
	unsigned int a = nextRand24(), b = nextRand24();
	return (a << 8) ^ b;
}

ui q_sort(int l, int r, int q_now){

	ui x = mass[(l + r) / 2];
	int i = l, j = r;

	/*for (int i = 0; i < mass.size(); i++) cout << mass[i] << ' ';
	cout << '\n';*/

	while(i <= j){

		while(mass[i] < x) i++;
		while(mass[j] > x) j--;

		if(i <= j){
			swap(mass[i], mass[j]);
			i++;
			j--;
		}
	}

	if(l <= q_now && q_now <= j) return q_sort(l, j, q_now);
	if(i <= q_now && q_now <= r) return q_sort(i, r, q_now);
	return mass[q_now];
}

int main() {

	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("qstat.in", "r", stdin);
	freopen("qstat.out", "w", stdout);
	cin >> n >> q >> a >> b;
	mass.resize(n);

	for (int i = 0; i < n; i++) mass[i] = nextRand32();

	cout << q_sort(0, mass.size() - 1, q - 1) << '\n';

	return 0;
}







