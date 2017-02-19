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
#include <queue>
#include <string.h>
#include <bitset>
 
#define INF 1000000009
#define ll long long
#define ui unsigned int
#define mp make_pair
#define pb push_back

using namespace std;


int n;
vector <pair < pair<int, int>, int> > g;
 
bool comp(pair < pair<int, int>, int> a, pair < pair<int, int>, int> b){
	return min(a.first.first, b.first.second) < min(b.first.first, a.first.second);
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("f2cmax.in", "r", stdin);
	freopen("f2cmax.out", "w", stdout);

	cin >> n;
	g.resize(n);

	for (int i = 0; i < n; i++){
		cin >> g[i].first.first;
		g[i].second = i;	
	}
	for (int i = 0; i < n; i++){
		cin >> g[i].first.second;
	}
 
	sort(g.begin(), g.end(), comp);
	ll t = 0, tt = 0;
	for (int i = 0; i < n; i++){
		t += g[i].first.first;
		tt = g[i].first.second + max(tt, t);
	}

	cout << tt << '\n';
	for (int i = 0; i < n; i++){
		cout << g[i].second + 1 << ' ';
	}
	cout << '\n';
	for (int i = 0; i < n; i++){
		cout << g[i].second + 1 << ' ';
	}
	cout << '\n';

	return 0;
}