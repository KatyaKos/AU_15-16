#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <numeric>
#include <queue>

 
#define INF 1000000009
#define ll long long
#define sort stable_sort

using namespace std;
int n;
vector <int> good(10001, 0);
queue < pair <int, int> > peop;
  
int main() {

	freopen("queue.in", "r", stdin);
	freopen("queue.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	int j, time, m;
	for (int i = 0; i < n; i++){
		cin >> j >> time >> m;
		if (j == 1){
			good[m] += 1;
		} else peop.push(make_pair(time, m));
		while (!peop.empty() && good[peop.front().second] > 0){
			cout << time - peop.front().first << ' ';
			good[peop.front().second]--;
			peop.pop();
		}
	}
	for (int i = 0; i < peop.size(); i++) cout << -1 << ' ';
	cout << '\n';	

	return 0;
}
