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



int main() {

	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("cows.in", "r", stdin);
	freopen("cows.out", "w", stdout);

	int n, k;
	cin >> n >> k;
	vector <int> stay;
	stay.resize(n);
	for (int i = 0; i < n; i++) cin >> stay[i];

	int l = 0, r = 1000000000;
	while (l + 1 < r){
		int m = (l +  r) / 2;
		int num = 1, i = 0;
		for (int j = 1; j < n; j++){
			if (stay[j] - stay[i] >= m){
				num++;
				i = j;
			}
		}

		if (num >= k) l = m;
		else r = m;
	}

	cout << l << '\n';


	return 0;
}








