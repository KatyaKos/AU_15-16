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
#include <set>
#include <string>
 
#define INF 1000000009
#define ll long long
#define ui unsigned int

using namespace std;

int n;
int a[1 << 11], d[1 << 11];

int go(int m){

    if (m + 1 == (1 << n)) return a[m];
    if (d[m] != -1) return d[m];
    d[m] = a[m];
    for (int i = 0; i < n; i++){
        if (((1 << i) & m) != 0)
            d[m] = max(d[m], a[m] + go((1 << i) ^ m));
    }
    return d[m];
}

int main() {

	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("kbest.in", "r", stdin);
	//freopen("cube.out", "w", stdout);

	cin >> n;
	for (int i = 0; i < (1 << n); i++){
		cin >> a[i];
		d[i] = -1;
	}

	cout << go(0) << '\n';

	return 0;
}









