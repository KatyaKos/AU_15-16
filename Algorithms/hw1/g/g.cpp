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

ifstream in("sprite.in");
ofstream out("sprite.out");
  
int main() {

	int n;
	in >> n;
	vector<int> ans;
	ans.assign(3, 10000000);
	int s = 10000000;
	for (int a = 1; a <= n; a++){
		for (int b = 1; b * a <= n; b++){
			if (n % (a * b) == 0){
				int c = n / (a * b);

				if ((b + c) * a + b * c < s){
					ans[0] = a; ans[1] = b; ans[2] = c;
					s = (b + c) * a + b * c;
				}
			} 
		}
	}
	out << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
	return 0;
} 
