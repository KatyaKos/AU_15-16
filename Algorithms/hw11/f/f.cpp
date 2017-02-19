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
#include <queue>
#include <map>
 
#define INF 1000000009
#define ll long long
#define ui unsigned int
#define mp make_pair
#define pb push_back

using namespace std;

vector < vector <int> > d;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("diameter.in", "r", stdin);
	freopen("diameter.out", "w", stdout);

	int n;
	cin >> n;
	d.resize(n);
	for (int i = 0; i < n; i++){
		d[i].assign(n, 2000000);
	}

	int a;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> a;
			if (a != -1){
				d[i][j] = a;
			}
		}
	}

	for (int k = 0; k < n; k++){
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				if (d[i][k] < 2000000 && d[k][j] < 2000000){
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				}
			}
		}
	}
	
	int di = -1, r = 2000000;
	for (int i = 0; i < n; i++){
		int tmp = -1;
		for (int j = 0; j < n; j++){
			if (tmp < d[i][j]) tmp = d[i][j];
		}
		if (tmp < r) r = tmp;
		if (tmp > di) di = tmp;
	}

	cout << di << '\n' << r << '\n';

	return 0;
}