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
#include <sstream>
 
#define INF 1000000000
#define ll long long
#define ui unsigned int
#define mp make_pair
#define pb push_back

using namespace std;
 
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("functions.in", "r", stdin);
	freopen("functions.out", "w", stdout);
	int n;
	cin >> n;

	vector <string> name;
	vector <int> deg;
	vector <vector<int> > g;
	name.resize(n);
	deg.assign(n, 0);
	g.resize(n);
	for (int i = 0; i < n; i++){
		g[i].assign(n, 0);
	}

	string tmp;
	int a;
	stringstream s[n];
	getline(cin, tmp);
	for (int i = 0; i < n; i++){
		getline(cin, tmp);
		s[i] << tmp;
		s[i] >> name[i];
		while (s[i] >> a){
			deg[i]++;
			g[a][i]++;
		}
	}

	int v;
	for (int i = 0; i < n; i++){
		v = INF;
		for (int j = 0; j < n; j++){
			if (deg[j] == 0 && (v == INF || name[j] < name[v])){
				v = j;
			}
		}
		for (int j = 0; j < n; j++){
			deg[j] -= g[v][j];
		}
		cout << name[v] << '\n';
		deg[v] = INF;
	}

	return 0;
}