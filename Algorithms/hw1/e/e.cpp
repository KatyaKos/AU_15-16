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
vector <int> mass;
vector <int> used;
int n;

ifstream in("perm.in");
ofstream out("perm.out");

void go(int i){
	if (i == n){
		for (int j = 0; j < n - 1; j++) out << mass[j] << ' ';
		out << mass[n - 1] << '\n';
		return;
	}
	for (int j = 0; j < n; j++){
		if (used[j] == 0){
			mass[i] = j + 1;
			used[j] = 1;
			go(i + 1);
			used[j] = 0;
		}
	}
}

int main() {
	in >> n;
	mass.assign(n, 0);
	used.assign(n, 0);

	go(0);

	return 0;
}
