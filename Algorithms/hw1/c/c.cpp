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
  
int main() {
	ifstream in("fib.in");
	ofstream out("fib.out");

	ll n;
	//scanf("%lld", &n);
	in >> n;
	ll pr1 = 1, pr2 = 1, now = 1;
	for (int i = 2; i <= n; i++){
		now = pr1 + pr2;
		pr1 = pr2;
		pr2 = now;
	}
	out << now;
	return 0;
}
