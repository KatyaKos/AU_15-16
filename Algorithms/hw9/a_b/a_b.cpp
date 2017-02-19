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
#include <set>
 
#define INF 1000000009
#define ll long long
#define ui unsigned int
#define mp make_pair

using namespace std;


int main() {

	freopen("marked2.in", "r", stdin);
	freopen("marked2.out", "w", stdout);

	int n, x, y;
	cin >> n >> x >> y;
	vector <int> task1;
	int m, tmp, b;

	for (int i = 0; i < x; i++){
		cin >> m;
		tmp = 0;
		for (int j = 0; j < m; j++){
			cin >> b;
			tmp += (1 << (b - 1));
		}
		task1.push_back(tmp);
	}

	sort(task1.begin(), task1.end());
	task1.resize(unique(task1.begin(), task1.end()) - task1.begin());


	vector <int> mask;
	mask.assign((1 << n), 0);
	for (int i = 0; i < task1.size(); i++){
		for (int j = task1[i]; j > 0; j = (j - 1) & task1[i]){
			mask[j] = 1;
		}
	}


	vector <int> task2;
	for (int i = 0; i < y; i++){
		cin >> m;
		tmp = 0;
		for (int j = 0; j < m; j++){
			cin >> b;
			tmp += (1 << (b - 1));
		}
		task2.push_back(tmp);
	}

	sort(task2.begin(), task2.end());
	task2.resize(unique(task2.begin(), task2.end()) - task2.begin());
	
	for (int i = 0; i < task2.size(); i++){
		for (int j = task2[i]; j > 0; j = (j - 1) & task2[i]){
			mask[j] = 0;
		}
	}

	int ans = 0;
	for (int i = 0; i < (1 << n); i++){
		ans += mask[i];
	}

	if (y == 0 && x != 0){
		ans++;
	}

	cout << ans << '\n';

	return 0;
}