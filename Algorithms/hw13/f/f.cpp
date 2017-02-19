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
#include <queue>
 
#define INF 1000000000
#define ll long long
#define ui unsigned int
#define mp make_pair
#define pb push_back

using namespace std;

class edg{
public:
	int a, b;
	int cost;
	edg(int aa, int bb, int cc){
		a = aa;
		b = bb;
		cost = cc;
	}
};

int n, m;
vector <edg> e;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("negcycle.in", "r", stdin);
	freopen("negcycle.out", "w", stdout);

	cin >> n >> m;
	int c;
	//m = 0;
	for (int i = 0; i < m; i++){
		int a, b; cin >> a >> b >> c;
		e.pb(edg(a - 1, b - 1, c));
	}

	vector<int> d(n, INF);
	int x;
	for (int i=0; i<n; ++i) {
		x = -1;
		for (int j=0; j<m; ++j){
			if (d[e[j].b] > d[e[j].a] + e[j].cost) {
				d[e[j].b] = max (-INF, d[e[j].a] + e[j].cost);
				x = e[j].b;
			}
		}
	}
 
	if (x == -1)
		cout << "no\n";
	else {
		cout << "yes\n";
	}

	return 0;
}