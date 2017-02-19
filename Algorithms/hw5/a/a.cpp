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
#include <iomanip>
 
#define INF 1000000009
#define ll long long
#define ui unsigned int

using namespace std;

double a, b, c, d;
const double E = 0.0000001;

int main() {

	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("cubroot.in", "r", stdin);
	freopen("cubroot.out", "w", stdout);

	cout.precision(6);

	cin >> a >> b >> c >> d;

	b = b / a;
	c = c / a;
	d = d / a;
	a = 1.0;
	
	double l = -10000000000.0, r = 10000000000.0;
	while (l + E < r){
		double m = (l + r) / 2;
		double ans = a * m * m * m + b * m * m + c * m + d;
		//cout << fixed << ans << ' ' << ' ' << m << ' ' << l << ' ' << r << '\n';
		if (ans < 0) l = m;
		else if (ans > 0) r = m;
		else{
			cout << fixed << m << '\n';
			return 0;
		}

	}

	cout << fixed << l << '\n';


	return 0;
}








