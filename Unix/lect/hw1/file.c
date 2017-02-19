#define _CRT_SECURE_NO_WARNINGS

#include <vector.h>
#include <fstream.h>
#include <iostream.h>
#include <cstdio.h>
#include <cmath.h>
#include <string.h>
#include <algorithm.h>
#include <numeric.h>

 
#define INF 1000000009
#define ll long long
#define sort stable_sort
#define pb push_back

using namespace std;

int n;
vector <string> child;
vector < vector<int> > mass;

  
int main() {

	freopen("meeting.in", "r", stdin);
	freopen("meeting.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	child.assign(n, "");
	mass.resize(n);

	for (int i = 0; i < n; i++){
		cin >> child[i];
		if (i != 0) mass[i].pb(i - 1); else mass[i].pb(n - 1);
		if (i != n - 1) mass[i].pb(i + 1); else mass[i].pb(0);
	}

	int m;
	for (int i = 0; i < n - 3; i++){
		cin >> m;
		m--;
		int l = mass[m][0], r = mass[m][1];
		cout << child[l] << ' ' << child[r] << '\n';
		mass[l][1] = r;
		mass[r][0] = l;
	}
	

	return 0;
}
