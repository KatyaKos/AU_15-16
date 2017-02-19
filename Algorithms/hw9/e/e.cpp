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
 
#define INF 1000000009
#define ll long long
#define ui unsigned int
#define mp make_pair

using namespace std;

int main() {

	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("salesman.in", "r", stdin);
	freopen("salesman.out", "w", stdout);

	vector <vector < int > > d;
	vector <vector <int> > mass;
	int n;
	cin >> n;
	if (n == 1){
		cout << 0 << '\n' << 1 << '\n';
		return 0;
	}
	d.resize(1 << n);
	mass.resize(n);
	for (int i = 0; i < (1 << n); i++){
		d[i].resize(n);
	}

	for (int i = 0; i < n; i++){
		mass[i].resize(n);
		for (int j = 0; j < n; j++){
			cin >> mass[i][j];
		}
	}


	for (int x = 3; x < (1 << n); x++){
		if ((x & (x - 1)) != 0){
			for (int i = 0; i < n; i++){
				if ((x & (1 << i)) != 0){
					d[x][i] = 2000000000;
					for (int j = 0; j < n; j++){
						if (i != j && (x & (1 << j)) != 0){
							d[x][i] = min(d[x - (1<<i)][j] + mass[j][i], d[x][i]);
						}
					}
				}
			}
		}
	}

	int x = (1 << n) - 1;
	int ans = d[x][0];
	for (int i = 1; i < n; i++){
		ans = min(ans, d[x][i]);
	}
	cout << ans << '\n';

	vector <int> ms;

	int flag = 0, u, tmp, k = 0;
	while (flag == 0){
		tmp = 2000000000;
		for (int i = 0; i < n; i++){
			if ((x & (1 << i)) != 0 && tmp > d[x][i]){
				tmp = d[x][i];
				u = i;
			}
		}
		ms.push_back(u + 1);
		k++;
		if (k != n - 1){
			x = x ^ (1 << u);
		}else{
			flag = 1;
			for (int i = 0; i < n; i++){
				if ((x & (1 << i)) != 0 && i != u){
					ms.push_back(i + 1);
					break;
				}
			}
		}
	}

	for (int i = n - 1; i >= 0; i--){
		cout << ms[i] << ' ';
	}
	cout << '\n';
	
	
	return 0;
}