#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <numeric>
#include <deque>

 
#define INF 1000000009
#define ll long long
#define sort stable_sort

using namespace std;
int n, k;
deque <int> mass;
const int M = 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2;
  
int main() {

	freopen("sleepgame.in", "r", stdin);
	freopen("sleepgame.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++){
		int a;
		cin >> a;
		mass.push_back(a);
	}

	for (int i = 0; i < k; i++){
		int x = mass.front(), y = mass.back();
		if (x < y){ mass.pop_front(); mass.push_back((x + y) % M); }
		else { mass.pop_back(); mass.push_front((M + y - x) % M);}
	}

	for (int i = 0; i < n; i++){
		cout << mass.front() << ' ';
		mass.pop_front();
	}
	cout << '\n';

	return 0;
}
