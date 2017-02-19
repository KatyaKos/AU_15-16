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

ifstream in("rect1.in");
ofstream out("rect1.out");

int main() {
	int n;
	in >> n;
	vector <ll> x;
	vector <ll> y;
	x.resize(4);
	y.resize(4);
	in >> x[2] >> y[2] >> x[3] >> y[3];

	for (int i = 1; i < n; i++){

		in >> x[0] >> y[0] >> x[1] >> y[1];

		if (x[2] > x[1] || x[3] < x[0]){
			out << 0 << '\n';
			return 0;
		}else{
			x[2] = max(x[0], x[2]);
			x[3] = min(x[3], x[1]);
		}

		if (y[2] > y[1] || y[3] < y[0]){
			out << 0 << '\n';
			return 0;
		}else{
			y[2] = max(y[0], y[2]);
			y[3] = min(y[3], y[1]);
		}
		
	}
	out << max(0ll, (x[3] - x[2]) * (y[3] - y[2])) <<'\n';

	return 0;















}
