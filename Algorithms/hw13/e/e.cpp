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

	cin >> n;
	int c;
	m = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> c;
			if (c != 100000){
				e.pb(edg(i, j, c));
				m++;
			}
		}
	}

	vector<int> d(n, INF);
	vector<int> p(n, -1);
	int x;
	for (int i=0; i<n; ++i) {
		x = -1;
		for (int j=0; j<m; ++j){
			if (d[e[j].b] > d[e[j].a] + e[j].cost) {
				d[e[j].b] = max (-INF, d[e[j].a] + e[j].cost);
				p[e[j].b] = e[j].a;
				x = e[j].b;
			}
		}
	}
 
	if (x == -1)
		cout << "NO\n";
	else {
		int y = x;
		for (int i=0; i<n; ++i) y = p[y];
 
		vector<int> path;
		for (int cur = y; ; cur=p[cur]) {
			path.pb(cur);
			if (cur == y && path.size() > 1)  break;
		}
		path.pop_back();
		reverse(path.begin(), path.end());
		cout << "YES\n" << path.size() << '\n';
		for (int i = 0; i < path.size(); i++){
			cout << path[i] + 1 << ' ';
		}
		cout << '\n';
	}

	return 0;
}