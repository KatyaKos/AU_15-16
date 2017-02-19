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
ll m;
vector <pair <int, int> > g;
set <pair <int, int> > ans;

bool comp(pair <int, int> a, pair <int, int> b){
	return a.first + a.second < b.first + b.second;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("boxes.in", "r", stdin);
	freopen("boxes.out", "w", stdout);

	cin >> n;
	g.resize(n);

	for (int i = 0; i < n; i++){
		cin >> g[i].first >> g[i].second;
	}
	sort (g.begin(), g.end(), comp);

	m = g[0].first;
	ans.insert(mp(-g[0].first, 0));

	for (int i = 1; i < n; i++){

		if (m <= g[i].second){
			ans.insert(mp(-g[i].first, i)); m += g[i].first;
		}else if (-(ans.begin()->first) > g[i].first){
			m += ans.begin()->first + g[i].first;
			ans.insert(mp(-g[i].first, i));
			ans.erase(ans.begin());
		}
	}

	cout << ans.size() << '\n';

	return 0;
}