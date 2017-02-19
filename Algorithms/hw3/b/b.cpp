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
#define ull unsigned long long
#define ll long long

using namespace std;
const ll m = 1ll<<32;
  
int main() {

	freopen("sqrt.in", "r", stdin);
	freopen("sqrt.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	ull n;

	while (cin >> n){
		ll a = sqrt(n);
		
		while (a * a > n || a == m) a--;
		while ((a + 1) * (a + 1) < n && a < m - 1) a++;

		cout << a << '\n';

	}

	return 0;
}
